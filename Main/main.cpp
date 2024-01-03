#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Course.h"
#include "User.h"
#include "RelasiUser.h"

int main() {
    int menu;
    char choice;
    bool login = false;
    string name, pass, id, role, code, task;
    addressCourse tempC;
    addressUser tempU;
    infotypeUser tempUser;
    infotypeCourse tempCourse;

    ListCourse courses;
    ListUser users;

    createListCourse(courses);
    createListUser(users);

    // Inisialisasi 5 course dan 7 user (5 dosen & 2 mahasiswa)
    // Course 1
    tempCourse.code = "MATH101";
    tempCourse.name = "Mathematics I";
    tempCourse.task = "Homework 1";
    tempCourse.forum[0].title = "Introduction to Homework 1";
    tempCourse.forum[0].body = "Let's discuss the problems and solutions for Homework 1.";
    tempCourse.quiz[0].question = "What is the value of pi (π)?";
    tempCourse.quiz[0].answer = "3.14159";
    tempCourse.quiz[0].point = 10;
    tempCourse.result[0].UID = "890123";
    tempCourse.result[0].score = 8;
    tempCourse.nForum = 1;
    tempCourse.nQuiz = 1;
    tempCourse.nResult = 1;
    addressCourse tempC1 = alokasiCourse(tempCourse);
    insertLastCourse(courses, tempC1);

    // Course 2
    tempCourse.code = "CS202";
    tempCourse.name = "Data Structures";
    tempCourse.task = "Programming Project";
    tempCourse.forum[0].title = "Project Discussion";
    tempCourse.forum[0].body = "Let's discuss ideas and issues related to the programming project.";
    tempCourse.quiz[0].question = "What is a linked list?";
    tempCourse.quiz[0].answer = "A data structure that consists of a sequence of elements, where each element points to the next element in the sequence.";
    tempCourse.quiz[0].point = 20;
    tempCourse.result[0].UID = "789012";
    tempCourse.result[0].score = 18;
    addressCourse tempC2 = alokasiCourse(tempCourse);
    insertLastCourse(courses, tempC2);

    // Course 3
    tempCourse.code = "ENG301";
    tempCourse.name = "Advanced English";
    tempCourse.task = "Essay";
    tempCourse.forum[0].title = "Essay Discussion";
    tempCourse.forum[0].body = "Let's discuss ideas and issues related to the essay.";
    tempCourse.quiz[0].question = "Define the term 'metaphor' in the context of literature.";
    tempCourse.quiz[0].answer = "A figure of speech in which a word or phrase is applied to an object or action to which it is not literally applicable.";
    tempCourse.quiz[0].point = 15;
    addressCourse tempC3 = alokasiCourse(tempCourse);
    insertLastCourse(courses, tempC3);

    // Course 4
    tempCourse.code = "PHYS102";
    tempCourse.name = "Physics II";
    tempCourse.task = "Lab Report";
    tempCourse.forum[0].title = "Lab Report Discussion";
    tempCourse.forum[0].body = "Let's discuss ideas and issues related to the lab report.";
    tempCourse.quiz[0].question = "Explain the concept of electric flux.";
    tempCourse.quiz[0].answer = "Electric flux is the measure of the electric field through a surface.";
    tempCourse.quiz[0].point = 25;
    addressCourse tempC4 = alokasiCourse(tempCourse);
    insertLastCourse(courses, tempC4);

    // Course 5
    tempCourse.code = "CHEM201";
    tempCourse.name = "Organic Chemistry";
    tempCourse.task = "Research Paper";
    tempCourse.forum[0].title = "Research Paper Discussion";
    tempCourse.forum[0].body = "Let's discuss ideas and issues related to the research paper.";
    tempCourse.quiz[0].question = "What is a nucleophile in organic chemistry?";
    tempCourse.quiz[0].answer = "A nucleophile is a chemical species that donates an electron pair to an electrophile.";
    tempCourse.quiz[0].point = 18;
    addressCourse tempC5 = alokasiCourse(tempCourse);
    insertLastCourse(courses, tempC5);

    // User 1
    tempUser.name = "Alice";
    tempUser.password = "alice123";
    tempUser.role = "Dosen";
    tempUser.UID = "123456";
    addressUser tempU1 = alokasiUser(tempUser);
    insertLastUser(users, tempU1);
    insertLastRelasiUser(relasiUser(tempC5), alokasiRelasiUser(tempU1));
    info(tempC5).nUser++;

    // User 2
    tempUser.name = "Bob";
    tempUser.password = "bob456";
    tempUser.role = "Dosen";
    tempUser.UID = "987654";
    addressUser tempU2 = alokasiUser(tempUser);
    insertLastUser(users, tempU2);
    insertLastRelasiUser(relasiUser(tempC2), alokasiRelasiUser(tempU2));
    info(tempC2).nUser++;

    // User 3
    tempUser.name = "Charlie";
    tempUser.password = "charlie789";
    tempUser.role = "Dosen";
    tempUser.UID = "654321";
    addressUser tempU3 = alokasiUser(tempUser);
    insertLastUser(users, tempU3);
    insertLastRelasiUser(relasiUser(tempC3), alokasiRelasiUser(tempU3));
    info(tempC3).nUser++;

    // User 4
    tempUser.name = "David";
    tempUser.password = "david987";
    tempUser.role = "Dosen";
    tempUser.UID = "123789";
    addressUser tempU4 = alokasiUser(tempUser);
    insertLastUser(users, tempU4);
    insertLastRelasiUser(relasiUser(tempC1), alokasiRelasiUser(tempU4));
    info(tempC1).nUser++;

    // User 5
    tempUser.name = "Eve";
    tempUser.password = "eve654";
    tempUser.role = "Dosen";
    tempUser.UID = "789456";
    addressUser tempU5 = alokasiUser(tempUser);
    insertLastUser(users, tempU5);
    insertLastRelasiUser(relasiUser(tempC4), alokasiRelasiUser(tempU5));
    info(tempC4).nUser++;

    // User 6
    tempUser.name = "John";
    tempUser.password = "doej614";
    tempUser.role = "Mahasiswa";
    tempUser.UID = "890123";
    addressUser tempU6 = alokasiUser(tempUser);
    insertLastUser(users, tempU6);
    insertLastRelasiUser(relasiUser(tempC1), alokasiRelasiUser(tempU6));
    info(tempC1).nUser++;

    // User 7
    tempUser.name = "Jane";
    tempUser.password = "jane456";
    tempUser.role = "Mahasiswa";
    tempUser.UID = "789012";
    addressUser tempU7 = alokasiUser(tempUser);
    insertLastUser(users, tempU7);
    insertLastRelasiUser(relasiUser(tempC2), alokasiRelasiUser(tempU7));
    info(tempC2).nUser++;

    do {
        cout << "=================================================" << endl;
        cout << "================== MENU =========================" << endl;
        cout << "=================================================" << endl;
        cout << "1. REGISTER " << endl;
        cout << "2. LOGIN " << endl;
        cout << "3. DASHBOARD " << endl;
        cout << "4. EXIT " << endl;
        cout << "Pilihan: ";
        cin >> menu;

        if (menu == 1) {
            cout << "=====AVAILABLE COURSES====" << endl;
            printAllCourses(courses);

            cout << "=== Registrasi ===" << endl;
            cout << "Masukan nama: ";
            cin >> name;
            tempUser.name = name;
            cout << "Masukan password: ";
            cin >> pass;
            tempUser.password = pass;
            cout << "Masukan role (Mahasiswa/Dosen): ";
            cin >> role;
            tempUser.role = role;
            cout << "Masukan ID: ";
            cin >> id;
            tempUser.UID = id;
            cout << "Masukan course: ";
            cin >> code;

            tempC = findElmCourse(courses, code);
            tempU = alokasiUser(tempUser);
            insertLastUser(users, tempU);
            insertLastRelasiUser(relasiUser(tempC), alokasiRelasiUser(tempU));
            info(tempC).nUser++;

            cout << "Akun berhasil terdaftar." << endl;

            printAllUsers(users);
        } else if (menu == 2) {
            cout << "Masukan ID: ";
            cin >> id;
            cout << "Masukan password: ";
            cin >> pass;

            tempU = findElmUser(users, id);
            if (tempU != NULL) {
                cout << "Berhasil login." << endl;
                login = true;
                role = info(tempU).role;
            } else {
                cout << "Akun belum terdaftar." << endl;
            }
        } else if (menu == 3) {
            if (!login){
                cout << "Mohon login terlebih dahulu." << endl;
            } else if (role == "Mahasiswa") {
                do {
                    cout << "=================================================" << endl;
                    cout << "================== DASHBOARD ====================" << endl;
                    cout << "=================================================" << endl;
                    cout << "=====ENROLLED COURSES=====" << endl;
                    printEnrolledCourse(courses, id);

                    cout << "1. FORUM " << endl;
                    cout << "2. QUIZ " << endl;
                    cout << "3. BACK TO MAIN MENU " << endl;
                    cout << "Pilihan: ";
                    cin >> menu;

                    if (menu == 1) {
                        cout << "Kode course: ";
                        cin >> code;

                        if (findElmCourse(courses, code) != NULL){
                            do {
                                cout << "=====FORUM=====" << endl;
                                printForum(courses, code);

                                cout << "Tambah forum? (Y/N) ";
                                cin >> choice;
                                if (choice == 'Y'){
                                    addForum(courses, code);
                                }
                            } while (choice != 'N');
                        } else {
                            printf("Course %s tidak ditemukan.\n", code.c_str());
                        }
                    } else if (menu == 2){
                        cout << "Kode course: ";
                        cin >> code;
                        doQuiz(courses, code, id);
                    }
                } while (menu != 3);
            } else if (role == "Dosen") {
                do {
                    cout << "=================================================" << endl;
                    cout << "================== DASHBOARD ====================" << endl;
                    cout << "=================================================" << endl;
                    cout << "1. COURSES " << endl;
                    cout << "2. USERS " << endl;
                    cout << "3. BACK TO MAIN MENU " << endl;
                    cout << "Pilihan: ";
                    cin >> menu;

                    if (menu == 1) {
                        do {
                            cout << "===================================================" << endl;
                            cout << "================== COURSES ========================" << endl;
                            cout << "===================================================" << endl;
                            cout << "1. ALL COURSES " << endl;
                            cout << "2. ENROLLED COURSES " << endl;
                            cout << "3. BACK TO DASHBOARD " << endl;
                            cout << "Pilihan: ";
                            cin >> menu;

                            if (menu == 1) {
                                do {
                                    cout << "=====ALL COURSES=====" << endl;
                                    printAllCourses(courses);

                                    cout << "1. ADD COURSE" << endl;
                                    cout << "2. DELETE COURSE" << endl;
                                    cout << "3. BACK TO COURSES" << endl;
                                    cout << "Pilihan: ";
                                    cin >> menu;

                                    if (menu == 1) {
                                        infotypeCourse dummyCourse;
                                        cout << "Nama course: ";
                                        cin.ignore();
                                        getline(cin, dummyCourse.name);
                                        cout << "Kode course: ";
                                        cin >> dummyCourse.code;
                                        insertLastCourse(courses, alokasiCourse(dummyCourse));
                                    } else if (menu == 2){
                                        cout << "Kode course: ";
                                        cin >> code;
                                        deleteSpesificCourse(courses, code);
                                    }
                                } while (menu != 3);
                            } else if (menu == 2) {
                                do {
                                    cout << "=====ENROLLED COURSES=====" << endl;
                                    printEnrolledCourse(courses, id);;

                                    cout << "1. DELETE FORUM" << endl;
                                    cout << "2. ADD QUIZ" << endl;
                                    cout << "3. DELETE QUIZ" << endl;
                                    cout << "4. EDIT QUIZ" << endl;
                                    cout << "5. QUIZ RESULT" << endl;
                                    cout << "6. EDIT TASK" << endl;
                                    cout << "7. BACK TO COURSES" << endl;
                                    cout << "Pilihan: ";
                                    cin >> menu;

                                    if (menu == 1) {
                                        cout << "=====DELETE FORUM=====" << endl;
                                        cout << "Kode course: ";
                                        cin >> code;
                                        deleteForum(courses, code);
                                    } else if (menu == 2) {
                                        cout << "=====ADD QUIZ=====" << endl;
                                        cout << "Kode course: ";
                                        cin >> code;
                                        addQuiz(courses, code);
                                    } else if (menu == 3) {
                                        cout << "=====DELETE QUIZ=====" << endl;
                                        cout << "Kode course: ";
                                        cin >> code;
                                        deleteQuiz(courses, code);
                                    } else if (menu == 4) {
                                        cout << "=====EDIT QUIZ=====" << endl;
                                        cout << "Kode course: ";
                                        cin >> code;
                                        editQuiz(courses, code);
                                    } else if (menu == 5) {
                                        cout << "=====QUIZ RESULT=====" << endl;
                                        cout << "Kode course: ";
                                        cin >> code;
                                        printResult(courses, code);
                                    } else if (menu == 6) {
                                        cout << "=====EDIT TASK=====" << endl;
                                        cout << "Kode course: ";
                                        cin >> code;
                                        editTask(courses, code);
                                    }
                                } while (menu != 7);
                            }
                        } while (menu != 3);
                    } else if (menu == 2) {
                        cout << "=====ALL USERS=====" << endl;
                        printAllUsers(users);
                    }
                } while (menu != 3);
            }
        }
    } while (menu != 4);

    return 0;
}
