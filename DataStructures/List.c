//
//  List.c
//  DataStructures
//
//  Created by Gonzo Fialho on 5/16/14.
//  Copyright (c) 2014 CEAFDC. All rights reserved.
//

#include <stdio.h>
#include "List.h"
#include <stdlib.h>
#include <string.h>

List * initList()
{
    List * aList = (List*)malloc(sizeof(List));
    aList->count = 0;
    aList->firstNode = NULL;
    aList->lastNode = NULL;
    return aList;
}

List * appendObjectToList(List *aList, void * object)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->object = object;
    newNode->next = NULL;
    newNode->prev = aList->lastNode;

    if (!aList->count) aList->firstNode = newNode;
    else aList->lastNode->next = newNode;
    aList->lastNode = newNode;    
    aList->count++;
    return aList;
}

List * pushObjectToList(List *aList, void * object)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->object = object;
    newNode->next = aList->firstNode;
    newNode->prev = NULL;
    
    if (!aList->count) aList->lastNode = newNode;
    else aList->firstNode->prev = newNode;
    aList->firstNode = newNode;
    aList->count++;
    
    return aList;
}

void * popFromList(List *aList)
{
    if (!aList->count) return NULL;
    Node * node = aList->firstNode;
    void * object = node->object;
    node->next->prev = NULL;
    aList->firstNode = node->next;
    free(node);
    aList->count--;
    if (!aList->count) aList->lastNode = NULL;
    return object;
}

void * dequeueFromList(List* aList)
{
    if (!aList->count) return NULL;
    Node * node = aList->lastNode;
    void * object = node->object;
    node->prev->next = NULL;
    aList->lastNode = node->prev;
    free(node);
    aList->count--;
    if (!aList->count) aList->firstNode = NULL;
    return object;
}

void freeList(List* aList)
{
    for (int i = 0; i < aList->count; i++)
    {
//        Node * node = nodeAtIndex(aList, i);
//        free(node->object);
//        free(node);
    }
    free(aList);
}







