#include <stdio.h>
int perfectProd1(int num);
void perfectProd2(int num, int *prod);
int main()
{
 int number, result=0;

 printf("Enter a number: \n");
 scanf("%d", &number);
 printf("perfectProd1(): %d\n", perfectProd1(number));
 perfectProd2(number, &result);
 printf("perfectProd2(): %d\n", result);
 return 0;
}
int perfectProd1(int num)
{
    int temp = 0;
    int result = 1;
    for(int i =1; i<= num;i++)
     {
         for(int x = 1; x<i; x++)
         {
             if(i%x==0)
             {
                temp +=x;
             }
         }
         if(temp == i)
         {
            result = result * i;
         }
         temp = 0;
     }
     return result;
}
void perfectProd2(int num, int *prod)
{
    *prod = 1;
    int temp = 0;
    for(int i =1; i<= num;i++)
     {
         for(int x = 1; x<i; x++)
         {
             if(i%x==0)
             {
                temp +=x;
             }
         }
         if(temp == i)
         {
            *prod = *prod * i;
         }
         temp = 0;
     }
}
