#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21

#define ADD 30
#define SUB 31
#define DIV 32
#define MUL 33

#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

int add(int, int);
int res(int, int);

int main(){
    /*
    char *programa[20] = {
	"1009",
	"1010",
	"2009",
	"3110",
	"4107",
	"1109",
	"4300",
	"1110",
	"4300",
	"0000",
	"0000"
    };
    */


    int memoria[20];
    
    char d[3];
    char p[3];

    int dir = 0;
    int pos = 0;

    int input = 0;
    int temp = 0;

    // Numero de instrucciones.
    int INST = 11;

    // Recorriendo memoria.
    for(int i = 0; i < INST; i++){
	d[0] = programa[i][0];
	d[1] = programa[i][1];
	d[2] = '\0';

	p[0] = programa[i][2];
	p[1] = programa[i][3];
	p[2] = '\0';
	
	dir = atoi(d);
	pos = atoi(p);

//	printf("dir: %d pos: %d\n", dir, pos);

	// switch. Evaluacion de los valores.
	switch(dir){
	case READ:
	    scanf("%d", &input);
	    memoria[pos] = input;
	    break;
	case WRITE:
	    printf("%d\n", memoria[pos]);
	    break;
	case LOAD:
	    temp = memoria[pos];
	    // printf("Valor temp: %d\n", temp);
	    break;
	case STORE:
	    memoria[pos] = temp;
	    break;
	case ADD:
	    temp = temp + memoria[pos];
	    break;
	case SUB:
	    temp = temp - memoria[pos];
	    break;
	case MUL:
	    temp = temp * memoria[pos];
	    break;
	case DIV:
	    temp = temp / memoria[pos];
	    break;
	case BRANCH:
	    i = pos - 1;
	    break;
	case BRANCHNEG:
	    if(temp < 0){
		i = pos - 1;
	    }
	    break;
	case BRANCHZERO:
	    if(temp == 0){
		i = pos - 1;
	    }
	case HALT:
	    i = INST - 1;
	    break;
	}
	
    }

    
    /*  int (*flist[2])(int, int);

    flist[0] = add;
    flist[1] = res;

    // Forma de hacer un menu con listas de funciones.
    // Para modificar el argumento de la funcion se desreferencia.
    printf("%d\n", flist[0](2, 4));
    printf("%d\n", flist[1](2, 4));
*/
    // Comando - operando.
    // 1000 10 = READ operando 00 direccion 00.

    return 0;
}

/*
int add(int x, int y){
    return x + y;
}

int res(int x, int y){
    return x - y;
    }*/
