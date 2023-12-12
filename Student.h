#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

#define next(P) P->next
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

typedef struct Student infotypeStudent;
typedef struct elmlistStudent *addressStudent;

struct Student{
    string nama, nim, email, password;
    int nilai;
};

struct elmlistStudent{
    infotypeStudent info;
    addressStudent next;
};

struct ListStudent{
    addressStudent first, last;
};

void createList(ListStudent &L);
void insertFirst(ListStudent &L, addressStudent P);
void insertLast(ListStudent &L, addressStudent P);
void insertAfter(addressStudent Prec, addressStudent P);
void deleteFirst(ListStudent &L, addressStudent &P);
void deleteLast(ListStudent &L, addressStudent &P);
void deleteAfter(addressStudent Prec, addressStudent &P);

addressStudent alokasi(infotypeStudent x);
void dealokasi(addressStudent &P);
addressStudent findElm(ListStudent L, infotypeStudent x);
void printInfo(ListStudent L);

#endif // STUDENT_H_INCLUDED
