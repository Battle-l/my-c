#include <stdio.h>
void main ()
{
	short num, sum=0;
	int n;
	printf("input a integral number(-32768~32767):");
	scanf("%hd", &num);
	for (n = 10000; n >= 1; n /= 10)
	{
		sum+= num / n;
		num = num%n;
	}
	if (sum<0)
	printf("%hd",-sum);
	else
		printf("%hd", sum);
}