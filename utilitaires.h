#ifndef UTILITAIRES_H
#define UTILITAIRES_H

#include "entierlong.h"
#include "lit_ecrit.h"


using namespace std;

/* Fonction qui prend un entier int en entrée
   et qui renvoie un t_EntierLong en sortie */

// Déclaration de la fonction (prototype)
t_EntierLong convertToLong(int n);
bool egalite(t_EntierLong bong, t_EntierLong zong);
bool estPlusGrand(t_EntierLong n1, t_EntierLong n2);

#endif