#include <iostream>

struct DNode
{
    int data;
    DNode* pPrev, *pNext;
};

void inputList(DNode* &head);
void insertAtBeginning(DNode* &pDH, int x);
void insertAfterK(DNode* pDH, int x, int k);
void insertBeforeK(DNode* pDH, int x, int k);
void outputList(DNode *head);

int main() {

    DNode* head;
    int n;

    inputList(head);

    return 0;
}

void inputList(DNode* &head) {
    int x;

    DNode *cur = nullptr;
    DNode *prev = nullptr;

    while (std::cin >> x) {
        if (x == 0) break;
        cur = new DNode;
        cur->data = x;

        if (prev == nullptr) {
            head = cur;
        } else {
            prev->pNext = cur;
        }

        cur->pPrev = prev;
        cur->pNext = nullptr;
        prev = cur;
    }
}

void insertAtBeginning(DNode* &pDH, int x) {

    DNode* newNode = new DNode;
    newNode->data = x;
    newNode->pNext = pDH;
    newNode->pPrev = nullptr;

    if (pDH != nullptr)
        pDH->pPrev = newNode;

    pDH = newNode;
}

void insertAfterK(DNode* pDH, int x, int k) {
    if (pDH == nullptr) return;
    DNode* cur = pDH;
    while (cur != nullptr && cur->data != k) {
        cur = cur->pNext;
    }

    if (cur == nullptr) return;

    DNode* newNode = new DNode;
    newNode->data = x;
    newNode->pPrev = cur;
    newNode->pNext = cur->pNext;

    if (cur->pNext)
        cur->pNext->pPrev = newNode;

    cur->pNext = newNode;
}

void insertBeforeK(DNode* &pDH, int x, int k) {
    if (pDH == nullptr) return;
    DNode* cur = pDH;
    while (cur != nullptr && cur->data != k) {
        cur = cur->pNext;
    }

    if (cur == nullptr) return;

    DNode* newNode = new DNode;
    newNode->data = x;
    newNode->pNext = cur;
    newNode->pPrev = cur->pPrev;

    if (cur->pPrev)
        cur->pPrev->pNext = newNode;
    else
        pDH = newNode;

    cur->pPrev = newNode;
}

void outputList(DNode *head) {

}