#include "zadanie.hpp"

void pushx(listx **headx,float value){

        listx* newnode=(listx*)malloc(sizeof(listx));

        newnode->id=value;

        newnode->next=*headx;

        *headx=newnode;

}
void pushy(listy **heady,char value){

        listy* newnode=(listy*)malloc(sizeof(listy));

        newnode->id=value;

        newnode->next=*heady;

        *heady=newnode;

}
void printlinkx(listx *nodeptr){
    while(nodeptr!=NULL){

        printf("%.2f",nodeptr->id);
        nodeptr=nodeptr->next;
        if(nodeptr!=NULL)
            printf("-->");
    }
        }
void printlinky(listy *nodeptr){
    while(nodeptr!=NULL){

        printf("%c",nodeptr->id);
        nodeptr=nodeptr->next;
        if(nodeptr!=NULL)
            printf(" ");
    }
        }


int prioritet(char a){
    if(a=='=')
        return 0;
    if(a=='(')
        return 1;
    if(a=='+'||a=='-')
        return 2;
    if(a=='*'|| a=='/')
        return 3;
    if(a=='!')
        return -1;
}

char verhy(listy *nodeptr){
    if(nodeptr==NULL){
        char c1='!';
        return c1;
    }
    else{
        char c=nodeptr->id;
        return c;
    }
}
char predverhy(listy *nodeptr){
    return nodeptr->next->id;
}

float verhx(listx *nodeptr){
    return nodeptr->id;
}


void popx(listx **headx){
    listx *tmp;

    tmp=*headx;
    *headx=(*headx)->next;
    free(tmp);
}
void popy(listy **heady){
    listy *tmp;

    tmp=*heady;
    *heady=(*heady)->next;
    free(tmp);
}
void poljaki(char pol[],char a){
            char q=a;
            strncat(pol,&q,1);
            char l=' ';
            strncat(pol,&l,1);

}

void zadanie(listx *headx,listy *heady,char stroka[], char pol[]){
    int length=strlen(stroka),i=0;
    bool pervij=true,pervijminus=false, proshli=false,znakps=false,error=false;
    while(i<length){
        char str[100]="";
        int j=i;
        if(stroka[j]>='0'&& stroka[j]<='9'){
            while(stroka[j]>='0'&& stroka[j]<='9'){
                j++;
            }
            if(stroka[j]=='.'){
                j++;
            }
            while(stroka[j]>='0'&& stroka[j]<='9'){
                j++;
            }
            if(stroka[j]=='e'){
                j=j+4;
            }

            if(pervijminus==true||znakps==true){
                char c='-';
                proshli=true;
                strncat(str,&c,1);
                strncat(pol,&c,1);}

            while(i<j){
                char ch=stroka[i];
                strncat(str,&ch,1);
                strncat(pol,&ch,1);
                i++;
                }
            double number=atof(str);
            pushx(&headx,number);

            char l=' ';
            strncat(pol,&l,1);
            pervijminus=false;
            znakps=false;
            continue;
        }

        if(stroka[i]=='('){
            if(stroka[i+1]=='-'){
                pushy(&heady,'(');
                znakps=true;
            }
            else{
                pushy(&heady,'(');
            }
        }
        else if(stroka[i]==')'){
            while(verhy(heady)!='('){
                char q=verhy(heady);
                poljaki(pol,q);
                float a=verhx(headx);
                popx(&headx);
                float b=verhx(headx);
                popx(&headx);

                if(q=='+'){
                    float res=b+a;
                    pushx(&headx,res);
                    }
                else if(q=='-'){
                    float res=b-a;
                    pushx(&headx,res);
                    }
                else if(q=='*'){
                    float res=b*a;
                    pushx(&headx,res);
                    }
                else if(q=='/'){
                    if(a==0){
                        printf("Error!, cannot devide on 0");
                        error=true;
                            break;}
                    else{
                        float res=b/a;
                        pushx(&headx,res);}
                }
                popy(&heady);
            }
            if(verhy(heady)=='(')
                 popy(&heady);
            if(heady==NULL)
                pervij=true;
        }

        else if(pervij==true || znakps==true){
            if((stroka[0]=='-')&&(proshli==false)){
                pervijminus=true;
                proshli=true;
            }
            else if(znakps==true){
                i++;
                continue;
            }
            else{
            pushy(&heady,stroka[i]);
            pervij=false;
            }
        }
        else if((prioritet(stroka[i]))>(prioritet(verhy(heady)))){
            pushy(&heady,stroka[i]);
        }
        else{
            while(prioritet(stroka[i])<=prioritet(verhy(heady))){
                    float a=verhx(headx);
                    popx(&headx);
                    float b=verhx(headx);
                    popx(&headx);

                    if(verhy(heady)=='-'){
                        poljaki(pol,'-');
                        float res=b-a;
                        pushx(&headx,res);
                    }
                    else if(verhy(heady)=='+'){
                        poljaki(pol,'+');
                        float res=b+a;
                        pushx(&headx,res);
                    }
                    else if(verhy(heady)=='*'){
                        poljaki(pol,'*');
                        float res=b*a;
                        pushx(&headx,res);
                    }
                    else if(verhy(heady)=='/'){
                        if(a==0){
                            printf("Error!, cannot devide on 0");
                            error=true;
                            break;}
                        else{
                            poljaki(pol,'/');
                            float res=b/a;
                            pushx(&headx,res);}
                    }
                    popy(&heady);
                    if(heady==NULL){
                        pervij=true;
                    }
                }
            pushy(&heady,stroka[i]);
            pervij=false;
        }

    i++;
    }

    if(error==false){
        printf("Resultat:\n");
        printlinkx(headx);
        printf("\n\n");
        printf("Polskaja zapis:\n");
        printf("%s",pol);
    }

}

