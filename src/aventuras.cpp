#include "aventuras.h"

void limpar_tela() {
	std::system("clear");
}

Aventura::Aventura(std::string nome) {
	_nome_aventura = nome;
}

std::string Aventura::get_nome() {
	return "║\e[33m " + _nome_aventura + " \e[37m║";
}

//Adicionam jogadores e inimigos com push_back nos vetores da aventura:
//(1)
void Aventura::adicionar_jogador(Jogador &Player) {
	_jogadores.push_back(Player);
}
//(2)
void Aventura::adicionar_inimigo(Inimigo &Enemy , std::string nome) {
	Enemy.set_nome(nome);
	_inimigos.push_back(Enemy);
}

std::vector<Jogador> Aventura::get_jogadores() {
	return this->_jogadores;
}

std::vector<Inimigo> Aventura::get_inimigos() {
	return this->_inimigos;
}

//A função status mostra os dados de um parâmetro fornecido, caso seja chamada sem parâmetro, o faz com os vetores de jogador/inimigo.
void Aventura::status(Jogador *Player)
{
	std::cout << "╔══════════════════════════════════════════════════════════════════╗" << std::endl;
	std::cout << "  \e[32m" << Player->get_HP() << " HP \e[37m║ " << Player->get_nome() << " ║ " << Player->get_classe() << \
	 " ║ " << Player->get_arma() << " ║ " << std::endl;
	std::cout << "╚══════════════════════════════════════════════════════════════════╝" << std::endl;
}

void Aventura::status(Inimigo *Enemy)
{
	std::cout << "╔══════════════════════════════════════════════════════════════════╗" << std::endl;
	std::cout << "  \e[32m" << Enemy->get_HP() << " HP \e[37m║ " << Enemy->get_nome() << " ║ " << \
	Enemy->get_arma() << " ║ " << std::endl;
	std::cout << "╚══════════════════════════════════════════════════════════════════╝" << std::endl;
}

void Aventura::status(Jogador *Player, Inimigo *Enemy){
	std::cout << "╔══════════════════════════════════════════════════════════════════╗" << std::endl;
	std::cout << "  \e[32m" << Player->get_HP() << " HP \e[37m║ " << Player->get_nome() << " ║ " << Player->get_classe() << \
	 " ║ " << Player->get_arma() << " ║ " << std::endl;
	std::cout << "  \e[32m" << Enemy->get_HP() << " HP \e[37m║ " << Enemy->get_nome() << " ║ " << \
	 Enemy->get_arma() << " ║ " << std::endl;
	std::cout << "╚══════════════════════════════════════════════════════════════════╝" << std::endl << std::endl;
}

void Aventura::status()
{	
	std::cout << "\e[94mPARTY\e[37m" << std::endl;
	for(unsigned int i = 0; i < _jogadores.size(); i++)
	{
		this->status(&_jogadores[i]);
	}
	std::cout << "\e[91mINIMIGOS\e[37m" << std::endl;
	for(unsigned int i = 0; i < _inimigos.size(); i++)
	{
		this->status(&_inimigos[i]);
	}
}

