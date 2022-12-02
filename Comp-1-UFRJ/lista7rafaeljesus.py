def questao1(nomeArq,DRE):
    dados = open(nomeArq,'r')
    for linha in dados:
        pos = linha.split(',')
        if pos[1] == DRE:
            return linha
    dados.close()

print('Questao1')
print(questao1('alunos.txt','31585198'))
print(questao1('alunos.txt','62489933'))
print(questao1('alunos.txt','00000000'))
print(questao1('alunos2.txt','18584203'))

def questao2(nomeArq,codigo):
    listaDRE = []
    dados = open(nomeArq,'r')
    for linha in dados:
        info = linha.split(',')
        disciplinas = info[2:]
        pos = 0
        while pos<len(disciplinas):
            if codigo == disciplinas[pos]:
                if float(disciplinas[pos+1])>=5:
                    listaDRE.append(info[1])
                    pos = pos+1
                else:
                    pos = pos+1
            pos = pos+1
    dados.close()
    return listaDRE

print('Questao2')
print(questao2('alunos.txt','MAB114'))
print(questao2('alunos.txt','MAC118'))
print(questao2('alunos.txt','EEK200'))
print(questao2('alunos.txt','EEA212'))
print(questao2('alunos2.txt','MAB225'))
print(questao2('alunos3.txt','MAB225'))
print()

def questao3(nomeArq,novoArq,codigo):
    arq1 = open(nomeArq,'r')
    arqNovo = open(novoArq,'w')
    info = []
    for linha in arq1:
        dados = linha.split(',')
        if codigo in dados:
            arqNovo.write(linha)
            info = info+[linha[:-1]]
    return info
    arq1.close()
    arqNovo.close()

print('Questao3')
print(questao3('alunos.txt','resultMAB114.txt','MAB114'))
print(questao3('alunos.txt','resultEEK200.txt','EEK200'))
print(questao3('alunos3.txt','resultMAB225.txt','MAB225'))
print()


def questao4(nomeArq,DRE,dicionario):
    dados = open(nomeArq,'r')
    for linha in dados:
        lista = linha.split(',')
        if DRE in lista:
            disciplinas = lista[2:]
            pos = 0
            numerador = 0
            denominador = 0
            while pos < len(disciplinas):
                if disciplinas[pos] in dicionario:
                    numerador = numerador + float(disciplinas[pos+1])*dicionario[disciplinas[pos]]
                    denominador = denominador + dicionario[disciplinas[pos]]
                    pos = pos+2
                else:
                    pos = pos+2
    CRA = numerador/denominador
    return CRA
    dados.close()

print('Questao4')
print(questao4('alunos.txt', '31585198',{'MAB114': 6, 'MAC118': 6, 'FIT112': 2,
'EEH210': 2, 'EEK200': 2, 'MAB225': 6}))
print(questao4('alunos.txt', '62489933',{'MAB114': 6, 'MAC118': 6, 'FIT112': 2,
'EEH210': 2, 'EEK200': 2, 'MAB225': 6, 'EEK243':1, 'FIM240':5, 'MAB225':5,
'EEA212':3}))
print(questao4('alunos2.txt','62489933',{'MAB114': 6, 'MAC118': 6, 'FIT112': 2,
'EEH210': 2, 'EEK200': 2, 'MAB225': 6, 'EEK243':1, 'FIM240':5, 'MAB225':5,
'EEA212':3}))
print(questao4('alunos2.txt','97563341',{'MAB114': 6, 'MAC118': 6, 'FIT112': 2,
'EEH210': 2, 'EEK200': 2, 'MAB225': 6, 'EEK243':1, 'FIM240':5, 'MAB225':5,
'EEA212':3}))
print()


import numpy as np

def questao5():
    a = np.array([[5,1,-2,-1/2],[1,0,-2/5,-2/5],[1/2,-3/8,0,-3/8]])
    b = np.array([[2,-4,1,4],[1,-4,0,0],[2,0,5,0]])
    bT = b.transpose()

    soma = a+b
    subtracao = a-b
    multiplicacao1 = a*b
    multiplicacao2 = a.dot(bT)
    inverso = np.linalg.inv(multiplicacao2)

    return soma,subtracao,multiplicacao1,multiplicacao2,inverso

print('Questao5')
print(questao5())
print()


def questao6():
    A = np.array([[4,1,-1,5,-2],[1,0,3,10,4],[2,2,-1,0,1],\
            [-1,4,1,-1,-1],[-1,8,-1,-1,-2]])
    b = np.array([[4.5],[25.5],[9],[-4],[0]])
    
    r = np.linalg.inv(A).dot(b)

    return r

print('Questao6')
print(questao6())
