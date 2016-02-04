CFLAGS= -g  -Wall -Wextra -Wno-unused-parameter
CC=gcc
DEFINES=__DEBUG
EXEC=minuteur

all: $(EXEC)

minuteur: debug_main.o time_piece.o time_type.o
	  $(CC) -g -o minuteur debug_main.o time_piece.o time_type.o

debug_main.o: debug_main.c
	$(CC) -D$(DEFINES) -c  debug_main.c $(CFLAGS)
time_piece.o: time_piece.c
	$(CC) -D$(DEFINES) -c  time_piece.c $(CFLAGS)
time_type.o: time_type.c
	$(CC) -D$(DEFINES) -c  time_type.c $(CFLAGS)

clean:
	rm -rf *.o
	rm -rf $(EXEC)
