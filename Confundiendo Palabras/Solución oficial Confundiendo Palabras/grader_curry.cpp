#include <bits/stdc++.h>
#include "curry.cpp"
using namespace std;

int main()
{
	int N;
	cin>>N;
	vector<string> palabras(N);
	vector<int> significados(N);
	for(int i = 0;i<N;i++){
		cin>>palabras[i];
		cin>>significados[i];
	}
	cout<<curry(palabras,significados)<<endl;
} 
