#include <stdio.h>
#include <malloc.h>
#include <windows.h>

int main()
{
	int* matrix;
	int raws, columns, k = 0, pos = 0;

	printf("Raws: ");
	scanf_s("%d", &raws);
	printf("Columns: ");
	scanf_s("%d", &columns);

	matrix = (int*)calloc(raws * columns, sizeof(int));
	for (int i = 0; i < raws; i++)
		for (int j = 0; j < columns; j++)
			scanf_s("%d", (matrix + i*columns + j));

	system("cls");

	printf("Source matrix:\n");
	for (int i = 0; i < raws; i++)
	{
		for (int j = 0; j < columns; j++)
			printf("%3d", *(matrix + i * columns + j));
		printf("\n");
	}

	for (int i = 0; i < raws * columns; i++)
	{
		if (*(matrix + i) < 0)
			k++;
		if (k == 2)
		{
			pos = i+1;
			break;
		}
	}

	for (int i = pos; i < raws * columns; i++)
		for (int j = pos; j < raws * columns; j++)
		{
			if (*(matrix + j) < *(matrix + j + 1))
			{
				int tmp = *(matrix + j);
				*(matrix + j) = *(matrix + j + 1);
				*(matrix + j + 1) = tmp;
			}
		}

	printf("Sorted matrix:\n");

	for (int i = 0; i < raws; i++)
	{
		for (int j = 0; j < columns; j++)
			printf("%3d", *(matrix + i*columns + j));
		printf("\n");
	}


	return 0;
}