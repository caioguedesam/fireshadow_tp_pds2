#include "../third_party/doctest.h"
#include "../include/aventuras.h"

TEST_CASE("Testando atributos - Aventura") {
	Aventura aventura_t("A Aventura Bizarra de JoJo");
	auto vec_test_jog = aventura_t.get_jogadores();
	auto vec_test_ini = aventura_t.get_inimigos();

	CHECK(aventura_t.get_nome() == "║\e[33m A Aventura Bizarra de JoJo \e[37m║");
	CHECK(vec_test_ini.size() == 0);
	CHECK(vec_test_jog.size() == 0);
}

TEST_CASE("Testando adicionar_jogador") {
	Arma hamon(15, "HAMON");
	Arma star_platinum(20, "STAR PLATINUM");

	Aventura aventura_t("A Aventura Bizarra de JoJo");

	Jogador jonathan("JONATHAN JOESTAR", "HAMON USER", hamon, 13, 100);
	Jogador joseph("JOSEPH JOESTAR", "HAMON USER", hamon, 17, 100);
	Jogador jotaro("JOTARO KUJO", "STAND USER", star_platinum, 19, 100);
	
	aventura_t.adicionar_jogador(jonathan);
	aventura_t.adicionar_jogador(joseph);
	aventura_t.adicionar_jogador(jotaro);

	auto vec_test_jog = aventura_t.get_jogadores();
	
	CHECK(vec_test_jog.size() == 3);
	CHECK(vec_test_jog[0].get_nome() == "JONATHAN JOESTAR");
	CHECK(vec_test_jog[1].get_arma() == "HAMON");
	CHECK(vec_test_jog[2].get_classe() == "STAND USER");
}

TEST_CASE("Testando adicionar_inimigo") {
	Arma the_world(19, "ZA WARUDO");
	Arma pillar_pow(16, "PILLAR MEN POWERS");
	
	Aventura aventura_t("A Aventura Bizarra de JoJo");

	Inimigo dio("VAMPIRE", the_world, 18, 200);
	Inimigo kars("PILLAR MAN", pillar_pow, 14, 500);

	aventura_t.adicionar_inimigo(dio, "DIO");
	aventura_t.adicionar_inimigo(kars, "KARS");

	auto vec_test_ini = aventura_t.get_inimigos(); 

	CHECK(vec_test_ini.size() == 2);
	CHECK(vec_test_ini[0].get_nome() == "DIO (VAMPIRE)");
	CHECK(vec_test_ini[1].get_nome() == "KARS (PILLAR MAN)");
}