//Library management System Project in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct  Book
{
    char title[50];
    char author[50];
    int id;
    int quantity;
    int is_available;
} Book;

struct Book books[MAX_BOOKS];
int num_books = 0;


void welcomeMessage()
{
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                     Wellcome                      ############");
    printf("\n\t\t\t############                        to                         ############");
    printf("\n\t\t\t############       Library management System Project in C      ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
}

void add_book()
{
    if (num_books == MAX_BOOKS)
    {
        printf("Error: Maximum number of books reached.\n");
        return;
    }

    struct  Book new_book;

    printf("\nEnter title: ");
    scanf("%s", &new_book.title);

    printf("Enter author: ");
    scanf("%s", &new_book.author);

    printf("Enter ID: ");
    scanf("%d", &new_book.id);

    printf("Enter quantity: ");
    scanf("%d", &new_book.quantity);

    new_book.is_available = 1;

    books[num_books++] = new_book;
    printf("Book added successfully.\n");
}

void display_books()
{
    for (int i = 0; i < num_books; i++)
    {
        printf("ID : %d \t\t Tittle : %s \t\t Author : %s \t\tQuantity : %d \t\t Available : %s\n", books[i].id, books[i].title, books[i].author,books[i].quantity, books[i].is_available ? "Yes" : "No");
    }
}

void borrow_book()
{
    int id;
    printf("Enter ID of book to borrow: ");
    scanf("%d", &id);

    for (int i = 0; i < num_books; i++)
    {
        if (books[i].id == id)
        {
            if (books[i].is_available)
            {
                books[i].is_available = 0;
                printf("\n\nBook borrowed successfully.\n");

                printf("Total Available Books After borrow: %d\n", --books[i].quantity);
            }
            else
            {
                printf("Error: Book not available for borrowing.\n");
            }
            return;
        }
    }

    printf("Error: Book not found.\n");
}

void return_book()
{
    int id;
    printf("Enter ID of book to return: ");
    scanf("%d", &id);

    for (int i = 0; i < num_books; i++)
    {
        if (books[i].id == id)
        {
            if (!books[i].is_available)
            {
                books[i].is_available = 1;
                printf("Book returned successfully.\n");

                printf("Total Available Books After return: %d\n", ++books[i].quantity);
            }
            else
            {
                printf("Error: Book not borrowed.\n");
            }
            return;
        }
    }

    printf("Error: Book not found.\n");
}


void delete_book()
{
    int id, i;
    printf("Enter ID of book to delete: ");
    scanf("%d", &id);

    for (i = 0; i < num_books; i++)
    {
        if (books[i].id == id)
        {
            num_books--;
            for (int j = i; j < num_books; j++)
            {
                books[j] = books[j+1];
            }
            printf("ID:%d  Book is  deleted successfully.\n");
            return;
        }
    }

    printf("Error: Book not found.\n");
}


void search_book()
{
    int book_id, i;
    printf("Enter book ID: ");
    scanf("%d", &book_id);

    for (i = 0; i < num_books; i++)
    {
        if (books[i].id == book_id)
        {
            printf("\nBook Found!!!\n\n");

            printf("Book ID: %d\n", books[i].id);
            printf("Book Title: %s\n", books[i].title);
            printf("Author Name: %s\n", books[i].author);
            printf("Quantity: %d\n", books[i].quantity);
            return;
        }
    }
    printf("Book not found.\n");
}


int total_books()
{
    return num_books;
}

int total_quantity()
{
    int total = 0;
    for (int i = 0; i < num_books; i++)
    {
        total += books[i].quantity;
    }
    return total;
}


int main()
{
    welcomeMessage();

    int choice;

    while(1)
    {
        printf("\n\n----Library Management System----\n\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Borrow Book\n");
        printf("5. Return Book\n");
        printf("6. Delete Book\n");
        printf("7. Total Types of Book\n");
        printf("8. Total Book in Library\n");
        printf("9. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_book();
            break;
        case 2:
            display_books();
            break;
        case 3:
            search_book();
            break;
        case 4:
            borrow_book();
            break;
        case 5:
            return_book();
            break;
        case 6:
            delete_book();
            break;
        case 7:
            printf("\nTotal Type of Books: %d\n", total_books());
            break;
        case 8:
            printf("\nTotal Book Quantity: %d\n", total_quantity());
            break;
        case 9:
            printf("\nThank You for using Library Management System.\n");
            return 0;
        default:
            printf("\nInvalid Choice!\n");
        }
    }
}

