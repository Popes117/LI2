#define MAX 1000
#pragma once

/** Estrutura responsável pelos tipos Long, Double e Char*/
typedef union HoldType {
                long numI;
                /** Long*/
                double numD;
                /** Double*/
                char car;
                /** Char*/
        } Type;

typedef struct stack STACK;

/** Definição da estrutura Container*/
typedef struct Container{
        /** Atribuição de um número para cada tipo do Container */
        int label; 
        /* 
           1 - Double
           2 - Long
           3 - Char
           4 - String
           5 - Array
           6 - Bloco
        */
       union{
                char *str;
                /** Tipo String para Container*/
                STACK *a;
                /** Tipo Array para Container*/
                Type type;
       };
} Container;

/** Definição dos conteúdos da Stack*/
struct stack {
        Container *stack;
        int sp;
        /** Tamanho da Stack*/
};

STACK* new_stack();

STACK * ministack();

STACK* reallocSTACK(STACK *s);

void prepush(STACK *s, Container container);

void push(STACK *s, Container container);
/**
 * \brief Devolve o topo da Stack
 *
 * @param STACK
 * @param Container
 *
 * @returns O conteúdo do topo da Stack
 */
Container pop(STACK *s);
/**
 * \brief Imprime a Stack
 *
 * @param STACK
 */
void printer(STACK *s);
/**
 * \brief Faz print da Stack elemento a elemento, dependendo do tipo da label
 *
 * @param STACK
 */