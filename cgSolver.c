#include "ioManager.h"

int main(int argc, char const *argv[])
{
    ioManager *io = allocIO();
    fillIO(io, argc, argv);
    printIO(io);
    freeIO(io);

    return 0;
}
