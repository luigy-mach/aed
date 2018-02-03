CFLAGS=-Wall -Werror -g -ansi -pedantic -std=c89
CCFLAGS=-Wall -Werror -g
LDFLAGS=-g -Wall -lstdc++

OBJS=test.o testWrapper.o main.o
PROG=test

all: $(PROG)
default: all
%.o: %.cc
	$(CC) $(CCFLAGS) -c $<
%.o: %.c
	$(CC) $(CFLAGS) -c $<
$(PROG): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@
clean:
	rm -f $(OBJS)
	rm -f $(PROG)
