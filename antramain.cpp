#include <string>
#include <iostream>
#include <cmath>
using namespace std;

string vardai[100];
int paz[100][10];
int kiek[100];
int mokKiek = 0;

void meniu();
void ivestMok();
void visi();
void vienas();
void atnauj();
void vidurkis();
void salint();

int main() {
    int pasirinkimas;
    bool veikia = true; // apie tai kalbu (cia sau pasilieku)

    while (veikia == true) {
        meniu();
        cin >> pasirinkimas;

        if (pasirinkimas == 1) {
            ivestMok();
        }
        else if (pasirinkimas == 2) {
            visi();
        }
        else if (pasirinkimas == 3) {
            vienas();
        }
        else if (pasirinkimas == 4) {
            atnauj();
        }
        else if (pasirinkimas == 5) {
            vidurkis();
        }
        else if (pasirinkimas == 6) {
            salint();
        }
        else if (pasirinkimas == 7) {
            veikia = false; // čia vietoj to, kad naudoti dar vieną if masyva, tiesiog while'as boolo naudojamas***
        }
        else {
            cout << "Neteisingas pasirinkimas!\n";
        }
    }

    return 0;
}
void meniu() {
    cout << "\n1. Ivesti mokini\n";
    cout << "2. Perziureti visus mokinius\n";
    cout << "3. Perziureti mokini\n";
    cout << "4. Atnaujinti pazymi\n";
    cout << "5. Mokinio vidurkis\n";
    cout << "6. Pasalinti mokini\n";
    cout << "7. Iseiti\n";
    cout << "Pasirinkite: ";
}

void ivestMok() { //mok+paz
}

void visi() { //rodysu visus mokinius
}

void vienas() { //tik viena mokiny parodyt
}

void atnauj() { //pakeitimas pazymku
}

void vidurkis() {//vidurkis pazymiu
}

void salint() {//pasalinimas mokynio xdd
}
