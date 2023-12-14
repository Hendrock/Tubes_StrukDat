#ifndef RELASICOURSELECTURER_H_INCLUDED
#define RELASICOURSELECTURER_H_INCLUDED

#include "Lecturer.h"
#include "Course.h"

#define next(P) P->next
#define child(P) P->child
#define parent(P) P->parent
#define first(L) L.first
#define last(L) L.last

typedef struct elmlistRelasiCourseLecturer *addressRelasiCourseLecturer;

struct elmlistRelasiCourseLecturer{
    addressRelasiCourseLecturer next;
    addressCourse parent;
    addressLecturer child;
};

struct ListRelasiCourseLecturer{
    addressRelasiCourseLecturer first, last;
};

void createListRelasiCourseLecturer(ListRelasiCourseLecturer &L);
void insertFirstRelasiCourseLecturer(ListRelasiCourseLecturer &L, addressRelasiCourseLecturer P);
void insertLastRelasiCourseLecturer(ListRelasiCourseLecturer &L, addressRelasiCourseLecturer P);
void insertAfterRelasiCourseLecturer(ListRelasiCourseLecturer &L, addressRelasiCourseLecturer Prec, addressRelasiCourseLecturer P);
void deleteFirstRelasiCourseLecturer(ListRelasiCourseLecturer &L, addressRelasiCourseLecturer &P);
void deleteLastRelasiCourseLecturer(ListRelasiCourseLecturer &L, addressRelasiCourseLecturer &P);
void deleteAfterRelasiCourseLecturer(ListRelasiCourseLecturer &L, addressRelasiCourseLecturer Prec, addressRelasiCourseLecturer &P);

addressRelasiCourseLecturer alokasi(addressCourse P, addressLecturer C);
void dealokasi(addressRelasiCourseLecturer &P);
addressRelasiCourseLecturer findElm(ListRelasiCourseLecturer L, addressCourse P, addressLecturer C);
void printInfo(ListRelasiCourseLecturer L);

#endif // RELASICOURSELECTURER_H_INCLUDED
