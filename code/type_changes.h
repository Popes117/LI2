#include "stack.h"
#include "parser.h"
#pragma once

// ___CONVERSÕES___ 

Container toInt(Container container);
/**
 * \brief Converte para Int
 *
 * @param Container
 *
 * @returns O valor em Int
 */
Container toDouble(Container container);
/**
 * \brief Converte para Double
 *
 * @param Container
 *
 * @returns O valor em Double
 */
Container toChar(Container container);
/**
 * \brief Converte para Char
 *
 * @param Container
 *
 * @returns O valor em Char
 */

void fill(Container *vars);

int comparaCont(Container x, Container y);
/**
 * \brief Compara 2 Containers
 *
 * @param Container
 * @param Container 
 */
int isZero(Container container);
/**
 * \brief Verifica se o valor do Container é diferente de 0
 *
 * @param Container
 *
 * @returns Verdadeiro se o valor for diferente de 0
 */

int hash_function(char *token);