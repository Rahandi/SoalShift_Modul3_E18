#include <stdio.h>
#include <stdlib.h>

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

   //menghitung fakto
   for (i=1; i<argc; i++)
   {
      hasil = 1;
      for (j=input_val[i]; j>1; j--)
      {
         hasil = hasil * j;
      }
      printf("%d! = %d\n",input_val[i], hasil);
   }
}