//Função batalha: funciona com estruturas de repetição internas:
bool Aventura::batalha()
{
	while(true) {
		this->status();
		std::cout << "Pressione qualquer tecla para iniciar a batalha\n\n";
		getchar();

		while(true) {
			//Ataque dos Jogadores:
			//aqui há repetição para todos os jogadores, que podem escolher qual inimigo atacar.
			for(unsigned int i = 0; i < _jogadores.size(); i++) {
				limpar_tela();
				std::cout << "Vez de \e[94m" << _jogadores[i].get_nome() << std::endl << std::endl;
				std::cout << "\e[37mEscolha qual inimigo atacar:" << std::endl;
				for(unsigned j = 0; j < _inimigos.size(); j++) {
					std::cout << "(" << j+1 << ")\e[91m " << _inimigos[j].get_nome() << " \e[37m" << std::endl;
				}
				unsigned int escolhido = 0;
				std::cout << "Opção: ";
				while(!(std::cin >> escolhido) || escolhido < 0 || escolhido > _inimigos.size()) {
					//Caso a pessoa insira um número invalido, ela pede outra entrada.
					std::cout << "Insira um número entre os apresentados: ";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}

				//após a escolha, esse pedaço de código executa o ataque e, caso haja uma morte,
				//elimina a entidade morta do vetor específico.
				status(&_jogadores[i], &_inimigos[escolhido-1]);
				_jogadores[i].atacar(_inimigos[escolhido-1]);
				if(_inimigos[escolhido-1].get_HP() <= 0) {
					std::cout << _inimigos[escolhido-1].get_nome() << " \e[31;1mMORREU!\e[37m" << std::endl;
					_inimigos.erase(_inimigos.begin() + escolhido-1);
					//Se a batalha for vitoriosa, batalha() retorna TRUE:
					if(_inimigos.empty()) {
						std::cout << "\e[32mPARABÉNS, VOCÊS GANHARAM!\e[37m" << std::endl << std::endl;
						std::cout << "A batalha acabou." << std::endl;
						std::cout << "Pressione qualquer tecla para avancar.";
						getchar();
						getchar();
						limpar_tela();
						return true;
					}
				}
				std::cout << "Pressione qualquer tecla para avancar.";
				getchar();
				getchar();
			}
			
			//Ataque dos Inimigos. Funciona análogo ao dos Jogadores.
			for(unsigned int i = 0; i < _inimigos.size(); i++) {
				limpar_tela();
				std::cout << "Vez de \e[91m" << _inimigos[i].get_nome() << "\e[37m" <<  std::endl << std::endl;
				Dado dado_inimigo;
				int escolhido = dado_inimigo.rolar_dado(_jogadores.size());

				status(&_jogadores[escolhido-1], &_inimigos[i]);
				_inimigos[i].atacar(_jogadores[escolhido-1]);
				if(_jogadores[escolhido-1].get_HP() <= 0) {
					//Se o jogador principal morre, a aventura acaba e é fim de jogo. Batalha() retorna FALSE.
					if(_jogadores.begin()->get_HP() <= 0) {
						std::cout << "\e[31;1mVOCÊ MORREU!\e[37m";
						std::cout << "A batalha acabou." << std::endl;
						std::cout << "Pressione qualquer tecla para avancar.";
						getchar();
						limpar_tela();
						return false;
					}
					std::cout << _jogadores[escolhido-1].get_nome() << " \e[31;1mMORREU!\e[37m" << std::endl;
					_jogadores.erase(_jogadores.begin() + escolhido-1);
				}
				std::cout << "Pressione qualquer tecla para avancar.\n";
				getchar();
			}
		}
	}
}

//Percorre o vetor de Jogadores e recupera toda a vida
void Aventura::party_descanso() {
	for(unsigned int i = 0; i < _jogadores.size(); i++) {
		_jogadores[i].recuperar_vida();
	}
}

void aventura_1(Jogador Player) {
	
	Aventura aventura("THE BLACK FOG");
	aventura.adicionar_jogador(Player);
	aventura.adicionar_jogador(Mirelly);
	aventura.adicionar_jogador(Adrian);
	srand(time(NULL));

	limpar_tela();

	//Aventura 1: THE BLACK FOG
	//História (1)
	std::cout << aventura.get_nome() << std::endl;
	getchar();
	std::cout << "Na noite fria, chovia forte. ";
	std::cout << "Os trovões eram tão fortes que pareciam rugidos de deuses. " << std::endl;
	getchar();
	std::cout << Player.get_nome() << " e sua equipe entraram no famoso cemitério de Bernochyl.";
	getchar();
	std::cout << "Souberam de pessoas que desapareceram no lugar e resolveram investigar." << std::endl;
	getchar();
	std::cout << "Após alguns minutos de exploração, ouviram sons estranhos. ";
	std::cout << "Era estranho, pois o som parecia vir de baixo deles." << std::endl;
	getchar();
	std::cout << "Foi quando perceberam: Os seres estavam saindo dos túmulos. ";
	std::cout << "Eram esqueletos, com aparência feroz e maléfica." << std::endl;
	getchar();
	
	//Batalha (1)
	aventura.adicionar_inimigo(Esqueleto, "Manchas negras");
	aventura.adicionar_inimigo(Esqueleto, "Sem braço");
	aventura.adicionar_inimigo(Esqueleto, "Sem cabeça");
	aventura.adicionar_inimigo(Esqueleto, "Sem mandíbula");
	aventura.adicionar_inimigo(Esqueleto, "Comum");
	if(!aventura.batalha())
		goto aventura_fim;
	aventura.party_descanso();

	//História (2)
	std::cout << "Quando finalmente derrotaram os esqueletos, a equipe caiu na terra, exausta." << std::endl;
	getchar();
	std::cout << "Porém, aquele não era o fim. Havia alguém por trás daqueles esqueletos." << std::endl;
	getchar();
	std::cout << "Ele mostrou seus olhos azuis brilhantes na escuridão próxima. " << std::endl;
	getchar();
	std::cout << "A equipe inteira conseguia sentir uma presença maligna forte. " << std::endl;
	getchar();
	std::cout << "Era Zaurog, um Lich que supostamente era lenda. " << std::endl;
	getchar();
	std::cout << "Aquela não seria uma batalha fácil para " << Player.get_nome() << " e seus amigos." << std::endl;
	getchar();

	//Batalha (2)
	// Lich = Zaurog
	aventura.adicionar_inimigo(Lich, "Zaurog");
	if(!aventura.batalha())
		goto aventura_fim;
	aventura.party_descanso();

	//História (3)
	std::cout << "Ao fim da noite, os aventureiros puderam sentir o gosto da vitória." << std::endl;
	getchar();

	//Fim da aventura. Caso o jogador perca a aventura, vai direto para cá com um goto. 
	//Caso ganhe, irá para cá naturalmente.
	aventura_fim:
	std::cout << "A aventura acabou." << std::endl;
	std::cout << "Pressione qualquer tecla para funcionar." << std::endl;
	getchar();
}

