#include <iostream>

using namespace std;

struct node {
    int val;
    node* pNxt;
};

void inputStore(node* &pStore);
void displayStore(node* pStore);
void deleteStore(node* pStore);
void insertStore(node *pStore, int x, int k);

int main() {

    node* store = NULL;
    
    inputStore(store);

    insertStore(store, 10, 4);
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
void insertStore(node *pStore, int x, int k) {
    while (pStore != nullptr) {
        if (pStore->val == k) {
            node *tmp = pStore->pNxt;
            pStore->pNxt = new node;
            pStore->pNxt->val = x;
            pStore->pNxt->pNxt = tmp;
            return;
        }

        pStore = pStore->pNxt;
    }
    return;
    
}