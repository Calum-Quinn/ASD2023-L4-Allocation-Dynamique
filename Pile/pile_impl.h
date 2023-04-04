#ifndef PILE_IMPL_H
#define PILE_IMPL_H

#include <stdexcept> // std::out_of_range
#include "pile.h"

// AJOUTEZ VOTRE CODE ICI ...

template <typename T>
Pile<T>::Pile(size_t n) {
   //Doit allouer la mémoire pour n éléments de type T (sans les construire)
   data = (T*)(::operator new[](n*sizeof(T)));
}

template <typename T>
Pile<T>::~Pile() {
   //Détruire les éléments et libérer la mémoire
   delete[] data;
}

template <typename T>
void Pile<T>::push(T e) {
   //La méthode push doit construire un élément en construisant
   //par déplacement l'objet passé en paramètre à la bonne addresse mémoire.
   *(data + taille) = e;
   ++taille;
}

template <typename T>
void Pile<T>::pop() {
   //pop doit détruire l'élément au sommet sans libérer de mémoire.
   --taille;
}

template <typename T>
const T& Pile<T>::top() const {
   return *(data + taille - 1);
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
   capacite = other.capacite;
   *this = other;
}

template <typename T>
void Pile<T>::swap(Pile& other) noexcept {
   //La méthode swap échange le contenu des 2 piles en offrant une garantie noexcept.
   // Elle doit vous aider à mettre en oeuvre un des cas de l'opérateur d'affectation.
   if (this != &other) {
      swap(this->taille,other.taille);
      swap(this->capacite,other.capacite);
      swap(this->data,other.data);
   }
}

template <typename T>
Pile<T>& Pile<T>::operator= ( const Pile& other ) {
   //L'opérateur d'affectation par copie doit se comporter comme suit:
   // si la taille de la Pile à copier est inférieure ou égale à la capacité
   // courante de la pile, on ne réalloue pas de mémoire.
   // Par contre, si la capacité actuelle est trop faible, on réalloue.
   if (this == &other)
      return *this;



   if (other.taille > this->capacite) {
      //Réallouer de la mémoire
//      Pile temp{other};

      T* temp = T(::operator new [](other.taille * sizeof(T)));
      delete[] data;
      data = temp;
      taille = other.taille;
//      swap(other);
   }

   copy(other.data, other.data + other.taille, data);

   return *this;
}



// ... FIN DE VOTRE CODE

#endif
