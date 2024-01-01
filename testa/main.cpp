#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Course.h"
#include "User.h"
#include "RelasiUser.h"

using namespace std;


int main() {
    int n,x;
    string nama,pass,id,Role,Kode;
    ListCourse courses;
    ListUser users;

    createListCourse(courses);
    createListUser(users);

//inisialisasi 5 course dan 7 user(5 dosen & 2 mahasiswa)
    //course 1
    infotypeCourse tempCourse;
    tempCourse.kode = "MATH101";
    tempCourse.nama = "Mathematics I";
    tempCourse.tugas = "Homework 1";
    addressCourse tempC1 = alokasiCourse(tempCourse);
    insertLastCourse(courses, tempC1);
    //course 2

    tempCourse.kode = "CS202";
    tempCourse.nama = "Data Structures";
    tempCourse.tugas = "Programming Project";
    addressCourse tempC2 = alokasiCourse(tempCourse);
    insertLastCourse(courses, tempC2);
    //course 3

    tempCourse.kode = "ENG301";
    tempCourse.nama = "Advanced English";
    tempCourse.tugas = "Essay";
    addressCourse tempC3 = alokasiCourse(tempCourse);
    insertLastCourse(courses, tempC3);
    //course 4

    tempCourse.kode = "PHYS102";
    tempCourse.nama = "Physics II";
    tempCourse.tugas = "Lab Report";
    addressCourse tempC4 = alokasiCourse(tempCourse);
    insertLastCourse(courses, tempC4);
    //course 5

    tempCourse.kode = "CHEM201";
    tempCourse.nama = "Organic Chemistry";
    tempCourse.tugas = "Research Paper";
    addressCourse tempC5 = alokasiCourse(tempCourse);
    insertLastCourse(courses, tempC5);

    //user 1
    infotypeUser tempUser;
    tempUser.nama = "Alice";
    tempUser.password = "alice123";
    tempUser.role = "Dosen";
    tempUser.UID = "123456";
    addressUser tempU1 = alokasiUser(tempUser);
    insertLastUser(users, tempU1);
    insertLastRelasiUser(relasiUser(tempC5), alokasiRelasiUser(tempU1));
     //user 2

    tempUser.nama = "Bob";
    tempUser.password = "bob456";
    tempUser.role = "Dosen";
    tempUser.UID = "987654";
    addressUser tempU2 = alokasiUser(tempUser);
    insertLastUser(users, tempU2);
    insertLastRelasiUser(relasiUser(tempC2), alokasiRelasiUser(tempU2));
    //user 3

    tempUser.nama = "Charlie";
    tempUser.password = "charlie789";
    tempUser.role = "Dosen";
    tempUser.UID = "654321";
    addressUser tempU3 = alokasiUser(tempUser);
    insertLastUser(users, tempU3);
    insertLastRelasiUser(relasiUser(tempC3), alokasiRelasiUser(tempU3));
     //user 4

    tempUser.nama = "David";
    tempUser.password = "david987";
    tempUser.role = "Dosen";
    tempUser.UID = "123789";
    addressUser tempU4 = alokasiUser(tempUser);
    insertLastUser(users, tempU4);
    insertLastRelasiUser(relasiUser(tempC1), alokasiRelasiUser(tempU4));
     //user 5

    tempUser.nama = "Eve";
    tempUser.password = "eve654";
    tempUser.role = "Dosen";
    tempUser.UID = "789456";
    addressUser tempU5 = alokasiUser(tempUser);
    insertLastUser(users, tempU5);
    insertLastRelasiUser(relasiUser(tempC4), alokasiRelasiUser(tempU5));
    //user 6

    tempUser.nama = "John";
    tempUser.password = "doej614";
    tempUser.role = "Mahasiswa";
    tempUser.UID = "890123";
    addressUser tempU6 = alokasiUser(tempUser);
    insertLastUser(users, tempU6);
    insertLastRelasiUser(relasiUser(tempC1), alokasiRelasiUser(tempU6));
    //user 7

    tempUser.nama = "Jane";
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
            addressCourse tempC;
            infotypeUser tempUser;
            cout<<"=== Registrasi ==="<<endl;
            cout<<"Masukan Nama ";
            cin>>nama;
            tempUser.nama = nama;
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
            cin>>Kode;
            tempC = findElmCourse(courses,Kode);
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
        }else if (x==2){
                cout<<"================================================="<<endl;
                cout<<"================== MENU ========================="<<endl;
                cout<<"================================================="<<endl;

                cout<<"1. USER "<<endl;
                cout<<"2. DASHBOARD "<<endl;
                cout<<"MASUKAN PILIHAN MENU : ";
                cin>> n;
        }
}
}







    // Create lists for courses, users, and user-course relationships
