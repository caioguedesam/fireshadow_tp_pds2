#include "dado.h"
#include <iostream>

Dado::Dado(){
	this->_tipo_dado = 20;
}
Dado::Dado(int tipo){
	if (tipo != 20 and tipo != 12 and tipo != 10 and tipo != 8 and tipo != 6 and tipo != 4){
		std::cout << "Erro. Tipo de dado inválido." << std::endl;
	} else{
		this->_tipo_dado = tipo;
	}
}

void Dado::set_tipo_dado(int tipo){
	this->_tipo_dado = tipo;
}
int Dado::get_tipo_dado(){
	return _tipo_dado;
}
int Dado::rolar_dado(){
	int randroll = rand() % _tipo_dado + 1;
	return randroll;
}

int Dado::rolar_dado(int tipo_dado){
	return rand() % tipo_dado + 1;
}
