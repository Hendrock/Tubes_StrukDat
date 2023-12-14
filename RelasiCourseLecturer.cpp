#include "RelasiCourseLecturer.h"

void createListRelasiCourseLecturer(ListRelasiCourseLecturer &L){
    first(L) = NULL;
    last(L) = NULL;
}

void insertFirstRelasiCourseLecturer(ListRelasiCourseLecturer &L, addressRelasiCourseLecturer P){
    if (first(L) == NULL){
        first(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}

void insertLastRelasiCourseLecturer(ListRelasiCourseLecturer &L, addressRelasiCourseLecturer P){
    if (fisrt(L) == NULL){
        first(L) == P;
    } else {
        next(last(L)) = P;
        last(L) = P;
    }
}

void insertAfterRelasiCourseLecturer(ListRelasiCourseLecturer &L, addressRelasiCourseLecturer Prec, addressRelasiCourseLecturer P){
    if (first(L) == NULL){
        first(L) = P;
    } else {
        next(P) = next(Prec);
        next(Prec) = P;
    }        
}

void deleteFirstRelasiCourseLecturer(ListRelasiCourseLecturer &L, addressRelasiCourseLecturer &P){
    if (first(L) == NULL){
        cout << "List Kosong" << endl;
    } else if (next(first(L)) == NULL){
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
    } else {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}

void deleteLastRelasiCourseLecturer(ListRelasiCourseLecturer &L, addressRelasiCourseLecturer &P){
    if (first(L) == NULL){
        cout << "List Kosong" << endl;
    } else if (next(first(L)) == NULL){
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
    } else {
        addressLastRelasiCourseLecturer Q;
        P = first(L);
        while (P != NULL){
            Q = P;
            P = next(P);
        }
        next(Q) = NULL;
        last(L) = Q; 
    }
}

void deleteAfterRelasiCourseLecturer(ListRelasiCourseLecturer &L, addressRelasiCourseLecturer Prec, addressRelasiCourseLecturer &P){
    if (first(L) == NULL){
        cout << "List Kosong" << endl;
    } else if (next(first(L)) == NULL){
        P = first(L);
        first(L) = NULL;
    } else {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

addressRelasiCourseLecturer alokasiRelasiCourseLecturer(infotypeRelasiCourseLecturer x){
    addressRelasiCourseLecturer P = new elmlistRelasiCourseLecturer;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void dealokasiRelasiCourseLecturer(addressRelasiCourseLecturer &P){
    delete (P);
}

addressRelasiCourseLecturer findElmRelasiCourseLecturer(ListRelasiCourseLecturer L, string x){
    addressRelasiCourseLecturer P = first(L);

    do{
        if (info(P).kode == x){
            return P;
        }
        P = next(P);
    }(while P != NULL);
}

void printInfoRelasiCourseLecturer(ListRelasiCourseLecturer L){
    addressRelasiCourseLecturer P = first(L);

    cout << "-----------------------------------" << endl;
    if (P == NULL){
        cout << "List Kosong" << endl;
    } else {
        do{
            cout << "Nama Mata Kuliah: " <<  info(P).nama << endl;
            cout << "Kode Mata Kuliah: " <<  info(P).kode << endl;
            cout << endl;
            P = next(P);
        }(while P != NULL);
    }
    cout << "-----------------------------------" << endl;
}
