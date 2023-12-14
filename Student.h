#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

#define next(P) P->next
#define info(P) P->info
#define first(L) L.first
#define last(L) L.last

typedef struct Student infotypeStudent;
typedef struct elmlistStudent *addressStudent;

struct Student{
    string nama, nim, email, password;
};

struct elmlistStudent{
    infotypeStudent info;
    addressStudent next;
};

struct ListStudent{
    addressStudent first, last;
};

void createListStudent(ListStudent &L);
void insertFirstStudent(ListStudent &L, addressStudent P);
void insertLastStudent(ListStudent &L, addressStudent P);
void insertAfterStudent(ListStudent &L, addressStudent Prec, addressStudent P);
void deleteFirstStudent(ListStudent &L, addressStudent &P);
void deleteLastStudent(ListStudent &L, addressStudent &P);
void deleteAfterStudent(ListStudent &L, addressStudent Prec, addressStudent &P);

addressStudent alokasiStudent(infotypeStudent x);
void dealokasiStudent(addressStudent &P);
addressStudent findElmStudent(ListStudent L, string nim);
void printInfoStudent(ListStudent L);

#endif // STUDENT_H_INCLUDED
