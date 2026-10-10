#include <string>
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
    bool veikia = true;

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
            veikia = false;
        }
        else {
            cout << "Neteisingas pasirinkimas!\n";
        }
    }

    return 0;
