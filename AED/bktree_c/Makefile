CFLAGS=-Wall -Werror -g -ansi -pedantic -std=c99
CCFLAGS=-Wall -Werror -g
LDFLAGS=-g -Wall -lstdc++

OBJS=BKNode.o BKTree.o CBKTree.o LevenshteinDistance.o main.o
PROG=bktree

all: $(PROG)
default: all
%.o: %.cpp
	$(CC) $(CCFLAGS) -c $<
%.o: %.c
	$(CC) $(CFLAGS) -c $<
$(PROG): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@
clean:
	rm -f $(OBJS)
	rm -f $(PROG)
