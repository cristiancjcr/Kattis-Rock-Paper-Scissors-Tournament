#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, k;
    bool t = true;

    while (cin >> n) {
        if (n == 0)
            break;
        else {
            cin >> k; //nr-ul de runde 

            if (!t)
                cout << endl; //dacă nu suntem la primul set de jucatori, afisam un rand gol
            else
                t = false;

            float players[n];    //va retine numarul de meciuri castigate de fiecare jucator
            float same[n];       //va retine numarul de meciuri care au fost remize pentru fiecare jucator
            float different[n];  //va retine daca fiecare jucator a jucat cel putin o data cu un alt jucator

            //initializam toate elementele din tablourile 'players', 'same' si 'different' la 0
            for (int i = 0; i < n; i++) {
                players[i] = 0;
                same[i] = 0;
                different[i] = 0;
            }

            int p1, p2;
            string m1, m2;
            int x = (k * n * (n - 1)) / 2; //calculam numarul total de meciuri care vor avea loc intre toti jucatorii

            for (int i = 0; i < x; i++) {
                cin >> p1 >> m1 >> p2 >> m2;
                if (m1 == "rock" && m2 == "paper") {
                    players[p2 - 1] += 1;
                    same[p1 - 1] += 1;
                    different[p2 - 1] = 1;
                    different[p1 - 1] = 1;
                } else if (m1 == "rock" && m2 == "scissors") {
                    players[p1 - 1] += 1;
                    same[p2 - 1] += 1;
                    different[p2 - 1] = 1;
                    different[p1 - 1] = 1;
                } else if (m1 == "paper" && m2 == "scissors") {
                    players[p2 - 1] += 1;
                    same[p1 - 1] += 1;
                    different[p2 - 1] = 1;
                    different[p1 - 1] = 1;
                } else if (m1 == "paper" && m2 == "rock") {
                    players[p1 - 1] += 1;
                    same[p2 - 1] += 1;
                    different[p2 - 1] = 1;
                    different[p1 - 1] = 1;
                } else if (m1 == "scissors" && m2 == "paper") {
                    players[p1 - 1] += 1;
                    same[p2 - 1] += 1;
                    different[p2 - 1] = 1;
                    different[p1 - 1] = 1;
                } else if (m1 == "scissors" && m2 == "rock") {
                    players[p2 - 1] += 1;
                    same[p1 - 1] += 1;
                    different[p2 - 1] = 1;
                    different[p1 - 1] = 1;
                }
            }

            for (int i = 0; i < n; i++) {
                float d = (float)(players[i] + same[i]); //suma pe care o covertim intr-un tip 'float'
                if (different[i] == 0)
                    cout << "-" << endl; //daca jucatorul nu a jucat cu niciun alt jucator, afisam "-"
                else
                    cout << setprecision(3) << fixed << (players[i]) / (d) << endl; //meciuri castigate
            }
        }
    }

    return 0;
}
