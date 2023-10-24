#include <stdio.h>
#include "utils.h"

FILE *open_file(char filename[], char mode[]) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        perror("");
    exit(1); // Exits program with return status 1.
    }
    }



int main(){
    char filename[] = "data2.txt"; 
    FILE *file = fopen(filename, "r");

    if (file == NULL){
        perror(""); 
    
        return 1; 
    }

    int buffer_size = 100; 
    char buffer[buffer_size]; 
    int count = 0;
    while(fgets(buffer,buffer_size,file) != NULL){
        printf("%s",buffer);
        count ++;
    }

    fclose(file); 

    return 0;
}