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
        listeCinq.ajouter(16.5, 4) ;
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
    EXPECT_FALSE(listeUn.estVide()) ;
    EXPECT_FALSE(listeDeux.estVide()) ;
    EXPECT_FALSE(listeCinq.estVide()) ;
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

TEST_F(ListeTest, position_retourne_position_valide_si_element_present) {
    EXPECT_EQ(1, listeUn.position(10.5)) ;
    EXPECT_EQ(1, listeDeux.position(11.5)) ;
    EXPECT_EQ(2, listeDeux.position(12.5)) ;
    EXPECT_EQ(1, listeCinq.position(13.5)) ;
    EXPECT_EQ(3, listeCinq.position(15.5)) ;
    EXPECT_EQ(5, listeCinq.position(17.5)) ;
}

TEST_F(ListeTest, position_retourne_cardinal_plus_un_si_element_absent) {
    EXPECT_EQ(1, listeVide.position(1.0)) ;
    EXPECT_EQ(2, listeUn.position(10000)) ;
    EXPECT_EQ(3, listeDeux.position(-70)) ;
    EXPECT_EQ(6, listeCinq.position(13.0)) ;
}

TEST_F(ListeTest, ajouter_dans_liste_vide_element_est_present) {
    listeVide.ajouter(1.0, 1) ;
    EXPECT_EQ("[1]", listeVide.format()) ;
    EXPECT_EQ(1, listeVide.taille()) ;
    EXPECT_FALSE(listeVide.estVide()) ;
}

TEST_F(ListeTest, ajouter_dans_liste_non_vide_en_premier) {
    listeUn.ajouter(1, 1) ;
    EXPECT_EQ("[1, 10.5]", listeUn.format()) ;
    EXPECT_EQ(2, listeUn.taille()) ;
    listeDeux.ajouter(1, 1) ;
    EXPECT_EQ("[1, 11.5, 12.5]", listeDeux.format()) ;
    EXPECT_EQ(3, listeDeux.taille()) ;
    listeCinq.ajouter(1, 1) ;
    EXPECT_EQ("[1, 13.5, 14.5, 15.5, 16.5, 17.5]", listeCinq.format()) ;
    EXPECT_EQ(6, listeCinq.taille()) ;
}

TEST_F(ListeTest, ajouter_dans_liste_non_vide_en_dernier) {
    listeUn.ajouter(1, 2) ;
    EXPECT_EQ("[10.5, 1]", listeUn.format()) ;
    EXPECT_EQ(2, listeUn.taille()) ;
    listeDeux.ajouter(1, 3) ;
    EXPECT_EQ("[11.5, 12.5, 1]", listeDeux.format()) ;
    EXPECT_EQ(3, listeDeux.taille()) ;
    listeCinq.ajouter(1, 6) ;
    EXPECT_EQ("[13.5, 14.5, 15.5, 16.5, 17.5, 1]", listeCinq.format()) ;
    EXPECT_EQ(6, listeCinq.taille()) ;
}

TEST_F(ListeTest, ajouter_dans_liste_non_vide_au_milieu) {
    listeDeux.ajouter(1, 2) ;
    EXPECT_EQ("[11.5, 1, 12.5]", listeDeux.format()) ;
    listeCinq.ajouter(1, 2) ;
    EXPECT_EQ("[13.5, 1, 14.5, 15.5, 16.5, 17.5]", listeCinq.format()) ;
}

TEST_F(ListeTest, ajouter_deux_elements_consecutifs_au_debut) {
    listeVide.ajouter(1, 1) ;
    listeVide.ajouter(2, 2) ;
    EXPECT_EQ("[1, 2]", listeVide.format()) ;
    EXPECT_EQ(2, listeVide.taille()) ;
}

TEST_F(ListeTest, ajouter_deux_elements_consecutifs_au_milieu) {
    listeDeux.ajouter(1, 2) ;
    listeDeux.ajouter(2, 2) ;
    EXPECT_EQ("[11.5, 2, 1, 12.5]", listeDeux.format()) ;
    EXPECT_EQ(4, listeDeux.taille()) ;
}

TEST_F(ListeTest, ajouter_deux_elements_consecutifs_a_la_fin) {
    listeDeux.ajouter(1, 3) ;
    listeDeux.ajouter(2, 4) ;
    EXPECT_EQ("[11.5, 12.5, 1, 2]", listeDeux.format()) ;
}

