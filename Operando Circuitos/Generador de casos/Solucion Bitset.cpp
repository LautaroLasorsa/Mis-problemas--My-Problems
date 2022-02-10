#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0;i<int(n);i++)
using namespace std;

bitset<5001> Eval(int pos, string & tipo, vector<vector<int> > & input){
    if(tipo[pos] == 'E'){
        bitset<5001> s;
        for(auto x : input[pos]){
            s[x] = true;
        }
        return s;
    }
    if(tipo[pos] == 'O'){
            return Eval(input[pos][0],tipo,input) | Eval(input[pos][1],tipo,input);
    }
    if(tipo[pos] == 'A'){
            return Eval(input[pos][0],tipo,input)&Eval(input[pos][1],tipo,input);
    }
    if(tipo[pos] == 'X'){
            return Eval(input[pos][0],tipo,input)^Eval(input[pos][1],tipo,input);
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
            bitset<5001> bs = Eval(i,tipo,input);
            forn(x,5001){
                if(bs[x])result[i].push_back(x);
            }
        }
    }
    return result;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
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
