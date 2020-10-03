/* 
   Universidade de Brasilia (UnB)
   Departamento de Ciencia da Computacao (CiC)
   
   Desenvolvedor: Prof. Dr. Vinícius R. P. Borges
   
   Complexidade da solucao: O(n + m + logn)
*/

#include<bits/stdc++.h>
#define N 100002

using namespace std;

vector<int> graph[N];
vector<int> tab[N];

int dp(int u, int ind_v)
{
    if(ind_v == graph[u].size())
        return 0;
        
    if(tab[u][ind_v])
        return tab[u][ind_v];
    
    //procura pelos vizinhos de v que sao maiores do que u
    int v = graph[u][ind_v];
    int vizinho = upper_bound(graph[v].begin(), graph[v].end(), u)-graph[v].begin();
   
    int pega = dp(v, vizinho)+1;
    int naopega = dp(u, ind_v+1);
        
    tab[u][ind_v] = max(pega,naopega);
    
    return max(pega,naopega);
}

int main()
{
    int a,b,n,m;

    scanf("%d %d",&n,&m);

    for(int i = 0; i < m; i++)
    {
        scanf("%d %d",&a,&b);
        graph[a].push_back(b);
        tab[a].push_back(0);
        graph[b].push_back(a);
        tab[b].push_back(0);
    }
    
    for(int i = 1; i <= n; i++)
    {
        sort(graph[i].begin(),graph[i].end());
    }
    
    for(int i = 1; i < n; i++)
    {
        printf("%d ",dp(i,0)+1);
    }
    printf("%d\n",dp(n,0)+1);
  
    return 0;
}