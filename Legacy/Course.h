#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

#define next(P) P->next
#define info(P) P->info
#define first(L) L.first
#define last(L) L.last
#define relasiStudent(P) P->relasiStudentList
#define relasiLecturer(P) P->relasiLecturerList

const int NMAX = 50;

struct soalQuiz {
    string pertanyaan, jawaban;
    int point;
};

struct nilaiQuiz {
    string NIM;
    int quizScore;
};

struct Course {
    string nama, kode, tugas;
    string forum[NMAX];
    soalQuiz quiz[NMAX];
    nilaiQuiz nilai[NMAX];
    int nQuiz, nForum, nStudent;
};

typedef struct string infotypeCourse;
typedef struct elmlistCourse *addressCourse;

struct ListRelasiCourseStudent;
struct ListRelasiCourseLecturer;

struct elmlistCourse {
    infotypeCourse info;
    addressCourse next;
    ListRelasiCourseStudent* relasiStudentList;
    ListRelasiCourseLecturer* relasiLecturerList;
};

struct ListCourse {
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
addressCourse findElmCourse(ListCourse L, string kode);
void printInfoCourse(ListCourse L);

#endif // COURSE_H_INCLUDED
