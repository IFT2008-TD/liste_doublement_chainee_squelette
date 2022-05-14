//
// Created by etudiant on 22-05-14.
//

#include "gtest/gtest.h"
#include "Liste.h"

TEST(Liste, constructeur_no_throw) {
    EXPECT_NO_THROW(td3::Liste<int> l) ;
}

class ListeTest : public ::testing::Test {
protected:
    void SetUp() override {
        listeUn.ajouter(10.5, 1) ;
        listeDeux.ajouter(11.5, 1) ;
        listeDeux.ajouter(12.5, 2) ;
        listeCinq.ajouter(13.5, 1) ;
        listeCinq.ajouter(14.5, 2) ;
        listeCinq.ajouter(15.5, 3) ;
        listeCinq.ajouter(16.6, 4) ;
        listeCinq.ajouter(17.5, 5) ;
    }

    td3::Liste<double> listeVide ;
    td3::Liste<double> listeUn ;
    td3::Liste<double> listeDeux ;
    td3::Liste<double> listeCinq ;

};

TEST_F(ListeTest, format_listeVide) {
    EXPECT_EQ("[]", listeVide.format()) ;
    EXPECT_EQ("[10.5]", listeUn.format()) ;
    EXPECT_EQ("[11.5, 12.5]", listeDeux.format()) ;
    EXPECT_EQ("[13.5, 14.5, 15.5, 16.5, 17.5]", listeCinq.format()) ;
}

TEST_F(ListeTest, taille_correcte_apres_creation) {
    EXPECT_EQ(0, listeVide.taille()) ;
    EXPECT_EQ(1, listeUn.taille()) ;
    EXPECT_EQ(2, listeDeux.taille()) ;
    EXPECT_EQ(5, listeCinq.taille()) ;
}

TEST_F(ListeTest, estVide_correcte_apres_creation) {
    EXPECT_TRUE(listeVide.estVide()) ;
    EXPECT_FALSE(listeVide.estVide()) ;
    EXPECT_FALSE(listeVide.estVide()) ;
    EXPECT_FALSE(listeVide.estVide()) ;
}

TEST_F(ListeTest, appartient_true_lorsque_present) {
    EXPECT_TRUE(listeUn.appartient(10.5)) ;
    EXPECT_TRUE(listeDeux.appartient(11.5)) ;
    EXPECT_TRUE(listeDeux.appartient(12.5)) ;
    EXPECT_TRUE(listeCinq.appartient(13.5)) ;
    EXPECT_TRUE(listeCinq.appartient(17.5)) ;
    EXPECT_TRUE(listeCinq.appartient(15.5)) ;
}

TEST_F(ListeTest, appartient_false_lorsque_absent) {
    EXPECT_FALSE(listeVide.appartient(1.0)) ;
    EXPECT_FALSE(listeUn.appartient(1.0)) ;
    EXPECT_FALSE(listeDeux.appartient(23.0)) ;
    EXPECT_FALSE(listeCinq.appartient(66.0)) ;
}

TEST_F(ListeTest, element_retourne_valeur_sur_position_valide) {
    EXPECT_EQ(10.5, listeUn.element(1)) ;
    EXPECT_EQ(11.5, listeDeux.element(1)) ;
    EXPECT_EQ(12.5, listeDeux.element(2)) ;
    EXPECT_EQ(13.5, listeCinq.element(1)) ;
    EXPECT_EQ(14.5, listeCinq.element(2)) ;
    EXPECT_EQ(17.5, listeCinq.element(5)) ;
}

TEST_F(ListeTest, element_exception_sur_position_invalide) {
    EXPECT_THROW(listeVide.element(1), std::invalid_argument) ;
    EXPECT_THROW(listeUn.element(0), std::invalid_argument) ;
    EXPECT_THROW(listeUn.element(-1), std::invalid_argument) ;
    EXPECT_THROW(listeDeux.element(-4), std::invalid_argument) ;
    EXPECT_THROW(listeDeux.element(0), std::invalid_argument) ;
    EXPECT_THROW(listeDeux.element(3), std::invalid_argument) ;
    EXPECT_THROW(listeCinq.element(-1), std::invalid_argument) ;
    EXPECT_THROW(listeCinq.element(0), std::invalid_argument) ;
    EXPECT_THROW(listeCinq.element(6), std::invalid_argument) ;
}




