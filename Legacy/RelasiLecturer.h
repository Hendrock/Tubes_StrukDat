#ifndef RELASILECTURER_H_INCLUDED
#define RELASILECTURER_H_INCLUDED

#include "Lecturer.h"

#include <iostream>
#include <string>

using namespace std;

#define next(P) P->next
#define child(P) P->lecturer
#define first(L) L.first
#define last(L) L.last

typedef struct elmlistRelasiLecturer *addressRelasiLecturer;

struct elmlistRelasiLecturer {
    addressRelasiLecturer next;
    addressLecturer lecturer;
};

struct ListRelasiLecturer {
    addressRelasiLecturer first, last;
};

void createListRelasiLecturer(ListRelasiLecturer &L);
void insertFirstRelasiLecturer(ListRelasiLecturer &L, addressRelasiLecturer P);
void insertLastRelasiLecturer(ListRelasiLecturer &L, addressRelasiLecturer P);
void insertAfterRelasiLecturer(ListRelasiLecturer &L, addressRelasiLecturer Prec, addressRelasiLecturer P);
void deleteFirstRelasiLecturer(ListRelasiLecturer &L, addressRelasiLecturer &P);
void deleteLastRelasiLecturer(ListRelasiLecturer &L, addressRelasiLecturer &P);
void deleteAfterRelasiLecturer(ListRelasiLecturer &L, addressRelasiLecturer Prec, addressRelasiLecturer &P);

addressRelasiLecturer alokasiRelasiLecturer(addressLecturer lecturer);
void dealokasiRelasiLecturer(addressRelasiLecturer &P);

#endif // RELASILECTURER_H_INCLUDED
