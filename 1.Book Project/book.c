#include "book.h"

int hardCoded(BookManagementSystem* book, int ctr)
{
    book[ctr].BookID = 101;
    strcpy(book[ctr].Book_Name, "Shrimanyogi");
    strcpy(book[ctr].Author_Name, "Ranjit Desai");
    strcpy(book[ctr].Category, "Historical Fiction");
    book[ctr].Price = 450.00;
    book[ctr].Rating = 4.8;
    ctr++;

    book[ctr].BookID = 102;
    strcpy(book[ctr].Book_Name, "Yugandhar");
    strcpy(book[ctr].Author_Name, "Shivaji Sawant");
    strcpy(book[ctr].Category, "Mythological");
    book[ctr].Price = 550.00;
    book[ctr].Rating = 4.7;
    ctr++;

    book[ctr].BookID = 103;
    strcpy(book[ctr].Book_Name, "Mrutyunjay");
    strcpy(book[ctr].Author_Name, "Shivaji Sawant");
    strcpy(book[ctr].Category, "Mythological");
    book[ctr].Price = 500.00;
    book[ctr].Rating = 4.9;
    ctr++;
    
    book[ctr].BookID = 104;
    strcpy(book[ctr].Book_Name, "Purnachandra");
    strcpy(book[ctr].Author_Name, "Sane Guruji");
    strcpy(book[ctr].Category, "Biography");
    book[ctr].Price = 300.00;
    book[ctr].Rating = 4.6;
    ctr++;

	book[ctr].BookID = 105;
    strcpy(book[ctr].Book_Name, "Batatyachi Chaal");
    strcpy(book[ctr].Author_Name, "P L Deshpande");
    strcpy(book[ctr].Category, "Humor");
    book[ctr].Price = 200.00;
    book[ctr].Rating = 4.8;
    ctr++;
    
    return ctr;
}

void storeBook(BookManagementSystem* book, int ctr)
{
    printf("Enter Book ID: ");
    scanf("%d", &book[ctr].BookID);

    printf("Enter Book name: ");
    scanf("%s", book[ctr].Book_Name);

    printf("Enter Author Name: ");
    scanf("%s", book[ctr].Author_Name);

    printf("Enter Category: ");
    scanf("%s", book[ctr].Category);

    printf("Enter Price: ");
    scanf("%lf", &book[ctr].Price);

    printf("Enter Rating: ");
    scanf("%lf", &book[ctr].Rating);

    printf("\nBook added successfully!\n");
}

void displayAllBook(BookManagementSystem* book, int ctr)
{
	int i;
    if (ctr > 0)
    {
        printf("\n+---------+------------------+-------------------+---------------------+----------------+---------------+");
        printf("\n| Book ID |     Book name    |    Book Author    |    Book Category    |   Book Price   |  Book Rating  |");
        printf("\n+---------+------------------+-------------------+---------------------+----------------+---------------+\n");

        for (i = 0; i < ctr; i++)
        {
            printf("|%8d |%17s |%18s |%20s |%15.2lf |%14.1lf |\n", 
                   book[i].BookID, book[i].Book_Name, book[i].Author_Name, book[i].Category, book[i].Price, book[i].Rating);
        }

        printf("+---------+------------------+-------------------+---------------------+----------------+---------------+\n");
    }
    else
    {
        printf("\nNo books to display!\n");
    }
}

void deleteBook(BookManagementSystem* book, int* ctr, int ind)
{
	int i;
    for ( i = ind; i < *ctr - 1; i++)
    {
        book[i] = book[i + 1];
    }
    (*ctr)--; 
}

void updatePriceAndRating(BookManagementSystem* book, int ctr) {
    int id;
    printf("\nEnter Book ID to update Price and Rating: ");
    scanf("%d", &id);
    int i = searchByID(book, ctr, id);
    if (i == -1) {
        printf("\nBook not found!\n");
        return;
    }

    printf("Enter new Price: ");
    scanf("%lf", &book[i].Price);

    printf("Enter new Rating: ");
    scanf("%lf", &book[i].Rating);

    printf("\nPrice and Rating updated successfully!\n");
}

