#include <bits/stdc++.h>
using namespace std;
map<int,int> nodos;
struct nodo{
	map<int,int> nex;
	int pad[18];
	int prof;
};
nodo Trie[int(3e5)];
int tam = 1;
int Add(vector<int> car){
	int loc = 0;
	for(auto it : car){
		if(Trie[loc].nex[it]==0){
			Trie[loc].nex[it] = tam;
			Trie[tam].pad[0] = loc;
			for(int k = 1;k<18;k++)
				Trie[tam].pad[k] = Trie[Trie[tam].pad[k-1]].pad[k-1];
			Trie[tam].prof = Trie[loc].prof+1;
			tam++;
		}
		loc = Trie[loc].nex[it];
	}
	return loc;
}
int lca(int x, int y){
	if(x==y) return x;
	if(Trie[x].prof>Trie[y].prof) swap(x,y);
	for(int k=17;k>=0;k--){
		if(Trie[x].prof+(1<<k)<=Trie[y].prof)
			y = Trie[y].pad[k];
	}
	if(x==y) return x;
	for(int k = 17;k>=0;k--){
		if(Trie[x].pad[k]!=Trie[y].pad[k])
			x = Trie[x].pad[k], y = Trie[y].pad[k];
	}
	return Trie[x].pad[0];
}
int main(int , char *args[])
{
    ifstream input(args[1]), correctOutput(args[2]), contestantsOutput(args[3]);
    int N; input>>N;
    map<int,int> pos[2];
    bool p1ok = true, p2ok = true;
    for(int i = 0; i<N;i++){
		int num,per, op, M;
		input>>num>>per>>op>>M;
		vector<int> in(M);
		for(int j = 0;j<M;j++){
			input>>in[j];
		}
		int r1[3], r2[3] = {-2,-2,-2};
		string participante;
		getline(contestantsOutput, participante);
		istringstream linea(participante);
		linea>>r2[0];
		getline(contestantsOutput, participante);
		linea = istringstream(participante);
		linea>>r2[1]>>r2[2];
		for(int j = 0;j<3;j++){
			correctOutput>>r1[j];
		}
		if(op == 0){
			pos[per].erase(num);
		}else{
			pos[per][num] = Add(in);
		}
		if(r1[0]!=r2[0]){
			p1ok = false;
			p2ok = false;
		}
		if(r1[0]!=-1){
			if(pos[0].count(r2[1])==0 or pos[1].count(r2[2])==0){
				p2ok = false;
			}
			int lc = lca(pos[0][r2[1]], pos[1][r2[2]]); 
			if(Trie[lc].prof!=r2[0]){
				
				p2ok = false;
			}
		}else{
			if(r2[1]!=-1 or r2[2]!=-1)
			{
				p2ok = false;
			}
		}
	}
	if(p2ok) cout<<"1.0"<<endl;
	else if(p1ok) cout<<"0.6"<<endl;
	else cout<<"0.0"<<endl;
    return 0;
}
