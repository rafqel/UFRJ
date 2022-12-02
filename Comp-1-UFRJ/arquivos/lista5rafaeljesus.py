def questao1(nomes,diretores,ano):
    tupla = []
    dados = ((nomes),(diretores),(ano))

    for pos in range(len(nomes)):
        tupla = tupla + [nomes[pos]]+[diretores[pos]]+[ano[pos]]

    return tuple(tupla)

print('Questao1')
print(questao1(('O Rei Leao',),('Rob Minkoff',),(1994,)))
print(questao1(('O Rei Leao','A Bela e a Fera',),('Rob Minkoff','Gary Trousdale'),(1994,1991)))
print(questao1(('O Rei Leao','A Bela e a Fera','Aladdin'),('Rob Minkoff,Roger Allers','Gary Trousdale,Kirk Wise','Ron Clements,John Musker'),(1994,1991,1992)))
print()

def questao2(pais,tupla):
    sameCountry = []
    for elemento in tupla:
        if elemento[1].lower() == pais.lower():
            sameCountry = sameCountry + [elemento[0]]
    return sameCountry

print('Questao2')
print(questao2('Espanha',(('Pedro','Espanha'),('Joao','Colombia'),\
        ('Fernanda','Portugal'),('Ana','Espanha'),('Luiz','Inglaterra'))))
print(questao2('ESPANHA',(('Pedro','Espanha'),('Joao','Colombia'),\
        ('Fernanda','Portugal'),('Ana','espanha'),('Luiz','Inglaterra'))))
print(questao2('Inglaterra',(('Pedro','Espanha'),('Fernanda','Portugal'),\
        ('Luiz','Inglaterra'))))
print(questao2('Portugal',(('Pedro','Espanha'),('Ana','Espanha'),\
        ('Luiz','Inglaterra'))))
print()

def questao3(string1,string2):
    posicao = []
    pos = 0
    while pos < len(string1):

        if string2 == string1[pos:pos+(len(string2))]: 
            posicao = posicao+[pos]
            pos = pos + len(string2)
        else:
            pos = pos+1

    return posicao

print('Questao3')
print(questao3('Fernanda Duarte Vilela',' '))
print(questao3('1,2,3,4,5,6,',','))
print(questao3('123123123123','12'))
print(questao3('123123123123','1234'))
print(questao3('5;;4;;;7;;;;8',';;'))
print(questao3('5;;4;;;7;;;;8',';;;'))
print()

def pedirNomesIdadeAltura():
    nome = input('Digite o nome do jogador: ')
    idade = input('Digite a idade do jogador: ')
    altura = input('Digite a altura do jogador: ')
    idade = int(idade)
    altura = float(altura)
    return (nome,idade,altura)

def idadeAltura(lista):
    quantidade = 0
    nome = ()
    for el1,el2,el3 in lista:
        if 16<=el2<=18 and el3>1.75:
            nome = nome + (el1,)
            quantidade = quantidade+1

    frase = f'Ha {quantidade} jogadores entre 16 e 18 anos com mais de 1.75 m: '
    
    for i in nome:
        if i == nome[0]:
            print(frase + i,end='; ')
        else:
            print(i,end='; ')
    print()
    return

def maisAlto(lista):
    altura = 0
    for el1,el2,el3 in lista:
        if el3 > altura:
            nome = el1
            altura = el3

    frase = f'O jogador mais alto eh o {nome}, e ele mede {altura:.3} m.'
    print(frase)
    return

def mostrarInfo(lista):
    resultado = ()
    for player in lista:
        resultado = resultado + (player,)
    print(resultado)
    print()
    return

def main4():
    players = []
    for i in range(8):
        player = pedirNomesIdadeAltura()
        players.append((player))
    idadeAltura(players)
    maisAlto(players)
    mostrarInfo(players)

main4()


def imprimirMenu():
    print('Digite uma das opcoes abaixo:')
    print('1 - Inserir os dados de um ou mais clientes.')
    print('2 - Mostrar a lista de clientes.')
    print('3 - Listar todos os clientes de uma especie determinada.')
    print('4 - Listar todos os animais de um cliente.')
    print('0 - Terminar.')

def pedirDados():
    cliente = input('Digite o nome do cliente: ')
    animal = input('Digite o nome do animal: ')
    especie = input('Digite a especie do animal: ')
    idade = input('Digite a idade do animal (anos): ')
    
    dados = ((cliente,animal,especie,idade),)
    return dados

def imprimirClientes(tupla):
    if tupla == ():
        print('Nao ha clientes cadastrados.')
    else:
        for el1,el2,el3,el4 in tupla:
            print('Dono:',el1,' ; Animal:',el2,' ; Especie:',el3,' ; Idade:',el4,sep='')
    print()

def listarClientesEspecie(tupla):
    especie = input('Digite a especie que deseja procurar: ')
    acertos = 0
    for el1,el2,el3,el4 in tupla:
        if especie.lower() == el3.lower():
            print('Dono:',el1,' ; Animal:',el2,' ; Idade:',el4,sep='')
            acertos = acertos+1
    if acertos == 0:
        print('Especie nao encontrada.')
    print()
    

def listarAnimaisCliente(tupla):
    cliente = input('Digite o nome do cliente: ')
    acertos = 0
    for el1,el2,el3,el4 in tupla:
        if cliente.lower() == el1.lower():
            print('Animal:',el2,' ; Especie:',el3,' ; Idade:',el4,sep='')
            acertos = acertos+1
    if acertos == 0:
        print('Cliente nao encontrado.')
    print()

def main5():
    dados = ()
    while True:
        imprimirMenu()
        r = input('Opcao: ')
        if r == '1':
            dados = dados + pedirDados()
            adicionar = input('Deseja inserir outro cliente? (s/n) ')
            print()
            while adicionar != 'n':
                if adicionar == 's':
                    dados = dados + pedirDados()
                    adicionar = input('Deseja inserir outro cliente? (s/n) ')
                    print()
        elif r == '2':
            imprimirClientes(dados)
        elif r == '3':
            listarClientesEspecie(dados)
        elif r == '4':
            listarAnimaisCliente(dados)
        elif r == '0':
            break
        else:
            print('Opcao invalida.')

main5()
