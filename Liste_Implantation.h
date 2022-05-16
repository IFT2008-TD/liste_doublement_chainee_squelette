//
// Created by etudiant on 22-05-14.
//

#ifndef LISTE_MAIN_LISTE_IMPLANTATION_H
#define LISTE_MAIN_LISTE_IMPLANTATION_H

#include "Liste.h"

namespace td3
{

  /**
   * @brief Constructeur par défaut d'une liste. Crée une liste vide.
   */
  template<typename T>
  Liste<T>
  ::Liste () { }

  /**
   * @brief Constructeur copie. Crée une liste distincte de la source, avec les
   * mêmes éléments dans le même ordre.
   * @param source  Liste originale.  Peut être vide.
   */
  template<typename T>
  Liste<T>
  ::Liste (const Liste &source) { }

  /**
   * Le destructeur.  Désalloue tous les éléments, si nécessaire.
   */
  template<typename T>
  Liste<T>
  ::~Liste () { }

  /**
   * @brief Opérateur d'assignation.  A = B efface le contenu de la liste A et
   * le remplace par une copie du contenu de la liste B.  Ensuite, retourne une
   * référence la liste A ainsi modifiée.
   * @param rhs La liste B.
   * @return Référence à la liste A qui contient maintenant une copie de B.
   */
  template<typename T>
  Liste<T> &Liste<T>::operator= (const Liste<T> &rhs)
  {
    return *this;
  }

  /**
   * @brief Insère un élément d'une valeur donnée à une position donnée.
   * @param valeur Élément à insérer.
   * @param position Indice où l'élément sera inséré.  Le nouvel élément aura
   * cette position dans la liste modifiée. L'élément dont il prend la place est
   * donc déplacé vers la droite de une position.
   * @pre La position est comprise entre 1 et cardinal+1 inclusivement.  L'insertion
   * à la position cardinal+1 est donc en FIN de liste.  L'insertion à la position
   * 1 est en tête de liste.  Si la position est invalide, la fonction ne fait
   * rien.
   */
  template<typename T>
  void Liste<T>
  ::ajouter (const T &valeur, const int &position) { }

  /**
   * @brief Retire de la liste la première occurrence, à-partir de la tête, de
   * l'élément ayant la valeur demandée.  Si cet élément est absent, ne fait
   * rien.
   * @param valeur Élément à retirer.
   */
  template<typename T>
  void Liste<T>
  ::enleverEl (const T &valeur) { }

  /**
   * @brief Retire de la liste l'élément à la position demandée.  Si cette
   * position est invalide, ne fait rien.
   * @param position Position à laquelle retirer l'élément.
   * @pre La position demandée est comprise entre 1 et cardinal inclusivement.
   */
  template<typename T>
  void Liste<T>
  ::enleverPos (const int &position) { }

  /**
   * @brief Compte les éléments de la liste.
   * @return Le nombre d'éléments de la liste.
   */
  template<typename T>
  int Liste<T>
  ::taille () const
  {
    return 0;
  }

  /**
   * @brief Teste la liste pour la présence d'un élément.
   * @return true si la liste est vide.
   */
  template<typename T>
  bool Liste<T>
  ::estVide () const
  {
    return false;
  }

  /**
   * @brief Vérifie la présence d'un élément dans la liste.
   * @param valeur Élément à vérifier
   * @return true si valeur est présent dans la liste.
   */
  template<typename T>
  bool Liste<T>
  ::appartient (const T &valeur) const
  {
    return false;
  }

  /**
   * @brief Valeur d'un élément de la liste à une position donnée.
   * @param position Position de l'élément
   * @return La valeur de l'élément à cette position.
   * @pre La position demandée est comprise entre 1 et cardinal inclusivement.
   * @except invalid_argument si la position est invalide.
   */
  template<typename T>
  T Liste<T>
  ::element (const int &position) const
  {
    T t;
    return t;
  }

  /**
   * @brief Retourne la position de la première occurrence, à-partir du début,
   * de l'élément valeur. Retourne cardinal+1 si l'élément est absent.
   * @param valeur Élément dont on veut connaître la position.
   * @return La position de la première occurrence de valeur.
   */
  template<typename T>
  int Liste<T>
  ::position (const T &valeur) const
  {
    return 0;
  }

  /**
   * @brief Vérifie la validité interne de la liste.
   * @return true si l'objet est valide.
   */
  template<typename T>
  bool Liste<T>
  ::verifieInvariant () const
  {
    return false;
  }

  /**
   * @brief Fonction amie qui affiche la liste dans un stream de sortie.
   * @param os stream de sortie
   * @param liste Liste à afficher
   * @return Le stream de sortie avec la liste insérée dedans.
   */
  template<class U>
  std::ostream &operator<< (std::ostream & os, const Liste<U> &liste)
  {
    return os;
  }

  /**
   * @brief Méthode privée qui retourne l'adresse du noeud à une position donnée.
   * @param position Position du noeud
   * @return adresse du noeud.  Si la position est invalide retourne nullptr.
   * @pre La position demandée doit être comprise entre 1 et cardinal inclusivement
   */
  template<typename T>
  typename Liste<T>::Noeud *Liste<T>
  ::adresseAPosition (int position) const
  {
    return nullptr;
  }

  /**
   * @brief Recherche l'adresse du premier noeud contenant la valeur demandée.
   * @param valeur Valeur demandée.
   * @return Adresse du premier noeud contenant cette valeur. Si cette valeur
   * n'est pas dans la liste, retourne nullptr.
   */
  template<typename T>
  typename Liste<T>::Noeud *Liste<T>
  ::adresseDeLaValeur (const T &valeur) const
  {
    return nullptr;
  }

  /**
   * @brief Insère un noeud dont le
   * @param adresse
   */
  template<typename T>
  void Liste<T>
  ::insererDansAdresse (Liste::Noeud *adresse) { }

  template<typename T>
  void Liste<T>
  ::desinsererDeAdresse (Liste::Noeud *adresse) { }

  /**
   * @brief Copie les éléments d'une liste dans une liste vide.
   */
  template<typename T>
  void Liste<T>
  ::copier () { }

  /**
   * Désalloue tous les éléments d'une liste
   */
  template<typename T>
  void Liste<T>
  ::effacer () { }

  /**
   * Produit une version texte de la liste.
   * @return un objet string de la forme [e1, e2, e3, ..., eN].  Si la liste
   * est vide simplement: []
   */
  template<typename T>
  std::string Liste<T>
  ::format () const
  {
    return "";
  }


}

#endif //LISTE_MAIN_LISTE_IMPLANTATION_H
