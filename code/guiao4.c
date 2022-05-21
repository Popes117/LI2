#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operators.h"
#include "stack.h"
#include <math.h>
#include "parser.h"
#include "type_changes.h"
#include "macro.h"

/**
 * @file Ficheiro que contém o Guião 4
 */

void readFile(STACK *s)
{
    char linha[BUFSIZ];
    Container z;
    _Zlabel_ = 4;
    _Zstr_ = alloccStr();
    _Zstr_[0] = '\0';
    while (fgets(linha,BUFSIZ,stdin) != NULL)
    {
        _Zstr_ = strcat(_Zstr_,linha);
    }
    push(s,z);
}

void compare(STACK *s, Container x, Container y, Container *vars){
    STACK *min = new_stack();
    if (_Xlabel_ == 6)
    {   
        for (int i = 1; i <= _Yarr_->sp;i++)
        {
            push(min,_Yarr_->stack[i]);
            char *helper = strdup(_Xstr_);
            parser(min,helper,vars);
            free(helper);
        }
        int i = 1;
        int n = 1;
        while (i <= min->sp)
        {
            if (min->stack[i].type.numI == 1 || min->stack[i].type.numD == 1)
            {
                    _Yarr_->stack[n] = _Yarr_->stack[i];
                    n++;
            }
            i++;
        }
        _Yarr_->sp = n-1;
    }
    free(min->stack);
    free(min);
    push(s,y);
}

void tamanho(STACK *s, Container *vars) {
    Container x = pop(s);
    Container y;
    _Ylabel_ = 2;
    if(_Xlabel_ == 6)
    {
        compare(s,x,pop(s),vars);
    }
    if(_Xlabel_ == 2){
        Container z;
        _Zlabel_ = 5;
        _Zarr_ = new_stack();
        for(int i = 0; i < _XnumI_; i++){
            _YnumI_ = i;
            push(_Zarr_,y);
        }
        push(s,z);
    }
    else if(_Xlabel_ == 5){
        STACK *aux = _Xarr_;
        Container z;
        _Zlabel_ = 2;
        _ZnumI_ = aux->sp;
        push(s,z);
    }
    else
     {   
        int n = strlen(_Xstr_);
        _YnumI_ = n;
        push(s,y);
    }
}

void arrcat(STACK *s, Container z) {
    if (_Zlabel_ != 5)
    {
        push(s,z);
    }
    else {
        for (int i = 1; i <= _Zarr_->sp; i++)
        {  
            push(s,_Zarr_->stack[i]);
        }
    }
}

void strtoke(STACK *s)
{
    Container y = pop(s);
    Container z;
    _Zlabel_ = 5;
    _Zarr_ = new_stack();
    char *token = alloca(BUFSIZ);
    while ((token = strtok_r(_Ystr_," \n",&_Ystr_))!= NULL)
    {
        Container aux;
        _Auxlabel_ = 4;
        _Auxstr_ = token;
        push(_Zarr_,aux);
    }
    push(s,z);
}

void strtoke2(STACK *s)
{
    Container y = pop(s);
    Container z;
    _Zlabel_ = 5;
    _Zarr_ = new_stack();
    char *token = alloca(BUFSIZ);
    while ((token = strtok_r(_Ystr_,"\n",&_Ystr_))!= NULL)
    {
        Container aux;
        _Auxlabel_ = 4;
        _Auxstr_ = token;
        push(_Zarr_,aux);
    }
    push(s,z);
}


