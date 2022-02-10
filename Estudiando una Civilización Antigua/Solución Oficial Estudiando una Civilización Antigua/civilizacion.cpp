#include "civilizacion.h"
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 250001;
int color[MAXN];
vector<int> adj[MAXN];
void DFS(int nod, int col){
    if(color[nod]!=-1) return;
    color[nod] = col;
    for(auto nex : adj[nod]){
        DFS(nex,1-col);
    }
}
int Civilizacion(int N, vector<vector<int> > palabras, vector<int> & vocales, vector<int> & consonantes){
    memset(color,-1,sizeof(color));
    int M = palabras.size();
    for(int i = 0;i<M;i++){
        for(int j = 0;j<palabras[i].size()-1;j++){
            int u = palabras[i][j];
            int v = palabras[i][j+1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    int res = 0;
    for(int i = 1;i<=N;i++){
        if(color[i]==-1){
            res++;
            DFS(i,0);
        }
        if(color[i]==0){
            vocales.push_back(i);
        }else{
            consonantes.push_back(i);
        }
    }
    return res;
}
