#include "jogador.h"

Jogador::Jogador(std::string nome, std::string classe, Arma arma, int CA, int HP):
	Entidade(CA, HP, nome, arma), _classe(classe), _max_HP(HP){}

std::string Jogador::get_nome(){
  return this->_nome;
}

std::string Jogador::get_classe(){
	return this->_classe;
}

void Jogador::atacar(Inimigo &enemy){
/*A função atacar() ataca um dado Inimigo
Retorna: Um dado que representa o ataque finalizado*/
    Dado dado;
    int roll = dado.rolar_dado();
    std::cout << "Rolagem: " << roll << "\n";

    //Ataque bem sucedido:
    if(roll >= enemy.get_CA()){
      	int dmg = dado.rolar_dado(_arma.get_dano());
      	if(roll==20){
      		dmg *= 2; 
      		std::cout << "\e[35mATAQUE CRITICO!\e[37m" << std::endl;
      	}
      	enemy.set_HP(enemy.get_HP() - dmg);
      	std::cout << enemy.get_nome() << " sofreu \e[31m" << dmg << "\e[37m pontos de dano!\n\n";
    } 
    else {  
      //Ataque mal sucedido:
      	std::cout << "FRACASSO!" << std::endl;
        std::cout << "\n\n";
    }
}

void Jogador::recuperar_vida() {
  this->_HP = this->_max_HP;
}