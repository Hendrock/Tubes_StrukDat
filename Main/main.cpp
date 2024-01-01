#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Course.h"
#include "User.h"
#include "RelasiUser.h"

using namespace std;


int main() {
    int n,x;
    string name,pass,id,Role,code,Task;
    addressCourse tempC;
    addressUser tempU;
    infotypeUser tempUser;
    infotypeCourse tempCourse;

    ListCourse courses;
    ListUser users;

    createListCourse(courses);
    createListUser(users);

//inisialisasi 5 course dan 7 user(5 dosen & 2 mahasiswa)
    //course 1

    tempCourse.code = "MATH101";
    tempCourse.name = "Mathematics I";
    tempCourse.task = "Homework 1";
    addressCourse tempC1 = alokasiCourse(tempCourse);
    insertLastCourse(courses, tempC1);
    //course 2

    tempCourse.code = "CS202";
    tempCourse.name = "Data Structures";
    tempCourse.task = "Programming Project";
    addressCourse tempC2 = alokasiCourse(tempCourse);
    insertLastCourse(courses, tempC2);
    //course 3

    tempCourse.code = "ENG301";
    tempCourse.name = "Advanced English";
    tempCourse.task = "Essay";
    addressCourse tempC3 = alokasiCourse(tempCourse);
    insertLastCourse(courses, tempC3);
    //course 4

    tempCourse.code = "PHYS102";
    tempCourse.name = "Physics II";
    tempCourse.task = "Lab Report";
    addressCourse tempC4 = alokasiCourse(tempCourse);
    insertLastCourse(courses, tempC4);
    //course 5

    tempCourse.code = "CHEM201";
    tempCourse.name = "Organic Chemistry";
    tempCourse.task = "Research Paper";
    addressCourse tempC5 = alokasiCourse(tempCourse);
    insertLastCourse(courses, tempC5);

    //user 1

    tempUser.name = "Alice";
    tempUser.password = "alice123";
    tempUser.role = "Dosen";
    tempUser.UID = "123456";
    addressUser tempU1 = alokasiUser(tempUser);
    insertLastUser(users, tempU1);
    insertLastRelasiUser(relasiUser(tempC5), alokasiRelasiUser(tempU1));
     //user 2

    tempUser.name = "Bob";
    tempUser.password = "bob456";
    tempUser.role = "Dosen";
    tempUser.UID = "987654";
    addressUser tempU2 = alokasiUser(tempUser);
    insertLastUser(users, tempU2);
    insertLastRelasiUser(relasiUser(tempC2), alokasiRelasiUser(tempU2));
    //user 3

    tempUser.name = "Charlie";
    tempUser.password = "charlie789";
    tempUser.role = "Dosen";
    tempUser.UID = "654321";
    addressUser tempU3 = alokasiUser(tempUser);
    insertLastUser(users, tempU3);
    insertLastRelasiUser(relasiUser(tempC3), alokasiRelasiUser(tempU3));
     //user 4

    tempUser.name = "David";
    tempUser.password = "david987";
    tempUser.role = "Dosen";
    tempUser.UID = "123789";
    addressUser tempU4 = alokasiUser(tempUser);
    insertLastUser(users, tempU4);
    insertLastRelasiUser(relasiUser(tempC1), alokasiRelasiUser(tempU4));
     //user 5

    tempUser.name = "Eve";
    tempUser.password = "eve654";
    tempUser.role = "Dosen";
    tempUser.UID = "789456";
    addressUser tempU5 = alokasiUser(tempUser);
    insertLastUser(users, tempU5);
    insertLastRelasiUser(relasiUser(tempC4), alokasiRelasiUser(tempU5));
    //user 6

    tempUser.name = "John";
    tempUser.password = "doej614";
    tempUser.role = "Mahasiswa";
    tempUser.UID = "890123";
    addressUser tempU6 = alokasiUser(tempUser);
    insertLastUser(users, tempU6);
    insertLastRelasiUser(relasiUser(tempC1), alokasiRelasiUser(tempU6));
    //user 7

    tempUser.name = "Jane";
    tempUser.password = "jane456";
    tempUser.role = "Mahasiswa";
    tempUser.UID = "789012";
    addressUser tempU7 = alokasiUser(tempUser);
    insertLastUser(users, tempU7);
    insertLastRelasiUser(relasiUser(tempC2), alokasiRelasiUser(tempU7));





cout<<"================================================="<<endl;
cout<<"================== MENU ========================="<<endl;
cout<<"================================================="<<endl;

cout<<"1. USER "<<endl;
cout<<"2. DASHBOARD "<<endl;
cout<<"MASUKAN PILIHAN MENU : ";
cin>> n;

if (n==1){
    cout<<"================================================="<<endl;
    cout<<"================== MENU ========================="<<endl;
    cout<<"================================================="<<endl;
    cout<<"1. REGISTER "<<endl;
    cout<<"2. LOGIN "<<endl;
    cout<<"3. HOME "<<endl;
    cout<<"MASUKAN PILIHAN MENU : ";
    cin>> x;
        if (x == 1){
            cout<<"=====List Mata Kuliah===="<<endl;
            printInfoCourse(courses);

            cout<<"=== Registrasi ==="<<endl;
            cout<<"Masukan name ";
            cin>>name;
            tempUser.name = name;
            cout<<"Masukan Password ";
            cin>> pass;
            tempUser.password = pass;
            cout<<"Masukan Role(Pilihan : Mhs/Dsn) ";
            cin>> Role;
            tempUser.role = Role;
            cout<<"Masukan ID ";
            cin>> id;
            tempUser.UID = id;
            cout<<"Masukan course : ";
            cin>>code;
            tempC = findElmCourse(courses,code);
            addressUser tempU = alokasiUser(tempUser);
            insertLastUser(users, tempU);
            insertLastRelasiUser(relasiUser(tempC), alokasiRelasiUser(tempU));
            printInfoUser(users);
            cout<<"AKUN TEREGISTRASI"<<endl;
        }else if (x == 2){
            cout<<"Masukan ID ";
            cin>> id;
            cout<<"Masukan Password ";
            cin>> pass;
            if  (findElmUser(users,id) != NULL){
                cout<<"Akun telah login"<<endl;
            }else{
                cout<<"Akun belum terdaftar"<<endl;
            }
        }else if (x == 3){
            cout<<"================================================="<<endl;
            cout<<"================== MENU ========================="<<endl;
            cout<<"================================================="<<endl;

            cout<<"1. USER "<<endl;
            cout<<"2. DASHBOARD "<<endl;
            cout<<"MASUKAN PILIHAN MENU : ";
            cin>> n;
        }
}else if(n == 2){
    cout<<"================================================="<<endl;
    cout<<"================== DASHBOARD ========================="<<endl;
    cout<<"================================================="<<endl;
    cout<<"1. Course "<<endl;
    cout<<"2. HOME "<<endl;
    cout<<"MASUKAN PILIHAN MENU : ";
    cin>> x;
        if (x==1){
                cout<<"================================================="<<endl;
                cout<<"================== COURSE ========================="<<endl;
                cout<<"================================================="<<endl;
                printInfoCourse(courses);
                cout<<" Masukan Kode Courses :";
                cin>>code;
                tempC = findElmCourse(courses,code);
                tempCourse = info(tempC);
                cout<<"================================================="<<endl;
                cout<<"================== COURSE ========================="<<endl;
                cout<<"================================================="<<endl;
                cout<<"1. Deskripsi Course  "<<endl;
                cout<<"2. User Menu "<<endl;
                cout<<"3. Home "<<endl;
                cout<<"MASUKAN PILIHAN MENU : ";
                cin>> n;
                    if (n==1){
                        //nanti diisi fungsi descCourse
                    }else if (n==2){
                        cout<<"Masukan UID : ";
                        cin>>id;
                        tempU = findElmUser(users,id);
                        tempUser =info(tempU);
                        if (tempUser.role == "Mahasiswa"){
                                cout<<"================================================="<<endl;
                                cout<<"================== COURSE MAHASISWA ========================="<<endl;
                                cout<<"================================================="<<endl;
                                cout<<"1. Lihat Forum "<<endl;
                                cout<<"2. Kerjakan Quiz"<<endl;
                                cout<<"3. Nilai Quiz"<<endl;
                                cout<<"4. Lihat Tubes"<<endl;
                                cout<<"5. Back"<<endl;
                                cout<<"MASUKAN PILIHAN MENU : ";
                                cin>> x;
                                    if (x==1){
                                        printForum(courses,code);
                                    }else if (x==2){
                                        //doQuiz
                                    }else if (x==3){
                                        printQuiz(courses,code);
                                    }else if (x==4){
                                        cout<<(tempCourse.task)<<endl;
                                    }else if (x==5){
                                        cout<<"================================================="<<endl;
                                        cout<<"================== COURSE ========================="<<endl;
                                        cout<<"================================================="<<endl;
                                        cout<<"1. Deskripsi Course  "<<endl;
                                        cout<<"2. User Menu "<<endl;
                                        cout<<"3. Home "<<endl;
                                        cout<<"MASUKAN PILIHAN MENU : ";
                                        cin>> n;
                                    }

                        }else if (tempUser.role == "Dosen"){
                                cout<<"================================================="<<endl;
                                cout<<"================== COURSE Dosen ========================="<<endl;
                                cout<<"================================================="<<endl;
                                cout<<"1. Edit Forum "<<endl;
                                cout<<"2. Edit Quiz"<<endl;
                                cout<<"3. Edit Tugas"<<endl;
                                cout<<"4. Back"<<endl;
                                cout<<"MASUKAN PILIHAN MENU : ";
                                cin>> x;
                                if(x==1){
                                    cout<<"================================================="<<endl;
                                    cout<<"================== Edit Forum ========================="<<endl;
                                    cout<<"================================================="<<endl;
                                    cout<<"1. Tambah Forum "<<endl;
                                    cout<<"2. Hapus Forum"<<endl;
                                    cout<<"MASUKAN PILIHAN MENU : ";
                                    cin>> n;
                                        if (n==1){
                                            //addForum(courses,code);
                                        }else if (n==2){
                                            deleteForum(courses,code);
                                        }
                                }else if (x==2){
                                    cout<<"================================================="<<endl;
                                    cout<<"================== Edit Quiz ========================="<<endl;
                                    cout<<"================================================="<<endl;
                                    cout<<"1. Tambah Quiz "<<endl;
                                    cout<<"2. Hapus Quiz"<<endl;
                                    cout<<"2. Edit Quiz"<<endl;
                                    cout<<"MASUKAN PILIHAN MENU : ";
                                    cin>> n;
                                        if (n==1){
                                            addQuiz(courses,code);
                                        }else if (n==2){
                                            deleteQuiz(courses,code);
                                        }else if (n==3){
                                            editQuiz(courses,code);
                                        }
                                }else if (x==3){
                                    cout<<"Masukan Task Baru : ";
                                    cin>> Task;
                                    tempCourse.task = Task;
                                    cout<<"Tugas Berhasil diubah!"<<endl;
                                    printInfoCourse(courses);

                                }else if (x==4){
                                    cout<<"================================================="<<endl;
                                    cout<<"================== COURSE ========================="<<endl;
                                    cout<<"================================================="<<endl;
                                    cout<<"1. Deskripsi Course  "<<endl;
                                    cout<<"2. User Menu "<<endl;
                                    cout<<"3. Home "<<endl;
                                    cout<<"MASUKAN PILIHAN MENU : ";
                                    cin>> n;
                                }
                            }
                        }
        }
}
}








    // Create lists for courses, users, and user-course relationships
