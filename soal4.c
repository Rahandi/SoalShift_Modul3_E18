#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

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

   //sorting
   int temp;
   for (i=1; i<argc; i++)
   {
      for (j=1; j<argc; j++)
      {
          if(input_val[j-1] >= input_val[j])                                
          {
             temp = input_val[j-1];                                    
             input_val[j-1] = input_val[j];                                 
             input_val[j] = temp;                                      
          }    
      }
   }

   fakto(input_val, argc);

}
