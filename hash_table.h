/*
------------------------------------------------------------------------------------------
File:    hash_table.h
Project: oyew8960_quiz08(new)
Purpose: Functions Declarations
==========================================================================================

Program Description:
  This file holds the declarations of functions and structures used in hash_table.c file 
------------------------------------------------------------------------------------------
Author:  Lovette Oyewole
ID:      190888960
Email:   wilfridlaurier@mylaurier.ca
Version  2020-11-21
-------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>

#define SIZE 101 // size of hash table(prime num to ensure as much less collision as possible)
typedef char* typeStr; // define generic string type

// linked list node structure
typedef struct llItem
{
    typeStr password; 
    struct llItem *next;
}ll_Node;


// does the hashing
// abs(username-password) % size
int Hash_Fuction(typeStr username, typeStr password);

// creates a linked list node 
ll_Node* llNodeCreate(typeStr password);

// creates a hash table and makes all the list at each spot null
ll_Node* ht_Initialize(int size);

// inserts a linked list node into a hash table
void ht_Insert(ll_Node* table,typeStr username, typeStr password);

// searches for a password
// returns true if password is found
bool search(ll_Node* table,typeStr username, typeStr password);
