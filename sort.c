#include <stdio.h>

void printAn(int a[],int n)	//打印数组元素
{
	for(int i=0;i<n;++i)
		printf("%d ",a[i]);
	putchar('\n');
}

void insertSort(int a[],int n)	//插入排序
{
	int i,j,temp;
	for(i=1;i<n;++i)
	{
		temp=a[i];
		for(j=i;a[j-1]>temp && j>0;--j)
		{
			a[j]=a[j-1];
		}
		a[j]=temp;
	}
}

void adjustHeap(int k,int a[],int n)	//调整堆
{
	int i,temp=a[k];
	for(i=2*k+1;i<n;i=2*i+1)
	{
		if(a[i]<a[i+1] && i+1<n)
			++i;
		if(a[i]>temp)
		{
			a[k]=a[i];
			k=i;
		}
		else
			break;
	}
	a[k]=temp;
}

void heapSort(int a[],int n)	//堆排序
{
	int i,j;
	for(i=n/2-1;i>=0;--i)	//构建大顶堆
	{
		adjustHeap(i,a,n);
	}
	for(j=n-1;j>0;--j)	//首尾交换，进行排序
	{
		a[0]+=a[j];
		a[j]=a[0]-a[j];
		a[0]-=a[j];
		adjustHeap(0,a,j);
	}
}

void quickSort(int a[],int left,int right)
{
	if(left >= right)
		return;
	int i=left,j=right,key=a[i];
	while(i<j)
	{
		while(key<=a[j] &&i<j)
		{
			--j;
		}
		a[i]=a[j];
		while(key>=a[i] && i<j)
		{
			++i;
		}
		a[j]=a[i];
	}
	a[i]=key;
	quickSort(a,left,i-1);
	quickSort(a,i+1,right);
}

int main()
{
	int a[10]={3,9,4,1,5,11,8,7,2,6};
	char ch;
	printf("Please input a char to sort(i-insert,d-heap,q-quick):");
	scanf("%c",&ch);
	switch(ch)
	{
		case 'i':
		insertSort(a,10);
		printAn(a,10);
		break;
		case 'd':
		heapSort(a,10);
		printAn(a,10);
		break;
		case 'q':
		quickSort(a,0,9);
		printAn(a,10);
		break;
	}
	getchar();
	return 0;
}
