#include <bits/stdc++.h>
#include "../Solución Oficial Eligiendo Carreras/carreras.cpp"
using namespace std;

#define pb push_back
#define mp make_pair

#define forn(i,n) for(int i = 0;i<int(n);i++)
#define dforn(i,n) for(int i = int(n)-1;i>=0;i--)
#define forsn(i,s,n) for(int i = int(s);i<int(n);i++)
#define fore(i,s,n) for(int i = int(s);i<int(n);i++)
#define dforsn(i,s,n) for(int i = int(n)-1;i>=int(s);i--)

#define DBG(x) do{cout<<#x<<" = "<<x<<endl;}while(false)
#define TAM_MASK 1
#define get(mask,i) ((mask>>(TAM_MASK*(i)) & ( (1<<TAM_MASK)-1)))
#define set(mask,i,v)  ( ((mask & ~( ( (1<<TAM_MASK)-1) << (TAM_MASK*(i)) )) | (v<<(TAM_MASK * (i))) ))
#define popcount(mask) (__builtin_popcount(mask))
#define endl '\n'
#define ALL(x) x.begin(),x.end()
template<class T> ostream & operator<<(ostream & out, vector<T> & v)
{
    out<<"[";
    for(auto k : v) out<<k<<",";
    out<<"]"<<"\n";
    return out;
}
template<class T> ostream & operator<<(ostream & out, set<T>  s)
{
    out<<"{";
    for(auto k : s) out<<k<<",";
    out<<"}"<<"\n";
    return out;
}

template<class T, class U> ostream & operator<<(ostream & out, pair<T,U>  p)
{
    out<<"[ "<<p.first<<" , "<<p.second<<" ] ";
    return out;
}
template<class T, class U> istream & operator>>(istream & in, pair<T,U> & p)
{
    in>>p.first>>p.second;
    return in;
}


typedef long long intl;
struct oper{
	int num, per, op;
	vector<int> M;
};
int main()
{
	int cant[4] = {33,30,33,30};
	for(int S = 0;S<4;S++){
		for(int tc = 0;tc<cant[S];tc++){
			string name = "S"+to_string(S+1)+"/"+((tc<10)?"0":"")+to_string(tc);
			string inst = "./corrector "+name+".in "+name+".out "+name+".out";
			
			system(("echo "+inst).c_str());
			system(inst.c_str());
		}
	}
}

