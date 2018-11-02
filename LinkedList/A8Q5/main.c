#include <stdio.h>
#include <stdlib.h>

#ifndef _NODE_
#define _NODE_
typedef struct _node{
     int item;
     struct _node *next;
}numNode;

typedef struct _nodeOp{
     char item;
     struct _nodeOp *next;
}opNode;

typedef struct _linkedlistEx{
    numNode *numHead;
    opNode *opHead;
}LinkedListExp;
#endif
void expressionLL(char* exp,LinkedListExp* llE);

int main(){
     test_main(expressionLL);
     return 0;
}

void expressionLL(char* exp,LinkedListExp* llE){
    llE->numHead = malloc(sizeof(numNode));
    llE->opHead = malloc(sizeof(opNode));
    numNode *num;
    opNode *op;
    num = llE->numHead;
    op = llE->opHead;
    char s;
    int i = 0;
    int count = 0;
    int opcount = 0;
    int wasOp = 0;
    s = exp[i];
    while(s!='\0')
    {

        if((s>='0') && (s<='9'))
        {

            if(wasOp == 1)
            {
                numNode *num2;
            num2 = (numNode*)malloc(sizeof(numNode));

            num->next = num2;

            num = num->next;
            wasOp = 0;

            }

            if(count > 0)
            {
                num->item = ((num->item)*10)+(atoi(&s));
            }
            else
            {
                num->item = (atoi(&s));
                count++;
            }
        }
        else
        {
            if(opcount == 0)
            {
                op->item = s;
                opcount++;
            }
            else
            {
            opNode *op2;
            op2 = (opNode*)malloc(sizeof(opNode));
            op->next = op2;
            op = op->next;
            }
            count = 0;
            op->item=s;
            wasOp = 1;
        }
        i++;
        s = exp[i];
    }
    num->next = NULL;
    op->next = NULL;


}
