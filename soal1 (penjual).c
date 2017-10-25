#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/wait.h>

int main(){
	key_t key = 2510;
	char senjata[6][8] = {"MP4A1", "PM2-V1","SS2-V5","SPR-3","SPG1-V3","MINE"};
	int shmid = shmget(key, sizeof(int)*6, IPC_CREAT);
	int *stok;
	stok = shmat(shmid, NULL, 0);
	while(1){
		int pilihan, a;
		char senjatanya[8];
		system("clear");
		printf("1.Tampilkan stock senjata\n2.Tambah stock sejata\n");
		scanf("%d", &pilihan);
		if(pil == 1){
			for(a=0;a<6;a++){
				if(stok[a]>0){
					printf("Jumlah %s di stock = %d barang\n", senjata[a], stok[a]);
				}
				printf("Press any key to continue...\n");
				getchar();
				getchar();
			}
		}
	}
}