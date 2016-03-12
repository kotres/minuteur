CFLAGS= -g  -Wall -Wextra -Wno-unused-parameter
CC=gcc
DEFINES=__DEBUG __GNU_BUILD
EXEC=minuteur

all: $(EXEC)

minuteur: GNUmain.o time_type.o functions_test.o byte_union.o input.o
	  $(CC) -g -o minuteur GNUmain.o input.o time_type.o functions_test.o byte_union.o

GNUmain.o: GNUmain.c
	$(CC) $(addprefix -D, $(DEFINES)) -c  GNUmain.c $(CFLAGS)
functions_test.o: functions_test.c
	$(CC) $(addprefix -D, $(DEFINES)) -c functions_test.c $(CFLAGS)
time_type.o: time_type.c
	$(CC) $(addprefix -D, $(DEFINES)) -c  time_type.c $(CFLAGS)
input.o: input.c
	$(CC) $(addprefix -D, $(DEFINES)) -c  input.c $(CFLAGS)
byte_union.o: byte_union.c
	$(CC) $(addprefix -D, $(DEFINES)) -c  byte_union.c $(CFLAGS)

clean:
	rm -rf *.o
	rm -rf $(EXEC)
