#include <bits/stdc++.h>
using namespace std;
#include "S3/divisores.cpp"
#include "S12/divisores.cpp"
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
//#define set(mask,i,v)  ( ((mask & ~( ( (1<<TAM_MASK)-1) << (TAM_MASK*(i)) )) | (v<<(TAM_MASK * (i))) ))
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
const string path1="jurisdiccional-oia-2021/2021/problemas/divisores1/casos/";
const string path2="jurisdiccional-oia-2021/2021/problemas/divisores2/casos/";
const string path3="jurisdiccional-oia-2021/2021/problemas/divisores3/casos/";
const intl maxlim = 100000000000000ll;
const int maxn = 2000000;
intl lim = 1e6;
bitset<maxn> ps;
vector<pair<intl,intl> > nums;
vector<intl> nums2;
const int Mmax = 1e7;
pair<int,int> cantDivs(intl X){
	int r = 0;
	int p = 0;
	for(intl i = 1;i*i<=X;i++){
		if(X%i==0){
			r++;
			if(i<maxn and ps[i]) p++;
			if(i*i!=X){
				r++;
				if(X/i<maxn and ps[X/i]) p++;
			}
		}
	}
	return {r,p};
}
void Generador(intl acum = 1, int p = 1, intl cantD = 1){
	if(p==1) nums.clear();
	if(!ps[p]){
		Generador(acum,p+1,cantD);
		return;
	}
	int ex = 0;
	while(p*acum<=lim){
		acum*=p;
		ex++;
		Generador(acum,p+1, cantD*(ex+1));
	}
	if(ex==0) nums.push_back({cantD,acum});

}
int main()
{
	ps.set();
	ps[0] = ps[1] = false;
	forn(i,maxn){
		if(ps[i])
			for(intl j = 1ll*i*i;j<maxn;j+=i)
				ps[j] = false;
	}
    cin.tie(0);
    cin.sync_with_stdio(0);
	/// Divisores 1 subtarea 1

	if(false){
		lim = 10;
		forsn(i,1,11){
			string name = path1+"S01E"+((i<10)?"0"+to_string(i):"10");
			ofstream in(name+".in");
			ofstream out(name+".dat");
			in<<i<<endl;
			auto p = Divisores(i);
			out<<p[0]<<" "<<p[1]<<endl;
		}
	}
	/// Divisores 1 subtarea 2

	if(false){
		lim = 1000;
		Generador();
		sort(nums.rbegin(),nums.rend());
		forsn(i,1,16){
			string name = path1+"S02E"+((i<10)?"0"+to_string(i):to_string(i));
			ofstream in(name+".in");
			ofstream out(name+".dat");
			int N = nums[i-1].second;
			in<<N<<endl;
			auto p = Divisores(N);
			out<<p[0]<<" "<<p[1]<<endl;
		}
	}
	/// Divisores 1 subtarea 3

	if(false){
		lim = 1e6;
		nums2.clear();
		forsn(i,1,lim){
			if(ps[i]){
				for(int j = 2;j<=i and j*i<=lim;j++)
					if(ps[j])
						nums2.push_back(i*j);
			}
		}
		sort(nums.rbegin(),nums.rend());
		forsn(i,1,min(16,(int)nums.size())){
			string name = path1+"S03E"+((i<10)?"0"+to_string(i):to_string(i));
			ofstream in(name+".in");
			ofstream out(name+".dat");
			intl N = nums2[i-1];
			in<<N<<endl;
			auto p = Divisores(N);
			out<<p[0]<<" "<<p[1]<<endl;
		}
	}

	/// Divisores 1 subtarea 4

	if(false){
		lim = 1e6;
		Generador();
		sort(nums.rbegin(),nums.rend());
		forsn(i,1,16){
			string name = path1+"S04E"+((i<10)?"0"+to_string(i):to_string(i));
			ofstream in(name+".in");
			ofstream out(name+".dat");
			intl N = nums[i-1].second;
			in<<N<<" "<<endl;
			auto p = Divisores(N);
			out<<p[0]<<" "<<p[1]<<endl;
		}
	}

	/// Divisores 2 subtarea 1

	if(false){
		lim = 10;
		forsn(i,1,11){
			string name = path2+"S01E"+((i<10)?"0"+to_string(i):"10");
			ofstream in(name+".in");
			ofstream out(name+".dat");
			in<<i<<endl;
			auto p = Divisores(i);
			out<<p[0]<<" "<<p[1]<<endl;
		}
	}

	/// Divisores 2 subtarea 2

	if(false){
		lim = 1000;
		Generador();
		sort(nums.rbegin(),nums.rend());
		forsn(i,1,16){
			string name = path2+"S02E"+((i<10)?"0"+to_string(i):to_string(i));
			ofstream in(name+".in");
			ofstream out(name+".dat");
			intl N = nums[i-1].second;
			in<<N<<endl;
			auto p = Divisores(N);
			out<<p[0]<<" "<<p[1]<<endl;
		}
	}

	/// Divisores 2 subtarea 3

	if(false){
		lim = 1e6;
		Generador();
		sort(nums.rbegin(),nums.rend());
		forsn(i,1,16){
			string name = path2+"S03E"+((i<10)?"0"+to_string(i):to_string(i));
			ofstream in(name+".in");
			ofstream out(name+".dat");
			intl N = nums[i-1].second;
			in<<N<<" "<<endl;
			auto p = Divisores(N);
			out<<p[0]<<" "<<p[1]<<endl;
		}
	}

	/// Divisores 2 subtarea 4

	if(false){
		lim = maxlim;
		nums2.clear();
		vector<intl> prims = {
			999959, 999961, 999979, 999983, 1000003, 1000033, 1000037, 1000039,
			9999943, 9999971, 9999973, 9999991, 10000019, 10000079, 10000103, 10000121,
			99999941, 99999959, 99999971, 99999989, 100000007, 100000037, 100000039, 100000049
		};
		for(auto a : prims)
			for(auto b : prims)
				if(a*b<=lim)
					nums2.push_back(a*b);
		sort(nums2.rbegin(),nums2.rend());
		forsn(i,1,min(16,(int)nums2.size())){
			string name = path2+"S04E"+((i<10)?"0"+to_string(i):to_string(i));
			ofstream in(name+".in");
			ofstream out(name+".dat");
			intl N = nums2[i-1];
			in<<N<<endl;
			auto p = Divisores(N);
			out<<p[0]<<" "<<p[1]<<endl;
		}
	}

	/// Divisores 2 subtarea 5

	if(false){
		lim = maxlim;
		Generador();
		sort(nums.rbegin(),nums.rend());
		forsn(i,1,16){
			string name = path2+"S05E"+((i<10)?"0"+to_string(i):to_string(i));
			ofstream in(name+".in");
			ofstream out(name+".dat");
			intl N = nums[i-1].second;
			in<<N<<" "<<endl;
			auto p = Divisores(N);
			out<<p[0]<<" "<<p[1]<<endl;
		}
	}

	/// Divisores 3 subtarea 1
	srand(333);

	if(false){
		lim = 10;
		int tc = 0;
		forn(m,2){
				forsn(i,1,11){
				tc++;
				string name = path3+"S01E"+((tc<10)?"0"+to_string(tc):to_string(tc));
				ofstream in(name+".in");
				ofstream out(name+".dat");
				int M = (m)?1:(rand()%1000000+9000000);
				in<<i<<" "<<M<<endl;
				auto p = Divisores(i,M);
				out<<p[0]<<" "<<p[1]<<endl;
			}
		}
	}

	/// Divisores 3 subtareas 2,3,4 y 6

	if(false){
		vector<intl> lims = {10,1000,1000000, 10000000000ll, maxlim};
		vector<int> idS = {1,2,3,4,6};
		forsn(sub,2,6){
			lim = lims[sub-1];
			Generador();
			sort(nums.rbegin(),nums.rend());
			int tc = 0;
			int lars[2] = {15,5};
			forn(m,2){
				forn(i,lars[m]){
					tc++;
					string name = path3+"S0"+to_string(idS[sub-1])+"E"+((tc<10)?"0"+to_string(tc):to_string(tc));
					ofstream in(name+".in");
					ofstream out(name+".dat");
					intl M = (m)?1:(rand()%1000000+9000000);
					intl N = nums[i].second;
					in<<nums[i].second<<" "<<M<<endl;
					auto p = Divisores(N,M);
					out<<p[0]<<" "<<p[1]<<endl;
				}
			}
		}
	}
	/// Divisores 3 Subtarea 5
	if(true){
		lim = maxlim;
		nums2.clear();
		vector<intl> prims = {
			999959, 999961, 999979, 999983, 1000003, 1000033, 1000037, 1000039,
			9999943, 9999971, 9999973, 9999991, 10000019, 10000079, 10000103, 10000121,
			99999941, 99999959, 99999971, 99999989, 100000007, 100000037, 100000039, 100000049
		};
		for(auto a : prims)
			for(auto b : prims)
				if(a*b<=lim)
					nums2.push_back(a*b);
		sort(nums2.rbegin(),nums2.rend());

		vector<intl> nums3;
		forsn(i,2,1000)
			if(ps[i])
				forsn(j,i+1,1000)
					if(ps[j]){
						//assert(cantDivs(i).first==2);
						//assert(cantDivs(j).second==2);
						for(intl vi = i;vi<maxlim;vi*=i)
							for(intl vj = j;vj*vi<=maxlim;vj*=j)
								nums3.push_back(vi*vj);
					}
		sort(nums3.rbegin(),nums3.rend());
		int tc = 1;
		for(auto vec : vector<vector<intl>>({nums2,nums3})){
			forn(i,min(10,(int)vec.size())){
				string name = path3+"S05E"+((tc<10)?"0"+to_string(tc):to_string(tc));
				tc++;
				//ofstream in(name+".in");
				//ofstream out(name+".dat");
				intl M = (i<3)?1:(rand()%1000000+9000000);
				intl N = vec[i];
				//in<<nums[i].second<<" "<<M<<endl;
				auto p = Divisores(N,M);
				//out<<p[0]<<" "<<p[1]<<endl;
                cout<<name<<endl;
                cout<<N<<" "<<M<<endl;
                cout<<p[0]<<" "<<p[1]<<endl;
                DBG(cantDivs(N));
			}
		}

	}
}

