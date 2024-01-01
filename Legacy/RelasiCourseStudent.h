#ifndef RELASICOURSESTUDENT_H_INCLUDED
#define RELASICOURSESTUDENT_H_INCLUDED

#include "Student.h"
#include "Course.h"

#include <iostream>
#include <string>

using namespace std;

#define next(P) P->next
#define child(P) P->student
#define parent(P) P->course
#define first(L) L.first
#define last(L) L.last

typedef struct elmlistRelasiCourseStudent *addressRelasiCourseStudent;

struct elmlistRelasiCourseStudent {
    addressRelasiCourseStudent next;
    addressCourse course;
    addressStudent student;
};

struct ListRelasiCourseStudent {
    addressRelasiCourseStudent first, last;
};

void createListRelasiCourseStudent(ListRelasiCourseStudent &L);
void insertFirstRelasiCourseStudent(ListRelasiCourseStudent &L, addressRelasiCourseStudent P);
void insertLastRelasiCourseStudent(ListRelasiCourseStudent &L, addressRelasiCourseStudent P);
void insertAfterRelasiCourseStudent(ListRelasiCourseStudent &L, addressRelasiCourseStudent Prec, addressRelasiCourseStudent P);
void deleteFirstRelasiCourseStudent(ListRelasiCourseStudent &L, addressRelasiCourseStudent &P);
void deleteLastRelasiCourseStudent(ListRelasiCourseStudent &L, addressRelasiCourseStudent &P);
void deleteAfterRelasiCourseStudent(ListRelasiCourseStudent &L, addressRelasiCourseStudent Prec, addressRelasiCourseStudent &P);

addressRelasiCourseStudent alokasiRelasiCourseStudent(addressCourse course, addressStudent student);
void dealokasiRelasiCourseStudent(addressRelasiCourseStudent &P);

#endif // RELASICOURSESTUDENT_H_INCLUDED
