#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N; 
    queue<string> normal;
    queue<string> darurat;

    for (int i = 0; i < N; i++) {
        string perintah;
        cin >> perintah;

        if (perintah == "DATANG") {
            string nama;
            cin >> nama;
            normal.push(nama); 
        }
        else if (perintah == "DARURAT") {
            string nama;
            cin >> nama;
            darurat.push(nama); 
        }
        else if (perintah == "LAYANI") {
            if (!darurat.empty()) {
                cout << darurat.front() << endl;
                darurat.pop();
            } 
            else if (!normal.empty()) {
                cout << normal.front() << endl;
                normal.pop();
            }
        }
    }
    return 0;
}
/*
Program ini mensimulasikan sistem antrian dengan dua jenis antrean:
1. Antrian normal
2. Antrian darurat (memiliki prioritas lebih tinggi)

Alur kerja program:
- Input pertama adalah N, jumlah perintah yang akan diproses.
- Setiap perintah bisa berupa:
  • "DATANG <nama>"   → menambahkan nama ke antrian normal.
  • "DARURAT <nama>"  → menambahkan nama ke antrian darurat.
  • "LAYANI"          → melayani pasien:
       - Jika ada pasien darurat, layani pasien darurat terlebih dahulu.
       - Jika tidak ada pasien darurat, layani pasien normal.
- Program menampilkan nama pasien yang sedang dilayani.

Struktur data yang digunakan:
- queue<string> normal   → menyimpan pasien normal.
- queue<string> darurat  → menyimpan pasien darurat.

Tujuan:
Mensimulasikan sistem pelayanan dengan prioritas pasien darurat
menggunakan konsep antrian (queue).

*/
