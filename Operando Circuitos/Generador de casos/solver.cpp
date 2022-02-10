#include <bits/stdc++.h>
using namespace std;
set<int> * AND(set<int> *s1, set<int> *s2){
    set<int> * s3 = new set<int>();
    if(s1->size()>s2->size())swap(s1,s2);
    for(auto x : *s1){
        if(s2->find(x)!=s2->end())
            s3->insert(x);
    }
    free(s1);
    free(s2);
    return s3;
}
set<int> * OR(set<int> * s1, set<int> *s2){
    if(s1->size()>s2->size())swap(s1,s2);
    for(auto x : *s1){
        s2->insert(x);
    }
    free(s1);
    return s2;
}

set<int> * XOR(set<int> * s1, set<int> * s2){
    if(s1->size()>s2->size())swap(s1,s2);
    for(auto x : *s1){
        if(s2->find(x)!=s2->end())
            s2->erase(x);
        else
            s2->insert(x);
    }
    free(s1);
    return s2;
}
//int prof = 0;
set<int> * Eval(int pos, string & tipo, vector<vector<int> > & input, int prof = 0){
    //DBG(make_pair(pos,prof));
    if(tipo[pos] == 'E'){
        set<int> * s = new set<int>();
        for(auto x : input[pos]){
            s->insert(x);
        }
        return s;
    }
    if(tipo[pos] == 'O'){
            return OR(Eval(input[pos][0],tipo,input, prof+1),Eval(input[pos][1],tipo,input, prof+1));
    }
    if(tipo[pos] == 'A'){
            return AND(Eval(input[pos][0],tipo,input, prof+1),Eval(input[pos][1],tipo,input, prof+1));
    }
    if(tipo[pos] == 'X'){
            return XOR(Eval(input[pos][0],tipo,input, prof+1),Eval(input[pos][1],tipo,input, prof+1));
    }
    if(tipo[pos] == 'L'){
            return Eval(input[pos][0],tipo,input, prof+1);
    }

}
vector<vector<int> > Circuitos(string tipo, vector<vector<int> > input){
    int N = tipo.size();
    vector<vector<int> > result(N);
    vector<set<int> *> vs(N,nullptr);
    vector<int> inds;
    for(int i = 0;i<N;i++){
        if(tipo[i]=='L'){
            inds.pb(i);
        }
    }
    while(inds.size()){
        int t = inds.back();
        inds.pop_back();
    //    DBG(inds.size());
    //    DBG(t);
        if(t>=0){
            if(tipo[t]=='E')
                vs[t] = Eval(t,tipo,input);
            else{
                inds.pb(-t-1);
                for(auto x : input[t])
                    inds.pb(x);
            }
        }else{
            t = -t - 1;
            if(tipo[t]=='O') vs[t] = OR(vs[input[t][0]],vs[input[t][1]]);
            if(tipo[t]=='A') vs[t] = AND(vs[input[t][0]],vs[input[t][1]]);
            if(tipo[t]=='X') vs[t] = XOR(vs[input[t][0]],vs[input[t][1]]);
            if(tipo[t]=='L') vs[t] = vs[input[t][0]];
        }
    }
    //cout<<"next"<<endl;
    //DBG(vs.size());
    forn(i,N)
    {
    //    DBG(i);
    //    DBG(tipo[i]);
        if(tipo[i]=='L')
        {
    //        DBG(vs[i]);
            for(auto x : *vs[i])
                result[i].pb(x);
        }
    }
    return result;
}
void solver(istream & in, ostream & out)
{
    int N; in>>N;
    string tipo;
    vector<vector<int> > input(N);
    in>>tipo;
    for(int i = 0;i<N;i++){
        int tam; in>>tam;
        input[i].resize(tam);
        for(int j = 0; j<tam;j++){
            in>>input[i][j];
        }
    }
    //cout<<"input leido"<<endl;
    vector<vector<int> > result = Circuitos(tipo,input);
    //cout<<"solucion ejecutada"<<endl;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<result[i].size();j++){
            out<<result[i][j]<<" ";
        }
        out<<endl;
    }
}

string Chequer(string tc){
    //DBG(tc);
    ifstream in(tc);
    int N, M = 0 ; in>>N;
    //DBG(N);
    string t; in>>t;
    vector<vector<int> > v(N);
    vector<bool> vis(N,false);
    forn(i,N){
        int k;in>>k;
        M += k;
        if(t[i]=='L') vis[i] = true;
        if(t[i]=='L' && k!=1) return "Mal L";
        if(t[i]=='O' && k!=2) return "Mal O";
        if(t[i]=='A' && k!=2) return "Mal A";
        if(t[i]=='X' && k!=2) return "Mal X";
        forn(j,k){
            int a; in>>a;
            if(a<0) return "a < 0";
            if(t[i]!='E'){
                if(a>=N){
                    DBG(a);
                    DBG(N);
                    return "a >= N";
                }
                if(vis[a]){
                    DBG(a);
                    return "a ya visto";
                }
                vis[a] = true;
            }
            v[i].pb(a);
        }
    }
    //cout<<"lectura A ok"<<endl;
    int c = accumulate(ALL(vis),0);
    cout<<tc<<" => "<<c<<" / "<<N<<" | "<<M<<endl;
    if(!all_of(ALL(vis),[](bool a){return a;})) return "No se visitan todos";
    return "todo OK";
}
