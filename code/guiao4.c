#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operators.h"
#include "stack.h"
#include <math.h>
#include "parser.h"
#include "type_changes.h"
#include "macro.h"

void readFile(STACK *s)
{
    char linha[BUFSIZ];
    Container z;
    z.label = 4;
    z.str = alloccStr();
    z.str[0] = '\0';
    while (fgets(linha,BUFSIZ,stdin) != NULL)
    {
        z.str = strcat(z.str,linha);
    }
    push(s,z);
}

void tamanho(STACK *s) {
    Container x = pop(s);
    Container y;
    y.label = 2;
    if(_Xlabel_ == 2){
        Container z;
        z.label = 5;
        z.a = new_stack();
        for(int i = 0; i < x.type.numI; i++){
            y.type.numI = i;
            push(z.a,y);
        }
        push(s,z);
    }
    else if(_Xlabel_ == 5){
        STACK *aux = x.a;
        Container z;
        z.label = 2;
        z.type.numI = aux->sp;
        push(s,z);
    }
    else
     {   
        for(;x.str[_YnumI_]!='\0';_YnumI_++);
        push(s,y);
    }
}

void til(STACK *s) {
    int i;
    Container x = pop(s);
    STACK *aux = x.a;
    for(i = 1; i <= aux->sp; i++) {
        Container y = aux->stack[i];
        push(s,y);
    }
}

void arrcat(STACK *s, Container z) {
    if (z.label != 5)
    {
        push(s,z);
    }
    else {
        for (size_t i = 1; i <= z.a->sp; i++)
        {  
            push(s,z.a->stack[i]);
           if(z.a->stack[i].label == 4) free(z.a->stack[i].str);
        }
    }
}

void strtoke(STACK *s)
{
    Container y = pop(s);
    Container z;
    z.label = 5;
    z.a = new_stack();
    char *token = alloca(BUFSIZ);
    while ((token = strtok_r(y.str," \n",&y.str))!= NULL)
    {
        Container aux;
        aux.label = 4;
        aux.str = token;
        push(z.a,aux);
    }
    push(s,z);
}

void strtoke2(STACK *s)
{
    Container y = pop(s);
    Container z;
    z.label = 5;
    z.a = new_stack();
    char *token = alloca(BUFSIZ);
    while ((token = strtok_r(y.str,"\n",&y.str))!= NULL)
    {
        Container aux;
        aux.label = 4;
        aux.str = token;
        push(z.a,aux);
    }
    push(s,z);
}

/* ()
void rmarr1(STACK *s, Container x) {
    Container y;
    y.label = 5;
    y.a = new_stack();
    STACK *aux = x.a;
    while(aux->sp != 1) {
        Container z = pop(aux);
        push(y.a,z);
    }
    Container z = pop(aux);
    push(s,y);
    push(s,z);
    // ciclo que vai passando os elementos da aux para outra stack e dps da pop(aux)
}
*/

// void indice(STACK *s) {
//     int x = pop(s).type.numI;
//     Container y = pop(s);
//     STACK *aux = y.a;
//     Container z = aux->stack[x+1];
//     push(s,z);
// }

// void concatena(STACK *s){
//     Container x = pop(s);
//     Container y = pop(s);
//     y.label = 2;
//     if(_Xlabel_ == 5){
//         STACK *auxX = x.a;
//         Container z;
//         _Zlabel_ = 2;
//         z.str = x.str; //strcat(x.str,y.str);
//     }
// }

// void maioR(STACK *s) {
//     Container x = pop(s);
//     Container y = pop(s);
//     Container z;
//     z.str = alloccStr();
//     int l;
//     if (_Ylabel_ == 4) {
//         l = strlen(y.str) - x.type.numI;
//         while(l <= (l+x.type.numI)) {
//             z.str = strcat(z.str,y.str[l]);
//             l++;
//         }
//         push(s,z);
//     }
// }


//  Tá feito o ~ e a , 
//  DONE *
//  DONE +

//  Falta: 

//  = (Quase feita)
//  < 
//  >
//  ( 
//  )
//  #
//  t
//  /
//  S/
//  N/