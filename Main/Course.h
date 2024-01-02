#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED

#include <iostream>
#include <string>

#include "relasiUser.h"

using namespace std;

#define next(P) P->next
#define info(P) P->info
#define relasiUser(P) P->relasiUserList
#define first(L) L.first
#define last(L) L.last

const int NMAX = 50;

struct elmForum {
    string title, body;
};

struct elmQuiz {
    string question, answer;
    int point;
};

struct elmResult {
    string UID;
    int score;
};

struct Course {
    string name, code, task;
    elmForum forum[NMAX];
    elmQuiz quiz[NMAX];
    elmResult result[NMAX];
    int nQuiz, nForum, nResult;
};

typedef struct Course infotypeCourse;
typedef struct elmlistCourse *addressCourse;

struct elmlistCourse {
    infotypeCourse info;
    addressCourse next;
    ListRelasiUser relasiUserList;
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
addressCourse findElmCourse(ListCourse L, string code);

void printAllCourses(ListCourse L);
void printCourse(ListCourse L, string code);
void printUsersInCourse(ListCourse L, string code);

void printForum(ListCourse L, string code);
void addForum(ListCourse &L, string code);
void deleteForum(ListCourse &L, string code);

void printQuiz(ListCourse L, string code);
void addQuiz(ListCourse &L, string code);
void deleteQuiz(ListCourse &L, string code);
void editQuiz(ListCourse &L, string code);
void doQuiz(ListCourse &L, string code, string UID);

void editTask(ListCourse &L, string code);


#endif // COURSE_H_INCLUDED
