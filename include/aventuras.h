/*
Aventuras: classe que representa uma aventura que um jogador pode trilhar no jogo.
atributos:
	> nome da aventura
	> vetor com todos os jogadores
	> vetor com todos os inimigos
métodos:
	> construtor com parâmetro nome
	> getter para o nome da aventura
	> adicionar jogador/inimigo
	> status (mostra os atributos pertinentes para a batalha)
		> do jogador
		> do inimigo
		> de um jogador e um inimigo
		> de todos na batalha
	> descansar (recuperar a vida de) todos os membros da sua party

Além disso, contém os métodos separados:
	> limpar tela (limpa a tela no console do jogo)
	> aventuras (1, 2, 3 e 4, métodos que geram a estrutura da aventura jogável).
*/

#ifndef AVENTURAS_PDS_G5
#define AVENTURAS_PDS_G5

#include <cstdlib>
#include "banco.h"
#include <typeinfo>
#include <vector>
#include <limits>

void limpar_tela();

class Aventura
{
private:
	std::string _nome_aventura;
	std::vector<Jogador> _jogadores;
	std::vector<Inimigo> _inimigos;
public:
	Aventura(std::string nome);
	std::string get_nome();
	std::vector<Jogador> get_jogadores();
	std::vector<Inimigo> get_inimigos();
	void adicionar_jogador(Jogador &Player);
	void adicionar_inimigo(Inimigo &Enemy , std::string nome);
	void status(Jogador *Player);
	void status(Inimigo *Enemy);
	void status(Jogador *Player, Inimigo *Enemy);
	void status();
	bool batalha();
	void party_descanso();
};

void aventura_1(Jogador Player);
void aventura_2(Jogador Player);
void aventura_3(Jogador Player);
void aventura_4(Jogador Player);

#endif