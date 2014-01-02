#Compiler
CC = g++
#Flags
CFLAGS = -Wall -g -w
#Source Files
SRCS = main.cpp Config.cpp Report.cpp Tool.cpp CommandLine.cpp
#Object Files
OBJS = $(SRCS:.c=.o)

#executable
MAIN = disktool

all: $(MAIN)
	@echo Project AUDISKTOOL has been compiled

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)


clean:
	rm -rf *.o *~ $(MAIN)
