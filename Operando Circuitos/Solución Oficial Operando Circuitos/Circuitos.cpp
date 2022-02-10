#include <bits/stdc++.h>
using namespace std;
set<int> * AND(set<int> *s1, set<int> *s2){
    set<int> * s3 = new set<int>();
    if(s1->size()>s2->size())swap(s1,s2);
    for(auto x : *s1){
        if(s2->find(x)!=s2->end())
            s3->insert(x);
    }
    return s3;
}
set<int> * OR(set<int> * s1, set<int> *s2){
    if(s1->size()>s2->size())swap(s1,s2);
    for(auto x : *s1){
        s2->insert(x);
    }
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
    return s2;
}
set<int> * Eval(int pos, string & tipo, vector<vector<int> > & input){
    if(tipo[pos] == 'E'){
        set<int> * s = new set<int>();
        for(auto x : input[pos]){
            s->insert(x);
        }
        return s;
    }
    if(tipo[pos] == 'O'){
            return OR(Eval(input[pos][0],tipo,input),Eval(input[pos][1],tipo,input));
    }
    if(tipo[pos] == 'A'){
            return AND(Eval(input[pos][0],tipo,input),Eval(input[pos][1],tipo,input));
    }
    if(tipo[pos] == 'X'){
            return XOR(Eval(input[pos][0],tipo,input),Eval(input[pos][1],tipo,input));
    }
    if(tipo[pos] == 'L'){
            return Eval(input[pos][0],tipo,input);
    }
}
vector<vector<int> > Circuitos(string tipo, vector<vector<int> > input){
    int N = tipo.size();
    vector<vector<int> > result(N);
    for(int i = 0;i<N;i++){
        if(tipo[i]=='L'){
            set<int> * s = Eval(i,tipo,input);
            for(auto x : *s){
                result[i].push_back(x);
            }
        }
    }
    return result;
}
