#include <cstdlib>
#include <ctime>

#include "Course.h"
#include "User.h"
#include "RelasiUser.h"

using namespace std;

// Function to generate a random string of a given length
string generateRandomString(int length) {
    const string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string randomString;
    for (int i = 0; i < length; ++i) {
        randomString += characters[rand() % characters.length()];
    }
    return randomString;
}

// Function to generate random user information
User generateRandomUser() {
    User newUser;
    newUser.nama = generateRandomString(5);
    newUser.UID = generateRandomString(8);
    newUser.password = generateRandomString(10);
    newUser.role = "Student"; // You can modify this if needed
    return newUser;
}

// Function to generate random course information
Course generateRandomCourse() {
    Course newCourse;
    newCourse.nama = generateRandomString(8);
    newCourse.kode = generateRandomString(5);
//    newCourse.tugas = generateRandomString(10);
//    newCourse.nQuiz = 3; // Assuming 3 quizzes for each course for the example
//
//    // Generating random quiz information
//    for (int i = 0; i < newCourse.nQuiz; ++i) {
//        newCourse.quiz[i].pertanyaan = "Pertanyaan " + to_string(i + 1);
//        newCourse.quiz[i].jawaban = "Jawaban " + to_string(i + 1);
//        newCourse.quiz[i].point = rand() % 11; // Random point between 0 and 10
//    }

    return newCourse;
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed for random number generation

    // Create lists for courses, users, and user-course relationships
    ListCourse courses;
    ListUser users;

    // Initialize the lists
    createListCourse(courses);
    createListUser(users);

    infotypeCourse tempCourse;
    tempCourse.kode = "APPPP";
    tempCourse.nama = "Test";
    tempCourse.tugas = "P";
    addressCourse tempC = alokasiCourse(tempCourse);
    insertLastCourse(courses, tempC);
    printInfoCourse(courses);

    infotypeUser tempUser;
    tempUser.nama = "aA";
    tempUser.password = "PP";
    tempUser.role = "mhs";
    tempUser.UID = "123123";
    addressUser tempU = alokasiUser(tempUser);
    insertLastUser(users, tempU);
    printInfoUser(users);

    insertLastRelasiUser(relasiUser(tempC), alokasiRelasiUser(tempU));

    printUser(courses, "APPPP");

    addressCourse buang;
    deleteFirstCourse(courses, buang);
    printInfoCourse(courses);

    printInfoUser(users);

//    // Generate and insert 10 courses
//    for (int i = 0; i < 10; ++i) {
//        Course newCourse = generateRandomCourse();
//        addressCourse courseAddress = alokasiCourse(newCourse);
//        insertLastCourse(courses, courseAddress);
//    }
//
//    printInfoCourse(courses);
//
//    // Generate and insert 20 users
//    for (int i = 0; i < 20; ++i) {
//        User newUser = generateRandomUser();
//        addressUser userAddress = alokasiUser(newUser);
//        insertLastUser(users, userAddress);
//    }
//
//    printInfoUser(users);



//    // Establish relationships between users and courses
//    for (addressUser user = first(users); user != NULL; user = next(user)) {
//        for (addressCourse course = first(courses); course != NULL; course = next(course)) {
//            // Assuming a random chance for a user to be related to a course
//            addressRelasiUser relationship = alokasiRelasiUser(user);
//            insertLastRelasiUser(relasiUser(course), relationship);
//
//            cout << info(first(courses)).nama << endl;
//            cout << info(first(relasiUser(courses))).nama << endl;
//        }
//    }


//    // Print information
//    cout << "Courses:" << endl;
//
//
//    cout << "\nUsers:" << endl;
//    printInfoUser(users);

    return 0;
}
