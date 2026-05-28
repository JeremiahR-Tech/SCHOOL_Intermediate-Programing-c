#include <stdio.h>

#ifdef DEBUG
#define printd(s) printf("[DEBUG] %s", s);
#else
#define printd(s)
#endif

#ifdef debug
#define printdd(str, args...) printd("[DEBUG] "); printf(str,args)
#else
#define printdd(str,args...)
#endif

int main()
{
	printf("This should always print.\n");

	printd("debugging help. \n");
	printdd("This is the econd debugging help.\n");

	return 0;
}
