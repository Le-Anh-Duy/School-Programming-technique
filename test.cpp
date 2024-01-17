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

void inputTitle(char* &title) {
    char ch;

    int sz = 1;
    title = new char[1];
    title[0] = '\0';

    while ((ch = cin.get()) != '\n') {
        sz ++;
        char *ptr = new char[sz];
        ptr[sz - 1] = '\0';

        char* pos = ptr;
        char* o = title;

        while (*title != '\0') {
            *ptr = *title;
            ptr++;
            title++;
        }

        *ptr = ch;
        delete[] o;
        title = pos;
    }
} 

