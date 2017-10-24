#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void sort(int n, int argv[])
{
   int i, j, temp;
   for (i=1; i<n; i++)
   {
      for (j=1; j<n; j++)
      {
          if(argv[j-1] >= argv[j])                                
          {
             temp = argv[j-1];                                    
             argv[j-1] = argv[j];                                 
             argv[j] = temp;                                      
          }    
      }
   }
}

void fakto(int input_val[], int argc)
{
   int i, j;
   //menghitung fakto
   for (i=1; i<argc; i++)
   {
      int hasil = 1;
      for (j=input_val[i]; j>1; j--)
      {
         hasil = hasil * j;
      }
      printf("%d! = %d\n",input_val[i], hasil);
   }
}


int main(int argc, char *argv[])
{
   int i, j;
   int input_val[100];   // integer version of argv[1]
   int hasil; //hasil faktorial
   
   //cek ada argv apa g
   if (argc < 2)
   {
      printf("INPUT TIDAK VALID\n");
      exit(1);
   }

   //convert string ke int
   for (i=0; i<argc; i++)
   {
      input_val[i] = atoi(argv[i]);
   }

   sort(argc, input_val);
   fakto(input_val, argc);

}
