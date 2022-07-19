#include <iostream>
#include "definicoes.h"

using namespace std;

/*
 * n: quantidade de vertices
 * m: quantidade de arestas
 */
void LA_para_MI(vi* LA, int** MI, int n, int m){
    int e =0;
    for(int i=0;i<n;i++){
        int z;
        for(int j=0;j<LA[i].size();j++){
            z= LA[i].at(j);
            if(z>e){
              MI[e][z]=1; 
              e++;
            }
        }
    }
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
    vi* LA = new vi[n];
   
    // leitura do grafo
    int u, v;
    for(int i = 1; i <= m; i++){
      cin >> u >> v; // lendo as arestas do grafo

      // grafo nao-orientado
      
      // LA
      LA[u-1].push_back(v-1);
      LA[v-1].push_back(u-1);
    }
 
    int** MI = new int*[m];
    for(int i = 0; i < m; i++)
    {
        MI[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            MI[i][j] = 0;
        }
    }
  
    LA_para_MI(LA, MI, n, m);
  
    // impressao da MI
    for(int i = 0; i < m; i++)
    {
        cout << "e" << i + 1 << ": (";
        for(int j = 0; j < n; j++)
        {
          if(MI[i][j])
            cout<< " " << 1 << " "; 
          else 
            cout <<" 0 ";
        }
        cout << ")" << endl;
    }

     cin >> n >> m;    
  }
  
  return 0;
}
