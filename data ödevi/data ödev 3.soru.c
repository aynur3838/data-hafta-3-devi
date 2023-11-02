#include<stdio.h>
//SORU3: ÖÐRENCÝ NUMARASI,ÝSÝM VE YAÞININ SAKLI TUTULDUÐU,LÝSTEDEKÝ TÜM DÜÐÜMLERÝ DOLAÞAN,ÖÐRENCÝ BÝLGÝLERÝNÝN TÜMÜNÜ EKRANA YAZAN VE SAYAN FONKSÝYONU YAZINIZ:

//Öðreci özellikleri:

struct Ogrenci {
    int ogrenci_no;
    char isim[50];
    int yas;
    struct Ogrenci* sonraki;
};

//Öðrenci listeye eklenir:
void ogrenciEkle(struct Ogrenci** bas, int no, char isim[], int yas) {
    struct Ogrenci* yeni_ogrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    yeni_ogrenci->ogrenci_no = no;
    strcpy(yeni_ogrenci->isim, isim);
    yeni_ogrenci->yas = yas;
    yeni_ogrenci->sonraki = *bas;
    *bas = yeni_ogrenci;
}
//Liste yazdýrýlýr:
void ogrenciListesiniYazdir(struct Ogrenci* bas) {
    int sira = 1;
    struct Ogrenci* suanki = bas;
    while (suanki != NULL) {
        printf(" %d-> Isim: %s    Yas: %d    Ogrenci_no: %d\n", sira, suanki->isim, suanki->yas, suanki->ogrenci_no);
        sira++;
        suanki = suanki->sonraki;
    }
}

int main() {
    struct Ogrenci* bas = NULL;

    // öðrenci bilgileri eklenir: 
    ogrenciEkle(&bas, 209, "kerem", 19);
    ogrenciEkle(&bas, 207, "rumeysa", 15);
    ogrenciEkle(&bas, 205, "hakan", 16);
    ogrenciEkle(&bas, 203, "sevde", 20);
    ogrenciEkle(&bas, 201, "aynur", 21);

    // Öðrenci listesini yazdýrma fonksiyonunu çaðýrýlýr:
    ogrenciListesiniYazdir(bas);


    return 0;
}
