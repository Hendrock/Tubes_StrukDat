#include "Student.h"

void createListStudent(ListStudent &L) {
    first(L) = NULL;
    last(L) = NULL;
}

addressStudent alokasiStudent(infotypeStudent x) {
    addressStudent P = new elmlistStudent;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void dealokasiStudent(addressStudent &P) {
    delete P;
}

void insertFirstStudent(ListStudent &L, addressStudent P) {
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

void insertLastStudent(ListStudent &L, addressStudent P) {
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

void insertAfterStudent(ListStudent &L, addressStudent Prec, addressStudent P) {
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

void deleteFirstStudent(ListStudent &L, addressStudent &P) {
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

void deleteLastStudent(ListStudent &L, addressStudent &P) {
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

void deleteAfterStudent(ListStudent &L, addressStudent Prec, addressStudent &P) {
    if (first(L) == NULL) {
        cout << "List Kosong" << endl;
    } else {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

addressStudent findElmStudent(ListStudent L, string nim) {
    addressStudent P = first(L);
    do {
        if (info(P).nim == nim) {
            return P;
        }
        P = next(P);
    } while (P != first(L));
    return NULL;
}

void printInfoStudent(ListStudent L) {
    cout << "-----------------------------------" << endl;
    if (first(L) != NULL) {
        addressStudent P = first(L);
        do {
            cout << "Nama: " << info(P).nama << endl;
            cout << "NIM: " << info(P).nim << endl;
            cout << endl;
            P = next(P);
        } while (P != first(L));
    } else {
        cout << "List Kosong" << endl;
    }
    cout << "-----------------------------------" << endl;
}