void aventura_2(Jogador Player) {
	Aventura aventura("ROYAL KIDNAPPING");
	aventura.adicionar_jogador(Player);
	aventura.adicionar_jogador(Adrian);
	srand(time(NULL));

	limpar_tela();

	//AVENTURA 2: ROYAL KIDNAPPING
	//História (1)
	std::cout << aventura.get_nome() << std::endl;
	getchar();
	std::cout << Player.get_nome() << ", junto de seu parceiro Adrian, são renomados aventureiros que decidiram, em suas andanças, passar a noite na cidade mais próxima." << std::endl;
	getchar();
	std::cout << "Ao chegar na cidade de Ghendorr, todos estão em apuros. "<< Player.get_nome() << " procura saber mais." << std::endl;
	getchar();
	std::cout << "O rei os informa que a princesa foi capturada por um bando de Orcs." << std::endl;
	getchar();
	std::cout << "Como bons aventureiros, os dois vão procurar a princesa nas proximidades para ganhar recompensas." << std::endl;
	getchar();
	std::cout << "Na estrada, aparece um par de Goblins querendo roubar alguma coisa. " << std::endl << std::endl;
	getchar();

	//Batalha (1)
	aventura.adicionar_inimigo(Goblin, "Marquinhos");
	aventura.adicionar_inimigo(Goblin, "Bob");
	if(!aventura.batalha())
		goto aventura_fim;
	aventura.party_descanso();

	//História (2)
	std::cout << "Ao prosseguir viagem, " << Player.get_nome() << " encontra no ceu um sinal de fumaca." << std::endl;
	getchar();
	std::cout << "Os dois seguiram o sinal de fumaça e acharam um acampamento Orc." << std::endl;
	getchar();
	std::cout << "La, um Orc de vigia os esperava, com um Warg de guarda junto a ele, e se alertaram a presença dos aventureiros" << std::endl << std::endl;
	getchar();

	//Batalha (2)
	aventura.adicionar_inimigo(Orc, "Mano");
	aventura.adicionar_inimigo(Warg, "Dogão");
	if(!aventura.batalha())
		goto aventura_fim;
	aventura.party_descanso();

	//História (3)
	std::cout << "Ao derrotar o vigia, os aventureiros descobriram uma trilha levando para uma caverna, saindo do acampamento montado" << std::endl;
	getchar();
	std::cout << "Entrando na caverna, " << Player.get_nome() << " acendeu uma tocha ao longo do caminho." << std::endl;
	getchar();
	std::cout << "Eventualmente, acharam a princesa raptada amarrada, junto de dois Orcs de guarda." << std::endl << std::endl;
	getchar();

	//Batalha (3)
	aventura.adicionar_inimigo(Orc, "Ricardão");
	aventura.adicionar_inimigo(Orc, "Jão");
	if(!aventura.batalha())
		goto aventura_fim;
	aventura.party_descanso();

	//História (4)
	std::cout << "Depois de derrotar os Orcs, " << Player.get_nome() << " desamarrou a princesa e os aventureiros a levaram de volta." << std::endl;
	getchar();
	std::cout << "O rei os recebeu end Ghendorr com festa e ouro, aliviado por ver sua filha novamente." << std::endl;

	//Fim da aventura. Caso o jogador perca a aventura, vai direto para cá com um goto. Caso ganhe, irá para cá naturalmente.
	aventura_fim:
	std::cout << "A aventura acabou." << std::endl;
	std::cout << "Pressione qualquer tecla para funcionar" << std::endl;
	getchar();

}

