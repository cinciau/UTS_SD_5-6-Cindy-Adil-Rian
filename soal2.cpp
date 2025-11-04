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
