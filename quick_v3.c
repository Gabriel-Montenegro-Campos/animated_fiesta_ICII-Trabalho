#include <stdlib.h>

quicksortz(int x[], int lb, int ub)
{
	int j;
	if (lb > ub) return;
	j = partition(x, lb, ub);
	quicksortz(x, lb, j-1);
	quicksortz(x, j+1, ub);
}

int partition(int x[], int lb, int ub)
{
	int a, down, up;
	a = x[lb];
	up = ub; down = lb;
	while (down < up) {
		while (x[down] <= a && down < ub)
			down++;
		while (x[up] > a)
			up--;
		if (down < up)
			swap(&x[down], &x[up]);
	}
x[lb] = x[up];
x[up] = a;
return up;
}

void swap(int *x, int *y){ 
   int temp;
   temp=*x;
   *x=*y;
   *y=temp;
}


int main(){
	int y[] = {25,65,48,35};
	int n=4;
	int i;
	quicksortz(y,0,n-1);
	for(i=0; i< n; i++)
		printf("%d ", y[i]);
}
