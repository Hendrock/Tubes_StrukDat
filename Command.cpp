#include "Student.h"
#include "Lecturer.h"
#include "Course.h"

void sortStudentScore(ListCourse LC, bool permission){
    if (!permission){
        cout << "Anda tidak dapat menggunakan fitur ini" << endl; 
    } else {
        string tempKode;

        cout << "Masukkan kode kelas yang ingin di sort: ";
        cin >> tempKode;

        addressCourse P = findElmCourse(LC, tempKode);

        if (P == NULL){
            cout << "Kelas tidak ditemukan." << endl;
        } else {
            string choice;

            cout << "Ascending/Descending? (A/D)";
            cin >> choice;
            
            for (int i = 0; i < NMAX-1; i++){
		        int index = i;
                for (int j = i+1; j < NMAX; j++){
                    if (choice == "A"){
                        if (info(P).menjawab[j].score < info(P).menjawab[idx].score
                    }
                }
		switch opt {
		case 0: // Ascending
			for j := i + 1; j < NMAX; j++ {
				if (*T)[j].Kategori == category && (*T)[j].Stok < (*T)[idx].Stok {
					idx = j
				}
			}
		case 1: // Descending
			for j := i + 1; j < NMAX; j++ {
				if (*T)[j].Kategori == category && (*T)[j].Stok > (*T)[idx].Stok {
					idx = j
				}
			}
		}

		(*T)[i], (*T)[idx] = (*T)[idx], (*T)[i]
	}
            }
        }
    }
}

void jawabQuiz(ListCourse LC, ListStudent &LS, bool permission){
    if (!permission){
        cout << "Anda tidak dapat menggunakan fitur ini" << endl; 
    } else {
        string tempKode;
        
        cout << "Masukkan kode Mahasiswa:";
        cin >> tempKode;

        addressStudent P = findElmStudent(LS, tempKode);

        if (P == NULL){
            cout << "Mahasiswa tidak ditemukan." << endl;
        } else {
            showAllStudentCourse(P);

            cout << ""
            
            int nSoal = 0;
            while (nSoal != NMAX){
                
            }
        }
    }
}

void addQuiz(ListCourse &L, bool permission){
    if (!permission){
        cout << "Anda tidak dapat menggunakan fitur ini" << endl; 
    } else {
        string tempKode;
        
        cout << "Kelas yang ingin ditambahkan Quiz";
        cin >> tempKode;

        addressCourse P = findElmCourse(L, tempKode);

        if (P == NULL){
            cout << "Kelas tidak ditemukan" << endl;
        } else {
            string tempSoal, tempJawaban;
            int tempPoint, index = info(P).nQuiz;

            cout << "Masukkan Pertanyaan" << endl;
            cin >> tempSoal;
            info(P).quiz[index].pertanyaan = tempSoal;

            cout << "Masukkan Jawaban" << endl;
            cin >> tempJawaban;
            info(P).quiz[index].jawaban = tempJawaban;

            cout << "Masukkan Poin" << endl;
            cin >> tempPoint;
            info(P).quiz[index].point = tempPoint;
        }
    }
}

void showQuiz(List)
