/////////////////////////////////////////////////////////////////////////////////

/* CE1007/CZ1007 Data Structures
Purpose: Implementing the required functions for Question 5 */
//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//#include "AS9_Q5.h" //Comment it and include library filewhen you work on code::blocks
////////////////////////////////// stack //////////////////////////////////////////

#ifndef _AS9_Q5_
#define _AS9_Q5_
typedef struct _listnode{
   char item;
   struct _listnode *next;
} ListNode;

typedef ListNode StackNode;

typedef struct _linkedlist{
   int size;
   ListNode *head;
} LinkedList;
typedef LinkedList Stack;
#endif

void push(Stack *sPtr, char item);
int pop(Stack *sPtr);
int peek(Stack s);
int isEmptyStack(Stack s);

void removeAllItemsFromStack(Stack *sPtr);

Stack* lineEditor(char* line);
int test_main(Stack* (*editor)(char*),void (*removeAllItemsFromStack)(Stack *));

int main()
{
    test_main(lineEditor,removeAllItemsFromStack);
    return 0;
}

void push(Stack *sPtr, char item)
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

Stack* lineEditor(char* line){
    int caps = 0;

    Stack *s = (Stack*)malloc(sizeof(Stack));
    Stack *s2 = (Stack*)malloc(sizeof(Stack));
    s->head = NULL;
    s->size = 0;
    s2->head = NULL;
    s2->size = 0;
    char holder;
    int x = 0;
    holder = line[x];
    while(holder)
    {
        holder = *(line+x);
        if(holder == '\\')
        {
                push(s,'\n');
        }
        else if(holder == '^')
        {
            if(caps==1)
            {
                caps = 0;
            }
            else if(caps == 0)
            {
                caps = 1;
            }
        }
        else if(holder == '*')
        {
            if(!isEmptyStack(*s))
            {
                pop(s);
            }
        }
        else if(holder == '#')
        {
            if(!isEmptyStack(*s))
            {
                while((peek(*s))!='\n')
                {
                    pop(s);
                }
            }
        }
        else
        {
            if(caps == 1)
            {
                 holder = toupper(holder);
                caps = 0;
            }

            push(s,holder);
        }

        x++;
    }
    while(!(isEmptyStack(*s)))
    {
        push(s2,s->head->item);
        pop(s);
    }

    return s2;
}
