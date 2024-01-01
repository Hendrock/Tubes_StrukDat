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

void printInfoCourse(ListCourse L) {
    addressCourse P = first(L);
    if (P != NULL){
        while (P != NULL) {
            // Print information of Course
            cout << "Nama: " << info(P).name << endl;
            cout << "Kode: " << info(P).code << endl;
            cout << "Tugas: " << info(P).task << endl;

    //        // Print information of Quiz
    //        for (int i = 0; i < info(P).nQuiz; ++i) {
    //            cout << "Quiz " << i + 1 << " - Pertanyaan: " << info(P).quiz[i].pertanyaan << endl;
    //            cout << "Quiz " << i + 1 << " - Jawaban: " << info(P).quiz[i].jawaban << endl;
    //            cout << "Quiz " << i + 1 << " - Point: " << info(P).quiz[i].point << endl;
    //        }
    //
    //        // Print information of Forum
    //        for (int i = 0; i < info(P).nForum; ++i) {
    //            cout << "Forum " << i + 1 << ": " << info(P).forum[i] << endl;
    //        }

            P = next(P);
        }
    } else {
        cout << "kosong" << endl;
    }
}

void printUser(ListCourse L, string code) {
    addressCourse P = findElmCourse(L, code);
    addressRelasiUser Q = first(relasiUser(P));
    while (Q != NULL) {
        cout << info(user(Q)).nama << endl;
        Q = next(Q);
    }
}

void printForum(ListCourse L, string code){
    addressCourse P = findElmCourse(L, code);

    cout << "==================================================";
    if (info(P).nForum != 0){
        for (int i = 0; i < info(P).nForum; i++){
            printf("\n[ID. %d] %s", info(P).nForum, info(P).forum[i].title.c_str());
            printf("\n\t%s", info(P).forum[i].body.c_str());
        }
    } else {
        cout << "Tidak ada content di forum ini.";
    }
    cout << endl << "==================================================" << endl;
}

void addForum(ListCourse L, string code){
    addressCourse P = findElmCourse(L, code);

    printForum(L, code);

    if (info(P).nForum != 0){
        cout << "Judul Forum: ";
        cin >> info(P).forum[info(P).nForum].title;
        cout << "Isi Forum:" << endl;
        getline(cin, info(P).forum[info(P).nForum].body);
        cout << "Berhasil!" << endl;

        info(P).nForum++;

        cout << "Penambahan berhasil!" << endl;

        printForum(L, code);
    }
}

void deleteForum(ListCourse &L, string code){
    addressCourse P = findElmCourse(L, code);
    int ID;

    printForum(L, code);

    if (info(P).nForum != 0){
        cout << "ID forum yang ingin dihapus: ";
        cin >> ID;

        if (ID < 0 || ID >= info(P).nForum){
            printf("ID forum %d diluar indeks.\n", ID);
        } else {
            for (int i = ID; i < info(P).nForum - 1; i++) {
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

    cout << "==================================================";
    if (info(P).nQuiz != 0){
        for (int i = 0; i < info(P).nQuiz; i++){
            printf("\n[No. %d] %d", info(P).nQuiz, info(P).quiz[i].point);
            printf("\n\t%s", info(P).quiz[i].question.c_str());
        }
    } else {
        cout << "Tidak ada content di quiz ini.";
    }
    cout << endl << "==================================================" << endl;
}

void addQuiz(ListCourse &L, string code){
    addressCourse P = findElmCourse(L, code);

    printQuiz(L, code);

    if (info(P).nQuiz != 0){
        cout << "Pertanyaan:" << endl;
        getline(cin, info(P).quiz[info(P).nQuiz].question);
        cout << "Jawaban:" << endl;
        getline(cin, info(P).quiz[info(P).nQuiz].answer);
        cout << "Poin:" << endl;
        cin >> info(P).quiz[info(P).nQuiz].point;
        cout << "Berhasil!" << endl;

        info(P).nQuiz++;

        cout << "Penambahan berhasil!" << endl;

        printForum(L, code);
    }
}

void deleteQuiz(ListCourse &L, string code){
    addressCourse P = findElmCourse(L, code);
    int ID;

    printQuiz(L, code);

    if (info(P).nQuiz != 0){
        cout << "Nomor soal yang ingin dihapus: ";
        cin >> ID;

        if (ID - 1 < 0 || ID - 1 >= info(P).nForum){
            printf("Soal nomor %d diluar indeks.\n", ID);
        } else {
            for (int i = ID - 1; i < info(P).nQuiz - 1; i++) {
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

        if (ID - 1 < 0 || ID - 1 >= info(P).nForum){
            printf("Soal nomor %d diluar indeks.\n", ID);
        } else {
            cout << "Pilih elemen yang ingin diubah:" << endl;
            cout << "\t[1] Pertanyaan Soal" << endl;
            cout << "\t[2] Jawaban Soal" << endl;
            cout << "\t[3] Poin Soal" << endl;
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Pertanyaan Soal: ";
                    cin.ignore();
                    getline(cin, info(P).quiz[ID - 1].question);
                case 2:
                    cout << "Jawaban Soal: ";
                    cin.ignore();
                    getline(cin, info(P).quiz[ID - 1].answer);
                case 3:
                    cout << "Poin Soal: ";
                    cin >> info(P).quiz[ID - 1].point;
                default:
                    cout << "Pilihan tidak valid." << endl;
                    return;
            }

            cout << "Perubahan berhasil!" << endl;

            printQuiz(L, code);
        }
    }
}

void doQuiz(ListCourse &L, string code, string UID){}
