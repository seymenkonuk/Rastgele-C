/*
Girilen Deðerler Arasýnda Rastgele Deðer Döndürür. 
aralik deðeri (yaklaþýk) RAND_MAX*RAND_MAX deðerinden büyükse çalýþmaz. 
Kendini çaðýran fonksiyonlar kullanarak bu durumu da önleyebilirsiniz.
*/

#ifndef ESKIRASTGELE_H
#ifndef RASTGELE_H
#define ESKIRASTGELE_H
#include <stdlib.h>
#include <time.h>
#define srand(x) {srand(x); karistirildiMi = true;}

static bool karistirildiMi = false;

int rastgele(int min, int max); // min-max arasýnda rastgele sayý döndürür.

int rastgele(int min, int max) {
    if (!karistirildiMi) srand(time(NULL));
    /* 0 ile aralik arasýnda sayý üretip üstüne min eklersek olur. */
    int bolum, sayi, aralik = max - min + 1;
    /*Ama rand() fonksiyonu 0-RAND_MAX arasýnda sayý üretebilir
    bu yüzden aralik deðerini RAND_MAX gruplarýna ayýracaðýz.
    RAND_MAX = 10; aralik = 23; olduðunu varsayalým. Grup sayýmýz 3 olacak. Önce hangi 
    grupta olduðunu seçeceðiz (0-2). Sonrasýnda 0-RAND_MAX arasýnda sayý seçeceðiz.*/ 
    int parca = aralik / (RAND_MAX + 1) + 1;
    while (1) {
    /*Her sayýnýn gelme olasýlýðýnýn ayný olmasý için çabalar*/
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
