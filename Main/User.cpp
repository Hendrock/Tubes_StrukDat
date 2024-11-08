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

void deleteSpesificUser(ListUser &L, string UID){
    addressUser P = findElmUser(L, UID);

    if (P != NULL){
        if (P == first(L)){
            deleteFirstUser(L, P);
        } else if (P == last(L)){
            deleteLastUser(L, P);
        } else {
            addressUser Q = first(L);
            while (next(Q) != P){
                Q = next(Q);
            }
            deleteAfterUser(L, Q, P);
        }
    } else {
        printf("User %s tidak ditemukan.\n", UID.c_str());
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

void printAllUsers(ListUser L){
    addressUser P = first(L);

    if (P != NULL){
        do {
            printf("%s (User ID: %s) - %s\n", info(P).name.c_str(), info(P).UID.c_str(), info(P).role.c_str());
            P = next(P);
        } while (P != first(L));
    } else {
        cout << "List kosong." << endl;
    }
}

void printUser(ListUser L, string UID){
    addressUser P = findElmUser(L, UID);

    if (P != NULL){
        printf("%s (User ID: %s)\n", info(P).name.c_str(), info(P).UID.c_str());
    } else {
        printf("User %s tidak ditemukan.\n", UID.c_str());
    }
}
