#include <stdio.h>
typedef struct {
 char name[20];
 int age;
} Person;
void readData(Person *p);
Person findMiddleAge(Person *p);
int main()
{
 Person man[3], middle;

 readData(man);
 middle = findMiddleAge(man);
 printf("findMiddleAge(): %s %d\n", middle.name, middle.age);
 return 0;
}
void readData(Person *p)
{
 for(int i = 0; i < 3; i++)
 {
     Person temp;
     printf("Enter person %d\n",(i+1));
     scanf("\n");
     scanf("%s %d",&temp.name,&temp.age);
     *(p+i) = temp;
 }
}
Person findMiddleAge(Person *p)
{
 Person result;
 for(int i =0;i<3;i++)
 {
    int moreThan=0,lessThan=0;
     Person temp = *(p+i);
     for(int x=0;x<3;x++)
     {
         if(i!=x)
         {
         Person compare = *(p+x);
             if(temp.age > compare.age)
             {
                 moreThan++;
             }
             else if(temp.age < compare.age)
             {
                lessThan++;
             }
         }
     }
     if(moreThan>0 && lessThan>0 && moreThan == lessThan)
     {
        result = temp;
     }
 }
 return result;
}
