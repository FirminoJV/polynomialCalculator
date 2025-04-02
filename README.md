# Calculadora de Polinômios

Uma biblioteca em C para manipulação de polinômios, incluindo operações básicas como soma, multiplicação e cálculo de valor para um dado x.

## Funcionalidades

- Criar e manipular polinômios de qualquer grau
- Calcular o valor de um polinômio para um dado valor de x
- Somar dois polinômios
- Multiplicar dois polinômios
- Interface amigável via linha de comando

## Requisitos

- Compilador C (GCC recomendado)
- Make
- Biblioteca matemática (math.h)

## Compilação

Para compilar o projeto, execute:

```bash
make
```

Isso irá gerar o executável `calculator`.

## Uso

Execute o programa com:

```bash
./calculator
```

O programa apresentará um menu com as seguintes opções:
1. Calcular valor do polinômio
2. Somar polinômios
3. Multiplicar polinômios
0. Sair

### Exemplo de Uso

Para calcular P(x) = 4x^6 + 3x^5 - 6x^3 - 8x^2 + 3x + 4 para x = 2:

1. Escolha a opção 1
2. Digite o grau do polinômio: 6
3. Digite os coeficientes na ordem do maior para o menor grau:
   - x^6: 4
   - x^5: 3
   - x^4: 0
   - x^3: -6
   - x^2: -8
   - x^1: 3
   - x^0: 4
4. Digite o valor de x: 2

## Estrutura do Projeto

- `polynomial.h`: Arquivo de cabeçalho com as declarações
- `polynomial.c`: Implementação das funções da biblioteca
- `interface.c`: Interface do usuário e menu principal
- `Makefile`: Script para compilação do projeto

## Limpeza

Para limpar os arquivos objeto e o executável:

```bash
make clean
```

## Licença

Este projeto está sob a licença MIT. Veja o arquivo LICENSE para mais detalhes.

## Autor

João Vitor Firmino de Almeida