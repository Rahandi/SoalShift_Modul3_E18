#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_t pemain1, pemain2;
int status=0, giliran=1, ranjaupertama[16], ranjaukedua[16], scoresatu=0, scoredua=0;
char namesatu[100], namedua[100];

void* pemainpertama(){
	int a, b=0, c, d, e[4];
	for(a=0;a<16;a++){
		ranjaupertama[a] = 0;
	}
	while(1){
		while(giliran!=1){}
		system("clear");
		if(b==0){
			printf("Nama pemain pertama:\n");
			scanf("%[^\n]s", namesatu);
			b=1;
		}
		else if(b==1){
			printf("%s silahkan pasang ranjau\n", namesatu);
			printf("berapa ranjau yang akan dipasang? (maks 4 ranjau)\n");
			scanf("%d", &c);
			if(c>4){
				printf("terlalu banyak ranjau yang dipasang, ulangi lagi\n");
				getchar();
				continue;
			}
			system("clear")
			printf("lubang yang sudah berisi ranjau: ");
			for(a=0;a<16;a++){
				if(ranjaupertama[a] == 1){
					printf("%d ", a+1);
				}
			}
			printf("\nranjau mau dipasang di lubang ke berapa? (1-16)\n");
			for(a=0;a<c;a++){
				scanf("%d", &d);
				d = d - 1;
				if(d>=16){
					printf("lubang yang dimasukkan melebihi batas, ulangi lagi\n");
					getchar();
					continue;
				}
				if(ranjaupertama[d] != 1){
					ranjaupertama[d] = 1;
				}
				else{
					printf("ranjau tidak bisa diinputkan ke tempat yang sama, ulangi lagi\n");
					getchar();
					continue;
				}
			}
			b = 2;
			giliran = 2;
		}
		else if(b==2){
			printf("%s silahkan tebak ranjau di 4 lubang (1-16)\n");
			for(a=0;a<4;a++){
				scanf("%d", &e[a]);
				e[a] = e[a] - 1;
				if(e[a] >= 16){
					printf("lubang melebihi batas, ulangi lagi\n");
					getchar();
					continue;
				}
			}
			for(a=0;a<4;a++){
				if(ranjaukedua[e[a]] == 1){
					scoredua += 1;
				}
				else{
					scoresatu += 1;
				}
			}
			if(scoresatu >= 10){
				status=1;
				break;
			}
			if(scoredua >= 10){
				status=2;
				break;
			}
			b = 1;
			giliran = 2;
		}
	}
}

void* pemainkedua(){
	int a, b=0, c, d, e[4];
	for(a=0;a<16;a++){
		ranjaukedua[a] = 0;
	}
	while(1){
		while(giliran!=2){}
		system("clear");
		if(b==0){
			printf("Nama pemain kedua:\n");
			scanf("%[^\n]s", namedua);
			b=1;
		}
		else if(b==1){
			printf("%s silahkan pasang ranjau\n", namedua);
			printf("berapa ranjau yang akan dipasang? (maks 4 ranjau)\n");
			scanf("%d", &c);
			if(c>4){
				printf("terlalu banyak ranjau yang dipasang, ulangi lagi\n");
				getchar();
				continue;
			}
			system("clear")
			printf("lubang yang sudah berisi ranjau: ");
			for(a=0;a<16;a++){
				if(ranjaukedua[a] == 1){
					printf("%d ", a+1);
				}
			}
			printf("\nranjau mau dipasang di lubang ke berapa? (1-16)\n");
			for(a=0;a<c;a++){
				scanf("%d", &d);
				d = d - 1;
				if(d>=16){
					printf("lubang yang dimasukkan melebihi batas, ulangi lagi\n");
					getchar();
					continue;
				}
				if(ranjaukedua[d] != 1){
					ranjaukedua[d] = 1;
				}
				else{
					printf("ranjau tidak bisa diinputkan ke tempat yang sama, ulangi lagi\n");
					getchar();
					continue;
				}
			}
			b = 2;
			giliran = 1;
		}
		else if(b==2){
			printf("%s silahkan tebak ranjau di 4 lubang (1-16)\n");
			for(a=0;a<4;a++){
				scanf("%d", &e[a]);
				e[a] = e[a] - 1;
				if(e[a] >= 16){
					printf("lubang melebihi batas, ulangi lagi\n");
					getchar();
					continue;
				}
			}
			for(a=0;a<4;a++){
				if(ranjaupertama[e[a]] == 1){
					scoresatu += 1;
				}
				else{
					scoredua += 1;
				}
			}
			if(scoresatu >= 10){
				status=1;
				break;
			}
			if(scoredua >= 10){
				status=2;
				break;
			}
			system("clear");
			printf("[SCORE]\n");
			printf("%s: %d\n", namesatu, scoresatu);
			printf("%s: %d\n", namedua, scoredua);
			printf("Klik tombol apapun untuk melanjutkan...\n");
			getchar();
			b = 1;
			giliran = 1;
		}
	}
}


int main(){
	system("clear");
	pthread_create(&(pemain1), NULL, &pemainpertama, NULL);
	pthread_create(&(pemain2), NULL, &pemainkedua, NULL);

	while(1){
		if(status == 1){
			system("clear");
			printf("%s menang\n", namesatu);
			return;
		}
		else if(status == 2){
			system("clear");
			printf("%s menang\n", namedua);
			return;
		}
	}
}