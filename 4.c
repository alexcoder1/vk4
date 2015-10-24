#include <stdio.h>
#include <malloc.h>
#define SIZE 20
//arr - отсортированный по неубыванию массив целых чисел
//x - ключ поиска
//n - размер массива
//Результат: индекс первого элемента массива, строго большего x
//При невозможности найти индекс функция возвращает -1
int bsearch(int *arr,int x,size_t n)
{
	size_t l=0,r=n,mid;
	if(0==n||arr[n-1]<=x)
		return -1;
	if(arr[0]>x)
		return 0;
    while (arr[l]<=x&&arr[r-1]>x)
	{
        mid=(l+r) >> 1;
        if (arr[mid]<=x)
            l = mid;
        else
            r = mid;
    }
	return r;
}

int main()
{
	int *a=NULL,i;
	a=(int*)malloc(SIZE*sizeof(int));
	if(!a)
	{
		printf("Not enough memory.\n");
		return 1;
	}
	for(i=0;i<SIZE;i++)
		a[i]=i+1;
	for(i=0;i<=SIZE;i++)
	{
		printf("%d ",bsearch(a,i,SIZE));
	}
	free(a);
	return 0;
}