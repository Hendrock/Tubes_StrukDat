#include "Course.h"

addressCourse alokasi(infotypeCourse x){
    addressCourse P = new elmlistCourse;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void dealokasi(addressCourse &P){
    delete (P);
}

addressCourse findElm(ListCourse L, string x){
    addressCourse P = first(L);

    do{
        if (info(P).kode == x){
            return P;
        }
        P = next(P);
    }(while P != NULL);
}

void printInfo(ListCourse L){
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
