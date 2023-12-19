#ifndef RELASISTUDENT_H_INCLUDED
#define RELASISTUDENT_H_INCLUDED

#include "Student.h"
#include "Course.h"

#include <iostream>
#include <string>

using namespace std;

#define next(P) P->next
#define child(P) P->student
#define first(L) L.first
#define last(L) L.last

typedef struct elmlistRelasiStudent *addressRelasiStudent;

struct elmlistRelasiStudent {
    addressRelasiStudent next;
    addressStudent student;
};

struct ListRelasiStudent {
    addressRelasiStudent first, last;
};

void createListRelasiStudent(ListRelasiStudent &L);
void insertFirstRelasiStudent(ListRelasiStudent &L, addressRelasiStudent P);
void insertLastRelasiStudent(ListRelasiStudent &L, addressRelasiStudent P);
void insertAfterRelasiStudent(ListRelasiStudent &L, addressRelasiStudent Prec, addressRelasiStudent P);
void deleteFirstRelasiStudent(ListRelasiStudent &L, addressRelasiStudent &P);
void deleteLastRelasiStudent(ListRelasiStudent &L, addressRelasiStudent &P);
void deleteAfterRelasiStudent(ListRelasiStudent &L, addressRelasiStudent Prec, addressRelasiStudent &P);

addressRelasiStudent alokasiRelasiStudent(addressStudent student);
void dealokasiRelasiStudent(addressRelasiStudent &P);

#endif // RELASISTUDENT_H_INCLUDED
