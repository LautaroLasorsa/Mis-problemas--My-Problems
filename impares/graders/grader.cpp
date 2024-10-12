#include <iostream>
#include <string>
#include <vector>

using namespace std;

int impares(vector<vector<int>> &subordinados);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<vector<int>> subordinados;
    subordinados.resize(N);
    for (int i0 = 0; i0 < N; i0++) {
        int auxSize1;
        cin >> auxSize1;
        subordinados[i0].resize(auxSize1);
        for (int i1 = 0; i1 < auxSize1; i1++) {
            cin >> subordinados[i0][i1];
        }
    }
    int returnedValue;
    returnedValue = impares(subordinados);
    cout << returnedValue << "\n";
    return 0;
}
