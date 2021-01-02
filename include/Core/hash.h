/*
    Autor: Carlos Ignacio Olano Mares
    2020-2021
    Libreria que facilita el uso de hash en C
*/
#ifndef _HASH_H
#define _HASH_H

#define SIZE 20

    struct DataItem
    {
        int data;
        int key;
    };

    struct DataItem* hashArray[SIZE];
    struct DataItem* dummyItem;
    struct DataItem* item;

    int hashCode(int key);
    struct DataItem *search(int key);
    void insert(int key, int data);
    struct DataItem *deleted(struct DataItem* item);
    void display();

#endif