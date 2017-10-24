#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_t thread_lohan, thread_kepiting, thread_input;
int status_lohan=100, status_kepiting=100, signal=0;

void* fungsi_lohan(){
	while(1){
		sleep(10);
		status_lohan-=15;
		if(status_lohan > 100 || status_lohan <= 0){
			signal = 1;
			break;
		}
	}
}

void* fungsi_kepiting(){
	while(1){
		sleep(20);
		status_kepiting-=10;
		if(status_kepiting > 100 || status_kepiting <= 0){
			signal = 1;
			break;
		}
	}
}

void* ambil_input(){
	int pilihan;
	while(1){
		printf("1.Beri makan lohan\n2.Beri makan kepiting\n3.Tampilkan status\npilihan = ");
		scanf("%d", &pilihan);
		system("clear");
		if(pilihan == 1){
			status_lohan += 10;
			if(status_lohan > 100 || status_lohan <= 0){
				signal = 1;
				break;
			}
		}
		else if(pilihan == 2){
			status_kepiting += 10;
			if(status_kepiting > 100 || status_kepiting <= 0){
				signal = 1;
				break;
			}
		}
		else if(pilihan == 3){
			printf("Lohan: %d\nKepiting: %d", status_lohan, status_kepiting);
		}
	}
}

int main(){
	system("clear");
	pthread_create(&(thread_lohan), NULL, &fungsi_lohan, NULL);
	pthread_create(&(thread_kepiting), NULL, &fungsi_kepiting, NULL);
	pthread_create(&(thread_input), NULL, &ambil_input, NULL);

	while(1){
		if(signal==1){
			printf("GAME OVER");
			return 0;
		}
	}

	pthread_join(thread_lohan, NULL);
	pthread_join(thread_kepiting, NULL);
	pthread_join(thread_input, NULL);
}