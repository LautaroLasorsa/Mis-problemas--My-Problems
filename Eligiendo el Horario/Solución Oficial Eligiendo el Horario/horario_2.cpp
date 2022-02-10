#include <vector>
#include <queue>
using namespace std;
struct Salida{
    long long inicio, duracion, frecuencia;
    int destino;
    Salida(long long _inicio, long long _duracion, long long _frecuencia, int _destino){
        inicio = _inicio;
        duracion = _duracion;
        frecuencia = _frecuencia;
        destino = _destino;
    }
};
vector<vector<Salida> > Adj;
long long tiempo[200000]; /// Tiempo máximo de llegada al nodo
bool Dijstrak(long long inicio, long long llegada){ /// Dice si, saliendo a "inicio", es posible llegar al final antes de "llegada"
    int N = Adj.size();
    for(int i = 0;i<N;i++)
        tiempo[i] = llegada+1;
    tiempo[0] = inicio;
    priority_queue<pair<long long,int>, vector<pair<long long,int> >, greater<pair<long long,int> > > PQ;
    PQ.push({inicio,0});
    while(PQ.size()){
        pair<long long,int>  p = PQ.top();
        PQ.pop();
        long long t = p.first;
        int n = p.second;
        for(auto k : Adj[n]){
            long long nt;
            if(t<k.inicio) {
                nt = k.inicio + k.duracion;
            }
            else{
                long long d = t-k.inicio;
                d = (d+k.frecuencia-1)/k.frecuencia;
                d*= k.frecuencia;
                nt = k.inicio + d + k.duracion;
            }
            if(tiempo[k.destino] > nt){
                tiempo[k.destino] = nt;
                PQ.push({nt,k.destino});
            }
        }
    }
    return tiempo[N-1]<=llegada;
}
long long Elegir_Horario(int N, vector<int> A, vector<int> B, vector<long long> T, vector<long long> I, vector<long long> F, long long llegada){
    int M = A.size();
    Adj.resize(N);
    for(int i = 0;i<M;i++){
        Adj[A[i]].push_back(Salida(I[i],T[i],F[i],B[i]));
    }
    long long a = -1, b = llegada+1;
    while(b-a>1){
        long long m = (a+b)/2;
        if(Dijstrak(m,llegada)) a = m;
        else b = m;
    }
    return a;
}