TEST_F(ListeTest, enlever_element_present_au_debut) {
    listeCinq.enleverEl(17.5) ;
    EXPECT_EQ(4, listeCinq.taille()) ;
    EXPECT_EQ("[13.5, 14.5, 15.5, 16.5]", listeCinq.format()) ;
}

TEST_F(ListeTest, enlever_element_present_a_la_fin) {
    listeCinq.enleverEl(13.5) ;
    EXPECT_EQ(4, listeCinq.taille()) ;
    EXPECT_EQ("[14.5, 15.5, 16.5, 17.5]", listeCinq.format()) ;
}

TEST_F(ListeTest, enlever_element_present_au_milieu) {
    listeCinq.enleverEl(15.5) ;
    EXPECT_EQ(4, listeCinq.taille()) ;
    EXPECT_EQ("[13.5, 14.5, 16.5, 17.5]", listeCinq.format()) ;
}

TEST_F(ListeTest, enlever_dernier_element_liste_vide) {
    listeUn.enleverEl(10.5) ;
    EXPECT_EQ("[]", listeUn.format()) ;
    EXPECT_TRUE(listeUn.estVide()) ;
}

TEST_F(ListeTest, enlever_element_absent_liste_inchangee) {
    listeCinq.enleverEl(666) ;
    EXPECT_EQ(5, listeCinq.taille()) ;
    EXPECT_EQ("[13.5, 14.5, 15.5, 16.5, 17.5]", listeCinq.format()) ;
}

TEST_F(ListeTest, enelver_sur_liste_vide_inchangee) {
    listeVide.enleverEl(1) ;
    EXPECT_TRUE(listeVide.estVide()) ;
    EXPECT_EQ("[]", listeVide.format()) ;
}

TEST_F(ListeTest, enlever_a_position_valide_au_debut) {
    listeCinq.enleverPos(1) ;
    EXPECT_EQ("[14.5, 15.5, 16.5, 17.5]", listeCinq.format()) ;
    listeCinq.enleverPos(1) ;
    EXPECT_EQ("[15.5, 16.5, 17.5]", listeCinq.format()) ;
    listeCinq.enleverPos(1) ;
    EXPECT_EQ("[16.5, 17.5]", listeCinq.format()) ;
    listeCinq.enleverPos(1) ;
    EXPECT_EQ("[17.5]", listeCinq.format()) ;
    listeCinq.enleverPos(1) ;
    EXPECT_EQ("[]", listeCinq.format()) ;
    EXPECT_TRUE(listeCinq.estVide()) ;
}

TEST_F(ListeTest, enlever_a_la_position_valide_a_la_fin) {
    listeCinq.enleverPos(5) ;
    EXPECT_EQ("[13.5, 14.5, 15.5, 16.5]", listeCinq.format()) ;
    EXPECT_EQ(4, listeCinq.taille()) ;
}

TEST_F(ListeTest, enlever_a_position_valide_au_milieu) {
    listeCinq.enleverPos(4) ;
    EXPECT_EQ("[13.5, 14.5, 15.5, 17.5]", listeCinq.format()) ;
    EXPECT_EQ(4, listeCinq.taille()) ;
}

TEST_F(ListeTest, enlever_a_position_invalide_inchangee) {
    listeCinq.enleverPos(6) ;
    EXPECT_EQ("[13.5, 14.5, 15.5, 16.5, 17.5]", listeCinq.format()) ;
    EXPECT_EQ(5, listeCinq.taille()) ;

    listeDeux.enleverPos(-4) ;
    EXPECT_EQ("[11.5, 12.5]", listeDeux.format()) ;
    EXPECT_EQ(2, listeDeux.taille()) ;

    listeVide.enleverPos(0) ;
    EXPECT_EQ("[]", listeVide.format()) ;
    EXPECT_TRUE(listeVide.estVide()) ;
}

TEST_F(ListeTest, constructeur_copie_copie_fidele) {
    td3::Liste<double> copie(listeDeux) ;
    EXPECT_EQ("[11.5, 12.5]", copie.format()) ;
}

TEST_F(ListeTest, operateur_assignation_membre_gauche_est_ecrase) {
    listeCinq = listeDeux ;
    EXPECT_EQ("[11.5, 12.5]", listeCinq.format()) ;
}

TEST_F(ListeTest, operateur_assignation_retourne_membre_droite) {
    EXPECT_EQ("[11.5, 12.5]", (listeCinq = listeDeux).format()) ;
}






