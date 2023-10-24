#include <stdio.h>

int main(){
    char filename[] = "data.txt"; //name of file
    FILE *file = fopen(filename, "w");//open file name asterisk nused for pointer

    if (file == NULL){
        perror(""); //prints the error 
        //e.g char filename[] = "/data.txt" <- can not write files to root directory
        // but we can do char filename[] = "./data.txt" instead <- puts it in working directory
        return 1; //any number - just for checking
    }

    fprintf(file,"Hello World"); // file print formatting, need 'name' / assigned location name of file
    fclose(file); //closing the object - pointer - location

    return 0;
}