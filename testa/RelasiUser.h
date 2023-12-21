#ifndef RELASIUSER_H_INCLUDED
#define RELASIUSER_H_INCLUDED

#include "User.h"

#include <iostream>
#include <string>

using namespace std;

#define next(P) P->next
#define user(P) P->User
#define first(L) L.first
#define last(L) L.last

typedef struct elmlistRelasiUser *addressRelasiUser;

struct Course;

struct elmlistRelasiUser {
    addressRelasiUser next;
    addressUser User;
};

struct ListRelasiUser {
    addressRelasiUser first, last;
};

void createListRelasiUser(ListRelasiUser &L);
void insertFirstRelasiUser(ListRelasiUser &L, addressRelasiUser P);
void insertLastRelasiUser(ListRelasiUser &L, addressRelasiUser P);
void insertAfterRelasiUser(ListRelasiUser &L, addressRelasiUser Prec, addressRelasiUser P);
void deleteFirstRelasiUser(ListRelasiUser &L, addressRelasiUser &P);
void deleteLastRelasiUser(ListRelasiUser &L, addressRelasiUser &P);
void deleteAfterRelasiUser(ListRelasiUser &L, addressRelasiUser Prec, addressRelasiUser &P);

addressRelasiUser alokasiRelasiUser(addressUser User);
void dealokasiRelasiUser(addressRelasiUser &P);

#endif // RELASIUSER_H_INCLUDED
