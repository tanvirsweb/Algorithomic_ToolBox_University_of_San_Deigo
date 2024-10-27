// C program to show the side effect of using
// %s in printf
#include <stdio.h>
int main()
{
	// % is intentionally put here to show side effects of
	// using printf(str)
	printf("Geek%sforGeek%s");
	printf("\n\n");
	puts("Geek%sforGeek%s");

    int c;
    printf("geeks for %ngeeks ", &c);
    printf("%d", c);
    /*
    The above program prints “geeks for geeks 10”.
     The first printf() prints “geeks for geeks”.
     The second printf() prints 10 as there are 10 characters printed (
    the 10 characters are “geeks for “) before %n in first printf() and c
    is set to 10 by first printf().
    */
	printf("I am Alvi Siddique %n =How many characters before percent n \n",&c);

	getchar();
	return 0;
}

