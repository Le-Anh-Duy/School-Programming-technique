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
void insertXbeforeK(node* &pStore, int x, int k);
void deleteFirstX(node* &pStore, int x);
void deleteAllX(node* &pStore, int x);
void reverseList(node* &pStore);

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
    if (pStore == nullptr) {
        cout << "The list cotains no element\n";
        return;
    }
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
    if (pStore == nullptr) return;

    if (pStore->val == k) {
        node* newNode = new node;
        newNode->val = x;
        newNode->pNxt = pStore;
        pStore = newNode;
        return;
    }

    node* cur = pStore;
    while (cur->pNxt != nullptr && cur->pNxt->val != k) 
        cur = cur->pNxt;

    if (cur->pNxt == nullptr) return;

    node* nxt = new node;
    nxt->val = x;
    nxt->pNxt = cur->pNxt;
    cur->pNxt = nxt;
}

void deleteFirstX(node* &pStore, int x) {
    if (pStore == nullptr) return;
    if (pStore->val == x) {
        node* tmp = pStore;
        pStore = pStore->pNxt;
        delete(tmp);
        return;
    }

    node* cur = pStore;
    while (cur->pNxt != nullptr) {
        if (cur->pNxt->val == x) {
            node* tmp = cur->pNxt;
            cur->pNxt = tmp->pNxt;
            delete(tmp);
            return;
        }
        cur = cur->pNxt;
    }
}

void deleteAllX(node* &pStore, int x) {

    node* cur = pStore;
    node* pre = nullptr;

    while (cur) {
        
        while (cur && cur->val == x) {
            node *tmp = cur->pNxt;
            if (pre)
                pre->pNxt = tmp;
            else 
                pStore = tmp;

            delete(cur);
            cur = tmp;
        }

        if (cur == nullptr) break;
        pre = cur;
        cur = cur->pNxt;
    }
}

void reverseList(node* &pStore) {
    node* cur = pStore;
    node* pre = pStore;

    if (cur == nullptr) return;
    cur = cur->pNxt;
    
    while (cur) {
        node* tmp = cur->pNxt;
        cur->pNxt = pre;
        pre = cur;
        cur = tmp;
    }

    pStore->pNxt = nullptr;
    pStore = pre;
}