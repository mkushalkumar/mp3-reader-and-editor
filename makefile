OBJ:= $(patsubst %.c,%.o,$(wildcard *.c))
mp.exe:$(OBJ)
	gcc -o $@ $^
clean:
	rm *.exe *.o
