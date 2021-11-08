//2. Crear una clase Libro, y luego un vector de objetos (diagrama y c�digo fuente).

#include <string>

using namespace std;

class Book {
private:
    string author;
    string subject;
    int pages;
    float price;
public:
    Book();

    void setSubject(string sub);

    string getSubject();

    void setPages(int pag);

    int getPages();

    void setPrice(float pri);

    float getPrice();

    void setAuthor(string aut);

    string getAuthor();
};

Book::Book() {
}

void Book::setSubject(string sub) {
    subject = sub;
}

string Book::getSubject() {
    return subject;
}

void Book::setPages(int pag) {
    pages = pag;
}

int Book::getPages() {
    return pages;
}

void Book::setPrice(float pri) {
    price = pri;
}

float Book::getPrice() {
    return price;
}

void Book::setAuthor(string aut) {
    author = aut;
}

string Book::getAuthor() {
    return author;
}

