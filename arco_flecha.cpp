#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll temp[100002];

ll merge(ll v[], int inicio, int meio, int fim)
{
    int i, j, k;
    ll swaps;
 
    i = inicio; 
    j = meio;
    k = inicio;
    
    swaps = 0;
    
    while ((i <= meio - 1) && (j <= fim))
    {
        if (v[i] > v[j])
            temp[k++] = v[i++];
        else
        {
            temp[k++] = v[j++];
            swaps = swaps + (meio-i);
        }
    }
 
    while (i <= meio - 1)
        temp[k++] = v[i++];
 
    while (j <= fim)
        temp[k++] = v[j++];
 
    for (i = inicio; i <= fim; i++)
        v[i] = temp[i];
    
    return swaps;
 
}

ll mergeSort(ll v[], int inicio, int fim)
{
    int meio;
    ll swaps=0;
    if (inicio < fim)
    {
        meio = (inicio+fim) / 2;
 
        swaps = mergeSort(v, inicio, meio);
        swaps = swaps + mergeSort(v, meio + 1, fim);
 
        swaps = swaps + merge(v, inicio, meio + 1, fim);
    }
    return swaps;
}

int main()
{
    int N;
    ll x,y;
    ll v[100002];
    
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        scanf("%lld %lld",&x,&y);
        ll d = x*x + y*y;
        v[i] = d;
    }
        
    ll ans = mergeSort(v,0,N-1);
        
    printf("%lld\n",ans);
    
    return 0;
}
