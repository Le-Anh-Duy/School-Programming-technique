#include <iostream>

using namespace std;

struct node {
    int val;
    node* pNxt;
};

void inputStore(node* &pStore);
void displayStore(node* pStore);
void deleteStore(node* pStore);
void insertXafterK(node *pStore, int x, int k);
void insertXbeforeK(node *pStore, int x, int k);

int main() {

    node* store = NULL;
    
    inputStore(store);

    insertXafterK(store, 10, 4);
    displayStore(store);
    deleteStore(store);
    return 0;
}

void inputStore(node* &pStore) {
    node* cur = pStore;

    int inp;
    while (cin >> inp) {
        if (inp == 0) break;
        if (cur == NULL) {
            pStore = new node;
            cur = pStore;
        } else {
            cur->pNxt = new node;
            cur = cur->pNxt;
        }

        cur->pNxt = NULL;
        cur->val = inp;
    }

}

void displayStore(node* pStore) {
    while (pStore) {
        cout << pStore->val << ' ';
        pStore = pStore->pNxt;
    }
    cout << '\n';
}

void deleteStore(node* pStore) {
    if (!pStore) return;
    while (pStore != nullptr) {
        node* tmp = pStore->pNxt;
        delete(pStore);
        pStore = tmp;
    }
}
void insertXafterK(node *pStore, int x, int k) {
    while (pStore != nullptr) {
        if (pStore->val == k) {
            node *tmp = pStore->pNxt;
            pStore->pNxt = new node;
            pStore = pStore->pNxt;
            pStore->val = x;
            pStore->pNxt = tmp;
            return;
        }
        pStore = pStore->pNxt;
    }
    return;
    
}

void insertXbeforeK(node *&pStore, int x, int k) {
    node* prev = nullptr;
    node* cur = pStore;
    while (cur != nullptr && cur->val != k) {
        prev = cur;
        cur = cur->pNxt;
    }

    if (cur == nullptr) return;
    
    if (prev == nullptr) {
        prev = new node;
        pStore = prev;
    } else {
        prev->pNxt = new node;
        prev = prev->pNxt;
    }

    prev->val = x;
    prev->pNxt = cur;
}
