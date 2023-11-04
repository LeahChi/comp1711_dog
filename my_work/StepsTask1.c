#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
}FITNESS_DATA;

// Define any additional variables here
    FITNESS_DATA file_data;
    int records;
    int no_of_loops = 0;

    char line[100]; //string to hold data
    char *sp; //string pointer


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() 
{
    FILE *file;

    file = fopen("FitnessData_2023.csv","r");

    if (file == NULL)
    {
        perror("");
        exit(1);
    }

    while(fgets(line, 100, file)!=NULL)//looping through each line in file
    {
        records++;
    }
    printf("Number of records in file: %d", records);

    fseek(file, 0, SEEK_SET);
    while(fgets(line, 100, file)!=NULL)//fgets to get one line of data
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
    }

    fclose(file);

    return 0;


}
