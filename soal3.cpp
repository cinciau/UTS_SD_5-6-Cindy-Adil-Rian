#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int numberVertex;
    vector<vector<int>> adjMatrix;

public:
    Graph(int V) {
        numberVertex = V;
        adjMatrix.resize(numberVertex, vector<int>(numberVertex, 0));
    }

    void addEdge(int i, int j) {
        if (i >= 0 && i < numberVertex && j >= 0 && j < numberVertex) {
            adjMatrix[i][j] = 1; 
            adjMatrix[j][i] = 1; 
        }
    }

    void cariTerinfeksiHariKe(int S, int K) {
        vector<int> hari_terinfeksi(numberVertex, -1);
        queue<int> titikVisit;
        hari_terinfeksi[S] = 0;
        titikVisit.push(S); 

        while (!titikVisit.empty()) {
            int currentVertex = titikVisit.front();
            titikVisit.pop();
            for (int i = 0; i < numberVertex; i++) {  
                if (adjMatrix[currentVertex][i] == 1 && hari_terinfeksi[i] == -1) {    
                    hari_terinfeksi[i] = hari_terinfeksi[currentVertex] + 1;                   
                    titikVisit.push(i);
                }
            }
        }

        vector<int> hasil;

        for (int node = 0; node < numberVertex; node++) {
            if (hari_terinfeksi[node] == K) {
                hasil.push_back(node);
            }
        }

        if (hasil.empty()) {
            cout << "(TIDAK ADA)" << endl;
        } else {
            for (size_t i = 0; i < hasil.size(); ++i) {
                cout << hasil[i];
                if (i < hasil.size() - 1) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int V, E;

    cout << "Masukkan jumlah orang (V) dan koneksi pertemanan (E): ";
    cin >> V >> E;

    Graph g(V);

    for (int i = 0; i < E; ++i) {
        int u, v;
        cout << "Masukkan koneksi pertemanan (u v) ke " << i << " : ";
        cin >> u >> v;
        g.addEdge(u, v); 
    }

    int S, K;
    
    cout << "Masukkan node awal (S) dan hari ke- (K): ";
    cin >> S >> K;

    g.cariTerinfeksiHariKe(S, K);

    return 0;
}

// Algoritma/Logika Penyelesaian

// Inisialisasi (Hari ke-0):
// 1. Ambil orang pertama yaitu S.
// 2. Catat di "Buku Catatan": hari_terinfeksi[S] = 0.
// 3. Masukkan S ke dalam "Antrean" (query titikVisit).

// Proses Penularan (Loop Utama):
// 1. Lakukan while loop: "Selama Antrean tidak kosong..."
// 2. Ambil 1 orang dari DEPAN Antrean. Sebut dia penular (currentVertex).
// 3. penular yang sekarang akan menyebarkan virus ke semua temannya.

// Mencari Teman (Loop Dalam):
// 1. Cek SEMUA orang di graf (loop i dari 0 sampai V-1).
// 2. Untuk setiap orang i. Sebut dia calon tertular, kita cek 2 syarat:
    // "Apakah penular berteman dengan calon tertular?" (Cek di matriks: adjMatrix[penular][calon tertular] == 1?, 1 artinya berteman)
    // "Apakah calon tertular belum terinfeksi?" (Cek di buku catatan: hari_terinfeksi[tertular] == -1?, -1 artinya belum)

// Jika 2 Syarat Terpenuhi, maka terjadi penularan:
// 1. Jika YA untuk kedua syarat itu, maka calon tertular (si teman) sekarang terinfeksi.
// 2. Catat di Buku:
    // Lihat harinya penular (misal, Hari ke-2).    
    // Tulis hari infeksi calon tertular sebagai hari_terinfeksi[penular] + 1 (2 + 1 = 3).
// 3. Masukkan ke Antrean:
// Masukkan calon tertular (penular baru) ke dalam Antrean. Dan menunggu giliran untuk menjadi penular ke teman-temannya.

// Proses Selesai:
// 1. Loop while akan berhenti ketika Antrean kosong. Artinya tidak ada lagi penular yang bisa menularkan virus.
// 2. "Buku Catatan" (hari_terinfeksi) sudah terisi lengkap.

// Pengumpulan Hasil:
// 1. Buat daftar hasil yang kosong.
// 2. Cek lagi semua orang (loop node dari 0 sampai V-1).
// 3. Cek "Buku Catatan"-nya: "Apakah hari_terinfeksi[node] tepat sama dengan K?"
// 4. Jika ya, masukkan node itu ke daftar hasil.

// Cetak:
// 1. Cetak isi daftar hasil.
// 2. Jika daftar hasil ternyata kosong, cetak (TIDAK ADA).
