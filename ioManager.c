#include "ioManager.h"

ioManager* allocIO()
{
    ioManager* io;
    io = malloc(sizeof(ioManager));
    return io;
}

void fillIO(ioManager* io, int argc, char const *argv[])
{
    if(io == NULL)
    {
        fprintf(stderr, "ioManager is not allocated, can't obtain arguments.\n");
        fprintf(stderr, "Aborting execution!\n");
        exit(1);
    }

    if(argc < 8)
    {
        fprintf(stderr, "Not enough arguments, please input all needed arguments:\n\n");
        fprintf(stderr, "[REQUIRED] N - integer - defines size of linear system.\n");
        fprintf(stderr, "[REQUIRED] K - integer - defines quantity of diagonals in matrix A.\n");
        fprintf(stderr, "[REQUIRED] P - integer - defines what pre-condicioner to be used.\n");
        fprintf(stderr, "[REQUIRED] I - integer - defines what maximum number of iterations to run.\n");
        fprintf(stderr, "[OPTIONAL] E - double - defines aproximmate absolute maximum error.\n\n");
        fprintf(stderr, "The following command is a representation of how to run this program:\n");
        fprintf(stderr, "./cgSolver -n <n> -k <k> -p <p> -i <i> -e <e>\n");

        if(io != NULL)
        {
            free(io);
        }
        exit(1);
    }

    for(int i = 1; i < argc; i++)
    {
        printf("%s\n", argv[i]);
        if(argv[i][0] == '-')
        {
            if(argv[i][1] == 'n')
            {
                i++;
                io->n = atoi(argv[i]);
            }
            else if(argv[i][1] == 'k')
            {
                i++;
                io->k = atoi(argv[i]);
            }
            else if(argv[i][1] == 'p')
            {
                i++;
                io->p = atoi(argv[i]);
            }
            else if(argv[i][1] == 'i')
            {
                i++;
                io->i = atoi(argv[i]);
            }
            else if(argv[i][1] == 'e')
            {
                i++;
                io->e = atof(argv[i]);
            }
        }
    }
}

void printIO(ioManager* io)
{
    printf("n = %d\n", io->n);
    printf("k = %d\n", io->k);
    printf("p = %d\n", io->p);
    printf("i = %d\n", io->i);
    printf("e = %lf\n", io->e);
}

void freeIO(ioManager* io)
{
    free(io);
}