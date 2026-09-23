#include <stdio.h>
#include <math.h>

/* ---------- Prototipos das funcoes ---------- */
double calcularIMC(double peso, double altura);
void classificarIMC(double imc);
void calcularAreaFiguras(void);
double somar(double a, double b);
double subtrair(double a, double b);
double multiplicar(double a, double b);
int dividir(double a, double b, double *resultado);
double mediaAritmetica(double a, double b, double c);
double calcularPorcentagem(double valor, double percentual);
int regraDeTresSimples(double a, double b, double c, double *x);
double celsiusParaFahrenheit(double celsius);
double kmParaMilhas(double km);
void calcularPerimetro(void);
double volumeCubo(double lado);
double jurosSimples(double capital, double taxa, double tempo);
double calcularDesconto(double valor, double percentual);
int velocidadeMedia(double distancia, double tempo, double *velocidade);
int consumoCombustivel(double distancia, double combustivel, double *consumo);
int ehPar(int numero);
int calcularIdade(int anoNascimento, int anoAtual);
int calcularPotencia(double base, double expoente, double *resultado);

/* ---------- Funcao principal ---------- */
int main(void) {
    int opcao;

    do {
        printf("\n========================================\n");
        printf("   CALCULADORA - 20 FUNCOES (Linguagem C)\n");
        printf("========================================\n");
        printf(" 1  - IMC\n");
        printf(" 2  - Area de figuras geometricas\n");
        printf(" 3  - Soma\n");
        printf(" 4  - Subtracao\n");
        printf(" 5  - Multiplicacao\n");
        printf(" 6  - Divisao\n");
        printf(" 7  - Media aritmetica\n");
        printf(" 8  - Porcentagem\n");
        printf(" 9  - Regra de tres simples\n");
        printf("10  - Conversao Celsius -> Fahrenheit\n");
        printf("11  - Conversao Km -> Milhas\n");
        printf("12  - Perimetro\n");
        printf("13  - Volume do cubo\n");
        printf("14  - Juros simples\n");
        printf("15  - Desconto\n");
        printf("16  - Velocidade media\n");
        printf("17  - Consumo (km/l)\n");
        printf("18  - Par ou impar\n");
        printf("19  - Calculo de idade\n");
        printf("20  - Potencia\n");
        printf(" 0  - Sair\n");
        printf("========================================\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Digite apenas numeros.\n");
            /* limpa o buffer de entrada para nao travar em loop infinito */
            while (getchar() != '\n');
            continue;
        }

        switch (opcao) {

            case 1: { /* IMC - obrigatoria */
                double peso, altura, imc;
                printf("Digite o peso (kg): ");
                scanf("%lf", &peso);
                printf("Digite a altura (m): ");
                scanf("%lf", &altura);

                if (altura <= 0) {
                    printf("Erro: altura deve ser maior que zero!\n");
                    break;
                }
                imc = calcularIMC(peso, altura);
                printf("IMC calculado: %.2f\n", imc);
                classificarIMC(imc);
                break;
            }

            case 2: /* Area de figuras geometricas - obrigatoria */
                calcularAreaFiguras();
                break;

            case 3: { /* Soma */
                double a, b;
                printf("Digite o primeiro valor: ");
                scanf("%lf", &a);
                printf("Digite o segundo valor: ");
                scanf("%lf", &b);
                printf("Resultado da soma: %.2f\n", somar(a, b));
                break;
            }

            case 4: { /* Subtracao */
                double a, b;
                printf("Digite o primeiro valor: ");
                scanf("%lf", &a);
                printf("Digite o segundo valor: ");
                scanf("%lf", &b);
                printf("Resultado da subtracao: %.2f\n", subtrair(a, b));
                break;
            }

            case 5: { /* Multiplicacao */
                double a, b;
                printf("Digite o primeiro valor: ");
                scanf("%lf", &a);
                printf("Digite o segundo valor: ");
                scanf("%lf", &b);
                printf("Resultado da multiplicacao: %.2f\n", multiplicar(a, b));
                break;
            }

            case 6: { /* Divisao */
                double a, b, resultado;
                printf("Digite o numerador: ");
                scanf("%lf", &a);
                printf("Digite o denominador: ");
                scanf("%lf", &b);
                if (dividir(a, b, &resultado)) {
                    printf("Resultado da divisao: %.2f\n", resultado);
                } else {
                    printf("Erro: divisao por zero!\n");
                }
                break;
            }

            case 7: { /* Media aritmetica */
                double a, b, c;
                printf("Digite o 1o valor: ");
                scanf("%lf", &a);
                printf("Digite o 2o valor: ");
                scanf("%lf", &b);
                printf("Digite o 3o valor: ");
                scanf("%lf", &c);
                printf("Media aritmetica: %.2f\n", mediaAritmetica(a, b, c));
                break;
            }

            case 8: { /* Porcentagem */
                double valor, percentual;
                printf("Digite o valor: ");
                scanf("%lf", &valor);
                printf("Digite o percentual: ");
                scanf("%lf", &percentual);
                printf("Resultado: %.2f\n", calcularPorcentagem(valor, percentual));
                break;
            }

            case 9: { /* Regra de tres simples */
                double a, b, c, x;
                printf("Digite o valor de A: ");
                scanf("%lf", &a);
                printf("Digite o valor de B: ");
                scanf("%lf", &b);
                printf("Digite o valor de C: ");
                scanf("%lf", &c);
                if (regraDeTresSimples(a, b, c, &x)) {
                    printf("Valor de X: %.2f\n", x);
                } else {
                    printf("Erro: o valor de A nao pode ser zero!\n");
                }
                break;
            }

            case 10: { /* Conversao Celsius -> Fahrenheit */
                double celsius;
                printf("Digite a temperatura em Celsius: ");
                scanf("%lf", &celsius);
                printf("Temperatura em Fahrenheit: %.2f\n", celsiusParaFahrenheit(celsius));
                break;
            }

            case 11: { /* Conversao Km -> Milhas */
                double km;
                printf("Digite a distancia em Km: ");
                scanf("%lf", &km);
                printf("Distancia em milhas: %.2f\n", kmParaMilhas(km));
                break;
            }

            case 12: /* Perimetro */
                calcularPerimetro();
                break;

            case 13: { /* Volume do cubo */
                double lado;
                printf("Digite o lado do cubo: ");
                scanf("%lf", &lado);
                printf("Volume do cubo: %.2f\n", volumeCubo(lado));
                break;
            }

            case 14: { /* Juros simples */
                double capital, taxa, tempo;
                printf("Digite o capital: ");
                scanf("%lf", &capital);
                printf("Digite a taxa (%%): ");
                scanf("%lf", &taxa);
                printf("Digite o tempo: ");
                scanf("%lf", &tempo);
                printf("Juros: %.2f\n", jurosSimples(capital, taxa, tempo));
                break;
            }

            case 15: { /* Desconto */
                double valor, percentual, desconto;
                printf("Digite o valor original: ");
                scanf("%lf", &valor);
                printf("Digite o percentual de desconto: ");
                scanf("%lf", &percentual);
                desconto = calcularDesconto(valor, percentual);
                printf("Valor do desconto: %.2f\n", desconto);
                printf("Valor final: %.2f\n", valor - desconto);
                break;
            }

            case 16: { /* Velocidade media */
                double distancia, tempo, velocidade;
                printf("Digite a distancia (km): ");
                scanf("%lf", &distancia);
                printf("Digite o tempo (h): ");
                scanf("%lf", &tempo);
                if (velocidadeMedia(distancia, tempo, &velocidade)) {
                    printf("Velocidade media: %.2f km/h\n", velocidade);
                } else {
                    printf("Erro: o tempo nao pode ser zero!\n");
                }
                break;
            }

            case 17: { /* Consumo km/l */
                double distancia, combustivel, consumo;
                printf("Digite a distancia percorrida (km): ");
                scanf("%lf", &distancia);
                printf("Digite o combustivel consumido (l): ");
                scanf("%lf", &combustivel);
                if (consumoCombustivel(distancia, combustivel, &consumo)) {
                    printf("Consumo: %.2f km/l\n", consumo);
                } else {
                    printf("Erro: o combustivel nao pode ser zero!\n");
                }
                break;
            }

            case 18: { /* Par ou impar */
                int numero;
                printf("Digite um numero inteiro: ");
                scanf("%d", &numero);
                if (ehPar(numero)) {
                    printf("O numero %d e PAR\n", numero);
                } else {
                    printf("O numero %d e IMPAR\n", numero);
                }
                break;
            }

            case 19: { /* Calculo de idade */
                int anoNascimento, anoAtual;
                printf("Digite o ano de nascimento: ");
                scanf("%d", &anoNascimento);
                printf("Digite o ano atual: ");
                scanf("%d", &anoAtual);
                printf("Idade aproximada: %d anos\n", calcularIdade(anoNascimento, anoAtual));
                break;
            }

            case 20: { /* Potencia */
                double base, expoente, resultado;
                printf("Digite a base: ");
                scanf("%lf", &base);
                printf("Digite o expoente: ");
                scanf("%lf", &expoente);
                if (calcularPotencia(base, expoente, &resultado)) {
                    printf("Resultado: %.2f\n", resultado);
                } else {
                    printf("Erro: operacao fora do dominio (base negativa com expoente fracionario)!\n");
                }
                break;
            }

            case 0:
                printf("Encerrando o programa. Ate mais!\n");
                break;

            default:
                printf("Opcao invalida! Escolha um numero de 0 a 20.\n");
        }

    } while (opcao != 0);

    return 0;
}

