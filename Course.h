#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

#define nextCourse(P) P->nextCourse
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
    infotypeCourse infoCourse;
    addressCourse nextCourse;
    addressLecturer adrLecturer;
    addressStudent adrStudent;
};

struct ListCourse{
    addressCourse first, last;
};

void createListCourse(ListCourse &L);
void insertFirstCourse(ListCourse &L, addressCourse P);
void insertLastCourse(ListCourse &L, addressCourse P);
void insertAfterCourse(ListCourse &L, addressCourse Prec, addressCourse P);
void deleteFirstCourse(ListCourse &L, addressCourse &P);
void deleteLastCourse(ListCourse &L, addressCourse &P);
void deleteAfterCourse(ListCourse &L, addressCourse Prec, addressCourse &P);

addressCourse alokasiCourse(infotypeCourse x);
void dealokasiCourse(addressCourse &P);
addressCourse findElmCourse(ListCourse L, infotypeCourse x);
void printInfoCourse(ListCourse L);


#endif // COURSE_H_INCLUDED
