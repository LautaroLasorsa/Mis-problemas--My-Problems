#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int res = 0;
vector<vector<int> > hs;
pair<int,int> dp(int x = 0){ /// forma recursiva
    int a = 1, b = 0;
    /// pares, impares
    for(auto y : hs[x]){
        auto p = dp(y);
        int aa = (1ll*a*p.first + 1ll*b*p.second)%mod;
        int bb = (1ll*a*p.second + 1ll*b*p.first)%mod;
        a = aa, b = bb;
    }
    res = (res+a)%mod;
    b = (b+1)%mod;
    return {b,a};
}

int dpIter(vector<vector<int> > subs){ /// forma iterativa
    vector<int> ord = {0};
    int N = subs.size();
    for(int i = 0;i<(int)ord.size();i++)
        for(auto y : subs[ord[i]])
            ord.push_back(y);
    vector<pair<int,int> > dpv(N);
    int lres = 0;
    for(int j = N-1;j>=0;j--){
        int x = ord[j];
        int a = 1, b = 0;
    /// pares, impares
        for(auto y : subs[x]){
            auto p = dpv[y];
            int aa = (1ll*a*p.first + 1ll*b*p.second)%mod;
            int bb = (1ll*a*p.second + 1ll*b*p.first)%mod;
            a = aa, b = bb;
        }
        lres = (lres+a)%mod;
        b = (b+1)%mod;
        dpv[x] = {b,a};
    }
    return lres;
}
int impares(vector<vector<int> > subordinados){
    res = 0;
    hs = subordinados;
    int res2 = dpIter(subordinados);
    if(subordinados.size()<20){
        dp();
        assert(res==res2);
    }
    return res2;
}