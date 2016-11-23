CC=gcc
CFLAGS=-O0
TARGET=./markov_c
INFILE=../alice30.txt
OUTFILE=../output/markov_c_out.txt

$(TARGET) : markov.o eprintf.o
	$(CC) $(CFLAGS) -o $(TARGET) markov.o eprintf.o
markov.o : markov.c
	$(CC) $(CFLAGS) -c markov.c
eprintf.o : eprintf.c eprintf.h
	$(CC) $(CFLAGS) -c eprintf.c

clean:
	rm -f *.o $(TARGET) $(OUTFILE)
run: $(TARGET)
	$(TARGET) < $(INFILE) > $(OUTFILE)
