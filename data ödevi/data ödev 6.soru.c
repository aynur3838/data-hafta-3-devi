#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//SORU6: LÝSTEDE EN UZUN ÝSMÝN OLDUÐU KAYDI YAZDIRAN FONKSÝYON:

// Öðrenci bilgileri tanýmlamalarý:
struct Student {
    int studentNumber;
    char name[50];
    int age;
    struct Student *next;
};

// Baðlý liste üzerinde dolaþarak en uzun ismi bulan fonksiyon
void findLongestName(struct Student *head) {
    struct Student *current = head;
    int maxLength = 0;
    char *longestName;

    while (current != NULL) {
        if (strlen(current->name) > maxLength) {
            maxLength = strlen(current->name);
            longestName = current->name;
        }
        current = current->next;
    }

    // En uzun isme sahip kaydý yazdýr
    printf("En uzun isme sahip kayit: %s\n", longestName);
}

// Baðlý liste örneði oluþturur:
struct Student* createSampleLinkedList() {
    struct Student *head = NULL;
    struct Student *second = NULL;
    struct Student *third = NULL;

    // Bellekte yer ayrýlýr:
    head = (struct Student *)malloc(sizeof(struct Student));
    second = (struct Student *)malloc(sizeof(struct Student));
    third = (struct Student *)malloc(sizeof(struct Student));

    // Veri atamasý yapar:
    head->studentNumber = 1;
    strcpy(head->name, "Alper");
    head->age = 20;
    head->next = second;

    second->studentNumber = 2;
    strcpy(second->name, "Gülben");
    second->age = 21;
    second->next = third;

    third->studentNumber = 3;
    strcpy(third->name, "Mustafa");
    third->age = 22;
    third->next = NULL;

    // En uzun ismi bulan fonksiyonu çaðýr
    findLongestName(head);

    return head;
}

// Ana fonksiyon
int main() {
    // Örnek baðlý listeyi oluþtur
    struct Student *list = createSampleLinkedList();

    // Belleði serbest býrak
    free(list);
    
    return 0;
}
