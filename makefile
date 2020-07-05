# change application name here (executable output name)
TARGET=SIMS
# compiler
CC=gcc
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=-Wall
PTHREAD=-pthread
CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe


# linker
LD=gcc


OBJS=   SIMS.o  
     
all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)

SIMS.o: SIMS.c
	$(CC) -c SIMS.c -o SIMS.o $(CFLAGS)
	
clean:
	rm -f *.o $(TARGET)
