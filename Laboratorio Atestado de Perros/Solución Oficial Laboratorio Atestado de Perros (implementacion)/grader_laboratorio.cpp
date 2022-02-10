#include <vector>
#include <iostream>
#include "laboratorio.cpp"

using namespace std;

vector<int> laboratorio(vector<string> labo, vector<pair<int,int> > perros);

int main()
{
    int N,M,P;
    cin>>N>>M>>P;
    if(N<0 || M<0 || P<0 || N*M > 1000000 || P>100000)
    {
        cout<<"Entrada invalida"<<endl;
        return 0;
    }
    vector<string> labo(N);
    for(int i = 0;i<N;i++)cin>>labo[i];
    vector<pair<int,int> > perros(P);
    for(int i = 0;i<P;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a<0||a>=N||b<0||b>=M)
        {
            cout<<"Entrada invalida"<<endl;
            return 0;
        }
        perros[i] = {a,b};
    }
    vector<int> res = laboratorio(labo,perros);
    for(auto k : res) cout<<k<<" ";
}