void searchByAuthor(BookManagementSystem* book, int ctr, const char* author) {
    char lowerAuthor[20];
    strcpy(lowerAuthor, author);
    toLowerCase(lowerAuthor);  // Convert input author to lowercase
    int i, found = 0;

    for (i = 0; i < ctr; i++) {
        char lowerBookAuthor[20];
        strcpy(lowerBookAuthor, book[i].Author_Name);
        toLowerCase(lowerBookAuthor);  // Convert stored author name to lowercase
        if (strstr(lowerBookAuthor, lowerAuthor) != NULL) {  // Check if input is a substring
            displayOneBook(book, i);
            found = 1;
        }
    }

    if (!found) {
        printf("\nNo books found by this author!\n");
    }
}

void searchByCategory(BookManagementSystem* book, int ctr, const char* category) {
    char lowerCategory[20];
    strcpy(lowerCategory, category);
    toLowerCase(lowerCategory);  // Convert input category to lowercase
    int i, found = 0;

    for (i = 0; i < ctr; i++) {
        char lowerBookCategory[20];
        strcpy(lowerBookCategory, book[i].Category);
        toLowerCase(lowerBookCategory);  // Convert stored category name to lowercase
        if (strstr(lowerBookCategory, lowerCategory) != NULL) {  // Check if input is a substring
            displayOneBook(book, i);
            found = 1;
        }
    }

    if (!found) {
        printf("\nNo books found in this category!\n");
    }
}


void sortBooks(BookManagementSystem* book, int ctr)
{
	int i, j;
    for (i = 0; i < ctr - 1; i++)
    {
        for (j = 0; j < ctr - i - 1; j++)
        {
            if (book[j].BookID > book[j + 1].BookID)
            {
                BookManagementSystem temp = book[j];
                book[j] = book[j + 1];
                book[j + 1] = temp;
            }
        }
    }
}

int searchByID(BookManagementSystem* book, int ctr, int id)
{
	int i;
    for (i = 0; i < ctr; i++)
    {
        if (book[i].BookID == id)
        {
            return i;
        }
    }
    return -1;
}

void toLowerCase(char* str) {
	int i;
    for ( i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void searchByName(BookManagementSystem* book, int ctr, const char* name) {
    char lowerName[20];
    strcpy(lowerName, name);
    toLowerCase(lowerName);

    int found = 0, i; // To track if at least one match is found

    for ( i = 0; i < ctr; i++) {
        char lowerBookName[20];
        strcpy(lowerBookName, book[i].Book_Name);
        toLowerCase(lowerBookName);

        // Check if lowerName is a substring of lowerBookName
        if (strstr(lowerBookName, lowerName) != NULL) {
            if (!found) {
                printf("\nBooks Found! Details are as follows:\n");
                found = 1; // Set found to true
            }
            displayOneBook(book, i); // Display each matching book
        }
    }

    if (!found) {
        printf("\nNo matching books found!\n");
    }
}

void search(BookManagementSystem* book, int ctr)
{
    int id;
    char name[20];
    int ch;

    printf("\n1. Search by Book ID\n2. Search by Book name\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        printf("Enter Book ID: ");
        scanf("%d", &id);
        int index = searchByID(book, ctr, id);
        if (index != -1)
        {
            displayOneBook(book, index);
        }
        else
        {
            printf("\nBook not found!\n");
        }
        break;

    case 2:
        printf("Enter Book Name: ");
        scanf("%s", name);
        searchByName(book, ctr, name);
        break;

    default:
        printf("Invalid choice!\n");
        break;
    }
}


void displayOneBook(BookManagementSystem* book, int index)
{
    printf("\n+---------+------------------+-------------------+---------------------+----------------+---------------+\n");
    printf("| Book ID |     Book name    |    Book Author    |    Book Category    |   Book Price   |  Book Rating  |\n");
    printf("+---------+------------------+-------------------+---------------------+----------------+---------------+\n");
    printf("|%8d |%17s |%18s |%20s |%15.2lf |%14.1lf |\n", 
           book[index].BookID, book[index].Book_Name, book[index].Author_Name, book[index].Category, book[index].Price, book[index].Rating);
    printf("+---------+------------------+-------------------+---------------------+----------------+---------------+\n");
}