void aventura_3(Jogador Player){
	Aventura aventura("THE KING'S ESCORT");
	aventura.adicionar_jogador(Player);
	srand(time(NULL));

	limpar_tela();

	//Aventura 3: THE KING'S ESCORT
	//História (1)
	std::cout << aventura.get_nome() << std::endl;
	getchar();
	std::cout << "O reino de Azeroth estava em alerta." << std::endl;
	getchar();
	std::cout << "Atacada por invasores Orcs, liderados por Gul'dan, um Orc feiticeiro vil que alimentava seu poder através da vida." << std::endl;
	getchar();
	std::cout << "Depois de várias cidades serem destruidas pelo seu poder e suas tropas, iria agora atacar Stormwind, uma das cidades mais importantes do Reino." << std::endl;
	getchar();
	std::cout << "Esse alvo não era apenas para alimentar seu poder, mas para matar o Rei Varian Wrynn, no qual tinha uma grande admiração por toda população." << std::endl;
	getchar();
	std::cout << "Era claro, se o rei permanecesse na cidade, ele seria morto, então para preservar sua vida foi declarada uma Escolta ao Rei para Redridge Mountains, onde ficaria seguro." << std::endl;
	getchar();
	std::cout << "Mas para isso, deveria ser a menor quantidade de pessoas para não atrair atenção, porém deveria conter os melhores. Então, como seu principal guarda-costas, foi escolhido " << Player.get_nome() << ", o melhor e mais habilidoso " << Player.get_classe() << " do reino." << std::endl;
	getchar();
	std::cout << "Partiram o mais rápido possível, pegando trilha pela Floresta de Elwin." << std::endl;
	getchar();
	std::cout <<"O que eles não esperavam era que estavam de encontro com um enorme Orc que estavam patrulhando a área. " << Player.get_nome()
				 << " escuta passos pesados e logo após, um grande silêncio... Então o Orc surge pelos ares após um grande salto, atacando tudo e todos que vêem pela frente." << std::endl;
	getchar();

	//Batalha (1)
	aventura.adicionar_inimigo(Orc, "Terry Crews");
	if(!aventura.batalha())
		goto aventura_fim;
	aventura.party_descanso();
	
	//Historia (2)
	std::cout << "Todos ficam impressionados pela força e habilidades de " << Player.get_nome() << " que acabara de derrotar um Orc sozinho." <<std::endl;
	getchar();
	std::cout << "Recuperados depois dessa batalha, prosseguiram em frente, entretanto sabiam que não seria nada fácil e que era apenas o começo." <<std::endl;
	getchar();
	std::cout << "...Se passaram algumas horas de viagem, deram uma pausa quando chegaram à uma nascente, onde poderam descansar dessa longa jornada." << std::endl;
	getchar();
	std::cout << "Aos cantos dos pássaros e as brisas dos ventos, um barulho nas gramas altas é escutado. Aparecem 2 pequenos Goblins, uma raça que sempre foram aliados aos Humanos. Mas estavam olhando meio receosos, não parecia uma situação normal." << std::endl;
	getchar();
	std::cout << "Estavam sussurando coisas estranhas em um equipamento não conhecido. E após alguns minutos deparados com essa situação..." << std::endl;
	getchar();
	std::cout << "Sem explicação, os 2 pequenos Goblins atacam." <<std::endl;
	getchar();

	//Batalha (2)
	aventura.adicionar_inimigo(GoblinPequeno, "Luquinhas");
	aventura.adicionar_inimigo(GoblinPequeno, "Binho");
	if(!aventura.batalha())
		goto aventura_fim;
	aventura.party_descanso();
	
	//Historia (3)
	std::cout << "..." << std::endl;
	getchar();
	std::cout << "..." << std::endl;
	getchar();
	std::cout << "Era um traição, os Goblins se juntaram a Gul'dan, que surgia flutuando pela floresta queimando tudo em sua volta com seu fogo vil." <<std::endl;
	getchar();
	std::cout << "Gul'dan se aproxima, soltando um rugido estrondoso, lançando uma Bola de Fogo Vil em direção à Varian e a " << Player.get_nome() << "." << std::endl;
	getchar();

	//Batalha (3)
	aventura.adicionar_inimigo(Guldan, "Gul'dan");
	if(!aventura.batalha())
		goto aventura_fim;
	aventura.party_descanso();
	
	//Historia(4)
	getchar();
	std::cout << Player.get_nome() << " derrotou Gul'dan, e o que seria apenas uma escolta para a segurança de seu rei, foi a batalha final para acabar com essa invasão que atormentava todo o reino." << std::endl;
	getchar();
	std::cout << "Ao voltarem da viagem, Stormwind estava intacta. E ao darem a noticia, todos comemoram e agradecem a " << Player.get_nome()<< ", que com derrotou todos os inimigos sozinho, levando a paz de novo ao reino de Azeroth" << std::endl;
	
	//Fim da aventura. Caso o jogador perca a aventura, vai direto para cá com um goto. Caso ganhe, irá para cá naturalmente.
	aventura_fim:
	std::cout << "A aventura acabou." << std::endl;
	std::cout << "Pressione qualquer tecla para funcionar" << std::endl;
	getchar();
}

