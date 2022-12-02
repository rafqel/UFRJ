def questao1(x,y):
    '''Funcao que recebe por argumento x e y e retorna o valor arredondado
    da divisao de x por y.'''
    z = 10*(x/y-x//y)

    if z>=5:
        return x//y+1
    else:
        return x//y

print ('Questao1')
print (questao1(757,100))
print (questao1(57,10))
print (questao1(3,2))
print (questao1(4,3))

def questao2(x):
    '''Funcao que recebe x e retorna o y equivalente de um grafico.'''

    if x<-1:
        return -1
    elif x>1:
        return 1
    else:
        return x

print ('Questao2')
print (questao2(0.5))
print (questao2(-0.5))
print (questao2(1))
print (questao2(2))
print (questao2(-2))

def questao3(Ve,Vc,Vb):

    if (type(Ve)!=float and type(Ve)!=int)\
            or (type(Vc)!=float and type(Vc)!=int)\
            or (type(Vb)!=float and type(Vb)!=int):
        return -1
    if (Ve==Vc) or (Ve==Vb) or (Vc==Vb):
        return -2
    if (Ve>15 or Ve<-15) or (Vc>15 or Vc<-15) or (Vb>15 or Vb<-15):
        return -3

    if (Ve>Vb) and (Vb<Vc):
        return 0
    elif (Ve<Vb) and (Vb<Vc):
        return 1
    elif (Ve<Vb) and (Vb>Vc):
        return 2
    elif (Ve>Vb) and (Vb>Vc):
        return 3

print ('Questao3')
print (questao3(1j,1,2))
print (questao3(1,1,4))
print (questao3(-16,3,2))
print (questao3(1,3,26))
print (questao3(5,4,3))
print (questao3(2.3,5,3))
print (questao3(2.5,3,3.2))
print (questao3(4,2.5,3.2))

def questao4(valorcompra,tempo):
    
    if tempo == 1:
        taxa = 0
    elif tempo>=2 and tempo<5:
        taxa = 0.02
    elif tempo>=5 and tempo<9:
        taxa = 0.05
    elif tempo>=9 and tempo<14:
        taxa = 0.10
    elif tempo>=14 and tempo<20:
        taxa = 0.18
    elif tempo>=20 and tempo<30:
        taxa = 0.25
    else:
        taxa = 0.35
    
    total = valorcompra+valorcompra*taxa*tempo

    return total

print ('Questao4')
print (questao4(200.5,1))
print (questao4(200,2))
print (questao4(200,4))
print (questao4(200,6))
print (questao4(200,12))
print (questao4(200,15))
print (questao4(200,20))
print (questao4(200,30))

def questao5(minUmcurso,minDoiscursos,comp1fase1,comp1fase2,\
        comp2fase1,comp2fase2,comp3fase1,comp3fase2):
    
    pontoscomp1 = (comp1fase1+2*comp1fase2)/3
    pontoscomp2 = (comp2fase1+2*comp2fase2)/3
    pontoscomp3 = (comp3fase1+2*comp3fase2)/3
    
    if pontoscomp1<minUmcurso:
        doiscursoscomp1 = 0
        umcursocomp1 = 0
    elif pontoscomp1>=minUmcurso and pontoscomp1<minDoiscursos:
        doiscursoscomp1 = 0
        umcursocomp1 = 1
    if pontoscomp1>=minDoiscursos:
        doiscursoscomp1 = 1
        umcursocomp1 = 0

    if pontoscomp2<minUmcurso:
        doiscursoscomp2 = 0
        umcursocomp2 = 0
    elif pontoscomp2>=minUmcurso and pontoscomp2<minDoiscursos:
        doiscursoscomp2= 0
        umcursocomp2 = 1
    if pontoscomp2>=minDoiscursos:
        doiscursoscomp2 = 1
        umcursocomp2 = 0

    if pontoscomp3<minUmcurso:
        doiscursoscomp3 = 0
        umcursocomp3 = 0
    elif pontoscomp3>=minUmcurso and pontoscomp3<minDoiscursos:
        doiscursoscomp3 = 0
        umcursocomp3 = 1
    if pontoscomp3>=minDoiscursos: 
        doiscursoscomp3 = 1
        umcursocomp3 = 0
    
    quantUmcurso = umcursocomp1+umcursocomp2+umcursocomp3
    quantDoiscursos = doiscursoscomp1+doiscursoscomp2+doiscursoscomp3
    
    return quantUmcurso,quantDoiscursos

print ('Questao5')
print (questao5(8,9,9,9,8,8,6,6))
print (questao5(8.5,9,9,9.5,8,10,6,7))
print (questao5(7,10,9,9,8,6.7,7.5,7))
print (questao5(6,7,9,9,8,6.7,7.5,7))
print (questao5(10,7.15,9,9,8,6.7,7.5,7))

def questao6(A,B,C,D):

    if (A==B+C+D) and (B+C==D) and (B==C):
        return True
    else:
        return False

print ('Questao6')
print (questao6(12,3,3,6))
print (questao6(20,6,6,9))
print (questao6(60,15,15,30))
print (questao6(60,16,14,30))

def questao7(consumo):
    
    if consumo>=0 and consumo<=15:
        return 10,0,0
    elif consumo>15 and consumo<=40:
        valor = 10+(consumo-15)*1.2+0*3.0
        valorsec = (consumo-15)*1.2
        valorterc = 0
        return valor,valorsec,valorterc
    elif consumo>40:
        valor = 10+25*1.2+(consumo-40)*3.0
        valorsec = 30
        valorterc = (consumo-40)*3.0
        return valor,valorsec,valorterc

print ('Questao7')
print (questao7(12))
print (questao7(15))
print (questao7(20))
print (questao7(40))
print (questao7(45))
