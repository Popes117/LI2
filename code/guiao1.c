#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operators.h"
#include "stack.h"
#include <math.h>
#include "macro.h"

void sub(STACK *s)
{
    
    Container x = pop(s);
    Container y = pop(s);
    Container z;
    
    if (_Ylabel_ == 3 ||_Xlabel_ == 3)
    {
        x = toChar(x);
        y = toChar(y);
        z.label = 3;
        z.type.car = _Ycar_-_Xcar_;
    }
    else if (_Ylabel_ == 1 ||_Xlabel_ == 1)
    {
        x = toDouble(x);
        y = toDouble(y);
        z.label = 1;
        z.type.numD = _YnumD_-_XnumD_;
    }
    else{
        z.label =_Xlabel_;
        z.type.numI = _YnumI_-_XnumI_;
    }
    push(s,z);
}

void add(STACK *s){
    
    Container x = pop(s);
    Container y = pop(s);
    Container z;
    if (_Ylabel_ == 3 ||_Xlabel_ == 3)
    {
        x = toChar(x);
        y = toChar(y);
        z.label = 3;
        z.type.car = _Xcar_+_Ycar_;
    }
    else if (_Ylabel_ == 1 ||_Xlabel_ == 1)
    {
        x = toDouble(x);
        y = toDouble(y);
        z.label = 1;
        z.type.numD = _XnumD_+_YnumD_;
    }
    else
    {
        z.label =_Xlabel_;
        z.type.numI = _XnumI_+_YnumI_;
    }
    push(s,z);
}

void mult(STACK *s)
{
    
    Container x = pop(s);
    Container y = pop(s);
    Container z;
    if (_Ylabel_ == 1 ||_Xlabel_ == 1)
    {
        x = toDouble(x);
        y = toDouble(y);
        z.label = 1;
        z.type.numD = _XnumD_*_YnumD_;
    }
    else
    {
        z.label =_Xlabel_;
        z.type.numI = _XnumI_*_YnumI_;
    }
    push(s,z);
}

void division(STACK *s)
{
    Container x = pop(s);
    Container y = pop(s);
    Container z;
    if (_Ylabel_ ==_Xlabel_ &&_Xlabel_ == 2)
    {
        z.label =_Xlabel_;
        z.type.numI = _YnumI_/_XnumI_;
    }
    else
    {
        x = toDouble(x);
        y = toDouble(y);
        z.label = 1;
        z.type.numD = _YnumD_/_XnumD_;
    }
    push(s,z);
}

void add1(STACK *s)
{
    Container y = pop(s);
    if(_Ylabel_ == 1)_YnumD_++;
    if(_Ylabel_ == 2)_YnumI_++;
    else _Ycar_++;
    push(s,y);
}

void sub1(STACK *s)
{
    Container y = pop(s);
    if(_Ylabel_ == 1)_YnumD_--;
    if(_Ylabel_ == 2)_YnumI_--;
    else y.type.car--;
    push(s,y);
}

void mod(STACK *s)
{
    Container x = pop(s);
    Container y = pop(s);
    Container z;
    x = toInt(x);
    y = toInt(y);
    z.label = 2;
    z.type.numI= _YnumI_%_XnumI_;
    push(s,z);
}

void expo(STACK *s)
{
    Container x = pop(s);
    Container y = pop(s);
    Container z;
    x = toDouble(x);
    y = toDouble(y);
    z.label = 1;
    z.type.numD = pow(_YnumD_,_XnumD_);
    push(s,z);
}

void e_bit(STACK *s)
{
    Container x = pop(s);
    Container y = pop(s);
    Container z;
    x = toInt(x);
    y = toInt(y);
    z.label = 2;
    z.type.numI = _YnumI_&_XnumI_;
    push(s,z);
}

void ou_bit(STACK *s)
{
    Container x = pop(s);
    Container y = pop(s);
    Container z;
    x = toInt(x);
    y = toInt(y);
    z.label = 2;
    z.type.numI = _YnumI_|_XnumI_;
    push(s,z);
}

void xor_bit(STACK *s)
{
    Container x = pop(s);
    Container y = pop(s);
    Container z;
    x = toInt(x);
    y = toInt(y);
    z.label = 2;
    z.type.numI = _YnumI_^_XnumI_;
    push(s,z);

}

void not_bit(STACK *s)
{
    Container x = pop(s);
    x = toInt(x);
    _XnumI_ = ~_XnumI_;
    push(s,x);
}