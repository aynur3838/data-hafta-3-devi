#include<stdio.h>

//SORU4: Listede ��renci ad�na g�re kay�t arama yapan fonksiyonu yaz�n�z

// ��renci yap�s�
struct Student {
    char name[50];
    int age;
    // Di�er ��renci bilgilerini buraya ekleyebilirsiniz.
};

// ��renci listesi
struct Student students[] = {
    {"remzi", 20},
    {"emir", 22},
    {"aynur", 21},
    {"kerem", 19},
    // Daha fazla ��renci eklemek i�in bu yap�y� kullanabilirsiniz.
};

int numberOfStudents = sizeof(students) / sizeof(students[0]);

// ��renci ad�na g�re arama yapacak fonksiyon
void searchStudentByName(const char *searchName) {
    int found = 0;
    int i;
    for ( i = 0; i < numberOfStudents; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("O�renci Bulundu: %s, Yasi: %d\n", students[i].name, students[i].age);
            found = 1;
        }
    }

    if (!found) {
        printf("��renci bulunamad�: %s\n", searchName);
    }
}

int main() {
    char nameToSearch[50]; // Aranacak ��rencinin ad�n� saklamak i�in bir dizi olu�turun
    printf("Aranacak ogrencinin ad�n� girin: ");
    scanf("%s", nameToSearch); // Kullan�c�dan ��renci ad�n� al�n
    searchStudentByName(nameToSearch);

    return 0;
}
