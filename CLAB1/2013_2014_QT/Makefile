all: calcula calcula_con_memoria mstat_v1 mstat_v2 mstat

calcula: calcula.c
	gcc -o calcula calcula.c

calcula_con_memoria: calcula_con_memoria.c
	gcc -o calcula_con_memoria calcula_con_memoria.c

mstat_v1: mstat_v1.c
	gcc -o mstat_v1 mstat_v1.c

mstat_v2: mstat_v2.c
	gcc -o mstat_v2 mstat_v2.c

mstat: mstat.c
	gcc -o mstat mstat.c

clean:
	rm -f *.o calcula calcula_con_memoria mstat_v1 mstat_v2 mstat
