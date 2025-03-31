/**
 * @file polynomial.h
 * @brief Biblioteca para manipulacao de polinomios
 * @author [Seu Nome]
 * @version 1.0
 * @date 2024
 * 
 * Esta biblioteca implementa operacoes basicas com polinomios, incluindo:
 * - Criacao e destruicao de polinomios
 * - Calculo do valor de um polinomio para um dado x
 * - Soma de polinomios
 * - Multiplicacao de polinomios
 * - Entrada e saida formatada
 */

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @struct Polinomio
 * @brief Estrutura para representar um polinomio
 * 
 * Um polinomio e representado por um array de coeficientes e seu grau.
 * O indice i no array representa o coeficiente do termo x^i.
 */
typedef struct {
    int *coeficientes;  /**< Array de coeficientes */
    int grau;           /**< Grau do polinomio */
} Polinomio;

/**
 * @brief Cria um novo polinomio
 * @param grau O grau do polinomio
 * @return Ponteiro para o polinomio criado ou NULL em caso de erro
 */
Polinomio* criarPolinomio(int grau);

/**
 * @brief Libera a memoria alocada para um polinomio
 * @param p Ponteiro para o polinomio a ser liberado
 */
void liberarPolinomio(Polinomio *p);

/**
 * @brief Mostra um polinomio na tela em formato legivel
 * @param p Ponteiro para o polinomio a ser mostrado
 */
void mostrarPolinomio(Polinomio *p);

/**
 * @brief Calcula o valor do polinomio para um dado valor de x
 * @param p Ponteiro para o polinomio
 * @param x Valor para o qual calcular P(x)
 * @return O valor calculado P(x)
 */
double calcularValor(Polinomio *p, double x);

/**
 * @brief Soma dois polinomios
 * @param p1 Ponteiro para o primeiro polinomio
 * @param p2 Ponteiro para o segundo polinomio
 * @return Ponteiro para um novo polinomio que e a soma de p1 e p2
 */
Polinomio* somarPolinomios(Polinomio *p1, Polinomio *p2);

/**
 * @brief Multiplica dois polinomios
 * @param p1 Ponteiro para o primeiro polinomio
 * @param p2 Ponteiro para o segundo polinomio
 * @return Ponteiro para um novo polinomio que e o produto de p1 e p2
 */
Polinomio* multiplicarPolinomios(Polinomio *p1, Polinomio *p2);

/**
 * @brief Le um polinomio da entrada padrao
 * @return Ponteiro para o polinomio lido
 */
Polinomio* lerPolinomio(void);

#endif /* POLYNOMIAL_H */ 