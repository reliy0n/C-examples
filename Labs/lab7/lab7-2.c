#include <stdio.h>
#include <string.h>
#define SIZE  10
int main ()
{
int *iPtr;
int oddNum[SIZE] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
iPtr = oddNum;

  for(size_t i = 0 ; i < SIZE ; i++ ){
    printf("%d\n",oddNum[i]); //Array index notation
    printf("%d\n",iPtr[i]); // Pointer index notation
    printf("%d\n",*(iPtr+i)); // Pointer ofset
    printf("%d\n",*(oddNum+i)); // Array ofset
  }

  printf("******\n");
  printf("%d\n",oddNum[2]); //Array index notation
  printf("%d\n",iPtr[2]); // Pointer index notation
  printf("%d\n",*(iPtr+2)); // Pointer ofset
  printf("%d\n",*(oddNum+2)); // Array ofset

//What address is referenced by iPtr + 5? What value is stored at that location?
  printf("******\n");
  printf("%d\n",*(iPtr+5));
  printf("%p\n",(iPtr+5));
//j) Assuming iPtr points to oddNum[ 9 ], what address is referenced by iPtr -= 3. What value is stored at that location?
  printf("******\n");
  iPtr = &oddNum[9];
  iPtr -= 3;
  printf("%p\n",(iPtr));
}
