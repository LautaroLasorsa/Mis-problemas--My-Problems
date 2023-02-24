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
const int maxn = 2e5+1;
struct query{int L,R,id;};
query qs[maxn];
pair<int,intl> ops[maxn];
intl res[maxn][3];
const int bloque = 400;
bool comp(query a, query b){
	int ba = a.L/bloque, bb = b.L/bloque;
	if(ba!=bb) return ba<bb;
	return a.R<b.R;
}
void rotar(intl & x, intl & y, int & d, int r){
	intl tx = x, ty = y;
	d = (d+r)%4;
	switch(r){
		case 0:
			break;
		case 1:
			x = -ty;
			y = tx;
			break;
		case 2:
			x = -tx;
			y = -ty;
			break;
		case 3:
			x = ty;
			y = -tx;
	}
}
void quitarInicio(int i, intl & x, intl & y, int & d){
	if(ops[i].first==1){
		x -= ops[i].second;
	}else{
		rotar(x,y,d,4-ops[i].second);
	}
}
void quitarFin(int i, intl & x, intl & y, int & d){
	if(ops[i].first==1){
		intl xx = ops[i].second, yy = 0;
		int dd = 0;
		rotar(xx,yy,dd,d);
		x-=xx;
		y-=yy;
	}else{
		d = (d-ops[i].second+4)%4;
	}
}
void ponerInicio(int i, intl & x, intl & y, int & d){
	if(ops[i].first==1){
		x += ops[i].second;
	}else{
		rotar(x,y,d,ops[i].second);
	}
}

void ponerFin(int i, intl & x, intl & y, int & d){
	if(ops[i].first==1){
		intl xx = ops[i].second, yy = 0;
		int dd = 0;
		rotar(xx,yy,dd,d);
		x+=xx;
		y+=yy;
	}else{
		d = (d+ops[i].second+4)%4;
	}
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N;
    cin>>N;
    forn(i,N){
		cin>>ops[i].first>>ops[i].second;
	}
	int Q;
	cin>>Q;
	forn(q,Q){
		int tq, L, R;
		cin>>tq>>L>>R;
		qs[q] = {L,R,q};
	}
	sort(qs,qs+Q,comp);
	intl x = 0, y = 0;
	int d = 0;
	int i = 0, j = -1;
	/// Consultas en [i,j]
	forn(q,Q){
		while(i>qs[q].L){
			i--;
			ponerInicio(i,x,y,d);
		}
		while(i<qs[q].L){
			quitarInicio(i,x,y,d);
			i++;
		}
		
		while(j<qs[q].R){
			j++;
			ponerFin(j,x,y,d);
		}
		
		while(j>qs[q].R){
			quitarFin(j,x,y,d);
			j--;
		}
		res[qs[q].id][0] = x;
		res[qs[q].id][1] = y;
		res[qs[q].id][2] = d;
	}
	forn(q,Q){
		cout<<res[q][0]<<" "<<res[q][1]<<" "<<res[q][2]<<"\n";
	}
	
}

 


