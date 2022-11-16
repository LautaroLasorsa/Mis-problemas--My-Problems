#include <bits/stdc++.h>
#include "toriis.h"

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector <int> ini(m), fin(m), cant(m);

    for(int i=0; i<m; i++)
        scanf("%d", &ini[i]);

    for(int i=0; i<m; i++)
        scanf("%d", &fin[i]);

    for(int i=0; i<m; i++)
        scanf("%d", &cant[i]);

    int res = Cantidad_Caminos(n, m, ini, fin, cant);

    printf("%d\n", res);


    return 0;
}
