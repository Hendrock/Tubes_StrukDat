#include "Student.h"
#include "Lecturer.h"
#include "Course.h"
#include "RelasiLecturer.h"
#include "RelasiStudent.h"

int main(){
    ListCourse myCourse;
    ListLecturer myLecturer;
    ListStudent myStudent;
    ListRelasiLecturer myRelasiLecturer;
    ListRelasiStudent myRelasiStudent;

    createListCourse(myCourse);
    createListLecturer(myLecturer);
    createListStudent(myStudent);
    createListRelasiLecturer(myRelasiLecturer);
    createListRelasiStudent(myRelasiStudent);

    insertLastCourse(myCourse, alokasiCourse("Test course"));
    insertLastLecturer(myLecturer, alokasiLecturer("Test Lecturer"));
    insertLastStudent(myStudent, alokasiStudent("Test Student"));
    insertLastRelasiLecturer(myRelasiLecturer, alokasiRelasiLecturer(findElmLecturer(myLecturer, "Test Lecturer")));
    insertLastRelasiStudent(myRelasiStudent, alokasiRelasiStudent(findElmStudent(myStudent, "Test Student")));

    printInfoCourse(myCourse);
    printInfoLecturer(myLecturer);
    printInfoStudent(myStudent);

    cout << "Hello world!" << endl;
    return 0;
}
