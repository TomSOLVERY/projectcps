CC=gcc
EXEC = projet
OUTPUT_DIR = ../bin
CFLAGS = -Wall -I ../the_headers
SRCS = $(wildcard *.c)
OBJS = $(SRCS: .c=.o)

all : 	$(OUTPUT_DIR)/$(EXEC)

$(OUTPUT_DIR)/$(EXEC) : 	$(OBJS)
			$(CC) $(CFLAGS) -o $@ $(OBJS) -lm
	
%.o: %.c
	$(CC) -o $@ -c $^ $(CFLAGS)

clean : 
		@echo "On efface les fichiers objets"
		rm -f *.o

mrproper :	clean
			rm -f $(EXEC)