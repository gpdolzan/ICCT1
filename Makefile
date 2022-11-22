    CC     = gcc -g
    CFLAGS = 
    LFLAGS = -lm

      PROG = cgSolver
      OBJS = ioManager.o \
             $(PROG).o

.PHONY: limpa faxina clean distclean purge all

%.o: %.c %.h ioManager.h
	$(CC) -c $(CFLAGS) $<

$(PROG):  $(OBJS)
	$(CC) -o $@ $^ $(LFLAGS)

clean:
	@rm -f *~ *.bak

purge:   clean
	@rm -f *.o core a.out
	@rm -f $(PROG)
