#ifndef __IOMANAGER_H__
#define __IOMANAGER_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ioManager
{
    int n; // Dimensao do SisLin - com n > 10 [Obrigatorio]
    int k; // Numero de Diagonais da Matriz - com k > 1 e impar [Obrigatorio]
    int p; // Indica o Pre-Condicionador que sera utilizado [Obrigatorio]
    int i; // Numero maximo de iteracoes a ser utilizado [Obrigatorio]
    double e; // Erro aproximado absoluto maximo [Opcional]
}ioManager;

ioManager* allocIO();
void fillIO(ioManager* io, int argc, char const *argv[]);
void printIO(ioManager* io);
void freeIO(ioManager* io);

#endif