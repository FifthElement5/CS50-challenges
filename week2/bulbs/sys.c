#include <stdio.h>

#define N 100

void przeksztalcPodstawe(int liczba, int podstawa) {
    // Tablica do przechowywania wyniku
     int wynik[N];
    int s = 0;

    if (podstawa == 1)
        {
        wynik[s] = liczba * podstawa;
        printf("\nWynik w podsatwie 1: ");
        for (int k=0; k<liczba; k++)
        {

            printf("1");
        }
        }
     else
     {

    // Konwersja liczby do nowej podstawy
    while (liczba > 0) {
        wynik[s] = liczba % podstawa;
        liczba /= podstawa;
        s++;

    }


    // Wyświetlenie wyniku w odwrotnej kolejności
    printf("Wynik w podstawie %d: ", podstawa);
    for (int i = s - 1; i >= 0; i--) {
        // Wypisz wynik, możesz dodać warunki dla liczb > 9 w zależności od potrzeb
        printf("%c", (wynik[i] < 10) ? (wynik[i] + '0') : (wynik[i] + 'A' - 10));
    }
    printf("\n");
    }
}

void binarny(int liczba)
{
     int j, wynik[N];
    int s = 0;
    while (liczba > 0) {
        wynik[s] = liczba % 2;
        liczba /= 2;
        s++;

    }
    for (j = s - 1; j >= 0; j--)
    {
        printf("%d", wynik[j]);
    }

}

int main() {
    // Przekształć liczbę 16 do systemu o podstawie 5

    binarny(10);
    przeksztalcPodstawe(10, 1);

    return 0;
}
