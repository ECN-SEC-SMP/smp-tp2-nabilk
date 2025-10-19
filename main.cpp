#include <iostream>
#include "entierlong.h"
#include "utilitaires.h"
#include "operations.h"
#include "lit_ecrit.h"  // si tu as la fonction afficheEntierLong ici

using namespace std;

int main() {

    // --- Conversion de base ---
    t_EntierLong a = convertToLong(12);
    t_EntierLong b = convertToLong(-10);
    t_EntierLong c = convertToLong(6);
    t_EntierLong d = convertToLong(6);

    cout << "\n>> Test de conversion :" << endl;
    cout << "a = "; afficheEntierLong(a);
    cout << "b = "; afficheEntierLong(b);
    cout << "c = "; afficheEntierLong(c);
    cout << "d = "; afficheEntierLong(d);

    // --- Test égalité ---
    cout << "\n>> Test egalite :" << endl;
    cout << "a == b ? " << (egalite(a,b) ? "Vrai" : "Faux") << endl;
    cout << "c == d ? " << (egalite(c,d) ? "Vrai" : "Faux") << endl;

    // --- Test estPlusGrand ---
    cout << "\n>> Test estPlusGrand :" << endl;
    cout << "a > b ? " << (estPlusGrand(a,b) ? "Vrai" : "Faux") << endl;
    cout << "b > a ? " << (estPlusGrand(b,a) ? "Vrai" : "Faux") << endl;
    cout << "c > d ? " << (estPlusGrand(c,d) ? "Vrai" : "Faux") << endl;

    // --- Test addition ---
    cout << "\n>> Test addition :" << endl;
    t_EntierLong add1 = addition(a,b);
    cout << "a + b = ";
    afficheEntierLong(add1);

    t_EntierLong add2 = addition(b,c);
    cout << "b + c = ";
    afficheEntierLong(add2);

    t_EntierLong add3 = addition(c,d);
    cout << "c + d = ";
    afficheEntierLong(add3);

    // --- Test soustraction ---
    cout << "\n>> Test soustraction :" << endl;
    t_EntierLong sub1 = soustraction(a,b);
    cout << "a - b = ";
    afficheEntierLong(sub1);

    t_EntierLong sub2 = soustraction(b,a);
    cout << "b - a = ";
    afficheEntierLong(sub2);

    t_EntierLong sub3 = soustraction(c,d);
    cout << "c - d = ";
    afficheEntierLong(sub3);

    // --- Test multiplication ---
    cout << "\n>> Test multiplication :" << endl;
    t_EntierLong mul1 = multiplication(a,b);
    cout << "a * b = ";
    afficheEntierLong(mul1);

    t_EntierLong mul2 = multiplication(c,d);
    cout << "c * d = ";
    afficheEntierLong(mul2);

    t_EntierLong mul3 = multiplication(convertToLong(-5), convertToLong(-4));
    cout << "-5 * -4 = ";
    afficheEntierLong(mul3);

    return 0;
}
