#include "Course.h"

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
