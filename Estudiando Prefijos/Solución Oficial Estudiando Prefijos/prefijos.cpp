#include <bits/stdc++.h>
using namespace std;
/**

Estructuras necesarias

TRIE
LCA
Segment Tree

Complejidad:
* Inicialización en O(N)
* Cada consulta / actualización en O(log(N)*log(Q))
* Total O(N + Q*log(N)*log(Q))

**/
const int lim = 18; /// Logaritmo en base 2 de la cantidad máxima de nodos del TRIE (redondeado arriba)
const int largo = 1 << 19; /// Cantidad de nodos del Segment Tree

struct nodo{
    int hijo[26]; /// hijos en el trie
    int padres[lim];
    int profundidad;
};

nodo TRIE[1<<lim];
int segtree[largo], L[largo], R[largo];
int pos[1<<lim]; /// El nodo vinculado a cada palabra, inicialmente todos 0(la raiz)
int tamTrie = 1; /// la cantidad actual de nodos en el trie


int LCA(int i, int j){
    /// Algoritmo clásico para obtener el LCA entre 2 nodos de un arbol en O(log(N))
    /// Se lo explica con más detalle en la parte teorica
    if(i==-1) return j;
    if(j==-1) return i;
    /// Se agrega de forma artificial al -1 como elemento neutro para poder implementar el Segment Tree
    if(i == j) return i;
    if(TRIE[i].profundidad < TRIE[j].profundidad) swap(i,j);
    for(int k = lim-1;k>=0;k--)
        if(TRIE[i].profundidad - (1<<k) >= TRIE[j].profundidad)
            i = TRIE[i].padres[k];
    if(i==j) return i;
    for(int k = lim-1;k>=0;k--)
        if(TRIE[i].padres[k]!=TRIE[j].padres[k])
            i = TRIE[i].padres[k], j = TRIE[j].padres[k];
    return TRIE[i].padres[0];
}
void Update(int i, int x){ /// El update de una posición del Segment Tree
    i += largo/2;
    segtree[i] = x;
    while(i/=2) segtree[i] = LCA(segtree[i*2],segtree[i*2+1]);
}

int Query(int nod, int lq, int rq){
    /// Nodo en el Segment Tree y extremos izquierdo y derecho de la consulta respectivamente
    if(lq<=L[nod] && R[nod] <= rq) return segtree[nod];
    if(lq>R[nod] || rq<L[nod]) return -1;
    return LCA(Query(nod*2,lq,rq),Query(nod*2+1,lq,rq));
}

void Inicializar(int N, int Q){
    /// Notar que en esta solución no aprovechamos los parametros N y Q en la función inicializar
    memset(segtree,0,sizeof(segtree));
    memset(pos,0,sizeof(pos));

    /// Inicializo los vectores L y R que guardan los extremos izquierdo y derecho de los nodos del Segment Tree
    for(int i = largo/2;i<largo;i++) L[i] = R[i] = i-largo/2;
    for(int i = largo/2-1;i>0;i--) L[i] = L[i*2], R[i] = R[i*2+1];

    /// Inicializo la raiz y por ahora unico nodo del TRIE
    TRIE[0].profundidad = 0;
    memset(TRIE[0].hijo,-1,sizeof(TRIE[0].hijo));
    memset(TRIE[0].padres,0,sizeof(TRIE[0].padres));


}

void Agregar(int i, char c){
    int p = pos[i];
    c-='a'; /// La pasa del rango ['a','z'] al rango [0,25]
    if(TRIE[p].hijo[c]==-1) /// si ese hijo no existe hay que crearlo
    {
        memset(TRIE[tamTrie].hijo,-1,sizeof(TRIE[tamTrie].hijo));
        TRIE[tamTrie].padres[0] = p;
        for(int k = 1;k<lim;k++)
            TRIE[tamTrie].padres[k] = TRIE[TRIE[tamTrie].padres[k-1]].padres[k-1];
        TRIE[tamTrie].profundidad = TRIE[p].profundidad+1;
        TRIE[p].hijo[c] = tamTrie;
        tamTrie++;
    }
    pos[i] = TRIE[p].hijo[c];
    Update(i,pos[i]);
}

void Borrar(int i, int j){
    int p = pos[i];
    for(int k = lim-1;k>=0;k--)
        if((1<<k)<=j)
            p = TRIE[p].padres[k], j-=(1<<k);
    /// Borrar caracteres es solamente ir para arriba en el TRIE
    pos[i] = p;
    Update(i,pos[i]);
}

void Cambiar(int i, int j){
    swap(pos[i],pos[j]);
    Update(i,pos[i]);
    Update(j,pos[j]);
}

void Copiar(int i, int j){
    pos[j] = pos[i];
    Update(j,pos[j]);
}

int Preguntar(int i, int j){
    return TRIE[Query(1,i,j)].profundidad;
}
