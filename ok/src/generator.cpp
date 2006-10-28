#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

double randr(double min, double max)
{
	return ((double)rand() / (double)RAND_MAX) * (max-min) + min;
}

int main()
{
	int offlines,tasks;
	double x=0;
	srand((unsigned)time(0));
	scanf("%d %d",&offlines,&tasks);
	printf("%d\n",offlines); 
	for (int i=0; i<offlines; ++i)
	{
		double start = randr(x,x+(tasks*75-x)/(offlines-i));
		double length = randr(1,20);
		x = start + length;
		printf("%.0f %.0f\n",start,length);
	}
	printf("%d\n",tasks); 
	for (int i=0; i<tasks; ++i)
	{
		double arr = randr(0,tasks*75/5);
		double p1 = randr(5,100);
		double p2 = randr(5,100);
		double s1 = randr(1,0.5*p1);
		double s2 = randr(1,0.5*p2);
		printf("%.0f %.0f %.0f %.0f %.0f\n",arr,s1,p1,s2,p2);
	}
}