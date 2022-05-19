#include "stack.h"
#include "type_changes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#pragma once

/**
 * @file Ficheiro que contém todas as funções criadas e usadas em cada Guião.
 */


// Funções no Guião 1

void sub(STACK *s);
/**
 * @brief Aplica a operação de subtração aos 2 elementos do topo da stack
 * 
 * @param STACK
 */
void realadd(STACK *s,Container x, Container y);
/**
 * @brief Faz a adição de dois valores e coloca o resultado no topo da stack.
 *        No caso de um dos containers recebidos ser um char, o resultado será também do tipo char.
 * 
 * @param STACK
 * @param Container 
 * @param Container 
 */
void add4str(STACK *s,Container x, Container y);

void add(STACK *s);
/**
 * @brief Aplica a operação de adição aos 2 elementos do topo da stack
 * 
 * @param STACK
 */
void foldr(STACK *s, Container x, Container y, Container *vars);
/**
 * @brief Aplica um bloco a um Array ou String
 * 
 * @param STACK
 * @param Container
 * @param Container
 * @param Container
 */
void realmult(STACK *s, Container x, Container y);
/**
 * @brief Faz a multiplicação de dois valores numéricos e coloca o resultado no topo da stack.
 * 
 * @param STACK
 * @param Container 
 * @param Container 
 */
void mult(STACK *s, Container *vars);
/**
 * @brief Aplica a operação de multiplicação aos 2 elementos do topo da stack
 * 
 * @param STACK
 * @param Container
 */
void division(STACK *s);
/**
 * @brief Aplica a operação de divisão aos 2 elementos do topo da stack
 * 
 * @param STACK 
 */
Container rmarr2(STACK *s, Container x);
/**
 * @brief Remove um elemento do fim de um array e coloca-o no topo da stack
 * 
 * @param STACK
 * @param Container 
 */
void add1(STACK *s);
/**
 * @brief Incrementa um valor
 * 
 * @param STACK
 */
Container rmarr1(STACK *s, Container x);
/**
 * @brief Remove um elemento do início de um array e coloca-o no topo da stack
 * 
 * @param STACK
 * @param Container 
 */
void sub1(STACK *s);
/**
 * @brief Decrementa um valor
 * 
 * @param STACK
 */
void mod(STACK *s, Container *vars);
/**
 * @brief Devolve o resto da divisão ou aplica um Bloco a um Array/String
 * 
 * @param STACK
 * @param Container
 */
size_t forloop(Container x,Container y, short *val);
/**
 * @brief Devolve o resto da divisão ou aplica um Bloco a um Array/String
 * 
 * @param Container
 * @param Container
 * @param short 
 */
void expo(STACK *s);
/**
 * @brief Faz a exponenciação do primeiro elemento do topo da stack com o segundo
 * 
 * @param STACK
 */
void e_bit(STACK *s);
/**
 * @brief Aplica a função lógica E 
 * 
 * @param STACK
 */
void ou_bit(STACK *s);
/**
 * @brief Aplica a função lógica Ou
 * 
 * @param STACK
 */
void xor_bit(STACK *s);

void not_bit(STACK *s, Container *vars);
/**
 * @brief Faz a negação do output esperado
 * 
 * @param STACK
 * @param Container
 */
void truthy(STACK *s, Container *vars);
/**
 * @brief Executa o bloco enquanto ele deixar um truthy no topo da stack e Remove da stack a condição
 * 
 * @param STACK
 * @param Container
 */
// Funções no Guião 2

void duplica(STACK *s);
/**
 * @brief Duplica o elemento do topo da stack
 * 
 * @param STACK
 */
void switch2(STACK *s);
/**
 * @brief Troca os 2 elementos do topo da stack
 * 
 * @param STACK
 */
void roda3(STACK *s);
/**
 * @brief Roda os 3 elementos do topo da stack
 * 
 * @param STACK
 */
void copy_help(STACK *min,Container x, Container y, Container *vars);
/**
 * @brief Função auxiliar criada para uso na função copy
 * 
 * @param STACK
 * @param Container
 * @param Container
 * @param Container 
 */
void copy(STACK *s, Container *vars);
/**
 * @brief Copia o n-ésimo elemento para o topo da stack
 * 
 * @param STACK
 * @param Container
 */
void nextLine(STACK *s);

void ConvChar(STACK *s);
/**
 * @brief Converte um Container para um char
 * 
 * @param STACK
 */
void ConvInt(STACK *s);
/**
 * @brief Converte um Container para um int
 * 
 * @param STACK
 */
void ConvFloat(STACK *s);
/**
 * @brief Converte um Container para um float
 * 
 * @param STACK
 */

// Funções no Guião 3

void coloca(STACK *s,Container *vars, char *token);

void ifelse(STACK *s);
/**
 * @brief Se o primeiro elemento for diferente de 0 ou de vazio retorna o segundo elemento, caso contrário devolve o terceiro elemento
 * 
 * @param STACK 
 */
void igual(STACK *s);
/**
 * @brief Verifica se os 2 elementos do topo da stack são iguais
 * 
 * @param STACK
 */
void strmaior(STACK *s,Container x, Container y);
/**
 * @brief Compara os 2 elementos de tipo string do topo da stack e devolve True se X for maior 
 * 
 * @param STACK
 * @param Container
 * @param Container
 */
void maior(STACK *s);
/**
 * @brief Compara os 2 elementos do topo da stack e devolve o maior
 * 
 * @param STACK
 */
void popmachine(STACK *x , int f);
/**
 * @brief Faz pop do topo da stack enquanto f é diferente de 0
 * 
 * @param STACK
 * @param Int 
 */
void strmenor(STACK *s,Container x, Container y);
/**
 * @brief Compara os 2 elementos de tipo string do topo da stack e devolve True se X for menor
 * 
 * @param STACK
 * @param Container
 * @param Container
 */
void menor(STACK *s);
/**
 * @brief Compara os 2 elementos do topo da stack e devolve o menor
 * 
 * @param STACK
 */
void eAnd(STACK *s);

void eOr(STACK *s);

void eMaior(STACK *s);
/**
 * @brief  Coloca o maior dos 2 elementos na stack
 * 
 * @param STACK
 */
void eMenor(STACK *s);
/**
 * @brief Coloca o menor dos 2 elementos na stack
 * 
 * @param STACK
 */
void nots(STACK *s);
/**
 * @brief Devolve o valor lógico oposto da operação afetada
 * 
 * @param STACK
 */
// Funções no Guião 4

void readFile(STACK *s);

void tamanho2(STACK *s, Container z);

void compare(STACK *s, Container x, Container y, Container *vars);

void tamanho(STACK *s, Container *vars);
/**
 * @brief Calcula o tamanho ou range do array
 * 
 * @param STACK
 * @param Container
 */
void arrcat(STACK *s, Container z);
/**
 * @brief Concatena Arrays 
 * 
 * @param STACK
 * @param Container
 */
void strtoke(STACK *s);

void strtoke2(STACK *s);

