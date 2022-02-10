
using namespace std;
int id[1000000], tam[1000000];
int findn(int x) /// Encuentra la componente del nodo.
{
    if(id[x] == x) return x;
    return (id[x] = findn(id[x]));
}
void unir(int a, int b) /// Une 2 nodos (une las componentes a las que pertenece cada nodo)
{
    int ta = findn(a), tb = findn(b);
    if(ta == tb) /// Si ya estan en la misma componente no hace nada
        return;
    if(tam[ta] > tam[tb]) /// Nos interesa unir la más chica a la más grande (optimización innecesaria para obtener 100 puntos en el problema)
        swap(a,b),swap(ta,tb);
    id[ta] = tb;
    tam[tb] += tam[ta];
    //cout<<ta<<" = "<<tam[ta]<<" se une a "<<tb<<" = "<<tam[tb]<<endl;
}
void Unir(int ai, int aj, int bi, int bj, int N, int M)
{
    /// Combierte las coordenadas a un unico numero
    int nodoa = ai*M + aj;
    int nodob = bi*M + bj;
    ///Une los nodos
    unir(nodoa,nodob);
}
int mx[] = {1,0,-1,0}, my[] = {0,1,0,-1}; /// Movimientos en X y en Y.
bool Legal(int i, int j, vector<string> & labo) /// Valida si una baldosa esta libre
{
    if(i < 0 || i >= labo.size()) /// Verifica que el indice i sea valido
        return false;
    if(j < 0 || j >= labo[0].size()) /// Verifica que el indice j sea valido
        return false;
    return (labo[i][j] == '.' || labo[i][j] == 'E'); /// Mira el contenido de la baldosa
}
vector<int> laboratorio(vector<string> labo, vector<pair<int,int> > perros)
{
    int N = labo.size(), M = labo[0].size();
    int P = perros.size();
    for(int i = 0;i<1000000;i++) id[i] = i, tam[i] = 1;
    int E=-1; /// Guarda un nodo de entrada, para poder consultar facilmente la componente.
    vector<string> local = labo; /// Hago una copia local de labo para sobreescribirla durante la ejecución del programa.
    for(auto k : perros)
        local[k.first][k.second] = 'P'; /// Guardo donde se ubica cada perro al final.
    vector<int> res(P,-1); /// El vector que contiene la respuesta.
    for(int i = 0;i<N;i++)
        for(int j = 0;j<M;j++)
        {
            if(local[i][j] == '.' || local[i][j] == 'E')
                for(int k = 0;k<4;k++)
                {
                    int y = i + my[k];
                    int x = j + mx[k];
                    if(Legal(y,x,local)) /// Vemos si nos movemos a un lugar legal
                        Unir(i,j,y,x,N,M); /// Unimos ambas celdas
                }
            if(local[i][j] == 'E')
            {
                int nod = i*M + j; /// numero de nodo de la entrada
                if(E == -1) /// Si no hay una entrada descubierta antes.
                    E = nod; /// Asigna E a este nodo.
                else
                    unir(E,nod); /// Lo une a las entradas ya encontradas.
            }
        }
    if(E == -1)
        res[P-1] = 0;
    else
        res[P-1] = tam[findn(E)];
   // for(auto k : local)
   //     cout<<k<<endl;
    for(int i = P-1;i>0;i--)
    {
        int pi = perros[i].first, pj = perros[i].second; /// Por comodidad. pi es la posición i del perro, y pj la posición j.
        local[pi][pj] = labo[pi][pj]; /// "Sacamos al perro" de la baldosa;
        /// Realizamos lo mismo que hemos realizado anteriormente.
        if(local[pi][pj] == '.' || local[pi][pj] == 'E')
                for(int k = 0;k<4;k++)
                {
                    int y = pi + my[k];
                    int x = pj + mx[k];
       //             cout<<"Miro = "<<y<<" , "<<x<<endl;
                    if(Legal(y,x,local)) /// Vemos si nos movemos a un lugar legal
                        Unir(pi,pj,y,x,N,M); /// Unimos ambas celdas
                }
            if(local[pi][pj] == 'E')
            {
                int nod = pi*M + pj; /// numero de nodo de la entrada
                if(E == -1) /// Si no hay una entrada descubierta antes.
                    E = nod; /// Asigna E a este nodo.
                else
                    unir(E,nod); /// Lo une a las entradas ya encontradas.
            }
        if(E == -1)
            res[i-1] = 0;
        else
            res[i-1] = tam[findn(E)];
    //    cout<<"-----------"<<" => "<<E<<" = "<<findn(E)<<endl;
    //    for(int i = 0;i<N*M;i++)
    //        cout<<id[i]<<" ";
    //    cout<<endl;
    //    for(auto k : local)
    //        cout<<k<<endl;
    }
    return res;
}
