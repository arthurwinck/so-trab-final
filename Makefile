IDIR=src
CC=g++
LDLIBS =  -lsfml-graphics -lsfml-window -lsfml-system -lm  -lpng
CFLAGS=-I$(IDIR) -g -Wextra

LDFLAGS= $(CFLAGS)

ODIR=src
LIBS= $(LDLIBS) $(LDFLAGS)

_DEPS = window.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o system.o main_class.o thread.o semaphore.o window.o cpu.o debug.o pacman.o ghost.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -std=c++14 -c -o $@ $< $(CFLAGS) -Wextra

main: $(OBJ)
	$(CC) -std=c++14 -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 