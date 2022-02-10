#include <iostream>
#include <vector>
#include "civilizacion.cpp"
using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N,M;
    cin>>N>>M;
    vector<vector<int> > palabras(M);
    vector<int> vocales, consonantes;
    for(int i = 0;i<M;i++){
        int Ki; cin>>Ki;
        palabras[i].resize(Ki);
        for(int j = 0;j<Ki;j++){
            cin>>palabras[i][j];
        }
    }
    cout<<Civilizacion(N,palabras, vocales, consonantes)<<'\n';
    for(auto i : vocales) cout<<i<<" ";
    cout<<"\n";
    for(auto i : consonantes) cout<<i<<" ";
    cout<<"\n";

}

