#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

pthread_t tid[100];

void *carikata(void *argv)
{
   int jumlah=0;
   char line[500], temp[500];
   FILE *filenovel;
   filenovel = fopen ("Novel.txt" , "r");

   //ditampung sementara di temp, agar bisa
   strcpy (temp, argv);
   
   //while(fgets(line, sizeof(line), filenovel)) 
   while (1)
   
   {
       if (fscanf(filenovel, "%s", line) == EOF) break;

       if(strstr(line, argv) != NULL) jumlah++;


   }

   fclose(filenovel);
   printf ("%s : %d\n", temp, jumlah);
}


int main (int argc, char *argv[])
{
   int i=0;

   for (i=1; i< argc; i++)
   {
      pthread_create(&tid[i], NULL, carikata, (void*)argv[i]);
      printf ("INI COBA : %s\n", argv[i]); //coba
   }

   
   for(i=0;i<argc;i++)
   {
      pthread_join(tid[i], NULL);
   }
  
   return 0;
}