/* ============================================================
 * Implementacao das funcoes
 * ============================================================ */

/* 1. IMC = peso / altura^2 */
double calcularIMC(double peso, double altura) {
    return peso / (altura * altura);
}

/* Classifica o IMC calculado (estrutura condicional) */
void classificarIMC(double imc) {
    if (imc < 18.5) {
        printf("Classificacao: Abaixo do peso\n");
    } else if (imc < 25.0) {
        printf("Classificacao: Peso normal\n");
    } else if (imc < 30.0) {
        printf("Classificacao: Sobrepeso\n");
    } else {
        printf("Classificacao: Obesidade\n");
    }
}

/* 2. Area de figuras geometricas - com submenu proprio */
void calcularAreaFiguras(void) {
    int opcaoFigura;

    printf("--- Area de Figuras ---\n");
    printf("1 - Quadrado\n");
    printf("2 - Retangulo\n");
    printf("3 - Circulo\n");
    printf("4 - Triangulo\n");
    printf("Escolha a figura: ");
    scanf("%d", &opcaoFigura);

    switch (opcaoFigura) {
        case 1: {
            double lado;
            printf("Digite o lado do quadrado: ");
            scanf("%lf", &lado);
            printf("Area do quadrado: %.2f\n", lado * lado);
            break;
        }
        case 2: {
            double base, altura;
            printf("Digite a base do retangulo: ");
            scanf("%lf", &base);
            printf("Digite a altura do retangulo: ");
            scanf("%lf", &altura);
            printf("Area do retangulo: %.2f\n", base * altura);
            break;
        }
        case 3: {
            double raio;
            printf("Digite o raio do circulo: ");
            scanf("%lf", &raio);
            printf("Area do circulo: %.2f\n", M_PI * raio * raio);
            break;
        }
        case 4: {
            double base, altura;
            printf("Digite a base do triangulo: ");
            scanf("%lf", &base);
            printf("Digite a altura do triangulo: ");
            scanf("%lf", &altura);
            printf("Area do triangulo: %.2f\n", (base * altura) / 2.0);
            break;
        }
        default:
            printf("Opcao de figura invalida!\n");
    }
}

