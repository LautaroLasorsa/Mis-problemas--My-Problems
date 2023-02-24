
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
template<class T> ostream & operator<<(ostream & out, vector<T>  v)
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
typedef vector<vector<intl> > matriz;
intl calls = 0;
matriz operator * (const matriz & a, const matriz & b){
	//assert(a.size()>0);
	//assert(b.size()>0);
	int n = a.size(), m = b[0].size(), r = a[0].size();
	//assert(a[0].size()==b.size());
	assert(n<=2);
	assert(m<=2);
	assert(r<=2);
	calls+=n*m*r;
	matriz c(n,vector<intl>(m,0));
	forn(i,n)
		forn(j,m)
			forn(k,r)
				c[i][j]+=a[i][k]*b[k][j];
	return c;
}
matriz operator +(const matriz & a, const matriz & b){
	int n = a.size(), m = a[0].size();
	matriz c(n,vector<intl>(m,0));
	calls+=n*m;
	forn(i,n)
		forn(j,m)
			c[i][j] = a[i][j]+b[i][j];
	return c;
}
const matriz rot0 = {{1,0},{0,1}};
const matriz rot90 = {{0,-1},{1,0}};
const matriz rots[4] = {rot0,rot90,rot90*rot90,rot90*rot90*rot90};
struct inst{
	matriz p;
	int d;
};
ostream & operator<<(ostream & u, const inst & i){
	u<<i.p[0][0]<<" "<<i.p[1][0]<<" "<<i.d;
	return u;
}
inst operator * (const inst & a, const inst & b){
	return {a.p+(rots[a.d]*b.p),(a.d+b.d)%4};
}
const inst neutro{{{0},{0}},0};
const int largo = 1<<19;
inst st[largo];
inst Query(int lq, int rq, int nod = 1, int l = 0, int r = largo/2-1){
	//calls++;
	if(lq<= l and r <= rq) return st[nod];
	if(lq>r or rq<l) return neutro;
	int m = (l+r)/2;
	return Query(lq,rq, nod * 2,l,m) * Query(lq,rq,nod * 2 + 1, m+1,r);
}
void Update(int p, inst v){
	p+=largo/2;
	st[p] = v;
	while(p/=2) st[p] = st[p*2]*st[p*2+1];
}
inst getInstruccion(){
	int t, m;
	cin>>t>>m;
	if(t==1) return inst{{ {m},{0} },0};
	else return inst{ { {0},{0} }, m};
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N; cin>>N;
    forn(i,largo) st[i] = neutro;
    forn(i,N) {
		st[i+largo/2] = getInstruccion();
	}
    dforn(i,largo/2) st[i] = st[i*2] * st[i*2+1];
    int Q; cin>>Q;
    forn(q,Q){
		int tq;
		cin>>tq;
		if(tq==1){
			int L,R;
			cin>>L>>R;
			inst I = Query(L,R);
			cout<<I<<"\n";
		}else{
			int p; cin>>p;
			Update(p,getInstruccion());
		}
	}
}

 
