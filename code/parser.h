#include <stdlib.h> 
#include <ctype.h>
#include "stack.h"
#pragma once

char* alloccStr();
/**
 * \brief Aloca memória para as Strings
 */
char *readString(char *rest, char *str);
/**
 * \brief Lê a String 
 *
 * @param rest
 * @param str
 *
 */
char *parseString(STACK *s, char *token, char *rest);
/**
 * \brief Faz parse de Strings
 *
 * @param STACK
 * @param token
 * @param rest
 * 
 */
char *parse_block(STACK *s, char *rest);
/**
 * \brief Faz parse de Blocos
 *
 * @param STACK
 * @param rest
 *
 */
char* parseArray(STACK *s, char *rest,Container *vars);
/**
 * \brief Faz parse de Arrays
 *
 * @param STACK
 * @param rest
 * @param vars
 *
 */
void parser(STACK *s, char *line, Container *vars);
/**
 * \brief Função principal responsável pelo parsing
 *
 * @param STACK
 * @param line
 * @param vars 
 *
 */
int isFloat(char *token);
/**
 * \brief Determina se o token é Float
 *
 * @param token
 *
 */

// __HANDLE__


char *handle(STACK *s, char *token, char *rest, Container *vars);
/**
 * \brief Função responsável pela chamada das funções dos guiões
 *
 * @param STACK
 * @param token
 * @param rest
 * @param Container
 *
 */
char *handle2(STACK *s, char *token, char *rest, Container *vars);
/**
 * \brief Função responsável pela chamada das funções dos guiões
 *
 * @param STACK
 * @param token
 * @param rest
 * @param Container
 *
 */
char *handle3(STACK *s, char *token, char *rest, Container *vars);
/**
 * \brief Função responsável pela chamada das funções dos guiões
 *
 * @param STACK
 * @param token
 * @param rest
 * @param Container
 *
 */
char *handle4(STACK *s, char *token, char *rest, Container *vars);
/**
 * \brief Função responsável pela chamada das funções dos guiões
 *
 * @param STACK
 * @param token
 * @param rest
 * @param Container
 *
 */
char *handle5(STACK *s, char *token, char *rest, Container *vars);
/**
 * \brief Função responsável pela chamada das funções dos guiões
 *
 * @param STACK
 * @param token
 * @param rest
 * @param Container
 *
 */
char *handle6(STACK *s, char *token, char *rest, Container *vars);
/**
 * \brief Função responsável pela chamada das funções dos guiões
 *
 * @param STACK
 * @param token
 * @param rest
 * @param Container
 *
 */






