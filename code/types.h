
typedef struct {
        int label; 
        /* 
           1 - Double
           2 - Long
           3 - Char
        */
        union HoldType {
                long numI;

                double numD;
                
                char car;
        } type;

} Container;

// #define LONG type.numI;

// #define DOUBLE type.numD;

// #define CHAR type.car;



