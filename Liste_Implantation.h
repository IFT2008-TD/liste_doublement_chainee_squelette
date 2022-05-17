//
// Created by etudiant on 22-05-14.
//

#ifndef LISTE_MAIN_LISTE_IMPLANTATION_H
#define LISTE_MAIN_LISTE_IMPLANTATION_H

#include "Liste.h"

namespace td3 {

    template<typename T>
    Liste<T>::Liste() : premier(new Noeud), dernier(new Noeud), cardinal(0) {
        premier->suivant = dernier;
        dernier->precedent = premier;
        assert(verifieInvariant()) ;
    }

    template<typename T>
    Liste<T>::Liste(const Liste &source) : premier(new Noeud), dernier(new Noeud), cardinal(0) {
        premier->suivant = dernier ;
        dernier->precedent = premier ;
        copier(source);
        assert(verifieInvariant()) ;
    }

    template<typename T>
    Liste<T>::~Liste() {
        effacer();
        delete premier ;
        delete dernier ;
    }

    template<typename T>
    Liste<T> &Liste<T>::operator=(const Liste<T> &rhs) {
        if (&rhs != this) {
            effacer();
            copier(rhs);
        }
        assert(verifieInvariant()) ;
        return *this;
    }

    template<typename T>
    void Liste<T>::ajouter(const T &valeur, const int &position) {
        if (!positionEstValideEnEcriture(position)) return;
        auto n = new Noeud(valeur);
        Noeud *p = adresseAPosition(position);
        insererDansAdresse(n, p);
        cardinal++;
        assert(verifieInvariant()) ;
    }

    template<typename T>
    void Liste<T>::enleverEl(const T &valeur) {
        if (estVide()) return;

        auto n = adresseDeLaValeur(valeur);
        enleverAAdresse(n);
        assert(verifieInvariant()) ;
    }

    template<typename T>
    void Liste<T>::enleverPos(const int &position) {
        if (!positionEstValideEnLecture(position)) return;

        auto n = adresseAPosition(position);
        enleverAAdresse(n);

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
        if (!positionEstValideEnLecture(position)) throw std::invalid_argument("element: position invalide");
        auto p = adresseAPosition(position);
        return p->donnee;
    }

    template<typename T>
    int Liste<T>::position(const T &valeur) const {
        if (estVide()) return 1;

        int position = 1;
        for (auto p = premier->suivant; p != dernier; p = p->suivant) {
            if (p->donnee == valeur) return position;
            ++position;
        }
        return position;
    }

    template<typename T>
    bool Liste<T>::verifieInvariant() const {
        if ((premier->precedent != nullptr) || (dernier->suivant != nullptr)) return false ;

        if (cardinal == 0) return (premier->suivant == dernier) && (dernier->precedent == premier) ;

        Noeud *p = adresseAPosition(cardinal);
        if (p->suivant != dernier) return false;

        Noeud *d = revAdresseAPosition(1);
        if (d->precedent != premier)  return false;

        return true;
    }

    template<class U>
    std::ostream &operator<<(std::ostream &os, const Liste<U> &liste) {
        os << liste.format();
        return os;
    }

    template<typename T>
    typename Liste<T>::Noeud *Liste<T>::adresseAPosition(int position) const {
        Noeud *p = premier;
        for (int i = 0; i < position; ++i) p = p->suivant;
        return p;
    }

    template<typename T>
    typename Liste<T>::Noeud *Liste<T>::adresseDeLaValeur(const T &valeur) const {
        for (auto p = premier->suivant; p != dernier; p = p->suivant) {
            if (p->donnee == valeur) return p;
        }
        return nullptr;
    }

    template<typename T>
    void Liste<T>::insererDansAdresse(Liste::Noeud *noeud, Liste::Noeud *adresse) {
        noeud->precedent = adresse->precedent;
        noeud->suivant = adresse;
        (noeud->precedent)->suivant = noeud;
        (noeud->suivant)->precedent = noeud;
    }

    template<typename T>
    void Liste<T>::desinsererDeAdresse(Liste::Noeud *adresse) {
        (adresse->precedent)->suivant = adresse->suivant;
        (adresse->suivant)->precedent = adresse->precedent;
    }

    template<typename T>
    void Liste<T>::effacer() {
        while (!estVide()) enleverPos(1);
    }

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

    template<typename T>
    bool Liste<T>::positionEstValideEnLecture(int pos) const {
        return (pos > 0) && (pos <= cardinal);
    }

    template<typename T>
    typename Liste<T>::Noeud *Liste<T>::revAdresseAPosition(int position) const {

        Noeud *d = dernier;
        for (int i = cardinal+1; i > position; --i) d = d->precedent;
        return d;
    }

    template<typename T>
    bool Liste<T>::positionEstValideEnEcriture(int pos) const {
        return (pos > 0) && (pos <= (cardinal + 1));
    }

    template<typename T>
    void Liste<T>::enleverAAdresse(Liste::Noeud *adresse) {
        if (adresse == nullptr) return;
        desinsererDeAdresse(adresse);
        --cardinal;
    }

    template<typename T>
    void Liste<T>::copier(const Liste<T> &rhs) {
        assert(estVide());

        if (rhs.estVide()) return;
        for (auto p = rhs.premier->suivant; p != rhs.dernier; p = p->suivant) {
            ajouter(p->donnee, taille() + 1);
        }
    }


}

#endif //LISTE_MAIN_LISTE_IMPLANTATION_H
