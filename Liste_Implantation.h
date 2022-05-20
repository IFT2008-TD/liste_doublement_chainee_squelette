//
// Created by etudiant on 22-05-14.
//

#ifndef LISTE_MAIN_LISTE_IMPLANTATION_H
#define LISTE_MAIN_LISTE_IMPLANTATION_H

#include "Liste.h"

namespace td3 {

    /**
     * Créer une liste vide.
     * @tparam T Type des données stockées dans la liste
     */
    template<typename T>
    Liste<T>::Liste() : premier(new Noeud), dernier(new Noeud), cardinal(0) {
        premier->suivant = dernier;
        dernier->precedent = premier;
        assert(verifieInvariant()) ;
    }

    /**
     * Constructeur par copie.
     * @tparam T
     * @param source
     */
    template<typename T>
    Liste<T>::Liste(const Liste &source) : premier(new Noeud), dernier(new Noeud), cardinal(0) {
        premier->suivant = dernier ;
        dernier->precedent = premier ;
        copier(source);
        assert(verifieInvariant()) ;
    }

    /**
     * Destructeur
     * @tparam T
     */
    template<typename T>
    Liste<T>::~Liste() {
        effacer();
        delete premier ;
        delete dernier ;
    }

    /**
     * Opérateur d'assignation
     * @tparam T Type de données stockées dans la liste
     * @param rhs Membre de droite de l'assignation
     * @return A = B assigne B à A et retourne A.
     */
    template<typename T>
    Liste<T> &Liste<T>::operator=(const Liste<T> &rhs) {
        if (&rhs != this) {
            effacer();
            copier(rhs);
        }
        assert(verifieInvariant()) ;
        return *this;
    }

    /**
     * Ajouter une données dans la liste à une position donnée. Si l'élément est ajouté à la position n, après insertion
     * l'élément occupe la position n.
     * @tparam T Type de l'élément ajouté
     * @param valeur Valeur de l'élément ajouté
     * @param position Position de l'ajout
     * @pre position est compris entre 1 et cardinal+1 inclusivement.  Si la position est invalide la fonction ne fait rien.
     */
    template<typename T>
    void Liste<T>::ajouter(const T &valeur, const int &position) {
        if (!positionEstValideEnEcriture(position)) return;

        auto n = new Noeud(valeur);
        auto p = adresseAPosition(position);

        insererDansAdresse(n, p);
        cardinal++;

        assert(verifieInvariant()) ;
    }

    /**
     * Enlever un élément de la liste.  enleverEl(v) enlève de la liste le premier élément de valeur v trouvé à partir
     * du début.  Si l'élément est absent, ou si la liste est vide, il ne se passe rien.
     * @tparam T Type de l'élément enlevé.
     * @param valeur Valeur à enlever et retirer de la liste.
     */
    template<typename T>
    void Liste<T>::enleverEl(const T &valeur) {
        if (estVide()) return;

        auto n = adresseDeLaValeur(valeur);
        enleverAAdresse(n);

        assert(verifieInvariant()) ;
    }

    /**
     * Enlever un élément de la liste.  Retire l'élément situé à une position donnée.
     * @tparam T Type dde données stockées dans la liste.
     * @param position Position à laquelle retire l'élément.
     * @pre position est comprise entre 1 et cardinal.
     */
    template<typename T>
    void Liste<T>::enleverPos(const int &position) {
        if (!positionEstValideEnLecture(position)) return;

        auto n = adresseAPosition(position);
        enleverAAdresse(n);

        assert(verifieInvariant()) ;

    }

    /**
     * Compte les éléments dans la liste
     * @tparam T
     * @return Le cardinal de la liste
     */
    template<typename T>
    int Liste<T>::taille() const {
        return cardinal;
    }

    /**
     * Vérifie si la liste est vide
     * @tparam T
     * @return true si la liste est vide
     */
    template<typename T>
    bool Liste<T>::estVide() const {
        return taille() == 0;
    }

