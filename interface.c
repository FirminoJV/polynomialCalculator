#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "polynomial.h"

#define SCREEN_WIDTH 40
#define MAX_EXPRESSION 100

// Buffer para armazenar a string do polinômio
char polynomial_str[MAX_EXPRESSION];

void print_separator() {
    for(int i = 0; i < SCREEN_WIDTH + 4; i++) printf("-");
    printf("\n");
}

void print_border_line() {
    printf("|");
    for(int i = 0; i < SCREEN_WIDTH - 2; i++) printf("_");
    printf("|\n");
}

void print_centered_text(const char* text) {
    int len = strlen(text);
    int padding = (SCREEN_WIDTH - 2 - len) / 2;
    
    printf("|");
    for(int i = 0; i < padding; i++) printf(" ");
    printf("%s", text);
    for(int i = 0; i < SCREEN_WIDTH - 2 - padding - len; i++) printf(" ");
    printf("|\n");
}

// Função para converter um Polinomio em string
void polynomial_to_string(Polinomio *p) {
    if (p == NULL) {
        strcpy(polynomial_str, "");
        return;
    }
    
    int first = 1;
    polynomial_str[0] = '\0';
    char term[20];
    
    for (int i = p->grau; i >= 0; i--) {
        if (p->coeficientes[i] != 0) {
            // Adiciona o sinal
            if (!first && p->coeficientes[i] > 0) {
                strcat(polynomial_str, "+");
            }
            
            // Adiciona o coeficiente
            if (i == 0 || p->coeficientes[i] != 1) {
                if (p->coeficientes[i] == -1 && i != 0) {
                    strcat(polynomial_str, "-");
                } else {
                    sprintf(term, "%d", p->coeficientes[i]);
                    strcat(polynomial_str, term);
                }
            }
            
            // Adiciona a parte com x
            if (i > 0) {
                if (i == 1) {
                    strcat(polynomial_str, "x");
                } else {
                    sprintf(term, "x^%d", i);
                    strcat(polynomial_str, term);
                }
            }
            
            first = 0;
        }
    }
    
    if (polynomial_str[0] == '\0') {
        strcpy(polynomial_str, "0");
    }
}

void display_calculator(const char* result) {
    print_separator();
    
    // Título
    print_border_line();
    print_centered_text("Calculadora de Polinomios");
    print_border_line();
    
    // Visor - Polinômio atual
    printf("|  %s", polynomial_str);
    for(int i = 0; i < SCREEN_WIDTH - 4 - strlen(polynomial_str); i++) printf(" ");
    printf("|\n");
    
    // Visor - Resultado
    if (result != NULL && strlen(result) > 0) {
        printf("|  = %s", result);
        for(int i = 0; i < SCREEN_WIDTH - 6 - strlen(result); i++) printf(" ");
        printf("|\n");
    }
    print_border_line();
    
    // Botões
    print_centered_text("[x^2] [x] [+] [-] [*] [^] [DEL]");
    print_centered_text("[1]  [2]  [3] [4] [5] [6] [0]");
    print_centered_text("[Derivar] [Integrar] [=]");
    print_border_line();
}

int main() {
    char result[MAX_EXPRESSION] = "";
    Polinomio *p1 = NULL, *p2 = NULL, *resultado = NULL;
    int historico_operacoes = 0;
    
    // Inicializa a string do polinômio
    strcpy(polynomial_str, "");
    
    while(1) {
        display_calculator(result);
        
        printf("\nComandos disponiveis:\n");
        printf("1. Digitar polinomio\n");
        printf("2. Calcular valor\n");
        printf("3. Somar com outro polinomio\n");
        printf("4. Multiplicar com outro polinomio\n");
        printf("5. Limpar\n");
        printf("0. Sair\n");
        printf("\nDigite um comando: ");
        
        int opcao;
        scanf("%d", &opcao);
        
        // Incrementa o contador de operações para manter o histórico
        historico_operacoes++;
        printf("\n--- Operacao #%d ---\n", historico_operacoes);
        
        switch(opcao) {
            case 1: {
                printf("Digite o polinomio (grau e coeficientes):\n");
                if (p1 != NULL) liberarPolinomio(p1);
                p1 = lerPolinomio();
                if (p1 != NULL) {
                    polynomial_to_string(p1);
                    printf("Polinomio digitado: %s\n", polynomial_str);
                    strcpy(result, "");
                }
                break;
            }
            case 2: {
                if (p1 == NULL) {
                    strcpy(result, "Erro: nenhum polinomio digitado!");
                    printf("%s\n", result);
                    break;
                }
                
                double x;
                printf("Digite o valor de x: ");
                scanf("%lf", &x);
                
                double valor = calcularValor(p1, x);
                sprintf(result, "P(%.2f) = %.2f", x, valor);
                printf("%s\n", result);
                break;
            }
            case 3: {
                if (p1 == NULL) {
                    strcpy(result, "Erro: primeiro polinomio nao digitado!");
                    printf("%s\n", result);
                    break;
                }
                
                printf("Digite o segundo polinomio:\n");
                p2 = lerPolinomio();
                if (p2 != NULL) {
                    printf("Segundo polinomio: ");
                    mostrarPolinomio(p2);
                    
                    resultado = somarPolinomios(p1, p2);
                    if (resultado != NULL) {
                        liberarPolinomio(p1);
                        p1 = resultado;
                        polynomial_to_string(p1);
                        strcpy(result, "Soma realizada com sucesso!");
                        printf("Resultado: %s\n", polynomial_str);
                    }
                    liberarPolinomio(p2);
                }
                break;
            }
            case 4: {
                if (p1 == NULL) {
                    strcpy(result, "Erro: primeiro polinomio nao digitado!");
                    printf("%s\n", result);
                    break;
                }
                
                printf("Digite o segundo polinomio:\n");
                p2 = lerPolinomio();
                if (p2 != NULL) {
                    printf("Segundo polinomio: ");
                    mostrarPolinomio(p2);
                    
                    resultado = multiplicarPolinomios(p1, p2);
                    if (resultado != NULL) {
                        liberarPolinomio(p1);
                        p1 = resultado;
                        polynomial_to_string(p1);
                        strcpy(result, "Multiplicacao realizada com sucesso!");
                        printf("Resultado: %s\n", polynomial_str);
                    }
                    liberarPolinomio(p2);
                }
                break;
            }
            case 5: {
                if (p1 != NULL) {
                    liberarPolinomio(p1);
                    p1 = NULL;
                }
                strcpy(polynomial_str, "");
                strcpy(result, "");
                printf("Calculadora limpa!\n");
                break;
            }
            case 0:
                printf("Encerrando a calculadora...\n");
                if (p1 != NULL) liberarPolinomio(p1);
                return 0;
            default:
                printf("Opcao invalida!\n");
        }
        
        printf("\n");  // Linha extra para separar as operações
    }
    
    return 0;
} 