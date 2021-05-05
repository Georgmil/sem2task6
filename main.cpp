#include "zadanie.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>




int main(){
    listx *headx=NULL;
    listy *heady=NULL;
    headx=NULL;
    heady=NULL;


   int n=1;
    while(n){
        printf("\n\n");
        printf("This is a menu, you will now see the options:\n");
        printf("Type 1 to set a task:\n");
        scanf("%d",&n);
        switch(n){
        case 1:
            printf("Vvedite urovnenie:\n");
            char stroka[100];
            scanf("%s",stroka);
            char pol[100]="";
            zadanie(headx,heady,stroka,pol);
            break;
        }
    }
return 0;
}