    /**
     * Vérifie la présence d'un élément dans la liste
     * @tparam T
     * @param valeur Valeur qu'on veut détecter dans la liste
     * @return true si valeur est dans la liste.
     */
    template<typename T>
    bool Liste<T>::appartient(const T &valeur) const {
        return (adresseDeLaValeur(valeur) != end());
    }

    /**
     * Retourne la valeur à une position donnée
     * @tparam T
     * @param position
     * @return La valeur de l'élément à la position position
     * @pre Position est comprise entre 1 et cardinal inclusivement.
     */
    template<typename T>
    T Liste<T>::element(const int &position) const {
        if (!positionEstValideEnLecture(position)) throw std::invalid_argument("element: position invalide");
        auto p = adresseAPosition(position);
        return *p ;
    }

    /**
     * Détecte la position de la première occurrence de valeur dans la liste.
     * @tparam T
     * @param valeur
     * @return L'indice où se trouve la valeur cherchée.  Si la valeur est absente de la liste, retourne cardinal+1
     */
    template<typename T>
    int Liste<T>::position(const T &valeur) const {
        if (estVide()) return 1;

        int position = 0 ;
        for (auto p = begin(); p != end(); p++) {
            if (*p == valeur) return position;
            ++position;
        }
        return position;
    }

    /**
     * Vérifie la validité de l'objet liste
     * @tparam T
     * @return true si l'invariant de classe est respecté
     */
    template<typename T>
    bool Liste<T>::verifieInvariant() const {
        if ((premier->precedent != nullptr) || (dernier->suivant != nullptr)) return false ;

        if (cardinal == 0) return (premier->suivant == dernier) && (dernier->precedent == premier) ;

        /*
        auto p = adresseAPosition(cardinal);
        if (++p != end()) return false;

        auto d = revAdresseAPosition(1);
        if (--d != premier)  return false;*/

        return true;
    }

    /**
     * Insère une représentation textuelle de la liste dans un stream d'IO.
     * @tparam U
     * @param os Stream d'IO
     * @param liste liste à afficher
     * @return Le stream additionné de la liste.
     */
    template<class U>
    std::ostream &operator<<(std::ostream &os, const Liste<U> &liste) {
        os << liste.format();
        return os;
    }

    /**
     * Localise le noeud à une position donnée
     * @tparam T
     * @param position La position cherchée
     * @return Un pointeur sur le noeud occupant la position demandée.
     * @pre position est valide
     */
    template<typename T>
    typename Liste<T>::iterateur Liste<T>::adresseAPosition(int position) const {
        auto p = begin();
        for (int i = 0; i < position; ++i) ++p ;
        return p;
    }

    /**
     * Localise la première occurrence de l'élément valeur dans la liste
     * @tparam T
     * @param valeur Valeur recherchée
     * @return Un pointeur sur le noeud contenant la première occurrence de valeur.  Si la valeur cherchée est absente,
     * retourne end().
     */
    template<typename T>
    typename Liste<T>::iterateur Liste<T>::adresseDeLaValeur(const T &valeur) const {
        auto p = begin() ;
        for ( ; p != end(); ++p) {
            if (*p == valeur) return p;
        }
        return p;
    }

    /**
     * Ajoute un noeud dans la liste: insère le noeud pointé par noeud à gauche de adresse et à droite de adresse->precedent
     * @tparam T
     * @param noeud pointeur sur le noeud à insérer
     * @param adresse adresse où insérer le noeud
     */
    template<typename T>
    void Liste<T>::insererDansAdresse(Liste::Noeud *noeud, Liste::iterateur itAdresse) {
        auto adresse = itAdresse.courant ;

        noeud->precedent = adresse->precedent;
        noeud->suivant = adresse;
        (noeud->precedent)->suivant = noeud;
        (noeud->suivant)->precedent = noeud;
    }

