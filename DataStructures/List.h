//
//  List.h
//  DataStructures
//
//  Created by Gonzo Fialho on 5/16/14.
//  Copyright (c) 2014 CEAFDC. All rights reserved.
//

#ifndef DataStructures_List_h
#define DataStructures_List_h

typedef struct Node
{
    void * object;
    struct Node * prev;
    struct Node * next;
} Node;

typedef struct
{
    Node * firstNode;
    Node * lastNode;
    int count;
} List;

List * initList();
List * appendObjectToList(List *aList, void * object);
List * pushObjectToList(List *aList, void * object);
void * popFromList(List *aList);
void * dequeueFromList(List* aList);
void freeList(List* aList);

#endif
