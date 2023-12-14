#include "RelasiCourseStudent.h"
#include "Course.h"
#include "Student.h"

void createListRelasiCourseStudent(ListRelasiCourseStudent &L) {
    first(L) = NULL;
    last(L) = NULL;
}

void insertFirstRelasiCourseStudent(ListRelasiCourseStudent &L, addressRelasiCourseStudent P) {
    if (first(L) == NULL) {
        first(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}

void insertLastRelasiCourseStudent(ListRelasiCourseStudent &L, addressRelasiCourseStudent P) {
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(last(L)) = P;
        last(L) = P;
    }
}

void insertAfterRelasiCourseStudent(ListRelasiCourseStudent &L, addressRelasiCourseStudent Prec, addressRelasiCourseStudent P) {
    if (first(L) == NULL) {
        first(L) = P;
    } else {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void deleteFirstRelasiCourseStudent(ListRelasiCourseStudent &L, addressRelasiCourseStudent &P) {
    if (first(L) == NULL) {
        cout << "List Kosong" << endl;
    } else if (next(first(L)) == NULL) {
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
    } else {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}

void deleteLastRelasiCourseStudent(ListRelasiCourseStudent &L, addressRelasiCourseStudent &P) {
    if (first(L) == NULL) {
        cout << "List Kosong" << endl;
    } else if (next(first(L)) == NULL) {
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
    } else {
        addressRelasiCourseStudent Q;
        P = first(L);
        while (next(P) != NULL) {
            Q = P;
            P = next(P);
        }
        next(Q) = NULL;
        last(L) = Q;
    }
}

void deleteAfterRelasiCourseStudent(ListRelasiCourseStudent &L, addressRelasiCourseStudent Prec, addressRelasiCourseStudent &P) {
    if (first(L) == NULL) {
        cout << "List Kosong" << endl;
    } else if (next(first(L)) == NULL) {
        P = first(L);
        first(L) = NULL;
    } else {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

addressRelasiCourseStudent alokasiRelasiCourseStudent(addressCourse course, addressStudent student) {
    addressRelasiCourseStudent PRelasi = new elmlistRelasiCourseStudent;
    parent(PRelasi) = course;
    child(PRelasi) = student;
    next(PRelasi) = NULL;
    return PRelasi;
}

void dealokasiRelasiCourseStudent(addressRelasiCourseStudent &P) {
    delete P;
}
