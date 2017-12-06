// Student record implementation ... Assignment 1 COMP9024 17s2
#include <stdio.h>
#include <stdlib.h>
#define LINE_LENGTH 1024

// scan input for a positive integer, returns -1 if none
int readInt(void) {
   char line[LINE_LENGTH];
   int  n;

   fgets(line, LINE_LENGTH, stdin);
   if ( (sscanf(line, "%d", &n) != 1) || n <= 0 )
      return -1;
   else
      return n;
}

// scan input for a positive floating point number, returns -1 if none
float readFloat(void) {
   char  line[LINE_LENGTH];
   float f;

   fgets(line, LINE_LENGTH, stdin);
   if ( (sscanf(line, "%f", &f) != 1) || f <= 0.0 )
      return -1;
   else
      return f;
}

/*** Your code for stage 1 starts here ***/



int readValidID(void)
{

    printf("Enter student ID: ");
    int returned_value = readInt();
    
    while(returned_value == -1 || returned_value < 1000000 || returned_value >= 10000000){
        printf("Not valid. Enter a valid value: ");
        returned_value = readInt();
    }
    
    return returned_value;
}

int readValidCredits(void) {
    
    printf("Enter credit points: ");
    int returned_value = readInt();
    while(returned_value == -1 || returned_value <2 || returned_value > 480){
        printf("Not valid. Enter a valid value: ");
        returned_value = readInt() ;
    }
    return returned_value;
}

float readValidWAM(void) {
    printf("Enter WAM: ");
    float returned_value = readFloat();
    while(returned_value == -1 || returned_value < 50 || returned_value > 100){
        printf("Not valid. Enter a valid value: ");
        returned_value = readFloat();
    }
    return returned_value;
}

void printStudentData(int zID, int credits, float WAM) {
    printf("------------------------\n");
    printf("Student zID: z%d\n", zID);
    printf("Credits: %d\n", credits);
    if(WAM >= 85 && WAM<=100){
        printf("Level of performance: HD\n");
    }else if (WAM >= 75 && WAM <85){
        printf("Level of performance: DN\n");
    }else if (WAM >=65 && WAM < 75){
        printf("Level of performance: CR\n");
    }else{
        printf("Level of performance: PS\n");
    }
    printf("------------------------\n");
    printf("");
    
}
