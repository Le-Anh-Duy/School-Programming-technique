#include <iostream>

using namespace std;

struct node {
    int val;
    node* pNxt;
};

void inputStore(node* pStore) {
    node* cur = pStore;

    int inp;
    while (cin >> inp) {
        if (inp == 0) break;
        cur->pNxt = new node;
        cur = cur->pNxt;

        cur->pNxt = NULL;
        cur->val = inp;
    }
}

void displayStore(node* pStore) {
    while (pStore->pNxt) {
        pStore = pStore->pNxt;
        cout << pStore->val << ' ';
    }
    cout << '\n';
}

void deleteStore(node* store) {
    node *cur = store;
    while (cur->pNxt) {
        node* tmp = cur;
        cur = cur->pNxt;
        delete(tmp);
    }
}


int main() {

    node* store = new node;
    inputStore(store);
    displayStore(store);
    deleteStore(store);
    return 0;
}