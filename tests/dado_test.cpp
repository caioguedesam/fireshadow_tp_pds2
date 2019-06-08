#include "../third_party/doctest.h"
#include "../include/dado.h"

TEST_CASE("Testando dado") {
	Dado t(19);

	CHECK(t.get_tipo_dado() == 0);
	
	t.set_tipo_dado(10);
	
	CHECK(t.get_tipo_dado() == 10);
	CHECK(t.rolar_dado() >= 1);
	CHECK(t.rolar_dado(20) >= 1);
}
