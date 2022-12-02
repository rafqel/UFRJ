def questao1(n):
    if n==0:
        return 0
    elif n==1:
        return 1
    else:
        return 3*questao1(n-1)-2*questao1(n-2)

print('Questao1')
print(questao1(1))
print(questao1(2))
print(questao1(3))
print(questao1(4))
print(questao1(5))
print()

def questao2(x,y):
    if x==0 or y==0:
        return 0
    elif x==1:
        return y
    elif y==1:
        return x
    else:
        return x+questao2(x,y-1)

print('Questao2')
print(questao2(0,2))
print(questao2(2,0))
print(questao2(2,2))
print(questao2(4,2))
print(questao2(2,4))
print()

def questao3(lista):
    if lista==[]:
        return 0
    else:
        return 1+questao3(lista[:-1])

print('Questao3')
print(questao3([]))
print(questao3([10,3]))
print(questao3([10,4,3]))
print()

def questao4(binario):

    if len(binario) == 1:
        binario = int(binario)
        return binario*2**0

    else:
        i = len(binario)-1 
        num = int(binario[0])
        return num*2**i+questao4(binario[1:])

print('Questao4')
print(questao4('0'))
print(questao4('11'))
print(questao4('1011'))
print(questao4('1110'))
print(questao4('10000'))
print()

def questao5(lista,num):

    if len(lista) == 0:
        return False
    
    elif num == lista[0]:
        return True

    else:
        return questao5(lista[1:],num)

print('Questao5')
print(questao5([1,2],0))
print(questao5([1,2],1))
print(questao5([1,2],2))
print(questao5([1,2],3))
print(questao5([1,2,3],1))
print(questao5([1,2,3],2))
print(questao5([1,2,3],3))
print(questao5([1,1,2,3],1.0))
print(questao5([1,1,2,3],1.5))
print()

def questao6(lista):

    for indice in range(1,len(lista)):
        num = lista[indice]
        pos = indice

        while pos > 0 and lista[pos-1] > num:
            lista[pos] = lista[pos-1]
            pos = pos-1

        lista[pos] = num
    
    return lista

print('Questao6')
print(questao6([1]))
print(questao6([4,5,1,2]))
print(questao6([5,4,3,2,1]))
print(questao6([5,1,3,2,4,1]))
