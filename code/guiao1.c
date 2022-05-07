#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operators.h"
#include "stack.h"
#include <math.h>
#include "macro.h"
#include "parser.h"
#include "alloca.h"

void sub(STACK *s)
{
    
    Container x = pop(s);
    Container y = pop(s);
    Container z;
    
    if (_Ylabel_ == 3 ||_Xlabel_ == 3)
    {
        x = toChar(x);
        y = toChar(y);
        _Zlabel_ = 3;
        _Zcar_ = _Ycar_-_Xcar_;
    }
    else if (_Ylabel_ == 1 ||_Xlabel_ == 1)
    {
        x = toDouble(x);
        y = toDouble(y);
        _Zlabel_ = 1;
        _ZnumD_ = _YnumD_-_XnumD_;
    }
    else{
        _Zlabel_ =_Xlabel_;
        _ZnumI_ = _YnumI_-_XnumI_;
    }
    push(s,z);
}

void add(STACK *s){
    
    Container x = pop(s);
    Container y = pop(s);
    Container z;
    if(_Xlabel_ == 5 && _Ylabel_ != 5){
        prepush(x.a,y);
        push(s,x);
    }
    else if (_Ylabel_ == 5){
        arrcat(y.a,x);
        push(s,y);
    }
    else if(_Ylabel_ == 4 ){
        y.str = strcat(y.str,x.str);
        push(s,y);
    }
    else if (_Ylabel_ == 3 ||_Xlabel_ == 3)
    {
        x = toChar(x);
        y = toChar(y);
        _Zlabel_ = 3;
        _Zcar_ = _Xcar_+_Ycar_;
        push(s,z);
    }
    else if (_Ylabel_ == 1 ||_Xlabel_ == 1)
    {
        x = toDouble(x);
        y = toDouble(y);
        _Zlabel_ = 1;
        _ZnumD_ = _XnumD_+_YnumD_;
        push(s,z);
    }
    else
    {
        _Zlabel_ =_Xlabel_;
        _ZnumI_ = _XnumI_+_YnumI_;
        push(s,z);
    }
}

void mult(STACK *s)
{
    
    Container x = pop(s);
    Container y = pop(s);
    Container z;
    if (_Ylabel_ == 5)
    {
        
    }
    else if(_Ylabel_ == 4)
    {
        z.label = 4;
        z.str = alloccStr();
        z.str = strcpy(z.str,y.str);
        while (_XnumI_ > 1)
        {
            z.str = strcat(z.str,y.str);
            _XnumI_--;
        }
    }
    else if (_Ylabel_ == 1 ||_Xlabel_ == 1)
    {
        x = toDouble(x);
        y = toDouble(y);
        _Zlabel_ = 1;
        _ZnumD_ = _XnumD_*_YnumD_;
    }
    else
    {
        _Zlabel_ =_Xlabel_;
        _ZnumI_ = _XnumI_*_YnumI_;
    }
    push(s,z);
}

void division(STACK *s)
{
    Container x = pop(s);
    Container y = pop(s);
    Container z;
    if (_Ylabel_ == 4)
    {
        z.label = 5;
        z.a = new_stack();
        char *token = alloca(BUFSIZ);
        while ((token = strtok_r(y.str,x.str,&y.str))!= NULL)
        {
            Container aux;
            aux.label = 4;
            aux.str = token;
            push(z.a,aux);
        }
    }
    else if (_Ylabel_ ==_Xlabel_ && _Xlabel_ == 2)
    {
        _Zlabel_ =_Xlabel_;
        _ZnumI_ = _YnumI_/_XnumI_;
    }
    else
    {
        x = toDouble(x);
        y = toDouble(y);
        _Zlabel_ = 1;
        _ZnumD_ = _YnumD_/_XnumD_;
    }
    push(s,z);
}

// ) guião 4
void rmarr2(STACK *s, Container x) {
    int i;
    Container y;
    y.label = 5;
    y.a = new_stack();
    STACK *aux = x.a;
    for(i = 1; i < aux->sp; i++) {
        Container z = aux->stack[i];
        push(y.a,z);
    }
    Container z = pop(aux);
    while(aux->sp >= 1) pop(aux);
    push(s,y);
    push(s,z);
}

