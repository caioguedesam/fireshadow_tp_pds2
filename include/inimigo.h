/*
Inimigo: classe filha de Entidade que contém os métodos e atributos específicos de Inimigos.
atributos:
	> raça
métodos:
	> construtor com parâmetros
	> getter e setter específico para nome de inimigo
	> método de atacar um jogador
*/

#ifndef INIMIGO_PDS_G5
#define INIMIGO_PDS_G5

#include <iostream>
#include "entidade.h"
#include "arma.h"
#include "jogador.h"
#include "dado.h"

class Jogador;

class Inimigo :	public Entidade {
private:
	std::string _raca;
public:
	Inimigo(std::string raca, Arma arma, int CA, int HP);
	std::string get_nome() override;
	void set_nome(std::string nome);
	void atacar (Jogador &player);
};

#endif
