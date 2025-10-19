#include <iostream>
#include <cmath>
#include "entierlong.h"
using namespace std;


//Conversion d'un entier en EntierLong
t_EntierLong convertToLong(int n) {
    t_EntierLong nlong;
    int i = 0;
    int absn = abs(n);

    // Initialisation du tableau à 0
    for (int v = 0; v < MAXCHIFFRES; v++)
        nlong.chiffres[v] = 0;

    nlong.negatif = (n < 0);

    // Décomposition en chiffres
    while (absn != 0 && i < MAXCHIFFRES) {
        nlong.chiffres[i] = absn % 10;
        absn /= 10;
        i++;
    }

    return nlong;
}


//egalite : teste si deux t_EntierLong sont identiques
bool egalite(t_EntierLong n1, t_EntierLong n2) {
    if (n1.negatif != n2.negatif)
        return false;

    for (int i = 0; i < MAXCHIFFRES; i++) {
        if (n1.chiffres[i] != n2.chiffres[i])
            return false;
    }

    return true;
}

//Test si deux entiers pour savoir quel est le plus grand
bool estPlusGrand(t_EntierLong n1, t_EntierLong n2) {
    //Gestion des signes
    if (n1.negatif != n2.negatif)
        return !n1.negatif; // un nombre positif est toujours plus grand qu’un négatif

    //Trouver la position du chiffre le plus significatif (comme ton indice 0 = chiffre le moins significatif)
    int i1 = MAXCHIFFRES - 1;
    while (i1 > 0 && n1.chiffres[i1] == 0) i1--;

    int i2 = MAXCHIFFRES - 1;
    while (i2 > 0 && n2.chiffres[i2] == 0) i2--;

    //Comparaison par longueur (nombre de chiffres significatifs)
    if (i1 != i2) {
        if (!n1.negatif)
            return i1 > i2;   // positif : plus de chiffres = plus grand
        else
            return i1 < i2;   // négatif : plus de chiffres = plus petit
    }

    //Même longueur : comparer du plus significatif vers le moins
    for (int i = i1; i >= 0; i--) {
        if (n1.chiffres[i] > n2.chiffres[i])
            return !n1.negatif; // positif → normal ; négatif → inversé
        if (n1.chiffres[i] < n2.chiffres[i])
            return n1.negatif;  // idem
    }

    //Ils sont égaux
    return false;
}
