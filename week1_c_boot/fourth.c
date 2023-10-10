#include<stdio.h>

int main() //integer because you are returning 0
{
    char name [10];
    printf("name: ");
    scanf("%s", name); 
    printf("hello, %s\n", name);
    return 0;
}