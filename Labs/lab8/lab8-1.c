#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
	{

		/* null caracter add */
		char s[10];
		strncpy(s, "hello",5);
		s[5] = '\0';
		printf("%s\n", s);

		/* 1 chracter so char */
		printf("%c\n", 'a');

		/* null crackter carackter+1 */
		char s[13];
		strcpy(s, "Welcome Home");

		/* if equal returns 0 and need pointer*/
		char *string1 = "hello";
		char *string2 = "hello";
		if (strcmp(string1, string2) == 0) {
       puts("The strings are equal");
		}

	}
