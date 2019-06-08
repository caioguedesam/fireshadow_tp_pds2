#include "banco.h"

//Armas
Arma EspadaLonga = Arma(8, "ESPADA LONGA");
Arma CanetaLonga = Arma(8, "CANETA LONGA");
Arma Adaga = Arma(4, "ADAGA");
Arma Cimitarra = Arma(6, "CIMITARRA");
Arma Martelo = Arma(8, "MARTELO");
Arma Besta = Arma(4, "BESTA");
Arma EspadaDeTurin = Arma(20, "ESPADA DE TURIN");

//Magias
Arma BolaDeFogo = Arma(8, "BOLA DE FOGO");
Arma Relampago = Arma(10, "RELAMPAGO");
Arma BolaDeFogoVil = Arma(8, "BOLA DE MAGIA VIL");
Arma RaioNegro = Arma(10, "RAIO NEGRO");
Arma QuadroNegro = Arma(10, "QUADRO NEGRO");

//Ataques
Arma Mordida = Arma(8, "MORDIDA");
Arma Soco = Arma(6, "SOCO");

//Jogador Player(nome, classe, arma, CA, HP)
Jogador Josivaldo = Jogador("Josivaldo", "GUERREIRO", EspadaLonga, 10, 16);
Jogador Mirelly = Jogador("Mirelly", "PATRULHEIRA", Besta, 11, 12);
Jogador Louro = Jogador("Louro", "LADINO", Adaga, 14, 10);
Jogador Maurus = Jogador("Maurus", "MAGO", Relampago, 16, 18);
Jogador Flavius = Jogador("Flavius", "FEITICEIRO", BolaDeFogo, 13, 13);
Jogador Adrian = Jogador("Adrian", "MONGE", Soco, 13, 12);
Jogador Turin = Jogador("Turin, o Grande", "TECNOMAGO", EspadaDeTurin, 19, 30);

Inimigo Goblin = Inimigo( "Goblin", Cimitarra, 8, 6);
Inimigo Orc = Inimigo("Orc", Martelo, 11, 15);
Inimigo Warg = Inimigo("Warg", Mordida, 10, 12);
Inimigo DragaoVermelho = Inimigo("Dragão Vermelho", Mordida, 19, 256);
Inimigo Guldan = Inimigo("Orc", BolaDeFogoVil, 12, 25);
Inimigo GoblinPequeno = Inimigo("Globin Pequeno", Adaga, 6, 6);
Inimigo Esqueleto = Inimigo("Esqueleto", EspadaLonga, 8, 4);
Inimigo Lich = Inimigo("Lich", RaioNegro, 13, 50);
Inimigo Pirralho = Inimigo("Pirralho", CanetaLonga, 8, 4);
Inimigo Encrenqueiro = Inimigo("Encrenqueiro", QuadroNegro, 13, 50);
