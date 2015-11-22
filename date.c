#include <stdio.h>
void clasify(long temp,int *y,int *m,int *d)
{
	//int yt=0,mt=0,dt=0;
	//int *a, *b, *c;
	int gy = 10000, gm = 100;
	//a = &yt;
	//b = &mt;
	//c = &dt;
	//printf("%d/%d/%d", *a, *b, *c);
	//yt = *y;
	//mt = *m;
	//dt = *d;
	*y = temp%gy;
	*m = temp / gy/gm;
	*d = temp / gy % gm;
	//y=&yt  ;
	//m=&mt  ;
	//d=&dt;
	//printf("%d-%d-%d\n", *y, *m, *d);
}
int judgey(int a)
{
	if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
		return 1;
	else return 0;
}
int year(int s,int e)
{
	int num;
	s++;
	num = 365 * (e - s);
	for (s, e; s < e; s++)if (judgey(s))num++;
	return num;
}
int judgem(int a)
{
	int i,n=0;
	int m[7] = { 1,3,5,7,8,10,12 };
	for (i = 0; i < 7; i++)
		if (a == m[i])n++;
	if (n)
		return 1;
	else return 0;
}
int mon(int y,int m,int d)
{
	int num,i;
	num = 30 * (m-1)+d;
	for (i=1; i < m; i++)if (judgem(i))num++;
	if (m>2&&judgey(y))num--;
	if (m>2 && !judgey(y))num-=2;
	return num;
}
void main()
{
	long int start, end;
	//int a = 1, b = 2, c = 3;
	int *yy, *mm, *dd;
	int ys, ms, ds, ye, me, de;
	int days=0;
	int exs, exe;
	//printf("%d%d%d", *yy, *mm, *dd);
	begin:
	printf("Input the start date(mmddyyyy,for exampal:10222001):\n");
	scanf("%d", &start);
	printf("Input the end date(mmddyyyy):\n");
	scanf("%d", &end);
	yy = &ys;
	mm = &ms;
	dd = &ds;
	clasify(start, yy, mm, dd);
	//printf("%d_%d_%d\n", ys, ms, ds);
	//ys = *yy;
	//ms = *mm;
	//ds = *dd;
	yy = &ye;
	mm = &me;
	dd = &de;
	clasify(end, yy, mm, dd);
	if(ms==2&&ds==30||me==2&&de==30)
	{
		printf("Sorry,there are no 30 in February,please check out the date,and input again.\n");
		goto begin;
	}
	if (ms==2&&!judgey(ys)&&ds==29)
	{
		printf("Sorry, the year of %d that you inputed for start date is not a leap year, so it do not have a 29 in February. \nPlease check out the date,and input again.\n",ys);
		goto begin;
	}
	if (me == 2 && !judgey(ye) && de == 29)
	{
		printf("Sorry, the year of %d that you inputed for end date is not a leap year, so it do not have a 29 in February. \nPlease check out the date,and input again.\n", ye);
		goto begin;
	}
	//printf("%d_%d_%d", ye, me, de);
	//ye = *yy;
	//me = *mm;
	//de = *dd;
    /*看分类函数是否正确*/
	printf("Start date: %d-%d-%d\nEnd date: %d-%d-%d\n", ms, ds, ys, me, de, ye);
	exs = mon(ys, ms, ds);
	//printf("%d\n", exs);
	exe = mon(ye, me, de);
	//printf("%d\n", exe);
	if (ys<ye)
	{
		days = year(ys, ye);
		//printf("%d\n", days);
		exs = ((judgey(ys)) ? 366:365 )- exs;	
		//printf("%d\n", exs);
		days += exs + exe;
	}
	else if (ys>ye)
	{
		printf("Your end date is biger than the start date.\nPlease input again.\n");
		goto begin;
	}
	else if (ys = ye)
		days = exe - exs;
	printf("The number of days is %d\n", days);
	printf("Go on input or press Ctrl+c to exit");
	goto begin;
}