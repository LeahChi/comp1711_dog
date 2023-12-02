#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}



int main() {

    char filename[100];
    char line[100]; //holds data
    //char line *sp; //string pointer
    //bool is_valid = true; //if file valid

    printf("Please enter the name of the data file: ");
    scanf("%s",filename);

    FILE *input = fopen(filename, "r");
        if (!input)
        {
            printf("Error: invalid file\n");
            return 1;
        }

    //invalid file if not in 2023-12-30,09:30,598 format





}
