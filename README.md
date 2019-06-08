| [Equipe] | [Descrição] | [Instruções] | [Sobre o Jogo] | [Como Jogar] | [Documentação de Código] |
|------------|--------------|------------|------------|------------|------------|
- - -

# TB - PDS 2 - G5

## Equipe

* Caio Guedes de Azevedo Mota
* Gabriel Victor Carvalho Rocha
* Guilherme Bezerra dos Santos
* Lucas Mariani Paiva Caldeira Brant

## Descrição

Nesse projeto, nossa equipe desenvolveu um sistema simples de batalha de RPG utilizando C++ orientado a objetos.

## Instruções

O programa deve ser executado em uma plataforma Linux, utilizando o comando "make run" no terminal.

## Sobre o Jogo

Fireshadow é um jogo de RPG de texto baseado na linha de comando (terminal).  O jogo consiste em várias aventuras, que podem ser trilhadas por diferentes personagens e seus parceiros, e que contém várias batalhas contra os mais diversos inimigos.

O funcionamento do jogo é similar à batalhas de jogos de RPG de mesa famosos, como Dungeons & Dragons. Os jogadores enfrentam inimigos numa batalha em turnos, onde cada um ataca em uma vez. 

No turno do jogador, ele escolhe qual inimigo vai atacar, e rola um dado para determinar se seu ataque foi um sucesso, e quanto irá danificar o inimigo. No turno do inimigo, ele ataca um jogador aleatório, e rola um dado da mesma forma.

O jogo tem 4 aventuras, e o jogador pode escolher qual vai jogar, e com qual dos personagens irá fazê-lo.

## Como Jogar

Primeiramente, execute as instruções de execução do início deste arquivo.

Ao executar o jogo, irá se abrir o menu principal.

Há duas opções:
1. Iniciar o Jogo
2. Sair do Jogo

Iniciando o jogo, abre-se o menu de personagens. Nele, se pode escolher um dos personagens apresentados no menu para trilhar a aventura.

Após selecionar o personagem, se pode escolher a aventura que você deseja trilhar durante o jogo.

Uma história irá se iniciar, e é avançada pressionando a tecla Enter.

Durante as aventuras, irão acontecer batalhas. Essas batalhas acontecem em turnos, e o jogador escolhe qual inimigo irá atacar.

Ao escolher o ataque, são mostradas as informações da batalha para o jogador, e o resultado do ataque. O mesmo acontece para o ataque dos inimigos.

O objetivo é vencer todas as batalhas da aventura sem morrer, e derrotar todos os inimigos em sua jornada. Caso contrário, será fim de jogo.

## Documentação de Código

### main e funções.cpp
A parte inicial do jogo (menus) funciona com estruturas de repetição while, que esperam um parâmetro entre os que são apresentados no menu. Caso a entrada não seja um dos números apresentados, a repetição detecta isso e pede uma entrada válida.

### banco.cpp
O arquivo banco.cpp instância objetos globais que serão utilizados ao longo do jogo, como armas, jogadores e inimigos. Funciona como um “banco de dados” para o restante do programa. Declara as variáveis num arquivo banco.h com “extern”.


### aventuras.cpp
O arquivo aventuras.cpp gerencia as aventuras do jogo. Uma explicação breve de alguns métodos relevantes:

##### adicionar_jogador/remover_jogador; adicionar_inimigo/remover_inimigo:
Adicionam e remover jogadores/inimigos na aventura, usando push_back nos vetores.
    
##### batalha:
Gere o sistema principal de batalha, explicado a seguir:
```
        ⇒ Primeiro chama status para exibir as informações de todos os participantes da batalha.
        ⇒ Há uma estrutura de repetição que continua indefinidamente até a função retornar um valor true ou false, representando o fim da batalha
        ⇒ Depois uma estrutura de repetição aninhada que gerencia o ataque de todos os jogadores na batalha, que escolhem um inimigo para atacar 
        ⇒ Após a escolha dos jogadores, a função executa o ataque. Caso todos os inimigos estejam mortos após o ataque, a função retorna true.
        ⇒ Outra estrutura de repetição aninhada, análoga para o ataque dos inimigos, mas que ataca um jogador aleatório. Caso o jogador principal esteja morto, a batalha retorna false, pois foi derrotado.
```

##### party_descanso:
Percorre o vetor de jogadores da aventura e chama uma função para recuperar a HP de cada membro. Usada após uma batalha.

##### aventura_i (para i = 1,2,3 ou 4):
Função que contém cada uma das aventuras. Todas as 4 seguem o mesmo modelo, explicado a seguir:
```
        ⇒ É escrita uma história, até a primeira batalha.
        ⇒ A batalha acontece em determinado momento, adicionando inimigos ao vetor de inimigos.
        ⇒ O condicional checa se a batalha retorna false (isto é, o jogador perdeu a batalha). Caso tenha perdido, um goto leva a execução ao fim da aventura, pois o jogo foi perdido e a aventura acabou.
        ⇒ Caso contrário, a história continua e os jogadores vivos descansam com o party_descanso. Caso todas as batalhas foram vencidas, o jogador ganhou o jogo e a aventura termina.
```

### dado.cpp
O arquivo dado.cpp cria uma classe dado que usa funções para gerar números pseudo-aleatórios para simular uma rolagem de dado.

### entidade.cpp, jogador.cpp e inimigo.cpp
O arquivo entidade.cpp cria uma classe geral Entidade, que contém atributos como:
        ⇒ vida
        ⇒ classe de armadura (atributo que controla a defesa em um ataque)
        ⇒ arma que usa para atacar

Os arquivos jogador.cpp e inimigo.cpp criam classes específicas Jogador/Inimigo que herdam Entidade, e implementam algumas especificações. 

##### Para Jogador:
        ⇒ atributo classe (guerreiro, ladino, mago, etc.)
        ⇒ atributo max_HP (vida máxima, utilizado para o descanso)
        ⇒ método recuperar_vida
##### Para Inimigo:
        ⇒ raça (Goblin, Orc, Troll, etc.)
        ⇒ um método set_nome específico que retorna o seu nome + sua raça.
##### Para ambos:
        ⇒ método atacar, que ataca um jogador ou um inimigo. O método funciona dessa forma:
                1) Cria um dado, que é rolado.
                2) Caso a rolagem seja bem sucedida, o ataque é executado. Caso contrário, ele falha e nada acontece.
                3) Caso a rolagem seja igual a 20, o ataque é crítico e o dano é duplicado.
                4) a HP do jogador ou inimigo é alterada com um setter, e recebe o valor da HP anterior decrementada de uma variável dmg que é gerada com o rolar de um dado com o tipo da arma que o atacante tem.


[Equipe]: #Equipe
[Descrição]: #Descrição
[Instruções]: #Instruções
[Sobre o Jogo]: #Sobre-o-Jogo
[Como Jogar]: #Como-Jogar
[Documentação de Código]: #Documentação-de-Código

