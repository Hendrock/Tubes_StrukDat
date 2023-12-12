#include "Lecturer.h"


void createList(List_child &L) {
    first(L) = NULL;
    last(L) = NULL;
}

void insertFirst(ListLecturer &L, addressLecturer P){
    if (first(L) == NULL){
        first(L) = P;
        last(L) = P;
        next(P) = P;
    } else {
        next(P) = first(L);
        next(last(L)) = P;
        first(L) = P;
    }
}

void insertLast(ListLecturer &L, addressLecturer P){
    next(P) = first(L);
    next(last(L)) = P;
    last(L) = P;
}

void insertAfter(addressLecturer Prec, addressLecturer P){

}

void deleteFirst(ListLecturer &L, addressLecturer &P);
void deleteLast(ListLecturer &L, addressLecturer &P);
void deleteAfter(addressLecturer Prec, addressLecturer &P);

addressLecturer alokasi(infotypeLecturer x){
    addressLecturer P = new elmlistLecturer;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void dealokasi(addressLecturer &P){
    delete (P);
}

addressLecturer findElm(ListLecturer L, string x){
    addressLecturer P = first(L);

    do{
        if (info(P).kode == x){
            return P;
        }
        P = next(P);
    }(while P != NULL);
}

void printInfo(ListLecturer L){
    addressLecturer P = first(L);

    cout << "-----------------------------------" << endl;
    if (P == NULL){
        cout << "List Kosong" << endl;
    } else {
        do{
            cout << "Nama Dosen: " <<  info(P).nama << endl;
            cout << "Kode Dosen: " <<  info(P).kode << endl;
            cout << endl;
            P = next(P);
        }(while P != NULL);
    }
    cout << "-----------------------------------" << endl;
}
