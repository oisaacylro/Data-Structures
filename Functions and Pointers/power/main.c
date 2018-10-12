#include <stdio.h>
float power1(float num, int p);
void power2(float num, int p, float *result);
int main()
{
 int power;
 float number, result=-1;

 printf("Enter the number and power: \n");
 scanf("%f %d", &number, &power);
 printf("power1(): %.2f\n", power1(number, power));
 power2(number,power,&result);
 printf("power2(): %.2f\n", result);
 return 0;
}
float power1(float num, int p)
{
 float x = num;
if(p>0)
{
    printf("P is more than 0\n");
  for(int i = 1; i<p; i++)
 {
     num = num * x;
 }
}
else if(p<0)
{
    printf("P is less than 0\n");
    x = 1/x;
    for(int i = 1; i>p; i--)
 {
     num = num * x;
 }
}
else
{
    printf("P is 0\n");
    return 1;
}

 return num;
}
void power2(float num, int p, float *result)
{
    *result = num;

 if(p>0)
{
  for(int i = 1; i<p; i++)
 {
     *result = *result * num;
 }
}
else if(p<0)
{
    num = 1/num;
    for(int i = 1; i>p; i--)
 {
     *result = *result * num;
 }
}
else
{
    *result = 1;
}
}
