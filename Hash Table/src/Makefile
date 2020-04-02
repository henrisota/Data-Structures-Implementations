CC = g++
CFLAGS = -Wall -O2 -o
TARGETS = Hash

all: $(TARGETS)

Hash: main.cpp Hash.cpp Hash.h
	$(CC) $(CFLAGS) Hash main.cpp Hash.cpp

run:
	./$(TARGETS)

clean:
	rm $(TARGETS)
