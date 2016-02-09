CFLAGS= -g  -Wall -Wextra -Wno-unused-parameter
CC=gcc
DEFINES=__DEBUG
EXEC=minuteur

all: $(EXEC)

minuteur: GNUmain.o time_piece.o time_type.o
	  $(CC) -g -o minuteur GNUmain.o time_piece.o time_type.o

GNUmain.o: GNUmain.c
	$(CC) -D$(DEFINES) -c  GNUmain.c $(CFLAGS)
time_piece.o: time_piece.c
	$(CC) -D$(DEFINES) -c  time_piece.c $(CFLAGS)
time_type.o: time_type.c
	$(CC) -D$(DEFINES) -c  time_type.c $(CFLAGS)

clean:
	rm -rf *.o
	rm -rf $(EXEC)