void aventura_4(Jogador Player) {
	
	Aventura aventura("THE BLACK CRECHE");
	aventura.adicionar_jogador(Player);
	aventura.adicionar_jogador(Mirelly);
	aventura.adicionar_jogador(Adrian);
	srand(time(NULL));

	limpar_tela();

	//Aventura 4: THE BLACK CRECHE
	//História (1)
	std::cout << aventura.get_nome() << std::endl;
	getchar();
	std::cout << "Na noite morna, chuviscava. ";
	std::cout << "O som da chuva era gostoso, calmante." << std::endl;
	getchar();
	std::cout << Player.get_nome() << " e sua equipe entraram na famosa creche de Bernochyl.";
	getchar();
	std::cout << "Souberam de criancas que desapareceram no lugar e resolveram investigar." << std::endl;
	getchar();
	std::cout << "Após alguns minutos de exploração, ouviram sons estranhos. ";
	std::cout << "Era estranho, pois o som parecia vir de baixo deles." << std::endl;
	getchar();
	std::cout << "Foi quando perceberam: Os seres estavam saindo debaixo das camas. ";
	std::cout << "Eram moleques endemoniados, com aparência feroz e sapeca." << std::endl;
	getchar();
	
	//Batalha (1)
	aventura.adicionar_inimigo(Pirralho, "Mancha-camisa");
	aventura.adicionar_inimigo(Pirralho, "Sem Freio");
	aventura.adicionar_inimigo(Pirralho, "Sem Cabeça");
	aventura.adicionar_inimigo(Pirralho, "Sem Noção");
	aventura.adicionar_inimigo(Pirralho, "Espuleta");
	if(!aventura.batalha())
		goto aventura_fim;
	aventura.party_descanso();

	//História (2)
	std::cout << "Quando finalmente pegaram os pirralhos, a equipe caiu nos puffs, exausta." << std::endl;
	getchar();
	std::cout << "Porém, aquele não era o fim. Havia alguém por trás daquela trupe." << std::endl;
	getchar();
	std::cout << "Ele mostrou seus olhos azuis brilhantes na escuridão próxima. " << std::endl;
	getchar();
	std::cout << "A equipe inteira conseguia sentir uma presença maligna forte. " << std::endl;
	getchar();
	std::cout << "Era Lourinho, um encrenqueiro que supostamente era lenda. " << std::endl;
	getchar();
	std::cout << "Aquela não seria uma batalha fácil para " << Player.get_nome() << " e seus amigos." << std::endl;
	getchar();

	//Batalha (2)
	aventura.adicionar_inimigo(Encrenqueiro, "Lourinho");
	if(!aventura.batalha())
		goto aventura_fim;
	aventura.party_descanso();

	//História (3)
	std::cout << "Ao fim da noite, os aventureiros puderam sentir o gosto da vitória." << std::endl;
	getchar();

	//Fim da aventura. Caso o jogador perca a aventura, vai direto para cá com um goto. 
	//Caso ganhe, irá para cá naturalmente.
	aventura_fim:
	std::cout << "A aventura acabou." << std::endl;
	std::cout << "Pressione qualquer tecla para funcionar." << std::endl;
	getchar();
}