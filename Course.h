#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

#define next(P) P->next
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

const int NMAX = 50;

typedef struct Course infotypeCourse;
typedef struct elmlistCourse *addressCourse;

struct soalQuiz{
    string pertanyaan, jawaban;
    int point;
};

struct Course{
    string nama, kode, tugas;
    string[NMAX] forum;
    soalQuiz[NMAX] quiz;
    int nQuiz, nForum;
};

struct elmlistCourse{
    infotypeCourse info;
    addressCourse next;
    addressQuiz adrQuiz;
    addressForum adrForum;
    addressTugas adrTugas;
};

struct ListCourse{
    addressCourse first, last;
};

void createList(ListCourse &L);
void insertFirst(ListCourse &L, addressCourse P);
void insertLast(ListCourse &L, addressCourse P);
void insertAfter(addressCourse Prec, addressCourse P);
void deleteFirst(ListCourse &L, addressCourse &P);
void deleteLast(ListCourse &L, addressCourse &P);
void deleteAfter(addressCourse Prec, addressCourse &P);

addressCourse alokasi(infotypeCourse x);
void dealokasi(addressCourse &P);
addressCourse findElm(ListCourse L, infotypeCourse x);
void printInfo(ListCourse L);


#endif // COURSE_H_INCLUDED
