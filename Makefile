all : main.c
	gcc main.c

clean : 
	rm *.o *~ a.out

re : clean all
