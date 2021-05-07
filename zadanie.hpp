#ifndef ZADANIE_HPP_INCLUDED
#define ZADANIE_HPP_INCLUDED

#include "zadanie.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Nodex{
    float id;
    struct Nodex *next;
    } listx;

typedef struct Nodey{
    char id;
    struct Nodey *next;
    } listy;



void zadanie(listx *headx,listy *heady,char stroka[], char pol[]);
void pushx(listx **headx,float value);
void pushy(listy **heady,char value);
void printlinkx(listx *nodeptr);
void printlinky(listy *nodeptr);
int prioritet(char a);
char verhy(listy *nodeptr);
float verhx(listx *nodeptr);
float predverhx(listx *nodeptr);
void popx(listx **headx);
void popy(listy **heady);
void poljaki(char pol[],char a);



#endif // ZADANIE_HPP_INCLUDED
