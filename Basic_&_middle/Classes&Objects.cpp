#include <iostream>
using namespace std;

class Book {
    public:
        string title;
        string author;
        int pages;
        Book(string name, string writer, int numPages) {
            title = name;
            author = writer;
            pages = numPages;
            cout << "A new book has been created!" << endl;
        }
};

int main() {
    Book book1("The Great Gatsby", "F. Scott Fitzgerald", 180);
    Book book2("To Kill a Mockingbird", "Harper Lee", 281);

    //book1.title = "The Great Gatsby";
    //book1.author = "F. Scott Fitzgerald";   
    //book1.pages = 180;
    cout << "Title: " << book1.title << endl;
    cout << "Author: " << book1.author << endl;
    cout << "Pages: " << book1.pages << endl;
    //book2.title = "To Kill a Mockingbird";
    //book2.author = "Harper Lee";
    //book2.pages = 281;
    cout << "Title: " << book2.title << endl;
    cout << "Author: " << book2.author << endl;
    cout << "Pages: " << book2.pages << endl;

    return 0;
}