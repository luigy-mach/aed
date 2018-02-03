#include <stdio.h>

#define MAX_SIZE 3002
#define APPEARS  1
#define DOES_NOT_APPEAR 0

void clean_jumper_array(int jumper_array[MAX_SIZE])
{
 int i;
 for (i = 0; i < MAX_SIZE; i++)
  jumper_array[i] = DOES_NOT_APPEAR;
}

int check_if_jolly_jumper(int jumper_array[MAX_SIZE], int forN)
{
 int i;
 int success = 1;
 for (i = 1; i < forN && success == 1; i++)
 {
  if (jumper_array[i] == DOES_NOT_APPEAR)
   success = 0;
 }
 
 return success;
}

int abs_diff(int a, int b)
{
 int diff = a - b;
 if (diff >= 0)
  return diff;
 else
  return -diff;
}

int main(int argc, char ** argv)
{
 int jumper_array[MAX_SIZE];
 
 int n;
 while (scanf("%d", &n) != EOF)
 {
  if (n == 1)
  {
   printf("Jolly\n", n);
   scanf("%d", &n);
  }
  else if (n == 0)
  { 
   printf("Not jolly\n", n);
  }
  else
  {
   clean_jumper_array(jumper_array);
   int nScan;
   int first;
   int second;
   int diff;
   scanf("%d", &first);
   for (nScan = 0; nScan < n - 1; nScan++)
   {
    scanf("%d", &second);
    diff = abs_diff(first, second);
    jumper_array[diff] = APPEARS;
    first = second;
   }
   
   if (check_if_jolly_jumper(jumper_array, n))
    printf("Jolly\n", n);
   else
    printf("Not jolly\n", n);
  }
 }
}
