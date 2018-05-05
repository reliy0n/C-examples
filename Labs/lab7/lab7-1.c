#include <stdio.h>
#include <string.h>

int main ()
{
int *zPtr;
int *aPtr = NULL;
void *sPtr = NULL;
int number;
int z[5] = {1, 2, 3, 4, 5};
zPtr = z;
++zPtr;


sPtr = z;
printf("%d\n",*zPtr);
number = *(zPtr+2);
for (size_t i = 0; i <= 4; ++i) {
printf("%d ", zPtr[i]);
}
number =  (*(int *)sPtr);



}