/* 3. Soma */
double somar(double a, double b) {
    return a + b;
}

/* 4. Subtracao */
double subtrair(double a, double b) {
    return a - b;
}

/* 5. Multiplicacao */
double multiplicar(double a, double b) {
    return a * b;
}

/* 6. Divisao - com tratamento de erro (divisao por zero) */
int dividir(double a, double b, double *resultado) {
    if (b == 0) {
        return 0; /* erro */
    }
    *resultado = a / b;
    return 1; /* sucesso */
}

/* 7. Media aritmetica de 3 valores */
double mediaAritmetica(double a, double b, double c) {
    return (a + b + c) / 3.0;
}

/* 8. Porcentagem */
double calcularPorcentagem(double valor, double percentual) {
    return (valor * percentual) / 100.0;
}

/* 9. Regra de tres simples (a esta para b assim como c esta para x) */
int regraDeTresSimples(double a, double b, double c, double *x) {
    if (a == 0) {
        return 0; /* erro */
    }
    *x = (b * c) / a;
    return 1;
}

/* 10. Conversao Celsius -> Fahrenheit */
double celsiusParaFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

/* 11. Conversao Km -> Milhas */
double kmParaMilhas(double km) {
    return km * 0.621371;
}

/* 12. Perimetro - com submenu proprio */
void calcularPerimetro(void) {
    int opcaoFigura;

    printf("--- Perimetro ---\n");
    printf("1 - Retangulo\n");
    printf("2 - Circulo\n");
    printf("Escolha a figura: ");
    scanf("%d", &opcaoFigura);

    switch (opcaoFigura) {
        case 1: {
            double base, altura;
            printf("Digite a base: ");
            scanf("%lf", &base);
            printf("Digite a altura: ");
            scanf("%lf", &altura);
            printf("Perimetro do retangulo: %.2f\n", 2 * (base + altura));
            break;
        }
        case 2: {
            double raio;
            printf("Digite o raio: ");
            scanf("%lf", &raio);
            printf("Perimetro do circulo: %.2f\n", 2 * M_PI * raio);
            break;
        }
        default:
            printf("Opcao de figura invalida!\n");
    }
}

/* 13. Volume do cubo */
double volumeCubo(double lado) {
    return pow(lado, 3);
}

/* 14. Juros simples */
double jurosSimples(double capital, double taxa, double tempo) {
    return (capital * taxa * tempo) / 100.0;
}

/* 15. Desconto */
double calcularDesconto(double valor, double percentual) {
    return (valor * percentual) / 100.0;
}

/* 16. Velocidade media - com tratamento de erro (tempo zero) */
int velocidadeMedia(double distancia, double tempo, double *velocidade) {
    if (tempo == 0) {
        return 0;
    }
    *velocidade = distancia / tempo;
    return 1;
}

/* 17. Consumo (km/l) - com tratamento de erro (combustivel zero) */
int consumoCombustivel(double distancia, double combustivel, double *consumo) {
    if (combustivel == 0) {
        return 0;
    }
    *consumo = distancia / combustivel;
    return 1;
}

/* 18. Par ou impar (operador modulo) */
int ehPar(int numero) {
    return (numero % 2 == 0);
}

/* 19. Calculo de idade */
int calcularIdade(int anoNascimento, int anoAtual) {
    return anoAtual - anoNascimento;
}

/* 20. Potencia */
int calcularPotencia(double base, double expoente, double *resultado) {
    if (base < 0 && floor(expoente) != expoente) {
        return 0;
    }
    *resultado = pow(base, expoente);
    return 1;
}
