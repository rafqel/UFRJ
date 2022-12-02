import random as rnd

class personagem():
    def __init__(self,nome,x=0,y=0,experiencia=2,pokemons=[]):
        self.nome = nome
        self.x = x
        self.y = y
        self.experiencia = experiencia
        self.pokemons = pokemons
    def questao2(self,sentido):
        if sentido == 'cima':
            self.y += 1
        if sentido == 'baixo':
            self.y -= 1
        if sentido == 'direita':
            self.x += 1
        if sentido == 'esquerda':
            self.x -= 1
        return self.x,self.y
    def questao3(self):
        n = rnd.randint(0,5)
        exp = n + self.experiencia
        if exp > 100:
            return 100
        else:
            self.experiencia += n
            return self.experiencia
    def questao4(self,nomePokemon,defesa):
        forca = rnd.randint(-1,3)
        total = self.experiencia + forca
        if total > defesa:
            self.pokemons += [nomePokemon]
            return 1
        else:
            return 0
    def questao5(self,nomePokemon,defesa,x,y):
        posx = self.x - x
        posy = self.y - y
        if posx >= -1 and posx <= 1 and posy >= -1 and posy <= 1:
            self.questao4(nomePokemon,defesa)
        return posx,posy

print('--- Questao 1 ---')
meuPersonagem = personagem('Fernanda')
print('Atributos definidos no construtor: ')
print('Nome: ',meuPersonagem.nome)
print('Posicao x: ',meuPersonagem.x)
print('Posicao y:',meuPersonagem.y)
print('Experiencia: ',meuPersonagem.experiencia)
print('Lista de Pokemons: ',meuPersonagem.pokemons)

print('--- Questao 2 ---')
print('Andando para cima: ')
print(meuPersonagem.questao2('cima'))
print('Posicao: ',meuPersonagem.x,meuPersonagem.y)
print('Andando para a direita: ')
print(meuPersonagem.questao2('direita'))
print('Posicao: ',meuPersonagem.x,meuPersonagem.y)

print('--- Questao 3 ---')
print('Adquirindo experiencia: ')
print(meuPersonagem.questao3())
print('Experiencia: ',meuPersonagem.experiencia)
print('Adquirindo experiencia: ')
print(meuPersonagem.questao3())
print('Experiencia: ',meuPersonagem.experiencia)

print('--- Questao 4 ---')
print('Tentando capturar um Charmander: ')
print(meuPersonagem.questao4('Charmander',4))
print('Lista de Pokemons: ',meuPersonagem.pokemons)
print('Tentando capturar um Venusaur: ')
print(meuPersonagem.questao4('Venusaur',20))
print('Lista de Pokemons: ',meuPersonagem.pokemons)

print('--- Questao 5 ---')
print('Tentando capturar um Bulbasar: ')
print(meuPersonagem.questao5('Bulbasar',4,2,4))
print('Lista de Pokemons: ',meuPersonagem.pokemons)
print('Tentando capturar um Squirtle: ')
print(meuPersonagem.questao5('Squirtle',4,1,0))
print('Lista de Pokemons: ',meuPersonagem.pokemons)


class personagem2(personagem):
    def questao7(self,nomePokemon):
        quant = 0
        for nomes in self.pokemons:
            if nomes == nomePokemon:
                quant += 1
        return quant
    def questao4(self,nomePokemon,defesa):
        forca = rnd.randint(1,self.experiencia)
        defesa = rnd.randint(1,defesa)
        if forca > defesa:
            self.pokemons += [nomePokemon]
            return 1
        else:
            return 0

print('--- Questao 6 ---')
meuNovoPersonagem = personagem2('Felipe')
print('Atributos definidos no construtor: ')
print('Nome: ',meuNovoPersonagem.nome)
print('Posicao x:',meuNovoPersonagem.x)
print('Posicao y:',meuNovoPersonagem.y)
print('Experiencia: ',meuNovoPersonagem.experiencia)
print('Lista de Pokemons: ',meuNovoPersonagem.pokemons)

print('--- Questoes 7 e 8 ---')
print('Quantidade de Charmanders na lista: ')
print(meuNovoPersonagem.questao7('Charmander'))
print('Tentando capturar uma Caterpillar: ')
print(meuNovoPersonagem.questao4('Caterpillar',1))
print('Lista de Pokemons: ',meuNovoPersonagem.pokemons)
print('Tentando capturar uma outra Caterpillar: ')
print(meuNovoPersonagem.questao5('Caterpillar',1,0,0))
print('Lista de Pokemons: ',meuNovoPersonagem.pokemons)
print('Tentando capturar um Pigeon: ')
print(meuNovoPersonagem.questao4('Pigeon',2))
print('Lista de Pokemons: ',meuNovoPersonagem.pokemons)
print('Quantidade de Caterpillars na lista: ')
print(meuNovoPersonagem.questao7('Caterpillar'))
print('Quantidade de Pigeons na lista: ')
print(meuNovoPersonagem.questao7('Pigeon'))
