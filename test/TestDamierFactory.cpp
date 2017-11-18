//
//  TestDamierFactory.cpp
//  test
//
//  Created by Pierre TASSEL on 18/11/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#include "catch.hpp"
#include "DamierFactory.hpp"

DamierFactory factory = DamierFactory();
Case** cases = factory.creerDamier(1, 10);

TEST_CASE( "Nombre de case correcte", "[nombreDeCases]" ) {
    REQUIRE( factory.nombreDeCases(1, 1) == 4 );
    REQUIRE( factory.nombreDeCases(1, 2) == factory.nombreDeCases(1, 2) );
    REQUIRE( factory.nombreDeCases(1, 2) == 6 );
    REQUIRE( factory.nombreDeCases(2, 1) == 6 );
    REQUIRE( factory.nombreDeCases(2, 2) == 9 );
}
