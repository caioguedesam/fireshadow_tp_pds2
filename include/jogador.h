/*
Jogador: classe filha de Entidade que contém os métodos e atributos específicos de Jogador.
atributos:
	> classe
	> HP máxima (usado no método de recuperar vida)
métodos:
	> construtor com parâmetros
	> getter para classe
	> método de atacar um inimigo
	> método de recuperar vida
*/

#ifndef JOGADOR_PDS_G5
#define JOGADOR_PDS_G5

#include <iostream>
#include "entidade.h"
#include "arma.h"
#include "inimigo.h"
#include "dado.h"

class Inimigo;

class Jogador :	public Entidade {
private:
	std::string _classe;
	int _max_HP;
public:
	std::string get_nome() override;
	Jogador(std::string nome, std::string classe, Arma arma, int CA, int HP);
	std::string get_classe();
	void atacar (Inimigo &enemy);
	void recuperar_vida();
};

#endif
