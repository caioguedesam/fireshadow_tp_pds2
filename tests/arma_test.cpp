#include "../third_party/doctest.h"
#include "../include/arma.h"

TEST_CASE("Testando arma") {
	Arma t(3, "troika");
	
	CHECK(t.get_dano() == 3);
	CHECK(t.get_nome() == "troika");
}
