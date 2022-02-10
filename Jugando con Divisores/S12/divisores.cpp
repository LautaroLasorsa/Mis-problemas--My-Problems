#include "divisores.h"
#include <bits/stdc++.h>

/**
Estas funciones se podrían sintetizar en un solo for, lo se, pero creo que
asi el código esta más autodocumentado y es entendible (más si lo van a
mostrar a participantes de Nivel 1

Notar que es la misma solución para los niveles 1 y 2.
**/
long long Agustin(long long N, vector<long long> prims){
    long long S = N;
    int i = 0, j = prims.size()-1;
    for(int k = 0;k<(int)prims.size();k++){
        if(k%2==0){
            N/=prims[j];
            j--;
        }else{
            N/=prims[i];
            i++;
        }
        S+=N;
    }
    return S;
}
long long Gaston(long long N, vector<long long> prims){
    long long S = N;
    int i = 0, j = prims.size()-1;
    for(int k = 0;k<(int)prims.size();k++){
        if(k%2==1){
            N/=prims[j];
            j--;
        }else{
            N/=prims[i];
            i++;
        }
        S+=N;
    }
    return S;
}

vector<long long> Divisores(long long N){
    /**
    Notar que la parte de obtener los divisores primos es común a los 3 niveles
    La unica diferencia es que en la version de Nivel 1 y 2 los contamos con repetición,
    y en la de Nivel 3 sin repetición.
    */
    vector<long long> prims; /// Los divisores PRIMOS de N
    long long N2 = N;
    for(long long i = 2;i*i<=N2;i++){
        while(N2%i==0){
            prims.push_back(i);
            N2/=i;
        }
    }
    if(N2!=1) prims.push_back(N2);
    sort(prims.begin(),prims.end());
    vector<long long> result(2);
    result[0] = Agustin(N, prims);
    result[1] = Gaston(N, prims);
    return result;
}
