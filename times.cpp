/* 
   Universidade de Brasilia (UnB)
   Departamento de Ciencia da Computacao (CiC)
   
   Desenvolvedor: Prof. Dr. Vinícius R. P. Borges
   
   Complexidade da solucao: O(n+m)
*/

#include<bits/stdc++.h>
#define N 100002
using namespace std;

typedef pair<int,int> pii;

vector<int> g[N];
vector<int> equipe(N,0);
int n;

void bfs(int start)
{

    queue<pii> q;
    vector<bool> visited(n+2,false);

    q.push(make_pair(start,0));
    visited[start]=true;

    while(!q.empty())
    {
        pii atual = q.front(); // ver o elemento da frente da fila
        q.pop(); // desenfileira

        int u = atual.first;   // aluno em analise
        int team = atual.second;   // equipe do aluno u
        equipe[u] = team;

        for(int v: g[u])
        {
            if(!visited[v])
            {
                q.push(make_pair(v,!team));
                visited[v] = true;
            }
        }
    }
}


int main()
{
    int m,aux;

    scanf("%d",&n);

    for(int i = 1; i <= n;i++)
    {
        scanf("%d",&m);
        for(int j = 1; j <= m; j++)
        {
            scanf("%d",&aux);
            g[i].push_back(aux);
        }
    }

    bfs(1);

    for(int i = 1; i <= n; i++)
    {
        if(!equipe[i])
            printf("%d ",i);
    }
    printf("\n");

    for(int i = 1; i <= n; i++)
    {
        if(equipe[i])
            printf("%d ",i);
    }
    printf("\n");

    return 0;
}