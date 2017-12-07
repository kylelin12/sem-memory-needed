test : semting.c
	gcc -o test semting.c

run : test
	./test -c 4
	./test -c 4
	./test -v
	./test -v
	./test -c 3
	./test -v
	./test -r
	./test -v

clean :
	rm *.o