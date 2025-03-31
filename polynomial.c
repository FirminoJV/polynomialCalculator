#include "polynomial.h"

Polinomio* criarPolinomio(int grau) {
    Polinomio *p = (Polinomio*)malloc(sizeof(Polinomio));
    if (p == NULL) return NULL;
    
    p->grau = grau;
    p->coeficientes = (int*)calloc(grau + 1, sizeof(int));
    if (p->coeficientes == NULL) {
        free(p);
        return NULL;
    }
    return p;
}

void liberarPolinomio(Polinomio *p) {
    if (p != NULL) {
        free(p->coeficientes);
        free(p);
    }
}

void mostrarPolinomio(Polinomio *p) {
    if (p == NULL) return;

    printf("P(x) = ");
    int primeiro = 1;

    for (int i = p->grau; i >= 0; i--) {
        if (p->coeficientes[i] != 0) {
            if (!primeiro && p->coeficientes[i] > 0) {
                printf("+ ");
            }
            
            if (p->coeficientes[i] == -1 && i > 0) {
                printf("-");
            } else if (p->coeficientes[i] != 1 || i == 0) {
                printf("%d", p->coeficientes[i]);
            }

            if (i > 1) {
                printf("x^%d ", i);
            } else if (i == 1) {
                printf("x ");
            }
            
            primeiro = 0;
        }
    }
    
    if (primeiro) { // Se todos os coeficientes forem zero
        printf("0");
    }
    printf("\n");
}

double calcularValor(Polinomio *p, double x) {
    if (p == NULL) return 0.0;

    double resultado = 0;
    for (int i = p->grau; i >= 0; i--) {
        resultado += p->coeficientes[i] * pow(x, i);
    }
    return resultado;
}

Polinomio* somarPolinomios(Polinomio *p1, Polinomio *p2) {
    if (p1 == NULL || p2 == NULL) return NULL;

    int maxGrau = (p1->grau > p2->grau) ? p1->grau : p2->grau;
    Polinomio *resultado = criarPolinomio(maxGrau);
    if (resultado == NULL) return NULL;

    for (int i = 0; i <= maxGrau; i++) {
        int coef1 = (i <= p1->grau) ? p1->coeficientes[i] : 0;
        int coef2 = (i <= p2->grau) ? p2->coeficientes[i] : 0;
        resultado->coeficientes[i] = coef1 + coef2;
    }

    return resultado;
}

Polinomio* multiplicarPolinomios(Polinomio *p1, Polinomio *p2) {
    if (p1 == NULL || p2 == NULL) return NULL;

    int novoGrau = p1->grau + p2->grau;
    Polinomio *resultado = criarPolinomio(novoGrau);
    if (resultado == NULL) return NULL;

    for (int i = 0; i <= p1->grau; i++) {
        for (int j = 0; j <= p2->grau; j++) {
            resultado->coeficientes[i + j] += p1->coeficientes[i] * p2->coeficientes[j];
        }
    }

    return resultado;
}

Polinomio* lerPolinomio(void) {
    int grau;
    printf("Digite o grau do polinomio: ");
    if (scanf("%d", &grau) != 1 || grau < 0) {
        printf("Erro: grau invalido\n");
        return NULL;
    }

    Polinomio *p = criarPolinomio(grau);
    if (p == NULL) {
        printf("Erro: falha na alocacao de memoria\n");
        return NULL;
    }

    printf("Digite os coeficientes do maior grau para o menor:\n");
    for (int i = grau; i >= 0; i--) {
        printf("Coeficiente de x^%d: ", i);
        if (scanf("%d", &p->coeficientes[i]) != 1) {
            printf("Erro: coeficiente invalido\n");
            liberarPolinomio(p);
            return NULL;
        }
    }

    return p;
} 