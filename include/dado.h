/*
Dado: classe que simula uma rolagem de um dado de determinado número de lados.
atributos:
	> tipo do dado (número de lados)
métodos:
	> construtor com parâmetro
	> getter e setter para tipo do dado
	> rolar dado (retorna um número aleatório representando uma face do dado)
*/

#ifndef DADO_PDS_G5
#define DADO_PDS_G5

#include <cstdlib>
#include <ctime>

class Dado {
private:
	int _tipo_dado;
public:
	Dado();
	Dado(int tipo);
	void set_tipo_dado(int tipo);
	int get_tipo_dado();
	int rolar_dado();
	int rolar_dado(int tipo_dado);
};

#endif
