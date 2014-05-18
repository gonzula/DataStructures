//
//  main.c
//  DataStructures
//
//  Created by Gonzo Fialho on 5/16/14.
//  Copyright (c) 2014 CEAFDC. All rights reserved.
//

#include <stdio.h>
#include "List.h"
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
    List *list = initList();
    int * a;
    a= (int*)malloc(sizeof(int));
    *a = 3;
    appendObjectToList(list, a);
    a= (int*)malloc(sizeof(int));
    *a = 4;
    appendObjectToList(list, a);
    a= (int*)malloc(sizeof(int));
    *a = 3213;
    appendObjectToList(list, a);
    a= (int*)malloc(sizeof(int));
    *a = 123;
    appendObjectToList(list, a);
    a= (int*)malloc(sizeof(int));
    *a = 321;
    appendObjectToList(list, a);
    a= (int*)malloc(sizeof(int));
    *a = 5;
    appendObjectToList(list, a);
    
    a= (int*)malloc(sizeof(int));
    *a = 69;
    pushObjectToList(list, a);
    
    popFromList(list);
    dequeueFromList(list);
    
    for (Node * thisNode = list->firstNode;
         thisNode;
         thisNode = thisNode->next)
    {
        int i = *(int*)thisNode->object;
        if (thisNode->next)
            printf("%d, ", i);
        else
            printf("%d", i);
    }
    puts("\n");
    
    for (Node * thisNode = list->lastNode;
         thisNode;
         thisNode = thisNode->prev)
    {
        int i = *(int*)thisNode->object;
        if (thisNode->prev)
            printf("%d, ", i);
        else
            printf("%d", i);
    }
    puts("\n");
    
    freeList(list);

    return 0;
}

