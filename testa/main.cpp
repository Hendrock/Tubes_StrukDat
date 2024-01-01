#include <cstdlib>
#include <ctime>

#include "Course.h"
#include "User.h"
#include "RelasiUser.h"

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed for random number generation

    ListCourse courses;
    ListUser users;

    createListCourse(courses);
    createListUser(users);

    infotypeUser mahasiswa1 = {"Mahasiswa1", "M123", "mahasiswa_pwd1", "Mahasiswa"};
    infotypeUser mahasiswa2 = {"Mahasiswa2", "M456", "mahasiswa_pwd2", "Mahasiswa"};

    infotypeUser dosen1 = {"Dosen1", "D123", "dosen_pwd1", "Dosen"};
    infotypeUser dosen2 = {"Dosen2", "D456", "dosen_pwd2", "Dosen"};

    addressUser mahasiswaPtr1 = alokasiUser(mahasiswa1);
    addressUser mahasiswaPtr2 = alokasiUser(mahasiswa2);
    addressUser dosenPtr1 = alokasiUser(dosen1);
    addressUser dosenPtr2 = alokasiUser(dosen2);

    insertLastUser(users, mahasiswaPtr1);
    insertLastUser(users, mahasiswaPtr2);
    insertLastUser(users, dosenPtr1);
    insertLastUser(users, dosenPtr2);

    printInfoUser(users);

//    infotypeCourse tempCourse;
//    tempCourse.kode = "APPPP";
//    tempCourse.nama = "Test";
//    tempCourse.tugas = "P";
//    addressCourse tempC = alokasiCourse(tempCourse);
//    insertLastCourse(courses, tempC);
//    printInfoCourse(courses);
//
//    infotypeUser tempUser;
//    tempUser.nama = "aA";
//    tempUser.password = "PP";
//    tempUser.role = "mhs";
//    tempUser.UID = "123123";
//    addressUser tempU = alokasiUser(tempUser);
//    insertLastUser(users, tempU);
//    printInfoUser(users);
//
//    insertLastRelasiUser(relasiUser(tempC), alokasiRelasiUser(tempU));
//
//    printUser(courses, "APPPP");
//
//    addressCourse buang;
//    deleteFirstCourse(courses, buang);
//    printInfoCourse(courses);
//
//    printInfoUser(users);

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
