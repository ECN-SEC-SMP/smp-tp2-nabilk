#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "entierlong.h"
#include "lit_ecrit.h"


using namespace std;

// Déclaration de la fonction (prototype)
t_EntierLong addition(t_EntierLong a, t_EntierLong b);
t_EntierLong soustraction(t_EntierLong a, t_EntierLong b) ;
bool estStrictementSuperieur(t_EntierLong a, t_EntierLong b) ;
t_EntierLong multiplication(t_EntierLong a, t_EntierLong b);

#endif