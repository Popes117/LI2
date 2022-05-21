#include "stack.h"
#include "parser.h"
#pragma once

/**
 * @file Biblioteca com as funções usadas na type_changes.c
 */

// ___CONVERSÕES___ 

/**
 * \brief Converte para Int
 *
 * @param Container
 *
 * @returns O valor em Int
 */
Container toInt(Container container);

/**
 * \brief Converte para Double
 *
 * @param Container
 *
 * @returns O valor em Double
 */
Container toDouble(Container container);

/**
 * \brief Converte para Char
 *
 * @param Container
 *
 * @returns O valor em Char
 */
Container toChar(Container container);

/**
 * \brief Enche o Array das variáveis com as variáveis prédefinidas 
 *
 * @param Container
 *
 */
void fill(Container *vars);

/**
 * \brief Compara 2 Containers
 *
 * @param Container
 * @param Container 
 */
int comparaCont(Container x, Container y);

/**
 * \brief Verifica se o valor do Container é diferente de 0
 *
 * @param Container
 *
 * @returns Verdadeiro se o valor for diferente de 0
 */
int isZero(Container container);

/**
 * \brief Função Hash criada para otimizar o código da função handle 
 *
 * @param Char 
 */
int hash_function(char *token);
