#include "RelasiStudent.h"

void createListRelasiStudent(ListRelasiStudent &L) {
    first(L) = NULL;
    last(L) = NULL;
}

addressRelasiStudent alokasiRelasiStudent(addressStudent student) {
    addressRelasiStudent P = new elmlistRelasiStudent;
    child(P) = student;
    next(P) = NULL;
    return P;
}

void dealokasiRelasiStudent(addressRelasiStudent &P) {
    delete P;
}

void insertFirstRelasiStudent(ListRelasiStudent &L, addressRelasiStudent P) {
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}

void insertLastRelasiStudent(ListRelasiStudent &L, addressRelasiStudent P) {
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(last(L)) = P;
        last(L) = P;
    }
}

void insertAfterRelasiStudent(ListRelasiStudent &L, addressRelasiStudent Prec, addressRelasiStudent P) {
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void deleteFirstRelasiStudent(ListRelasiStudent &L, addressRelasiStudent &P) {
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

void deleteLastRelasiStudent(ListRelasiStudent &L, addressRelasiStudent &P) {
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

void deleteAfterRelasiStudent(ListRelasiStudent &L, addressRelasiStudent Prec, addressRelasiStudent &P) {
    if (first(L) == NULL) {
        cout << "List Kosong" << endl;
    } else {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}