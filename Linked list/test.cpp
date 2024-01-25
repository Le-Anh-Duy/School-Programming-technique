#include <iostream>

using namespace std;

struct node {
    int val;
    node* pNxt;
};

void inputStore(node* &pStore) {
    node* cur = pStore;

    int inp;
    while (cin >> inp) {
        if (inp == 0) break;
        if (cur == NULL) {
            cur = new node;
            cur->val = inp;
            cur->pNxt = nullptr;
            pStore = cur;
            continue;
        }

        cur->pNxt = new node;
        cur = cur->pNxt;

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


int main() {

    node* store = NULL;
    inputStore(store);
    displayStore(store);
    deleteStore(store);
    return 0;
}