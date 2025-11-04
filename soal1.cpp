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
