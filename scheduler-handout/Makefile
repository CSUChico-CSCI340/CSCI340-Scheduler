# Makefile for the CS:APP Shell Lab


VERSION = 1
sim = ./sim
simec= ./simec
CC = gcc
CXX = g++
CFLAGS = -Wall -O
FILES = $(sim) $(simec)

all: $(FILES)

sim: sim.o schedule.o
	$(CC) -o sim sim.o schedule.o

simec: simec.o schedule_ec.o
	$(CC) -o simec simec.o schedule_ec.o

clean:
	rm -f $(FILES) schedule.o schedule_ec.o 
