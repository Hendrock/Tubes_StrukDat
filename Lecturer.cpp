#include "Lecturer.h"

void createListLecturer(ListLecturer &L) {
    first(L) = NULL;
    last(L) = NULL;
}

addressLecturer alokasiLecturer(infotypeLecturer x) {
    addressLecturer P = new elmlistLecturer;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void dealokasiLecturer(addressLecturer &P) {
    delete P;
}

void insertFirstLecturer(ListLecturer &L, addressLecturer P) {
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

void insertLastLecturer(ListLecturer &L, addressLecturer P) {
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

void insertAfterLecturer(ListLecturer &L, addressLecturer Prec, addressLecturer P) {
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

void deleteFirstLecturer(ListLecturer &L, addressLecturer &P) {
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

void deleteLastLecturer(ListLecturer &L, addressLecturer &P) {
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

void deleteAfterLecturer(ListLecturer &L, addressLecturer Prec, addressLecturer &P) {
    if (first(L) == NULL) {
        cout << "List Kosong" << endl;
    } else {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

addressLecturer findElmLecturer(ListLecturer L, string kode) {
    addressLecturer P = first(L);
    do {
        if (info(P).kode == kode) {
            return P;
        }
        P = next(P);
    } while (P != first(L));
    return NULL;
}

void printInfoLecturer(ListLecturer L) {
    cout << "-----------------------------------" << endl;
    if (first(L) != NULL) {
        addressLecturer P = first(L);
        do {
            cout << "Nama: " << info(P).nama << endl;
            cout << "Kode: " << info(P).kode << endl;
            cout << endl;
            P = next(P);
        } while (P != first(L));
    } else {
        cout << "List Kosong" << endl;  
    }
    cout << "-----------------------------------" << endl;
}