    /**
     * Retirer un noeud de la liste.  adresse->precedent sera lié directement à adresse->suivant
     * @tparam T
     * @param adresse Adresse du noeud à retirer
     */
    template<typename T>
    void Liste<T>::desinsererDeAdresse(Liste::iterateur it) {
        auto adresse = it.courant ;

        (adresse->precedent)->suivant = adresse->suivant;
        (adresse->suivant)->precedent = adresse->precedent;
    }

    /**
     * Élimine tous les noeuds de la liste, sauf les sentinelles.
     * @tparam T
     */
    template<typename T>
    void Liste<T>::effacer() {
        while (!estVide()) enleverPos(1);
    }

    /**
     * Retourne un représentation textuelle de la liste: "[e1, e2, e3]"
     * @tparam T
     * @return Un objet string contenant cette représentation
     */
    template<typename T>
    std::string Liste<T>::format() const {
        if (estVide()) return "[]";

        std::ostringstream os;
        os << "[";
        for (Noeud *p = premier->suivant; p != dernier; p = p->suivant) {
            os << p->donnee;
            if (p->suivant != dernier) os << ", ";
        }
        os << "]";
        return os.str();
    }

    /**
     * Vérifie la validité d'un index pour lire un élément
     * @tparam T
     * @param pos L'index à vérifier
     * @return true si l'index correspond à une valeur lisible dans la liste (1--cardinal)
     */
    template<typename T>
    bool Liste<T>::positionEstValideEnLecture(int pos) const {
        return (pos > 0) && (pos <= cardinal);
    }

    /**
     * Localise un noeud mais à-partir de la fin.  Utilisé dans l'invariant.
     * @tparam T
     * @param position Position du noeud à localiser (la position est comptée du début, mais le noeud sera localisé de
     * la fin)
     * @return L'adresse du noeud
     */
    template<typename T>
    typename Liste<T>::Noeud *Liste<T>::revAdresseAPosition(int position) const {

        Noeud *d = dernier;
        for (int i = cardinal+1; i > position; --i) d = d->precedent;
        return d;
    }

    /**
     * Vérifie la validitié d'un index pour insérer un élément.
     * @tparam T
     * @param pos Index à vérifier
     * @return true si une insertion est possible à cet index. (1 --> cardinal+1)
     */
    template<typename T>
    bool Liste<T>::positionEstValideEnEcriture(int pos) const {
        return (pos > 0) && (pos <= (cardinal + 1));
    }

    /**
     * Retire un noeud de la liste
     * @tparam T
     * @param adresse Adresse du noeud à retirer
     */
    template<typename T>
    void Liste<T>::enleverAAdresse(Liste::iterateur adresse) {
        if (adresse == end()) return;
        desinsererDeAdresse(adresse);
        --cardinal;
    }

    /**
     * Copier dans l'objet courant, tous les noeuds d'un autre objet liste.
     * @tparam T
     * @param rhs Liste à recopier
     * @pre L'objet courant est une liste vide.
     */
    template<typename T>
    void Liste<T>::copier(const Liste<T> &rhs) {
        assert(estVide());

        if (rhs.estVide()) return;
        for (auto p = rhs.premier->suivant; p != rhs.dernier; p = p->suivant) {
            ajouter(p->donnee, taille() + 1);
        }
    }

    template<typename T>
    typename Liste<T>::const_iterateur Liste<T>::cbegin() const {
        return Liste<T>::const_iterateur(premier);
    }

    template<typename T>
    typename Liste<T>::iterateur Liste<T>::begin() const {
        return Liste<T>::iterateur(premier);
    }

    template<typename T>
    typename Liste<T>::const_iterateur Liste<T>::cend() const {
        return Liste<T>::const_iterateur(dernier);
    }

    template<typename T>
    typename Liste<T>::iterateur Liste<T>::end() const {
        return Liste<T>::iterateur(dernier);
    }


}

#endif //LISTE_MAIN_LISTE_IMPLANTATION_H
