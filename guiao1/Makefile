CC = gcc
CFLAGS = -O2 -Wall

all: mycp mycat

mycp: ./cp/*.o
	$(CC) $(CFLAGS) -o $@ $^

mycat: ./cat/*.o
	$(CC) $(CFLAGS) -o $@ $^

readln: ./readln/*.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	@rm -f mycp mycat readln *.o
