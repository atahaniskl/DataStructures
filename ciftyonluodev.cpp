#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;

void menu(){
    cout << "1.Cift yonlu listeye ilk elemani ekle"<< endl;
    cout << "2.Cift yonlu listenin basina eleman ekle"<< endl;
    cout << "3.Cift yonlu listenin arasina eleman ekle"<<endl;
    cout << "4.Cift yonlu listenin sonuna eleman ekle"<<endl;        
    cout << "5.Cift yonlu listeyi listele"<<endl;
    cout << "6.Cift yonlu listeye tersten listele"<<endl;
    cout << "7.Cift yonlu listeye ilk elemani sil"<<endl;
    cout << "8.Cift yonlu listenin arasindan eleman sil"<<endl;
    cout << "9.Cift yonlu listeden son elemani silme"<<endl;
    cout << "10.CIKIS"<<endl;
    cout << "Seciminizi yapin: ";
}
void basaekle(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    newNode->prev = nullptr;

    
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}

void arayaekle(int index, int data) {
    Node* newNode = new Node();
    newNode->data = data;

    if (index == 0) {
        basaekle(data);
        return;
    }

    Node* current = head;
    int count = 0;
    while (current != nullptr && count < index - 1) {
        current = current->next;
        count++;
    }

    
    if (current == nullptr) {
        std::cout << "Gecersiz indeks!" << std::endl;
        return;
    }

    newNode->prev = current;
    newNode->next = current->next;
    if (current->next != nullptr) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

void sonaekle(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    
    if (head == nullptr) {
        head = newNode;
        return;
    }


    Node* lastNode = head;
    while (lastNode->next != nullptr) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    newNode->prev = lastNode;
}

void listele() {
    Node* temp = head;
    std::cout << "Listenin elemanlari: ";
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void terstenlistele() {
    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        current = current->next;
    }
    std::cout << "Liste ters sirada: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

void bastansil() {
    if (head == nullptr) {
        std::cout << "Liste bos!" << std::endl;
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }

    delete temp;
}

void aradansil(Node** head_ref, int key) {
    if (*head_ref == nullptr)
        return;

    Node* temp = *head_ref;

    
    if (temp != nullptr && temp->data == key) {
        *head_ref = temp->next;
        if (*head_ref != nullptr)
            (*head_ref)->prev = nullptr;
        delete temp;
        return;
    }

    
    while (temp != nullptr && temp->data != key)
        temp = temp->next;

    
    if (temp == nullptr)
        return;

    
    temp->prev->next = temp->next;

    if (temp->next != nullptr)
        temp->next->prev = temp->prev;

    delete temp;
}

void sondansil() {
    if (head == nullptr) {
        std::cout << "Liste bos!" << std::endl;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    if (current == head) {
        head = nullptr;
    } else {
        current->prev->next = nullptr;
    }

    delete current;
}

int main() {
    int choice;
    int data;

    do {
        menu();
        cin >> choice;
        cout << "\n" << endl;

        switch (choice) {
            case 1: {
                int data;
                std::cout << "Eklenecek veri: ";
                std::cin >> data;
                basaekle(data);
                break;
            }
            case 2:{
                int data;
                std::cout << "Eklenecek veri: ";
                std::cin >> data;
                basaekle(data);
                break;
            }
            case 3:{
                int index, data;
                std::cout << "Eklenecek veri: ";
                std::cin >> data;
                std::cout << "Eklenecek indeks: ";
                std::cin >> index;
                arayaekle(index, data);
        
                break;
            }
            case 4:{
                int data;
            std::cout << "Eklenecek veri (sona): ";
            std::cin >> data;
            sonaekle(data);
            break;
                break;
            }
            case 5:{
                listele();
                cout << "\n" << endl;
                break;
            }
            case 6:{
                terstenlistele();
                cout << "\n" << endl;
                break;
            }
            case 7:{
                bastansil();
                break;
            }
            case 8:{
                cout << "Silmek istediğiniz değeri girin: ";
                cin >> data;
                aradansil(&head, data);
                break;
                
                
            }
            case 9:{
                sondansil();
                break;
            }
            case 10:
                std::cout << "Programdan cikiliyor...\n";
                break;
            default:
                std::cout << "Gecersiz secim!\n";
        }
    } while (choice != 10);

    return 0;
}