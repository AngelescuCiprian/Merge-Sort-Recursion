#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
void merge_sort(int *v, int st , int dr)
{
	if (st < dr)
	{
		int m = (st + dr) / 2;
		merge_sort(v, st, m);
		merge_sort(v, m + 1, dr);
		//Interclasare
		int k = 0, i = st, j = m + 1;
		int* tmp = (int*)malloc((dr - st + 1) * sizeof(int));
		while (i <= m && j <= dr)
		{
			if (v[i] < v[j])
				tmp[k++] = v[i++];
			else
				tmp[k++] = v[j++];
		}
		while (i <= m)
			tmp[k++] = v[i++];
		while (j <=dr)
			tmp[k++] = v[j++];
		for (i = st, j = 0;i <= dr;i++, j++)
			v[i] = tmp[j];
	}
}
void main()
{
	int* v, n, i;
	printf("Enter the number of elements :"), scanf("%d", &n);
	 v= (int*)malloc(n * sizeof(int));
	if (v == NULL)
	{
		perror("Can t allocate memory");
			return;
	}
	for (i = 0;i < n;i++)
	{
		printf("Enter the element %d : ", i+1);
		scanf("%d", &v[i]);
	}
	printf("\The unsorted array is : \n");
	for (i = 0;i < n;i++)
		printf("%d ", v[i]);
	printf("\nThe sorted array is : \n");
	merge_sort(v, 0, n-1);
	for (i = 0;i < n;i++)
	{
		printf("%d ", v[i]);
	}
}