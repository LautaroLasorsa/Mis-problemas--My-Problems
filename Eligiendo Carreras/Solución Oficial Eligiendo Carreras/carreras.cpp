#include <vector>
#include <set>
#include <map>
using namespace std;
set<pair<int,int> > glob;
struct Nodo{
    set<int> ana, joe;
    int prof, id;
    map<int,int> prox;
    void Actualiar(int per, int op, int num){
        set<int> * s;
        if(per == 0) s = &ana;
        else s = &joe;
        if(op == 0) s->erase(num);
        else s->insert(num);

        if(ana.size() == 0 || joe.size() == 0)
            glob.erase({prof,id});
        else
            glob.insert({prof,id});
    }
    Nodo(){
        prof = id = -1;
    }
};
Nodo Trie[200001];
int tsize;
void Inicializar(int N){
    for(int i = 0;i<tsize;i++){
		Trie[i].id = -1;
		Trie[i].prof = -1;
		Trie[i].prox.clear();
		Trie[i].ana.clear();
		Trie[i].joe.clear();
	}
	glob.clear();
    tsize = 1;
    Trie[0].prof = 0;
    Trie[0].id = 0;
}
void Actualizar(vector<int> car, int num, int per, int op, int & maxp, int & ca, int & cj){
    int nod = 0, M = int(car.size());
    Trie[0].Actualiar(per,op,num);
    for(int i = 0;i<M;i++){
        if(Trie[nod].prox.count(car[i]) == 0){
            Trie[nod].prox[car[i]] = tsize;
            Trie[tsize].id = tsize;
            Trie[tsize].prof = i+1;
            tsize++;
        }
        nod = Trie[nod].prox[car[i]];
        Trie[nod].Actualiar(per,op,num);
    }
    if(glob.size() == 0){
        maxp = ca = cj = -1;
        return;
    }
    pair<int,int> p = *glob.rbegin();
    maxp = p.first;
    nod = p.second;
    ca = *Trie[nod].ana.begin();
    cj = *Trie[nod].joe.begin();
}
