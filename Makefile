CC = gcc
CFLAGS = -g -Wall
OBJFILES = main.o coordinador.o metricas.o
TARGET = lab1
OUTPUTFILES = rp_*.txt rc_*.txt

all: $(TARGET)
	
$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

main: main.c coordinador.h metricas.h

coordinador: coordinador.c coordinador.h

metricas: metricas.c metricas.h

clean:
	rm -f $(OBJFILES) $(TARGET) rp_files/$(OUTPUTFILES)