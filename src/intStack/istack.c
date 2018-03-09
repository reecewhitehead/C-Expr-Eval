/*
 *  
 *
 *  Author:  Reece Whitehead
 *	Help from : Robby
 *  Date:    Feb. 2, 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "istack.h"


Node2_t* Node2Create(int value) {
    Node2_t* Node2 = malloc(sizeof(Node2_t));
    Node2->data = value;
    Node2->next = NULL;
    return Node2;
}

void Node2Print(Node2_t Node2) {
    printf("[%d]%s", Node2.data, Node2.next ? "-->" : "--|");
}




IntStack_t istackCreate() {
   IntStack_t stack = {Node2Create(-987654321), NULL};
   stack.tail = stack.head;
   return stack;
}

void istackPrint(const IntStack_t stack) {
   Node2_t* cur = stack.head->next;
   printf("\nstack:  ");
   while (cur != NULL) {
       Node2Print(*cur);
       cur = cur->next;
   }
   printf("\n\n");
}

bool istackIsEmpty(IntStack_t stack) {
   return stack.head->next == NULL;
}

void istackPush(IntStack_t* stack, int value) {
   Node2_t* newNode2 = Node2Create(value);
   if (istackIsEmpty(*stack)) {
      stack->head->next = stack->tail = newNode2;
   }
   else {
      newNode2->next = stack->head->next;
      stack->head->next = newNode2;
   }
}

int istackPop(IntStack_t* stack) {
   assert(!istackIsEmpty(*stack));
   Node2_t* Node2 = stack->head->next;
   stack->head->next = stack->head->next->next;
   int value = Node2->data;
   free(Node2);
   return value;
}


int istackTop( IntStack_t stack){
    
    if(istackIsEmpty(stack)){
        printf("ERROR UNDERFLOW! The list is empty");
        return;
    }
    
    else{
        int value;
        value = stack.head->next->data;
        return value;
    }
    
    
}



void istackDestroy(IntStack_t* list) {
   while (list->head->next != NULL) {
      Node2_t* cur = list->head->next;
      list->head->next = list->head->next->next;
      free(cur);
   }
   list->tail = NULL;
}