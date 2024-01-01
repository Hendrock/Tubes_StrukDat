#include "RelasiUser.h"

void createListRelasiUser(ListRelasiUser &L) {
    first(L) = NULL;
    last(L) = NULL;
}

addressRelasiUser alokasiRelasiUser(addressUser User) {
    addressRelasiUser P = new elmlistRelasiUser;
    user(P) = User;
    next(P) = NULL;
    return P;
}

void dealokasiRelasiUser(addressRelasiUser &P) {
    delete P;
}

void insertFirstRelasiUser(ListRelasiUser &L, addressRelasiUser P) {
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}

void insertLastRelasiUser(ListRelasiUser &L, addressRelasiUser P) {
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(last(L)) = P;
        last(L) = P;
    }
}

void insertAfterRelasiUser(ListRelasiUser &L, addressRelasiUser Prec, addressRelasiUser P) {
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void deleteFirstRelasiUser(ListRelasiUser &L, addressRelasiUser &P) {
    if (first(L) == NULL) {
        cout << "List Kosong" << endl;
    } else {
        P = first(L);
        if (first(L) == last(L)) {
            first(L) = NULL;
            last(L) = NULL;
        } else {
            first(L) = next(P);
        }
        next(P) = NULL;
    }
}

void deleteLastRelasiUser(ListRelasiUser &L, addressRelasiUser &P) {
    if (first(L) == NULL) {
        cout << "List Kosong" << endl;
    } else {
        P = first(L);
        if (first(L) == last(L)) {
            first(L) = NULL;
            last(L) = NULL;
        } else {
            while (next(P) != last(L)) {
                P = next(P);
            }
            next(P) = NULL;
            last(L) = P;
            P = next(P);
        }
    }
}

void deleteAfterRelasiUser(ListRelasiUser &L, addressRelasiUser Prec, addressRelasiUser &P) {
    if (first(L) == NULL) {
        cout << "List Kosong" << endl;
    } else {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}
