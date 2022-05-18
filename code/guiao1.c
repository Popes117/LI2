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

void realadd(STACK *s,Container x, Container y){
    Container z;
    if (_Ylabel_ == 3 ||_Xlabel_ == 3)
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

void add4str(STACK *s,Container x, Container y)
{
    if(_Xlabel_ == 3){
        char aux[2];
        aux[0] = _Xcar_;
        aux[1] = '\0';
        _Ystr_ = strcat(_Ystr_,aux);
        push(s,y);

    }
    else{
        size_t l1 = strlen(_Ystr_);
        size_t l2 = strlen(_Xstr_);
        char* res = malloc(l1 + l2 + 1);
        memcpy(res,_Ystr_,l1);
        memcpy(res+l1,_Xstr_,l2+1);
        memcpy(_Ystr_,res,l1+l2+1);
        free(res);
        push(s,y);
    }
}

void add(STACK *s){
    
    Container x = pop(s);
    Container y = pop(s);
    if (_Ylabel_ == 3 && _Xlabel_ == 4)
    {
        _Xstr_[strlen(_Xstr_)+1] = '\0';
        for (int i = strlen(_Xstr_); i>0; i--)
        {
            _Xstr_[i] = _Xstr_[i-1];
        }
        _Xstr_[0] = _Ycar_;
        push(s,x);
    }
    else if(_Xlabel_ == 5 && _Ylabel_ != 5){
        prepush(_Xarr_,y);
        push(s,x);
    }
    else if (_Ylabel_ == 5){
        arrcat(_Yarr_,x);
        push(s,y);
        if(_Xlabel_ == 5){
            free(_Xarr_->stack);
            free(_Xarr_);
        }
    }
    else if(_Ylabel_ == 4){
        add4str(s,x,y);
    }
    else{
        realadd(s,x,y);
    }
}

void foldr(STACK *s, Container x, Container y, Container *vars){
    STACK *min = ministack();
    push(min,_Yarr_->stack[1]);
    push(min,_Yarr_->stack[2]);
    int i = 3;
    while (i <= _Yarr_->sp)
    {
        char *helper = strdup(_Xstr_);
        parser(min,helper,vars);
        push(min,_Yarr_->stack[i]);
        i++;
        free(helper);
    }
    char *helper = strdup(_Xstr_);
    parser(min,helper,vars);
    free(helper);
    Container z = min->stack[1];
    free(_Yarr_->stack);
    free(_Yarr_);
    push(s,z);
}

void realmult(STACK *s, Container x, Container y){
    Container z;
    if (_Ylabel_ == 1 ||_Xlabel_ == 1)
    {
        x = toDouble(x);
        y = toDouble(y);
        _Zlabel_ = 1;
        _ZnumD_ = _XnumD_*_YnumD_;
        push(s,z);
    }
    else
    {
        _Zlabel_ =_Xlabel_;
        _ZnumI_ = _XnumI_*_YnumI_;
        push(s,z);
    }
}

void mult(STACK *s, Container *vars)
{
    
    Container x = pop(s);
    Container y = pop(s);
    Container z;
    if (_Xlabel_ == 6)
    {
        foldr(s,x,y,vars);
    }
    else if (_Ylabel_ == 5)
    {
        Container aux;
        _Auxlabel_ = 5;
        _Auxarr_ = new_stack();
        arrcat(_Auxarr_,y);
        while (_XnumI_ > 1)
        {
            arrcat(_Yarr_,aux);
            _XnumI_--;
        } 
        push(s,y);
        free(_Auxarr_->stack);
        free(_Auxarr_);
    }
    else if(_Ylabel_ == 4)
    {
        _Zlabel_ = 4;
        _Zstr_ = alloccStr();
        _Zstr_ = strcpy(_Zstr_,_Ystr_);
        while (_XnumI_ > 1)
        {
            _Zstr_ = strcat(_Zstr_,_Ystr_);
            _XnumI_--;
        }
        push(s,z);
    }
    else{
        realmult(s,x,y);
    }
}

void division(STACK *s)
{
    Container x = pop(s);
    Container y = pop(s);
    Container z;
    if (_Ylabel_ == 4)
    {
        _Zlabel_ = 5;
        _Zarr_ = new_stack();
        char *token = alloca(BUFSIZ);
        while ((token = strtok_r(_Ystr_,_Xstr_,&_Ystr_))!= NULL)
        {
            Container aux;
            _Auxlabel_ = 4;
            _Auxstr_ = token;
            push(_Zarr_,aux);
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
Container rmarr2(STACK *s, Container x){
    Container z = pop(_Xarr_);
    push(s,x);
    return z;
}

void add1(STACK *s)
{
    Container y = pop(s);
    if (_Ylabel_ == 4) 
    {
        Container x;
        _Xlabel_ = 3;
        _Xcar_ = _Ystr_[strlen(_Ystr_)-1];
        _Ystr_[strlen(_Ystr_)-1] = '\0';
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
        Container z = rmarr2(s,y);
        push(s,z);
    }
    else {
        _Ycar_++;
        push(s,y);
    }
}

// ( guião 4
Container rmarr1(STACK *s, Container x){
    int i;
    Container y;
    _Ylabel_ = 5;
    _Yarr_ = new_stack();
    STACK *aux = _Xarr_;
    for(i = 2; i <= aux->sp; i++) {
        Container z = aux->stack[i];
        push(_Yarr_,z);
    }
    Container z = aux->stack[1];
    while(aux->sp >= 1) pop(aux);
    push(s,y);
    return z;
}

void sub1(STACK *s)
{
    Container y = pop(s);
    if (_Ylabel_ == 4) 
    {
        Container x;
        _Xlabel_ = 3;
        _Xcar_ = _Ystr_[0];
        _Ystr_++;
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
        Container z = rmarr1(s,y);
        push(s,z);
    }
    else {
        _Ycar_--;
        push(s,y);
    }
}

void mod(STACK *s, Container *vars)
{   
    Container x = pop(s);
    Container y = pop(s);
    Container z;
    if (_Xlabel_ == 6)
    {
        STACK *min = new_stack();
        if (_Ylabel_ == 5)
        {   
            for (int i = 1; i <= _Yarr_->sp;i++)
            {
                push(min,_Yarr_->stack[i]);
                char *helper = strdup(_Xstr_);
                parser(min,helper,vars);
                free(helper);
            }
            free(_Yarr_->stack);
            free(_Yarr_);
            _Yarr_ = min;
            push(s,y);
        }
        else
        {
            _Zlabel_ = 3;
            char *str = strdup(_Ystr_);
            for (int i = 0; str[i] != '\0';i++)
            {
                _Zcar_ = str[i];
                char *helper = strdup(_Xstr_);
                push(min,z);
                parser(min,helper,vars);
                _Ystr_[i] = min->stack[1].type.car;
                pop(min);
                free(helper);

            }
            push(s,y);
        }
    }
    else
    {
        x = toInt(x);
        y = toInt(y);
        _Zlabel_ = 2;
        _ZnumI_= _YnumI_%_XnumI_;
        push(s,z);
    }
}

size_t forloop(Container x,Container y, short *val){
    size_t i = 0;
    for (; i < strlen(_Xstr_) && *val; i++)
    {
        if (_Ystr_[i] != _Xstr_[i])
        {
            *val = 0;
        }
    }
    return i;
}

void expo(STACK *s)
{
    Container x = pop(s);
    Container y = pop(s);
    Container z;
    if (_Ylabel_ == 4)
    {
        long pos = 0;
        short val = 1;
        short end = 1;
        while (_Ystr_[0] != '\0' && end)
        {
            if (_Ystr_[0] == _Xstr_[0])
            {
                size_t i = 0;
                val = 1;
                i = forloop(x,y,&val);
                if(i == strlen(_Xstr_)){
                    end = 0;
                }
            }
            pos++;
            _Ystr_++;
        }
        if (end)
        {
            pos = 0;
        }
        _Zlabel_ = 2;
        _ZnumI_ = --pos;
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

void not_bit(STACK *s, Container *vars)
{
    Container x = pop(s);
    pop(s);
    if(_Xlabel_ == 6){
        Container y = pop(s);
        STACK *min = ministack();
        push(min,y);
        char *helper = strdup(_Xstr_);
        parser(min,helper,vars);
        push(s,min->stack[1]);
        free(min->stack);
        free(min);
    }
    else if (_Xlabel_ == 5)
    {
        for(int i = 1; i <= _Xarr_->sp; i++) {
        push(s,_Xarr_->stack[i]);
        }
    }
    else if(s->sp == 1){
            x = toInt(x);
            _XnumI_ = ~_XnumI_;
            push(s,x);
        }
    else{
        Container y = pop(s);
        if(_Ylabel_==5){
            int i;
            STACK *aux = _Xarr_;
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
    }

void truthy(STACK *s, Container *vars){
    Container x = pop(s);
    Container y = pop(s);
    STACK *min = new_stack();
    Container z;
    push(min,y);
    while (_ZnumI_ != 0)
    {
        z = min->stack[1];
        char *helper = strdup(_Xstr_);
        parser(min,helper,vars);
        free(helper);
    }
    push(s,z);
}
