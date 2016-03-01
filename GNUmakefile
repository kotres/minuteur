CFLAGS= -g  -Wall -Wextra -Wno-unused-parameter
CC=gcc
DEFINES=__DEBUG
EXEC=minuteur

all: $(EXEC)

minuteur: GNUmain.o flag_array.o time_type.o functions_test.o byte_union.o
	  $(CC) -g -o minuteur GNUmain.o flag_array.o time_type.o functions_test.o byte_union.o

GNUmain.o: GNUmain.c
	$(CC) -D$(DEFINES) -c  GNUmain.c $(CFLAGS)
functions_test.o: functions_test.c
	$(CC) -D$(DEFINES) -c functions_test.c $(CFLAGS)
time_type.o: time_type.c
	$(CC) -D$(DEFINES) -c  time_type.c $(CFLAGS)
flag_array.o: flag_array.c
	$(CC) -D$(DEFINES) -c  flag_array.c $(CFLAGS)
byte_union.o: byte_union.c
	$(CC) -D$(DEFINES) -c  byte_union.c $(CFLAGS)

clean:
	rm -rf *.o
	rm -rf $(EXEC)
