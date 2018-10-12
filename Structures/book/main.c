#include <stdio.h>
#define SIZE 20
typedef struct {
 char title[81];
 char lastname[81];
 char firstname[81];
 char publisher[81];
 int day, month, year;
} Booktype;
void readBook(Booktype *book);
void printBook(Booktype book);
int main(){
 Booktype book[SIZE];
 char repeat = 'y',size=0;

 do {
 readBook(&book[size]);
 printf("The book information:\n");
 printBook(book[size]);
 printf("Continue ('y' or 'n'): ");
 scanf("%c", &repeat);
 size++;
 } while (repeat == 'y');
}
void readBook(Booktype *book)
{
    Booktype temp;
    printf("Enter the title of the book: \n");
    scanf("\n");
    gets(temp.title);
    printf("Enter the author's first name: \n");
    scanf("\n");
    gets(temp.firstname);
    printf("Enter the author's last name: \n");
    scanf("\n");
    gets(temp.lastname);
    printf("Enter date as (dd-mm-yy): \n");
    scanf("%d-%d-%d",&temp.day,&temp.month,&temp.year);
    printf("Enter the publisher name: \n");
    scanf("\n");
    gets(temp.publisher);
    *book = temp;
}
void printBook(Booktype book)
{
    printf("Title: %s\n",book.title);
    printf("Author: %s %s\n",book.firstname,book.lastname);
    printf("Date: %d-%d-%d\n",book.day,book.month,book.year);
    printf("Publisher: %s\n",book.publisher);
}
