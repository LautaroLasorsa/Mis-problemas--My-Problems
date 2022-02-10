typedef long long intl;
using namespace std;
int electricista(vector<pair<int,int> > tubos, int X, long long MOD)
{
    int N =  tubos.size(), M = N+1, CH = 0; /// CH = Cantidad de Hojas
    if(X >= M) /// Si tengo más cables que nodos (sin contar la roceta 0) es imposible armar la red.
        return -1;
    vector<int> grado(M,0); /// Grado de cada nodo (cada roceta)
    for(auto k : tubos)
        grado[k.first]++,grado[k.second]++;
    for(int i = 1;i<M;i++) /// Ignoro el nodo 0
        if(grado[i]==1) /// Si el nodo i tiene grado 1, es decir que es una hoja.
            CH++;
    if(CH > X) /// Si tengo más hojas que cables es imposible armar dicha red.
        return -1;
    intl CI = M-1-CH, CL = X-CH; /// CI = Cantidad de nodos Interiores. CL = Cantidad de cables Libres (sin asignar)
    vector<vector<pair<int,int> > > facts(CI+1); /// Guardo la factorización en primos de cada número de 1 a CI
    for(intl i = 2;i<=CI;i++)
    {
        if(facts[i].size() == 0) /// Si es primo
        {
            facts[i] = {{i,1}}; /// Factor Primo , Exponente con el que aparece
            for(intl j = i*2;j<=CI;j+=i)
            {
                intl k = j; /// Hago una copia local por comodidad
                intl exp = 0;
                while(k%i == 0) k/=i, exp++;
                facts[j].push_back({i,exp});
            }
        }
    }
    vector<intl> cantf(CI+1,0); /// Factores primos de la cantidad de formas
    for(int i = 0;i<CL;i++)
    {
        for(auto k : facts[CI-i]) cantf[k.first] += k.second; /// Multiplicar es sumar los exponentes de sus factores primos
        for(auto k : facts[i+1]) cantf[k.first] -= k.second; /// Dividir es restar los exponentes de sus factores primos
    }
    intl cant = 1;
    for(intl i = 1;i<=CI;i++)
        for(int j = 0;j<cantf[i];j++)
            cant = (cant*i)%MOD; /// Acá es donde básicamente se hace la cuenta.
    return int(cant);
}
