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
                    cout << " "; // Beri spasi
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
