#include <vector>
#include <iostream>
#include "pueblos.cpp"
using namespace std;
//void Inicializar();
//long long Crear(vector<int> A, vector<int> B, long long PA, long long PB);
//long long Cambiar(vector<int> C, long long x);
int main()
{
    int N,M;
    cin>>N>>M;
    Inicializar(N,M);
    for(int i = 0;i<N;i++){
        int t;
        cin>>t;
        if(t == 1){
            vector<int> A(M), B(M);
            long long PA,PB;
            for(int j = 0;j<M;j++) cin>>A[j];
            for(int j = 0;j<M;j++) cin>>B[j];
            cin>>PA>>PB;
            cout<<Crear(A,B,PA,PB)<<endl;
        }
        else{
            vector<int> C(M);
            long long x;
            for(int j = 0;j<M;j++) cin>>C[j];
            cin>>x;
            cout<<Cambiar(C,x)<<endl;
        }
    }
	return 0;
}
