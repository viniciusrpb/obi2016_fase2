/* 
   Universidade de Brasilia (UnB)
   Departamento de Ciencia da Computacao (CiC)
   
   Desenvolvedor: Prof. Dr. Vinícius R. P. Borges
   
   Complexidade da solucao: O(7^2)
*/

#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

// vertice associado ao angulo alpha "a"
ll cross(pll a, pll b, pll c)
{
    pll v1;
    pll v2;
    
    v1 = make_pair(b.x - a.x,b.y-a.y);
    v2 = make_pair(c.x - a.x,c.y-a.y);
    
    return (v1.x*v2.y)-(v2.x*v1.y);
}

ll dist(pll a, pll b)
{
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

int sign(ll a)
{
    if(a > 0)
        return 1;
    else
        if(a < 0)
            return -1;
        else
            return 0;
}

int main()
{
    int n,a,b;
    vector<pll> p;
    ll d[8][8];
    
    p.push_back(make_pair(0,0));
    
    for(int i = 1; i <= 7; i++)
    {
        scanf("%d %d",&a,&b);
        p.push_back(make_pair(a,b));
    }
    
    for(int i = 1; i <= 7; i++)
    {
        for(int j =1; j <= 7; j++)
        {
            d[i][j] = dist(p[i],p[j]);
        }
    }
    
    // condicao 1
    if(d[2][3] >= d[1][2] + d[1][3])
    {
        printf("N\n");
    }
    else
    {
        // condicao 2
        if(d[1][2] != d[1][3])
        {
            printf("N\n");
        }
        else
        {
            // condicao 3
            if(cross(p[2], p[3], p[4]) != 0 || cross(p[2],p[3],p[5]) != 0)
            {
                printf("N\n");
            }
            else
            {
                // condicao 4
                if( (p[2].x + p[3].x != p[4].x + p[5].x) || (p[2].y + p[3].y != p[4].y+p[5].y))
                {
                    printf("N\n");
                }
                else
                {
                    // condicao 5
                    if(d[2][3] <= d[4][5])
                    {
                        printf("N\n");
                    }
                    else
                    {
                        // condicao 6
                        if(d[2][6] != d[2][4] + d[4][6] || d[3][7] != d[3][5] + d[5][7])
                        {
                            printf("N\n");
                        }
                        else
                        {
                            // condicao 7
                            if(d[4][6] != d[5][7])
                            {
                                printf("N\n");
                            }
                            else
                            {
                                //condicao 8
                                if(sign(cross(p[2],p[3],p[1])) == sign(cross(p[2],p[3],p[6])))
                                {
                                    printf("N\n");
                                }
                                else
                                {
                                    printf("S\n");
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}