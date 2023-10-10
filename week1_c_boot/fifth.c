#include<stdio.h>

int main() //integer because you are returning 0
{
    float side1;
    float side2;
    printf("side1 length: ");
    scanf("%f", &side1); 
    printf("side2 length: ");
    scanf("%f", &side2); //the ampersand!!!!!
    float area;
    area = side1*side2;
    printf("area of rec = %f\n", area);
    return 0;
}