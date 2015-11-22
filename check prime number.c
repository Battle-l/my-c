#include <stdio.h>
void main ()
{
	int inte,n,temp;
	printf("Input a positive integer:");
	scanf("%d", &inte);
	for (n = 2; n < inte / 2;n++)
	{
		temp = inte%n;
		if (temp == 0)
			break;
	}
	if (temp)
		printf("%d is a prime number", inte);
	else
		printf("%d is not a prime number", inte);
}