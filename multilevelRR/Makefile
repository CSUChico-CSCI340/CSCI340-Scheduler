# Makefile for the CS:APP Shell Lab


VERSION = 1
sim = ./sim ./sim2
#sim2 = ./sim2
#simec= ./simec
CC = gcc
CXX = g++
CFLAGS = -Wall -O 
#FILES = $(sim) $(simec)
FILES = $(sim)

all: $(FILES)

sim: sim.o schedule.o
	$(CC) -o sim sim.o schedule.o

sim2: sim2.o schedule.o
	$(CC) -o sim2 sim2.o schedule.o

#simec: simec.o schedule_ec.o
#	$(CC) -o simec simec.o schedule_ec.o

clean:
	rm -f $(FILES) *.o
