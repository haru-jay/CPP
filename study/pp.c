#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i = 0;
	char *s = malloc(11);
	
	while(i != 10)
	{
		s[i] = i++;
	}
	printf("%d\n", s[10]);
}