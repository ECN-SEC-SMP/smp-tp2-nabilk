#include <iostream>
#include "entierlong.h"
#include "utilitaires.h"
#include "operations.h"
#include "lit_ecrit.h"  // si tu as la fonction afficheEntierLong ici

using namespace std;
t_EntierLong fibonacci(int n) ;

int main() {

    // --- Conversion de base ---
    t_EntierLong a = convertToLong(15);
    t_EntierLong b = convertToLong(10);
    t_EntierLong c = convertToLong(-9);
    t_EntierLong d = convertToLong(9);

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

    t_EntierLong mul3 = multiplication(b, d);
    cout << "b * d = ";
    afficheEntierLong(mul3);

    cout << "\n>> Test Fibonnaci" << endl;

    t_EntierLong fibo = fibonacci(60);
    cout << "60 ème terme de la suite de fibonnaci: ";
    afficheEntierLong(fibo);

    t_EntierLong fibo2 = fibonacci(59);
    cout << "\n59 ème terme de la suite de fibonnaci: ";
    afficheEntierLong(fibo2);

    t_EntierLong fibo3 = fibonacci(58);
    cout << "\n58 ème terme de la suite de fibonnaci: ";
    afficheEntierLong(fibo3);

    t_EntierLong sousfibo = soustraction(fibo,fibo2);
    cout << "\nSoustraction u60-u58= ";
    afficheEntierLong(sousfibo);
    cout << endl;
    return 0;
}

t_EntierLong fibonacci(int n) {
    // Cas de base
    if (n == 0) return convertToLong(0);
    if (n == 1) return convertToLong(1);

    t_EntierLong prev = convertToLong(0); // u0
    t_EntierLong curr = convertToLong(1); // u1
    t_EntierLong next;

    for (int i = 2; i <= n; i++) {
        next = addition(prev, curr); // un = un-1 + un-2
        prev = curr;
        curr = next;
    }

    return curr;
}
