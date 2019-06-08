#include "../third_party/doctest.h"
#include "../include/includes.h"

TEST_CASE("Testando metodo atacar") {
  Arma besta(4, "BESTA");
  Jogador t("Gabe", "DEV", besta, 0, 100);
  Inimigo dummy("Dummy", besta, 0, 100);

  dummy.set_nome("Dummo");
    
  t.atacar(dummy);
  dummy.atacar(t);
  
  CHECK(dummy.get_HP() < 100);
  CHECK(t.get_HP() < 100);
  
  t.recuperar_vida();
  
  CHECK(t.get_HP() == 100);
}

TEST_CASE("Testando atributos - Entidade") {
  Arma besta(4, "BESTA");
  Entidade t(0, 100, "Gabe", besta);

  CHECK(t.get_nome() == "Gabe");
  CHECK(t.get_arma() == "BESTA");
  CHECK(t.get_HP() == 100);
  CHECK(t.get_CA() == 0);
}

TEST_CASE("Testando atributos - Jogador") {
  Arma besta(4, "BESTA");
  Jogador t("Gabe", "DEV", besta, 0, 100);

  CHECK(t.get_classe() == "DEV");
}

TEST_CASE("Testando atributos - Inimigo") {
  Arma besta(4, "BESTA");
  Inimigo dummy("Dummy", besta, 0, 100);

  CHECK(dummy.get_nome() == " (Dummy)");

  dummy.set_nome("Dummo");
  
  CHECK(dummy.get_nome() == "Dummo (Dummy)");
}
