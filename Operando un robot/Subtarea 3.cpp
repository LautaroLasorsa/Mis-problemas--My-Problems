#include <bits/stdc++.h>
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
const int largo = 1<<19;
intl st[largo];
intl Query(int lq, int rq, int nod = 1, int l = 0, int r = largo/2-1){
	if(lq<=l and r<=rq) return st[nod];
	if(lq>r or rq<l) return 0;
	int m = (l+r)/2;
	return Query(lq,rq,nod*2,l,m) + Query(lq,rq,nod*2+1,m+1,r);
}
void Update(int p, intl v){
	p+=largo/2;
	st[p] = v;
	while(p/=2) st[p] = st[p*2]+st[p*2+1];
}
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	int N;
	cin>>N;
	forn(i,N){
		int t; cin>>t;
		cin>>st[i+largo/2];
	}
	dforn(i,largo/2) st[i] = st[i*2]+st[i*2+1];
	
	int Q;cin>>Q;
	forn(q,Q){
		int tq; cin>>tq;
		if(tq==1){
			int L,R;
			cin>>L>>R;
			intl r = Query(L,R);
			cout<<r<<" 0 0\n";
		}else{
			int p;
			cin>>p;
			intl v;
			int t; cin>>t;
			cin>>v;
			Update(p,v);
		}
	}
}

 
