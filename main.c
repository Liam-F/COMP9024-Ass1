#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "studentLL.h"
#include "studentRecord.h"

// linked list node type
// DO NOT CHANGE
typedef struct node {
    studentRecordT data;
    struct node    *next;
} NodeT;

// linked list type
typedef struct ListRep {
   NodeT *head;

/* Add more fields if you wish */

} ListRep;

/*** Your code for stages 2 & 3 starts here ***/

// Time complexity: O(1);
// Explanation: There is no loop and sorting operation in linked list creation function,hence,the time complexity should be O(1);
List newLL() {
    List p = malloc(sizeof(ListRep));
    p->head = NULL;
    return p;
}

// Time complexity: O(n);
// Explanation: There is only one while loop in the dropLL function ,hence,the time complexity should be O(n);
void dropLL(List listp) {
    NodeT *current = listp->head;
    while (current != NULL){
        NodeT *temp = current->next;
        free(current);
        current = temp;
    }
}

// Time complexity: O(n);
// Explanation:There are some if else statements and a while loop in the inLL function,hence,the complexity should be O(1)+ O(n),which means it should be O(n);
void inLL(List listp, int zid) {
    if(listp->head == NULL){
        printf("No record found.");
    }else{
        NodeT *current = malloc(sizeof(NodeT));
        current = listp->head;
        while(current->data.zID != zid && current->next != NULL){
            current = current->next;
        }
        if(current->data.zID == zid){
            printStudentData(current->data.zID, current->data.credits, current->data.WAM);
        }else{
            printf("No record found.\n");
        }
    }
    
}

// Time complexity: O(n);
// Explanation: There are a large number of if-else statements and while loops,however,there is no  nested loops in this function ,hence,the complexity should be O(1)+O(n),which means,the complexity can be O(n);
void insertLL(List listp, int zid, int cr, float wam) {
    NodeT *new = malloc(sizeof(NodeT));
    assert(new != NULL);
    new->data.zID = zid;
    new->data.credits = cr;
    new->data.WAM = wam;
    if(listp->head == NULL){            //for first time,when the list is empty
        new->next = listp->head;
        listp->head = new;
        printf("Student record added.\n");
    }else{
        if(listp->head->data.zID > new->data.zID){  // the new.zid is smaller than the first zid
        new->next = listp->head;
            listp->head = new;
            printf("Student record added.\n");
        }else{
            NodeT *current = malloc(sizeof(NodeT));
            current = listp->head;
            if((new->data.zID > current->data.zID) && current->next == NULL){
                current->next = new;
                new->next = NULL;
                printf("Student record added.\n");
            }else{
                while(new->data.zID > current->next->data.zID && current->next != NULL){
                    current = current->next;
                    if (current->next == NULL){
                        break;
                    }
                }
                if((new->data.zID > current->data.zID)  && current->next == NULL){
                    new->next = NULL;
                    current->next = new;
                    printf("Student record added.\n");
                }
                else if((current->next->data.zID != new->data.zID) && (current->next != NULL)){
                    new->next = current->next;
                    current->next = new;
                    printf("Student record added.\n");
                }
                else{
                    current->next->data.credits = new->data.credits;
                    current->next->data.WAM = new->data.WAM;
                    printf("Student record updated.\n");
                }
            }
        }
    }
}

// Time complexity: O(n);
// Explanation: In this function ,there are a pair of if-else statement and a while loop,hence,the complexity should be O(n)+O(1),which means the complexity should be O(n);
void getStatLL(List listp, int *n, float *wam, float *w_wam) {
    float average_Wam = 0;
    float weight_Wam = 0;
    float credit = 0;
    NodeT *current = malloc(sizeof(NodeT));
    current = listp->head;
    while(current != NULL){
        float stu_Wam;   //total student wam
        int stu_credit;  //total student credits
        *n += 1;
        stu_Wam = current->data.WAM;
        stu_credit = current->data.credits;
        credit = credit + stu_credit;
        average_Wam = average_Wam + stu_Wam;
        weight_Wam = weight_Wam + stu_credit * stu_Wam;
        current = current->next;
    }
    if(*n == 0){
        printf("Number of records: 0\n");
        printf("Average WAM: 0.000\n");
        printf("Average weighted WAM: 0.000\n");
    }else{
        printf("Number of records: %d\n",*n);
        printf("Average WAM: %5.3f\n",(average_Wam / *n));
        printf("Average weighted WAM: %5.3f\n",(weight_Wam / credit));
    }
}

// Time complexity: O(n);
// Explanation: In this function, there is just a while loop,hence,the complexity should be O(n)+O(1),which means the complexity of this function should be O(n);
void showLL(List listp) {
    NodeT *current = malloc(sizeof(NodeT));
    current= listp->head;
    while (current != NULL){
        printStudentData(current->data.zID, current->data.credits, current->data.WAM);
        current = current->next;
    }
}
