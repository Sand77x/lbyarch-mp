N_SAMPLES ?= 1000
AS = nasm
CC = gcc

ASFLAGS = -fwin64
CFLAGS = -Wall

C_SRC = main.c
AS_SRC = func.asm

C_OBJ = $(C_SRC:.c=.o)
AS_OBJ = $(AS_SRC:.asm=.o)

OUT = main.exe

all: $(OUT)

$(OUT): $(C_OBJ) $(AS_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.asm
	$(AS) $(ASFLAGS) $< -o $@

clean: 
	rm -f *.o *.exe

run:
	./$(OUT)

# testing
samples:
	gcc make_samples.c -o make_samples.exe
	./make_samples.exe $(N_SAMPLES)

run_samples:
	./$(OUT) < sample_input.txt
