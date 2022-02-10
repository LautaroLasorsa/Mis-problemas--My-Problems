#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0;i<int(n);i++)
#define pb push_back
using namespace std;
set<int> * AND(set<int> *s1, set<int> *s2){
    set<int> * s3 = new set<int>();
    //if(s1->size()>s2->size())swap(s1,s2);
    for(auto x : *s1){
        if(s2->find(x)!=s2->end())
            s3->insert(x);
    }
    return s3;
}
set<int> * OR(set<int> * s1, set<int> *s2){
    //if(s1->size()>s2->size())swap(s1,s2);
    for(auto x : *s1){
        s2->insert(x);
    }
    return s2;
}

set<int> * XOR(set<int> * s1, set<int> * s2){
    //if(s1->size()>s2->size())swap(s1,s2);
    for(auto x : *s1){
        if(s2->find(x)!=s2->end())
            s2->erase(x);
        else
            s2->insert(x);
    }
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
        if(inds.size()%1000 == 0) DBG(inds.size());
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
            if(tipo[t]=='L') {
                vs[t] = vs[input[t][0]];
                continue;
            }
            if(tipo[input[t][1]]=='E') swap(input[t][0],input[t][1]);
            if(tipo[t]=='O') vs[t] = OR(vs[input[t][0]],vs[input[t][1]]);
            if(tipo[t]=='A') vs[t] = AND(vs[input[t][0]],vs[input[t][1]]);
            if(tipo[t]=='X') vs[t] = XOR(vs[input[t][0]],vs[input[t][1]]);
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
int main()
{
//    cin.tie(0);
//    cin.sync_with_stdio(0);
    ifstream in("inputs\\24.in");
    ofstream out("sarasa.txt");
    #define cin in
    #define cout out
    int N; cin>>N;
    string tipo;
    vector<vector<int> > input(N);
    cin>>tipo;
    for(int i = 0;i<N;i++){
        int tam; cin>>tam;
        input[i].resize(tam);
        for(int j = 0; j<tam;j++){
            cin>>input[i][j];
        }
    }
    vector<vector<int> > result = Circuitos(tipo,input);
    for(int i = 0;i<N;i++){
        for(int j = 0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}
