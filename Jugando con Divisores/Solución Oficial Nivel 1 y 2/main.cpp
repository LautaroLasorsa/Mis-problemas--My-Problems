#include <bits/stdc++.h>
#include "divisores.cpp"
using namespace std;

int main()
{
    long long N;
    cin>>N;
    vector<long long> result = Divisores(N);
    cout<<result[0]<<" "<<result[1]<<endl;
    return 0;
}