void add1(STACK *s)
{
    Container y = pop(s);
    if (_Ylabel_ == 4) 
    {
        Container x;
        x.label = 3;
        x.type.car = y.str[strlen(y.str)-1];
        y.str[strlen(y.str)-1] = '\0';
        push(s,y);
        push(s,x);
    }
    else if(_Ylabel_ == 1){
        _YnumD_++;
        push(s,y);
    }
    else if(_Ylabel_ == 2){
        _YnumI_++;
        push(s,y);
    }
    else if(_Ylabel_ == 5) {
        rmarr2(s,y);
        push(s,y);
    }
    else {
        _Ycar_++;
        push(s,y);
    }
}

// ( guião 4
void rmarr1(STACK *s, Container x) {
    int i;
    Container y;
    y.label = 5;
    y.a = new_stack();
    STACK *aux = x.a;
    for(i = 2; i <= aux->sp; i++) {
        Container z = aux->stack[i];
        push(y.a,z);
    }
    Container z = aux->stack[1];
    while(aux->sp >= 1) pop(aux);
    push(s,y);
    push(s,z);
}

void sub1(STACK *s)
{
    Container y = pop(s);
    if (_Ylabel_ == 4) 
    {
        Container x;
        x.label = 3;
        x.type.car = y.str[0];
        y.str++;
        push(s,y);
        push(s,x);
    }
    else if(_Ylabel_ == 1){
        _YnumD_--;
        push(s,y);
    }
    else if(_Ylabel_ == 2){
        _YnumI_--;
        push(s,y);
    }
    else if(_Ylabel_ == 5) {
        rmarr1(s,y);
        push(s,y);
    }
    else {
        _Ycar_--;
        push(s,y);
    }
}

void mod(STACK *s)
{
    Container x = pop(s);
    Container y = pop(s);
    Container z;
    x = toInt(x);
    y = toInt(y);
    _Zlabel_ = 2;
    _ZnumI_= _YnumI_%_XnumI_;
    push(s,z);
}

void expo(STACK *s)
{
    Container x = pop(s);
    Container y = pop(s);
    Container z;
    if (_Ylabel_ == 4)
    {
        long pos = -1;
        short val = 1;
        z.label = 2;
        for (int i = 0; y.str[i] != '\0'; i++)
        {
            val = 1;
            int z = 0;
            if (x.str[z] == y.str[i])
            {
                for (; x.str[z] != '\0' && val; z++){
                    if(x.str[z] != y.str[i]) val = 0;
                }
                if (val = 1 && pos == -1)
                {
                    pos = i;
                } 
            }
        }
        z.type.numI = pos;
        push(s,z);
    }
    else{
        x = toDouble(x);
        y = toDouble(y);
        _Zlabel_ = 1;
        _ZnumD_ = pow(_YnumD_,_XnumD_);
        push(s,z);
    }
}

void e_bit(STACK *s)
{
    Container x = pop(s);
    Container y = pop(s);
    Container z;
    x = toInt(x);
    y = toInt(y);
    _Zlabel_ = 2;
    _ZnumI_ = _YnumI_&_XnumI_;
    push(s,z);
}

void ou_bit(STACK *s)
{
    Container x = pop(s);
    Container y = pop(s);
    Container z;
    x = toInt(x);
    y = toInt(y);
    _Zlabel_ = 2;
    _ZnumI_ = _YnumI_|_XnumI_;
    push(s,z);
}

void xor_bit(STACK *s)
{
    Container x = pop(s);
    Container y = pop(s);
    Container z;
    x = toInt(x);
    y = toInt(y);
    _Zlabel_ = 2;
    _ZnumI_ = _YnumI_^_XnumI_;
    push(s,z);

}

void not_bit(STACK *s)
{
    Container x = pop(s);
    Container y = pop(s);
    if(y.label == 5 || _Xlabel_ == 5){
    int i;
    STACK *aux = x.a;
    for(i = 0; i <= aux->sp; i++) {
        Container y = aux->stack[i];
        push(s,y);
        }
    }
    else{
    x = toInt(x);
    _XnumI_ = ~_XnumI_;
    push(s,x);
    }
}
