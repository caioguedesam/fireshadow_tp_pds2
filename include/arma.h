/*
Arma: classe que guarda a arma que será usada por um jogador ou inimigo.
atributos:
	> nome da arma
	> dano da arma (um dado que será jogado para o ataque, semelhante à D&D)
métodos:
	> construtor com parâmetros
	> retorna nome da arma
	> retorna dano da arma
*/

#ifndef ARMA_PDS_G5
#define ARMA_PDS_G5
#include <iostream>
#include <string>

class Arma {
private:
  std::string _nome;
  int _dano;
  friend class Jogador;
  friend class Inimigo;

public:
  Arma();
  Arma(int dano, std::string nome);
  int get_dano();
  std::string get_nome ();
};
#endif
