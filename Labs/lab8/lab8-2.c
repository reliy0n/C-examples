#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
	{
		char myString[5][1000] ;
    char rem[5][1000];
    int  value[5],b;

    int i = 0,a;
    for(i = 0 ; i < 5 ; i++ ){
      scanf("%999s",myString[i]);
      value[i] = strlen(myString[i]);


    }
printf("The strings ending with tion are:\n");
for(i = 0 ; i < 5 ; i++ ){
b =   value[i];
for(a = b-4 ; a < b; a++){
  if(strcmp(&myString[i][a],"tion") == 0 ){printf("%s\n",myString[i]);}
}
}
	}
