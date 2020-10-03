/* 
   Universidade de Brasilia (UnB)
   Departamento de Ciencia da Computacao (CiC)
   
   Desenvolvedor: Prof. Dr. Vinícius R. P. Borges
   
   Complexidade da solucao: O(2^3)
*/

#include<bits/stdc++.h>

using namespace std;

int vetor[3];

/*i: pokemon em analise (2,1,0)*/
int solve(int doces, int i)
{
    /* criterio de parada: qdo nao tenho mais pokemon para analisar*/
    if(i < 0)
        return 0;
    
    int pega = 0;
    int naopega = solve(doces,i-1);
    
    if(doces - vetor[i] >= 0)
        pega = solve(doces-vetor[i],i-1)+1;

    return max(pega,naopega);
    
}

int main()
{
    int n;

    scanf("%d",&n);

    for(int i = 0; i < 3; i++)
    {
        scanf("%d",&vetor[i]);
    }

    printf("%d\n",solve(n,2));
    return 0;
}