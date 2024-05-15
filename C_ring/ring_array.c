#include <stdio.h>
#define DATATYPE int
#define RINGSIZE 1024
#define str(s) #s
#define xstr(s) str(s)

DATATYPE ring[RINGSIZE];
int start = 0;
int end = 0;
int overflow = 0;
int put_on_ring(DATATYPE data){
	ring[start] = data;
	if (++start == RINGSIZE){
		start = 0;
	}
	if(start == end){
		--start;
	       return 1; //Stack is full
	}
	return 0;
}
DATATYPE get_of_ring(){
	if (end == start){
		overflow = 1;
		return (DATATYPE)-1L;//Stack is empty
	}
	DATATYPE returnvalue = ring[end];
	if(++end == RINGSIZE){
		end = 0;
	}
	return returnvalue;
}

int main(int argv, char** argc)
{	
	(void)put_on_ring(20);
	(void)put_on_ring(40);
	(void)put_on_ring(90);
	for(int i = 0; i < 5; i++){
		printf("Got %i of ring\n",get_of_ring());
		if (overflow != 0){
			printf("Overlow detected\n");
		}
	}
	return 0;
}
