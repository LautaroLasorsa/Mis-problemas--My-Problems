#include  <vector>
#include  <iostream>
#include  "electricista.cpp"
using namespace std;
int electricista(vector<pair<int,int> > tubos, int X, long long MOD);


int main()
{
    int N,X;
    cin>>N>>X;
    if(N<=0 || N>2000000 || X<0||X>10000000)
    {
        cout<<"Ingreso invalido"<<endl;
        return 0;
    }
    int M = N+1;
    vector<pair<int,int> > tubos;
    for(int i = 0;i<N;i++)
    {
        int a,b;
        cin>>a>>b;
        tubos.push_back({a,b});
    }
    int cantf = electricista(tubos,X);
    cout<<cantf<<endl;
}

