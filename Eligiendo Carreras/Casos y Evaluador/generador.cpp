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
	bool subtarea1 = true, subtarea2 = true, subtarea3 = true, subtarea4 = true;
	/// Subtarea 1 : T<=500
	cout<<"Subtarea 1"<<endl<<endl;
	
	if(subtarea1){
		srand(100000);
		int maxls[5] = {3,5,10,15,125}; 
		for(int tc = 0;tc<30;tc++){
			glob.clear();
			string name = string("S1/")+((tc<10)?"0":"")+to_string(tc);
			ofstream in((name+".in").c_str());
			ofstream out((name+".out").c_str());
			vector<int> nums(tc/5 + 2);
			int maxl = maxls[tc%5];
			forn(i,nums.size()){
				bool ok = false;
				while(!ok){
					ok = true;
					nums[i] = rand()%int(1e9)+1;
					forn(j,i) if(nums[j]==nums[i]) ok = false;
				}
			}
			int lar[2] = {125,125};
			vector<pair<int,vector<int> > > prevs[2];
			vector<oper> opers;
			vector<int> ids(1005); int idc = 0;
			set<int> used;
			forn(i,ids.size()){
				ids[i] = rand()%int(1e9)+1;
				while(used.count(ids[i]))
					ids[i] = rand()%int(1e9)+1;
			}
			while(lar[0] or lar[1] or prevs[0].size() or prevs[1].size()){
				int per = rand()%2;
				int op = (rand()%5)<4;
				if(lar[per]==0 and prevs[per].size()==0) per = 1-per;
				if(lar[per]==0) op = 0;
				if(prevs[per].size()==0) op = 1;
				vector<int> M;
				int num;
				if(op==0){
					int i = rand()%prevs[per].size();
					num = prevs[per][i].first;
					M = prevs[per][i].second;
					prevs[per].erase(prevs[per].begin()+i);
				}
				else{
					int l = rand()%min(maxl,lar[per])+1;
					lar[per]-=l;
					M = vector<int>(l);
					forn(i,l){
						M[i] = nums[rand()%nums.size()];
					}
					num = ids[idc];
					idc++;
					prevs[per].push_back({num,M});
				}
				opers.push_back({num,per,op,M});
			}
			int N = opers.size();
			Inicializar(N);
			in<<N<<endl;
			forn(i,N){
				in<<opers[i].num<<" "<<opers[i].per<<" "<<opers[i].op<<" "<<opers[i].M.size()<<endl;
				forn(j,opers[i].M.size()){
					if(j) in<<" ";
					in<<opers[i].M[j];
				}
				in<<endl;
				int maxp, ca, cj;
				Actualizar(opers[i].M,opers[i].num,opers[i].per, opers[i].op, maxp, ca, cj);
				out<<maxp<<endl<<ca<<" "<<cj<<endl;
			}
			DBG(N);
		}
		/// Matar brute propuesta por Agus, caso chico
		for(int tc = 30; tc<=32; tc++){
			glob.clear();
			string name = string("S1/")+((tc<10)?"0":"")+to_string(tc);
			ofstream in((name+".in").c_str());
			ofstream out((name+".out").c_str());

			vector<oper> opers;
			vector<int> ids(2); 
			set<int> used;
			forn(i,ids.size()){
				ids[i] = rand()%int(1e9)+1;
				while(used.count(ids[i]))
					ids[i] = rand()%int(1e9)+1;
			}
			vector<int> M(250);
			for(int i = 0;i<250;i++){
				M[i] = rand()%int(1e9)+1;
			}
			opers.push_back({ids[0],0,1,M});
			opers.push_back({ids[1],1,1,M});
			int N = opers.size();
			Inicializar(N);
			in<<N<<endl;
			forn(i,N){
				in<<opers[i].num<<" "<<opers[i].per<<" "<<opers[i].op<<" "<<opers[i].M.size()<<endl;
				forn(j,opers[i].M.size()){
					if(j) in<<" ";
					in<<opers[i].M[j];
				}
				in<<endl;
				int maxp, ca, cj;
				Actualizar(opers[i].M,opers[i].num,opers[i].per, opers[i].op, maxp, ca, cj);
				out<<maxp<<endl<<ca<<" "<<cj<<endl;
			}
		}
	}
	
	/// Subtarea 2: T<=3000
	cout<<"Subtarea 2"<<endl<<endl;
	if(subtarea2){
		srand(314159);
		int maxls2[5] = {3,5,10,50,750}; 
		for(int tc = 0;tc<30;tc++){
			glob.clear();
			string name = string("S2/")+((tc<10)?"0":"")+to_string(tc);
			ofstream in((name+".in").c_str());
			ofstream out((name+".out").c_str());
			vector<int> nums(tc/5 + 5);
			int maxl = maxls2[tc%5];
			forn(i,nums.size()){
				bool ok = false;
				while(!ok){
					ok = true;
					nums[i] = rand()%int(1e9)+1;
					forn(j,i) if(nums[j]==nums[i]) ok = false;
				}
			}
			int lar[2] = {750,750};
			vector<pair<int,vector<int> > > prevs[2];
			vector<oper> opers;
			vector<int> ids(7000); int idc = 0;
			set<int> used;
			forn(i,ids.size()){
				ids[i] = rand()%int(1e9)+1;
				while(used.count(ids[i]))
					ids[2] = rand()%int(1e9)+1;
			}
			while(lar[0] or lar[1] or prevs[0].size() or prevs[1].size()){
				int per = rand()%2;
				int op = (rand()%5)<4;
				if(lar[per]==0 and prevs[per].size()==0) per = 1-per;
				if(lar[per]==0) op = 0;
				if(prevs[per].size()==0) op = 1;
				vector<int> M;
				int num;
				if(op==0){
					int i = rand()%prevs[per].size();
					num = prevs[per][i].first;
					M = prevs[per][i].second;
					prevs[per].erase(prevs[per].begin()+i);
				}
				else{
					int l = rand()%min(maxl,lar[per])+1;
					lar[per]-=l;
					M = vector<int>(l);
					forn(i,l){
						M[i] = nums[rand()%nums.size()];
					}
					num = ids[idc];
					idc++;
					prevs[per].push_back({num,M});
				}
				opers.push_back({num,per,op,M});
			}
			int N = opers.size();
			Inicializar(N);
			in<<N<<endl;
			forn(i,N){
				in<<opers[i].num<<" "<<opers[i].per<<" "<<opers[i].op<<" "<<opers[i].M.size()<<endl;
				forn(j,opers[i].M.size()){
					if(j) in<<" ";
					in<<opers[i].M[j];
				}
				in<<endl;
				int maxp, ca, cj;
				Actualizar(opers[i].M,opers[i].num,opers[i].per, opers[i].op, maxp, ca, cj);
				out<<maxp<<endl<<ca<<" "<<cj<<endl;
			}
			DBG(N);
		}
	}
	
	/// Subtarea 3: Sin Borrar
	cout<<"Subtarea 3"<<endl<<endl;
	
	if(subtarea3){
		srand(32064323);
		int maxls3[5] = {100,1000,5000,10000,100000}; 
		for(int tc = 0;tc<30;tc++){
			glob.clear();
			string name = string("S3/")+((tc<10)?"0":"")+to_string(tc);
			ofstream in((name+".in").c_str());
			ofstream out((name+".out").c_str());
			vector<int> nums(tc/5 + 5);
			int maxl = maxls3[tc%5];
			forn(i,nums.size()){
				bool ok = false;
				while(!ok){
					ok = true;
					nums[i] = rand()%int(1e9)+1;
					forn(j,i) if(nums[j]==nums[i]) ok = false;
				}
			}
			int lar[2] = {100000,100000};
			vector<pair<int,vector<int> > > prevs[2];
			vector<oper> opers;
			vector<int> ids(200000); int idc = 0;
			set<int> used;
			forn(i,ids.size()){
				ids[i] = rand()%int(1e9)+1;
				while(used.count(ids[i]))
					ids[i] = rand()%int(1e9)+1;
			}
			forn(i,ids.size()) ids[i] = rand()%int(1e9)+1;
			while(lar[0] or lar[1]){
				int per = rand()%2;
				int op = 1;
				if(lar[per]==0 ) per = 1-per;
				vector<int> M;
				int num;
				
				int l = rand()%min(maxl,lar[per])+1;
				lar[per]-=l;
				M = vector<int>(l);
				forn(i,l){
					M[i] = nums[rand()%nums.size()];
				}
				num = ids[idc];
				idc++;
				
				opers.push_back({num,per,op,M});
			}
			int N = opers.size();
			Inicializar(N);
			in<<N<<endl;
			forn(i,N){
				in<<opers[i].num<<" "<<opers[i].per<<" "<<opers[i].op<<" "<<opers[i].M.size()<<endl;
				forn(j,opers[i].M.size()){
					if(j) in<<" ";
					in<<opers[i].M[j];
				}
				in<<endl;
				int maxp, ca, cj;
				Actualizar(opers[i].M,opers[i].num,opers[i].per, opers[i].op, maxp, ca, cj);
				out<<maxp<<endl<<ca<<" "<<cj<<endl;
			}
			DBG(N);
		}
		for(int tc = 30; tc<=32; tc++){
			glob.clear();
			string name = string("S3/")+((tc<10)?"0":"")+to_string(tc);
			ofstream in((name+".in").c_str());
			ofstream out((name+".out").c_str());

			vector<oper> opers;
			vector<int> ids(2);
			set<int> used;
			forn(i,ids.size()){
				ids[i] = rand()%int(1e9)+1;
				while(used.count(ids[i]))
					ids[i] = rand()%int(1e9)+1;
			}
			vector<int> M(100000);
			for(int i = 0;i<100000;i++){
				M[i] = rand()%int(1e9)+1;
			}
			opers.push_back({ids[0],0,1,M});
			opers.push_back({ids[1],1,1,M});
			int N = opers.size();
			Inicializar(N);
			in<<N<<endl;
			forn(i,N){
				in<<opers[i].num<<" "<<opers[i].per<<" "<<opers[i].op<<" "<<opers[i].M.size()<<endl;
				forn(j,opers[i].M.size()){
					if(j) in<<" ";
					in<<opers[i].M[j];
				}
				in<<endl;
				int maxp, ca, cj;
				Actualizar(opers[i].M,opers[i].num,opers[i].per, opers[i].op, maxp, ca, cj);
				out<<maxp<<endl<<ca<<" "<<cj<<endl;
			}
		}
	}
	
	/// Subtarea 4: Sin restricciones adicionales
	cout<<"Subtarea 4"<<endl<<endl;
	if(subtarea4){
		srand(123456);
		int maxls4[5] = {100,1000,5000,10000,100000}; 
		for(int tc = 0;tc<30;tc++){
			glob.clear();
			string name = string("S4/")+((tc<10)?"0":"")+to_string(tc);
			ofstream in((name+".in").c_str());
			ofstream out((name+".out").c_str());
			vector<int> nums(tc/5 + 5);
			int maxl = maxls4[tc%5];
			forn(i,nums.size()){
				bool ok = false;
				while(!ok){
					ok = true;
					nums[i] = rand()%int(1e9)+1;
					forn(j,i) if(nums[j]==nums[i]) ok = false;
				}
			}
			int lar[2] = {50000,50000};
			vector<pair<int,vector<int> > > prevs[2];
			vector<oper> opers;
			vector<int> ids(200000); int idc = 0;
			set<int> used;
			forn(i,ids.size()){
				ids[i] = rand()%int(1e9)+1;
				while(used.count(ids[i]))
					ids[i] = rand()%int(1e9)+1;
			}
			while(lar[0] or lar[1] or prevs[0].size() or prevs[1].size()){
				int per = rand()%2;
				int op = (rand()%5)<4;
				if(lar[per]==0 and prevs[per].size()==0) per = 1-per;
				if(lar[per]==0) op = 0;
				if(prevs[per].size()==0) op = 1;
				vector<int> M;
				int num;
				if(op==0){
					int i = rand()%prevs[per].size();
					num = prevs[per][i].first;
					M = prevs[per][i].second;
					prevs[per].erase(prevs[per].begin()+i);
				}
				else{
					int l = rand()%min(maxl,lar[per])+1;
					lar[per]-=l;
					M = vector<int>(l);
					forn(i,l){
						M[i] = nums[rand()%nums.size()];
					}
					num = ids[idc];
					idc++;
					prevs[per].push_back({num,M});
				}
				opers.push_back({num,per,op,M});
			}
			int N = opers.size();
			Inicializar(N);
			in<<N<<endl;
			forn(i,N){
				in<<opers[i].num<<" "<<opers[i].per<<" "<<opers[i].op<<" "<<opers[i].M.size()<<endl;
				forn(j,opers[i].M.size()){
					if(j) in<<" ";
					in<<opers[i].M[j];
				}
				in<<endl;
				int maxp, ca, cj;
				Actualizar(opers[i].M,opers[i].num,opers[i].per, opers[i].op, maxp, ca, cj);
				out<<maxp<<endl<<ca<<" "<<cj<<endl;
			}
			DBG(N);
		}
		
	}
}

