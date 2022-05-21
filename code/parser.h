#include <stdlib.h> 
#include <ctype.h>
#include "stack.h"
#pragma once

/**
 * @file Biblioteca com as funções utilizadas na parser.c
 */

/**
 * \brief Aloca memória para as Strings
 */
char* alloccStr();

/**
 * \brief Lê a String 
 *
 * @param Char
 * @param Char
 *
 */
char *readString(char *rest, char *str);

/**
 * \brief Faz parse de Strings
 *
 * @param STACK
 * @param token
 * @param Char
 * 
 */
char *parseString(STACK *s, char *token, char *rest);

/**
 * \brief Faz parse de Blocos
 *
 * @param STACK
 * @param Char
 *
 */
char *parse_block(STACK *s, char *rest);

/**
 * \brief Faz parse de Arrays
 *
 * @param STACK
 * @param Char
 * @param Container 
 *
 */
char* parseArray(STACK *s, char *rest,Container *vars);

/**
 * \brief Função principal responsável pelo parsing
 *
 * @param STACK
 * @param Char
 * @param Container  
 *
 */
void parser(STACK *s, char *line, Container *vars);

/**
 * \brief Determina se o token é Float
 *
 * @param Char
 *
 */
int isFloat(char *token);


// __HANDLE__

/**
 * \brief Função responsável pela chamada das funções dos guiões
 *
 * @param STACK
 * @param Char
 * @param Char
 * @param Container
 *
 */
char *handle(STACK *s, char *token, char *rest, Container *vars);

/**
 * \brief Função responsável pela chamada das funções dos guiões
 *
 * @param STACK
 * @param Char
 * @param Char
 * @param Container
 *
 */
char *handle2(STACK *s, char *token, char *rest, Container *vars);

/**
 * \brief Função responsável pela chamada das funções dos guiões
 *
 * @param STACK
 * @param Char  
 * @param Char
 * @param Container
 *
 */
char *handle3(STACK *s, char *token, char *rest, Container *vars);

/**
 * \brief Função responsável pela chamada das funções dos guiões
 *
 * @param STACK
 * @param Char
 * @param Char
 * @param Container
 *
 */
char *handle4(STACK *s, char *token, char *rest, Container *vars);

/**
 * \brief Função responsável pela chamada das funções dos guiões
 *
 * @param STACK
 * @param Char
 * @param Char
 * @param Container
 *
 */
char *handle5(STACK *s, char *token, char *rest, Container *vars);

/**
 * \brief Função responsável pela chamada das funções dos guiões
 *
 * @param STACK
 * @param Char
 * @param Char
 * @param Container
 *
 */
char *handle6(STACK *s, char *token, char *rest, Container *vars);







