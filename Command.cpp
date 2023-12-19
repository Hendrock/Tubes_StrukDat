#include "Student.h"
#include "Lecturer.h"
#include "Course.h"

void add

void sortStudentScore(ListCourse LC, bool permission){
    if (!permission){
        cout << "Anda tidak dapat menggunakan fitur ini" << endl; 
    } else {
        string tempKode;

        cout << "Masukkan kode kelas yang ingin di sort: ";
        cin >> tempKode;

        addressCourse P = findElmCourse(LC, tempKode);

        if (P == NULL){
            cout << "Kelas tidak ditemukan." << endl;
        } else {
            string choice;

            cout << "Ascending/Descending? (A/D)";
            cin >> choice;
            
            for (int i = 0; i < NMAX-1; i++){
		        int index = i;
                for (int j = i+1; j < NMAX; j++){
                    
            }
        }
    }
}

void jawabQuiz(ListCourse LC, ListStudent &LS, bool permission){
    if (!permission){
        cout << "Anda tidak dapat menggunakan fitur ini" << endl; 
    } else {
        string tempKode;
        
        cout << "Masukkan kode Mahasiswa:";
        cin >> tempKode;

        addressStudent P = findElmStudent(LS, tempKode);

        if (P == NULL){
            cout << "Mahasiswa tidak ditemukan." << endl;
        } else {
            showAllStudentCourse(P);

            cout << ""
            
            int nSoal = 0;
            while (nSoal != NMAX){
                
            }
        }
    }
}

void addQuiz(ListCourse &L, bool permission){
    if (!permission){
        cout << "Anda tidak dapat menggunakan fitur ini" << endl; 
    } else {
        string tempKode;
        
        cout << "Kelas yang ingin ditambahkan Quiz";
        cin >> tempKode;

        addressCourse P = findElmCourse(L, tempKode);

        if (P == NULL){
            cout << "Kelas tidak ditemukan" << endl;
        } else {
            string tempSoal, tempJawaban;
            int tempPoint, index = info(P).nQuiz;

            cout << "Masukkan Pertanyaan" << endl;
            cin >> tempSoal;
            info(P).quiz[index].pertanyaan = tempSoal;

            cout << "Masukkan Jawaban" << endl;
            cin >> tempJawaban;
            info(P).quiz[index].jawaban = tempJawaban;

            cout << "Masukkan Poin" << endl;
            cin >> tempPoint;
            info(P).quiz[index].point = tempPoint;
        }
    }
}

void showQuiz(List)
