#include <vector>
#include <queue>
#include <iostream>
#include "horario.cpp"
using namespace std;


int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N,M;
    long long llegada;
    cin>>N>>M>>llegada;
    vector<int> A(M),B(M);
    vector<long long> T(M), I(M), F(M);
    for(int i = 0;i<M;i++){
        cin>>A[i]>>B[i]>>T[i]>>I[i]>>F[i];
    }
    cout<<Elegir_Horario(N,A,B,T,I,F,llegada)<<"\n";
}
