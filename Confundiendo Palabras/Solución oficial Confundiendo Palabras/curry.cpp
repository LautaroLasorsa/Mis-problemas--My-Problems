#include <bits/stdc++.h> 
using namespace std;
const int maxLargo = 3e5 + 50;

struct nodo{
	int nex[27];
	int & operator[](char c){
		return nex[c-'a'];
	}
};
nodo trie[2*maxLargo];
int lartrie = 1;
int go(int nod, char c){
	if(trie[nod][c]==0){
		trie[nod][c] = lartrie;
		lartrie++;
	}
	return trie[nod][c];
}
vector<string> pals[maxLargo];
vector<int> sigs[maxLargo];

long long caso(vector<string> & pal, vector<int> & sig){
	int n = (int)pal.size();
	if(n==0) return 0;
	int lar = (int)pal[0].size();
	vector<vector<int> > ids1(n,vector<int>(lar+2,0)), ids2(n,vector<int>(lar+2,0));
	for(int i = 0;i<n;i++){
		int raiz = 0;
		for(int j = 0;j<lar;j++){
			ids1[i][j+1] = raiz = go(raiz,pal[i][j]);
		}
		raiz = 0;
		for(int j = lar-1;j>=0;j--){
			ids2[i][j+1] = raiz = go(raiz,pal[i][j]);
		}
	}
	long long res = 0;
	for(int j = 0;j<lar;j++){
		map<pair<int,int>,vector<int> > dp;
		for(int i = 0;i<n;i++){
			pair<int,int> p = {ids1[i][j],ids2[i][j+2]};
			dp[p].push_back(sig[i]);
		}
		for(auto & pos : dp){
			auto & vec = pos.second;
			sort(vec.begin(),vec.end());
			long long acum = 0;
			for(long long i = 0;i<(long long) vec.size();i++){
				res  += vec[i]*i-acum;
				acum += vec[i];
			}
		}
	}
	return res;
}

long long curry(vector<string> palabras, vector<int> significados){
	long long res = 0;
	int N = (int)palabras.size();
	for(int i = 0;i<N;i++){
		int lar = (int)palabras[i].size();
		pals[lar].push_back(palabras[i]);
		sigs[lar].push_back(significados[i]);
	}
	for(int lar = 0;lar<maxLargo;lar++){
		res += caso(pals[lar],sigs[lar]);
	}
	return res;
} 
