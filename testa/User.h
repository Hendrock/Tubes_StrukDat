#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

#define next(P) P->next
#define info(P) P->info
#define first(L) L.first
#define last(L) L.last

typedef struct User infotypeUser;
typedef struct elmlistUser *addressUser;

struct User{
    string nama, UID, password, role;
};

struct elmlistUser{
    infotypeUser info;
    addressUser next;
};

struct ListUser{
    addressUser first, last;
};

void createListUser(ListUser &L);
void insertFirstUser(ListUser &L, addressUser P);
void insertLastUser(ListUser &L, addressUser P);
void insertAfterUser(ListUser &L, addressUser Prec, addressUser P);
void deleteFirstUser(ListUser &L, addressUser &P);
void deleteLastUser(ListUser &L, addressUser &P);
void deleteAfterUser(ListUser &L, addressUser Prec, addressUser &P);

addressUser alokasiUser(infotypeUser x);
void dealokasiUser(addressUser &P);
addressUser findElmUser(ListUser L, string nim);
void printInfoUser(ListUser L);

#endif // USER_H_INCLUDED
