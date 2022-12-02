def fatorial(n):
    f = 1
    while n>1:
        f = f*n
        n = n-1
    return f

def questao1a(n,k):
    arranjo = fatorial(n)/fatorial(n-k)
    return arranjo

def questao1b(n,k):
    arranjo = fatorial(n)/fatorial(n-k)
    combinacao = (1/fatorial(k))*questao1a(n,k)
    return combinacao

print('Questao1a')
print(questao1a(3,2))
print(questao1a(3,3))
print(questao1a(4,2))
print('Questao1b')
print(questao1b(3,2))
print(questao1b(3,3))
print(questao1b(4,2))

def questao2(x,m):
    n = 0
    resultado = 0
    while n<=m:
        resultado = resultado+((-1)**n*(x**(2*n+1)))/(2*n+1)
        n = n+1
    return resultado

print('Questao2')
print(questao2(0,2))
print(questao2(-0.99,2))
print(questao2(0.99,2))
print(questao2(0.99,25))
print(questao2((3**0.5)/3,25))

def Perfeitos(num):
    lista = []
    n = 1
    while n<num:
        if (num%n)==0:
            lista = lista+[n]
        n = n+1

    return lista

def questao3(num):
    soma = 0
    pos = 0
    lista = Perfeitos(num)
    while pos<len(lista):
        soma = soma+lista[pos]
        pos = pos+1
    if soma==num:
        return True
    else:
        return False

print ('Questao3')
print (questao3(2))
print (questao3(6))
print (questao3(9))
print (questao3(496))

def questao4(lista1,lista2):
    lista3 = []
    pos = 0
    while pos<len(lista1):
        if lista1[pos]>=lista2[pos]:
            lista3 = lista3+[lista1[pos]]
        else:
            lista3 = lista3+[lista2[pos]]
        pos = pos+1
    return lista3

print('Questao4')
print(questao4([],[]))
print(questao4([2],[1]))
print(questao4([1],[2]))
print(questao4([2],[2]))
print(questao4([2,4,-5,10],[2,-7,-1,10.1]))

def questao5(gabarito,respostas):
    acertos = 0
    erros = 0
    pos = 0
    while pos<len(gabarito):
        if gabarito[pos]==respostas[pos]:
            acertos = acertos+1
        pos = pos+1
    return acertos/len(gabarito)

print('Questao5')
print(questao5([1,2,3,4,5],[1,2,3,4,5]))
print(questao5([4,1,1,3,2,3,1,5],[3,1,1,5,2,3,2,4]))
print(questao5([4,1,1,3,2,3,1,5],[3,1,1,5,2,3,1,5]))
print(questao5([4,2,1,1,2,3,1,5,5,3],[4,2,1,1,2,3,5,5,4,3]))

def questao6(capacidade,sequencia):
    pos = 0
    soma = 0
    sinal = -1
    while pos<len(sequencia):
        soma = soma+sinal*sequencia[pos]
        if soma>capacidade:
            return True
        else:
            pos = pos+1
            sinal = -1*sinal
    if soma<=capacidade:
        return False

print ('Questao6')
print (questao6(10,[0,3,0,5,0,2,3,4,6,4]))
print (questao6(10,[0,5,2,7,3,3,5,2,7,0]))
print (questao6(4,[0,5,3,5,4,5,1,0,1,1,1,1]))
print (questao6(10,[0,4,3,3,1,4,3,1,5,4,0,1,0,2,1,4,5,2,1,5]))
print (questao6(6,[0,3,0,2,2,0,1,2,2,3,2,1,3,2,1,2,1,1,2,2]))

def questao7(players,obstacles):
    situacao = []
    pos1 = 0
    while pos1<len(players):
        pos2 = 0 
        colidiu = 0

        while pos2<len(obstacles):
            if players[pos1]==obstacles[pos2] and players[pos1+1]==obstacles[pos2+1]:
                colidiu = 1
                pos2 = pos2+2

            else:
                pos2 = pos2+2

        if colidiu==1:
            situacao.append(1)
        else:
            situacao.append(0)

        pos1 = pos1+2

    return situacao
print ('Questao7')
print (questao7([0,6,3,5],[10,2,0,6,3,4,9,5]))
print (questao7([0,6,3,5],[10,3,5,6,3,4,9,5]))
print (questao7([0,6,3,5,10,3,9,5],[10,3,5,6,3,4,9,5]))
print (questao7([1,1,0,7,9,5,3,5,10,3],[1,1,10,3,3,4,0,7]))
