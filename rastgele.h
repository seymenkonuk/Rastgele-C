/*
Daha �yi Rastgele Fonksiyonlar�
*/

#ifndef RASTGELE_H
#ifndef ESKIRASTGELE_H
#define RASTGELE_H
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define srand(x) {srand(x); karistirildiMi = true;}

static bool karistirildiMi = false;

long long int rastgeleAralik(long long int min, long long int maks); // min maks aras�nda rastgele say� d�nd�r�r. RAND_MAX limiti yoktur.

long long int rastgeleAralik(long long int min, long long int maks) {
    if (!karistirildiMi) srand(time(NULL)); // srand daha �nce hi� �al��t�r�lmad�ysa srand �al��t�r
    if (min > maks) return rastgeleAralik(maks, min);
    unsigned long long int fark = maks - min; // min-maks aras� de�il, 0-fark aras� say� belirleyece�iz
    unsigned long long int sonuc;
    if (fark>RAND_MAX) { // rand fonksiyonu yetmiyorsa
        // Ka� bit oldu�unu bul
        int kacBit = 0;
        {
            unsigned long long int depo = fark;
            while (depo > 0) {
                depo = depo/2;
                kacBit++;
            }
        }
        while (1) {
            sonuc = 0; int i;
            // O kadar bit say� �ret
            for (i=0; i<kacBit; i++) {
                int bit = rastgeleAralik(0, 1);
                sonuc = sonuc*2+bit;
            }
            if (sonuc <= fark) break;
        }
    } else { // rand limitleri i�erisindeyse
        do {
            sonuc = rand();
        } while (sonuc > RAND_MAX - (RAND_MAX+1)%(fark+1));
        sonuc = sonuc % (fark + 1);
    }
    return sonuc + min;
}
#endif
#endif
