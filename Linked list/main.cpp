#include <iostream>
#include <cstring>

class book {
public:
    char* title;
    char* author;
    float price;
    char* id;

private:
    void setPrice(float nPrice) {
        price = nPrice;
    } 

    void setAuther(char name[]) {
        delete[] author;

        int n = strlen(name);
        author = new char[n + 1];
        strncpy(author, name, 100); 
    }
};

struct node
{
    book data;
    node* pNext;
};





int main() {

    return 0;
}