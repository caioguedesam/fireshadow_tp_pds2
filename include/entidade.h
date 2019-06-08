/*
Entidade: classe-mãe que contém os métodos e atributos gerais de Jogadores e Inimigos.
atributos:
	> nome
	> classe de armadura (define qual o número que quem irá atacar deve tirar no dado para atacar a entidade)
	> pontos de vida (HP)
	> arma
métodos:
	> construtor com parâmetros
	> getter para CA, HP, nome e arma
	> setter para HP
*/

#ifndef ENTIDADE_PDS_G5
#define ENTIDADE_PDS_G5

#include "arma.h"

class Entidade {
protected:
	std::string _nome;
	int _CA;
	int _HP;
	Arma _arma;
public:
	Entidade(int CA, int HP, std::string nome, Arma arma);
	int get_CA();
	int get_HP();
	void set_HP(int vida);
	virtual std::string get_nome();
	std::string get_arma();
};


#endif
