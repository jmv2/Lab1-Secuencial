CC = gcc
CFLAGS = -g -Wall
OBJFILES = main.o coordinador.o metricas.o
TARGET = program

all: $(TARGET)
	
$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

main: main.c coordinador.h metricas.h

coordinador: coordinador.c coordinador.h

metricas: metricas.c metricas.h

clean:
	rm -f $(OBJFILES) $(TARGET)