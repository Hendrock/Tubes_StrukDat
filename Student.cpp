#include "Student.h"

addressStudent alokasi(infotypeStudent x){
    addressStudent P = new elmlistStudent;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void dealokasi(addressStudent &P){
    delete (P);
}

addressStudent findElm(ListStudent L, string x){
    addressStudent P = first(L);

    do{
        if (info(P).kode == x){
            return P;
        }
        P = next(P);
    }(while P != NULL);
}

void printInfo(ListStudent L){
    addressStudent P = first(L);

    cout << "-----------------------------------" << endl;
    if (P == NULL){
        cout << "List Kosong" << endl;
    } else {
        do{
            cout << "Nama Mahasiswa: " <<  info(P).nama << endl;
            cout << "NIM Mahasiswa: " <<  info(P).nim << endl;
            cout << endl;
            P = next(P);
        }(while P != NULL);
    }
    cout << "-----------------------------------" << endl;
}
