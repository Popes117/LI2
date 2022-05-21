#include "stack.h"
#include "type_changes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#pragma once

/**
 * @file Biblioteca que contém todas as funções criadas e usadas em cada Guião.
 */

// Funções no Guião 1

/**
 * @brief Aplica a operação de subtração aos 2 elementos do topo da stack
 * 
 * @param STACK
 */
void sub(STACK *s);

/**
 * @brief Faz a adição de dois valores e coloca o resultado no topo da stack.
 *        No caso de um dos containers recebidos ser um char, o resultado será também do tipo char.
 * 
 * @param STACK
 * @param Container 
 * @param Container 
 */
void realadd(STACK *s,Container x, Container y);

/**
 * @brief Faz a adição de 2 strings
 * 
 * @param STACK
 * @param Container 
 * @param Container 
 */
void add4str(STACK *s,Container x, Container y);

/**
 * @brief Aplica a operação de adição aos 2 elementos do topo da stack
 * 
 * @param STACK
 */
void add(STACK *s);

/**
 * @brief Função que reduz o array pela aplicação de outra ou várias funções
 * 
 * @param STACK
 * @param Container
 * @param Container
 * @param Container
 */
void foldr(STACK *s, Container x, Container y, Container *vars);

/**
 * @brief Faz a multiplicação de dois valores numéricos e coloca o resultado no topo da stack.
 * 
 * @param STACK
 * @param Container 
 * @param Container 
 */
void realmult(STACK *s, Container x, Container y);

/**
 * @brief Aplica a operação de multiplicação aos 2 elementos do topo da stack
 * 
 * @param STACK
 * @param Container
 */
void mult(STACK *s, Container *vars);

/**
 * @brief Aplica a operação de divisão aos 2 elementos do topo da stack
 * 
 * @param STACK 
 */
void division(STACK *s);

/**
 * @brief Remove um elemento do fim de um array e coloca-o no topo da stack
 * 
 * @param STACK
 * @param Container 
 */
Container rmarr2(STACK *s, Container x);

/**
 * @brief Incrementa um valor
 * 
 * @param STACK
 */
void add1(STACK *s);

/**
 * @brief Remove um elemento do início de um array e coloca-o no topo da stack
 * 
 * @param STACK
 * @param Container 
 */
Container rmarr1(STACK *s, Container x);

/**
 * @brief Decrementa um valor
 * 
 * @param STACK
 */
void sub1(STACK *s);

/**
 * @brief Devolve o resto da divisão ou aplica um Bloco a um Array/String
 * 
 * @param STACK
 * @param Container
 */
void mod(STACK *s, Container *vars);

/**
 * @brief Função auxiliar criada para uso na função expo 
 * 
 * @param Container
 * @param Container
 * @param short 
 */
size_t forloop(Container x,Container y, short *val);

/**
 * @brief Faz a exponenciação do primeiro elemento do topo da stack com o segundo
 * 
 * @param STACK
 */
void expo(STACK *s);

/**
 * @brief Aplica a função lógica E 
 * 
 * @param STACK
 */
void e_bit(STACK *s);

/**
 * @brief Aplica a função lógica Ou
 * 
 * @param STACK
 */
void ou_bit(STACK *s);

/**
 * @brief Forma um bitwisexor
 * 
 * @param STACK
 */
void xor_bit(STACK *s);

/**
 * @brief Faz a negação do output esperado
 * 
 * @param STACK
 * @param Container
 */
void not_bit(STACK *s, Container *vars);

/**
 * @brief Executa o bloco enquanto ele deixar um truthy no topo da stack e Remove da stack a condição
 * 
 * @param STACK
 * @param Container
 */
void truthy(STACK *s, Container *vars);

// Funções no Guião 2

/**
 * @brief Duplica o elemento do topo da stack
 * 
 * @param STACK
 */
void duplica(STACK *s);

/**
 * @brief Troca os 2 elementos do topo da stack
 * 
 * @param STACK
 */
void switch2(STACK *s);

/**
 * @brief Roda os 3 elementos do topo da stack
 * 
 * @param STACK
 */
void roda3(STACK *s);

