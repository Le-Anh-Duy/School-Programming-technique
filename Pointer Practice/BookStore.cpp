/*
    This code is for learning pointers
*/
#include <iostream>
#include <cstring>
using namespace std;

struct Book {
    int ID;
    char* title;
    float price;

    Book(): ID(0), title(nullptr), price(0) {};
};

void inputTitle(char* &title);
void inputStore(Book* &bookStore, int &n);
void ouputStore(Book* bookStore, int n);
void clearHeap(Book* bookStore, int n);

int main() { 
    int n;
    Book *bookStore;
    inputStore(bookStore, n);
    ouputStore(bookStore, n);
    clearHeap(bookStore, n);
    return 0;
}

void clearHeap(Book* bookStore, int n) {
    for (int i = 0; i < n; i ++)
        delete[] bookStore[i].title;
    delete[] bookStore;
}

void ouputStore(Book* bookStore, int n) {
    for (int i = 0; i < n; i ++)
        cout << bookStore[i].ID << ' ' << bookStore[i].title << ' ' << bookStore[i].price << '\n';
}

void inputStore(Book* &bookStore, int &n) {
    cin >> n;
    bookStore = new Book[n]();
    for (int i = 0; i < n; i ++) {
        cin >> (bookStore + i)->ID; 
        cin.ignore();
        inputTitle((bookStore + i)->title);
        
        cin >> (bookStore + i)->price; 
    }
}

void inputTitle(char* &title) {
    int curSz = 0;
    int allocated_Sz = 1;

    title = new char[allocated_Sz];
    title[0] = '\0';
    
    char ch;
    while ((ch = cin.get()) != '\n') {
        curSz ++;
        if (curSz == allocated_Sz) {
            allocated_Sz *= 2;
            char* newTitle = new char[allocated_Sz];
            strcpy(newTitle, title);
            delete[] title;
            title = newTitle;
        }

        title[curSz - 1] = ch;
        title[curSz] = '\0';
    }
} 

