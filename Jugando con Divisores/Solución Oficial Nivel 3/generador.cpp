#include <bits/stdc++.h>
#include "divisores.cpp"
using namespace std;
typedef long long intl;
vector<int> primos;
intl lim = 100000000000000LL;
vector<pair<intl,intl> > ns;
void Recur(int i = 0, intl num = 1, intl cdivs = 1){
	int ex = 0;
	if(num*primos[i]>lim) ns.push_back({cdivs,num});
	else while(num*primos[i]<=lim){
		num*=primos[i];
		ex++;
		Recur(i+1,num,cdivs*(ex+1));
	}
}
const intl lims[5] = {10ll,1000ll,1000000ll, 10000000000ll, 100000000000000ll};
int main()
{
	for(int i = 2;i<=100;i++){
		bool p = true;
		for(int j = 2;j<i;j++)
			if(i%j==0)
				p = false;
		if(p) primos.push_back(i);
	}
	srand(111);
	int tc = 1;
	for(int sub = 0; sub<5; sub++){
		lim = lims[sub];
		ns.clear();
 	    Recur();
 	    sort(ns.rbegin(),ns.rend());
 	    for(int i = 0;i<10;i++){
			string ruta = string("Casos/Subtarea ")+to_string(sub+1)+string("/Divisores")+to_string(tc);
			cout<<ruta<<endl;
			tc++;
			ofstream fin(ruta+string(".in"));
			ofstream fout(ruta+string(".out"));
			intl N = ns[i%ns.size()].second, M;
			if(i) M = rand()%(10000000)+1;
			else M = 1;
			fin<<N<<" "<<M<<endl;
			auto p = Divisores(N,M);
			cout<<N<<" "<<M<<" >> "<<p[0]<<" "<<p[1]<<endl;
			fout<<p[0]<<" "<<p[1]<<endl;
			fin.close();
			fout.close();
		}
	}
	return 0;
}

