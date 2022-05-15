//
// Created by etudiant on 22-05-14.
//

#ifndef LISTE_MAIN_LISTE_IMPLANTATION_H
#define LISTE_MAIN_LISTE_IMPLANTATION_H

#include "Liste.h"

namespace td3 {

    template<typename T>
    Liste<T>::Liste() : premier(nullptr), dernier(nullptr), cardinal(0) {
        assert(verifieInvariant()) ;
    }

    template<typename T>
    Liste<T>::Liste(const Liste &source) : premier(nullptr), dernier(nullptr), cardinal(0) {
        copier(source) ;
        assert(verifieInvariant()) ;
    }

    template<typename T>
    Liste<T>::~Liste() {
        effacer() ;
    }

    template<typename T>
    Liste<T> &Liste<T>::operator=(const Liste<T> &rhs) {
        if (&rhs != this) {
            effacer() ;
            copier(rhs) ;
        }
        assert(verifieInvariant()) ;
        return *this;
    }

    template<typename T>
    void Liste<T>::ajouter(const T &valeur, const int &position) {
        if (!positionEstValideEnEcriture(position)) return ;
        auto n = new Noeud(valeur) ;

        if (estVide()) {
            premier = n ;
            dernier = n ;
        }

        else if (position == 1) {
            n->suivant = premier ;
            premier = n ;
            (n->suivant)->precedent = n ;
        }

        else if (position == cardinal + 1) {
            n->precedent = dernier ;
            dernier = n ;
            (n->precedent)->suivant = n ;
        }

        else {
            Noeud* p = adresseAPosition(position) ;
            insererDansAdresse(n, p) ;
        }
        cardinal ++ ;
        assert(verifieInvariant()) ;
    }

    template<typename T>
    void Liste<T>::enleverEl(const T &valeur) {
        if (estVide()) return ;

        auto n = adresseDeLaValeur(valeur) ;
        enleverAAdresse(n) ;
        assert(verifieInvariant()) ;
    }

    template<typename T>
    void Liste<T>::enleverPos(const int &position) {
        if (!positionEstValideEnLecture(position)) return ;

        auto n = adresseAPosition(position) ;
        enleverAAdresse(n) ;

        assert(verifieInvariant()) ;

    }

    template<typename T>
    int Liste<T>::taille() const {
        return cardinal;
    }

    template<typename T>
    bool Liste<T>::estVide() const {
        return taille() == 0;
    }

    template<typename T>
    bool Liste<T>::appartient(const T &valeur) const {
        return (adresseDeLaValeur(valeur) != nullptr);
    }

    template<typename T>
    T Liste<T>::element(const int &position) const {
        if (!positionEstValideEnLecture(position)) throw std::invalid_argument("element: position invalide") ;
        auto p = adresseAPosition(position) ;
        return p->donnee ;
    }

    template<typename T>
    int Liste<T>::position(const T &valeur) const {
        if (estVide()) return 1 ;

        int position = 1 ;
        for (auto p = premier; p != nullptr; p = p->suivant) {
            if (p->donnee == valeur) return position ;
            ++position ;
        }
        return position;
    }

    template<typename T>
    bool Liste<T>::verifieInvariant() const {
        if (cardinal == 0) return (premier == nullptr) && (dernier == nullptr) ;

        Noeud* p = adresseAPosition(cardinal) ;
        if ( (p->suivant != nullptr) || (p != dernier) ) return false ;

        Noeud* d = revAdresseAPosition(1) ;
        if ((d->precedent != nullptr) || (d != premier)) return false ;

        return true ;
    }

    template<class U>
    std::ostream &operator<<(std::ostream & os, const Liste<U> &liste) {
        os << liste.format() ;
        return os;
    }

    template<typename T>
    typename Liste<T>::Noeud *Liste<T>::adresseAPosition(int position) const {
        assert(positionEstValideEnLecture(position)) ;
        Noeud* p = premier ;
        for (int i = 1; i < position; ++i) p = p->suivant ;
        return p ;
    }

    template<typename T>
    typename Liste<T>::Noeud *Liste<T>::adresseDeLaValeur(const T &valeur) const {
        for (auto p = premier; p != nullptr; p = p->suivant) {
            if (p->donnee == valeur) return p ;
        }
        return nullptr;
    }

    template<typename T>
    void Liste<T>::insererDansAdresse(Liste::Noeud* noeud, Liste::Noeud *adresse) {
        noeud->precedent = adresse->precedent ;
        noeud->suivant = adresse ;
        (noeud->precedent)->suivant = noeud ;
        (noeud->suivant)->precedent = noeud ;
    }

    template<typename T>
    void Liste<T>::desinsererDeAdresse(Liste::Noeud *adresse) {
        (adresse->precedent)->suivant = adresse->suivant ;
        (adresse->suivant)->precedent = adresse->precedent ;
    }

    template<typename T>
    void Liste<T>::effacer() {
        while (!estVide()) enleverPos(1) ;
    }

    template<typename T>
    std::string Liste<T>::format() const {
        if (estVide()) return "[]" ;

        std::ostringstream os ;
        os << "[" ;
        for (Noeud* p = premier; p != nullptr; p = p->suivant) {
            os << p->donnee ;
            if (p->suivant != nullptr) os << ", " ;
        }
        os << "]" ;
        return os.str();
    }

    template<typename T>
    bool Liste<T>::positionEstValideEnLecture(int pos) const {
        return (pos > 0) && (pos <= cardinal);
    }

    template<typename T>
    typename Liste<T>::Noeud *Liste<T>::revAdresseAPosition(int position) const {
        assert(positionEstValideEnLecture(position)) ;

        Noeud* d = dernier ;
        for (int i = cardinal; i > position; --i) d = d->precedent ;
        return d;
    }

    template<typename T>
    bool Liste<T>::positionEstValideEnEcriture(int pos) const {
        return (pos >0) && (pos <= (cardinal + 1)) ;
    }

    template<typename T>
    void Liste<T>::enleverAAdresse(Liste::Noeud *adresse) {
        if (adresse == nullptr) return ;

        if (cardinal == 1) {
            premier = nullptr ;
            dernier = nullptr ;
        }

        else if (adresse == premier) {
            premier = adresse->suivant ;
            (adresse->suivant)->precedent = nullptr ;
        }

        else if (adresse == dernier) {
            dernier = adresse->precedent ;
            (adresse->precedent)->suivant = nullptr ;
        }

        else desinsererDeAdresse(adresse) ;

        --cardinal ;
    }

    template<typename T>
    void Liste<T>::copier(const Liste<T> &rhs) {
        assert(estVide()) ;

        if (rhs.estVide()) return ;
        for (auto p = rhs.premier; p != nullptr; p = p->suivant){
            ajouter(p->donnee, taille() + 1) ;
        }
    }


}

#endif //LISTE_MAIN_LISTE_IMPLANTATION_H
