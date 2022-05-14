//
// Created by etudiant on 22-05-14.
//

#include "gtest/gtest.h"
#include "Liste.h"

TEST(Liste, constructeur_no_throw) {
    EXPECT_NO_THROW(td3::Liste<int> l) ;
}
