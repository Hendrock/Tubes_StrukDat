#include "Course.h"

void createListCourse(ListCourse &L){
    first(L) = NULL;    
}

void insertFirstCourse(ListCourse &L, addressCourse P){
    if (first(L) == NULL){
        first(L) = P;
    } else {
        next(P) = first(L)
        first(L) = P;
    }
}

void insertLastCourse(ListCourse &L, addressCourse P){
    if (fisrt(L) == NULL){
        first(L) == P;
    } else {
        addressCourse Q = first(L);
        while (Q != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void insertAfterCourse(ListCourse &L, addressCourse Prec, addressCourse P){
    if (first(L) == NULL){
        first(L) = P;
    } else {
        next(P) = next(Prec);
        next(Prec) = P;
    }        
}
void deleteFirstCourse(ListCourse &L, addressCourse &P);
void deleteLastCourse(ListCourse &L, addressCourse &P);
void deleteAfterCourse(addressCourse Prec, addressCourse &P);

addressCourse alokasiCourse(infotypeCourse x){
    addressCourse P = new elmlistCourse;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void dealokasiCourse(addressCourse &P){
    delete (P);
}

addressCourse findElmCourse(ListCourse L, string x){
    addressCourse P = first(L);

    do{
        if (info(P).kode == x){
            return P;
        }
        P = next(P);
    }(while P != NULL);
}

void printInfoCourse(ListCourse L){
    addressCourse P = first(L);

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
