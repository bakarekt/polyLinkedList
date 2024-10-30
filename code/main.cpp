#include <iostream>
using namespace std;

struct Node {
    int soMu;
    double heSo;
    Node* next;
};

struct List {
    Node* firstNode;
};

void listInit(List* list) {
    list->firstNode = 0;
}

void listAddFirst(List* list, int soMu, double heSo) {
    Node* newNode = new Node;
    newNode->soMu = soMu;
    newNode->heSo = heSo;
    newNode->next = list->firstNode;
    list->firstNode = newNode;
}

void listRemoveFirst(List* list) {
    Node* temp = list->firstNode;
    list->firstNode = list->firstNode->next;
    delete temp;
}

void createNode(List* list, int n) {
    for (int i = 0; i < n; i++) {
        double heSo;
        int soMu = i;
        cout << "Nhap he so cua x^" << i << ": ";
        cin >> heSo;

        listAddFirst(list, soMu, heSo);

        if (heSo == 0) {
            listRemoveFirst(list);
        }
    }
}

void listDisplay(List* list) {
    Node* node = list->firstNode;
    while (node != 0) {
        cout << node->heSo << "x^" << node->soMu;
        if (node->next != 0) {
            cout << " + ";
        }
        node = node->next;
    }
    cout << endl;
}

int main(){
    Node poly;
    int n;
    cout << "Nhap bac cua da thuc: "; cin >> n;
    List list;
    listInit(&list);
    createNode(&list, n);
    listDisplay(&list);
    return 0;
}