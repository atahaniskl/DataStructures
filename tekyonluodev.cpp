#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void menu() {
    cout << "Bagli Liste Islemleri" << endl;
    cout << "1. Bagli listeye ILK eleman ekle" << endl;
    cout << "2. Eleman ekle (basina)" << endl;
    cout << "3. Eleman ekle (araya)" << endl;
    cout << "4. Eleman ekle (sonuna)" << endl;
    cout << "5. Listele" << endl;
    cout << "6. Tersten Listele" << endl;
    cout << "7. Ilk elemani silme" << endl;
    cout << "8. Aradan bir eleman silme" << endl;
    cout << "9. Sondan bir eleman silme" << endl;
    cout << "10. CIKIS" << endl;
    cout << "Seciminiz: ";
}

void basaEkle(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
    cout << "\nIsteginiz gerceklesmistir.\n"<< endl;
}

void arayaEkle(Node** head_ref, int position, int new_data) {
    if (position < 0) {
        cout << "Gecersiz pozisyon!" << endl;
        return;
    }

    Node* new_node = new Node();
    new_node->data = new_data;

    if (position == 0) {
        basaEkle(head_ref, new_data);
        return;
    }

    Node* current = *head_ref;
    for (int i = 1; current != NULL && i < position - 1; i++) {
        current = current->next;
    }

    if (current == NULL) {
        cout << "Pozisyon liste boyutunu asti!" << endl;
        return;
    }
    cout <<"\nIsteginiz gerceklesmistir.\n"<< endl;;
    new_node->next = current->next;
    current->next = new_node;
}

void sonaEkle(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;

    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        Node* last = *head_ref;
        while (last->next != NULL)
            last = last->next;
        last->next = new_node;
    }
    cout <<"\nIsteginiz gerceklesmistir.\n"<< endl;
}
void arayaekle(Node** head_ref, int position, int new_data) {
    if (position < 0) {
        cout << "Geçersiz pozisyon!" << endl;
        return;
    }

    Node* new_node = new Node();
    new_node->data = new_data;

    if (position == 0) {
        basaEkle(head_ref, new_data);
        return;
    }

    Node* current = *head_ref;
    for (int i = 1; current != NULL && i < position - 1; i++) {
        current = current->next;
    }

    if (current == NULL) {
        cout << "Pozisyon liste boyutunu asti!" << endl;
        return;
    }
    cout <<"\nIsteginiz gerceklesmistir.\n"<< endl;

    new_node->next = current->next;
    current->next = new_node;
}

void yazdir(Node* n) {
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

void tersyazdir(Node** head_ref) {
    Node* prev = NULL;
    Node* current = *head_ref;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void basisil(Node** head_ref) {
    if (*head_ref == NULL)
        return;
    
    Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    delete temp;
    cout <<"\nIsteginiz gerceklesmistir.\n"<< endl;
}

void aradansil(Node** head_ref, int position) {
    if (*head_ref == NULL)
        return;

    if (position == 0) {
        basisil(head_ref);
        return;
    }

    Node* current = *head_ref;
    for (int i = 1; current != NULL && i < position - 1; i++) {
        current = current->next;
    }

    if (current == NULL || current->next == NULL) {
        cout << "Geçersiz pozisyon!" << endl;
        return;
    }
    cout <<"\nIsteginiz gerceklesmistir.\n"<< endl;
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

void sonusil(Node** head_ref) {
    if (*head_ref == NULL)
        return;

    if ((*head_ref)->next == NULL) {
        delete *head_ref;
        *head_ref = NULL;
        return;
    }

    Node* second_last = *head_ref;
    Node* last = (*head_ref)->next;
    while (last->next != NULL) {
        second_last = last;
        last = last->next;
    }
    cout <<"\nIsteginiz gerceklesmistir.\n"<< endl;
    second_last->next = NULL;
    delete last;
}

int main() {
    Node* head = NULL;
    int choice,data,position;

    do {
        menu();
        cin >> choice;
        cout << "\n" << endl;

        switch (choice) {
            case 1:
                cout << "Eklenecek veri: ";
                cin >> data;
                basaEkle(&head, data);
                break;
            case 2:
                cout << "Eklenecek veri: ";
                cin >> data;
                basaEkle(&head, data);
                break;
            case 3:
                cout << "Eklenecek veri: ";
                cin >> data;
                cout << "Eklenecek pozisyon: ";
                cin >> position;
                arayaEkle(&head, position, data);
                break;
            case 4:
                cout << "Eklenecek veri: ";
                cin >> data;
                sonaEkle(&head, data);
                break;
            case 5:
                yazdir(head);
                cout << "\n" << endl;
                cout << "\n" << endl;
                break;
            case 6:
                tersyazdir(&head);
                yazdir(head);
                cout << "\n" << endl;
                cout << "\n" << endl;
                break;
            case 7:
                basisil(&head);
                break;
            case 8:
                cout << "Silinecek elemanin pozisyonu: ";
                cin >> position;
                aradansil(&head, position);
                break;
            case 9:
                sonusil(&head);
                break;
            case 10:
                cout << "Programdan cikiliyor..." << endl;
                break;
            default:
                cout << "Gecersiz secim!" << endl;
        }
    } while (choice != 10);

    return 0;
}