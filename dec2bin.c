#include <stdio.h>
void main ()
{
	int decimal, binary[11];
	int m,n;
	printf("input a integer:(0~2047)\n");
	scanf("%d", &decimal);
	for (n = 0; n < 10; n++)
	{
		binary[n] = decimal % 2;
		decimal /= 2;
		if (decimal == 1)
			break;
	}
	binary[++n] = 1;
	printf("The corresponding binary number is :\n");
	for (m = 0; n - m >= 0; m++)
		printf("%d", binary[n - m]);
}