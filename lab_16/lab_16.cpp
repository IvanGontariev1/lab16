#include <iostream>

struct Book {
    char author[50];
    char title[50];
    char publisher[50];
    int year;
    int pages;
};


bool compareStrings(const char* str1, const char* str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            return false;
        }
        str1++;
        str2++;
    }
    return (*str1 == '\0' && *str2 == '\0');
}


void printBooksByAuthor(Book books[], int size, const char* author) {
    std::cout << "Books by " << author << ":\n";
    for (int i = 0; i < size; ++i) {
        if (compareStrings(books[i].author, author)) {
            std::cout << "Title: " << books[i].title
                << ", Publisher: " << books[i].publisher
                << ", Year: " << books[i].year
                << ", Pages: " << books[i].pages << std::endl;
        }
    }
}


void printBooksByPublisher(Book books[], int size, const char* publisher) {
    std::cout << "Books published by " << publisher << ":\n";
    for (int i = 0; i < size; ++i) {
        if (compareStrings(books[i].publisher, publisher)) {
            std::cout << "Author: " << books[i].author
                << ", Title: " << books[i].title
                << ", Year: " << books[i].year
                << ", Pages: " << books[i].pages << std::endl;
        }
    }
}


void printBooksAfterYear(Book books[], int size, int year) {
    std::cout << "Books published after " << year << ":\n";
    for (int i = 0; i < size; ++i) {
        if (books[i].year > year) {
            std::cout << "Author: " << books[i].author
                << ", Title: " << books[i].title
                << ", Publisher: " << books[i].publisher
                << ", Year: " << books[i].year
                << ", Pages: " << books[i].pages << std::endl;
        }
    }
}

int main() {
    const int size = 5;
    Book books[size] = {
        {"Author A", "Title A1", "Publisher X", 2000, 300},
        {"Author B", "Title B1", "Publisher Y", 2005, 250},
        {"Author A", "Title A2", "Publisher X", 2010, 400},
        {"Author C", "Title C1", "Publisher Z", 2015, 500},
        {"Author B", "Title B2", "Publisher Y", 2020, 350}
    };


    char author[50];
    char publisher[50];
    int year;

    std::cout << "Enter author name: ";
    std::cin.getline(author, 50);
    printBooksByAuthor(books, size, author);

    std::cout << "\nEnter publisher name: ";
    std::cin.getline(publisher, 50);
    printBooksByPublisher(books, size, publisher);

    std::cout << "\nEnter year: ";
    std::cin >> year;
    printBooksAfterYear(books, size, year);

    return 0;
}
