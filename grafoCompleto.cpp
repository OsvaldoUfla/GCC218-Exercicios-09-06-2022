/*
solução com poucas alterações do execicío do grafo completo da 
aula de 09-06-2022
*/

#include<utility>
#include<vector>
#include<iostream>

using namespace std;

typedef pair<int, int> ii; // pares de inteiros
typedef vector<ii> vii; // vetor de pares de inteiros
typedef vector<int> vi; // vetor de inteiros

bool ehCompleto(int** MA, int n)
{
    bool completo = true;
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = i ; j<n ; j++)
        {
            if(i != j)
            {
                if(MA[i][j] != 1)
                {
                  completo = false;    
                }
            }
        }
    }
    // TO DO
    return completo;
}

int main()
{
    int n, m; // numero de vertices; numero de arestas do grafo

    
    cin >> n >> m;

    int** M = new int*[n]; // matriz de adjacencia
    
    
    
    //cria a matriz
    for(int i = 0; i < n; i++)
	{
		M[i] = new int[n];
	}

	for(int u = 0; u < n; u++)
	{
		for(int v = 0; v < n; v++)
		{
			M[u][v] = 0;
		}
	}

	// leitura do grafo
	int u, v;
	for(int i = 0; i < m; i++)
	{
		cin >> u >> v; // lendo as arestas do grafo
		M[u-1][v-1] = 1;
	}

	//Exibe a matriz de adjacência
	for(int u = 0; u < n; u++)
	{
		for(int v = 0; v < n; v++)
		{
			cout << M[u][v] << " ";
		}
		cout << endl;
	}
    
    cout << ehCompleto(M,n) <<endl;
 
    for(int u = 0; u < n; u++)
	{
        delete M[u];
	}
    delete[] M;
    return 0;
}
