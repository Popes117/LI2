/**
 * \brief Definição do valor máximo como 1000
 */
#define MAX 1000
#pragma once

/**
 * @file Biblioteca com as funções usadas na stack.c
 */

/** Estrutura responsável pelos tipos Long, Double e Char*/
typedef union HoldType {
                /** Long*/
                long numI;
                
                /** Double*/
                double numD;
                
                /** Char*/
                char car;
                
        } Type;

/** Definição da estrutura Stack*/
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
       /**Union que distribui Arrays, Strings e tipos*/
       union{
                /** Tipo String para Container*/
                char *str;
                
                /** Tipo Array para Container*/
                STACK *a;
               
                /** Tipo do Container*/
                Type type;
       };
} Container;

/** Definição dos conteúdos da Stack*/
struct stack {
        /**Container*/
        Container *stack;
        /** Tamanho da Stack*/
        int sp;
        
};

/**
 * \brief Cria uma nova Stack 
 *
 * @param STACK
 */
STACK* new_stack();

/**
 * \brief Cria uma mini Stack 
 *
 * @param STACK
 */
STACK * ministack();

/**
 * \brief Faz push no início da Stack e não no final 
 *
 * @param STACK
 * @param Container
 *
 */
void prepush(STACK *s, Container container);

/**
 * \brief Devolve o topo da Stack
 *
 * @param STACK
 * @param Container
 *
 * @returns O conteúdo do topo da Stack
 */
void push(STACK *s, Container container);

/**
 * \brief Imprime a Stack
 *
 * @param STACK
 */
Container pop(STACK *s);

/**
 * \brief Faz print da Stack elemento a elemento, dependendo do tipo da label
 *
 * @param STACK
 */
void printer(STACK *s);
