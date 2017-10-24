#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_t thread_lohan, tread_kepiting;
int status_lohan=100, status_kepiting=100, signal=0;

void* fungsi_lohan(){
	while(1){
		status_lohan-=15;
		if(status_lohan > 100 || status_lohan <= 0){
			signal=1;
		}
		sleep(10)
	}
}

void* fungsi_kepiting(){
	while(1){
		status_kepiting-=10;
		if(status_kepiting > 100 || status_kepiting <= 0){
			signal = 1;
		}
		sleep(20)
	}
}

void* ambil_input(){
	int pilihan;
	while(1){
		printf("1.Beri makan lohan\n2.Beri makan kepiting\npilihan = ");
		scanf("%d", &pilihan);
		system("clear")
		if(pilihan == 1){
			status_lohan += 10;
			if(status_lohan > 100 || status_lohan <= 0){
				signal = 1;
			}
		}
		else if(pilihan == 2){
			status_kepiting += 10;
			if(status_kepiting > 100 || status_kepiting <= 0){
				signal = 1;
			}
		}
	}
}

int main(){

}