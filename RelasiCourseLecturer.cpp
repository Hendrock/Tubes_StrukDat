#include "RelasiCourseStudent.h"

void createListRelasiCourseStudent(ListRelasiCourseStudent &L){
    first(L) = NULL;
    last(L) = NULL;
}

void insertFirstRelasiCourseStudent(ListRelasiCourseStudent &L, addressRelasiCourseStudent P){
    if (first(L) == NULL){
        first(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}

void insertLastRelasiCourseStudent(ListRelasiCourseStudent &L, addressRelasiCourseStudent P){
    if (fisrt(L) == NULL){
        first(L) == P;
    } else {
        next(last(L)) = P;
        last(L) = P;
    }
}

void insertAfterRelasiCourseStudent(ListRelasiCourseStudent &L, addressRelasiCourseStudent Prec, addressRelasiCourseStudent P){
    if (first(L) == NULL){
        first(L) = P;
    } else {
        next(P) = next(Prec);
        next(Prec) = P;
    }        
}

void deleteFirstRelasiCourseStudent(ListRelasiCourseStudent &L, addressRelasiCourseStudent &P){
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

void deleteLastRelasiCourseStudent(ListRelasiCourseStudent &L, addressRelasiCourseStudent &P){
    if (first(L) == NULL){
        cout << "List Kosong" << endl;
    } else if (next(first(L)) == NULL){
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
    } else {
        addressLastRelasiCourseStudent Q;
        P = first(L);
        while (P != NULL){
            Q = P;
            P = next(P);
        }
        next(Q) = NULL;
        last(L) = Q; 
    }
}

void deleteAfterRelasiCourseStudent(ListRelasiCourseStudent &L, addressRelasiCourseStudent Prec, addressRelasiCourseStudent &P){
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

addressRelasiCourseStudent alokasiRelasiCourseStudent(infotypeRelasiCourseStudent x){
    addressRelasiCourseStudent P = new elmlistRelasiCourseStudent;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void dealokasiRelasiCourseStudent(addressRelasiCourseStudent &P){
    delete (P);
}

addressRelasiCourseStudent findElmRelasiCourseStudent(ListRelasiCourseStudent L, string x){
    addressRelasiCourseStudent P = first(L);

    do{
        if (info(P).kode == x){
            return P;
        }
        P = next(P);
    }(while P != NULL);
}

void printInfoRelasiCourseStudent(ListRelasiCourseStudent L){
    addressRelasiCourseStudent P = first(L);

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
