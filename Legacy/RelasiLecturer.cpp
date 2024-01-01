#include "RelasiLecturer.h"

void createListRelasiLecturer(ListRelasiLecturer &L) {
    first(L) = NULL;
    last(L) = NULL;
}

addressRelasiLecturer alokasiRelasiLecturer(addressLecturer lecturer) {
    addressRelasiLecturer P = new elmlistRelasiLecturer;
    child(P) = lecturer;
    next(P) = NULL;
    return P;
}

void dealokasiRelasiLecturer(addressRelasiLecturer &P) {
    delete P;
}

void insertFirstRelasiLecturer(ListRelasiLecturer &L, addressRelasiLecturer P) {
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}

void insertLastRelasiLecturer(ListRelasiLecturer &L, addressRelasiLecturer P) {
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(last(L)) = P;
        last(L) = P;
    }
}

void insertAfterRelasiLecturer(ListRelasiLecturer &L, addressRelasiLecturer Prec, addressRelasiLecturer P) {
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void deleteFirstRelasiLecturer(ListRelasiLecturer &L, addressRelasiLecturer &P) {
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

void deleteLastRelasiLecturer(ListRelasiLecturer &L, addressRelasiLecturer &P) {
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

void deleteAfterRelasiLecturer(ListRelasiLecturer &L, addressRelasiLecturer Prec, addressRelasiLecturer &P) {
    if (first(L) == NULL) {
        cout << "List Kosong" << endl;
    } else {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}
