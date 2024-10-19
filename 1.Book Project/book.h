#include<stdio.h>
#include<string.h>
#include <ctype.h>

typedef struct BookManagementSystem
{
    int BookID;
    char Book_Name[20];
    char Author_Name[20];
    char Category[20];
    double Price;
    double Rating;
} BookManagementSystem;

int hardCoded(BookManagementSystem*, int);
void storeBook(BookManagementSystem*, int);
void displayAllBook(BookManagementSystem*, int);
void deleteBook(BookManagementSystem*, int*, int);
void updatePriceAndRating(BookManagementSystem*, int);
void sortBooks(BookManagementSystem*, int);
int searchByID(BookManagementSystem*, int, int);
void searchByName(BookManagementSystem*, int, const char*);
void search(BookManagementSystem*, int);
void searchByAuthor(BookManagementSystem*, int, const char*);
void searchByCategory(BookManagementSystem*, int, const char*);
void displayOneBook(BookManagementSystem*, int);
void toLowerCase(char* str);

