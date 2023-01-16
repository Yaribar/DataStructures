CC = gcc
CFLAGS = -g -Wall
BINS = treeexample

all: $(BINS)

%: %.c 
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(BINS)