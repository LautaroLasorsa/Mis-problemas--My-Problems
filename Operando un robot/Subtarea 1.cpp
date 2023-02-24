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
const int maxn = 1e3;
pair<int,int> ins[maxn];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N;
    cin>>N;
    forn(i,N){
		cin>>ins[i].first>>ins[i].second;
	}
	int Q;
	cin>>Q;
	forn(q,Q){
		int tq;
		cin>>tq;
		if(tq == 1){
			intl x = 0, y = 0, d = 0;
			int L,R;
			cin>>L>>R;
			forsn(i,L,R+1){
				if(ins[i].first==1){
					switch(d){
						case 0:
							x+=ins[i].second;
							break;
						case 1:
							y+=ins[i].second;
							break;
						case 2:
							x-=ins[i].second;
							break;
						case 3:
							y-=ins[i].second;
							break;
					}
				}else d = (d+ins[i].second)%4;
			}
			cout<<x<<" "<<y<<" "<<d<<"\n";
		}else{
			int p; cin>>p;
			cin>>ins[p].first>>ins[p].second;
		}
	}
}

 
