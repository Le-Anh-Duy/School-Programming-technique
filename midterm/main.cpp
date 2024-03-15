#include <iostream>

using namespace std;

struct DNode {
    int data;
    DNode* pPrev;
    DNode* pNext;
};

void rotateK(DNode* &pDHead, int k);
DNode* elementKthFromEnd(DNode* pDHead, int k);

// Function to create a new node
DNode* createNode(int data) {
    DNode* newNode = new DNode;
    newNode->data = data;
    newNode->pPrev = nullptr;
    newNode->pNext = nullptr;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
void insertEnd(DNode* &pDHead, int data) {
    DNode* newNode = createNode(data);
    if (pDHead == nullptr) {
        pDHead = newNode;
    } else {
        DNode* temp = pDHead;
        while (temp->pNext != nullptr) {
            temp = temp->pNext;
        }
        temp->pNext = newNode;
        newNode->pPrev = temp;
    }
}

// Function to display the doubly linked list
void displayList(DNode* pDHead) {
    DNode* temp = pDHead;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->pNext;
    }
    cout << endl;
}

int main() {
    // Test the provided functions

    // Create a sample doubly linked list
    DNode* pDHead = nullptr;
    insertEnd(pDHead, 1);
    insertEnd(pDHead, 2);
    insertEnd(pDHead, 3);
    insertEnd(pDHead, 4);
    insertEnd(pDHead, 5);
    insertEnd(pDHead, 6);

    cout << "Original list: ";
    displayList(pDHead);


    // Test finding the Kth element from the end of the list
    int kthElement = 3;
    DNode* kthNode = elementKthFromEnd(pDHead, kthElement);
    if (kthNode != nullptr) {
        cout << "Element at " << kthElement << " position from end: " << kthNode->data << endl;
    } else {
        cout << "Invalid position." << endl;
    }

    // Test rotating the list
    int k = 2;
    rotateK(pDHead, k);
    cout << "List after rotating by " << k << " nodes: ";
    displayList(pDHead);
    // Free allocated memory
    while (pDHead != nullptr) {
        DNode* temp = pDHead;
        pDHead = pDHead->pNext;
        delete temp;
    }

    return 0;
}

DNode* elementKthFromEnd(DNode* pDHead, int k) {
    if (pDHead == nullptr) return nullptr;
    DNode* tail = pDHead;
    int n = 1;
    while (tail->pNext != nullptr) {
        n ++;
        tail = tail->pNext;
    }
    if (k > n) return nullptr;
    for (int i = 1; i < k; i ++) {
        tail = tail->pPrev;
    }
    return tail;
}

void rotateK(DNode* &pDHead, int k) {
    if (pDHead == nullptr) return;
    int n = 1;
    DNode* pTail = pDHead;
    while (pTail->pNext != nullptr) {
        n ++;
        pTail = pTail->pNext;
    }

    if (n == 0) return;
    k %= n;

    if (k == 0) return;

    DNode* newHead = elementKthFromEnd(pDHead, k);
    if (newHead->pPrev != nullptr) {
        newHead->pPrev->pNext = nullptr;
    }
    newHead->pPrev = nullptr;

    pTail->pNext = pDHead;
    pDHead->pPrev = pTail;

    pDHead = newHead;
}
