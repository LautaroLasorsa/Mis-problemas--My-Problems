#include <vector>
#include <iostream>
#include "carreras.cpp"
using namespace std;

int main()
{
    int N;
    cin>>N;
    Inicializar(N);
    for(int i = 0;i<N;i++){
        int num, per, op, M, maxp, ca, cj;
        cin>>num>>per>>op>>M;
        vector<int> car(M);
        for(int j = 0;j<M;j++){
            cin>>car[j];
        }
        Actualizar(car,num,per,op,maxp,ca,cj);
        cout<<maxp<<" "<<ca<<" "<<cj<<endl;
    }
	return 0;
}
