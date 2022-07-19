#include <iostream>
#include "definicoes.h"

using namespace std;

// n: quantidade de vertices
void MA_para_LA(int** MA, vi* LA, int n)
{
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(MA[i][j]){
                LA[i].push_back (j);
            }
        }
    }
    // TO DO
}

int main()
{  
  int n, m;
  cin >> n >> m;
 
  while(!cin.eof())
  {
    /* se o seu teste inicial considerar G =(V,E) como uma MA, deixe o codigo
     * abaixo descomentado e comente a declaracao das outras estruturas.
     */
    int** MA = new int*[n];
    for(int i = 0; i < n; i++)
    {
        MA[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            MA[i][j] = 0;
        }
    }
   
    // leitura do grafo
    int u, v;
    for(int i = 1; i <= m; i++)
    {
      cin >> u >> v; // lendo as arestas do grafo

      // grafo nao-orientado
      
      // MA
      MA[u-1][v-1] = MA[v-1][u-1] = 1;
    }    
 
    vi* LA = new vi[n];
  
    MA_para_LA(MA, LA, n);
  
    // impressao da LA
    for(int i = 0; i < n; i++)
    {
        cout << i + 1 << ": ";
        for(vi::iterator it = LA[i].begin(); it != LA[i].end(); ++it)
          cout << (*it) + 1 << " ";
        cout << endl;
    }

    cin >> n >> m;
  }

  return 0;
}
