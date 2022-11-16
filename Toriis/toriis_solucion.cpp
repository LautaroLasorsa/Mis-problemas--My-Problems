#include <bits/stdc++.h>
using namespace std;

#define MOD 112345687
#define ll long long

struct Arista
{
    int desde, hasta, id, toriis;
};

vector <vector <Arista> > ady;
vector <bool> visit;
vector <int> orden;

void TopoSort(int n)
{
    visit[n] = true;
    for(struct Arista i:ady[n])
        if(!visit[i.hasta])
            TopoSort(i.hasta);
    orden.push_back(n);
}

int binModPow(int base, int exp)
{
    if(exp == 0)
        return 1;
    if(exp == 1)
        return base;
    ll sub = binModPow(base, exp/2);
    return (((sub*sub)%MOD) * (exp%2 ? ((ll)base) : 1LL))%MOD;
}

int Cantidad_Caminos(int n, int m, vector <int> ini, vector <int> fin, vector <int> cant)
{
    ady.resize(n+1);
    visit = vector <bool> (n+1, false);

    for(int i=0; i<m; i++)
        ady[ini[i]].push_back({ini[i], fin[i], i, cant[i]});

    for(int i=1; i<=n; i++)
        if(!visit[i])
            TopoSort(i);

    reverse(orden.begin(), orden.end());

    vector <int> pares(n+1, 1), impares(n+1, 0);

    for(int i=0; i<fin.size(); i++)
        pares[fin[i]] = 0;

    for(int i:orden)
    {
        for(struct Arista ar:ady[i])
        {
            int a = ar.desde;
            int b = ar.hasta;
            ll bmp = binModPow(2, ar.toriis-1);
            ll suma = (impares[a]+pares[a])%MOD;
            suma = (suma*bmp)%MOD;
            pares[b] = (pares[b]+suma)%MOD;
            impares[b] = (impares[b]+suma)%MOD;
        }
    }

    int sumaTotal = 0;
    for(int i=1; i<=n; i++)
        if(ady[i].size() == 0)
            sumaTotal = (sumaTotal + pares[i])%MOD;

    return sumaTotal;
}

