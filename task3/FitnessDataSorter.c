#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

//PLAN shove each line into an array delimited by the comma and then compare

FitnessData file_data;
    int records = 0;
    int no_of_loops = 0;

    char line[100]; //string to hold data
    char *sp; //string pointer


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

int isLineValid(char *date, char *time, int steps)
{
    return strlen(date) == 10 && strlen(time) == 5 && steps >0;
}
//used logic from: https://www.programiz.com/dsa/bubble-sort
void bubbleSort(FitnessData *data, int records) 
{
    for (int i = 0; i < records - 1; i++) 
    {
        for (int j = 0; j < records - i - 1; j++) 
        {
            if (data[j].steps < data[j + 1].steps) 
            {
                // Swap data[j] and data[j+1]
                FitnessData temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
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

    FILE *file = fopen(filename, "r");
        if (!file)
        {
            printf("Error: invalid file\n");
            return 1;
        }

    

    while(fgets(line, 100, file)!=NULL)//looping through each line in file
    {
        records ++;

        sp = strtok(line,",");
        if (!sp)
        {
            printf("Error: invalid file\n");
            //fclose(file);
            return 1;
        }

        strcpy(file_data.date,sp);

        sp = strtok(NULL, ",");
        if (!sp)
        {
            printf("Error: invalid file\n");
            //fclose(file);
            return 1;
        }
        strcpy(file_data.time,sp);

        sp = strtok(NULL, ",");
        if (!sp)
        {
            printf("Error: invalid file\n");
            //fclose(file);
            return 1;
        }
        //file_data.steps = atoi(sp);

        if(!isLineValid(file_data.date, file_data.time, file_data.steps)) 
        {
            printf("Error: invalid file format\n");
            //fclose(file);
            return 1;
        }


    }

    FitnessData *data = malloc(records * sizeof(FitnessData));

    fseek(file,0,SEEK_SET);

    int i = 0;
    while (fgets(line, 100, file) != NULL) {
        sp = strtok(line, ",");
        strcpy(data[i].date, sp);

        sp = strtok(NULL, ",");
        strcpy(data[i].time, sp);

        sp = strtok(NULL, ",");
        data[i].steps = atoi(sp);

        i++;
    }

    bubbleSort(data, records);

    // Write out the sorted data to a new file
    char outputFilename[100];
    strcpy(outputFilename, filename);
    strcat(outputFilename, ".tsv");

    FILE *outputFile = fopen(outputFilename, "w");
    if (!outputFile) 
    {
        printf("Error: invalid file\n");
        return 1;
    }

     for (i = 0; i < records; i++) 
    {
        fprintf(outputFile, "%s\t%s\t%d\n", data[i].date, data[i].time, data[i].steps);
    }



    fclose(file);
    fclose(outputFile);
    return 0;

}
