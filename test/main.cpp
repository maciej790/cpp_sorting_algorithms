#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//sortowanie b¹belkowe
void sortowanieBabelkowe(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        bool czyZamiana = false; //wartownik typu zmienna logiczna
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                czyZamiana = true;
                swap(arr[j], arr[j + 1]);
            }
        }

        if(!czyZamiana)
        {
            break;
        }
    }
}

// Sprawdzenie poprawnoœci sortowania
bool czyPosortowane(int tab[], int n) {
    for (int i = 0; i < n-1; i++) {
        if (tab[i] > tab[i+1]) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << "Sortowanie \t" << "Rozmiar_tablicy \t" << "Sredni_czas \t\n" << endl; //Nag³ówek komunikatu wyniku

    srand(time(NULL)); // Inicjalizacja generatora liczb pseudolosowych

    int rozmiaryTablic[] = {100, 1000, 10000, 20000}; // Rozmiary tablic do testowania

    //Pêtla po rozmiarach tablic
    for (int i = 0; i < 4; i++) {
        int rozmiarAktualnejTablicy = rozmiaryTablic[i];
        double czasCalkowitySortowanieBabelkowe = 0;

        // Powtórzenie pomiaru 100 razy dla ka¿dego rozmiaru tablicy
        for (int j = 0; j < 100; j++) {
            int* tab = new int[rozmiarAktualnejTablicy];

            // Wype³nienie tablicy liczbami losowymi
            for (int k = 0; k < rozmiarAktualnejTablicy; k++) {
                tab[i] = rand() % 10000; // Zakres: 0-9999
            }

            //sortowanie b¹belkowe + pomiar czasu
            clock_t startSortowanieBabelkowe = clock();
            sortowanieBabelkowe(tab, rozmiarAktualnejTablicy);
            clock_t koniecSortowanieBabelkowe = clock();
            czasCalkowitySortowanieBabelkowe += double(koniecSortowanieBabelkowe - startSortowanieBabelkowe) / CLOCKS_PER_SEC;

            if(!czyPosortowane(tab, rozmiarAktualnejTablicy))
            {
                cout << "Program nie posortowal poprawnie ktorejs z tablic !" << endl;
                delete[] tab;
                return 0;
            }

            delete[] tab;
        }

        cout << "----------------------------------------------------" << endl;
        cout << "babelkowe \t" << rozmiarAktualnejTablicy << "\t\t\t" <<  czasCalkowitySortowanieBabelkowe / 100 << "\t" << endl;
        cout << "----------------------------------------------------" << endl;
    }


    return 0;
}
