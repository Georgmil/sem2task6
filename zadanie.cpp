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
}

char verhy(listy *nodeptr){
    char c=nodeptr->id;
    return c;
}
char predverhy(listy *nodeptr){
    return nodeptr->next->id;
}

float verhx(listx *nodeptr){
    return nodeptr->id;
}
float predverhx(listx *nodeptr){
    return nodeptr->next->id;
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

void zadanie(listx *headx,listy *heady,char stroka[], char pol[]){
    int length=strlen(stroka);
    bool pervij=true,pervijminus=false, proshli=false,znakps=false,error=false;
    int i=0;
    while(i<length){
        char str[100]="";
        if(((stroka[i]!='(')&&(stroka[i]!=')')&&(stroka[i]!='+')&&(stroka[i]!='-')&&(stroka[i]!='=')&&(stroka[i]!='/')&&(stroka[i]!='*'))&&((stroka[i+1]!='(')&&(stroka[i+1]!=')')&&(stroka[i+1]!='+')&&(stroka[i+1]!='-')&&(stroka[i+1]!='*')&&(stroka[i+1]!='/')&&(stroka[i+1]!='='))){
            int j=i;
            while((stroka[j]!='(')&&(stroka[j]!=')')&&(stroka[j]!='+')&&(stroka[j]!='-')&&(stroka[j]!='=')&&(stroka[j]!='/')&&(stroka[j]!='*')){
                if(stroka[j]=='e'){
                    j=j+4;
                }
                else{
                    j=j+1;
                }
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
            i=i-1;
        }

        else if(stroka[i]=='0'){
            pushx(&headx,0);
            char t='0';
            strncat(pol,&t,1);}
        else if(stroka[i]=='1'){
            if(pervijminus==true || znakps==true){
                pushx(&headx,-1);
                char t='-';
                strncat(pol,&t,1);
                char q='1';
                strncat(pol,&q,1);
                char l=' ';
                strncat(pol,&l,1);
                pervijminus=false;
                znakps=false;}
            else{
               pushx(&headx,1);
               char t='1';
                strncat(pol,&t,1);
                char l=' ';
                strncat(pol,&l,1);}
            }
            else if(stroka[i]=='2'){
                if(pervijminus==true || znakps==true){
                    pushx(&headx,-2);
                    char t='-';
                    strncat(pol,&t,1);
                    char q='2';
                    strncat(pol,&q,1);
                    char l=' ';
                    strncat(pol,&l,1);
                    pervijminus=false;
                    znakps=false;}
                else{
                    pushx(&headx,2);
                    char t='2';
                    strncat(pol,&t,1);
                    char l=' ';
                    strncat(pol,&l,1);}
            }
        else if(stroka[i]=='3'){
                if(pervijminus==true || znakps==true){
                    char t='-';
                    strncat(pol,&t,1);
                    char q='3';
                    strncat(pol,&q,1);
                    char l=' ';
                    strncat(pol,&l,1);
                    pushx(&headx,- 3);
                    pervijminus=false;
                    znakps=false;}
                else{
                    pushx(&headx,3);
                    char t='3';
                    strncat(pol,&t,1);
                    char l=' ';
                    strncat(pol,&l,1);}
            }

        else if(stroka[i]=='4'){
                if(pervijminus==true || znakps==true){
                    pushx(&headx,-4);
                    char t='-';
                    strncat(pol,&t,1);
                    char q='4';
                    strncat(pol,&q,1);
                    char l=' ';
                    strncat(pol,&l,1);
                    pervijminus=false;
                    znakps=false;}
                else{
                    pushx(&headx,4);
                    char t='4';
                    strncat(pol,&t,1);
                    char l=' ';
                    strncat(pol,&l,1);}
            }

        else if(stroka[i]=='5'){
                if(pervijminus==true || znakps==true){
                    pushx(&headx,-5);
                    char t='-';
                    strncat(pol,&t,1);
                    char q='5';
                    strncat(pol,&q,1);
                    char l=' ';
                    strncat(pol,&l,1);
                    pervijminus=false;
                    znakps=false;}
                else{
                    pushx(&headx,5);
                    char t='5';
                    strncat(pol,&t,1);
                    char l=' ';
                    strncat(pol,&l,1);}
            }
        else if(stroka[i]=='6'){
                if(pervijminus==true || znakps==true){
                    pushx(&headx,-6);
                    char t='-';
                    strncat(pol,&t,1);
                    char q='6';
                    strncat(pol,&q,1);
                    char l=' ';
                    strncat(pol,&l,1);
                    pervijminus=false;
                    znakps=false;}
                else{
                    pushx(&headx,6);
                    char q='6';
                    strncat(pol,&q,1);
                    char l=' ';
                    strncat(pol,&l,1);}
            }
        else if(stroka[i]=='7'){
                if(pervijminus==true || znakps==true){
                    pushx(&headx,-7);
                    char t='-';
                    strncat(pol,&t,1);
                    char q='7';
                    strncat(pol,&q,1);
                    char l=' ';
                    strncat(pol,&l,1);
                    pervijminus=false;
                    znakps=false;}
                else{
                    pushx(&headx,7);
                    char q='7';
                    strncat(pol,&q,1);
                    char l=' ';
                    strncat(pol,&l,1);}
            }
        else if(stroka[i]=='8'){
                if(pervijminus==true || znakps==true){
                    pushx(&headx,-8);
                    char t='-';
                    strncat(pol,&t,1);
                    char q='8';
                    strncat(pol,&q,1);
                    char l=' ';
                    strncat(pol,&l,1);
                    pervijminus=false;
                    znakps=false;}
                else{
                    pushx(&headx,8);
                    char q='8';
                    strncat(pol,&q,1);
                    char l=' ';
                    strncat(pol,&l,1);}
            }
        else if(stroka[i]=='9'){
                if(pervijminus==true || znakps==true){
                    pushx(&headx,-9);
                    char t='-';
                    strncat(pol,&t,1);
                    char q='9';
                    strncat(pol,&q,1);
                    char l=' ';
                    strncat(pol,&l,1);
                    pervijminus=false;
                    znakps=false;}
                else{
                    pushx(&headx,9);
                    char q='9';
                    strncat(pol,&q,1);
                    char l=' ';
                    strncat(pol,&l,1);}
            }
        //+
        else if(stroka[i]=='+'){
            if(pervij==true){
                pushy(&heady,'+');
                pervij=false;}
            else if(prioritet('+')>prioritet(verhy(heady))){
                pushy(&heady,'+');
                pervij=false;}
            else if(prioritet('+')==prioritet(verhy(heady))){
                if(verhy(heady)=='+'){
                    char q='+';
                    strncat(pol,&q,1);
                    char l=' ';
                    strncat(pol,&l,1);
                    float res=predverhx(headx)+verhx(headx);
                    popx(&headx);
                    popx(&headx);
                    pushx(&headx,res);
                    popy(&heady);
                    pushy(&heady,'+');
                    pervij=false;
                }
                else if(verhy(heady)=='-'){
                    char q='-';
                    strncat(pol,&q,1);
                    char l=' ';
                    strncat(pol,&l,1);
                    float res=predverhx(headx)-verhx(headx);
                    popx(&headx);
                    popx(&headx);
                    pushx(&headx,res);
                    popy(&heady);
                    pushy(&heady,'+');
                    pervij=false;
                }
            }
            else{
                if(verhy(heady)=='*'){
                    char q='*';
                    strncat(pol,&q,1);
                    char l=' ';
                    strncat(pol,&l,1);
                    float res=predverhx(headx)*verhx(headx);
                    popx(&headx);
                    popx(&headx);
                    pushx(&headx,res);
                    popy(&heady);
                    pushy(&heady,'+');
                    pervij=false;}

                else if(verhy(heady)=='/'){
                    if(verhx(headx)==0){
                        printf("Error!, cannot devide on 0");
                        error=true;
                        break;
                    }
                    else{
                    char q='/';
                    strncat(pol,&q,1);
                    int res=predverhx(headx)/verhx(headx);
                    popx(&headx);
                    popx(&headx);
                    pushx(&headx,res);
                    popy(&heady);
                    pushy(&heady,'+');
                    pervij=false;}
                }
            }
        }
        //-
        else if(stroka[i]=='-'){
            if(znakps==true){
                znakps=true;
                i++;
                continue;}
            else if(pervij==true){
                if((stroka[0]=='-')&&(proshli==false)){
                    pervijminus=true;
                    proshli=true;
                    i++;
                    continue;}
                else{
                pervij=false;
                pushy(&heady,'-');
                i++;
                continue;}
            }
            else if(prioritet('-')>prioritet(verhy(heady))){
                pushy(&heady,'-');
                pervij=false;
                i++;
                continue;
            }

            while(pervij==false){
                if(prioritet('-')==prioritet(verhy(heady))){
                    if(verhy(heady)=='-'){
                        char q='-';
                        strncat(pol,&q,1);
                        char l=' ';
                        strncat(pol,&l,1);
                        float res=predverhx(headx)-verhx(headx);
                        popx(&headx);
                        popx(&headx);
                        pushx(&headx,res);
                        popy(&heady);
                        if(heady==NULL||(verhy(heady)=='(')){
                            pervij=true;
                        }
                        else{
                            pervij=false;
                    }
                }
                    else if(verhy(heady)=='+'){
                            char q='+';
                            strncat(pol,&q,1);
                            char l=' ';
                            strncat(pol,&l,1);
                            float res=predverhx(headx)+verhx(headx);
                            popx(&headx);
                            popx(&headx);
                            pushx(&headx,res);
                            popy(&heady);
                            if(heady==NULL||(verhy(heady)=='(')){
                                pervij=true;
                            }
                            else{
                                pervij=false;
                            }
                    }
                }
                else{
                    if(verhy(heady)=='*'){
                        char q='*';
                        strncat(pol,&q,1);
                        char l=' ';
                        strncat(pol,&l,1);
                        float res=predverhx(headx)*verhx(headx);
                        popx(&headx);
                        popx(&headx);
                        pushx(&headx,res);
                        popy(&heady);
                        if(heady==NULL||(verhy(heady)=='(')){
                            pervij=true;
                        }
                        else{
                            pervij=false;
                    }
                }
                    else if(verhy(heady)=='/'){
                        if(verhx(headx)==0){
                            printf("Error!, cannot devide on 0");
                            break;
                            error=true;
                        }
                        else{
                            char q='/';
                            strncat(pol,&q,1);
                            char l=' ';
                            strncat(pol,&l,1);
                            float res=predverhx(headx)/verhx(headx);
                            popx(&headx);
                            popx(&headx);
                            pushx(&headx,res);
                            popy(&heady);
                            if(heady==NULL||(verhy(heady)=='(')){
                                pervij=true;
                            }
                            else{
                                pervij=false;
                            }
                        }
                    }
                }
        }pushy(&heady,'-');
        pervij=false;
    }

        //*
        else if(stroka[i]=='*'){
            if(pervij==true){
                pushy(&heady,'*');
                pervij=false;}
            else if(prioritet('*')>prioritet(verhy(heady))){
                pushy(&heady,'*');
                pervij=false;
                }
            else if(prioritet('*')==prioritet(verhy(heady))){
                if(verhy(heady)=='*'){
                    char q='*';
                    strncat(pol,&q,1);
                    char l=' ';
                    strncat(pol,&l,1);
                    float res=predverhx(headx)*verhx(headx);
                    popx(&headx);
                    popx(&headx);
                    pushx(&headx,res);
                    popy(&heady);
                    pushy(&heady,'*');
                    pervij=false;
                }
                else if(verhy(heady)=='/'){
                    if(verhx(headx)==0){
                        printf("Error!, cannot devide on 0");
                        error=true;
                        break;
                        }
                    else{
                        char q='/';
                        strncat(pol,&q,1);
                        char l=' ';
                        strncat(pol,&l,1);
                        float res=predverhx(headx)/verhx(headx);
                        popx(&headx);
                        popx(&headx);
                        pushx(&headx,res);
                        popy(&heady);
                        pushy(&heady,'*');
                        pervij=false;
                    }
            }
        }
    }
        // /
        else if(stroka[i]=='/'){
            if(pervij==true){
                pushy(&heady,'/');
                pervij=false;}

            else if(prioritet('/')>prioritet(verhy(heady))){
                pushy(&heady,'/');
                pervij=false;
            }

            else if(prioritet('/')==prioritet(verhy(heady))){
                if(verhy(heady)=='/'){
                    if(verhx(headx)==0){
                        printf("Error!, cannot devide on 0");
                        error=true;
                        break;
                    }
                    else{
                        char q='/';
                        strncat(pol,&q,1);
                        char l=' ';
                        strncat(pol,&l,1);
                        float res=predverhx(headx)/verhx(headx);
                        popx(&headx);
                        popx(&headx);
                        pushx(&headx,res);
                        popy(&heady);
                        pushy(&heady,'/');
                        pervij=false;}
                }
                else if(verhy(heady)=='*'){
                        char q='*';
                        strncat(pol,&q,1);
                        char l=' ';
                        strncat(pol,&l,1);
                        float res=predverhx(headx)*verhx(headx);
                        popx(&headx);
                        popx(&headx);
                        pushx(&headx,res);
                        popy(&heady);
                        pushy(&heady,'/');
                        pervij=false;
                    }
            }
        }
        // (
        else if(stroka[i]=='('){
            if(stroka[i+1]=='-'){
                znakps=true;
                pushy(&heady,'(');
            }
            else{
                pushy(&heady,'(');
            }
        }
        // )
        else if(stroka[i]==')'){
                znakps=false;
                while(verhy(heady)!='('){
                    if(verhy(heady)=='+'){
                        char q='+';
                        strncat(pol,&q,1);
                        char l=' ';
                        strncat(pol,&l,1);
                        float res=predverhx(headx)+verhx(headx);
                        popx(&headx);
                        popx(&headx);
                        popy(&heady);
                        pushx(&headx,res);
                    }
                    else if(verhy(heady)=='-'){
                        char q='-';
                        strncat(pol,&q,1);
                        char l=' ';
                        strncat(pol,&l,1);
                        float res=predverhx(headx)-verhx(headx);
                        popx(&headx);
                        popx(&headx);
                        popy(&heady);
                        pushx(&headx,res);
                    }
                    else if(verhy(heady)=='*'){
                        char q='*';
                        strncat(pol,&q,1);
                        char l=' ';
                        strncat(pol,&l,1);
                        float res=predverhx(headx)*verhx(headx);
                        popx(&headx);
                        popx(&headx);
                        popy(&heady);
                        pushx(&headx,res);
                    }
                    else if(verhy(heady)=='/'){
                        if(verhx(headx)==0){
                            printf("Error!, cannot devide on 0");
                            error=true;
                            break;
                        }
                        else{
                        char q='/';
                        strncat(pol,&q,1);
                        char l=' ';
                        strncat(pol,&l,1);
                        float res=predverhx(headx)/verhx(headx);
                        popx(&headx);
                        popx(&headx);
                        popy(&heady);
                        pushx(&headx,res);}
                    }
            }
            if(verhy(heady)=='(')
                 popy(&heady);
            if(heady==NULL){
                pervij=true;
            }
        //=
    }
        else if(stroka[i]=='='){
            while(heady!=NULL){
                if(verhy(heady)=='+'){
                    char q='+';
                    strncat(pol,&q,1);
                    char l=' ';
                    strncat(pol,&l,1);
                    double res=predverhx(headx)+verhx(headx);
                    popx(&headx);
                    popx(&headx);
                    popy(&heady);
                    pushx(&headx,res);
                }
                else if(verhy(heady)=='-'){
                    char q='-';
                    strncat(pol,&q,1);
                    char l=' ';
                    strncat(pol,&l,1);
                    float res=predverhx(headx)-verhx(headx);
                    popx(&headx);
                    popx(&headx);
                    popy(&heady);
                    pushx(&headx,res);
                }
                else if(verhy(heady)=='*'){
                    char q='*';
                    strncat(pol,&q,1);
                    char l=' ';
                    strncat(pol,&l,1);
                    float res=predverhx(headx)*verhx(headx);
                    popx(&headx);
                    popx(&headx);
                    popy(&heady);
                    pushx(&headx,res);
                }
                else if(verhy(heady)=='/'){
                    if(verhx(headx)==0){
                        printf("Error!, cannot devide on 0");
                        error=true;
                        break;
                    }
                    else{
                        char q='/';
                        strncat(pol,&q,1);
                        char l=' ';
                        strncat(pol,&l,1);
                        float res=predverhx(headx)/verhx(headx);
                        popx(&headx);
                        popx(&headx);
                        popy(&heady);
                        pushx(&headx,res);}
                }
            }
            pushy(&heady,'=');

    } i++;

}
if(error==false){
        printf("Resultat:\n");
        printlinkx(headx);
        printf("\n\n");
        printf("Polskaja zapis:\n");
        printf("%s",pol);
    }

}

