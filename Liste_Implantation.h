//
// Created by etudiant on 22-05-14.
//

#ifndef LISTE_MAIN_LISTE_IMPLANTATION_H
#define LISTE_MAIN_LISTE_IMPLANTATION_H

#include "Liste.h"

namespace td3 {

    template<typename T>
    Liste<T>::Liste() {}

    template<typename T>
    Liste<T>::Liste(const Liste &source) {

    }

    template<typename T>
    Liste<T>::~Liste() {

    }

    template<typename T>
    const Liste<T> &Liste<T>::operator=(const Liste<T> &rhs) {
        return *this;
    }

    template<typename T>
    void Liste<T>::ajouter(const T &valeur, const int &position) {

    }

    template<typename T>
    void Liste<T>::enleverEl(const T &valeur) {

    }

    template<typename T>
    void Liste<T>::enleverPos(const int &position) {

    }

    template<typename T>
    int Liste<T>::taille() const {
        return 0;
    }

    template<typename T>
    bool Liste<T>::estVide() const {
        return false;
    }

    template<typename T>
    bool Liste<T>::appartient(const T &valeur) const {
        return false;
    }

    template<typename T>
    T Liste<T>::element(const int &position) const {
        return nullptr;
    }

    template<typename T>
    int Liste<T>::position(const T &valeur) const {
        return 0;
    }

    template<typename T>
    void Liste<T>::verifieInvariant() const {

    }

    template<class U>
    std::ostream &operator<<(std::ostream & os, const Liste<U> &) {
        return os;
    }


}

#endif //LISTE_MAIN_LISTE_IMPLANTATION_H
