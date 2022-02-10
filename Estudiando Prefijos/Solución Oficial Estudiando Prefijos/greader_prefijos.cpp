#include <bits/stdc++.h>
#include "prefijos.cpp"
using namespace std;

int main()
{
	int N,Q;
	cin>>N>>Q;
	Inicializar(N,Q);
	for(int q = 0;q<Q;q++){
        int t;
        cin>>t;
        if(t==0){
            int i;
            string c;
            cin>>i>>c;
            Agregar(i,c[0]);
        }else if(t==1){
            int i, j;
            cin>>i>>j;
            Borrar(i,j);
        }else if(t == 2){
            int i, j;
            cin>>i>>j;
            Cambiar(i,j);
        }else if(t == 3){
            int i, j;
            cin>>i>>j;
            Copiar(i,j);
        }else{
            int i, j;
            cin>>i>>j;
            cout<<Preguntar(i,j)<<endl;
        }
	}
}
