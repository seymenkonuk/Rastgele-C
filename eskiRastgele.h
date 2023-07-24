/*
Girilen De�erler Aras�nda Rastgele De�er D�nd�r�r. 
aralik de�eri (yakla��k) RAND_MAX*RAND_MAX de�erinden b�y�kse �al��maz. 
Kendini �a��ran fonksiyonlar kullanarak bu durumu da �nleyebilirsiniz.
*/

#ifndef ESKIRASTGELE_H
#ifndef RASTGELE_H
#define ESKIRASTGELE_H
#include <stdlib.h>
#include <time.h>
#define srand(x) {srand(x); karistirildiMi = true;}

static bool karistirildiMi = false;

int rastgele(int min, int max); // min-max aras�nda rastgele say� d�nd�r�r.

int rastgele(int min, int max) {
    if (!karistirildiMi) srand(time(NULL));
    /* 0 ile aralik aras�nda say� �retip �st�ne min eklersek olur. */
    int bolum, sayi, aralik = max - min + 1;
    /*Ama rand() fonksiyonu 0-RAND_MAX aras�nda say� �retebilir
    bu y�zden aralik de�erini RAND_MAX gruplar�na ay�raca��z.
    RAND_MAX = 10; aralik = 23; oldu�unu varsayal�m. Grup say�m�z 3 olacak. �nce hangi 
    grupta oldu�unu se�ece�iz (0-2). Sonras�nda 0-RAND_MAX aras�nda say� se�ece�iz.*/ 
    int parca = aralik / (RAND_MAX + 1) + 1;
    while (1) {
    /*Her say�n�n gelme olas�l���n�n ayn� olmas� i�in �abalar*/
        do {
            bolum = rand();
        } while (bolum > RAND_MAX - ((RAND_MAX+1) % parca) );
        bolum %= parca; 
        sayi = rand();
        sayi = sayi + bolum * (RAND_MAX+1) + min;
        if (sayi <= max) return sayi;
    } 
}
#endif
#endif
