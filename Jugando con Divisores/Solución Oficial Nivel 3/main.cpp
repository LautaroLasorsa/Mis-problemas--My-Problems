#include <bits/stdc++.h>
#include "divisores.cpp"
using namespace std;

int main()
{
    long long N , M;
    cin>>N>>M;
    vector<long long> result = Divisores(N,M);
    cout<<result[0]<<" "<<result[1]<<endl;
    return 0;
}
