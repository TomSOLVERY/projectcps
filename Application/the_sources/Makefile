CC=gcc
EXEC = projet
CFLAGS = -Wall -I ../the_headers
SRCS = $(wildcard *.c)
OBJS = $(SRCS: .c=.o)

all : 	$(EXEC)

$(EXEC) : 	$(OBJS)
			$(CC) $(CFLAGS) -o $(EXEC) $(OBJS) -lm
	
%.o: %.c
	$(CC) -o $@ -c $^ $(CFLAGS)

clean : 
		@echo "On efface les fichiers objets"
		
		rm -f *.o

mrproper :	clean
			rm -f $(EXEC)