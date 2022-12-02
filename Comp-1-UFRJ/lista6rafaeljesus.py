def questao1(CEP):
    info = {22030010:'Rua Assis Brasil',22021000:'Avenida Atlantica',\
            22021001:'Avenida Atlantica',22020020:'Rua Duvivier',\
            22061020:'Rua Bolivar',22020010:'Rua Belfort Roxo',\
            22011002:'Rua Barata Ribeiro',22041012:'Rua Barata Ribeiro'}
    if CEP in info:
        endereco = info[CEP]
        return endereco
    else:
        return ' ' 

print('Questao1')
print(questao1(22030010))
print(questao1(22011002))
print(questao1(22041012))
print(questao1(22041015))
print(questao1(2))


def questao2(partidas,time):
    vitorias = []
    for chave in partidas:
        vencedor = partidas[chave]
        if vencedor == time:
            vitorias.append(chave)
    return vitorias

print('Questao2')
print(questao2({'Warriors X Nuggets':'Warriors','Nets X Suns':'Nets',\
        'Nets X Celtics':'Nets','Knicks X Raptors':'Knicks',\
        'Pelicans X Spurs':'Spurs','Heat X Bulls':'Heat',\
        'Warriors X Wizards':'Wizards','Pelicans X Nets':'Nets',\
        'Celtics X Bulls':'Bulls','76ers X Warriors':'Warriors'},'Spurs'))
print(questao2({'Warriors X Nuggets':'Warriors','Nets X Suns':'Nets',\
        'Nets X Celtics':'Nets','Knicks X Raptors':'Knicks',\
        'Warriors X Wizards':'Wizards','Pelicans X Nets':'Nets',\
        'Celtics X Bulls':'Bulls','76ers X Warriors':'Warriors'},'Warriors'))
print(questao2({'Nets X Suns':'Nets','Nets X Celtics':'Nets',\
        'Knicks X Raptors':'Knicks','Pelicans X Spurs':'Spurs',\
        'Heat X Bulls':'Heat', 'Warriors X Wizards':'Wizards',\
        'Pelicans X Nets':'Nets', 'Celtics X Bulls':'Bulls',\
        '76ers X Warriors':'Warriors'},'Nets'))


import random

def questao3(quantQuestoes,lista):
    dicionario = {}
    for questao in range(1,quantQuestoes+1):
        dicionario[questao] = random.choice(lista)
    return dicionario

print('Questao3')
print(questao3(5,['a','b','c','d']))
print(questao3(10,['a','b','c','d','e']))
print(questao3(15,['a','b','c']))


def questao4(produtos,precos):
    dicionario = {}
    for i in range(len(produtos)):
        nome = produtos[i]
        valor = precos[i]
        if nome in dicionario:
            if valor>dicionario[nome]:
                dicionario[nome] = valor
        else: 
            dicionario[nome] = valor

    return dicionario

print('Questao4')
print(questao4(['lapis','borracha','caneta'],[1.2,1.5,2.4]))
print(questao4(['lapis','borracha','caneta','lapis','caneta','lapis'],\
        [1.2,1.5,2.4,1.1,2.0,1.8]))
print(questao4(['borracha','borracha','caneta','caneta','lapis'],[2,3,3,2,1]))


def questao5(prodPreco,minhaLista):

    if set(minhaLista.keys())-set(prodPreco.keys()) != set():
        return -1
    
    soma = 0
    for produto in minhaLista:
        preco = prodPreco[produto]
        quantidade = minhaLista[produto]
        soma = soma + preco*quantidade
    
    return soma

'''set(nomeDicionarioPrecos.keys())-\
        set(nomeDicionarioProdutosDesejados.keys()) nao e possivel,
        pois estaria-se desconsiderando um produto desejado que nao
        tem no mercado. Suponhamos que eu queira comprar o produto x e y
        no mercado, mas la so tem o produto x. Se subtrairmos o set do
        que tem no mercado pelo set do que eu quero, daria um set vazio
        e desconsideraria o meu produto y. Ja se fizermos a subtracao
        do set ao contrario, temos a consciencia de que ha um produto
        faltando.'''
    
print('Questao5')
print(questao5({'lapis':1.8,'borracha':1.5,'caneta':2.4},{'borracha':1,\
        'lapis':2,'caneta':5}))
print(questao5({'lapis':1.8,'borracha':1.5,'caneta':2.4},{'lapis':2,\
        'borracha':1}))
print(questao5({'lapis':1.8,'borracha':1.5,'caneta':2.4},{'lapis':2,\
        'apontador':3,'borracha':1,'caneta':5}))


def questao6(respostas1,respostas2):
    comum = respostas1&respostas2
    nComum = len(comum)
    
    distinto = (respostas1-respostas2)|(respostas2-respostas1)
    nDistinto = len(distinto)
    
    total = respostas1|respostas2
    nTotal = len(total)
    
    afinidade = nComum/nTotal
    estranhamento = nDistinto/nTotal

    return afinidade,estranhamento,comum,distinto

print('Questao6')
print(questao6({'basquete','matematica','comida japonesa'},{'futebol',\
        'historia','comida japonesa'}))
print(questao6({'basquete','matematica','comida italiana','pintura'},\
        {'futebol','historia','comida italiana','croche','leitura'}))
print(questao6({'basquete','matematica','comida italiana','pintura'},{'basquete','futebol','matematica','comida italiana','pintura'}))
print(questao6({'basquete','matematica','comida italiana','pintura'}\
        ,{'basquete','historia','comida italiana','pintura'}))
print(questao6({'basquete','matematica','comida italiana','pintura'},\
        {'basquete','matematica','comida italiana','pintura'}))