/**
 * @brief Função auxiliar criada para uso na função copy
 * 
 * @param STACK
 * @param Container
 * @param Container
 * @param Container 
 */
void copy_help(STACK *min,Container x, Container y, Container *vars);

/**
 * @brief Copia o n-ésimo elemento para o topo da stack
 * 
 * @param STACK
 * @param Container
 */
void copy(STACK *s, Container *vars);

/**
 * @brief Faz parse de uma nova string 
 * 
 * @param STACK
 */
void nextLine(STACK *s);

/**
 * @brief Converte um Container para um char
 * 
 * @param STACK
 */
void ConvChar(STACK *s);

/**
 * @brief Converte um Container para um int
 * 
 * @param STACK
 */
void ConvInt(STACK *s);

/**
 * @brief Converte um Container para um float
 * 
 * @param STACK
 */
void ConvFloat(STACK *s);


// Funções no Guião 3

/**
 * @brief Define uma variável com o Container anterior
 * 
 * @param STACK
 */
void coloca(STACK *s,Container *vars, char *token);

/**
 * @brief Se o primeiro elemento for diferente de 0 ou de vazio retorna o segundo elemento, caso contrário devolve o terceiro elemento
 * 
 * @param STACK 
 */
void ifelse(STACK *s);

/**
 * @brief Verifica se os 2 elementos do topo da stack são iguais
 * 
 * @param STACK
 */
void igual(STACK *s);

/**
 * @brief Compara os 2 elementos de tipo string do topo da stack e devolve True se X for maior 
 * 
 * @param STACK
 * @param Container
 * @param Container
 */
void strmaior(STACK *s,Container x, Container y);

/**
 * @brief Compara os 2 elementos do topo da stack e devolve o maior
 * 
 * @param STACK
 */
void maior(STACK *s);

/**
 * @brief Faz pop do topo da stack enquanto f é diferente de 0
 * 
 * @param STACK
 * @param Int 
 */
void popmachine(STACK *x , int f);

/**
 * @brief Compara os 2 elementos de tipo string do topo da stack e devolve True se X for menor
 * 
 * @param STACK
 * @param Container
 * @param Container
 */
void strmenor(STACK *s,Container x, Container y);

/**
 * @brief Compara os 2 elementos do topo da stack e devolve o menor
 * 
 * @param STACK
 */
void menor(STACK *s);

/**
 * \brief Se os dois elementos forem diferentes de 0, retorna o segundo elemento. Caso contrário, retorna 0
 *   
 * @param STACK
 */
void eAnd(STACK *s);

/**
 * \brief Se os dois elementos forem iguais a 0, retorna 0. Caso contrário, devolve o primeiro elemento se este for verdadeiro, ou o segundo, caso contrario
 * 
 * @param STACK
 */
void eOr(STACK *s);

/**
 * @brief  Coloca o maior dos 2 elementos na stack
 * 
 * @param STACK
 */
void eMaior(STACK *s);

/**
 * @brief Coloca o menor dos 2 elementos na stack
 * 
 * @param STACK
 */
void eMenor(STACK *s);

/**
 * @brief Devolve o valor lógico oposto da operação afetada
 * 
 * @param STACK
 */
void nots(STACK *s);

// Funções no Guião 4

/**
 * @brief Transforma o ficheiro numa string 
 * 
 * @param STACK
 */
void readFile(STACK *s);

/**
 * @brief Aplica o Bloco a cada Container e filtra todos aqueles que são falsos (ou seja, são iguais a 0)
 * 
 * @param STACK
 * @param Container
 */
void compare(STACK *s, Container x, Container y, Container *vars);

/**
 * @brief Calcula o tamanho ou range do array
 * 
 * @param STACK
 * @param Container
 */
void tamanho(STACK *s, Container *vars);

/**
 * @brief Concatena Arrays 
 * 
 * @param STACK
 * @param Container
 */
void arrcat(STACK *s, Container z);

/**
 * @brief Separa as strings por substrings
 * 
 * @param STACK
 */
void strtoke(STACK *s);

/**
 * @brief Separa as strings por newlines
 * 
 * @param STACK
 */
void strtoke2(STACK *s);

