#include <bits/stdc++.h>
#include "circuitos.cpp"
using namespace std;

int main()
{
    int N; cin>>N;
    string tipo;
    vector<vector<int> > input(N);
    cin>>tipo;
    for(int i = 0;i<N;i++){
        int tam; cin>>tam;
        input[i].resize(tam);
        for(int j = 0; j<tam;j++){
            cin>>input[i][j];
        }
    }
    vector<vector<int> > result = Circuitos(tipo,input);
    for(int i = 0;i<N;i++){
        for(int j = 0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}
