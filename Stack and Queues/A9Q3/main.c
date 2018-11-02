/////////////////////////////////////////////////////////////////////////////////

/* CE1007/CZ1007 Data Structures
Purpose: Implementing the required functions for Question 3 */
//////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
//#include "AS9_Q3.h"  //Comment it and include library filewhen you work on code::blocks
////////////////////////////////// stack //////////////////////////////////////////
#ifndef _AS9_Q3_
#define _AS9_Q3_
typedef struct _listnode{
   int item;
   struct _listnode *next;
} ListNode;

typedef ListNode StackNode;

typedef struct _stack{
   int size;
   ListNode *head;
} Stack;
#endif
////////////////////////// function prototypes ////////////////////////////////////

// You should not change the prototypes of these functions
int isStackPairwiseConsecutive(Stack *sPtr);

void push(Stack *sPtr, int item);
int pop(Stack *sPtr);
int peek(Stack s);
int isEmptyStack(Stack s);
void removeAllItemsFromStack(Stack *sPtr);

//////////////////////////////////////////////////////////////////////////////////////
int test_main(int (*isStackPairwiseConsecutive)(Stack *),void (*removeAllItemsFromStack)(Stack *));
int main()
{
    test_main(isStackPairwiseConsecutive,removeAllItemsFromStack);
    return 0;
}


//////////////////////////////////////////////////////////////////////////////////

void push(Stack *sPtr, int item)
{
	StackNode *newNode;
    newNode= malloc(sizeof(StackNode));
    newNode->item = item;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr)
{
    if(sPtr==NULL || sPtr->head==NULL){
        return 0;
    }
    else{
       StackNode *temp = sPtr->head;
       sPtr->head = sPtr->head->next;
       free(temp);
       sPtr->size--;
       return 1;
    }
}

int isEmptyStack(Stack s)
{
     if(s.size==0) return 1;
     else return 0;
}

int peek(Stack s){
    return s.head->item;
}

void removeAllItemsFromStack(Stack *sPtr)
{
	while(pop(sPtr));
}


/////////////////////////////////////////////////////////////////////////////////

int isStackPairwiseConsecutive(Stack* sPtr)
{
    int x = 0;
    int y = 0;
    int counter = 0;
    while(isEmptyStack(*sPtr)!=1)
    {
        if(counter == 0)
        {
            x = sPtr->head->item;
            counter++;
            pop(sPtr);
        }
        else if(counter == 1)
        {
            y = sPtr->head->item;
            counter++;
            pop(sPtr);
        }
        else
        {
            if((x-y!=1)&&(y-x!=1))
            {
                return 0;
            }
            counter = 0;
        }

    }
    return 1;
}
