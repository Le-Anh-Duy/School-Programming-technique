#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* pNext;
};

void rotateKSteps(Node* &pHead, int k) {
    if (pHead == nullptr) return;
    int n = 1;
    Node* cur = pHead;
    while (cur->pNext) n ++, cur = cur->pNext;
    cur->pNext = pHead;

    if (k < 0) k = n - (-k) % n; else k = k % n;

    for (int i = 0; i < n - k; i ++) {
        pHead = pHead->pNext;
        cur = cur->pNext;
    }

    cur->pNext = nullptr;
}

void removeBiggest(Node* &pHead) {
    if (pHead == nullptr) return;
    Node* cur = pHead;
    int biggest = pHead->data;
    while (cur) {
        if (cur->data > biggest)
            biggest = cur->data;
        cur = cur->pNext;
    }

    cur = pHead;
    Node* prev = NULL;
    while (cur) {
        Node* next = cur->pNext;
        if (cur->data == biggest) {
            if (prev)
                prev->pNext = next;
            if (cur == pHead)
                pHead = next;
            delete cur;
        } else prev = cur;
        cur = next;
    }
}

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->pNext = nullptr;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertEnd(Node* &pHead, int data) {
    Node* newNode = createNode(data);
    if (pHead == nullptr) {
        pHead = newNode;
    } else {
        Node* temp = pHead;
        while (temp->pNext != nullptr) {
            temp = temp->pNext;
        }
        temp->pNext = newNode;
    }
}

// Function to display the linked list
void displayList(Node* pHead) {
    Node* temp = pHead;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->pNext;
    }
    cout << endl;
}

int main() {
    // Create a sample linked list
    Node* pHead = nullptr;
    insertEnd(pHead, 5);
    insertEnd(pHead, 5);
    insertEnd(pHead, 5);
    insertEnd(pHead, 1);
    insertEnd(pHead, 2);
    insertEnd(pHead, 3);
    insertEnd(pHead, 5);
    insertEnd(pHead, 5);
    insertEnd(pHead, 5);
    insertEnd(pHead, 4);
    insertEnd(pHead, 5);
    insertEnd(pHead, 1);
    insertEnd(pHead, 4);
    insertEnd(pHead, 5);
    insertEnd(pHead, 5);


    cout << "Original list: ";
    displayList(pHead);

    // Rotate the list by k steps
    // int k = -1;
    // rotateKSteps(pHead, k);
    cout << "List after removed: ";
    removeBiggest(pHead);
    displayList(pHead);

    // Free allocated memory
    while (pHead != nullptr) {
        Node* temp = pHead;
        pHead = pHead->pNext;
        delete temp;
    }

    return 0;
}
