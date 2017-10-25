#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void carikata(void *argv)
{

}

int main (int argc, char *argv[])
{
   int i=0;

   for (i=1; i< argc; i++)
   {
      printf ("INI COBA : %s\n", argv[i]);
   }
  
   return 0;
}
