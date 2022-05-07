#include "type_changes.h"
#include "macro.h"

Container toInt(Container x){
    if ( _Xlabel_ == 4){
        _Xlabel_ = 2;
        long z;
        sscanf(x.str,"%ld",&z);
        x.type.numI = z;
    }
    if ( _Xlabel_ == 1)
    {
         _Xlabel_ = 2;
        _XnumI_ = _XnumD_;
    }
    else if ( _Xlabel_ == 3)
    {
         _Xlabel_ = 2;
        _XnumI_ = _Xcar_;
    }
    return x;
}

Container toDouble(Container x){
    if ( _Xlabel_ == 4){
        _Xlabel_ = 1;
        double z;
        sscanf(x.str,"%lf",&z);
        //free(x.str);
        x.type.numD = z;
    }
    else if ( _Xlabel_ == 2)
    {
         _Xlabel_ = 1;
        _XnumD_= _XnumI_;
    }
    if ( _Xlabel_ == 3)
    {
         _Xlabel_ = 1;
        _XnumD_ = _Xcar_;
    }
    return x;
}

Container toChar(Container x){
    if ( _Xlabel_ == 4){
        _Xlabel_ = 3;
        char z;
        sscanf(x.str,"%c",&z);
        x.type.car = z;
    }
    if ( _Xlabel_ == 1)
    {
        int n = _XnumD_;
         _Xlabel_ = 3;
        _Xcar_ = n;
    }
    if ( _Xlabel_ == 2)
    {
         _Xlabel_ = 3;
        _Xcar_ = _XnumI_;
    }
    return x;
}

void fill(Container *vars){
    vars[0].label = 2;
    vars[0].type.numI = 10;
    vars[1].label = 2;
    vars[1].type.numI = 11;
    vars[2].label = 2;
    vars[2].type.numI = 12;
    vars[3].label = 2;
    vars[3].type.numI = 13;
    vars[4].label = 2;
    vars[4].type.numI = 14;
    vars[5].label = 2;
    vars[5].type.numI = 15;
    vars[13].label = 3;
    vars[13].type.car = '\n';
    vars[18].label = 3;
    vars[18].type.car = ' ';
    vars[23].label = 2;
    vars[23].type.numI = 0;
    vars[24].label = 2;
    vars[24].type.numI = 1;
    vars[25].label = 2;
    vars[25].type.numI = 2;
}

int comparaCont( Container x, Container y){
    if( _Xlabel_ != 3 && y.label != 3)
    {
        x = toDouble(x);
        y = toDouble(y);
        if (_XnumD_== _YnumD_) return 1;
        else if (_XnumD_ > _YnumD_) return 2;
        else return 3;
    }
    else
    {
        x = toChar(x);
        y = toChar(y);
        if (_Xcar_ == _Ycar_) return 1;
        else return 0;
    }
}

int isZero(Container x){
    if ( _Xlabel_ == 1) return (_XnumD_ != 0);
    else if ( _Xlabel_ == 2) return (_XnumI_ != 0);
    else if (_Xlabel_ == 5) return (x.a->sp != 0);
    return 0;
}