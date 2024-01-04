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
    string name, pass, id, tempID, role, code, task;
    addressCourse tempC;
    addressUser tempU;
    infotypeUser tempUser;
    infotypeCourse tempCourse, tempCourse1, tempCourse2, tempCourse3, tempCourse4, tempCourse5;

    ListCourse courses;
    ListUser users;

    createListCourse(courses);
    createListUser(users);

    // Course 1
    tempCourse1.code = "MATH101";
    tempCourse1.name = "Mathematics I";
    tempCourse1.task = "Homework 1";
    tempCourse1.forum[0].title = "Introduction to Homework 1";
    tempCourse1.forum[0].body = "Let's discuss the problems and solutions for Homework 1.";
    tempCourse1.quiz[0].question = "What is the value of pi (π)?";
    tempCourse1.quiz[0].answer = "3.14159";
    tempCourse1.quiz[0].point = 10;
    tempCourse1.result[0].UID = "890123";
    tempCourse1.result[0].score = 8;
    tempCourse1.result[1].UID = "678901";
    tempCourse1.result[1].score = 9;
    tempCourse1.nForum = 1;
    tempCourse1.nQuiz = 1;
    tempCourse1.nResult = 2;
    addressCourse tempC1 = alokasiCourse(tempCourse1);
    insertLastCourse(courses, tempC1);

    // Course 2
    tempCourse2.code = "CS202";
    tempCourse2.name = "Data Structures";
    tempCourse2.task = "Programming Project";
    tempCourse2.forum[0].title = "Project Discussion";
    tempCourse2.forum[0].body = "Let's discuss ideas and issues related to the programming project.";
    tempCourse2.quiz[0].question = "What is a linked list?";
    tempCourse2.quiz[0].answer = "A data structure that consists of a sequence of elements, where each element points to the next element in the sequence.";
    tempCourse2.quiz[0].point = 20;
    tempCourse2.result[0].UID = "782461";
    tempCourse2.result[0].score = 18;
    tempCourse1.result[1].UID = "789012";
    tempCourse1.result[1].score = 8;
    tempCourse2.nForum = 1;
    tempCourse2.nQuiz = 1;
    tempCourse2.nResult = 2;
    addressCourse tempC2 = alokasiCourse(tempCourse2);
    insertLastCourse(courses, tempC2);

    // Course 3
    tempCourse3.code = "ENG301";
    tempCourse3.name = "Advanced English";
    tempCourse3.task = "Essay";
    tempCourse3.forum[0].title = "Essay Discussion";
    tempCourse3.forum[0].body = "Let's discuss ideas and issues related to the essay.";
    tempCourse3.quiz[0].question = "Define the term 'metaphor' in the context of literature.";
    tempCourse3.quiz[0].answer = "A figure of speech in which a word or phrase is applied to an object or action to which it is not literally applicable.";
    tempCourse3.quiz[0].point = 15;
    tempCourse3.nForum = 1;
    tempCourse3.nQuiz = 1;
    addressCourse tempC3 = alokasiCourse(tempCourse3);
    insertLastCourse(courses, tempC3);

    // Course 4
    tempCourse4.code = "PHYS102";
    tempCourse4.name = "Physics II";
    tempCourse4.task = "Lab Report";
    tempCourse4.forum[0].title = "Lab Report Discussion";
    tempCourse4.forum[0].body = "Let's discuss ideas and issues related to the lab report.";
    tempCourse4.quiz[0].question = "Explain the concept of electric flux.";
    tempCourse4.quiz[0].answer = "Electric flux is the measure of the electric field through a surface.";
    tempCourse4.quiz[0].point = 25;
    tempCourse4.nForum = 1;
    tempCourse4.nQuiz = 1;
    addressCourse tempC4 = alokasiCourse(tempCourse4);
    insertLastCourse(courses, tempC4);

    // Course 5
    tempCourse5.code = "CHEM201";
    tempCourse5.name = "Organic Chemistry";
    tempCourse5.task = "Research Paper";
    tempCourse5.forum[0].title = "Research Paper Discussion";
    tempCourse5.forum[0].body = "Let's discuss ideas and issues related to the research paper.";
    tempCourse5.quiz[0].question = "What is a nucleophile in organic chemistry?";
    tempCourse5.quiz[0].answer = "A nucleophile is a chemical species that donates an electron pair to an electrophile.";
    tempCourse5.quiz[0].point = 18;
    tempCourse5.nForum = 1;
    tempCourse5.nQuiz = 1;
    addressCourse tempC5 = alokasiCourse(tempCourse5);
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
    tempUser.UID = "782461";
    addressUser tempU7 = alokasiUser(tempUser);
    insertLastUser(users, tempU7);
    insertLastRelasiUser(relasiUser(tempC2), alokasiRelasiUser(tempU7));
    info(tempC2).nUser++;

    // User 8
    tempUser.name = "Fiona";
    tempUser.password = "fiona789";
    tempUser.role = "Mahasiswa";
    tempUser.UID = "345678";
    addressUser tempU8 = alokasiUser(tempUser);
    insertLastUser(users, tempU8);
    insertLastRelasiUser(relasiUser(tempC3), alokasiRelasiUser(tempU8));
    info(tempC3).nUser++;
    insertLastRelasiUser(relasiUser(tempC5), alokasiRelasiUser(tempU8));
    info(tempC5).nUser++;

    // User 9
    tempUser.name = "George";
    tempUser.password = "george123";
    tempUser.role = "Mahasiswa";
    tempUser.UID = "456789";
    addressUser tempU9 = alokasiUser(tempUser);
    insertLastUser(users, tempU9);
    insertLastRelasiUser(relasiUser(tempC4), alokasiRelasiUser(tempU9));
    info(tempC4).nUser++;

    // User 10
    tempUser.name = "Hannah";
    tempUser.password = "hannah456";
    tempUser.role = "Mahasiswa";
    tempUser.UID = "567890";
    addressUser tempU10 = alokasiUser(tempUser);
    insertLastUser(users, tempU10);
    insertLastRelasiUser(relasiUser(tempC5), alokasiRelasiUser(tempU10));
    info(tempC5).nUser++;

    // User 11
    tempUser.name = "Isaac";
    tempUser.password = "isaac789";
    tempUser.role = "Mahasiswa";
    tempUser.UID = "678901";
    addressUser tempU11 = alokasiUser(tempUser);
    insertLastUser(users, tempU11);
    insertLastRelasiUser(relasiUser(tempC1), alokasiRelasiUser(tempU11));
    info(tempC1).nUser++;

    // User 12
    tempUser.name = "Jasmine";
    tempUser.password = "jasmine123";
    tempUser.role = "Mahasiswa";
    tempUser.UID = "789012";
    addressUser tempU12 = alokasiUser(tempUser);
    insertLastUser(users, tempU12);
    insertLastRelasiUser(relasiUser(tempC2), alokasiRelasiUser(tempU12));
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
            cout << "Masukan ID: ";
            cin >> id;
            tempUser.UID = id;
            cout << "Masukan password: ";
            cin >> pass;
            tempUser.password = pass;
            cout << "Masukan role (Mahasiswa/Dosen): ";
            cin >> role;
            tempUser.role = role;
            cout << "Masukan course: ";
            cin >> code;

            tempC = findElmCourse(courses, code);
            tempU = alokasiUser(tempUser);
            insertLastUser(users, tempU);
            insertLastRelasiUser(relasiUser(tempC), alokasiRelasiUser(tempU));
            info(tempC).nUser++;

            cout << "Akun berhasil terdaftar." << endl;
        } else if (menu == 2) {
            cout << "Masukan ID: ";
            cin >> id;
            cout << "Masukan password: ";
            cin >> pass;

            tempU = findElmUser(users, id);
            if (tempU != NULL && info(tempU).password == pass) {
                cout << "Berhasil login." << endl;
                login = true;
                role = info(tempU).role;
            } else {
                cout << "Akun belum terdaftar atau password salah." << endl;
                login = false;
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
                                        cout << "Nama course: ";
                                        cin.ignore();
                                        getline(cin, tempCourse.name);
                                        cout << "Kode course: ";
                                        cin >> tempCourse.code;
                                        insertLastCourse(courses, alokasiCourse(tempCourse));
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
                                    cout << "7. ADD STUDENT" << endl;
                                    cout << "8. BACK TO COURSES" << endl;
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
                                    } else if (menu == 7) {
                                        cout << "=====ADD STUDENT=====" << endl;
                                        cout << "UID mahasiswa: ";
                                        cin >> tempID;
                                        tempU = findElmUser(users, tempID);

                                        if (tempU != NULL){
                                            cout << "Kode course: ";
                                            cin >> code;
                                            tempC = findElmCourse(courses, code);
                                            insertLastRelasiUser(relasiUser(tempC), alokasiRelasiUser(tempU));
                                            info(tempC).nUser++;
                                        }
                                    }
                                } while (menu != 8);
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
