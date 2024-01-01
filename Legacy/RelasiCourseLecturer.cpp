#include "RelasiCourseLecturer.h"

void createListRelasiCourseLecturer(ListRelasiCourseLecturer &L) {
    first(L) = NULL;
    last(L) = NULL;
}

addressRelasiCourseLecturer alokasiRelasiCourseLecturer(addressCourse course, addressLecturer Lecturer) {
    addressRelasiCourseLecturer P = new elmlistRelasiCourseLecturer;
    parent(P) = course;
    child(P) = Lecturer;
    next(P) = NULL;
    return P;
}

void dealokasiRelasiCourseLecturer(addressRelasiCourseLecturer &P) {
    delete P;
}

void insertFirstRelasiCourseLecturer(ListRelasiCourseLecturer &L, addressRelasiCourseLecturer P) {
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}

void insertLastRelasiCourseLecturer(ListRelasiCourseLecturer &L, addressRelasiCourseLecturer P) {
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(last(L)) = P;
        last(L) = P;
    }
}

void insertAfterRelasiCourseLecturer(ListRelasiCourseLecturer &L, addressRelasiCourseLecturer Prec, addressRelasiCourseLecturer P) {
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void deleteFirstRelasiCourseLecturer(ListRelasiCourseLecturer &L, addressRelasiCourseLecturer &P) {
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

void deleteLastRelasiCourseLecturer(ListRelasiCourseLecturer &L, addressRelasiCourseLecturer &P) {
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

void deleteAfterRelasiCourseLecturer(ListRelasiCourseLecturer &L, addressRelasiCourseLecturer Prec, addressRelasiCourseLecturer &P) {
    if (first(L) == NULL) {
        cout << "List Kosong" << endl;
    } else {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}
