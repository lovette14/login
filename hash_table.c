/*
------------------------------------------------------------------------------------------
File:    hash_table.c
Project: oyew8960_quiz08(new)
Purpose: Functions for a Chained Hash Table
==========================================================================================
Author:  Lovette Oyewole
ID:      190888960
Email:   wilfridlaurier@mylaurier.ca
Version  2020-11-21
-------------------------------------
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "hash_table.h"

int Hash_Fuction(typeStr username, typeStr password)
{
  int index, user= 0,pass = 0,i;

  // getting username ascii values
  for (i=0; username[i];i++)
  {
    user += username[i];
  }
  
  // getting password ascii values
  for (i=0; password[i]; i++)
  {
    pass+= password[i];
  }

  // calculating index
  index = abs(user-pass) % SIZE;
  
  return index;
}

ll_Node* llNodeCreate(typeStr password)
{
  ll_Node* node = malloc(sizeof(ll_Node)); // allocating space for new node
  node->password = password;
  node->next = NULL;
  return node;
}

ll_Node* ht_Initialize(int size)
{
  
  ll_Node* table = (ll_Node*) malloc(size*sizeof(ll_Node)); // makes space for the each slot in the table

  for (int i = 0; i<size; i++)
  {
    table[i].next = NULL; // makes all the table heads NULL
  }

  return table;
}

void ht_Insert(ll_Node* table, typeStr username, typeStr password)
{
  ll_Node* newNode = llNodeCreate(password); // creates a new linked node
  int index = Hash_Fuction(username, password); // getting the place in the hash table for the login id
  
  if (table[index].next == NULL) // if slot is empty
    table[index].next = newNode;

  else
  {
    ll_Node *curr = table[index].next; // makes curr the head of the list at that slot
    
    while (curr->next != NULL) // stops at tail
    {
      curr = curr->next;
    }
    curr->next = newNode; // newNode is now tail of head
  }
}

bool search(ll_Node* table,typeStr username, typeStr password)
{
  int i = Hash_Fuction(username,password); // gets location

  bool found;
  if (table[i].next == NULL) // if slot is empty
    found = false;

  else
  {
    ll_Node* curr = table[i].next; // makes curr head of the ll
    while (curr->next != NULL && (strcmp(curr->password,password)!= 0) ) 
    //strcmp returns 0 if they match
      {
        curr = curr->next;
      }
    
    if (strcmp(curr->password,password) == 0) // if password matches, found is true
        found = true;
        
  }
  return found;
}






















