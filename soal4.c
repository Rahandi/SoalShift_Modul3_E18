#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_t tid[100];
int status = 0;

typedef struct arg_struct{
	int angka;
	int stat;
} args;

void* fakto(void *arguments)
{
	int i, j;
	struct arg_struct *args = (struct arg_struct *)arguments;
	while(args->stat != status){}
	int input_val = args->angka;
	//menghitung fakto
	int hasil = 1;
	for (j=input_val; j>1; j--){
		hasil = hasil * j;
	}
	printf("%d! = %d\n",input_val, hasil);
	status++;
	free(arguments);
}


int main(int argc, char *argv[])
{
	int i, j;
	int input_val[100];   // integer version of argv[1]
	 
	 //cek ada argv apa g
	if (argc < 2){
		printf("INPUT TIDAK VALID\n");
		exit(1);
	}

	 //convert string ke int
	for (i=1; i<argc; i++){
		input_val[i-1] = atoi(argv[i]);
	}

	//sorting
	argc--;
	int temp;
	for (i=1; i<argc; i++){
		for (j=1; j<argc; j++){
			if(input_val[j-1] >= input_val[j]){
	   			temp = input_val[j-1];                                    
					input_val[j-1] = input_val[j];                                 
					input_val[j] = temp;                                      
			}    
		}
	}

	for(i=0;i<argc;i++){
		struct arg_struct *args = malloc(sizeof(struct arg_struct));
		args->angka = input_val[i];
		args->stat = i;

		pthread_create(&tid[i], NULL, fakto, (void*)args);
	}

	for(i=0;i<argc;i++){
		pthread_join(tid[i], NULL);
	}

	return 0;
}
