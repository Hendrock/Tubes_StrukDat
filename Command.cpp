#include "Student.h"
#include "Lecturer.h"
#include "Course.h"

void jawabQuiz(ListCourse L){

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
