#include <bits/stdc++.h>
#include "impares.cpp"
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<vector<int> > subordinados(N);
    for(int i = 0;i<N;i++){
        int k;
        cin>>k;
        subordinados[i].resize(k);
        for(int j = 0;j<k;j++)
            cin>>subordinados[i][j];
    }
    cout<<impares(subordinados)<<endl;
}