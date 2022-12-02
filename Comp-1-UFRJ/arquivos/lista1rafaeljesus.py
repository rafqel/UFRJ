def questao1 (x1,p1,x2,p2):
    '''Funcao que recebe quatro valores por argumento (x1,x2,p1,p2)
    e retorna a media aritmetica ponderada desses valores sabendo
    que p1 e o peso de x1, e que p2 e o peso de x2.'''
    MediaAritmeticaPonderada = (x1*p1+x2*p2)/(p1+p2)
    return MediaAritmeticaPonderada

print (questao1(10,1,8,1))
print (questao1(10,1,8,3))
print (questao1(7.5,1.5,9.1,3.5))

def questao2(x):
    '''Funcao que recebe um valor de x por argumento e retorna y.'''
    y = x**(5/3)+(x**2-8*x)/10-4*(5*x**4+9*x**3-10*x**2)
    return y

print (questao2(0))
print (questao2(1))
print (questao2(10.2))

def questao3(valorconsumido,gorjeta):
    '''Funcao que recebe, por argumento, o valor consumido e a
    porcentagem da gorjeta que será paga ao garcom, e retorna o
    o valor total a ser pago.'''
    total = valorconsumido+valorconsumido*gorjeta/100
    return total

print (questao3(20,10))
print (questao3(20,20))
print (questao3(30.55,10))

def questao4(x):
    '''Funcao que recebe, por argumento, um valor em horas e
    retorna em dias.'''
    dias = (1*x)/24
    return dias

print (questao4(12))
print (questao4(24))
print (questao4(30))

def questao5(S0,S,V0,V):
    '''Funcao que recebe, por argumento, respectivamente, os valores
    da posicao inicial, posicao final, velocidade inicial e velocidade
    final retornando o valor da aceleracao.'''
    deltaS = S-S0
    aceleracao = (V**2-V0**2)/(2*deltaS)
    return aceleracao

print (questao5(0,1,4,8))
print (questao5(1,5,2,10))
print (questao5(1,5,10,2))

def questao6(diagonal,lado):
    '''Funcao que recebe, por argumento, a diagonal e lado de um retangulo
    e recebe a sua area.'''
    base = (diagonal**2-lado**2)**(1/2)
    areaRetangulo = lado*base
    return areaRetangulo

print (questao6(10,6))
print (questao6(5,3))
print (questao6(4,2))

def questao7(Vmax,Vmin,nbits):
    '''Funcao que recebe por argumento, respectivamente, um valor maximo
    de tensao, um valor minimo da faixa de tensao e o numero de bits,
    retornando assim o valor do passo.'''
    valormaximo = 2**nbits-1
    passo = (Vmax-Vmin)/valormaximo
    return passo

print (questao7(5,0,1))
print (questao7(5,1,1))
print (questao7(4.5,1.5,2))
print (questao7(4,2,4))

def questao8(x):
    '''Funcao que recebe por argumento o angulo x e retorna o valor
    de sua tangente'''
    senx = x-x**3/(3*2*1)+x**5/(5*4*3*2*1)-x**7/(7*6*5*4*3*2*1)
    cosx = 1-x**2/(2*1)+x**4/(4*3*2*1)-x**6/(6*5*4*3*2*1)
    tangentex = senx/cosx
    return tangentex

print (questao8(3.1415))
print (questao8(3.1415/3))
print (questao8(3.1415/4))
