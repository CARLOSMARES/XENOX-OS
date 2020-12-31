#include <Core/hash.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int hashCode(int key)
{
    return key % SIZE;
}

struct DataItem *search(int key)
{
    int hashIndex = hashCode(key);
    while (hashArray[hashIndex] != NULL)
    {
        if(hashArray[hashIndex]->key == key)
        {
            return hashArray[hashIndex];
        }
        ++hashIndex;
        hashIndex %= SIZE;
    }
    return NULL;
}

void insert(int key, int data)
{
    struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
    item->data = data;
    item->key = key;
    int hashIndex = hashCode(key);
    while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1)
    {
        ++hashIndex;
        hashIndex %= SIZE
    }
    hashArray[hashIndex] = item;
}

struct DataItem *deleted(struct DataItem* item)
{
    int key = item->key;
    int hashIndex = hashCode(key);
    while (hashArray[hashIndex] != NULL)
    {
        if (hashArray[hashIndex]->key = key)
        {
            struct DataItem* temp = hashArray[hashIndex];
            hashArray[hashIndex] = dummyItem;
            return temp;
        }
        ++hashIndex;
        hashIndex %= SIZE;        
    }
    return NULL;
}

void display()
{
    int i = 0;
    for ( i = 0; i < SIZE; i++)
    {
        if (hashArray[i] != NULL)
        {
            printf("(%d,%d)", hashArray[i]->key, hashArray[i]->data);
        }
        else
        {
            printf(" == ");
        }
    }
    printf("\n");
}