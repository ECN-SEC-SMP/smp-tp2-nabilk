#include <iostream>
#include "entierlong.h"
#include "utilitaires.h"
#include "operations.h"
using namespace std;

/* 
   Contient les fonctions d’opérations arithmétiques 
   sur les t_EntierLong :
   - addition
   - soustraction
   - multiplication
*/

//Fonction additiondeSigneQuelconque
t_EntierLong addition(t_EntierLong a, t_EntierLong b) {
    t_EntierLong res;
    int retenue = 0;

    // On initialise le résultat à 0
    for (int i = 0; i < MAXCHIFFRES; i++)
        res.chiffres[i] = 0;

    // Cas 1 : les deux ont le même signe 
    if (a.negatif == b.negatif) {
        for (int i = 0; i < MAXCHIFFRES; i++) {
            int somme = a.chiffres[i] + b.chiffres[i] + retenue;
            // on a pas de retenue dans ce cas
            if (somme < 10) {
                res.chiffres[i] = somme;
                retenue = 0;
            } 
            else {
                res.chiffres[i] = somme - 10;
                retenue = 1;
            }
        }

        res.negatif = a.negatif;
    } 

    //  Cas 2 : signes différents 
    else {
        // a positif, b négatif → a + (-b) = a - b
        if (!a.negatif && b.negatif) {
            b.negatif = false;
            res = soustraction(a, b);
        }
        // a négatif, b positif → (-a) + b = b - a
        else if (a.negatif && !b.negatif) {
            a.negatif = false;
            res = soustraction(b, a);
        }
    }

    return res;
}



// fonction soustractionSigneQuelconque
t_EntierLong soustraction(t_EntierLong a, t_EntierLong b) {
    t_EntierLong res;
    int retenue = 0;

    for (int i = 0; i < MAXCHIFFRES; i++)
        res.chiffres[i] = 0;

    // Cas 1 : a et b positifs
    if (!a.negatif && !b.negatif) {
        if (estPlusGrand(a, b)) {
            for (int i = 0; i < MAXCHIFFRES; i++) {
                int diff = a.chiffres[i] - b.chiffres[i] - retenue;
                if (diff < 0) {
                    diff += 10;
                    retenue = 1;
                } else {
                    retenue = 0;
                }
                res.chiffres[i] = diff;
            }
            res.negatif = false;
        } else {
            for (int i = 0; i < MAXCHIFFRES; i++) {
                int diff = b.chiffres[i] - a.chiffres[i] - retenue;
                if (diff < 0) {
                    diff += 10;
                    retenue = 1;
                } else {
                    retenue = 0;
                }
                res.chiffres[i] = diff;
            }
            res.negatif = true;
        }
    } 

    // Cas 2 : a positif, b négatif → a - (-b) = a + b
    else if (!a.negatif && b.negatif) {
        b.negatif = false;
        res = addition(a, b);
    } 

    // Cas 3 : a négatif, b positif → (-a) - b = -(a + b)
    else if (a.negatif && !b.negatif) {
        a.negatif = false;
        res = addition(a, b);
        res.negatif = true;
    } 

    // Cas 4 : les deux négatifs → (-a) - (-b) = b - a
    else {
        a.negatif = false;
        b.negatif = false;
        res = soustraction(b, a);
    }

    return res;
}

// fonction multiplication
t_EntierLong multiplication(t_EntierLong a, t_EntierLong b) {
    t_EntierLong res;
    

    // Initialisation à 0
    for (int i = 0; i < MAXCHIFFRES; i++){
        res.chiffres[i] = 0;
    }

    int  na = 0;
    int  nb = 0;
    int  puissance = 1;
    
    // indice 0 *1 indice 1*10
    for (int i = 0; i < MAXCHIFFRES; i++) {
        na += a.chiffres[i] * puissance;
        nb += b.chiffres[i] * puissance;
        puissance *= 10;
    }
    
    // ---- Multiplication classique 
    int produit = na * nb;
    if(a.negatif!=b.negatif){
        produit=produit*-1;
    }
    

    // ---- Conversion en t_EntierLong ----
    res= convertToLong(produit);

    return res;
}




