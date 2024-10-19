#include <stdio.h>
#include <stdlib.h>
#include "book.h"
/* run this program using the console pauser or add your own getch, 
system("pause") or input loop */

int main()
{
    int size = 20;
    BookManagementSystem book[20];
    int ctr = 0;

    ctr = hardCoded(book, ctr); 
    printf("\nNumber of books after hard coding: %d\n", ctr);

    if (ctr > 0)
    {
        printf("\nDisplaying all hardcoded books:\n");
        displayAllBook(book, ctr);
    }
    else
    {
        printf("\nNo books available to display.\n");
    }

    int ch;
    do
    {
        printf("\n1. Add Book");
		printf("\n2. Display All Book");
		printf("\n3. Search Book");
		printf("\n4. Delete Book");
		printf("\n5. Update Price and Rating");
		printf("\n6. Sort Book");
		printf("\n7. Search by Author");
		printf("\n8. Search by Category");
		printf("\n0. Exit\n");
		
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if (ctr < size)
            {
                storeBook(book, ctr);
                ctr++;
            }
            else
            {
                printf("Insufficient memory!\n");
            }
            break;

        case 2:
            if (ctr > 0)
            {
                displayAllBook(book, ctr);
            }
            else
            {
                printf("No book present!\n");
            }
            break;

        case 3:
            search(book, ctr);
            break;

        case 4:
            {
                int id;
                printf("\nEnter Book ID you want to delete: ");
                scanf("%d", &id);
                int i = searchByID(book, ctr, id);
                if (i == -1)
                {
                    printf("\nBook not found!\n");
                }
                else
                {
                    deleteBook(book, &ctr, i);
                    printf("\nBook deleted successfully!\n");
                }
            }
            break;

        case 5:
            if (ctr != 0) {
                updatePriceAndRating(book, ctr);
            } else {
                printf("No books to update!\n");
            }
            break;

        case 6:
            if (ctr != 0)
            {
                sortBooks(book, ctr);
                printf("\nBooks sorted by Book ID!\n");
            }
            else
            {
                printf("No books to sort!\n");
            }
            break;
            
        case 7:
            if (ctr != 0) {
                char author[20];
                printf("\nEnter Author's Name: ");
                scanf("%s", author);
                searchByAuthor(book, ctr, author);
            } else {
                printf("No books available!\n");
            }
            break;
            
        case 8:
            if (ctr != 0) {
                char category[20];
                printf("\nEnter Category: ");
                scanf("%s", category);
                searchByCategory(book, ctr, category);
            } else {
                printf("No books available!\n");
            }
            break;

        case 0:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice! Please enter a valid option.\n");
            break;
        }

    } while (ch != 0);

    return 0;
}

