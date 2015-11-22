#include<stdio.h>
void main()
{
  int a[20][20] = { 0 };
  int i , j, n, k,l,m,t;
   	  printf("input 1~16\n");
	  scanf_s("%d", &n);
	  if (n % 2 == 1)
	  {
		  for (i = 0, j = n / 2, k = 1; k <= n * n; i--, j++, k++)
		  {
			  if ((i == -1 && j == n) || (i >= 0 && a[i][j] != 0))
			  {
				  i = i + 2;
				  j = j - 1;
			  }
			  if (i == -1)
				  i = n - 1;
			  if (j == n)
				  j = 0;
			  a[i][j] = k;
		  }
	  }
	  else if (n % 4 == 0)
	  {
		  for (k = 1, i = 0; i < n; i++)
		  {
			  for (j = 0; j < n; j++)
			  {
				  a[i][j] = k;
				  k++;
				  for (l = 1 - n; -n < l&&l < n; l++)
				  {
					  if (i == j || (l % 4 == 0 && i + j == n - 1 - l) || (i - j) % 4 == 0)
						  a[i][j] = 0;
				  }
			  }
		  }
		  for (k = 1, i = n - 1; i >= 0; i--)
		  {
			  for (j = n - 1; j >= 0; j--)
			  {
				  if (a[i][j] != 0)
				  {
					  k++;
					  continue;
				  }
				  a[i][j] = k;
				  k++;
			  }
		  }
	  }
	  else if (n % 2 == 0 && n % 4 != 0)
	  {
		  m = (n - 2) / 4;
		  for (i = 0, j = n / 4, k = 1; k <= n * n / 4; i--, j++, k++)
		  {
			  if ((i == -1 && j == n / 2) || (i >= 0 && a[i][j] != 0))
			  {
				  i = i + 2;
				  j = j - 1;
			  }
			  if (i == -1)
				  i = n / 2 - 1;
			  if (j == n / 2)
				  j = 0;
			  a[i][j] = k;
		  }
		  for (i = n / 2, j = n / 2 + n / 4; k <= n * n / 2; i--, j++, k++)
		  {
			  if ((i == n / 2 - 1 && j == n) || (i >= n / 2 && a[i][j] != 0))
			  {
				  i = i + 2;
				  j = j - 1;
			  }
			  if (i == n / 2 - 1)
				  i = n - 1;
			  if (j == n)
				  j = n / 2;
			  a[i][j] = k;
		  }
		  for (i = 0, j = n / 2 + n / 4; k <= n * n / 2 + n*n / 4; i--, j++, k++)
		  {
			  if ((i == -1 && j == n) || (i >= 0 && a[i][j] != 0))
			  {
				  i = i + 2;
				  j = j - 1;
			  }
			  if (i == -1)
				  i = n / 2 - 1;
			  if (j == n)
				  j = n / 2;
			  a[i][j] = k;
		  }
		  for (i = n / 2, j = n / 4; k <= n * n; i--, j++, k++)
		  {
			  if ((i == n / 2 - 1 && j == n / 2) || (i >= n / 2 && j <= n / 2 - 1 && a[i][j] != 0))
			  {
				  i = i + 2;
				  j = j - 1;
			  }
			  if (i == n / 2 - 1)
				  i = n - 1;
			  if (j == n / 2)
				  j = 0;
			  a[i][j] = k;
		  }
		  for (i = 0; i <= 19; i++)
		  for (j = 0; j <= 19; j++)
		  if (i<n / 2 && (j > n / 2 + m + 1 || (i == m&&j == m) || (j < m&&!(j == 0 && i == m))))
		  {
			  t = a[i][j];
			  a[i][j] = a[i + n / 2][j];
			  a[i + n / 2][j] = t;
		  }
	  }
	  for (i = 0; i <= 19; i++)
	  {
		  printf("\n");
		  for (j = 0; j <= 19; j++)
		  if (a[i][j] != 0)
		  {
			  printf("%-4d", a[i][j]);
		  }
		  printf("\n");
		  if (a[i][0] == 0)break;
	  }
   system("pause");
}