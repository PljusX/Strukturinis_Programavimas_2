#include <string>
#include <iostream>
#include <cmath>
#include <iomanip>
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

void ivestMok() {
    if (mokKiek >= 100) {
        cout << "Mokiniu sarasas pilnas!\n";
    }
    else {
        cout << "Iveskite mokinio varda: ";
        cin >> vardai[mokKiek];

        cout << "Kiek pazymiu turi mokinys? ";
        cin >> kiek[mokKiek];

        while (kiek[mokKiek] < 0 || kiek[mokKiek] > 10) {
            cout << "Iveskite skaiciu nuo 0 iki 10: ";
            cin >> kiek[mokKiek];
        }

        for (int i = 0; i < kiek[mokKiek]; i++) {
            cout << "Iveskite " << i + 1 << " pazymi: ";
            cin >> paz[mokKiek][i];

            while (paz[mokKiek][i] < 1 ||
                   paz[mokKiek][i] > 10) {
                cout << "Pazymys turi buti nuo 1 iki 10: ";
                cin >> paz[mokKiek][i];
            }
        }

        mokKiek++;

        cout << "Mokinys pridetas!\n";
    }
}

void visi() {
    if (mokKiek == 0) {
        cout << "Mokiniu sarasas tuscias!\n";
    }
    else {
        for (int i = 0; i < mokKiek; i++) {
            cout << "\nMokinys: " << vardai[i] << endl;
            cout << "Pazymiai: ";

            for (int j = 0; j < kiek[i]; j++) {
                cout << paz[i][j] << " ";
            }

            cout << endl;
        }
    }
}

void vienas() {
    if (mokKiek == 0) {
        cout << "Mokiniu sarasas tuscias!\n";
    }
    else {
        int nr;

        cout << "Iveskite mokinio numeri nuo 1 iki "
             << mokKiek << ": ";
        cin >> nr;

        while (nr < 1 || nr > mokKiek) {
            cout << "Neteisingas numeris! Bandykite dar karta: ";
            cin >> nr;
        }

        cout << "\nMokinys: " << vardai[nr - 1] << endl;
        cout << "Pazymiai: ";

        for (int i = 0; i < kiek[nr - 1]; i++) {
            cout << paz[nr - 1][i] << " ";
        }

        cout << endl;
    }
}

void atnauj() {
    if (mokKiek == 0) {
        cout << "Mokiniu sarasas tuscias!\n";
    }
    else {
        int nr, pnr; // nr yra mokinio eilute, o pnr yra pazymio stulpelis*

        cout << "Iveskite mokinio numeri nuo 1 iki "
             << mokKiek << ": ";
        cin >> nr;

        while (nr < 1 || nr > mokKiek) {
            cout << "Neteisingas numeris! Bandykite dar karta: ";
            cin >> nr;
        }

        if (kiek[nr - 1] == 0) {
            cout << "Mokinys neturi pazymiu!\n";
        }
        else {
            cout << "Pazymiai: ";

            for (int i = 0; i < kiek[nr - 1]; i++) {
                cout << i + 1 << ". " << paz[nr - 1][i] << endl;
            }

            cout << "Kuri pazymi norite pakeisti? ";
            cin >> pnr;

            while (pnr < 1 || pnr > kiek[nr - 1]) {
                cout << "Neteisingas pazymio numeris! Bandykite dar karta: ";
                cin >> pnr;
            }

            cout << "Iveskite nauja pazymi (1-10): ";
            cin >> paz[nr - 1][pnr - 1];

            while (paz[nr - 1][pnr - 1] < 1 || paz[nr - 1][pnr - 1] > 10) {
                cout << "Pazymys turi buti nuo 1 iki 10: ";
                cin >> paz[nr - 1][pnr - 1];
            }

            cout << "Pazymys pakeistas!\n";
        }
    }
}

void vidurkis() {
    if (mokKiek == 0) {
        cout << "Mokiniu sarasas tuscias!\n";
    }
    else {
        int nr;
        int suma = 0;
        double vid;

        cout << "Iveskite mokinio numeri nuo 1 iki "
             << mokKiek << ": ";
        cin >> nr;

        while (nr < 1 || nr > mokKiek) {
            cout << "Neteisingas numeris! Bandykite dar karta: ";
            cin >> nr;
        }

        if (kiek[nr - 1] == 0) {
            cout << "Mokinys neturi pazymiu!\n";
        }
        else {
            for (int i = 0; i < kiek[nr - 1]; i++) {
                suma = suma + paz[nr - 1][i];
            }

            vid = (double)suma / kiek[nr - 1];

            cout << fixed << setprecision(2) << "Mokinio " << vardai[nr - 1] << " vidurkis: " << vid << endl;
        }
    }
}

void salint() {
    if (mokKiek == 0) {
        cout << "Mokiniu sarasas tuscias!\n";
    }
    else {
        int nr;

        cout << "Iveskite mokinio numeri nuo 1 iki "
             << mokKiek << ": ";
        cin >> nr;

        while (nr < 1 || nr > mokKiek) {
            cout << "Neteisingas numeris! Bandykite dar karta: ";
            cin >> nr;
        }

        for (int i = nr - 1; i < mokKiek - 1; i++) {
            vardai[i] = vardai[i + 1];
            kiek[i] = kiek[i + 1];

            for (int j = 0; j < 10; j++) {
                paz[i][j] = paz[i + 1][j];
            }
        }

        mokKiek--; // susimazinu kieki totaliu mokiniu, nes kadangi persikeliau pvz antra i pirma ir tada nuo 0 iki 1 eina

        cout << "Mokinys pasalintas!\n";
    }
}
//sau; g++ antramain.cpp -o programa.exe 
// .\programa.exe
