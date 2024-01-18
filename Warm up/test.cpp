/*

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

int main() { 
    int n;
    cin >> n;
    Book *bookStore;
    bookStore = new Book[n]();
    for (int i = 0; i < n; i ++) {
        cin >> (bookStore + i)->ID; 
        cin.ignore();
        inputTitle((bookStore + i)->title);
        
        cin >> (bookStore + i)->price; 
    }

    for (int i = 0; i < n; i ++) {
        cout << bookStore[i].ID << ' ' << bookStore[i].title << ' ' << bookStore[i].price << '\n';
    }

    for (int i = 0; i < n; i ++)
        delete[] bookStore[i].title;
    delete[] bookStore;

    return 0;
}   
