def questao1(tempFah,temp='C'):
    tempCelsius = ((tempFah-32)*5)/9
    tempKelvin = ((tempFah-32)*5)/9+273
    
    if temp == 'C':
        return tempCelsius
    elif temp == 'K':
        return tempKelvin
    elif temp == temp.upper() and len(temp) == 1:
        return tempFah
    else:
        print('A string recebida deve ser uma letra maiuscula.')

print('Questao1')
print(questao1(77,'K'))
print(questao1(77,'C'))
print(questao1(77))
print(questao1(77,'X'))
print()

def questao2(l1,l2):
    medias = []
    for pos in range(len(l1)):
        try:
            medias = medias + [((l1[pos]+l2[pos])/2)]
        except IndexError:
            break
        except TypeError:
            return -1

    return medias

print('Questao2')
print(questao2([1,2,3],[3,4,5]))
print(questao2([1,2,3],[3,4]))
print(questao2([1,2],[3,4,5]))
print(questao2([1,2,3],[3,'4',5]))
print(questao2(['1',2,3],[3,4,5]))
print()

def main3():
    lista = []
    
    try:
        nome = input('Digite o nome do produto: ')
           
        while True:
            try:
                preco = input('Digite o preco do produto: ')
                preco = float(preco)
                if preco<1 or preco>99:
                    raise ValueError
                else:
                    break

            except ValueError:
                print('Valor invalido, digite um valor maior que 0 e menor que 100.')
                continue
            except KeyboardInterrupt:
                print()
                print('Encerrando o programa...')
                return -1
        
        while True:
            try:
                quant = input('Digite a quantidade: ')
                quant = int(quant)
                if quant<0 or quant>1000:
                    raise ValueError
                else:
                    break

            except ValueError:
                print('Valor invalido, digite um valor inteiro entre 0 e 1000.')
                continue
            except KeyboardInterrupt:
                print()
                print('Encerrando o programa...')
                return -1

        lista = lista + [nome]+[preco]+[quant]

    except KeyboardInterrupt:
        print()
        print('Encerrando o programa...')
        return -1
        
    return lista

print('Questao3')
if __name__ == '__main__':
    print(main3())
print()


def questao4(nomeArq):
    lista = []
    try:
        temp = open(nomeArq,'r')
        for linha in temp:
            try:
                linha = float(linha)
                lista = lista + [linha]
            except ValueError:
                print('A linha: %s nao pode ser convertida.'%(linha))
                continue
        temp.close()

    except FileNotFoundError:
        print('Arquivo nao encontrado.')
        return -1

    return lista

print('Questao4')
print(questao4('temp0.txt'))
print(questao4('temp.txt'))
print(questao4('temp2.txt'))
