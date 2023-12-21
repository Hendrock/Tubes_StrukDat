#include "Course.h"
#include "RelasiUser.h"

void createListCourse(ListCourse &L) {
    first(L) = NULL;
    last(L) = NULL;
}

addressCourse alokasiCourse(infotypeCourse x) {
    addressCourse P = new elmlistCourse;
    info(P) = x;
    next(P) = NULL;
    relasiUser(P) = NULL;
    return P;
}

void dealokasiCourse(addressCourse &P) {
    delete P;
}

void insertFirstCourse(ListCourse &L, addressCourse P) {
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}

void insertLastCourse(ListCourse &L, addressCourse P) {
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(last(L)) = P;
        last(L) = P;
    }
}

void insertAfterCourse(ListCourse &L, addressCourse Prec, addressCourse P) {
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void deleteFirstCourse(ListCourse &L, addressCourse &P) {
    if (first(L) == NULL) {
        cout << "List Kosong" << endl;
    } else {
        P = first(L);
        if (first(L) == last(L)) {
            first(L) = NULL;
            last(L) = NULL;
        } else {
            first(L) = next(P);
        }
        next(P) = NULL;
    }
}

void deleteLastCourse(ListCourse &L, addressCourse &P) {
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
            next(P) = NULL;
            last(L) = P;
            P = next(P);
        }
    }
}

void deleteAfterCourse(ListCourse &L, addressCourse Prec, addressCourse &P) {
    if (first(L) == NULL) {
        cout << "List Kosong" << endl;
    } else {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

addressCourse findElmCourse(ListCourse L, string kode) {
    addressCourse P = first(L);
    while (P != NULL) {
        if (info(P).kode == kode) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void printInfoCourse(ListCourse L) {
    addressCourse P = first(L);
    while (P != NULL) {
        // Print information of Course
        cout << "Nama: " << info(P).nama << endl;
        cout << "Kode: " << info(P).kode << endl;
        cout << "Tugas: " << info(P).tugas << endl;

        // Print information of Quiz
        for (int i = 0; i < info(P).nQuiz; ++i) {
            cout << "Quiz " << i + 1 << " - Pertanyaan: " << info(P).quiz[i].pertanyaan << endl;
            cout << "Quiz " << i + 1 << " - Jawaban: " << info(P).quiz[i].jawaban << endl;
            cout << "Quiz " << i + 1 << " - Point: " << info(P).quiz[i].point << endl;
        }

        // Print information of Forum
        for (int i = 0; i < info(P).nForum; ++i) {
            cout << "Forum " << i + 1 << ": " << info(P).forum[i] << endl;
        }

        P = next(P);
    }
}

void printUser(ListCourse L, string kode) {
    addressCourse P = first(L);
    while (P != NULL) {
        if (info(P).kode == kode) {
            ListRelasiUser* LU = relasiUser(P);
            addressRelasiUser Q = first(LU);
            while (Q != NULL) {
                cout << info(Q) << endl;
                Q = next(Q);
            }
        }
        P = next(P);
    }
}
