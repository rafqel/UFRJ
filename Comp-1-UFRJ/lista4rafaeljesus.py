def questao1(lista):
    quantidade = 0
    for elemento in lista:
        if (type(elemento)==float) or (type(elemento)==int):
            quantidade = quantidade + 1
    return quantidade

print('Questao1')
print(questao1([0,1,0.3,8]))
print(questao1([0,1,0.3,1j,[1,2,3],8]))
print(questao1([True,1,4,5.9,False]))

def questao2(n,lista):
    for pos in lista:
        if n == pos:
            return True
    else:
        return False

print('Questao2')
print(questao2(1,[1,2,3]))
print(questao2(1,[2,1,3,4]))
print(questao2(1,[2,0,3,4,1]))
print(questao2(1,[2,0,1,4,1]))
print(questao2(1,[2,5,3,4,0,9]))

def questao3(lista):
    resultado = [0]*20

    for pos in lista:
        resultado[pos]+=1

    return resultado

print('Questao3')
print(questao3([6,1,0,1,18]))
print(questao3([0,1,1,2,2,2,3,3,3,3,4,4,4,4,4]))
print(questao3([19,10,6,3,7,0,15,6,6,19]))
print(questao3([15,14,6,14,10,1,7,3,14,9,18,6,0,11,1,4,8,13,11,17]))

def questao4(n,lista):
    lista2 = []
    for pos in lista:
        if pos != n:
            lista2.append(pos)
    return lista2

print('Questao4')
print(questao4(1,[0,1,2,3]))
print(questao4(1,[1,3,4,5]))
print(questao4(1,[0,2,3,1,4]))
print(questao4(1,[1,1,1,1,1]))

def questao5(n):
    numerador = 1
    resultado = 0
    for div in range(2,2*n+1,2):
        if n == 0:
            return 0
            break
        else:
            resultado = resultado + numerador/div
    return resultado

print('Questao5')
print(questao5(0))
print(questao5(1))
print(questao5(2))
print(questao5(4))

def questao6(latas,copos):
    soma = 0
    pos = 0
    for elemento in latas:
        if elemento>copos[pos]:
            soma = soma+copos[pos]
            pos = pos+1
        else:
            pos = pos+1
            continue
    return soma

print('Questao6')
print(questao6([10,80,100,90,50],[8,2,9,1,40]))
print(questao6([2,6,8,10,20,40],[1,1,1,1,1,1]))
print(questao6([3,5,8],[0,0,0]))
print(questao6([3,8,10,12,15],[8,10,15,20,20]))
print(questao6([3,8,10,12],[3,8,10,12]))
print(questao6([100,95,92,44,52,62,40],[70,100,41,69,89,34,10]))

def questao7(lista):
    novaLista = []
    
    if len(lista)==0:
        return lista

    for elemento in lista:
        novaLista = novaLista + [elemento[0]/elemento[1]]

    barato = 0
    for pos in range(len(novaLista)):
        if novaLista[pos] < novaLista[barato]:
            barato = pos 
    return lista[barato]
    
print('Questao7')
print(questao7([]))
print(questao7([[12,0.01]]))
print(questao7([[10.5,800],[5,300.8],[2,150],[1,60]]))
print(questao7([[12,80],[4,300],[3.5,150]]))
print(questao7([[10,800],[5,300],[2,150],[1,60],[20,1800]]))

def questao8(lista):
    vm = 0
    for elemento in lista:
        vm = vm + elemento[0]*elemento[1]
    return vm

print('Questao8')
print(questao8([[12,19],[41,73],[61,7]]))
print(questao8([[10,0],[55,12],[75,120]]))
print(questao8([[37,24],[68,69],[28,26],[79,8],[36,0],[50,71],[13,68],[87,113]]))
print(questao8([[45,46],[46,101],[7,2],[95,104],[12,107],[78,29],[10,26],[52,86],[13,79],[1,107]]))



