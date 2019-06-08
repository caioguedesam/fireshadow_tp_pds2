#include "inimigo.h"

Inimigo::Inimigo(std::string raca, Arma arma, int CA, int HP):
	Entidade(CA, HP, "", arma), _raca(raca){}

std::string Inimigo::get_nome(){
  return this->_nome + " (" + this->_raca + ")";
}

void Inimigo::set_nome(std::string nome){
  this->_nome = nome;
}

void Inimigo::atacar(Jogador &player){
/*A função atacar() ataca um dado Inimigo
Retorna: Um dado que representa o ataque finalizado*/
  Dado dado;
  int roll = dado.rolar_dado();
  std::cout << "Rolagem: " << roll << "\n";
  //Ataque bem sucedido:
  if(roll >= player.get_CA()){
  	int dmg = dado.rolar_dado(_arma.get_dano());
  	if(roll==20){
  		dmg *= 2; 
      std::cout << "\e[35mATAQUE CRITICO!\e[37m" << std::endl;	
  	}
  	player.set_HP(player.get_HP() - dmg);
  	std::cout << player.get_nome() << " sofreu \e[31m" << dmg << "\e[37m pontos de dano!\n\n";
  }
  //Ataque mal sucedido:
  else{
  	std::cout << "FRACASSO!" << std::endl;
    std::cout << "\n\n";
  }
}
