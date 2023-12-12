#ifndef LECTURER_H_INCLUDED
#define LECTURER_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

#define next(P) P->next
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

typedef struct Lecturer infotypeLecturer;
typedef struct elmlistLecturer *addressLecturer;

struct Lecturer{
    string nama, kode, email, password;
};

struct elmlistLecturer{
    infotypeLecturer info;
    addressLecturer next;
};

struct ListLecturer{
    addressLecturer first, last;
};

void createList(ListLecturer &L);
void insertFirst(ListLecturer &L, addressLecturer P);
void insertLast(ListLecturer &L, addressLecturer P);
void insertAfter(addressLecturer Prec, addressLecturer P);
void deleteFirst(ListLecturer &L, addressLecturer &P);
void deleteLast(ListLecturer &L, addressLecturer &P);
void deleteAfter(addressLecturer Prec, addressLecturer &P);

addressLecturer alokasi(infotypeLecturer x);
void dealokasi(addressLecturer &P);
addressLecturer findElm(ListLecturer L, infotypeLecturer x);
void printInfo(ListLecturer L);


#endif // LECTURER_H_INCLUDED
