# Otimiza-o

CI1238 - OTIMIZAÇÃO
Primeiro Trabalho
Kokouvi Hola Kanyi-Kodjovi
GRR 20170300
O primeiro trabalho da disciplina OTIMIZAÇÃO (CI1238) , consiste em modelar o Problema
da rede elétrica de uma cidade.
Modelagem:
-
A função Objetivo:
consiste em minimizar o custo mensal de geração da energia em um período
de n meses .
A função objetivo desse problema será a minimização do custo da termoelétrica
multiplicado pela soma da energia hidrelétrica por (MWatt) durante o período mais o custo
da variação do reservatório vezes a soma da energia ambiental por (m³).
Cada MW da termoelétrica tem custo associado .
min : CA* (soma da energia ambiental/m³)
-
+ CT*(soma da energia termoeletrica/MWatt)
As restriçoes :
Volume do reservatório: Vr
Volume initial: Vini
Influencias: Yi
Volume minímo: Vmin
Volume maxímo: Vmax
O volume do reservatório é a soma do volume inicial e das afluências
Vr = Vini +Yi
Vmin <= Vr <= Vmax
A energía Hidroeléctrica(Eh) = (Vr - Vmin)*KMWatt
(Vr-Vmin) é o volume de água usado para turbinar a cada mês.
K é o coeficiente de geração
A energia termoelétrica (Et)tem capacidade máxima Tmax e é uma restrição da energia
termoelétrica.
Et <= Tmax
As Demandas mensais : di
Et + Eh >= di(Vini + Yi) - Vmin <= Vmax ;
Volume de água turbinado: (Vini+ Yi) - Vmin
IMPLEMENTAÇÃO
O trabalho foi implementado em linguagem C e tem três arquivos tais como trab1.c, trab1.h
, main.c e o makefile .
-O arquivo trab1.c tem 3 funções
-readInput(): funções para ler as entradas dos dados;
-inic_dados(int n) : inicializa as variáveis
-free_dados(dados* dt, energia* e) : libera a memoria;
-print_dados(dados* d, energia* e) : implementa os valores e a imprime.
-O arquivo trab1.h tem as declarações dos struct “dados “ e “energia” e também tem os
protótipos das funções
-O arquivo main.c tem a função principal que implementa todo o programa.
O arquivo makefile compila o programa e gera o executável trab1
Conclusão
O programa minimiza o custo de geração e tem um plano ótimo .O programa gera as energias
na termoelétrica e os volumes turbinados a cada mês .
Exemplo de entrada do Programa
3
900 1000 950
500 800 200
500 200 1000 1.1
1000 0.2
0.005
Exemplo de saida do Programa
min : 0.005x1 + 396.000 ;
x1 + 880 >= 900 ;
x1 + 880 >= 1000 ;
x1 + 220 >= 950 ;
1000.00 >= 1000 ;
1000.00 >= 1000 ;
400.00 >= 1000 ;x10 = 800.000 ;
x11 = 800.000 ;
x12 = 200.000 ;
x1 >= 1000 ;
int x1 ;
