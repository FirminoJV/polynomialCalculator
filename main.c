#include "polynomial.h"

// Funcao auxiliar para calcular valores de um polinomio
void calcularValoresPolinomio(Polinomio *p) {
    if (p == NULL) return;

    char continuar;
    do {
        double x;
        printf("\nDigite o valor de x (ou 'q' para voltar ao menu): ");
        if (scanf("%lf", &x) != 1) {
            scanf("%c", &continuar); // Limpa o buffer
            if (continuar == 'q' || continuar == 'Q') break;
            printf("Erro: valor invalido para x\n");
            continue;
        }

        double valor = calcularValor(p, x);
        printf("P(%.2f) = %.2f\n", x, valor);

        printf("Deseja calcular outro valor? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');
}

int main() {
    int opcao;
    Polinomio *p1 = NULL, *p2 = NULL, *resultado = NULL;
    Polinomio *polinomio_armazenado = NULL;

    do {
        printf("\n=== Calculadora de Polinomios ===\n");
        printf("1. Calcular valor do polinomio\n");
        printf("2. Somar polinomios\n");
        printf("3. Multiplicar polinomios\n");
        printf("4. Armazenar polinomio\n");
        printf("5. Calcular valores para polinomio armazenado\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("Erro: opcao invalida\n");
            while (getchar() != '\n'); // Limpa o buffer
            continue;
        }

        switch (opcao) {
            case 1: {
                printf("\nDigite o polinomio:\n");
                p1 = lerPolinomio();
                if (p1 == NULL) break;

                printf("Polinomio digitado: ");
                mostrarPolinomio(p1);

                calcularValoresPolinomio(p1);
                liberarPolinomio(p1);
                break;
            }
            case 2: {
                printf("\nDigite o primeiro polinomio:\n");
                p1 = lerPolinomio();
                if (p1 == NULL) break;

                printf("Primeiro polinomio: ");
                mostrarPolinomio(p1);

                printf("\nDigite o segundo polinomio:\n");
                p2 = lerPolinomio();
                if (p2 == NULL) {
                    liberarPolinomio(p1);
                    break;
                }

                printf("Segundo polinomio: ");
                mostrarPolinomio(p2);

                resultado = somarPolinomios(p1, p2);
                if (resultado == NULL) {
                    printf("Erro: falha ao somar polinomios\n");
                } else {
                    printf("Resultado da soma: ");
                    mostrarPolinomio(resultado);
                    
                    printf("\nDeseja calcular valores para este resultado? (s/n): ");
                    char calcular;
                    scanf(" %c", &calcular);
                    if (calcular == 's' || calcular == 'S') {
                        calcularValoresPolinomio(resultado);
                    }
                }

                liberarPolinomio(p1);
                liberarPolinomio(p2);
                liberarPolinomio(resultado);
                break;
            }
            case 3: {
                printf("\nDigite o primeiro polinomio:\n");
                p1 = lerPolinomio();
                if (p1 == NULL) break;

                printf("Primeiro polinomio: ");
                mostrarPolinomio(p1);

                printf("\nDigite o segundo polinomio:\n");
                p2 = lerPolinomio();
                if (p2 == NULL) {
                    liberarPolinomio(p1);
                    break;
                }

                printf("Segundo polinomio: ");
                mostrarPolinomio(p2);

                resultado = multiplicarPolinomios(p1, p2);
                if (resultado == NULL) {
                    printf("Erro: falha ao multiplicar polinomios\n");
                } else {
                    printf("Resultado da multiplicacao: ");
                    mostrarPolinomio(resultado);
                    
                    printf("\nDeseja calcular valores para este resultado? (s/n): ");
                    char calcular;
                    scanf(" %c", &calcular);
                    if (calcular == 's' || calcular == 'S') {
                        calcularValoresPolinomio(resultado);
                    }
                }

                liberarPolinomio(p1);
                liberarPolinomio(p2);
                liberarPolinomio(resultado);
                break;
            }
            case 4: {
                // Libera o polinomio anteriormente armazenado
                if (polinomio_armazenado != NULL) {
                    liberarPolinomio(polinomio_armazenado);
                }

                printf("\nDigite o polinomio para armazenar:\n");
                polinomio_armazenado = lerPolinomio();
                if (polinomio_armazenado != NULL) {
                    printf("Polinomio armazenado: ");
                    mostrarPolinomio(polinomio_armazenado);
                    
                    printf("\nDeseja calcular valores para este polinomio? (s/n): ");
                    char calcular;
                    scanf(" %c", &calcular);
                    if (calcular == 's' || calcular == 'S') {
                        calcularValoresPolinomio(polinomio_armazenado);
                    }
                }
                break;
            }
            case 5: {
                if (polinomio_armazenado == NULL) {
                    printf("Erro: nenhum polinomio armazenado!\n");
                    break;
                }

                printf("\nPolinomio armazenado: ");
                mostrarPolinomio(polinomio_armazenado);
                calcularValoresPolinomio(polinomio_armazenado);
                break;
            }
            case 0:
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    // Libera o polinomio armazenado antes de encerrar
    if (polinomio_armazenado != NULL) {
        liberarPolinomio(polinomio_armazenado);
    }

    return 0;
} 