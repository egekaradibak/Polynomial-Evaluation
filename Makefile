polyapp: polyapp.o poly.o utils.o
	gcc -o olyapp polyapp.o poly.o utils.o
polyapp.o: polyapp.c poly.h utils.h
	gcc -c polyapp.c
poly.o: poly.c utils.h
	gcc -c poly.c
utils.o: utils.c utils.h
	gcc -c utils.c
clean:
	rm *.o
