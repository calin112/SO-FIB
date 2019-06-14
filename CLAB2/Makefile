all: my_wcl my_wcl_v2 my_wcl_v3 cuantaslineas 1deN

my_wcl: my_wcl.c
	gcc -o my_wcl my_wcl.c

my_wcl_v2: my_wcl_v2.c
	gcc -o my_wcl_v2 my_wcl_v2.c

my_wcl_v3: my_wcl_v3.c
	gcc -o my_wcl_v3 my_wcl_v3.c

cuantaslineas: cuantaslineas.c
	gcc -o cuantaslineas cuantaslineas.c

1deN: 1deN.c
	gcc -o 1deN 1deN.c

clean:
	rm -f *.o my_wcl my_wcl_v2 my_wcl_v3 cuantaslineas 1deN
