#include <vector>
#include <queue>
using namespace std;
struct Salida{
    long long inicio, duracion, frecuencia;
    int origen;
    Salida(long long _inicio, long long _duracion, long long _frecuencia, int _origen){
        inicio = _inicio;
        duracion = _duracion;
        frecuencia = _frecuencia;
        origen = _origen;
    }
};
vector<vector<Salida> > Adj;
long long tiempo[200000]; /// Tiempo máximo de llegada al nodo
long long Elegir_Horario(int N, vector<int> A, vector<int> B, vector<long long> T, vector<long long> I, vector<long long> F, long long llegada){
    int M = A.size();
    Adj.resize(N);
    for(int i = 0;i<M;i++){
        Adj[B[i]].push_back(Salida(I[i]+T[i],T[i],F[i],A[i]));
    }
    for(int i = 0;i<N-1;i++) tiempo[i] = -1;
    tiempo[N-1] = llegada;
    priority_queue<pair<long long,int> > PQ;
    PQ.push({llegada,N-1});
    while(PQ.size()){
        pair<long long,int> p = PQ.top();
        PQ.pop();
        long long t = p.first;
        int n = p.second;
        for(auto k : Adj[n]){
            if(t<k.inicio) continue; /// No puedo "tomar al reves" este colectivo
            long long d = t-k.inicio;
            d/=k.frecuencia;
            d*=k.frecuencia;
            /// Esto vuelve a d en el múltiplo de k.frecuencia inmediatamente menor
            long long nt = k.inicio + d - k.duracion;
            if(tiempo[k.origen] < nt){
                tiempo[k.origen] = nt;
                PQ.push({nt,k.origen});
            }
        }
    }
    return tiempo[0];
}
