#   Universidade de Brasilia (UnB)
#   Departamento de Ciencia da Computacao (CiC)
#   
#   Desenvolvedor: Prof. Dr. Vinícius R. P. Borges
#   Complexidade da solucao: O(2^3)


def solve(pokemons,doces,i):
    if i < 0:
        return 0
    
    pega = 0
    naopega = solve(pokemons,doces,i-1)
    
    if doces - pokemons[i] >= 0:
        pega = solve(pokemons,doces-pokemons[i],i-1)+1
    
    return max(pega,naopega)

n = int(input())

vetor = []

for i in range(0,3):
    a = int(input())
    vetor.append(a)

print(solve(vetor,n,2))