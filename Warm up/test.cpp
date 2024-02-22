#include<stdio.h>

int main()
{
int x = 10;
int *y, ** z;
y = &x;
z = &y;
printf("x = %d, y = %d, z =%d\n", x, *y, ** z);
return 0;

}