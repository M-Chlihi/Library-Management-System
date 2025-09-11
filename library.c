#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>

typedef struct {
    char title[100];
    char author[50];
    int year;
    char isbn[20];
    bool isBorrowed; 
} Book;

void addBook(Book **library, int *bookCount);
void displayBooks(Book *library,int bookCount);
void  searchBook(Book *library,int  bookCount, char *query); 
void deleteBook(Book **library, int *bookCount, char *isbn);
int compareByTitle(const void *a, const void *b);
int compareByAuthor(const void *a, const void *b);
void sortBooks(Book *library, int bookCount);
void saveToFile(Book *library,int  bookCount,const char *filename);
void borrowBook(Book *library, int bookCount, char *isbn);
void returnBook(Book *library, int bookCount, char *isbn);
void trim(char *str);
int loadFromFile(Book **library, const char *filename);
void toUpperCase(char *str);

int main(){
Book *library = NULL;  // pointer to dynamic array

printf("** Welcome in your Library **\n");
printf("\n");
int bookCount = loadFromFile(&library, "library.txt");
  
int choice;

do {
    printf("1. Add Book\n2. Display Books\n3. Search Book\n4. Delete Book\n5. Sort Books\n6. Borrow Book\n7. Return Book\n8. Save & Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1: addBook(&library, &bookCount); break;
        case 2: displayBooks(library, bookCount); break;
        case 3: 
            char query[100];
            printf("\nEnter title/author: ");
            scanf(" %[^\n]", query);
            searchBook(library, bookCount, query); 
            break;
        case 4:
            char isbn[20];
            printf("Enter ISBN to delete: ");
            scanf(" %[^\n]", isbn);
            deleteBook(&library, &bookCount, isbn);
            break;
        case 5: sortBooks(library, bookCount); break;
        case 6:
    {
        char isbn[20];
        printf("Enter ISBN to borrow: ");
        scanf(" %[^\n]", isbn);
        borrowBook(library, bookCount, isbn);
    }
    break;
case 7:
    {
        char isbn[20];
        printf("Enter ISBN to return: ");
        scanf(" %[^\n]", isbn);
        returnBook(library, bookCount, isbn);
    }
    break;

        case 8: saveToFile(library, bookCount, "library.txt"); break;
        default: printf("Invalid choice!\n");
    }


} while(choice != 8);

  free(library);
}

