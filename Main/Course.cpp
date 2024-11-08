#include "Course.h"

void createListCourse(ListCourse &L) {
    first(L) = NULL;
    last(L) = NULL;
}

addressCourse alokasiCourse(infotypeCourse x) {
    addressCourse P = new elmlistCourse;
    info(P) = x;
    next(P) = NULL;
    createListRelasiUser(relasiUser(P));
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

void deleteSpesificCourse(ListCourse &L, string code){
    addressCourse P = findElmCourse(L, code);

    if (P != NULL){
        if (P == first(L)){
            deleteFirstCourse(L, P);
        } else if (P == last(L)){
            deleteLastCourse(L, P);
        } else {
            addressCourse Q = first(L);
            while (next(Q) != P){
                Q = next(Q);
            }
            deleteAfterCourse(L, Q, P);
        }
    } else {
        printf("Course %s tidak ditemukan.\n", code.c_str());
    }
}

addressCourse findElmCourse(ListCourse L, string code) {
    addressCourse P = first(L);
    while (P != NULL) {
        if (info(P).code == code) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void sortCourses(ListCourse L, ListCourse &sortedL) {
    addressCourse P = first(L);
    while (P != NULL) {
        infotypeCourse tempCourse = info(P);
        insertLastCourse(sortedL, alokasiCourse(tempCourse));
        P = next(P);
    }

    addressCourse Q, R;
    infotypeCourse temp;

    if (first(sortedL) != NULL) {
        for (Q = first(sortedL); next(Q) != NULL; Q = next(Q)) {
            for (R = next(Q); R != NULL; R = next(R)) {
                if (info(Q).nUser < info(R).nUser) {
                    temp = info(Q);
                    info(Q) = info(R);
                    info(R) = temp;
                }
            }
        }
    } else {
        cout << "List courses kosong." << endl;
    }
}

void printAllCourses(ListCourse L) {
    ListCourse sortedList;
    createListCourse(sortedList);

    sortCourses(L, sortedList);

    addressCourse P = first(sortedList);

    if (P != NULL){
            while (P != NULL) {
            printf("%s (%s) - User: %d\n", info(P).name.c_str(), info(P).code.c_str(), info(P).nUser);
            printForum(L, info(P).code);
            printf("Task: %s\n", info(P).task.c_str());
            P = next(P);
        }
    } else {
        cout << "List courses kosong." << endl;
    }
}

void printCourse(ListCourse L, string code){
    addressCourse P = findElmCourse(L, code);

    if (P != NULL){
        printf("%s (%s) - User: %d\n", info(P).name.c_str(), info(P).code.c_str(), info(P).nUser);
        printForum(L, info(P).code);
        printf("Task: %s\n", info(P).task.c_str());
    } else {
        printf("Course %s tidak ditemukan.\n", code.c_str());
    }
}

void printUsersInCourse(ListCourse L, string code) {
    addressCourse P = findElmCourse(L, code);
    addressRelasiUser Q = first(relasiUser(P));

    if (P != NULL && Q != NULL){
        while (Q != NULL) {
            printf("%s (User ID: %s) - %s\n", info(user(Q)).name.c_str(), info(user(Q)).UID.c_str(), info(user(Q)).role.c_str());
            Q = next(Q);
        }
    } else {
        printf("Tidak ada user pada course %s.\n", code.c_str());
    }
}

void printEnrolledCourse(ListCourse L, string UID){
    addressCourse P = first(L);

    while (P != NULL){
        addressRelasiUser Q = first(relasiUser(P));
        while (Q != NULL){
            if (info(user(Q)).UID == UID){
                printf("%s (%s) - User: %d\n", info(P).name.c_str(), info(P).code.c_str(), info(P).nUser);
                printForum(L, info(P).code);
                printf("Task: %s\n", info(P).task.c_str());
            }
            Q = next(Q);
        }
        P = next(P);
    }
}

void printForum(ListCourse L, string code){
    addressCourse P = findElmCourse(L, code);

    if (P != NULL){
        if (info(P).nForum != 0){
            for (int i = 0; i < info(P).nForum; i++){
                printf("[ID. %d] %s\n", i + 1, info(P).forum[i].title.c_str());
                printf("\t%s\n", info(P).forum[i].body.c_str());
            }
        } else {
            cout << "Tidak ada content di forum ini." << endl;
        }
    } else {
        printf("Course %s tidak ditemukan.\n", code.c_str());
    }
}

void addForum(ListCourse &L, string code){
    addressCourse P = findElmCourse(L, code);

    if (info(P).nForum != 0){
        cout << "Judul Forum: ";
        cin.ignore();
        getline(cin, info(P).forum[info(P).nForum].title);
        cout << "Isi Forum:" << endl;
        getline(cin, info(P).forum[info(P).nForum].body);

        info(P).nForum++;

        cout << "Penambahan berhasil!" << endl;
    }
}

void deleteForum(ListCourse &L, string code){
    addressCourse P = findElmCourse(L, code);
    int ID;

    printForum(L, code);

    if (info(P).nForum != 0){
        cout << "ID forum yang ingin dihapus: ";
        cin >> ID;

        if (ID - 1 < 0 || ID - 1 >= info(P).nForum){
            printf("ID forum %d diluar indeks.\n", ID);
        } else {
            for (int i = ID - 1; i < info(P).nForum - 1; i++) {
                info(P).forum[i] = info(P).forum[i + 1];
            }

            info(P).nForum--;

            cout << "Penghapusan berhasil!" << endl;

            printForum(L, code);
        }
    }
}

void printQuiz(ListCourse L, string code){
    addressCourse P = findElmCourse(L, code);

    if (P != NULL){
        if (info(P).nQuiz != 0){
            for (int i = 0; i < info(P).nQuiz; i++){
                printf("[No. %d] Point: %d\n", i + 1, info(P).quiz[i].point);
                printf("\t%s\n", info(P).quiz[i].question.c_str());
                printf("\tAnswer: %s\n", info(P).quiz[i].answer.c_str());
            }
        } else {
            cout << "Tidak ada content di quiz ini." << endl;
        }
     } else {
        printf("Course %s tidak ditemukan.\n", code.c_str());
     }
}

void addQuiz(ListCourse &L, string code){
    addressCourse P = findElmCourse(L, code);

    if (info(P).nQuiz != 0){
        cout << "Pertanyaan:" << endl;
        cin.ignore();
        getline(cin, info(P).quiz[info(P).nQuiz].question);
        cout << "Jawaban:" << endl;
        getline(cin, info(P).quiz[info(P).nQuiz].answer);
        cout << "Poin:" << endl;
        cin >> info(P).quiz[info(P).nQuiz].point;
        cout << "Berhasil!" << endl;

        info(P).nQuiz++;

        cout << "Penambahan berhasil!" << endl;

        printQuiz(L, code);
    }
}

void deleteQuiz(ListCourse &L, string code){
    addressCourse P = findElmCourse(L, code);
    int ID;

    printQuiz(L, code);

    if (info(P).nQuiz != 0){
        cout << "Nomor soal yang ingin dihapus: ";
        cin >> ID;

        if (ID - 1 < 0 || ID - 1 >= info(P).nQuiz){
            printf("Soal nomor %d diluar indeks.\n", ID);
        } else {
            for (int i = ID - 1; i < info(P).nQuiz; i++) {
                info(P).quiz[i] = info(P).quiz[i + 1];
            }

            info(P).nQuiz--;

            cout << "Penghapusan berhasil!" << endl;

            printQuiz(L, code);
        }

    }
}

void editQuiz(ListCourse &L, string code){
    addressCourse P = findElmCourse(L, code);
    int ID, choice;

    printQuiz(L, code);

    if (info(P).nQuiz != 0){
        cout << "Nomor soal yang ingin diubah: ";
        cin >> ID;

        if (ID - 1 < 0 || ID - 1 >= info(P).nQuiz){
            printf("Soal nomor %d diluar indeks.\n", ID);
        } else {
            cout << "Pilih elemen yang ingin diubah:" << endl;
            cout << "[1] Pertanyaan Soal" << endl;
            cout << "[2] Jawaban Soal" << endl;
            cout << "[3] Poin Soal" << endl;
            cout << "Pilihan: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Pertanyaan Soal: ";
                    cin.ignore();
                    getline(cin, info(P).quiz[ID - 1].question);
                    break;
                case 2:
                    cout << "Jawaban Soal: ";
                    cin.ignore();
                    getline(cin, info(P).quiz[ID - 1].answer);
                    break;
                case 3:
                    cout << "Poin Soal: ";
                    cin >> info(P).quiz[ID - 1].point;
                    break;
                default:
                    cout << "Pilihan tidak valid." << endl;
                    return;
            }

            cout << "Perubahan berhasil!" << endl;

            printQuiz(L, code);
        }
    }
}

void doQuiz(ListCourse &L, string code, string UID){
    addressCourse P = findElmCourse(L, code);

    if (P != NULL){
        if (info(P).nQuiz != 0){
            string tempAnswer;
            int tempScore = 0;
            cin.ignore();

            for (int i = 0; i < info(P).nQuiz; i++){
                printf("[No. %d] Point: %d\n", i + 1, info(P).quiz[i].point);
                printf("\t%s\n", info(P).quiz[i].question.c_str());
                cout << "Jawaban: ";
                getline(cin, tempAnswer);

                if (tempAnswer == info(P).quiz[i].answer){
                    tempScore += info(P).quiz[i].point;
                }
            }

            printf("Anda mendapatkan nilai %d.\n", tempScore);

            info(P).result[info(P).nResult].UID = UID;
            info(P).result[info(P).nResult].score = tempScore;

            info(P).nResult++;
        } else {
            cout << "Tidak ada content di quiz ini." << endl;
        }
    } else {
        printf("Course %s tidak ditemukan.\n", code.c_str());
    }
}

void printResult(ListCourse L, string code) {
    addressCourse P = findElmCourse(L, code);

    if (P != NULL) {
        if (info(P).nResult != 0) {
            printf("Results for %s (%s):\n", info(P).name.c_str(), code.c_str());
            printf("--------------------\n");
            printf("UID\tScore\n");
            printf("--------------------\n");

            for (int i = 0; i < info(P).nResult; i++) {
                printf("%d\t%s\t%d\n", i + 1, info(P).result[i].UID.c_str(), info(P).result[i].score);
            }

            printf("--------------------\n");
        } else {
            cout << "Tidak ada hasil nilai di quiz ini." << endl;
        }
    } else {
        printf("Course %s tidak ditemukan.\n", code.c_str());
    }
}

void editTask(ListCourse &L, string code){
    addressCourse P = findElmCourse(L, code);

    cout << "Masukan Task Baru : ";
    cin.ignore();
    getline(cin, info(P).task);

    cout << "Perubahan berhasil!" << endl;

    printCourse(L, code);
}

