#include <stdio.h>
typedef struct {
 char source;
 char code;
} Rule;
void encodeChar(Rule table[5], char *s, char *t);
int main()
{
 char s[80],t[80];
 Rule table[5] = {'a','d', 'b','z', 'z','a', 'd','b', '\0','\0' };

 printf("Source string: \n");
 gets(s);
 encodeChar(table,s,t);
 printf("Encoded string: %s\n", t);
 return 0;
}
void encodeChar(Rule table[5], char *s, char *t)
{
 char temp = "0";
 int i = 0;
 Rule rTemp ;
 while(temp!= '\0')
 {
     temp = *(s+i);
     for(int x = 0; x<5;x++)
     {
         rTemp = *(table+x);
         if(temp == rTemp.source)
         {
             temp = rTemp.code;
             break;
         }
     }
     *(t+i)=temp;
     i++;
 }

}
