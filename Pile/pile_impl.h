#ifndef PILE_IMPL_H
#define PILE_IMPL_H

#include <stdexcept> // std::out_of_range
#include "pile.h"

// AJOUTEZ VOTRE CODE ICI ...

#include <algorithm>

using namespace std;

template <typename T>
Pile<T>::Pile(size_t n) {
   //Constructeur avec valeur
   //Doit allouer la mémoire pour n éléments de type T (sans les construire)
   data = (T*)(::operator new(n*sizeof(T)));
   capacite = n;
   taille = 0;
}

template <typename T>
Pile<T>::~Pile() {
   //Destructeur
   //Détruire les éléments et libérer la mémoire
   for (size_t i = 0; i < taille; ++i) {
      data[i].~T();
   }
   ::operator delete(data);
}

template <typename T>
void Pile<T>::push(T e) {
   //La méthode push doit construire un élément en construisant
   //par déplacement l'objet passé en paramètre à la bonne addresse mémoire.
   if(taille < capacite) {
      new(&data[taille]) T(std::move(e));
      ++taille;
   }
   else {
      throw out_of_range("Push");
   }
}

template <typename T>
void Pile<T>::pop() {
   //pop doit détruire l'élément au sommet sans libérer de mémoire.
   if (taille > 0) {
      std::destroy_at(&top());
      --taille;
   }
   else {
      throw out_of_range("Pop");
   }
}

template <typename T>
const T& Pile<T>::top() const {
   //Retourne l'élément en haut de la pile
   if(!taille) {
      throw out_of_range("top");
   }
   return data[(taille - 1)];
}

template <typename T>
bool Pile<T>::empty() const noexcept {
   //Retourne si la pile est vide
   return !taille;
}

template <typename T>
bool Pile<T>::full() const noexcept {
   //Retourne si la pile est pleine
   return capacite == taille;
}

template <typename T>
Pile<T>::Pile(const Pile& other) {
   //Le constructeur de copie effectue une copie de la Pile reçue en
   //paramètre avec la même capacité que celle-ci.
   taille = 0;
   data = (T*)(::operator new(other.capacite*sizeof(T)));
   capacite = other.capacite;
   for(size_t i = 0; i < other.taille; ++i) {
      new(&data[taille]) T(other.data[i]);
      ++taille;
   }
}

template <typename T>
void Pile<T>::swap(Pile& other) noexcept {
   //La méthode swap échange le contenu des 2 piles en offrant une garantie noexcept.
   //Elle doit vous aider à mettre en oeuvre un des cas de l'opérateur d'affectation.
   if (this != &other) {
      std::swap(taille,other.taille);
      std::swap(capacite,other.capacite);
      std::swap(data,other.data);
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

   //Pas assez de place
   if (other.taille > this->capacite) {
      Pile<T> temp(other);
      swap(temp);
   }
   else {
      //La pile a copier à plus d'éléments que la pile actuelle
      if (taille <= other.taille) {
         //Affecter les nouvelles valeurs aux éléments existants
         for (size_t i = 0; i < taille; ++i) {
            data[i] = other.data[i];
         }
         //Construire les nouveaux éléments
         for (size_t j = taille; j < other.taille; ++j) {
            new(&data[j]) T(other.data[j]);
            ++taille;
         }
      }
      //La pile a copier à moins d'éléments que la pile actuelle
      else {
         //Affecter les nouvelles valeurs aux éléments existants
         for (size_t i = 0; i < other.taille; ++i) {
            data[i] = other.data[i];
         }
         //Détruire les éléments en trop
         for (size_t j = other.taille; j < taille; ++j) {
            pop();
         }
      }
   }

   return *this;
}

// ... FIN DE VOTRE CODE

#endif