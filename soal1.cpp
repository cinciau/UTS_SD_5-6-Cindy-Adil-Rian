#include <iostream>
using namespace std;

// Fungsi untuk melakukan rotasi kiri
void rotasiKiri(int arr[], int n, int d) {
    d = d % n; //ini untuk menghindari rotasinya supaya tidak berlebihan yang hasilnya sama
    for (int i = 0; i < n; i++) {
        cout << arr[(i + d) % n] << " ";
    }
    cout << endl;
}

int main() {
    int n, d;
    cout << "Masukkan n dan banyak rotasi: ";
    cin >> n >> d;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    rotasiKiri(arr, n, d);

    return 0;
}


/* Contoh:
Input:
   n = 5, d = 2
   array = [10, 20, 30, 40, 50]

Proses:
   d = 2 % 5 = 2
   Output:
   30 40 50 10 20

/* 
alur program 

- yang pertama program akan meminta kita untuk memasukkan 2 angaka:
n = berapa banyak angka yang akan di masukkan ke array
d = berapa banyak kita akan rotasinya 

- selanjutnya kita isi semua elemen arraynya satu persatu 

- program akan memamnggil fungsi rotasiKiri()
porses rotasinya 

- pada line 6 ada fungsi  d = d % n;
maksudnya kalau rotasinya lebih banyak dari pada jumlah datanya 

kalau bagian arr[(i + d) % n] menentukan elemen apa yang akan di tampilkan setelah rotasi


*/
