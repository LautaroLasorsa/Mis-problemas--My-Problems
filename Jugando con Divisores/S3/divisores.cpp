#include "divisores.h"
#include <bits/stdc++.h>
unordered_map<long long, long long> gaston, agustin;

long long Agustin(long long N, long long M, vector<long long> & prims);
long long Gaston(long long N, long long M, vector<long long> & prims);

long long Agustin(long long N, long long M, vector<long long> & prims){
    auto it = agustin.find(N);
    if(it!=agustin.end()) return it->second;
    auto & v = agustin[N];
    v = -1;
    long long pN = (N%M)*(N%M) % M;
    pN = pN*pN;
    for(auto y : prims)
    {
        if(N%y!=0) continue;
        long long val = Gaston(N/y,M,prims);
        if(v==-1 or v>val)
            v = val;
    }
    v += pN;
    return v;
}
long long Gaston(long long N, long long M, vector<long long> & prims){
     auto it = gaston.find(N);
    if(it!=gaston.end()) return it->second;
    auto & v = gaston[N];
    v = -1;
    long long pN = (N%M)*(N%M) % M;
    pN = pN*pN;
    for(auto y : prims)
    {
        if(N%y!=0) continue;
        long long val = Agustin(N/y,M,prims);
        if(v<val)
            v = val;
    }
    v += pN;
    return v;
}

vector<long long> Divisores(long long N, long long M){
    gaston.clear();
    agustin.clear();
    /**
    Notar que la parte de obtener los divisores primos es común a los 3 niveles
    La unica diferencia es que en la version de Nivel 1 y 2 los contamos con repetición,
    y en la de Nivel 3 sin repetición.
    */
    vector<long long> prims; /// Los divisores PRIMOS de N
    long long N2 = N;
    for(long long i = 2;i*i<=N2;i++){
        if(N2%i==0) prims.push_back(i);
        while(N2%i==0){
            N2/=i;
        }
    }
    gaston[1] = agustin[1] = (1%M)*(1%M);
    if(N2!=1) prims.push_back(N2);
    vector<long long> result(2);
    result[0] = Agustin(N, M, prims);
    result[1] = Gaston(N, M, prims);
    return result;
}
