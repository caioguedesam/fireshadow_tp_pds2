#include "entidade.h"

Entidade::Entidade(int CA, int HP, std::string nome, Arma arma){
	this->_CA = CA;
	this->_HP = HP;
	this->_arma = arma;
	this->_nome = nome;
}

std::string Entidade::get_nome(){
  return this->_nome;
}

int Entidade::get_CA(){
	return this->_CA;
}
int Entidade::get_HP(){
	return this->_HP;
}
void Entidade::set_HP(int vida){
	this->_HP = vida;
}

std::string Entidade::get_arma()
{
	return this->_arma.get_nome();
}
