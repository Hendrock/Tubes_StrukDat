#ifndef RELASICOURSESTUDENT_H_INCLUDED
#define RELASICOURSESTUDENT_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

#include "Student.h"
#include "Course.h"

#define next(P) P->next
#define child(P) P->child
#define parent(P) P->parent
#define first(L) L.first
#define last(L) L.last

typedef struct elmlistRelasiCourseStudent *addressRelasiCourseStudent;

struct elmlistRelasiCourseStudent{
    addressRelasiCourseStudent next;
    addressCourse parent;
    addressStudent child;
};

struct ListRelasiCourseStudent{
    addressRelasiCourseStudent first, last;
};

void createListRelasiCourseStudent(ListRelasiCourseStudent &L);
void insertFirstRelasiCourseStudent(ListRelasiCourseStudent &L, addressRelasiCourseStudent P);
void insertLastRelasiCourseStudent(ListRelasiCourseStudent &L, addressRelasiCourseStudent P);
void insertAfterRelasiCourseStudent(ListRelasiCourseStudent &L, addressRelasiCourseStudent Prec, addressRelasiCourseStudent P);
void deleteFirstRelasiCourseStudent(ListRelasiCourseStudent &L, addressRelasiCourseStudent &P);
void deleteLastRelasiCourseStudent(ListRelasiCourseStudent &L, addressRelasiCourseStudent &P);
void deleteAfterRelasiCourseStudent(ListRelasiCourseStudent &L, addressRelasiCourseStudent Prec, addressRelasiCourseStudent &P);

addressRelasiCourseStudent alokasi(addressCourse P, addressStudent C);
void dealokasi(addressRelasiCourseStudent &P);
addressRelasiCourseStudent findElm(ListRelasiCourseStudent L, addressCourse P, addressStudent C);
void printInfo(ListRelasiCourseStudent L);

#endif // RELASICOURSESTUDENT_H_INCLUDED