void addBook(Book **library, int *bookCount) {
    *library = realloc(*library, (*bookCount + 1) * sizeof(Book));
    if (*library == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    Book *newBook = &(*library)[*bookCount]; 
    
    printf("Enter book title: ");
    scanf(" %[^\n]", newBook->title);

    printf("Enter author name: ");
    scanf(" %[^\n]", newBook->author);

    printf("Enter publication year: ");
    scanf("%d", &newBook->year);

    printf("Enter ISBN: ");
    scanf(" %[^\n]", newBook->isbn);

    (*bookCount)++;

    printf(" Book added successfully!\n\n");
}

void displayBooks(Book *library,int bookCount){
        if (bookCount == 0) {
        printf("\n Your library is empty.\n\n");
        return;
    }
    printf("\n Library Collection (%d books):\n", bookCount);
    printf("--------------------------------------\n");

    for (int i = 0; i < bookCount; i++)
    {
        printf("book number :%d\n", i+1);
     printf("Title : %s\n", library[i].title);
    printf("author name: %s\n", library[i].author);
     printf("publication year:  %d\n", library[i].year);
    printf("ISBN: %s\n", library[i].isbn);
         printf("--------------------------------------\n");
   
    }
     printf("\n");
}

void  searchBook(Book *library,int  bookCount, char *query){
    if (bookCount == 0) {
        printf("\n Your library is empty.\n\n");
        return;
    }
    int found = 0;
    for (int i = 0; i < bookCount; i++){     
    if (strstr(library[i].title , query) != NULL || strstr(library[i].author , query) != NULL )
    {
         printf("Book #%d\n", i + 1);
            printf(" Title : %s\n", library[i].title);
            printf(" Author: %s\n", library[i].author);
            printf(" Year  : %d\n", library[i].year);
            printf(" ISBN  : %s\n", library[i].isbn);
            printf("--------------------------------------\n");
            found = 1;
    }
    }
  if (!found)
  {
printf(" No books found matching your search!... ");
}
  printf("\n");
    
}

void deleteBook(Book **library, int *bookCount, char *isbn) {
    if (*bookCount == 0) {
        printf("\n Your library is empty.\n\n");
        return;
    }

    int index = -1;
    for (int i = 0; i < *bookCount; i++) {
        if (strcmp((*library)[i].isbn, isbn) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Book not found!\n");
        return;
    }

    for (int i = index; i < *bookCount - 1; i++) {
        (*library)[i] = (*library)[i + 1];
    }

    (*bookCount)--;

    if (*bookCount > 0) {
        Book *temp = realloc(*library, (*bookCount) * sizeof(Book));
        if (temp == NULL) {
            printf("Memory reallocation failed!\n");
            exit(1);
        }
        *library = temp;
    } else {
        free(*library);
        *library = NULL;
    }
    char tempISBN[20];
strcpy(tempISBN, isbn);
toUpperCase(tempISBN);

for (int i = 0; i < *bookCount; i++) {
    char libISBN[20];
    strcpy(libISBN, (*library)[i].isbn);
    toUpperCase(libISBN);

    if (strcmp(libISBN, tempISBN) == 0) {
        index = i;
        break;
    }
}

    printf(" Book deleted successfully!\n");
}

int compareByTitle(const void *a, const void *b) {
    return strcmp(((Book*)a)->title, ((Book*)b)->title);
}

int compareByAuthor(const void *a, const void *b) {
    return strcmp(((Book*)a)->author, ((Book*)b)->author);
}

void sortBooks(Book *library, int bookCount) {
    int choice;
    printf("Sort by: 1. Title  2. Author\n");
    scanf("%d", &choice);

    if (choice == 1) {
        qsort(library, bookCount, sizeof(Book), compareByTitle);
        printf(" Books sorted by title!\n");
    } 
    else if (choice == 2) {
        qsort(library, bookCount, sizeof(Book), compareByAuthor);
        printf(" Books sorted by author!\n");
    } 
    else {
        printf(" Invalid choice.\n");
    }
}

void toUpperCase(char *str) {
    for(int i = 0; str[i]; i++)
        str[i] = toupper(str[i]);
}

void borrowBook(Book *library, int bookCount, char *isbn) {
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].isbn, isbn) == 0) {
            if (library[i].isBorrowed) {
                printf(" This book is already borrowed!\n");
            } else {
                library[i].isBorrowed = true;
                printf(" You have borrowed: %s\n", library[i].title);
                    printf("--------------------------------------\n");

            }
            return;
        }
    }
    printf(" Book with ISBN %s not found!\n", isbn);
}

void returnBook(Book *library, int bookCount, char *isbn) {
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].isbn, isbn) == 0) {
            if (!library[i].isBorrowed) {
                printf(" This book was not borrowed.\n");
            } else {
                library[i].isBorrowed = false;
                printf(" You have returned: %s\n", library[i].title);
                    printf("--------------------------------------\n");

            }
            return;
        }
    }
    printf(" Book with ISBN %s not found!\n", isbn);
}


void saveToFile(Book *library,int bookCount,const char *filename){
    FILE *fp = fopen(filename, "w"); 
    if (fp == NULL) {
        printf(" Couldn't open file %s for writing!\n", filename);
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        fprintf(fp, "%s;%s;%s;%d\n",
                library[i].title,
                library[i].author,
                library[i].isbn,
                library[i].year);
    }

    fclose(fp);
    printf(" saved successfully to %s!\n", filename);
    
}

void trim(char *str) {
    // Trim leading spaces
    while (*str == ' ') str++;

    char *end = str + strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\n' || *end == '\r')) {
        *end = '\0';
        end--;
    }
}

int loadFromFile(Book **library, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf(" No saved library found. Starting with an empty library.\n");
        *library = NULL;
        return 0;
    }

    char line[256];
    int count = 0;
    *library = NULL;

    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\n")] = '\0'; // remove newline

        Book newBook;

        char *token = strtok(line, ";");
        if (token) {
            trim(token);
            strcpy(newBook.title, token);
        }

        token = strtok(NULL, ";");
        if (token) {
            trim(token);
            strcpy(newBook.author, token);
        }

        token = strtok(NULL, ";");
        if (token) {
            trim(token);
            strcpy(newBook.isbn, token);
        }

        token = strtok(NULL, ";");
        if (token) {
            trim(token);
            newBook.year = atoi(token);
        } else {
            newBook.year = 0;
        }

        // Expand library array
        Book *temp = realloc(*library, (count + 1) * sizeof(Book));
        if (temp == NULL) {
            printf(" Memory allocation failed while loading file!\n");
            fclose(fp);
            exit(1);
        }
        *library = temp;
        (*library)[count] = newBook;
        count++;
    }

    fclose(fp);
    printf(" Library loaded successfully from %s (%d books).\n", filename, count);
    return count;
}
