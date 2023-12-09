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
    int records;
    int no_of_loops = 0;
    int num_of_commas = 0;
    int is_valid = 1; //1 = valid, 0= not valid

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
        //records++;
        num_of_commas = 0; //have to reset the #
        if (records!=0)
        {
            for (int i = 0; i < strlen(line); i++) //checks if line has 2 commas
            {
                if (line[i] == ',')
                {
                    num_of_commas ++;
                }

                if(num_of_commas != 2)
            {
                is_valid = 0;
                break;
            }

            }

        }
        records ++;
    }
    if (records == 0 || is_valid == 0) //checks to see if file is empty
    {
        printf("Error: invalid file\n");
        return 1;
    }

    //invalid file if not in 2023-12-30,09:30,598 format
    // check each record, split into 3 parts
    // 1st contains hyphem, 2nd contains : , 3rd is an integer

    /* while(fgets(line, 100, file)!=NULL)//fgets to get one line of data
    {
        if(no_of_loops<3)
        {
        sp = strtok(line, ","); //stops when reaches comma
        strcpy(file_data.date, sp);

        sp = strtok(NULL, ",");
        strcpy(file_data.time, sp);
        
        sp = strtok(NULL, ",");
        file_data.steps = atoi(sp);// a to i(nt) ->str to int
        
        printf("\n%s/%s/%d", file_data.date,file_data.time,file_data.steps);
        no_of_loops++;
        }
    }*/


    fclose(file);
    return 0;

}
