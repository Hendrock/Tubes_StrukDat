#ifndef RELASICOURSELECTURER_H_INCLUDED
#define RELASICOURSELECTURER_H_INCLUDED

#include "Lecturer.h"
#include "Course.h"

#include <iostream>
#include <string>

using namespace std;

#define next(P) P->next
#define child(P) P->lecturer
#define parent(P) P->course
#define first(L) L.first
#define last(L) L.last

typedef struct elmlistRelasiCourseLecturer *addressRelasiCourseLecturer;

struct elmlistRelasiCourseLecturer {
    addressRelasiCourseLecturer next;
    addressCourse course;
    addressLecturer lecturer;
};

struct ListRelasiCourseLecturer {
    addressRelasiCourseLecturer first, last;
};

void createListRelasiCourseLecturer(ListRelasiCourseLecturer &L);
void insertFirstRelasiCourseLecturer(ListRelasiCourseLecturer &L, addressRelasiCourseLecturer P);
void insertLastRelasiCourseLecturer(ListRelasiCourseLecturer &L, addressRelasiCourseLecturer P);
void insertAfterRelasiCourseLecturer(ListRelasiCourseLecturer &L, addressRelasiCourseLecturer Prec, addressRelasiCourseLecturer P);
void deleteFirstRelasiCourseLecturer(ListRelasiCourseLecturer &L, addressRelasiCourseLecturer &P);
void deleteLastRelasiCourseLecturer(ListRelasiCourseLecturer &L, addressRelasiCourseLecturer &P);
void deleteAfterRelasiCourseLecturer(ListRelasiCourseLecturer &L, addressRelasiCourseLecturer Prec, addressRelasiCourseLecturer &P);

addressRelasiCourseLecturer alokasiRelasiCourseLecturer(addressCourse course, addressLecturer lecturer);
void dealokasiRelasiCourseLecturer(addressRelasiCourseLecturer &P);

#endif // RELASICOURSELECTURER_H_INCLUDED
