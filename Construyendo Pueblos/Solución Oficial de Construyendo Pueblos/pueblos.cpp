#include <bits/stdc++.h>
using namespace std;
struct Nodo{
    int prox[10];
    long long val;
    Nodo()
    {
        memset(prox,-1,sizeof(prox)); /// Llena todas las posiciones de prox con el valor -1
        val = 0;
    }
};

const int largo = 2000000;
int gN, gM;
Nodo Trie[largo];
int tsize = 1;/// Largo actual del Trie / Ubicación del siguiente nodo a agregar
int Siguiente(int nodo, int v)
{
    if(Trie[nodo].prox[v]==-1)
    {
        Trie[nodo].prox[v] = tsize;
        Trie[tsize] = Nodo();
        tsize++;
    }
    return Trie[nodo].prox[v];
}
void Inicializar(int N, int M)
{
    gN = N, gM = M;
    Trie[0] = Nodo();
}
long long Crear(vector<int> A, vector<int> B, long long PA, long long PB)
{
    long long RES = 0;
    int posa = 0, posb = 0;
    Trie[0].val+=PA+PB;
    for(int i = 0; i<gM; i++)
    {
        if(posa != posb)
        {
            for(int j = A[i]+1; j<=9; j++)
            {
                if(Trie[posa].prox[j]!=-1)
                    RES+=Trie[Trie[posa].prox[j]].val;
            }
            for(int j = B[i]-1; j>=0; j--)
            {
                if(Trie[posb].prox[j]!=-1)
                    RES+=Trie[Trie[posb].prox[j]].val;
            }
        }
        else if(A[i] != B[i])
        {
            for(int j = A[i]+1; j<B[i]; j++)
            {
                if(Trie[posa].prox[j]!=-1)
                    RES+=Trie[Trie[posa].prox[j]].val;
            }
        }
        posa = Siguiente(posa,A[i]);
        posb = Siguiente(posb,B[i]);
        Trie[posa].val += PA;
        Trie[posb].val += PB;
    }
    return RES;
}

long long Cambiar(vector<int> C, long long x)
{
    int posc = 0;
    Trie[0].val+=x;
    for(int i = 0; i<gM; i++)
    {
        posc = Siguiente(posc,C[i]);
        Trie[posc].val += x;
    }
    return Trie[posc].val;
}


