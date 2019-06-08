#include "arma.h"
#include "dado.h"

Arma::Arma(){}

Arma::Arma(int dano, std::string nome){
	this->_dano = dano;
	this->_nome = nome;
}

int Arma::get_dano(){
  return this->_dano;
}

std::string Arma::get_nome(){
  return this->_nome;
}
