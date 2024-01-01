#include "User.h"

void createListUser(ListUser &L) {
    first(L) = NULL;
    last(L) = NULL;
}

addressUser alokasiUser(infotypeUser x) {
    addressUser P = new elmlistUser;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void dealokasiUser(addressUser &P) {
    delete P;
}

void insertFirstUser(ListUser &L, addressUser P) {
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
        next(P) = P;
    } else {
        next(P) = first(L);
        last(L)->next = P;
        first(L) = P;
    }
}

void insertLastUser(ListUser &L, addressUser P) {
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
        next(P) = P;
    } else {
        next(last(L)) = P;
        next(P) = first(L);
        last(L) = P;
    }
}

void insertAfterUser(ListUser &L, addressUser Prec, addressUser P) {
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
        next(P) = P;
    } else if (Prec == last(L)) {
        next(Prec) = P;
        next(P) = first(L);
        last(L) = P;
    } else {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void deleteFirstUser(ListUser &L, addressUser &P) {
    if (first(L) == NULL) {
        cout << "List Kosong" << endl;
    } else {
        P = first(L);
        if (first(L) == last(L)) {
            first(L) = NULL;
            last(L) = NULL;
        } else {
            first(L) = next(P);
            next(last(L)) = first(L);
        }
        next(P) = NULL;
    }
}

void deleteLastUser(ListUser &L, addressUser &P) {
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
            next(P) = first(L);
            last(L) = P;
            P = next(P);
        }
    }
}

void deleteAfterUser(ListUser &L, addressUser Prec, addressUser &P) {
    if (first(L) == NULL) {
        cout << "List Kosong" << endl;
    } else {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

addressUser findElmUser(ListUser L, string UID) {
    addressUser P = first(L);
    do {
        if (info(P).UID == UID) {
            return P;
        }
        P = next(P);
    } while (P != first(L));
    return NULL;
}

void printInfoUser(ListUser L) {
    cout << "-----------------------------------" << endl;
    if (first(L) != NULL) {
        addressUser P = first(L);
        do {
            cout << "Nama: " << info(P).nama << endl;
            cout << "NIM: " << info(P).UID << endl;
            cout << endl;
            P = next(P);
        } while (P != first(L));
    } else {
        cout << "List Kosong" << endl;
    }
    cout << "-----------------------------------" << endl;
}
