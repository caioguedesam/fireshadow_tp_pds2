#include "funcoes.h"

void menu(){
	int option = 1;
	while(option != 0){
		limpar_tela();
		imprime_menu("Fireshadow");
		while(!(std::cin >> option) || option < 0 || option > 1){
		    std::cout << "Selecione uma opção válida: ";
		    std::cin.clear();
		    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		switch(option){
		case 0:
			exit(0);
		case 1:
			menu_iniciar();	
			break;
		}
	}
}

void imprime_opcoes(std::string nome){
	if(nome == "Fireshadow"){
		std::cout << "║|1| \e[32mIniciar\e[0m" << std::endl;
		std::cout << "║|0| \e[32mSair\e[0m" << std::endl;
	} else if(nome == "Personagens"){
		std::cout << "║|1| " << Josivaldo.get_nome() << std::endl;
		std::cout << "║|2| " << Louro.get_nome() << std::endl;
		std::cout << "║|3| " << Flavius.get_nome() << std::endl;
		std::cout << "║|4| " << Maurus.get_nome() << std::endl;
		std::cout << "║|0| Voltar" << std::endl;
	} else if(nome == "Aventuras"){
		std::cout << "║|1| The Black Fog" << std::endl;
		std::cout << "║|2| Royal Kidnapping" << std::endl;
		std::cout << "║|3| The King's Escort" << std::endl;
		std::cout << "║|4| The Black Creche" << std::endl;
		std::cout << "║|0| Voltar" << std::endl;
	}
}

void imprime_menu(std::string nome){
	std::cout << "\e[37m";
	std::cout << "╔═══════════════════════╗" << std::endl;
	std::cout << "║       \e[36m"<< nome <<"\e[37m" << std::endl;
	std::cout << "╠═══════════════════════╣" << std::endl;
	imprime_opcoes(nome);
	std::cout << "╠═══════════════════════╣" << std::endl;
	std::cout << "║Selecione uma opção: ";
	std::cout << "\e[0m";
}

void menu_iniciar(){
	int option = 1;
	while(option != 0){
		limpar_tela();
		imprime_menu("Personagens");
		while(!(std::cin >> option) || option < 0 || option > 5){
		    std::cout << "Selecione uma opção válida: ";
		    std::cin.clear();
		    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		switch(option){
			case 0:
				menu();
				break;
			case 1:
				menu_aventura(Josivaldo);	
				break;
			case 2:
				menu_aventura(Louro);	
				break;
			case 3:
				menu_aventura(Flavius);	
				break;
			case 4:
				menu_aventura(Maurus);	
				break;
			case 5:
				//Personagem secreto
				menu_aventura(Turin);
				break;
		}
	}
}

void menu_aventura(Jogador &Player){
	int option = 1;
	while(option != 0){
		limpar_tela();
		imprime_menu("Aventuras");
		while(!(std::cin >> option) || option < 0 || option > 4){
		    std::cout << "Selecione uma opção válida: ";
		    std::cin.clear();
		    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		switch(option){
		case 0:
			menu_iniciar();
			break;
		case 1:
			aventura_1(Player);	
			break;
		case 2:
			aventura_2(Player);	
			break;
		case 3:
			aventura_3(Player);	
			break;
		case 4:
			aventura_4(Player);	
			break;
		}
	}
}