#ifndef LECTURER_H_INCLUDED
#define LECTURER_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

#define next(P) P->next
#define info(P) P->info
#define first(L) L.first
#define last(L) L.last

typedef struct string infotypeLecturer;
typedef struct elmlistLecturer *addressLecturer;

struct Lecturer {
    string nama, kode, email, password;
};

struct elmlistLecturer {
    infotypeLecturer info;
    addressLecturer next;
};

struct ListLecturer {
    addressLecturer first, last;
};

void createListLecturer(ListLecturer &L);
void insertFirstLecturer(ListLecturer &L, addressLecturer P);
void insertLastLecturer(ListLecturer &L, addressLecturer P);
void insertAfterLecturer(ListLecturer &L,addressLecturer Prec, addressLecturer P);
void deleteFirstLecturer(ListLecturer &L, addressLecturer &P);
void deleteLastLecturer(ListLecturer &L, addressLecturer &P);
void deleteAfterLecturer(ListLecturer &L,addressLecturer Prec, addressLecturer &P);

addressLecturer alokasiLecturer(infotypeLecturer x);
void dealokasiLecturer(addressLecturer &P);
addressLecturer findElmLecturer(ListLecturer L, string kode);
void printInfoLecturer(ListLecturer L);

#endif // LECTURER_H_INCLUDED
