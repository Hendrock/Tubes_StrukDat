#include "Student.h"
#include "Lecturer.h"
#include "Course.h"

void jawabQuiz(ListCourse L){

}

void addQuiz(ListCourse &L){
    string tempKode, tempSoal, tempJawaban;
    int tempPoint;

    cin >> tempKode;
    addressCourse P = findElm(L, tempKode);

    int index = info(P).nQuiz;

    cin >> tempSoal;
    info(P).quiz[index].pertanyaan = tempSoal;

    cin >> tempJawaban;
    info(P).quiz[index].jawaban = tempJawaban;

    cin >> tempPoint;
    info(P).quiz[index].point = tempPoint;
}

void showQuiz(List)
