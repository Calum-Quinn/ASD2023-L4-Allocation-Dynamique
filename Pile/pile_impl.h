#ifndef PILE_IMPL_H
#define PILE_IMPL_H

#include <stdexcept> // std::out_of_range
#include "pile.h"

// AJOUTEZ VOTRE CODE ICI ...

template <typename T>
Pile<T>::Pile(size_t n) {
   //Doit allouer la mémoire pour n éléments de type T (sans les construire)
   Pile* pile = new Pile(n);
}

template <typename T>
Pile<T>::~Pile() {
   //Détruire les éléments et libérer la mémoire
   while (!this->empty()) {
      ~(this->top());
   }
}

template <typename T>
void Pile<T>::push(T e) {
   //La méthode push doit construire un élément par construisant
   //par déplacement l'objet passé en paramètre à la bonne addresse mémoire.
}

template <typename T>
void Pile<T>::pop() {
   //pop doit détruire l'élément au sommet sans libérer de mémoire.
}

template <typename T>
const T& Pile<T>::top() const {
   return top();
}

template <typename T>
bool Pile<T>::empty() const noexcept {
   return !taille;
}

template <typename T>
bool Pile<T>::full() const noexcept {
   return capacite == taille;
}

template <typename T>
Pile<T>::Pile(const Pile& other) {
   //Le constructeur de copie effectue une copie de la Pile reçue en
   // paramètre avec la même capacité que celle-ci.
}

template <typename T>
void Pile<T>::swap(Pile& other) noexcept {
   //La méthode swap échange le contenu des 2 piles en offrant une garantie noexcept.
   // Elle doit vous aider à mettre en oeuvre un des cas de l'opérateur d'affectation.
}

template <typename T>
Pile<T>& Pile<T>::operator= ( const Pile& other ) {
   //L'opérateur d'affectation par copie doit se comporter comme suit:
   // si la taille de la Pile à copier est inférieure ou égale à la capacité
   // courante de la pile, on ne réalloue pas de mémoire.
   // Par contre, si la capacité actuelle est trop faible, on réalloue.
}



// ... FIN DE VOTRE CODE

#endif
