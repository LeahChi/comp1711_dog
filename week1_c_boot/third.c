#include<stdio.h>

int main()
{
    int var;
    printf("number: ");
    scanf("%d", &var); //scans user'sinput.does not actually take the variable - takes location. it takes POINTER
    printf("var = %d\n",var );
    return 0;
}