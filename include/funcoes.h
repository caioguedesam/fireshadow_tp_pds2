/*
Funções: arquivo com funções que são executadas durante o programa principal.
funções:
	> menu (menu principal do jogo, a pessoa escolhe iniciar ou sair do jogo)
	> menu aventura (a pessoa escolhe qual aventura vai trilhar)
	> menu iniciar (a pessoa escolhe qual personagem vai ser)
	> imprime menu/opções (funções para impressão na tela dos menus)
*/

#ifndef FUNCOES_PDS_G5
#define FUNCOES_PDS_G5

#include <iostream>
#include "aventuras.h"
#include <exception>

void menu_aventura(Jogador &Player);
void menu();
void menu_iniciar();
void imprime_opcoes(std::string nome);
void imprime_menu(std::string nome);

#endif