/*
------------------------------------------------------------------------------------------
File:    main.c
Project: oyew8960_quiz08(new)
Purpose: Stimulate a login entry.
==========================================================================================

Program Description:
  This program will load username/password sets from a file that the programmer creates 
  (See password.txt for the example format). Then, insert the usernames/passwords into a 
  chained hash table until the file's end is reached. 
  ***Example Output***
  The program then will give a login prompt, read a username, present a password prompt 
  and print "Correct authentication" or "Failure to authenticate" after looking up the 
  username/password in the hash table.
------------------------------------------------------------------------------------------
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

// output macros
#define CORRECT "Correct authentication" 
#define WRONG "Failure to authenticate" 

const char delim[] = "    "; // space to demarcate


int main()
{
    FILE *fp = fopen("password.txt","r");

    // testing for successful opening
    if (fp == NULL)
        printf("The file did not open.");
    
    else
    {   
        ll_Node* table = ht_Initialize(SIZE); // initialize the hash table
        typeStr username, password; // username and password variables for input file
        char usr_username[20], usr_password[20]; // user login id variables
        char c[50];

        //inserting into the table
        while (fgets(c,sizeof(c),fp) != NULL) 
        {   
            //splits the line, ptr points to the first set of strings before the delimeter
            typeStr ptr = strtok(c, delim);  
            username = ptr; // stores it in username

            // splits the c again now from \0 which replaced the delimeter at the first strtok
            ptr = strtok(NULL, delim);
            strtok(ptr, "\n"); // to remove the trailing new line character
            password = ptr; // stores it in password
            ht_Insert(table,username,password); 
        }

         // getting user input 
        printf("Login: ");
        scanf("%s", usr_username);
        printf("Password: ");
        scanf(" %s", usr_password);
        printf("\n");
        
        //confirming authentication (searches the table and the correct output is shown)
        int authenticate = search(table, usr_username, usr_password);
        switch (authenticate)
        {
            case 0 : printf(WRONG);break;
            case 1 : printf(CORRECT);break;
        }
    }
   
    fclose(fp);
    return 0;
}