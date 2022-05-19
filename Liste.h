//
// Created by etudiant on 22-05-14.
//

#ifndef LISTE_DOUBLEMENT_CHAINEE_SQUELETTE_LISTE_H
#define LISTE_DOUBLEMENT_CHAINEE_SQUELETTE_LISTE_H

#include <cstddef>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cassert>

namespace td3 {
    template<typename T>
    class Liste {

    public:
        class const_iterateur;

        class iterateur;

    public:
        explicit Liste();

        Liste(const Liste &);

        ~Liste();

        Liste<T> &operator=(const Liste<T> &);

        const_iterateur cbegin() const ;

        iterateur begin() const ;

        const_iterateur cend() const ;

        iterateur end() const ;

        void ajouter(const T &, const int &);

        void enleverEl(const T &);

        void enleverPos(const int &);

        int taille() const;

        bool estVide() const;

        bool appartient(const T &) const;

        T element(const int &) const;

        int position(const T &) const;


        std::string format() const;

        template<class U>
        friend std::ostream &operator<<(std::ostream &, const Liste<U> &);

    private:


        class Noeud {
        public:
            T donnee;
            Noeud *suivant;
            Noeud *precedent;

            explicit Noeud() : donnee(), suivant(nullptr), precedent(nullptr) {}

            explicit Noeud(const T &data_item, Noeud *next_ptr = nullptr, Noeud *prev_ptr = nullptr) :
                    donnee(data_item), suivant(next_ptr), precedent(prev_ptr) {}
        };


        Noeud *premier;
        Noeud *dernier;
        int cardinal;

        bool positionEstValideEnLecture(int pos) const;

        bool positionEstValideEnEcriture(int pos) const;

        bool verifieInvariant() const;

        Noeud *adresseAPosition(int position) const;

        Noeud *revAdresseAPosition(int position) const;

        Noeud *adresseDeLaValeur(const T &valeur) const;

        void enleverAAdresse(Noeud *adresse);

        void insererDansAdresse(Noeud *noeud, Noeud *adresse);

        void desinsererDeAdresse(Noeud *adresse);

        void copier(const Liste<T> &rhs);

        void effacer();

    public:
        class const_iterateur {
        public:
            explicit const_iterateur(Noeud* p = nullptr) : courant(p) {}

            const const_iterateur& operator++() {
                courant = courant->suivant ;
                return *this ;
            }

            const_iterateur operator++(int ){
                courant = courant->suivant ;
                return *this ;
            }

            const_iterateur operator--() {
                courant = courant->precedent;
                return *this;
            }

            bool operator == (const const_iterateur& rhs) {
                return this->courant == rhs.courant ;
            }

            bool operator != (const const_iterateur& rhs) {
                return this->courant != rhs.courant;
            }

            const T &operator*() const {
                return courant->donnee;
            }

        protected:
            Noeud *courant;
        };

        class iterateur : public const_iterateur {
        public:
            iterateur(Noeud* p) : const_iterateur(p) {}

            T &operator*() const {
                return const_iterateur::courant->donnee;
            }
        };


    };


}


#include "Liste_Implantation.h"


#endif //LISTE_DOUBLEMENT_CHAINEE_SQUELETTE_LISTE_H
