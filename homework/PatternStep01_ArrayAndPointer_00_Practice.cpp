

//=========================================================================================
//  01��. ���� ����� ǥ���� ���
//=========================================================================================
// 01��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	puts("���� ����� ǥ���� ���");
	printf("%C ", 'B');		// �����������ڴ� �빮�� �ҹ��� �������� ���
	printf("%c", '\n');

	return 0;
}
#endif

//=========================================================================================
// 01��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	char a1, a2;
	// -------�Է�-���� �ʱ�ȭ----------------------------

	scanf(" %c %c", &a1, &a2);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	puts("���� ����� ǥ���� ���");
	printf("%c ", a1);		// �����������ڴ� �빮�� �ҹ��� �������� ���
	printf("%c", a2);

	return 0;
}
#endif

// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 01��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value
#if 0
#include <stdio.h>
void printData(char, char);
int main(void) {
	// -------�Է�-���� ����------------------------------
	char a1, a2;
	// -------�Է�-���� �ʱ�ȭ----------------------------

	scanf(" %c %c", &a1, &a2);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(a1, a2);
	return 0;
}

void printData(char a1, char a2)
{
	puts("���� ����� ǥ���� ���");
	printf("%c ", a1);		// �����������ڴ� �빮�� �ҹ��� �������� ���
	printf("%c", a2);
	return;
}
#endif
// case 2. call-by-address
#if 0
#include <stdio.h>
void inputData(char*, char*);
void printData(char*, char*);
int main(void) {
	// -------�Է�-���� ����------------------------------
	char a1, a2;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	inputData(&a1, &a2);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(&a1, &a2);
	return 0;
}

void inputData(char* a1, char* a2)
{
	scanf(" %c %c", *(&a1), *(&a2));
	return;
}

void printData(char* a1, char* a2)
{
	puts("���� ����� ǥ���� ���");
	printf("%c ", *a1);		// �����������ڴ� �빮�� �ҹ��� �������� ���
	printf("%c", *a2);
	return;
}
#endif
// case 3. call-by-reference
#if 0
#include <stdio.h>
void inputData(char&, char&);
void printData(char&, char&);
int main(void) {
	// -------�Է�-���� ����------------------------------
	char a1, a2;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	inputData(a1, a2);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(a1, a2);
	return 0;
}

void inputData(char& a1, char& a2)
{
	scanf(" %c %c", &a1, &a2);
	return;
}

void printData(char& a1, char& a2)
{
	puts("���� ����� ǥ���� ���");
	printf("%c ", a1);		// �����������ڴ� �빮�� �ҹ��� �������� ���
	printf("%c", a2);
	return;
}
#endif
//=========================================================================================
// 01��-03.1���� �迭
//=========================================================================================
#if 0
#include <stdio.h>
#define ColSize 2               // 2 
void inputData(char[ColSize], int, int);      //12
void printData(char[ColSize], int, int);      //13   
int main(void) {
	// -------�Է�-���� ����------------------------------
	char a[ColSize];            // 1
	int i, CSize;               // 3
	// -------�Է�-���� �ʱ�ȭ----------------------------
	i = 0;                  // 4
	CSize = ColSize;
	inputData(a, i, CSize);            // 5

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(a, i, CSize);           // 6

	return 0;
}
void inputData(char a[ColSize], int i, int CSize)   //7
{
	for (i = 0; i < CSize; i++)            //9 forŸ�����ϰ� ���� �ٷ� ��Ű ������ �ڵ��ϼ�
	{
		scanf(" %c", &a[i]);          //10
	}
	return;
}
void printData(char a[ColSize], int i, int CSize)   // 8
{
	puts("���� ����� ǥ���� ���");
	for (i = 0; i < CSize; i++)            //11
	{
		printf("%c ", a[i]);
	}
	return;
}
#endif

//=========================================================================================
// 01��-04.1���� ������
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define ColSize 2
void inputData(char*, int, int);
void printData(char*, int, int);

int main(void) {
	// -------�Է�-���� ����------------------------------
	char* a;
	int i, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	a = (char*)malloc(sizeof(char) * ColSize);
	i = 0;
	CSize = ColSize;
	inputData(a, i, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(a, i, CSize);

	free(a);
	return 0;
}
void inputData(char* a, int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		//scanf(" %c", &a[i]);
		//scanf(" %c", &(a[i]));3

		//scanf(" %c", &(*(a+i)));   
		scanf(" %c", (a + i));
	}
	return;
}
void printData(char* a, int i, int CSize)
{
	puts("���� ����� ǥ���� ���");
	for (i = 0; i < CSize; i++)
	{
		//printf("%c", a[i]);
		printf("%c", *(a + i));
	}
	return;
}
#endif

//=========================================================================================
// 01��-05.2���� �迭
//=========================================================================================
#if 0
#include <stdio.h>
#define RowSize 1
#define ColSize 2
void inputData(char[RowSize][ColSize], int, int, int, int);
void printData(char[RowSize][ColSize], int, int, int, int);

int main(void) {
	// -------�Է�-���� ����------------------------------
	char a[RowSize][ColSize];
	int i, j, RSize, CSize;

	// -------�Է�-���� �ʱ�ȭ----------------------------
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(a, i, j, RSize, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(a, i, j, RSize, CSize);

	return 0;
}
void inputData(char a[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//scanf(" %c", &a[i][j]);
			//scanf(" %c", &(a[i][j]));
			//scanf(" %c", &(*(a[i]+j)));
			//scanf(" %c", (a[i]+j));
			//scanf(" %c", &(*(*(a+i)+j)));
			scanf(" %c", (*(a + i) + j));
		}
	}
	return;
}
void printData(char a[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	puts("���� ����� ǥ���� ���");
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//printf("%c", a[i][j]);
			//printf("%c", *(a[i]+j));
			//printf("%c", *(a[i]+j));
			printf("%c", *(*(a + i) + j));
		}
	}
	return;
}
#endif

//=========================================================================================
// 01��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define RowSize 1
#define ColSize 2
void inputData(char* [RowSize], int, int, int, int);
void printData(char* [RowSize], int, int, int, int);

int main(void) {
	// -------�Է�-���� ����------------------------------
	char* a[RowSize];
	int i, j, RSize, CSize;

	// -------�Է�-���� �ʱ�ȭ----------------------------
	for (i = 0; i < RowSize; i++)
	{
		a[i] = (char*)malloc(sizeof(char) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(a, i, j, RSize, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(a, i, j, RSize, CSize);

	for (i = 0; i < RowSize; i++)
	{
		free(a[i]);
	}
	return 0;
}
void inputData(char* a[RowSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//scanf(" %c", &a[i][j]);
			//scanf(" %c", &(a[i][j]));
			//scanf(" %c", &(*(a[i]+j)));
			//scanf(" %c", (a[i]+j));
			//scanf(" %c", &(*(*(a+i)+j)));
			scanf(" %c", (*(a + i) + j));

		}
	}
	return;
}
void printData(char* a[RowSize], int i, int j, int RSize, int CSize)
{
	puts("���� ����� ǥ���� ���");
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//printf("%c", a[i][j]);
			//printf("%c", *(a[i]+j));
			printf("%c", *(*(a + i) + j));
		}
	}
	return;
}
#endif
//=========================================================================================
// 01��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 01��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define RowSize 1
#define ColSize 2
void inputData(char**, int, int, int, int);
void printData(char**, int, int, int, int);

int main(void) {
	// -------�Է�-���� ����------------------------------
	char** a;
	int i, j, RSize, CSize;

	// -------�Է�-���� �ʱ�ȭ----------------------------
	a = (char**)malloc(sizeof(char*) * RowSize);
	for (i = 0; i < RowSize; i++)
	{
		a[i] = (char*)malloc(sizeof(char) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(a, i, j, RSize, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(a, i, j, RSize, CSize);

	for (i = 0; i < RowSize; i++)
	{
		free(a[i]);
	}
	free(a);

	return 0;
}
void inputData(char** a, int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//scanf(" %c", &a[i][j]);
			//scanf(" %c", &(a[i][j]));
			//scanf(" %c", &(*(a[i]+j)));
			//scanf(" %c", (a[i]+j));
			//scanf(" %c", &(*(*(a+i)+j)));
			//scanf(" %c", (*(a+i)+j));

		}
	}
	return;
}
void printData(char** a, int i, int j, int RSize, int CSize)
{
	puts("���� ����� ǥ���� ���");
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//printf("%c", a[i][j]);
			//printf("%c", *(a[i]+j));
			printf("%c", *(*(a + i) + j));
		}
	}
	return;
}
#endif

//=========================================================================================
// 01��-09. ����ü �Լ� ��ȯ
//=========================================================================================
// 01��-09-1. call-by-value
//=========================================================================================
// case 1. ����ü�� typdef�� �и��Ͽ� ������ ��� 
//-----------------------------------------------------------------------------------------
#if 0
#include <stdio.h>
struct _SData
{
	char a1, a2;
};
typedef struct _SData SData;

SData inputData(SData);
SData printData(SData);

int main(void)
{
	SData x;
	x.a1 = '0';
	(&x)->a2 = '0';

	x = inputData(x);
	x = printData(x);
	return 0;
}

SData inputData(SData x)
{
	scanf(" %c %c", &(x.a1), &((&x)->a2));
	return x;
}

SData printData(SData x)
{
	puts("���� ����� ǥ���� ���");
	printf("%c", x.a1);
	printf("%c", (&x)->a2);
	return x;
}
#endif

//-----------------------------------------------------------------------------------------
// case 2. ����ü�� typdef�� �����Ͽ�  ������ ���
//-----------------------------------------------------------------------------------------
#if 0
#include <cstdio>

typedef struct _SData
{
	char a1, a2;
	struct _SData inputData(struct _SData);
	struct _SData printData(struct _SData);
}SData;

SData SData::inputData(SData x)
{
	scanf(" %c %c", &(x.a1), &((&x)->a2));
	return x;
}
SData SData::printData(SData x)
{
	puts("���� ����� ǥ���� ���");
	printf("%c", x.a1);
	printf("%c", (&x)->a2);
	return x;
}

int main(void) {
	// -------�Է�-���� ����------------------------------
	SData x;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	x.a1 = '0';
	(&x)->a2 = '0';

	x = x.inputData(x);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	x = x.printData(x);
	return 0;
}

#endif
//=========================================================================================
// 01��-09-3. call-by-reference
//=========================================================================================
// case 1. �Լ��� ��ȯ���� Call by reference ������� ��ȯ�ϴ� ��� 
//-----------------------------------------------------------------------------------------
// case 3. call-by-reference
#if 0
#include <stdio.h>

typedef struct _SData
{
	char a1, a2;
}SData;

SData& inputData(SData&);
SData& printData(SData&);

int main(void) {
	// -------�Է�-���� ����------------------------------
	SData x;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	x = inputData(x);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	x = printData(x);

	return 0;
}
SData& inputData(SData& x)
{
	scanf(" %c %c", &(x.a1), &((&x)->a2));
	return x;
}
SData& printData(SData& x)
{
	puts("���� ����� ǥ���� ���");
	printf("%c", x.a1);
	printf("%c", (&x)->a2);
	return x;
}
#endif

//=========================================================================================
// 01��-09-2. call-by-address
//=========================================================================================
// case 1. �Լ��� ��ȯ���� call by address�� ��ȯ�ϴ� ��� 
//-----------------------------------------------------------------------------------------
#if 0
#include <stdio.h>
typedef struct _SData
{
	char a1, a2;
}SData;

SData* inputData(SData*);
SData* printData(SData*);

int main(void) {
	// -------�Է�-���� ����------------------------------
	SData x;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	x = *(inputData(&x));

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	x = *(printData(&x));

	return 0;
}
SData* inputData(SData* x)
{
	scanf(" %c %c", &((*x).a1), &(x->a2));
	return x;
}
SData* printData(SData* x)
{
	puts("���� ����� ǥ���� ���");
	printf("%c", (*x).a1);
	printf("%c", x->a2);
	return x;
}
#endif

//=========================================================================================
// 01��-10. ����ü 1���� �迭
//=========================================================================================
// case 1. �Լ��� ��ȯ���� call by value�� ��ȯ�ϴ� ��� 
//-----------------------------------------------------------------------------------------
#if 0
#include <stdio.h>
#define ColSize 2

typedef struct _SData
{
	char a1, a2;
}SData;

SData& inputData(SData[ColSize], int, int);
SData* printData(SData[ColSize], int, int);

int main(void) {
	// -------�Է�-���� ����------------------------------
	SData x[ColSize];
	int i, CSize;
	// -------�Էº��� �ʱ�ȭ----------------------------
	i = 0;
	CSize = ColSize;
	*x = inputData(x, i, CSize);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	*x = *(printData(x, i, CSize));

	return 0;
}
SData& inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		//scanf(" %c %c", &(x[i].a1), &(x[i].a2));
		scanf(" %c %c", &((*(x + i)).a1), &((*(x + i)).a2));
		scanf(" %c %c", &((x + i)->a1), &((x + i)->a2));
	}
	//return *(x+0);
	return *x;

}
SData* printData(SData x[ColSize], int i, int CSize)
{
	puts("���� ����� ǥ���� ���");
	for (i = 0; i < CSize; i++)
	{
		printf("%c", x[i].a1);
		//printf("%c", x[i].a2);
		//printf("%c", (*(x+i)).a2);   
		printf("%c", (x + i)->a2);
	}
	//return (x+0);
	return x;

}
#endif

//=========================================================================================
// 01��-11. ����ü 1���� �迭 - ������ ��ȯ
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define ColSize 2

typedef struct _SData
{
	char a1, a2;
}SData;

SData* inputData(SData*, int, int);
SData& printData(SData*, int, int);

int main(void) {
	// -------�Է�-���� ����------------------------------
	SData* x;
	int i, CSize;

	// -------�Է�-���� �ʱ�ȭ----------------------------
	x = (SData*)malloc(sizeof(SData) * ColSize);
	i = 0;
	CSize = ColSize;

	*x = *(inputData(x, i, CSize));
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	*x = printData(x, i, CSize);

	free(a);

	return 0;
}
SData* inputData(SData* x, int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		//scanf(" %c %c", &(x[i].a1), &(x[i].a2));
		//scanf(" %c %c", &((*(x+i)).a1), &((*(x+i)).a2));
		scanf(" %c %c", &((x + i)->a1), &((x + i)->a2));
		//scanf(" %c %c", &((&x[i])->a1), &((&x[i])->a2));
	}
	//return (x+0);
	return x;
}
SData& printData(SData* x, int i, int CSize)
{
	puts("���� ����� ǥ���� ���");
	for (i = 0; i < CSize; i++)
	{
		printf("%c", x[i].a1);
		//printf("%c", x[i].a2);
		//printf("%c", (*(x+i)).a2);
		printf("%c", (x + i)->a2);
	}

	//return *(x+0);
	return *x;
}
#endif



//=========================================================================================
// 01��-12. ����ü 2���� �迭
//=========================================================================================
// case 1. �Լ��� ��ȯ���� call by value�� ��ȯ�ϴ� ��� 
//-----------------------------------------------------------------------------------------
#if 0
#include <stdio.h>
#define RowSize 1
#define ColSize 2
struct _SData
{
	char a1, a2;
};
typedef struct _SData SData;

SData* inputData(SData[RowSize][ColSize], int, int, int, int);
SData& printData(SData[RowSize][ColSize], int, int, int, int);

int main(void) {
	// -------�Է�-���� ����------------------------------
	SData x[RowSize][ColSize];
	int i, j, RSize, CSize;

	// -------�Է�-���� �ʱ�ȭ----------------------------
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	**x = *(inputData(x, i, j, RSize, CSize));
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	**x = printData(x, i, j, RSize, CSize);
	return 0;
}
SData* inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//scanf(" %c %c", &(x[i][j].a1), &(x[i][j].a2));
			//scanf(" %c %c", &((x[i][j]).a1), &((x[i][j]).a2));
			//scanf(" %c %c", &((*(x[i]+j)).a1), &((*(x[i]+j)).a2));
			//scanf(" %c %c", &((x[i]+j)->a1), &((x[i]+j)->a2));
			//scanf(" %c %c", &((*(*(x+i)+j)).a1), &((*(*(x+i)+j)).a2));
			scanf(" %c %c", &((*(x + i) + j)->a1), &((*(x + i) + j)->a2));
		}
	}
	//return *(x+0);
	return *x;
}
SData& printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	puts("���� ����� ǥ���� ���");
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("%c", x[i][j].a1);
			//printf("%c", x[i][j].a2);
			//printf("%c", (*(x[i]+j)).a2);
			//printf("%c", (x[i]+j)->a2);
			//printf("%c", (*(*(x+i)+j)).a2);
			printf("%c", (*(x + i) + j)->a2);
		}
	}
	//return *(*(x+0)+0);
	//return *(*(x+0));
	//return *(*(x));
	return **x;
}
#endif



//=========================================================================================
// 01��-13. ����ü 2���� �迭 - ������ �迭 ��ȯ
//=========================================================================================
#if 0

#include <stdio.h>
#include <malloc.h>
#define RowSize 1
#define ColSize 2

struct SData
{
	char a1, a2;
};
typedef struct SData SData;

SData* inputData(SData* [RowSize], int, int, int, int);
SData& printData(SData* [RowSize], int, int, int, int);

int main(void) {
	// -------�Է�-���� ����------------------------------
	SData* x[RowSize];
	int i, j, RSize, CSize;

	// -------�Է�-���� �ʱ�ȭ----------------------------
	for (i = 0; i < RowSize; i++)
	{
		x[i] = (SData*)malloc(sizeof(SData) * ColSize);
	}

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	//**x = *(inputData(x, i, j, RSize, CSize));
	*x = inputData(x, i, j, RSize, CSize);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	//**x= printData(x, i, j, RSize, CSize);
	*x = &(printData(x, i, j, RSize, CSize));

	for (i = 0; i < RowSize; i++)
	{
		free(x[i]);
	}
	return 0;
}
SData* inputData(SData* x[RowSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//scanf(" %c %c", &(x[i][j].a1), &(x[i][j].a2));
			//scanf(" %c %c", &((*(x[i]+j)).a1), &((x[i][j]).a2));
			//scanf(" %c %c", &((x[i]+j)->a1), &((x[i][j]).a2));
			//scanf(" %c %c", &((*(*(x+i)+j)).a1), &((x[i][j]).a2));
			scanf(" %c %c", &((*(x + i) + j)->a1), &((x[i][j]).a2));
		}
	}
	return *x;
}
SData& printData(SData* x[RowSize], int i, int j, int RSize, int CSize)
{
	puts("���� ����� ǥ���� ���");
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("%C ", x[i][j].a1);
			//printf("%c", x[i][j].a2);
			//printf("%c", (*(x[i]+j)).a2);
			//printf("%c", (x[i]+j)->a2);
			//printf("%c", (*(*(x+i)+j)).a2);   
			printf("%c", (*(x + i) + j)->a2);
		}
	}

	return **x;
}
#endif


//=========================================================================================
// 01��-15. ����ü 2���� �迭 - ���� ������ ��ȯ
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define RowSize 1
#define ColSize 2

struct _SData
{
	char a1, a2;
};
typedef struct _SData SData;

SData* inputData(SData**, int, int, int, int);
SData& printData(SData**, int, int, int, int);

int main(void) {
	// -------�Է�-���� ����------------------------------
	SData** x;
	int i, j, RSize, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	x = (SData * *)malloc(sizeof(SData*) * RowSize);
	for (i = 0; i < RowSize; i++)
	{
		x[i] = (SData*)malloc(sizeof(SData) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	**x = *(inputData(x, i, j, RSize, CSize));
	*x = inputData(x, i, j, RSize, CSize);
	//**x = *(*x));

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	**x = printData(x, i, j, RSize, CSize);
	*x = &printData(x, i, j, RSize, CSize);
	//*xx = **x; 

	for (i = 0; i < RowSize; i++)
	{
		free(x[i]);
	}
	free(x);
	return 0;
}
SData* inputData(SData** x, int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//scanf(" %c %c",  &(x[i][j].a1), &(x[i][j].a2));
			//scanf(" %c %c",  &((*(x[i]+j)).a1), &((*(x[i]+j)).a2));
			//scanf(" %c %c",  &((*(*(x+i)+j)).a1), &((*(*(x+i)+j)).a2));
			//scanf(" %c %c",  &((x[i]+j)->a1), &((x[i]+j)->a2));
			scanf(" %c %c", &((*(x + i) + j)->a1), &((*(x + i) + j)->a2));
		}
	}
	//return (*(x+0)+0);
	//return *(x+0);
	//return *(x);
	return *x;
}
SData& printData(SData** x, int i, int j, int RSize, int CSize)
{
	puts("���� ����� ǥ���� ���");
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("%c", x[i][j].a1);
			//printf("%c", x[i][j].a2);
			//printf("%c", (*(x[i]+j)).a2);
			//printf("%c", (*(*(x+i)+j)).a2);   
			//printf("%c", (x[i]+j)->a2);
			printf("%c", (*(x + i) + j)->a2);
		}
	}

	//return *(*(x+0)+0);
	//return *(*(x+0));
	//return *(*(x));
	return **x;
}
#endif





//=========================================================================================
// 02��. ���� ����� �Ǽ� ����� ǥ���� ���
//=========================================================================================
// 02��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#include <stdio.h>
int main(void)
{
	// -------�Է�-���� ����------------------------------
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("���� ����� ǥ���� ���\n");
	printf("%d ", 30);
	printf("%d ", 030);
	printf("%d ", 0X2F);

	printf("�Ǽ� ����� ǥ���� ���\n");
	printf("%lf ", 3.14);
	printf("%lf ", 3.14);
	printf("%lf ", 3.14);

	return 0;
}
#endif

//=========================================================================================
// 02��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#include <stdio.h>
int main(void)
{
	// -------�Է�-���� ����------------------------------
	int x1, x2, x3;
	double y1, y2, y3;

	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf("%d%d%d", &x1, &x2, &x3);
	scanf("%lf%lf%lf", &y1, &y2, &y3);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("���� ����� ǥ���� ���\n");
	printf("%d ", x1);
	printf("%d ", x2);
	printf("%d ", x3);

	printf("�Ǽ� ����� ǥ���� ���\n");
	printf("%lf ", y1);
	printf("%lf ", y2);
	printf("%lf ", y3);

	return 0;
}
#endif

// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 02��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value
#if 0
#include <stdio.h>

void printData(int, int, int, double, double, double);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	int x1, x2, x3;
	double y1, y2, y3;

	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf("%d%d%d", &x1, &x2, &x3);
	scanf("%lf%lf%lf", &y1, &y2, &y3);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x1, x2, x3, y1, y2, y3);
	return 0;
}

void printData(int x1, int x2, int x3, double y1, double y2, double y3)
{
	printf("���� ����� ǥ���� ���\n");
	printf("%d ", x1);
	printf("%d ", x2);
	printf("%d ", x3);

	printf("�Ǽ� ����� ǥ���� ���\n");
	printf("%lf ", y1);
	printf("%lf ", y2);
	printf("%lf ", y3);
	return;
}
#endif
// case 2. call-by-address
#if 0
#include <stdio.h>

void inputData(int*, int*, int*, double*, double*, double*);
void printData(int*, int*, int*, double*, double*, double*);
int main(void)
{
	// -------�Է�-���� ����------------------------------
	int x1, x2, x3;
	double y1, y2, y3;

	// -------�Է�-���� �ʱ�ȭ----------------------------
	inputData(&x1, &x2, &x3, &y1, &y2, &y3);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(&x1, &x2, &x3, &y1, &y2, &y3);
	return 0;
}
void inputData(int* x1, int* x2, int* x3, double* y1, double* y2, double* y3)
{
	scanf("%d%d%d", *(&x1), *(&x2), *(&x3));
	scanf("%lf%lf%lf", *(&y1), *(&y2), *(&y3));
	return;
}
void printData(int* x1, int* x2, int* x3, double* y1, double* y2, double* y3)
{
	printf("���� ����� ǥ���� ���\n");
	printf("%d ", *x1);
	printf("%d ", *x2);
	printf("%d ", *x3);

	printf("�Ǽ� ����� ǥ���� ���\n");
	printf("%lf ", *y1);
	printf("%lf ", *y2);
	printf("%lf ", *y3);
	return;
}
#endif
// case 3. call-by-reference
#if 0
#include <stdio.h>

void inputData(int&, int&, int&, double&, double&, double&);
void printData(int&, int&, int&, double&, double&, double&);
int main(void)
{
	// -------�Է�-���� ����------------------------------
	int x1, x2, x3;
	double y1, y2, y3;

	// -------�Է�-���� �ʱ�ȭ----------------------------
	inputData(x1, x2, x3, y1, y2, y3);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x1, x2, x3, y1, y2, y3);
	return 0;
}
void inputData(int& x1, int& x2, int& x3, double& y1, double& y2, double& y3)
{
	scanf("%d%d%d", &x1, &x2, &x3);
	scanf("%lf%lf%lf", &y1, &y2, &y3);
	return;
}
void printData(int& x1, int& x2, int& x3, double& y1, double& y2, double& y3)
{
	printf("���� ����� ǥ���� ���\n");
	printf("%d ", x1);
	printf("%d ", x2);
	printf("%d ", x3);

	printf("�Ǽ� ����� ǥ���� ���\n");
	printf("%lf ", y1);
	printf("%lf ", y2);
	printf("%lf ", y3);
	return;
}
#endif
//=========================================================================================
// 02��-03.1���� �迭
//=========================================================================================
#if 0
#include <stdio.h>
#define ColSize 3

void inputData(int[ColSize], double[ColSize], int, int);
void printData(int[ColSize], double[ColSize], int, int);
int main(void)
{
	// -------�Է�-���� ����------------------------------
	int x[ColSize];
	double y[ColSize];
	int i, CSize;

	// -------�Է�-���� �ʱ�ȭ----------------------------
	i = 0;
	CSize = ColSize;
	inputData(x, y, i, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, y, i, CSize);
	return 0;
}
void inputData(int x[ColSize], double y[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%d", &x[i]);
	}
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &y[i]);
	}
	return;
}
void printData(int x[ColSize], double y[ColSize], int i, int CSize)
{
	printf("���� ����� ǥ���� ���\n");
	for (i = 0; i < CSize; i++)
	{
		printf("%d ", x[i]);
	}

	printf("�Ǽ� ����� ǥ���� ���\n");
	for (i = 0; i < CSize; i++)
	{
		printf("%lf ", y[i]);
	}
	return;
}
#endif
//=========================================================================================
// 02��-04.1���� ������
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define ColSize 3

void inputData(int*, double*, int, int);
void printData(int*, double*, int, int);
int main(void)
{
	// -------�Է�-���� ����------------------------------
	int* x;
	double* y;
	int i, CSize;

	// -------�Է�-���� �ʱ�ȭ----------------------------
	x = (int*)malloc(sizeof(int) * ColSize);
	y = (double*)malloc(sizeof(double) * ColSize);
	i = 0;
	CSize = ColSize;
	inputData(x, y, i, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, y, i, CSize);
	free(y); // ���� ��� �ϳ�? 
	free(x);
	return 0;
}
void inputData(int* x, double* y, int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%d", (x + i));
	}
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", (y + i));
	}
	return;
}
void printData(int* x, double* y, int i, int CSize)
{
	printf("���� ����� ǥ���� ���\n");
	for (i = 0; i < CSize; i++)
	{
		printf("%d ", *(x + i));
	}

	printf("�Ǽ� ����� ǥ���� ���\n");
	for (i = 0; i < CSize; i++)
	{
		printf("%lf ", *(y + i));
	}
	return;
}
#endif
//=========================================================================================
// 02��-05.2���� �迭
//=========================================================================================
#if 0
#include <stdio.h>
#define RowSize 1
#define ColSize 3

void inputData(int[RowSize][ColSize], double[RowSize][ColSize], int, int, int, int);
void printData(int[RowSize][ColSize], double[RowSize][ColSize], int, int, int, int);
int main(void)
{
	// -------�Է�-���� ����------------------------------
	int x[RowSize][ColSize];
	double y[RowSize][ColSize];
	int i, j, RSize, CSize;

	// -------�Է�-���� �ʱ�ȭ----------------------------
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(x, y, i, j, RSize, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, y, i, j, RSize, CSize);
	return 0;
}
void inputData(int x[RowSize][ColSize], double y[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{

		for (j = 0; j < CSize; j++)
		{
			scanf("%d", (*(x + i) + j));
		}
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", (*(y + i) + j));
		}
	}
	return;
}
void printData(int x[RowSize][ColSize], double y[RowSize][ColSize], int i, int j, int RSize, int CSize)
{

	printf("���� ����� ǥ���� ���\n");
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("%d ", *(*(x + i) + j));
		}
	}
	puts("");
	printf("�Ǽ� ����� ǥ���� ���\n");
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("%lf ", *(*(y + i) + j));
		}
	}
	puts("");

	return;
}
#endif
//=========================================================================================
// 02��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define RowSize 1
#define ColSize 3

void inputData(int* [RowSize], double* [RowSize], int, int, int, int);
void printData(int* [RowSize], double* [RowSize], int, int, int, int);
int main(void)
{
	// -------�Է�-���� ����------------------------------
	int* x[RowSize];
	double* y[RowSize];
	int i, j, RSize, CSize;

	// -------�Է�-���� �ʱ�ȭ----------------------------
	for (i = 0; i < RowSize; i++)
	{
		x[i] = (int*)malloc(sizeof(int) * ColSize);
		y[i] = (double*)malloc(sizeof(double) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(x, y, i, j, RSize, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, y, i, j, RSize, CSize);

	for (i = 0; i < RowSize; i++)
	{
		free(x[i]);
		free(y[i]);
	}
	return 0;
}
void inputData(int* x[RowSize], double* y[RowSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%d", (*(x + i) + j));
		}
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", (*(y + i) + j));
		}
	}
	return;
}
void printData(int* x[RowSize], double* y[RowSize], int i, int j, int RSize, int CSize)
{

	printf("���� ����� ǥ���� ���\n");
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("%d ", *(*(x + i) + j));
		}
	}
	puts("");
	printf("�Ǽ� ����� ǥ���� ���\n");
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("%lf ", *(*(y + i) + j));
		}
	}
	puts("");

	return;
}
#endif
//=========================================================================================
// 02��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 02��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define RowSize 1
#define ColSize 3

void inputData(int**, double**, int, int, int, int);
void printData(int**, double**, int, int, int, int);
int main(void)
{
	// -------�Է�-���� ����------------------------------
	int** x;
	double** y;
	int i, j, RSize, CSize;

	// -------�Է�-���� �ʱ�ȭ----------------------------
	x = (int**)malloc(sizeof(int*) * RowSize);
	y = (double**)malloc(sizeof(double*) * RowSize);
	for (i = 0; i < RowSize; i++)
	{
		x[i] = (int*)malloc(sizeof(int) * ColSize);
		y[i] = (double*)malloc(sizeof(double) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(x, y, i, j, RSize, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, y, i, j, RSize, CSize);

	for (i = 0; i < RowSize; i++)
	{
		free(x[i]);
		free(y[i]);
	}
	free(x);
	free(y);

	return 0;
}
void inputData(int** x, double** y, int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%d", (*(x + i) + j));
		}
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", (*(y + i) + j));
		}
	}
	return;
}
void printData(int** x, double** y, int i, int j, int RSize, int CSize)
{

	printf("���� ����� ǥ���� ���\n");
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("%d ", *(*(x + i) + j));
		}
	}
	puts("");
	printf("�Ǽ� ����� ǥ���� ���\n");
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("%lf ", *(*(y + i) + j));
		}
	}
	puts("");

	return;
}
#endif



//=========================================================================================
//  03��. ����
//=========================================================================================
// 03��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#include <stdio.h>
int main(void)
{
	// -------�Է�-���� ����------------------------------
	int age;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	age = 20;
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("%d\n", age);

	age = 21;			// ������ �������� �Ҵ��� ���� ������ ������ 20�̶�� ���� 21�� �����
	printf("%d\n", age);

	return 0;
}
#endif

//=========================================================================================
// 03��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#include <stdio.h>
int main(void)
{
	// -------�Է�-���� ����------------------------------
	int age;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf("%d", &age);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("%d\n", age);

	scanf("%d", &age);	// ������ �������� �Ҵ��� ���� ������ ������ 20�̶�� ���� 21�� �����
	printf("%d\n", age);

	return 0;
}
#endif

// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 03��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value
#if 0
#include <stdio.h>

void printData(int);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	int age;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf("%d", &age);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(age);

	scanf("%d", &age);	// ������ �������� �Ҵ��� ���� ������ ������ 20�̶�� ���� 21�� �����
	printData(age);
	return 0;
}

void printData(int age) {
	printf("%d\n", age);
	return;
}

#endif
// case 2. call-by-address
#if 0
#include <stdio.h>

void inputData(int*);
void printData(int*);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	int age;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	inputData(&age);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(&age);
	inputData(&age);

	printData(&age);
	return 0;
}
void inputData(int* age) {
	scanf("%d", age);
	return;
}

void printData(int* age) {
	printf("%d\n", *age);
	return;
}

#endif
// case 3. call-by-reference
#if 0
#include <stdio.h>

void inputData(int&);
void printData(int&);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	int age;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	inputData(age);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(age);

	scanf("%d", &age);	// ������ �������� �Ҵ��� ���� ������ ������ 20�̶�� ���� 21�� �����
	printData(age);
	return 0;
}
void inputData(int& age) {
	scanf("%d", &age);
	return;
}

void printData(int& age) {
	printf("%d\n", age);
	return;
}

#endif
//=========================================================================================
// 03��-03.1���� �迭
//=========================================================================================
#if 0
#include <stdio.h>
#define ColSize 2
void inputData(int[ColSize], int, int);
void printData(int[ColSize], int, int);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	int age[ColSize];
	int i, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	i = 0;
	CSize = ColSize;
	inputData(age, i, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(age, i, CSize);

	return 0;
}

void inputData(int age[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%d", &age[i]);
	}
	return;
}

void printData(int age[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("%d\n", age[i]);
	}
	return;
}

#endif
//=========================================================================================
// 03��-04.1���� ������
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define ColSize 2

void inputData(int*, int, int);
void printData(int*, int, int);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	int* age;
	int i, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	age = (int*)malloc(sizeof(char) * ColSize);
	i = 0;
	CSize = ColSize;
	inputData(age, i, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(age, i, CSize);


	return 0;
}
void inputData(int* age, int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%d", (age + i));
	}
	return;
}

void printData(int* age, int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("%d\n", *(age + i));
	}
	return;
}

#endif
//=========================================================================================
// 03��-05.2���� �迭
//=========================================================================================
#if 0
#include <stdio.h>
#define RowSize 1
#define ColSize 2
void inputData(int[RowSize][ColSize], int, int, int, int);
void printData(int[RowSize][ColSize], int, int, int, int);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	int age[RowSize][ColSize];
	int i, j, RSize, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(age, i, j, RSize, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(age, i, j, RSize, CSize);

	return 0;
}

void inputData(int age[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//scanf("%d", &age[i][j]);
			//scanf("%d", &(age[i][j]));
			//scanf("%d", &(*(age[i]+j)));
			//scanf("%d", (age[i] + j));
			//scanf("%d", &(*(*(age+i) + j)));
			scanf("%d", (*(age + i) + j));
		}
	}
	return;
}

void printData(int age[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//printf("%d\n", age[i][j]);
			//printf("%d\n", *(age[i]+j));
			printf("%d\n", *(*(age + i) + j));
		}
	}
	return;
}

#endif
//=========================================================================================
// 03��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define RowSize 1
#define ColSize 2
void inputData(int* [RowSize], int, int, int, int);
void printData(int* [RowSize], int, int, int, int);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	int* age[RowSize];
	int i, j, RSize, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	for (i = 0; i < RowSize; i++)
	{
		age[i] = (int*)malloc(sizeof(char) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(age, i, j, RSize, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(age, i, j, RSize, CSize);

	for (i = 0; i < RowSize; i++)
	{
		free(age[i]);
	}
	return 0;
}

void inputData(int* age[RowSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//scanf("%d", &age[i][j]);
			//scanf("%d", &(age[i][j]));
			//scanf("%d", &(*(age[i]+j)));
			//scanf("%d", (age[i] + j));
			//scanf("%d", &(*(*(age+i) + j)));
			scanf("%d", (*(age + i) + j));
		}
	}
	return;
}

void printData(int* age[RowSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//printf("%d\n", age[i][j]);
			//printf("%d\n", *(age[i]+j));
			printf("%d\n", *(*(age + i) + j));
		}
	}
	return;
}

#endif
//=========================================================================================
// 03��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 03��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define RowSize 1
#define ColSize 2
void inputData(int**, int, int, int, int);
void printData(int**, int, int, int, int);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	int** age;
	int i, j, RSize, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	age = (int**)malloc(sizeof(char*) * RowSize);
	for (i = 0; i < RowSize; i++)
	{
		age[i] = (int*)malloc(sizeof(char) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(age, i, j, RSize, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(age, i, j, RSize, CSize);

	for (i = 0; i < RowSize; i++)
	{
		free(age[i]);
	}
	free(age);
	return 0;
}

void inputData(int** age, int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//scanf("%d", &age[i][j]);
			//scanf("%d", &(age[i][j]));
			//scanf("%d", &(*(age[i]+j)));
			//scanf("%d", (age[i] + j));
			//scanf("%d", &(*(*(age+i) + j)));
			scanf("%d", (*(age + i) + j));
		}
	}
	return;
}

void printData(int** age, int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//printf("%d\n", age[i][j]);
			//printf("%d\n", *(age[i]+j));
			printf("%d\n", *(*(age + i) + j));
		}
	}
	return;
}

#endif




//=========================================================================================
// 04��. ����
//=========================================================================================
// 04��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#include <stdio.h>
int main(void)
{
	// -------�Է�-���� ����------------------------------
	int year = 1972; //���� ����� �ʱ�ȭ�� �Ѳ����� ����(���� ����)
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("C ���� %d�⵵�� ���ߵǾ���.\n", year);

	return 0;
}
#endif

//=========================================================================================
// 04��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#include <stdio.h>
int main(void)
{
	// -------�Է�-���� ����------------------------------
	int year = 1972; //���� ����� �ʱ�ȭ�� �Ѳ����� ����(���� ����)

	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf("%d", &year);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("C ���� %d�⵵�� ���ߵǾ���.\n", year);

	return 0;
}
#endif
// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 04��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value
#if 0
#include <stdio.h>

void printData(int);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	int year;

	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf("%d", &year);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(year);


	return 0;
}

void printData(int year) {
	printf("C ���� %d�⵵�� ���ߵǾ���.\n", year);
	return;
}
#endif
// case 2. call-by-address
#if 0
#include <stdio.h>
void inputData(int*);
void printData(int*);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	int year;

	// -------�Է�-���� �ʱ�ȭ----------------------------
	inputData(&year);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(&year);


	return 0;
}
void inputData(int* year) {
	scanf("%d", *(&year));
	return;
}
void printData(int* year) {
	printf("C ���� %d�⵵�� ���ߵǾ���.\n", *year);
	return;
}
#endif
// case 3. call-by-reference
#if 0
#include <stdio.h>
void inputData(int&);
void printData(int&);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	int year;

	// -------�Է�-���� �ʱ�ȭ----------------------------
	inputData(year);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(year);


	return 0;
}
void inputData(int& year) {
	scanf("%d", &year);
	return;
}
void printData(int& year) {
	printf("C ���� %d�⵵�� ���ߵǾ���.\n", year);
	return;
}
#endif
//=========================================================================================
// 04��-03.1���� �迭
//=========================================================================================
#if 0
#include <stdio.h>
#define ColSize 2

void inputData(int[ColSize], int, int);
void printData(int[ColSize], int, int);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	int year[ColSize];
	int i, CSize;

	// -------�Է�-���� �ʱ�ȭ----------------------------
	i = 0;
	CSize = ColSize;
	inputData(year, i, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(year, i, CSize);
	return 0;
}
void inputData(int year[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%d", &year[i]);
	}
	return;
}
void printData(int year[ColSize], int i, int CSize) {
	for (i = 0; i < CSize; i++)
	{
		printf("C ���� %d�⵵�� ���ߵǾ���.\n", year[i]);
	}
	return;
}
#endif
//=========================================================================================
// 04��-04.1���� ������
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define ColSize 2

void inputData(int*, int, int);
void printData(int*, int, int);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	int* year;
	int i, CSize;

	// -------�Է�-���� �ʱ�ȭ----------------------------
	year = (int*)malloc(sizeof(int) * ColSize);
	i = 0;
	CSize = ColSize;
	inputData(year, i, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(year, i, CSize);

	free(year);
	return 0;
}
void inputData(int* year, int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%d", (year + i));
	}
	return;
}
void printData(int* year, int i, int CSize) {
	for (i = 0; i < CSize; i++)
	{
		printf("C ���� %d�⵵�� ���ߵǾ���.\n", *(year + i));
	}
	return;
}
#endif
//=========================================================================================
// 04��-05.2���� �迭
//=========================================================================================
#if 0
#include <stdio.h>
#define RowSize 1
#define ColSize 2

void inputData(int[RowSize][ColSize], int, int, int, int);
void printData(int[RowSize][ColSize], int, int, int, int);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	int year[RowSize][ColSize];
	int i, j, RSize, CSize;

	// -------�Է�-���� �ʱ�ȭ----------------------------
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(year, i, j, RSize, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(year, i, j, RSize, CSize);
	return 0;
}
void inputData(int year[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//scanf("%d", &year[i][j]); // �迭
			//scanf("%d", &(*(year[i]+j))); // ������ �迭
			//scanf("%d", (year[i]+j)); // �����͹迭
			//scanf("%d", &(*(*(year+i) + j)));  // ���� ������
			scanf("%d", (*(year + i) + j)); // ���� ������


		}
	}
	return;
}
void printData(int year[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//printf("C ���� %d�⵵�� ���ߵǾ���.\n", year[i][j]);
			//printf("C ���� %d�⵵�� ���ߵǾ���.\n", *(year[i]+j));
			printf("C ���� %d�⵵�� ���ߵǾ���.\n", *(*(year + i) + j));
		}
	}
	return;
}
#endif
//=========================================================================================
// 04��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define RowSize 1
#define ColSize 2

void inputData(int* [RowSize], int, int, int, int);
void printData(int* [RowSize], int, int, int, int);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	int* year[RowSize];
	int i, j, RSize, CSize;

	// -------�Է�-���� �ʱ�ȭ----------------------------
	for (i = 0; i < RowSize; i++)
	{
		year[i] = (int*)malloc(sizeof(char) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(year, i, j, RSize, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(year, i, j, RSize, CSize);
	for (i = 0; i < RowSize; i++)
	{
		free(year[i]);
	}
	return 0;
}
void inputData(int* year[RowSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//scanf("%d", &year[i][j]); // �迭
			//scanf("%d", &(*(year[i]+j))); // ������ �迭
			//scanf("%d", (year[i]+j)); // �����͹迭
			//scanf("%d", &(*(*(year+i) + j)));  // ���� ������
			scanf("%d", (*(year + i) + j)); // ���� ������


		}
	}
	return;
}
void printData(int* year[RowSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//printf("C ���� %d�⵵�� ���ߵǾ���.\n", year[i][j]);
			//printf("C ���� %d�⵵�� ���ߵǾ���.\n", *(year[i]+j));
			printf("C ���� %d�⵵�� ���ߵǾ���.\n", *(*(year + i) + j));
		}
	}
	return;
}
#endif
//=========================================================================================
// 04��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 04��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define RowSize 1
#define ColSize 2

void inputData(int**, int, int, int, int);
void printData(int**, int, int, int, int);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	int** year;
	int i, j, RSize, CSize;

	// -------�Է�-���� �ʱ�ȭ----------------------------
	year = (int**)malloc(sizeof(int*) * RowSize);
	for (i = 0; i < RowSize; i++)
	{
		year[i] = (int*)malloc(sizeof(char) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(year, i, j, RSize, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(year, i, j, RSize, CSize);
	for (i = 0; i < RowSize; i++)
	{
		free(year[i]);
	}
	free(year);
	return 0;
}
void inputData(int** year, int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//scanf("%d", &year[i][j]); // �迭
			//scanf("%d", &(*(year[i]+j))); // ������ �迭
			//scanf("%d", (year[i]+j)); // �����͹迭
			//scanf("%d", &(*(*(year+i) + j)));  // ���� ������
			scanf("%d", (*(year + i) + j)); // ���� ������


		}
	}
	return;
}
void printData(int** year, int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//printf("C ���� %d�⵵�� ���ߵǾ���.\n", year[i][j]);
			//printf("C ���� %d�⵵�� ���ߵǾ���.\n", *(year[i]+j));
			printf("C ���� %d�⵵�� ���ߵǾ���.\n", *(*(year + i) + j));
		}
	}
	return;
}
#endif


//=========================================================================================
// 05��. �ڷ���
//=========================================================================================
// 05��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	short sVar = 32000;							//-32767���� 32767����
	int   iVar = 2140000000;					//��  21�� �������� ���� ����
	long  gVar = -2140000000;					//�� -21�� �������� ���� ����

	unsigned short int	usVar = 65000;			//0���� 65535���� ���� ����
	unsigned int		uiVar = 2140000000;		//�� 0���� 42�� �������� ���� ����
	unsigned long int	ugVar = 4280000000;		//�� 0���� 42�� �������� ���� ����

	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("���� ��: %hd %d %ld\n", sVar, iVar, gVar);
	printf("���� ��: %hu %u %lu\n", usVar, uiVar, ugVar);

	return 0;
}
#endif

//=========================================================================================
// 05��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	short sVar;
	int   iVar;
	long  gVar;

	unsigned short int	usVar;
	unsigned int		uiVar;
	unsigned long int	ugVar;

	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf("%hd%d%ld", &sVar, &iVar, &gVar);
	scanf("%hu%u%lu", &usVar, &uiVar, &ugVar);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("���� ��: %hd %d %ld\n", sVar, iVar, gVar);
	printf("���� ��: %hu %u %lu\n", usVar, uiVar, ugVar);

	return 0;
}
#endif
// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 05��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value
#if 0
#include <stdio.h>

void printData(short, int, long, unsigned short int, unsigned int, unsigned long int);

int main(void) {
	// -------�Է�-���� ����------------------------------
	short sVar;
	int   iVar;
	long  gVar;

	unsigned short int	usVar;
	unsigned int		uiVar;
	unsigned long int	ugVar;

	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf("%hd%d%ld", &sVar, &iVar, &gVar);
	scanf("%hu%u%lu", &usVar, &uiVar, &ugVar);

	// -------ó��----------------------------------------
	// -------���----------------------------------------

	printData(sVar, iVar, gVar, usVar, uiVar, ugVar);


	return 0;
}

void printData(short sVar, int  iVar, long gVar, unsigned short int usVar, unsigned int uiVar, unsigned long int ugVar) {
	printf("���� ��: %hd %d %ld\n", sVar, iVar, gVar);
	printf("���� ��: %hu %u %lu\n", usVar, uiVar, ugVar);
	return;
}
#endif
// case 2. call-by-address
#if 0
#include <stdio.h>
void inputData(short*, int*, long*, unsigned short int*, unsigned int*, unsigned long int*);
void printData(short*, int*, long*, unsigned short int*, unsigned int*, unsigned long int*);

int main(void) {
	// -------�Է�-���� ����------------------------------
	short sVar;
	int   iVar;
	long  gVar;

	unsigned short int	usVar;
	unsigned int		uiVar;
	unsigned long int	ugVar;

	// -------�Է�-���� �ʱ�ȭ----------------------------

	inputData(&sVar, &iVar, &gVar, &usVar, &uiVar, &ugVar);

	// -------ó��----------------------------------------
	// -------���----------------------------------------

	printData(&sVar, &iVar, &gVar, &usVar, &uiVar, &ugVar);

	return 0;
}

void inputData(short* sVar, int* iVar, long* gVar, unsigned short int* usVar, unsigned int* uiVar, unsigned long int* ugVar)
{
	scanf("%hd%d%ld", *(&sVar), *(&iVar), *(&gVar));
	scanf("%hu%u%lu", *(&usVar), *(&uiVar), *(&ugVar));
	return;
}

void printData(short* sVar, int* iVar, long* gVar, unsigned short int* usVar, unsigned int* uiVar, unsigned long int* ugVar)
{
	printf("���� ��: %hd %d %ld\n", *sVar, *iVar, *gVar);
	printf("���� ��: %hu %u %lu\n", *usVar, *uiVar, *ugVar);
	return;
}
#endif
// case 3. call-by-reference
#if 0
#include <stdio.h>
void inputData(short&, int&, long&, unsigned short int&, unsigned int&, unsigned long int&);
void printData(short&, int&, long&, unsigned short int&, unsigned int&, unsigned long int&);

int main(void) {
	// -------�Է�-���� ����------------------------------
	short sVar;
	int   iVar;
	long  gVar;

	unsigned short int	usVar;
	unsigned int		uiVar;
	unsigned long int	ugVar;

	// -------�Է�-���� �ʱ�ȭ----------------------------

	inputData(sVar, iVar, gVar, usVar, uiVar, ugVar);

	// -------ó��----------------------------------------
	// -------���----------------------------------------

	printData(sVar, iVar, gVar, usVar, uiVar, ugVar);

	return 0;
}

void inputData(short& sVar, int& iVar, long& gVar, unsigned short int& usVar, unsigned int& uiVar, unsigned long int& ugVar)
{
	scanf("%hd%d%ld", &sVar, &iVar, &gVar);
	scanf("%hu%u%lu", &usVar, &uiVar, &ugVar);
	return;
}

void printData(short& sVar, int& iVar, long& gVar, unsigned short int& usVar, unsigned int& uiVar, unsigned long int& ugVar)
{
	printf("���� ��: %hd %d %ld\n", sVar, iVar, gVar);
	printf("���� ��: %hu %u %lu\n", usVar, uiVar, ugVar);
	return;
}
#endif
//=========================================================================================
// 05��-03.1���� �迭
//=========================================================================================
#if 0
#include <stdio.h>
#define ColSize 1

void inputData(short[ColSize], int[ColSize], long[ColSize], unsigned short int[ColSize], unsigned int[ColSize], unsigned long int[ColSize], int, int);
void printData(short[ColSize], int[ColSize], long[ColSize], unsigned short int[ColSize], unsigned int[ColSize], unsigned long int[ColSize], int, int);

int main(void) {
	// -------�Է�-���� ����------------------------------
	short sVar[ColSize];
	int   iVar[ColSize];
	long  gVar[ColSize];

	unsigned short int	usVar[ColSize];
	unsigned int		uiVar[ColSize];
	unsigned long int	ugVar[ColSize];

	int i, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	i = 0;
	CSize = ColSize;

	inputData(sVar, iVar, gVar, usVar, uiVar, ugVar, i, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------

	printData(sVar, iVar, gVar, usVar, uiVar, ugVar, i, CSize);

	return 0;
}

void inputData(short sVar[ColSize], int iVar[ColSize], long gVar[ColSize], unsigned short int usVar[ColSize], unsigned int uiVar[ColSize], unsigned long int ugVar[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%hd%d%ld", &sVar[i], &iVar[i], &gVar[i]);
		scanf("%hu%u%lu", &usVar[i], &uiVar[i], &ugVar[i]);
	}
	return;
}

void printData(short sVar[ColSize], int iVar[ColSize], long gVar[ColSize], unsigned short int usVar[ColSize], unsigned int uiVar[ColSize], unsigned long int ugVar[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("���� ��: %hd %d %ld\n", sVar[i], iVar[i], gVar[i]);
		printf("���� ��: %hu %u %lu\n", usVar[i], uiVar[i], ugVar[i]);
	}
	return;
}
#endif
//=========================================================================================
// 05��-04.1���� ������
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define ColSize 1

void inputData(short*, int*, long*, unsigned short int*, unsigned int*,
	unsigned long int*, int, int);
void printData(short*, int*, long*, unsigned short int*,
	unsigned int*, unsigned long int*, int, int);

int main(void) {
	// -------�Է�-���� ����------------------------------
	short* sVar;
	int* iVar;
	long* gVar;

	unsigned short int* usVar;
	unsigned int* uiVar;
	unsigned long int* ugVar;

	int i, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	sVar = (short*)malloc(sizeof(short) * ColSize);
	iVar = (int*)malloc(sizeof(int) * ColSize);
	gVar = (long*)malloc(sizeof(long) * ColSize);
	usVar = (unsigned short int*)malloc(sizeof(unsigned short int) * ColSize);
	uiVar = (unsigned int*)malloc(sizeof(unsigned int) * ColSize);
	ugVar = (unsigned long int*)malloc(sizeof(unsigned long int) * ColSize);

	i = 0;
	CSize = ColSize;

	inputData(sVar, iVar, gVar, usVar, uiVar, ugVar, i, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------

	printData(sVar, iVar, gVar, usVar, uiVar, ugVar, i, CSize);
	free(sVar);
	free(iVar);
	free(gVar);
	free(usVar);
	free(uiVar);
	free(ugVar);
	return 0;
}

void inputData(short* sVar, int* iVar, long* gVar, unsigned short int* usVar,
	unsigned int* uiVar, unsigned long int* ugVar, int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%hd%d%ld", (sVar + i), (iVar + i), (gVar + i));
		scanf("%hu%u%lu", (usVar + i), (uiVar + i), (ugVar + i));
	}
	return;
}

void printData(short* sVar, int* iVar, long* gVar, unsigned short int* usVar,
	unsigned int* uiVar, unsigned long int* ugVar, int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("���� ��: %hd %d %ld\n", *(sVar + i), *(iVar + i), *(gVar + i));
		printf("���� ��: %hu %u %lu\n", *(usVar + i), *(uiVar + i), *(ugVar + i));
	}
	return;
}
#endif
//=========================================================================================
// 05��-05.2���� �迭
//=========================================================================================
#if 0
#include <stdio.h>
#define RowSize 1
#define ColSize 1

void inputData(short[RowSize][ColSize], int[RowSize][ColSize], long[RowSize][ColSize],
	unsigned short int[RowSize][ColSize], unsigned int[RowSize][ColSize],
	unsigned long int[RowSize][ColSize], int, int, int, int);
void printData(short sVar[RowSize][ColSize], int iVar[RowSize][ColSize], long gVar[RowSize][ColSize],
	unsigned short int usVar[RowSize][ColSize], unsigned int uiVar[RowSize][ColSize],
	unsigned long int ugVar[RowSize][ColSize], int i, int j, int RSize, int CSize);

int main(void) {
	// -------�Է�-���� ����------------------------------
	short sVar[RowSize][ColSize];
	int   iVar[RowSize][ColSize];
	long  gVar[RowSize][ColSize];

	unsigned short int	usVar[RowSize][ColSize];
	unsigned int		uiVar[RowSize][ColSize];
	unsigned long int	ugVar[RowSize][ColSize];

	int i, j, RSize, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	i = 0;
	RSize = RowSize;
	CSize = ColSize;

	inputData(sVar, iVar, gVar, usVar, uiVar, ugVar, i, j, RSize, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------

	printData(sVar, iVar, gVar, usVar, uiVar, ugVar, i, j, RSize, CSize);

	return 0;
}

void inputData(short sVar[RowSize][ColSize], int iVar[RowSize][ColSize], long gVar[RowSize][ColSize],
	unsigned short int usVar[RowSize][ColSize], unsigned int uiVar[RowSize][ColSize],
	unsigned long int ugVar[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			/*scanf("%hd%d%ld", &sVar[i][j], &iVar[i][j], &gVar[i][j]);
			scanf("%hu%u%lu", &usVar[i][j], &uiVar[i][j], &ugVar[i][j]);*//*
			scanf("%hd%d%ld", &(*(sVar[i]+j)), &(*(iVar[i]+j)), &(*(gVar[i]+j)));
			scanf("%hu%u%lu", &(*(usVar[i]+j)), &(*(uiVar[i]+j)), &(*(ugVar[i]+j)));*/
			/*scanf("%hd%d%ld", (sVar[i] + j), (iVar[i] + j), (gVar[i] + j));
			scanf("%hu%u%lu", (usVar[i] + j), (uiVar[i] + j), (ugVar[i] + j));*/

			scanf("%hd%d%ld", (*(sVar + i) + j), (*(iVar + i) + j), (*(gVar + i) + j));
			scanf("%hu%u%lu", (*(usVar + i) + j), (*(uiVar + i) + j), (*(ugVar + i) + j));
		}

	}
	return;
}

void printData(short sVar[RowSize][ColSize], int iVar[RowSize][ColSize], long gVar[RowSize][ColSize],
	unsigned short int usVar[RowSize][ColSize], unsigned int uiVar[RowSize][ColSize],
	unsigned long int ugVar[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//printf("���� ��: %hd %d %ld\n", sVar[i][j], iVar[i][j], gVar[i][j]);
			//printf("���� ��: %hu %u %lu\n", usVar[i][j], uiVar[i][j], ugVar[i][j]);
			/*printf("���� ��: %hd %d %ld\n", *(sVar[i]+j), *(iVar[i]+j), *(gVar[i]+j));
			printf("���� ��: %hu %u %lu\n", *(usVar[i]+j), *(uiVar[i]+j), *(ugVar[i]+j));*/
			printf("���� ��: %hd %d %ld\n", *(*(sVar + i) + j), *(*(iVar + i) + j), *(*(gVar + i) + j));
			printf("���� ��: %hu %u %lu\n", *(*(usVar + i) + j), *(*(uiVar + i) + j), *(*(ugVar + i) + j));
		}
	}
	return;
}
#endif
//=========================================================================================
// 05��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define RowSize 1
#define ColSize 1

void inputData(short* [RowSize], int* [RowSize], long* [RowSize],
	unsigned short int* [RowSize], unsigned int* [RowSize],
	unsigned long int* [RowSize], int, int, int, int);
void printData(short* sVar[RowSize], int* iVar[RowSize], long* gVar[RowSize],
	unsigned short int* usVar[RowSize], unsigned int* uiVar[RowSize],
	unsigned long int* ugVar[RowSize], int i, int j, int RSize, int CSize);

int main(void) {
	// -------�Է�-���� ����------------------------------
	short* sVar[RowSize];
	int* iVar[RowSize];
	long* gVar[RowSize];

	unsigned short int* usVar[RowSize];
	unsigned int* uiVar[RowSize];
	unsigned long int* ugVar[RowSize];

	int i, j, RSize, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	for (i = 0; i < RowSize; i++)
	{
		sVar[i] = (short*)malloc(sizeof(short) * ColSize);
		iVar[i] = (int*)malloc(sizeof(int) * ColSize);
		gVar[i] = (long*)malloc(sizeof(long) * ColSize);
		usVar[i] = (unsigned short int*)malloc(sizeof(unsigned short int) * ColSize);
		uiVar[i] = (unsigned int*)malloc(sizeof(unsigned int) * ColSize);
		ugVar[i] = (unsigned long int*)malloc(sizeof(unsigned long int) * ColSize);
	}
	i = 0;
	RSize = RowSize;
	CSize = ColSize;

	inputData(sVar, iVar, gVar, usVar, uiVar, ugVar, i, j, RSize, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------

	printData(sVar, iVar, gVar, usVar, uiVar, ugVar, i, j, RSize, CSize);
	for (i = 0; i < RowSize; i++)
	{
		free(sVar[i]);
		free(iVar[i]);
		free(gVar[i]);
		free(usVar[i]);
		free(uiVar[i]);
		free(ugVar[i]);
	}
	return 0;
}

void inputData(short* sVar[RowSize], int* iVar[RowSize], long* gVar[RowSize],
	unsigned short int* usVar[RowSize], unsigned int* uiVar[RowSize],
	unsigned long int* ugVar[RowSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			/*scanf("%hd%d%ld", &sVar[i][j], &iVar[i][j], &gVar[i][j]);
			scanf("%hu%u%lu", &usVar[i][j], &uiVar[i][j], &ugVar[i][j]);*//*
			scanf("%hd%d%ld", &(*(sVar[i]+j)), &(*(iVar[i]+j)), &(*(gVar[i]+j)));
			scanf("%hu%u%lu", &(*(usVar[i]+j)), &(*(uiVar[i]+j)), &(*(ugVar[i]+j)));*/
			/*scanf("%hd%d%ld", (sVar[i] + j), (iVar[i] + j), (gVar[i] + j));
			scanf("%hu%u%lu", (usVar[i] + j), (uiVar[i] + j), (ugVar[i] + j));*/

			scanf("%hd%d%ld", (*(sVar + i) + j), (*(iVar + i) + j), (*(gVar + i) + j));
			scanf("%hu%u%lu", (*(usVar + i) + j), (*(uiVar + i) + j), (*(ugVar + i) + j));
		}

	}
	return;
}

void printData(short* sVar[RowSize], int* iVar[RowSize], long* gVar[RowSize],
	unsigned short int* usVar[RowSize], unsigned int* uiVar[RowSize],
	unsigned long int* ugVar[RowSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//printf("���� ��: %hd %d %ld\n", sVar[i][j], iVar[i][j], gVar[i][j]);
			//printf("���� ��: %hu %u %lu\n", usVar[i][j], uiVar[i][j], ugVar[i][j]);
			/*printf("���� ��: %hd %d %ld\n", *(sVar[i]+j), *(iVar[i]+j), *(gVar[i]+j));
			printf("���� ��: %hu %u %lu\n", *(usVar[i]+j), *(uiVar[i]+j), *(ugVar[i]+j));*/
			printf("���� ��: %hd %d %ld\n", *(*(sVar + i) + j), *(*(iVar + i) + j), *(*(gVar + i) + j));
			printf("���� ��: %hu %u %lu\n", *(*(usVar + i) + j), *(*(uiVar + i) + j), *(*(ugVar + i) + j));
		}
	}
	return;
}
#endif
//=========================================================================================
// 05��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 05��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define RowSize 1
#define ColSize 1

void inputData(short**, int**, long**,
	unsigned short int**, unsigned int**,
	unsigned long int**, int, int, int, int);
void printData(short**, int**, long**,
	unsigned short int**, unsigned int**,
	unsigned long int**, int i, int j, int RSize, int CSize);

int main(void) {
	// -------�Է�-���� ����------------------------------
	short** sVar;
	int** iVar;
	long** gVar;

	unsigned short int** usVar;
	unsigned int** uiVar;
	unsigned long int** ugVar;

	int i, j, RSize, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	sVar = (short**)malloc(sizeof(short*) * RowSize);
	iVar = (int**)malloc(sizeof(int*) * RowSize);
	gVar = (long**)malloc(sizeof(long*) * RowSize);
	usVar = (unsigned short int**)malloc(sizeof(unsigned short int*) * RowSize);
	uiVar = (unsigned int**)malloc(sizeof(unsigned int*) * RowSize);
	ugVar = (unsigned long int**)malloc(sizeof(unsigned long int*) * RowSize);
	for (i = 0; i < RowSize; i++)
	{
		sVar[i] = (short*)malloc(sizeof(short) * ColSize);
		iVar[i] = (int*)malloc(sizeof(int) * ColSize);
		gVar[i] = (long*)malloc(sizeof(long) * ColSize);
		usVar[i] = (unsigned short int*)malloc(sizeof(unsigned short int) * ColSize);
		uiVar[i] = (unsigned int*)malloc(sizeof(unsigned int) * ColSize);
		ugVar[i] = (unsigned long int*)malloc(sizeof(unsigned long int) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	inputData(sVar, iVar, gVar, usVar, uiVar, ugVar, i, j, RSize, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------

	printData(sVar, iVar, gVar, usVar, uiVar, ugVar, i, j, RSize, CSize);
	for (i = 0; i < RowSize; i++)
	{
		free(sVar[i]);
		free(iVar[i]);
		free(gVar[i]);
		free(usVar[i]);
		free(uiVar[i]);
		free(ugVar[i]);
	}
	free(sVar);
	free(iVar);
	free(gVar);
	free(usVar);
	free(uiVar);
	free(ugVar);
	return 0;
}

void inputData(short** sVar, int** iVar, long** gVar,
	unsigned short int** usVar, unsigned int** uiVar,
	unsigned long int** ugVar, int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			/*scanf("%hd%d%ld", &sVar[i][j], &iVar[i][j], &gVar[i][j]);
			scanf("%hu%u%lu", &usVar[i][j], &uiVar[i][j], &ugVar[i][j]);*//*
			scanf("%hd%d%ld", &(*(sVar[i]+j)), &(*(iVar[i]+j)), &(*(gVar[i]+j)));
			scanf("%hu%u%lu", &(*(usVar[i]+j)), &(*(uiVar[i]+j)), &(*(ugVar[i]+j)));*/
			/*scanf("%hd%d%ld", (sVar[i] + j), (iVar[i] + j), (gVar[i] + j));
			scanf("%hu%u%lu", (usVar[i] + j), (uiVar[i] + j), (ugVar[i] + j));*/

			scanf("%hd%d%ld", (*(sVar + i) + j), (*(iVar + i) + j), (*(gVar + i) + j));
			scanf("%hu%u%lu", (*(usVar + i) + j), (*(uiVar + i) + j), (*(ugVar + i) + j));
		}

	}
	return;
}

void printData(short** sVar, int** iVar, long** gVar,
	unsigned short int** usVar, unsigned int** uiVar,
	unsigned long int** ugVar, int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//printf("���� ��: %hd %d %ld\n", sVar[i][j], iVar[i][j], gVar[i][j]);
			//printf("���� ��: %hu %u %lu\n", usVar[i][j], uiVar[i][j], ugVar[i][j]);
			/*printf("���� ��: %hd %d %ld\n", *(sVar[i]+j), *(iVar[i]+j), *(gVar[i]+j));
			printf("���� ��: %hu %u %lu\n", *(usVar[i]+j), *(uiVar[i]+j), *(ugVar[i]+j));*/
			printf("���� ��: %hd %d %ld\n", *(*(sVar + i) + j), *(*(iVar + i) + j), *(*(gVar + i) + j));
			printf("���� ��: %hu %u %lu\n", *(*(usVar + i) + j), *(*(uiVar + i) + j), *(*(ugVar + i) + j));
		}
	}
	return;
}
#endif










//=========================================================================================
// 06��. �ڷ���
//=========================================================================================
// 06��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	float 		x = 3.14;		//float x = 3.14;�ΰ��, ��� �߻�
	double		y = -3.14;	//double ������� ũ��� float�� 2��	
	long double	z = 3.14;	//double�� long double�� ��������� ��� 64��Ʈ	
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("���� ��: %f %lf %lf\n", x, y, z);

	return 0;
}
#endif

//=========================================================================================
// 06��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	float 		x;
	double		y;
	long double	z;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf("%f%lf%lf", &x, &y, &z);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("���� ��: %f %lf %lf\n", x, y, z);

	return 0;
}
#endif
// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 06��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value
#if 0
#include <stdio.h>
void printData(float, double, long double);

int main(void) {
	// -------�Է�-���� ����------------------------------
	float 		x;
	double		y;
	long double	z;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf("%f%lf%lf", &x, &y, &z);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, y, z);


	return 0;
}

void printData(float x, double y, long double z)
{
	printf("���� ��: %f %lf %lf\n", x, y, z);
	return;
}

#endif
// case 2. call-by-address

#if 0
#include <stdio.h>

void inputData(float*, double*, long double*);
void printData(float*, double*, long double*);

int main(void) {
	// -------�Է�-���� ����------------------------------
	float 		x;
	double		y;
	long double	z;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	inputData(&x, &y, &z);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(&x, &y, &z);


	return 0;
}
void inputData(float* x, double* y, long double* z)
{
	scanf("%f%lf%lf", *(&x), *(&y), *(&z));
	return;
}

void printData(float* x, double* y, long double* z)
{
	printf("���� ��: %f %lf %lf\n", *x, *y, *z);
	return;
}

#endif

// case 3. call-by-reference
#if 0
#include <stdio.h>

void inputData(float&, double&, long double&);
void printData(float&, double&, long double&);

int main(void) {
	// -------�Է�-���� ����------------------------------
	float 		x;
	double		y;
	long double	z;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	inputData(x, y, z);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, y, z);


	return 0;
}
void inputData(float& x, double& y, long double& z)
{
	scanf("%f%lf%lf", &x, &y, &z);
	return;
}

void printData(float& x, double& y, long double& z)
{
	printf("���� ��: %f %lf %lf\n", x, y, z);
	return;
}

#endif

//=========================================================================================
// 06��-03.1���� �迭
//=========================================================================================
#if 0
#include <stdio.h>
#define ColSize 1

void inputData(float[ColSize], double[ColSize], long double[ColSize], int, int);
void printData(float[ColSize], double[ColSize], long double[ColSize], int, int);

int main(void) {
	// -------�Է�-���� ����------------------------------
	float 		x[ColSize];
	double		y[ColSize];
	long double	z[ColSize];
	int i, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	i = 0;
	CSize = ColSize;
	inputData(x, y, z, i, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, y, z, i, CSize);


	return 0;
}
void inputData(float x[ColSize], double y[ColSize], long double z[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%f%lf%lf", &x[i], &y[i], &z[i]);
	}
	return;
}

void printData(float x[ColSize], double y[ColSize], long double z[ColSize], int i, int CSize)
{

	for (i = 0; i < CSize; i++)
	{
		printf("���� ��: %f %lf %lf\n", x[i], y[i], z[i]);
	}
	return;
}
#endif

//=========================================================================================
// 06��-04.1���� ������
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define ColSize 1

void inputData(float*, double*, long double*, int, int);
void printData(float*, double*, long double*, int, int);

int main(void) {
	// -------�Է�-���� ����------------------------------
	float* x;
	double* y;
	long double* z;
	int i, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	x = (float*)malloc(sizeof(float) * ColSize);
	y = (double*)malloc(sizeof(double) * ColSize);
	z = (long double*)malloc(sizeof(long double) * ColSize);
	i = 0;
	CSize = ColSize;
	inputData(x, y, z, i, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, y, z, i, CSize);

	free(x);
	free(y);
	free(z);

	return 0;
}
void inputData(float* x, double* y, long double* z, int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%f%lf%lf", (x + i), (y + i), (z + i));
	}
	return;
}

void printData(float* x, double* y, long double* z, int i, int CSize)
{

	for (i = 0; i < CSize; i++)
	{
		printf("���� ��: %f %lf %lf\n", *(x + i), *(y + i), *(z + i));
	}
	return;
}
#endif
//=========================================================================================
// 06��-05.2���� �迭
//=========================================================================================
#if 0
#include <stdio.h>
#define RowSize 1
#define ColSize 2


void inputData(float[RowSize][ColSize], double[RowSize][ColSize], long double[RowSize][ColSize], int, int, int, int);
void printData(float[RowSize][ColSize], double[RowSize][ColSize], long double[RowSize][ColSize], int, int, int, int);

int main(void) {
	// -------�Է�-���� ����------------------------------
	float 		x[RowSize][ColSize];
	double		y[RowSize][ColSize];
	long double	z[RowSize][ColSize];
	int i, j, RSize, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(x, y, z, i, j, RSize, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, y, z, i, j, RSize, CSize);


	return 0;
}
void inputData(float x[RowSize][ColSize], double y[RowSize][ColSize], long double z[RowSize][ColSize], int i, int j, int RSize, int CSize)
{

	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%f%lf%lf", &x[i][j], &y[i][j], &z[i][j]);
		}
	}
	return;
}

void printData(float x[RowSize][ColSize], double y[RowSize][ColSize], long double z[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("���� ��: %f %lf %lf\n", x[i][j], y[i][j], z[i][j]);
		}
	}

	return;
}
#endif

//=========================================================================================
// 06��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define RowSize 1
#define ColSize 2


void inputData(float* [RowSize], double* [RowSize], long double* [RowSize], int, int, int, int);
void printData(float* [RowSize], double* [RowSize], long double* [RowSize], int, int, int, int);

int main(void) {
	// -------�Է�-���� ����------------------------------

	float* x[RowSize];
	double* y[RowSize];
	long double* z[RowSize];
	int i, j, RSize, CSize;

	// -------�Է�-���� �ʱ�ȭ----------------------------
	for (i = 0; i < RowSize; i++)
	{
		x[i] = (float*)malloc(sizeof(float) * ColSize);
		y[i] = (double*)malloc(sizeof(double) * ColSize);
		z[i] = (long double*)malloc(sizeof(long double) * ColSize);

	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(x, y, z, i, j, RSize, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, y, z, i, j, RSize, CSize);

	for (i = 0; i < RowSize; i++)
	{
		free(x[i]);
		free(y[i]);
		free(z[i]);
	}

	return 0;
}
void inputData(float* x[RowSize], double* y[RowSize], long double* z[RowSize], int i, int j, int RSize, int CSize)
{

	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%f%lf%lf", &x[i][j], &y[i][j], &z[i][j]);
		}
	}
	return;
}

void printData(float* x[RowSize], double* y[RowSize], long double* z[RowSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("���� ��: %f %lf %lf\n", x[i][j], y[i][j], z[i][j]);
		}
	}

	return;
}
#endif

//=========================================================================================
// 06��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 06��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define RowSize 1
#define ColSize 2


void printData(float**, double**, long double**, int, int, int, int);
void inputData(float**, double**, long double**, int, int, int, int);

int main(void) {
	// -------�Է�-���� ����------------------------------

	float** x;
	double** y;
	long double** z;
	int i, j, RSize, CSize;

	x = (float**)malloc(sizeof(float*) * RowSize);
	y = (double**)malloc(sizeof(double*) * RowSize);
	z = (long double**)malloc(sizeof(long double*) * RowSize);

	// -------�Է�-���� �ʱ�ȭ----------------------------
	for (i = 0; i < RowSize; i++)
	{
		x[i] = (float*)malloc(sizeof(float) * ColSize);
		y[i] = (double*)malloc(sizeof(double) * ColSize);
		z[i] = (long double*)malloc(sizeof(long double) * ColSize);

	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(x, y, z, i, j, RSize, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, y, z, i, j, RSize, CSize);

	for (i = 0; i < RowSize; i++)
	{
		free(x[i]);
		free(y[i]);
		free(z[i]);
	}
	free(x);
	free(y);
	free(z);

	return 0;
}
void inputData(float** x, double** y, long double** z, int i, int j, int RSize, int CSize)
{

	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//scanf("%f%lf%lf", &x[i][j], &y[i][j], &z[i][j]);
			//scanf("%f%lf%lf", &(x[i][j]), &(y[i][j]), &(z[i][j]));
			//scanf("%f%lf%lf", &(*(x[i]+j)), &(*(y[i]+j)), &(*(z[i]+j)));
			//scanf("%f%lf%lf", (x[i] + j), (y[i] + j), (z[i] + j));
			scanf("%f%lf%lf", (*(x + i) + j), (*(y + i) + j), (*(z + i) + j));
		}
	}
	return;
}

void printData(float** x, double** y, long double** z, int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//printf("���� ��: %f %lf %lf\n", x[i][j], y[i][j], z[i][j]);
			//printf("���� ��: %f %lf %lf\n", *(x[i]+j), *(y[i]+j), *(z[i]+j));
			printf("���� ��: %f %lf %lf\n", *(*(x + i) + j), *(*(y + i) + j), *(*(z + i) + j));
		}
	}

	return;
}
#endif








//=========================================================================================
// 07��. �ڷ���
//=========================================================================================
// 07��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	char c1 = 'a';		//�ҹ��� a
	char c2 = 65;		//�빮�� A�� �ڵ� �� 65
	char c3 = '\132';	//�빮�� Z�� 8���� �ڵ� �� 132 //scanf�� �Է¹������� '\132'�� �Է��ϸ� �ȵ�
	// scanf ��ȯ �ÿ����� �ƹ� ���ڳ� �Է��ϸ� ��
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("���� ��(����): %c %c %c\n", c1, c2, c3);
	printf("���� ��(����): %d %d %d\n", c1, c2, c3);

	return 0;
}
#endif

//=========================================================================================
// 07��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#include <stdio.h> 
int main(void) {
	// -------�Է�-���� ����------------------------------
	char c1, c2, c3;
	// scanf ��ȯ �ÿ����� �ƹ� ���ڳ� �Է��ϸ� ��
	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf(" %c %c %c", &c1, &c2, &c3);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("���� ��(����): %c %c %c\n", c1, c2, c3);
	printf("���� ��(����): %d %d %d\n", c1, c2, c3);

	return 0;
}
#endif
// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 07��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

void printData(char, char, char);

int main(void) {
	// -------�Է�-���� ����------------------------------
	char c1, c2, c3;
	// scanf ��ȯ �ÿ����� �ƹ� ���ڳ� �Է��ϸ� ��
	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf(" %c %c %c", &c1, &c2, &c3);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(c1, c2, c3);

	return 0;
}


void printData(char c1, char c2, char c3)
{
	printf("���� ��(����): %c %c %c\n", c1, c2, c3);
	printf("���� ��(����): %d %d %d\n", c1, c2, c3);
	return;
}
#endif
// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 07��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 07��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 07��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 07��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 07��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 07��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================










//=========================================================================================
// 08��. �ڷ���-define
//=========================================================================================
// 08��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#include <stdio.h>
#define	KPOP 50000000			//���� ��ũ�� ���
#define	PHI 3.14				//�Ǽ� ��ũ�� ���
#define	PRT printf("����\n")	//���ڿ� ��ũ�� ���
int main(void)
{
	// -------�Է�-���� ����------------------------------
	double radius = 2.83;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("�ѱ��α�: %d��\n", KPOP);
	printf("�� ����: %f\n", radius * radius * PHI);
	PRT;

	return 0;
}
#endif

//=========================================================================================
// 08��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#include <stdio.h>
#define	KPOP 50000000			//���� ��ũ�� ���
#define	PHI 3.14				//�Ǽ� ��ũ�� ���
#define	PRT printf("����\n")	//���ڿ� ��ũ�� ���
int main(void)
{
	// -------�Է�-���� ����------------------------------
	double radius;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf(" %lf", &radius);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("�ѱ��α�: %d��\n", KPOP);
	printf("�� ����: %f\n", radius * radius * PHI);
	PRT;

	return 0;
}
#endif

// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 08��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value
#if 0
#include <stdio.h>
#define	KPOP 50000000			//���� ��ũ�� ���
#define	PHI 3.14				//�Ǽ� ��ũ�� ���
#define	PRT printf("����\n")	//���ڿ� ��ũ�� ���

void printData(double);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	double radius;
	// -------�Է�-���� �ʱ�ȭ----------------------------

	scanf(" %lf", &radius);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(radius);

	return 0;
}

void printData(double radius)
{
	printf("�ѱ��α�: %d��\n", KPOP);
	printf("�� ����: %f\n", radius * radius * PHI);
	PRT;
}
#endif
// case 2. call-by-address

#if 0
#include <stdio.h>
#define	KPOP 50000000			//���� ��ũ�� ���
#define	PHI 3.14				//�Ǽ� ��ũ�� ���
#define	PRT printf("����\n")	//���ڿ� ��ũ�� ���

void inputData(double*);
void printData(double*);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	double radius;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	inputData(&radius);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(&radius);

	return 0;
}
void inputData(double* radius) {

	scanf(" %lf", radius);
}
void printData(double* radius)
{
	printf("�ѱ��α�: %d��\n", KPOP);
	printf("�� ����: %f\n", (*radius) * (*radius) * PHI);
	PRT;
}
#endif
// case 3. call-by-reference
#if 0
#include <stdio.h>
#define	KPOP 50000000			//���� ��ũ�� ���
#define	PHI 3.14				//�Ǽ� ��ũ�� ���
#define	PRT printf("����\n")	//���ڿ� ��ũ�� ���

void inputData(double&);
void printData(double&);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	double radius;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	inputData(radius);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(radius);

	return 0;
}
void inputData(double& radius) {

	scanf(" %lf", &radius);
}
void printData(double& radius)
{
	printf("�ѱ��α�: %d��\n", KPOP);
	printf("�� ����: %f\n", radius * radius * PHI);
	PRT;
}
#endif
//=========================================================================================
// 08��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 08��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 08��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 08��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 08��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 08��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 09��. �ڷ���-escape
//=========================================================================================
// 09��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	char sq = '\'';
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("BCPL\tB\tC\tJava\n");
	printf("%c\7\n", '\a');
	printf("%c�ڹپ��'\n", sq);
	printf("\"C���\" ���� ����ִ�!\n");
	return 0;
}
#endif

//=========================================================================================
// 09��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	char sq;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf("%c", &sq);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("BCPL\tB\tC\tJava\n");
	printf("%c\7\n", '\a');
	printf("%c�ڹپ��'\n", sq);
	printf("\"C���\" ���� ����ִ�!\n");
	return 0;
}
#endif
// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 09��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value
#if 0
#include <stdio.h>
void printData(char);
int main(void) {
	// -------�Է�-���� ����------------------------------
	char sq;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf("%c", &sq);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(sq);

	return 0;
}

void printData(char sq) {

	printf("BCPL\tB\tC\tJava\n");
	printf("%c\7\n", '\a');
	printf("%c�ڹپ��'\n", sq);
	printf("\"C���\" ���� ����ִ�!\n");
	return;

}

#endif
// case 2. call-by-address
#if 0
#include <stdio.h>
void inputData(char*);
void printData(char*);
int main(void) {
	// -------�Է�-���� ����------------------------------
	char sq;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	inputData(&sq);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(&sq);

	return 0;
}

void inputData(char* sq)
{
	scanf("%c", sq);
	return;
}

void printData(char* sq) {

	printf("BCPL\tB\tC\tJava\n");
	printf("%c\7\n", '\a');
	printf("%c�ڹپ��'\n", *sq);
	printf("\"C���\" ���� ����ִ�!\n");
	return;

}

#endif

// case 3. call-by-reference
#if 0
#include <stdio.h>
void printData(char&);
int main(void) {
	// -------�Է�-���� ����------------------------------
	char sq;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf("%c", &sq);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(sq);

	return 0;
}

void printData(char& sq) {

	printf("BCPL\tB\tC\tJava\n");
	printf("%c\7\n", '\a');
	printf("%c�ڹپ��'\n", sq);
	printf("\"C���\" ���� ����ִ�!\n");
	return;

}

#endif
//=========================================================================================
// 09��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 09��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 09��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 09��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 09��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 09��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 10��. �ڷ���-������� ����
//=========================================================================================
// 10��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#include <stdio.h>
int main(void)
{
	// -------�Է�-���� ����------------------------------
	int		n = 255;
	float	f = 3.141592F;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("%d\n", n);
	printf("%10d\n", n);
	printf("%+10d\n", n);
	printf("%-10d\n", n);
	printf("%f\n", f);
	printf("%10f\n", f);
	printf("%10.4f\n", f);
	printf("%+10.4f\n", f);
	printf("%-10.4f\n", f);

	return 0;
}
#endif

//=========================================================================================
// 10��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#include <stdio.h>
int main(void)
{
	// -------�Է�-���� ����------------------------------
	int	n;
	float f;
	// -------�Է�-���� �ʱ�ȭ----------------------------

	scanf("%d%f", &n, &f);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("%d\n", n);
	printf("%10d\n", n);
	printf("%+10d\n", n);
	printf("%-10d\n", n);
	printf("%f\n", f);
	printf("%10f\n", f);
	printf("%10.4f\n", f);
	printf("%+10.4f\n", f);
	printf("%-10.4f\n", f);

	return 0;
}
#endif
// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 10��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value
#if 0
#include <stdio.h>

void printData(int, float);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	int	n;
	float f;
	// -------�Է�-���� �ʱ�ȭ----------------------------

	scanf("%d%f", &n, &f);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(n, f);
	return 0;
}

void printData(int n, float f)
{
	printf("%d\n", n);
	printf("%10d\n", n);
	printf("%+10d\n", n);
	printf("%-10d\n", n);
	printf("%f\n", f);
	printf("%10f\n", f);
	printf("%10.4f\n", f);
	printf("%+10.4f\n", f);
	printf("%-10.4f\n", f);


}
#endif
// case 2. call-by-address
#if 0
#include <stdio.h>
void inputData(int*, float*);
void printData(int*, float*);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	int	n;
	float f;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	inputData(&n, &f);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(&n, &f);
	return 0;
}

void inputData(int* n, float* f)
{
	scanf("%d%f", *(&n), *(&f));
}
void printData(int* n, float* f)
{
	printf("%d\n", *n);
	printf("%10d\n", *n);
	printf("%+10d\n", *n);
	printf("%-10d\n", *n);
	printf("%f\n", *f);
	printf("%10f\n", *f);
	printf("%10.4f\n", *f);
	printf("%+10.4f\n", *f);
	printf("%-10.4f\n", *f);


}
#endif
// case 3. call-by-reference
#if 0
#include <stdio.h>
void inputData(int&, float&);
void printData(int&, float&);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	int	n;
	float f;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	inputData(n, f);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(n, f);
	return 0;
}
void inputData(int& n, float& f)
{
	scanf("%d%f", &n, &f);
}
void printData(int& n, float& f)
{
	printf("%d\n", n);
	printf("%10d\n", n);
	printf("%+10d\n", n);
	printf("%-10d\n", n);
	printf("%f\n", f);
	printf("%10f\n", f);
	printf("%10.4f\n", f);
	printf("%+10.4f\n", f);
	printf("%-10.4f\n", f);


}
#endif
//=========================================================================================
// 10��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 10��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 10��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 10��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 10��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 10��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 11��. ������- ��� ������
//=========================================================================================
// 11��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int x, y, z;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	x = 3;
	y = 2;
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("%d \n", z = x + y);		// ��� �� : 5
	printf("%d \n", z = x - y);		// ��� �� : 1
	printf("%d \n", x * y);		// ��� �� : 6
	printf("%d \n", x / y);		// ��� �� : 1
	printf("%d \n", x % y);		// ��� �� : 1
	return 0;
}
#endif

//=========================================================================================
// 11��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0

#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int x, y, z;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf("%d %d %d", &x, &y, &z);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("%d \n", z = x + y);		// ��� �� : 5
	printf("%d \n", z = x - y);		// ��� �� : 1
	printf("%d \n", x * y);		// ��� �� : 6
	printf("%d \n", x / y);		// ��� �� : 1
	printf("%d \n", x % y);		// ��� �� : 1
	return 0;
}
#endif
// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 11��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value
#if 0

#include <stdio.h>

void printData(int, int, int);

int main(void) {
	// -------�Է�-���� ����------------------------------
	int x, y, z;
	// -------�Է�-���� �ʱ�ȭ----------------------------

	scanf("%d %d %d", &x, &y, &z);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, y, z);
	return 0;
}

void printData(int x, int y, int z)
{
	printf("%d \n", z = x + y);		// ��� �� : 5
	printf("%d \n", z = x - y);		// ��� �� : 1
	printf("%d \n", x * y);		// ��� �� : 6
	printf("%d \n", x / y);		// ��� �� : 1
	printf("%d \n", x % y);		// ��� �� : 1
}
#endif
// case 2. call-by-address
#if 0

#include <stdio.h>
void inputData(int*, int*, int*);
void printData(int*, int*, int*);

int main(void) {
	// -------�Է�-���� ����------------------------------
	int x, y, z;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	inputData(&x, &y, &z);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(&x, &y, &z);
	return 0;
}
void inputData(int* x, int* y, int* z)
{
	scanf("%d %d %d", *(&x), *(&y), *(&z));
}
void printData(int* x, int* y, int* z)
{
	printf("%d \n", *z = *x + *y);		// ��� �� : 5
	printf("%d \n", *z = *x - *y);		// ��� �� : 1
	printf("%d \n", *x * *y);		// ��� �� : 6
	printf("%d \n", *x / *y);		// ��� �� : 1
	printf("%d \n", *x % *y);		// ��� �� : 1
}
#endif
// case 3. call-by-reference
#if 0

#include <stdio.h>
void inputData(int&, int&, int&);
void printData(int&, int&, int&);

int main(void) {
	// -------�Է�-���� ����------------------------------
	int x, y, z;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	inputData(x, y, z);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, y, z);
	return 0;
}
void inputData(int& x, int& y, int& z)
{
	scanf("%d %d %d", &x, &y, &z);
}
void printData(int& x, int& y, int& z)
{
	printf("%d \n", z = x + y);		// ��� �� : 5
	printf("%d \n", z = x - y);		// ��� �� : 1
	printf("%d \n", x * y);		// ��� �� : 6
	printf("%d \n", x / y);		// ��� �� : 1
	printf("%d \n", x % y);		// ��� �� : 1
}
#endif
//=========================================================================================
// 11��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 11��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 11��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 11��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 11��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 11��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 12��. ������-���������
//=========================================================================================
// 12��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int time, minute, second;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	printf("�ð��� �Է��Ͻÿ�(��). \n");
	scanf("%d", &time);	// scanf�� �̿��Ͽ� time(��)�� �Է� ����
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	minute = time / 60;	// ���� ����Ͽ� minute�� ���� -> �ð��� 60���� ���� ��
	second = time % 60;	// �ʸ� ����Ͽ� second�� ���� -> �ð��� 60���� ���� ������

	printf("%d �ʴ� %d �� %d �� �Դϴ�.\n", time, minute, second);

	return 0;
}
#endif

//=========================================================================================
// 12��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int time, minute, second;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	printf("�ð��� �Է��Ͻÿ�(��). \n");
	scanf("%d", &time);	// scanf�� �̿��Ͽ� time(��)�� �Է� ����
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	minute = time / 60;	// ���� ����Ͽ� minute�� ���� -> �ð��� 60���� ���� ��
	second = time % 60;	// �ʸ� ����Ͽ� second�� ���� -> �ð��� 60���� ���� ������

	printf("%d �ʴ� %d �� %d �� �Դϴ�.\n", time, minute, second);

	return 0;
}
#endif

// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 12��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void printData(int, int, int);
int main(void) {
	// -------�Է�-���� ����------------------------------
	int time, minute, second;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	printf("�ð��� �Է��Ͻÿ�(��). \n");
	scanf("%d", &time);	// scanf�� �̿��Ͽ� time(��)�� �Է� ����
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(time, minute, second);
	return 0;
}

void printData(int time, int minute, int second)
{

	minute = time / 60;	// ���� ����Ͽ� minute�� ���� -> �ð��� 60���� ���� ��
	second = time % 60;	// �ʸ� ����Ͽ� second�� ���� -> �ð��� 60���� ���� ������

	printf("%d �ʴ� %d �� %d �� �Դϴ�.\n", time, minute, second);

}
#endif
// case 2. call-by-address
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void inputData(int*);
void printData(int*, int*, int*);
int main(void) {
	// -------�Է�-���� ����------------------------------
	int time, minute, second;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	printf("�ð��� �Է��Ͻÿ�(��). \n");
	inputData(&time);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(&time, &minute, &second);
	return 0;
}
void inputData(int* time)
{
	scanf("%d", *(&time));	// scanf�� �̿��Ͽ� time(��)�� �Է� ����
}
void printData(int* time, int* minute, int* second)
{

	*minute = *time / 60;	// ���� ����Ͽ� minute�� ���� -> �ð��� 60���� ���� ��
	*second = *time % 60;	// �ʸ� ����Ͽ� second�� ���� -> �ð��� 60���� ���� ������

	printf("%d �ʴ� %d �� %d �� �Դϴ�.\n", *time, *minute, *second);

}
#endif
// case 3. call-by-reference
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void inputData(int&);
void printData(int&, int&, int&);
int main(void) {
	// -------�Է�-���� ����------------------------------
	int time, minute, second;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	printf("�ð��� �Է��Ͻÿ�(��). \n");
	inputData(time);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(time, minute, second);
	return 0;
}
void inputData(int& time)
{
	scanf("%d", &time);	// scanf�� �̿��Ͽ� time(��)�� �Է� ����
}
void printData(int& time, int& minute, int& second)
{

	minute = time / 60;	// ���� ����Ͽ� minute�� ���� -> �ð��� 60���� ���� ��
	second = time % 60;	// �ʸ� ����Ͽ� second�� ���� -> �ð��� 60���� ���� ������

	printf("%d �ʴ� %d �� %d �� �Դϴ�.\n", time, minute, second);

}
#endif
//=========================================================================================
// 12��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 12��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 12��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 12��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 12��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 12��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================











//=========================================================================================
// 13��. ������-��� ������
//=========================================================================================
// 13��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	
void main() {
	// -------�Է�-���� ����------------------------------
	int a, b, c;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	a = 10, b = 20, c = a + b
		// -------ó��----------------------------------------
		// -------���----------------------------------------
		printf("���ϱ� ���� \n");
	printf("----------- \n");
	printf("a = %d \n", a);
	printf("b = %d \n", b);
	printf("a + b = %d \n", a + b); // ���ϱ� ����
	printf("a * b = %d \n", a * b); // ���ϱ� ����
	printf("a - b = %d \n", a - b); // ���� ����
	printf("b / a = %d \n", b / a); // ������ ����
	printf("b %% a = %d \n", b % a); // ������ ����
}
#endif

//=========================================================================================
// 13��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	
int main() {
	// -------�Է�-���� ����------------------------------
	int a, b, c;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf("%d %d", &a, &b);
	c = a + b;
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("���ϱ� ���� \n");
	printf("----------- \n");
	printf("a = %d \n", a);
	printf("b = %d \n", b);
	printf("a + b = %d \n", a + b); // ���ϱ� ����
	printf("a * b = %d \n", a * b); // ���ϱ� ����
	printf("a - b = %d \n", a - b); // ���� ����
	printf("b / a = %d \n", b / a); // ������ ����
	printf("b %% a = %d \n", b % a); // ������ ����

	return 0;
}
#endif
// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 13��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 13��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 13��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 13��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 13��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 13��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 13��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 14��. ������-���������
//=========================================================================================
// 14��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("3 + 4 ==> %d\n", 3 + 4);
	printf("3.4 - 4.3 ==> %f\n", 3.4 - 4.3);
	printf("3.4 * 4.3 ==> %f\n", 3.4 * 4.3);
	printf("10 / 3 ==> %d\n", 10 / 3);
	printf("10.0 / 3.0 ==> %f\n", 10.0 / 3.0);
	//printf("10.0 % 3.0 ==> %d\n", 10.0 % 3.0);
	printf("10 %% 3 ==> %d\n", 10 % 3);

	return 0;
}
#endif

//=========================================================================================
// 14��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("3 + 4 ==> %d\n", 3 + 4);
	printf("3.4 - 4.3 ==> %f\n", 3.4 - 4.3);
	printf("3.4 * 4.3 ==> %f\n", 3.4 * 4.3);
	printf("10 / 3 ==> %d\n", 10 / 3);
	printf("10.0 / 3.0 ==> %f\n", 10.0 / 3.0);
	//printf("10.0 % 3.0 ==> %d\n", 10.0 % 3.0);
	printf("10 %% 3 ==> %d\n", 10 % 3);

	return 0;
}
#endif
// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 14��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 14��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 14��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 14��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 14��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 14��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 14��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 15��. ������ - ���� ������
//=========================================================================================
// 15��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int a, b, c;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	a = b = c = 5;	//(a = (b = (c = 5)))
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("a = a + 2 ==> %d\n", a = a + 2);
	printf("a ==> %d\n", a);
	printf("a = b + c ==> %d\n", b + c);
	printf("a ==> %d\n", a);
	return 0;
}
#endif

//=========================================================================================
// 15��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int a, b, c;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf("%d %d %d", &a, &b, &c);
	//(a = (b = (c = 5)))
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("a = a + 2 ==> %d\n", a = a + 2);
	printf("a ==> %d\n", a);
	printf("a = b + c ==> %d\n", b + c);
	printf("a ==> %d\n", a);
	return 0;
}
#endif
// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 15��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printData(int, int, int);

int main(void) {
	// -------�Է�-���� ����------------------------------
	int a, b, c;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf("%d %d %d", &a, &b, &c);
	//(a = (b = (c = 5)))
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(a, b, c);
	return 0;
}

void printData(int a, int b, int c)
{
	printf("a = a + 2 ==> %d\n", a = a + 2);
	printf("a ==> %d\n", a);
	printf("a = b + c ==> %d\n", b + c);
	printf("a ==> %d\n", a);

}
#endif
// case 2. call-by-address

// case 3. call-by-reference
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void inputData(int&, int&, int&);
void printData(int&, int&, int&);

int main(void) {
	// -------�Է�-���� ����------------------------------
	int a, b, c;
	// -------�Է�-���� �ʱ�ȭ----------------------------

	inputData(a, b, c);

	//(a = (b = (c = 5)))
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(a, b, c);
	return 0;
}

void inputData(int& a, int& b, int& c)
{
	scanf("%d %d %d", &a, &b, &c);
}
void printData(int& a, int& b, int& c)
{
	printf("a = a + 2 ==> %d\n", a = a + 2);
	printf("a ==> %d\n", a);
	printf("a = b + c ==> %d\n", b + c);
	printf("a ==> %d\n", a);

}
#endif
//=========================================================================================
// 15��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 15��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 15��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 15��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 15��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 15��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 16��. ������ - ���� ������
//=========================================================================================
// 16��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int n = 10, m = 5;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	//�������� �������� ����
	printf("%d ", n += m /= 3);
	n = 10; m = 5;
	printf("%d\n", (n += (m /= 3)));

	//�������� �������� ����
	printf("%d ", 10 * 3 / 2);
	printf("%d ", (10 * 3) / 2);
	printf("%d\n", 10 * (3 / 2));

	return 0;
}
#endif

//=========================================================================================
// 16��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int n, m;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf("%d%d", &n, &m);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	//�������� �������� ����
	printf("%d ", n += m /= 3);
	n = 10; m = 5;
	printf("%d\n", (n += (m /= 3)));

	//�������� �������� ����
	printf("%d ", 10 * 3 / 2);
	printf("%d ", (10 * 3) / 2);
	printf("%d\n", 10 * (3 / 2));

	return 0;
}
#endif
// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 16��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 16��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 16��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 16��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 16��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 16��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 16��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 17��. ������-�޸� ������
//=========================================================================================
// 17��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int a = 100, b = 50, c;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("%d ", sizeof(short));
	printf("%d ", sizeof(a * 2));
	printf("%d ", sizeof 3.5F);
	printf("%d\n", sizeof 3.14);

	c = ++a, b++;		// a = 101, b�� �� ������ ����� ���� 1����
	printf("%d %d %d\n", a, b, c);	// a = 101, b = 51, c = 101

	c = (3 + a, b * 2); // 3+a�� ���� �Ҵ�Ǵ� �κ��� ������,
	// b*2�� ��, 51*2 = 102�� ���� C�� �Ҵ��
	// a�� b�� ���� ������� ���� ������
	printf("%d %d %d\n", a, b, c); // a = 101, b = 51, c = 102

	return 0;
}
#endif

//=========================================================================================
// 17��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int a, b, c;
	scanf("%d%d", &a, &b);
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("%d ", sizeof(short));
	printf("%d ", sizeof(a * 2));
	printf("%d ", sizeof 3.5F);
	printf("%d\n", sizeof 3.14);

	c = ++a, b++;		// a = 101, b�� �� ������ ����� ���� 1����
	printf("%d %d %d\n", a, b, c);	// a = 101, b = 51, c = 101

	c = (3 + a, b * 2); // 3+a�� ���� �Ҵ�Ǵ� �κ��� ������,
	// b*2�� ��, 51*2 = 102�� ���� C�� �Ҵ��
	// a�� b�� ���� ������� ���� ������
	printf("%d %d %d\n", a, b, c); // a = 101, b = 51, c = 102

	return 0;
}
#endif
// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 17��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 17��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 17��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 17��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 17��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 17��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 17��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 18��. ������ - �� ������
//=========================================================================================
// 18��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	// -------�Է�-���� ����------------------------------
	int x = 5, y = 10;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	x += y;
	printf("The addition is: %d\n", x);

	x -= y;
	printf("The subtraction is: %d\n", x);

	x *= y;
	printf("The multiplication is: %d\n", x);

	x /= y;
	printf("The division is: %d\n", x);

	x %= y;
	printf("The remainder is: %d\n", x);

	x *= x + y;
	printf("x *= x + y is: %d\n", x);

	return 0;
}
#endif

//=========================================================================================
// 18��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	// -------�Է�-���� ����------------------------------
	int x, y;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf("%d%d", &x, &y);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	x += y;
	printf("The addition is: %d\n", x);

	x -= y;
	printf("The subtraction is: %d\n", x);

	x *= y;
	printf("The multiplication is: %d\n", x);

	x /= y;
	printf("The division is: %d\n", x);

	x %= y;
	printf("The remainder is: %d\n", x);

	x *= x + y;
	printf("x *= x + y is: %d\n", x);

	return 0;
}
#endif
// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 18��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 18��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 18��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 18��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 18��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 18��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 18��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 19��. ������ - �� ������
//=========================================================================================
// 19��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int x, y;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	x = 10;
	y = 20;
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("%d \n", (x > y) ? x : y); // -> �������� ���� ū ���� 20

	return 0;
}
#endif

//=========================================================================================
// 19��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int x, y;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf("%d%d", &x, &y);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("%d \n", (x > y) ? x : y); // -> �������� ���� ū ���� 20

	return 0;
}
#endif
// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 19��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 19��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 19��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 19��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 19��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 19��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 19��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 20��. ������ - ���� ������
//=========================================================================================
// 20��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	// -------�Է�-���� ����------------------------------
	int a = 10, b = -5;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("�ִ밪: %d\n", (a > b) ? a : b);
	printf("�ּҰ�: %d\n", (a < b) ? a : b);
	printf("���밪: %d\n", (a > 0) ? a : -a);
	printf("���밪: %d\n", (b > 0) ? b : -b);

	((a % 2) == 0) ? printf("¦��\n") : printf("Ȧ��\n");;

	return 0;
}
#endif

//=========================================================================================
// 20��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	// -------�Է�-���� ����------------------------------
	int a, b;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf("%d%d", &a, &b);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("�ִ밪: %d\n", (a > b) ? a : b);
	printf("�ּҰ�: %d\n", (a < b) ? a : b);
	printf("���밪: %d\n", (a > 0) ? a : -a);
	printf("���밪: %d\n", (b > 0) ? b : -b);

	((a % 2) == 0) ? printf("¦��\n") : printf("Ȧ��\n");;

	return 0;
}
#endif
// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 20��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 20��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 20��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 20��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 20��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 20��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 20��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 21��. ������ - ���� ������
//=========================================================================================
// 21��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	// -------�Է�-���� ����------------------------------
	int a = 5, b = 10, c = 15;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("a=%d, b=%d, c=%d\n", a, b, c);						//a=5, b=10, c=15
	printf("\ta + b++ - --c �� ��� = %5d\n\n", a + b++ - --c);	//a=5, b=11, c=14

	printf("a=%d, b=%d, c=%d\n", a, b, c);						//a=5, b=11, c=14
	printf("\t--a + ++b %% 3 �� ��� = %5d\n\n", --a + ++b % 3);	//a=4, b=12, c=14
	printf("a=%d, b=%d, c=%d\n", a, b, c);						//a=4, b=12, c=14

	return 0;
}
#endif

//=========================================================================================
// 21��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	// -------�Է�-���� ����------------------------------
	int a = 5, b = 10, c = 15;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("a=%d, b=%d, c=%d\n", a, b, c);						//a=5, b=10, c=15
	printf("\ta + b++ - --c �� ��� = %5d\n\n", a + b++ - --c);	//a=5, b=11, c=14

	printf("a=%d, b=%d, c=%d\n", a, b, c);						//a=5, b=11, c=14
	printf("\t--a + ++b %% 3 �� ��� = %5d\n\n", --a + ++b % 3);	//a=4, b=12, c=14
	printf("a=%d, b=%d, c=%d\n", a, b, c);						//a=4, b=12, c=14

	return 0;
}
#endif
// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 21��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 21��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 21��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 21��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 21��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 21��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 21��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 22��. ������ - ���� ������
//=========================================================================================
// 22��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int x;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	x = 10;
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("%d \n", x++);	// x++ = 10, �� ������ ������ x = 11�� ��
	printf("%d \n", ++x);	// ++x = 12, �����̱� ������ 11+1�� �Ǿ� 12
	printf("%d \n", x--);	// x-- = 12, �� ������ ������ ���� 12-1=11�� ��
	return 0;
}
#endif

//=========================================================================================
// 22��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int x;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf("%d", &x);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("%d \n", x++);	// x++ = 10, �� ������ ������ x = 11�� ��
	printf("%d \n", ++x);	// ++x = 12, �����̱� ������ 11+1�� �Ǿ� 12
	printf("%d \n", x--);	// x-- = 12, �� ������ ������ ���� 12-1=11�� ��
	return 0;
}
#endif
// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 22��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 22��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 22��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 22��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 22��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 22��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 22��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================











//=========================================================================================
// 23��. ������ - ���� ������
//=========================================================================================
// 23��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int a, b, c, d, x;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	x = 1;
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("a=%d \n", x++);		//a = x++ = 1, �����̱� ������ �̹����� ������ ���� 2�� �����
	printf("b=%d \n", ++x);		//b = ++x = 3, �����̱� ������ 2+1�� ���� ���
	printf("c=%d \n", x--);		//c = x-- = 3, �����̱� ������ 3�� ��µǰ� ���� �� ���� ������ 1����
	printf("d=%d \n", --x);		//d = --x = 1, �����̱� ������ 2-1�� ���� ��µ�

	return 0;
}
#endif

//=========================================================================================
// 23��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int a, b, c, d, x;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &x);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("a=%d \n", x++);		//a = x++ = 1, �����̱� ������ �̹����� ������ ���� 2�� �����
	printf("b=%d \n", ++x);		//b = ++x = 3, �����̱� ������ 2+1�� ���� ���
	printf("c=%d \n", x--);		//c = x-- = 3, �����̱� ������ 3�� ��µǰ� ���� �� ���� ������ 1����
	printf("d=%d \n", --x);		//d = --x = 1, �����̱� ������ 2-1�� ���� ��µ�

	return 0;
}
#endif
// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 23��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 23��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 23��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 23��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 23��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 23��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 23��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 24��. ������ - ���� ������
//=========================================================================================
// 24��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int m = 10, n = 5;
	int result;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	result = m++ + --n;
	printf("m=%d n=%d result=%d\n", m, n, result);

	result = ++m - n--;
	printf("m=%d n=%d result=%d\n", m, n, result);

	return 0;
}
#endif

//=========================================================================================
// 24��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int m, n;
	int result;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf("%d%d", &m, &n);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	result = m++ + --n;
	printf("m=%d n=%d result=%d\n", m, n, result);

	result = ++m - n--;
	printf("m=%d n=%d result=%d\n", m, n, result);

	return 0;
}
#endif
// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 24��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 24��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 24��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 24��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 24��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 24��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 24��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 25��. ������ - �� ������
//=========================================================================================
// 25��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("(3 > 4) ��� ��: %d\n", (3 > 4));
	printf("(3 < 4.0) ��� ��: %d\n", (3 < 4.0));
	printf("('a' <= 'b') ��� ��: %d\n", ('a' <= 'b'));
	printf("(4.27 >= 4.35) ��� ��: %d\n", (4.27 >= 4.35));
	printf("(4 != 4.0) ��� ��: %d\n", (4 != 4.0));
	printf("(4.0F == 4.0) ��� ��: %d\n", (4.0F == 4.0));

	return 0;
}
#endif

//=========================================================================================
// 25��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("(3 > 4) ��� ��: %d\n", (3 > 4));
	printf("(3 < 4.0) ��� ��: %d\n", (3 < 4.0));
	printf("('a' <= 'b') ��� ��: %d\n", ('a' <= 'b'));
	printf("(4.27 >= 4.35) ��� ��: %d\n", (4.27 >= 4.35));
	printf("(4 != 4.0) ��� ��: %d\n", (4 != 4.0));
	printf("(4.0F == 4.0) ��� ��: %d\n", (4.0F == 4.0));

	return 0;
}
#endif
// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 25��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 25��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 25��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 25��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 25��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 25��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 25��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 26��. ������ - �켱����
//=========================================================================================
// 26��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	// -------�Է�-���� ����------------------------------
	int a = 3, b = 5;
	double x = 3.5, y = 2.7;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("%d ", a++ - --b * 2);			//���� > ���� > ����
	printf("%f ", a > b ? x + 1 : y * 2);	//��� > ���� > ����

	return 0;
}
#endif

//=========================================================================================
// 26��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	// -------�Է�-���� ����------------------------------
	int a, b;
	double x, y;
	scanf("%d%d", &a, &b);
	scanf("%lf%lf", &x, &y);

	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("%d ", a++ - --b * 2);			//���� > ���� > ����
	printf("%f ", a > b ? x + 1 : y * 2);	//��� > ���� > ����

	return 0;
}
#endif
// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 26��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 26��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 26��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 26��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 26��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 26��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 26��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 27��. ������ - ���� ������
//=========================================================================================
// 27��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	char null = '\0', a = 'a';
	int zero = 0, n = 10;
	double dzero = 0.0, x = 3.56;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------	
	printf("%d\n", !zero);
	printf("%d\n", zero && x);
	printf("%d\n", dzero || null);
	printf("%d\n", n && x);
	printf("%d\n", a || null);
	return 0;
}
#endif
//=========================================================================================
// 27��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	char null = '\0', a = 'a';
	int zero = 0, n = 10;
	double dzero = 0.0, x = 3.56;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------	
	printf("%d\n", !zero);
	printf("%d\n", zero && x);
	printf("%d\n", dzero || null);
	printf("%d\n", n && x);
	printf("%d\n", a || null);
	return 0;
}
#endif
// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 27��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 27��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 27��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 27��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 27��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 27��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 27��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 28��. ������ - ���� ������
//=========================================================================================
// 28��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int x, y;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	x = 10;
	y = 20;
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("%d \n", x < y);		// ��� �� : 1
	printf("%d \n", x == y);	// ��� �� : 0
	printf("%d \n", x = y);		// ��� �� : 20 // �Ҵ翬�����̱� ������ y�� ���� x�� �Ҵ���
	printf("%d \n", x != y);	// ��� �� : 0
	printf("%d \n", !x);		// ��� �� : 0

	return 0;
}
#endif

//=========================================================================================
// 28��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	char null = '\0', a = 'a';
	int zero = 0, n = 10;
	double dzero = 0.0, x = 3.56;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf(" %c", &a);
	scanf(" %d %d", &zero, &n);
	scanf(" %lf %lf", &dzero, &x);

	// -------ó��----------------------------------------
	// -------���----------------------------------------	
	printf("%d\n", !zero);
	printf("%d\n", zero && x);
	printf("%d\n", dzero || null);
	printf("%d\n", n && x);
	printf("%d\n", a || null);
	return 0;
}
#endif
// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 28��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 28��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 28��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 28��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 28��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 28��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 28��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 29��. ������ - ���� ������
//=========================================================================================
// 29��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int x;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	x = 0;
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("%d \n", !0);					// ��� �� : 1
	printf("%d \n", !!2);					// ��� �� : 1
	printf("%d \n", !(1 == 2) + (1 == 1));	// ��� �� : 2
	printf("%d \n", (1 == 2) && (1 == 1));	// ��� �� : 0
	printf("%d \n", (1 == 2) || (1 == 1));	// ��� �� : 1
	printf("%d \n", (x != 0) || (x != 1));	// ��� �� : 1
	return 0;
}
// �� �����ڿ��� 0�� ��쿡�� ����(0)�� ��. 0�� �ƴ� �������� ��쿡�� ��� ��(1)�� �Ǳ�
// ������ !!2�� ��쿡�� 2�� ��, !2�� ����, !!2�� ���� ��
#endif

//=========================================================================================
// 29��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int x;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf("%d", &x);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("%d \n", !0);					// ��� �� : 1
	printf("%d \n", !!2);					// ��� �� : 1
	printf("%d \n", !(1 == 2) + (1 == 1));	// ��� �� : 2
	printf("%d \n", (1 == 2) && (1 == 1));	// ��� �� : 0
	printf("%d \n", (1 == 2) || (1 == 1));	// ��� �� : 1
	printf("%d \n", (x != 0) || (x != 1));	// ��� �� : 1
	return 0;
}
// �� �����ڿ��� 0�� ��쿡�� ����(0)�� ��. 0�� �ƴ� �������� ��쿡�� ��� ��(1)�� �Ǳ�
// ������ !!2�� ��쿡�� 2�� ��, !2�� ����, !!2�� ���� ��
#endif
// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 29��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 29��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 29��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 29��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 29��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 29��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 29��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 30��. ������ - ���� ������
//=========================================================================================
// 30��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int year, result;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	printf("������ �Է��Ͻÿ�. \n");
	scanf("%d", &year);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	result = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	// �����̸� 1�̰� ������ �ƴϸ� 0���� �ǹ�
	printf("result=%d \n", result);

	return 0;
}
#endif

//=========================================================================================
// 30��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int year, result;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	printf("������ �Է��Ͻÿ�. \n");
	scanf("%d", &year);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	result = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	// �����̸� 1�̰� ������ �ƴϸ� 0���� �ǹ�
	printf("result=%d \n", result);

	return 0;
}
#endif
// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 30��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 30��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 30��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 30��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 30��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 30��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 30��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 31��. ������ - ���� ������
//=========================================================================================
// 31��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("(3 > 4) ��� ��: %d\n", (3 > 4));
	printf("(3 < 4.0) ��� ��: %d\n", (3 < 4.0));
	printf("('a' <= 'b') ��� ��: %d\n", ('a' <= 'b'));
	printf("(4.27 >= 4.35) ��� ��: %d\n", (4.27 >= 4.35));
	printf("(4 != 4.0) ��� ��: %d\n", (4 != 4.0));
	printf("(4.0F == 4.0) ��� ��: %d\n", (4.0F == 4.0));

	return 0;
}
// ������ ��� �� ���ں��� ASCII �ڵ� ���� �Ҵ�Ǿ� �ֱ� ������ 
// printf("('a' <= 'b') ��� ��: %d\n", ('a' <= 'b'));�� ���� �񱳰� ������
#endif

//=========================================================================================
// 31��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("(3 > 4) ��� ��: %d\n", (3 > 4));
	printf("(3 < 4.0) ��� ��: %d\n", (3 < 4.0));
	printf("('a' <= 'b') ��� ��: %d\n", ('a' <= 'b'));
	printf("(4.27 >= 4.35) ��� ��: %d\n", (4.27 >= 4.35));
	printf("(4 != 4.0) ��� ��: %d\n", (4 != 4.0));
	printf("(4.0F == 4.0) ��� ��: %d\n", (4.0F == 4.0));

	return 0;
}
// ������ ��� �� ���ں��� ASCII �ڵ� ���� �Ҵ�Ǿ� �ֱ� ������ 
// printf("('a' <= 'b') ��� ��: %d\n", ('a' <= 'b'));�� ���� �񱳰� ������
#endif
// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 31��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 31��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 31��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 31��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 31��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 31��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 31��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 32��. ������ - ���� ������
//=========================================================================================
// 32��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int x, y;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	x = 5;
	y = 2;
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("%d \n", x += 2);		// ��� �� : 7
	printf("%d \n", y *= 10);		// ��� �� : 20
	printf("%d \n", y /= x + 1);	// ��� �� : 2
	printf("%d \n", x %= x - y);	// ��� �� : 2

	return 0;
}
#endif

//=========================================================================================
// 32��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int x, y;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf("%d%d", &x, &y);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("%d \n", x += 2);		// ��� �� : 7
	printf("%d \n", y *= 10);		// ��� �� : 20
	printf("%d \n", y /= x + 1);	// ��� �� : 2
	printf("%d \n", x %= x - y);	// ��� �� : 2

	return 0;
}
#endif
// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 32��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 32��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 32��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 32��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 32��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 32��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 32��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 33��. ������ - ����ȯ
//=========================================================================================
// 33��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	// -------�Է�-���� ����------------------------------
	int a = 3.4;	//�ڵ����� ������ȯ�Ǿ� ���� a���� 3�� ���� 
	double d = 3;	//�ڵ����� �ø���ȯ�Ǿ� ���� d���� 3.0�� ����
	double  result = (double)7 / 2;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("%5d %10f ", a, d);
	printf("%10f\n", 3 + 4.5);

	printf("%5d ", 10 / 4);
	printf("%10f ", (double)10 / 4);
	printf("%10f ", 10 / (double)4);
	printf("%10f\n", (double)(10 / 4));

	printf("%5d ", (int)(3.4 + 7.8));
	printf("%10d ", (int)3.4 + (int)7.8);
	printf("%10f ", (int)3.4 + 7.8);
	printf("%10f\n", 3.4 + (int)7.8);

	return 0;
}
#endif

//=========================================================================================
// 33��-01. scanf/scanf_s ��ȯ
//=========================================================================================
// case 1. ���� �ʱ�ȭ �κ��� scanf() �Լ��� ����Ͽ� ��ȯ�� ����
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	// -------�Է�-���� ����------------------------------
	int a;	//�ڵ����� ������ȯ�Ǿ� ���� a���� 3�� ���� 
	double d;	//�ڵ����� �ø���ȯ�Ǿ� ���� d���� 3.0�� ����
	double  result = (double)7 / 2;

	scanf("%d %lf", &a, &d);
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printf("%5d %10f ", a, d);
	printf("%10f\n", 3 + 4.5);

	printf("%5d ", 10 / 4);
	printf("%10f ", (double)10 / 4);
	printf("%10f ", 10 / (double)4);
	printf("%10f\n", (double)(10 / 4));

	printf("%5d ", (int)(3.4 + 7.8));
	printf("%10d ", (int)3.4 + (int)7.8);
	printf("%10f ", (int)3.4 + 7.8);
	printf("%10f\n", 3.4 + (int)7.8);

	return 0;
}
#endif

// case 2. ���� �ʱ�ȭ �κ��� scanf_s() �Լ��� ����Ͽ� ��ȯ�� ����

//=========================================================================================
// 33��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 33��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 33��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 33��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 33��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 33��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 33��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 34��. ����-goto��
//=========================================================================================
// 34��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	char a;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf(" %c", &a);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	if (a == 'Q' || a == 'q') {		// end �κ����� ����
		goto end;
	}
	printf("%c pressed \n", a);

end:
	printf("Program terminated ... \n");

	return 0;
}
#endif

//=========================================================================================
// 34��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 34��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 34��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 34��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 34��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 34��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 34��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 35��. ����-goto��
//=========================================================================================
// 35��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	// -------�Է�-���� ����------------------------------
	int a, b;
	char c;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	scanf("%d %c%d", &a, &c, &b);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	if (c == '+') {						// 'c=+'�� �ǹ�, ���ǹ����� ���ǹ��� ������ ��� printf ����.
		printf("a+b=%d \n", a + b);
	}
	else if (c == '-') {				// 'c=-'�� �ǹ�, ���ǹ����� ���ǹ��� ������ ��� printf ����.
		printf("a-b=%d \n", a - b);
	}
	else if (c == '*') {				// 'c=*'�� �ǹ�, ���ǹ����� ���ǹ��� ������ ��� printf ����.
		printf("a*b=%d \n", a * b);
	}
	else if (c == '/') {				// 'c=/'�� �ǹ�, ���ǹ����� ���ǹ��� ������ ��� printf ����.
		printf("a/b=%d \n", a / b);
	}
	else goto end;					// if���� else if���� ������Ű�� ���� ��쿡 �ش�. goto���� ���� end�κ����� ����.
	return;
end:
	printf("Program terminated... \n");
	return;

	return 0;	// return ���� ����.
}
#endif

//=========================================================================================
// 35��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 35��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 35��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 35��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 35��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 35��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 35��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 36��. ���� - if��
//=========================================================================================
// 36��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(void) {
	// -------�Է�-���� ����------------------------------
	int a;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	printf("10���� ū ���� �Է� : ");
	scanf("%d", &a);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	if (a > 10) {	// ���ǹ����� ���ǹ��� ������ ��� printf�� �����.
		printf("%d��(��) 10���� Ů�ϴ�. \n", a);
		printf("%d��(��) 10���� %d��ŭ Ů�ϴ�. \n", a, a - 10);
	}
}
#endif

//=========================================================================================
// 36��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 36��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 36��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 36��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 36��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 36��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 36��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 37��. ���� - if��
//=========================================================================================
// 37��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	double grade;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	printf("������� �Է�: ");
	scanf("%lf", &grade);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	if (grade >= 4.0)
	{
		printf("�Ｚ�� ������ �� �ֽ��ϴ�.\n");
	}
	printf("������ �����մϴ�.\n");
	return 0;
}
#endif

//=========================================================================================
// 37��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 37��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 37��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 37��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 37��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 37��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 37��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 38��. ���� - if-else��
//=========================================================================================
// 38��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(void) {
	// -------�Է�-���� ����------------------------------
	int a;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	printf("a�� ���� ���� �Է� : ");
	scanf("%d", &a);
	// -------ó��----------------------------------------
	// -------���----------------------------------------	
	if (a > 10) {				// ���ǹ����� ���ǹ��� ������ ��� printf�� �����.
		printf("a��(��) 10���� Ů�ϴ�. \n");
	}
	else {					// if���� ������Ű�� ���� ��� ������ printf�� �����.
		printf("a��(��) 10���� �۰ų� ����. \n");
	}
}
#endif

//=========================================================================================
// 38��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 38��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 38��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 38��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 38��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 38��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 38��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 39��. ���� - if-else��
//=========================================================================================
// 39��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	
int main(void) {
	// -------�Է�-���� ����------------------------------
	int score;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	printf("������ �Է��Ͻÿ� : ");
	scanf("%d", &score);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	if (score >= 60) {		// ���ǹ����� ���ǹ��� ������ ��� printf�� ���
		printf("�հ�! \n");
	}
	else {					// if���� ������Ű�� ���� ��� ������ printf ���
		printf("���հ�! \n");
	}
	return 0;
}
#endif

//=========================================================================================
// 39��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 39��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 39��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 39��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 39��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 39��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 39��-08. 2���� �迭- ���� ������ ��ȯ
//========================================================================================


//=========================================================================================
// 40��. ���� - if-else��
//=========================================================================================
// 40��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int n;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	printf("���� �Է�: ");
	scanf("%d", &n);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	if (n % 2)
		printf("Ȧ��");
	else
		printf("¦��");

	printf("�Դϴ�.\n");

	return 0;
}
#endif

//=========================================================================================
// 40��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 40��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 40��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 40��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 40��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 40��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 40��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 41��. ���� - ��ø if��
//=========================================================================================
// 41��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>	// ���а����Լ��� ����ϱ� ���� math.h ������� ����
int main(void) {
	// -------�Է�-���� ����------------------------------
	double a, b, c, dis;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	printf("��� a�� �Է��Ͻÿ� : ");
	scanf("%lf", &a);

	printf("��� b�� �Է��Ͻÿ� : ");
	scanf("%lf", &b);

	printf("��� c�� �Է��Ͻÿ� : ");
	scanf("%lf", &c);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	if (a == 0) {	// a�� 0�� ���ٶ�� �ǹ�, ���ǹ��� ������ ��� {}���� ���� ����.
		printf("�������� ���� %f�Դϴ�. \n", -c / b);
	}
	else {			// a != 0�� ���, �� a�� 0�� �ƴ� ��츦 �ǹ�
		dis = sqrt(b * b - 4.0 * a * c);	// dis�� �ʱ�ȭ

		if (dis >= 0) {				// dis�� 0���� ũ�ų� ���� ��츦 �ǹ�
			printf("�������� ���� %f�Դϴ�. \n", (-b + dis) / (2.0 * a));
			printf("�������� ���� %f�Դϴ�. \n", (b + dis) / (2.0 * a));
		}
		else {		// dis�� 0���� ���� ��츦 �ǹ�
			printf("�Ǳ��� �������� �ʽ��ϴ�. \n");
		}
	}
	return 0;
}
#endif

//=========================================================================================
// 41��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 41��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 41��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 41��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 41��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 41��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 41��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 42��. ���� - ��ø if��
//=========================================================================================
// 42��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
int main(void) {
	// -------�Է�-���� ����------------------------------
	int type, point;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	printf("��ȣ�� ����: 1(1������), 2(2������): ");
	scanf("%d", &type);
	printf("�ʱ���� ���� �Է�: ");
	scanf("%d", &point);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	if (type == 1)
	{
		if (point >= 70)
			printf("1������ �հ�\n");
		else
			printf("1������ ���հ�\n");
	}
	else if (type == 2)
	{
		if (point >= 60)
			printf("2������ �հ�\n");
		else
			printf("2������ ���հ�\n");
	}
	return 0;
}
#endif

//=========================================================================================
// 42��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 42��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 42��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 42��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 42��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 42��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 42��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 43��. ���� - if-elseif��
//=========================================================================================
// 43��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int a;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	printf("������ �Է��Ͻÿ� : ");
	scanf("%d", &a);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	if (a < 50) {	// ���ǹ����� ���ǹ��� ������ ��� printf�� ���.
		printf("���հ��Դϴ�. \n");
	}
	else if (a < 60) {						// a >= 50 && a < 60
		printf("��Ÿ���� ���հ��Դϴ�. \n");
	}
	else if (a < 70) {						// a >= 60 && a < 70
		printf("�հ��Դϴ�. \n");
	}
	else if (a < 80) {						// a >= 70 && a < 80
		printf("����ϰ� �հ��Ͽ����ϴ�. \n");
	}
	else {									// a >= 80
		printf("���� ����ϰ� �հ��Ͽ����ϴ�. \n");
	}

	return 0;
}
#endif

//=========================================================================================
// 43��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 43��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 43��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 43��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 43��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 43��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 43��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 44��. ���� - if-elseif��
//=========================================================================================
// 44��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	unsigned long income;
	unsigned long tax;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	printf("���� ǥ���� �Է��Ͻÿ�(����) : ");
	scanf("%d", &income);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	if (income <= 1000) {			// 1000���� ����, ���ǹ����� ���ǹ��� ������ ��� {}���� ������ ������.
		tax = income * 0.08;
	}
	else if (income > 1000 && income <= 4000) {	// 1000���� �ʰ� 4000���� ����, ���ǹ����� ���ǹ��� ������ ��� {}���� ������ ������.
		tax = income * 0.17;
	}
	else if (income > 4000 && income <= 8000) {	// 4000���� �ʰ� 8000���� ����, ���ǹ����� ���ǹ��� ������ ��� {}���� ������ ������.
		tax = income * 0.26;	// ���� 26%
	}
	else {										// (income > 8000) 8000���� �ʰ�
		tax = income * 0.35;	// ���� 35%
	}
	printf("�ҵ漼: %d����\n", tax);
	return 0;
}
#endif

//=========================================================================================
// 44��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 44��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 44��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 44��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 44��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 44��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 44��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 45��. ���� - if-elseif��
//=========================================================================================
// 45��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	double gpa;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	printf("��� ���� �Է�: ");
	scanf("%lf", &gpa);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	if (gpa >= 4.3)
		printf("������ �ְ� ����� �л��Դϴ�.\n");
	else if (gpa >= 3.8)
		printf("������ �ſ� ����� �л��Դϴ�.\n");
	else if (gpa >= 3.0)
		printf("������ ����� �л��Դϴ�.\n");
	else
		printf("������ 3.0 �̸��� �л��Դϴ�.\n");

	return 0;
}
#endif

//=========================================================================================
// 45��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 45��-03.1���� �迭
//=========================================================================================

//=========================================================================================
// 45��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 45��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 45��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 45��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 45��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 46��. ���� - switch case��
//=========================================================================================
// 46��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int a, b, c;
	char d;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	printf("������ �Է��Ͻÿ� : ");
	scanf("%d %c%d", &a, &d, &b);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	switch (d) {			// switch���� ���� ���� ������ ���� �߿��� �ϳ��� ���� �����ϴ� ����. () ���� ǥ���� �� �߿��� case�� ���� ��ġ�ϴ� ���� ó���ϴ� �����̴�.
	case '+': c = a + b; break;	// ���� break�� ������ switch���� �����Ѵ�. ���� break�� ���ٸ� ���� ���� ������� �Ʒ� ������ �����Ѵ�.
	case '-': c = a - b; break;	// ���� break�� ������ switch���� �����Ѵ�.
	case '*': c = a * b; break;	// ���� break�� ������ switch���� �����Ѵ�.
	case '/': c = a / b; break;	// ���� break�� ������ switch���� �����Ѵ�.
	default: 0;	  break;	// ��ġ�� case ���� ������ ���Ͽ� default�� ������ default ������ ������ �����Ѵ�.
	}
	printf("%d %c %d = %d \n", a, d, b, c);
	return 0;
}
#endif

//=========================================================================================
// 46��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printData(int, int, int, char);
int main(void) {
	// -------�Է�-���� ����------------------------------
	int a, b, c;
	char d;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	printf("������ �Է��Ͻÿ� : ");
	scanf("%d %c%d", &a, &d, &b);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(a, b, c, d);
	return 0;
}

void printData(int a, int b, int c, char d)
{

	switch (d) {			// switch���� ���� ���� ������ ���� �߿��� �ϳ��� ���� �����ϴ� ����. () ���� ǥ���� �� �߿��� case�� ���� ��ġ�ϴ� ���� ó���ϴ� �����̴�.
	case '+': c = a + b; break;	// ���� break�� ������ switch���� �����Ѵ�. ���� break�� ���ٸ� ���� ���� ������� �Ʒ� ������ �����Ѵ�.
	case '-': c = a - b; break;	// ���� break�� ������ switch���� �����Ѵ�.
	case '*': c = a * b; break;	// ���� break�� ������ switch���� �����Ѵ�.
	case '/': c = a / b; break;	// ���� break�� ������ switch���� �����Ѵ�.
	default: 0;	  break;	// ��ġ�� case ���� ������ ���Ͽ� default�� ������ default ������ ������ �����Ѵ�.
	}
	printf("%d %c %d = %d \n", a, d, b, c);
}
#endif

// case 2. call-by-address
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void inputData(int*, int*, char*);
void printData(int*, int*, int*, char*);
int main(void) {
	// -------�Է�-���� ����------------------------------
	int a, b, c;
	char d;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	inputData(&a, &b, &d);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(&a, &b, &c, &d);
	return 0;
}
void inputData(int* a, int* b, char* d)
{
	printf("������ �Է��Ͻÿ� : ");
	scanf("%d %c%d", a, d, b);

}
void printData(int* a, int* b, int* c, char* d)
{

	switch (*d) {			// switch���� ���� ���� ������ ���� �߿��� �ϳ��� ���� �����ϴ� ����. () ���� ǥ���� �� �߿��� case�� ���� ��ġ�ϴ� ���� ó���ϴ� �����̴�.
	case '+': *c = *a + *b; break;	// ���� break�� ������ switch���� �����Ѵ�. ���� break�� ���ٸ� ���� ���� ������� �Ʒ� ������ �����Ѵ�.
	case '-': *c = *a - *b; break;	// ���� break�� ������ switch���� �����Ѵ�.
	case '*': *c = *a * *b; break;	// ���� break�� ������ switch���� �����Ѵ�.
	case '/': *c = *a / *b; break;	// ���� break�� ������ switch���� �����Ѵ�.
	default: 0;	  break;	// ��ġ�� case ���� ������ ���Ͽ� default�� ������ default ������ ������ �����Ѵ�.
	}
	printf("%d %c %d = %d \n", *a, *d, *b, *c);
}
#endif
// case 3. call-by-reference

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void inputData(int&, int&, char&);
void printData(int&, int&, int&, char&);
int main(void) {
	// -------�Է�-���� ����------------------------------
	int a, b, c;
	char d;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	inputData(a, b, d);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(a, b, c, d);
	return 0;
}
void inputData(int& a, int& b, char& d)
{
	printf("������ �Է��Ͻÿ� : ");
	scanf("%d %c%d", &a, &d, &b);

}
void printData(int& a, int& b, int& c, char& d)
{

	switch (d) {			// switch���� ���� ���� ������ ���� �߿��� �ϳ��� ���� �����ϴ� ����. () ���� ǥ���� �� �߿��� case�� ���� ��ġ�ϴ� ���� ó���ϴ� �����̴�.
	case '+': c = a + b; break;	// ���� break�� ������ switch���� �����Ѵ�. ���� break�� ���ٸ� ���� ���� ������� �Ʒ� ������ �����Ѵ�.
	case '-': c = a - b; break;	// ���� break�� ������ switch���� �����Ѵ�.
	case '*': c = a * b; break;	// ���� break�� ������ switch���� �����Ѵ�.
	case '/': c = a / b; break;	// ���� break�� ������ switch���� �����Ѵ�.
	default: 0;	  break;	// ��ġ�� case ���� ������ ���Ͽ� default�� ������ default ������ ������ �����Ѵ�.
	}
	printf("%d %c %d = %d \n", a, d, b, c);
}
#endif
//=========================================================================================
// 46��-03.1���� �迭
//=========================================================================================

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void inputData(int&, int&, char&);
void printData(int&, int&, int&, char&);
int main(void) {
	// -------�Է�-���� ����------------------------------
	int a, b, c;
	char d;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	inputData(a, b, d);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(a, b, c, d);
	return 0;
}
void inputData(int& a, int& b, char& d)
{
	printf("������ �Է��Ͻÿ� : ");
	scanf("%d %c%d", &a, &d, &b);

}
void printData(int& a, int& b, int& c, char& d)
{

	switch (d) {			// switch���� ���� ���� ������ ���� �߿��� �ϳ��� ���� �����ϴ� ����. () ���� ǥ���� �� �߿��� case�� ���� ��ġ�ϴ� ���� ó���ϴ� �����̴�.
	case '+': c = a + b; break;	// ���� break�� ������ switch���� �����Ѵ�. ���� break�� ���ٸ� ���� ���� ������� �Ʒ� ������ �����Ѵ�.
	case '-': c = a - b; break;	// ���� break�� ������ switch���� �����Ѵ�.
	case '*': c = a * b; break;	// ���� break�� ������ switch���� �����Ѵ�.
	case '/': c = a / b; break;	// ���� break�� ������ switch���� �����Ѵ�.
	default: 0;	  break;	// ��ġ�� case ���� ������ ���Ͽ� default�� ������ default ������ ������ �����Ѵ�.
	}
	printf("%d %c %d = %d \n", a, d, b, c);
}
#endif
//=========================================================================================
// 46��-04.1���� ������
//=========================================================================================

//=========================================================================================
// 46��-05.2���� �迭
//=========================================================================================

//=========================================================================================
// 46��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================

//=========================================================================================
// 46��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 46��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================












//=========================================================================================
// 47��. ���� - switch case��
//=========================================================================================
// 47��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	char c;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	printf("���ڸ� �Է��Ͻÿ� : ");
	scanf(" %c", &c);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	switch (c) {
	case 'a':
		printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c);
		break;
	case 'e':
		printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c);
		break;
	case 'i':
		printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c);
		break;
	case 'u':
		printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c);
		break;
	case 'o':
		printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c);
		break;
	default:
		printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c);
		break; .
	}
	return 0;
}
#endif

//=========================================================================================
// 47��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printData(char);
int main(void) {
	// -------�Է�-���� ����------------------------------
	char c;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	printf("���ڸ� �Է��Ͻÿ� : ");
	scanf(" %c", &c);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(c);
	return 0;
}

void printData(char c)
{
	switch (c) {
	case 'a':
		printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c);
		break;
	case 'e':
		printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c);
		break;
	case 'i':
		printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c);
		break;
	case 'u':
		printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c);
		break;
	case 'o':
		printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c);
		break;
	default:
		printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c);
		break;
	}
}
#endif
// case 2. call-by-address
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void inputData(char*);
void printData(char*);
int main(void) {
	// -------�Է�-���� ����------------------------------
	char c;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	inputData(&c);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(&c);
	return 0;
}
void inputData(char* c)
{
	printf("���ڸ� �Է��Ͻÿ� : ");
	scanf(" %c", c);
	return;
}
void printData(char* c)
{
	switch (*c) {
	case 'a':
		printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", *c);
		break;
	case 'e':
		printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", *c);
		break;
	case 'i':
		printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", *c);
		break;
	case 'u':
		printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", *c);
		break;
	case 'o':
		printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", *c);
		break;
	default:
		printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c);
		break;
	}
	return;
}
#endif
// case 3. call-by-reference
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void inputData(char&);
void printData(char&);
int main(void) {
	// -------�Է�-���� ����------------------------------
	char c;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	inputData(c);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(c);
	return 0;
}
void inputData(char& c)
{
	printf("���ڸ� �Է��Ͻÿ� : ");
	scanf(" %c", &c);
	return;
}
void printData(char& c)
{
	switch (c) {
	case 'a':
		printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c);
		break;
	case 'e':
		printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c);
		break;
	case 'i':
		printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c);
		break;
	case 'u':
		printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c);
		break;
	case 'o':
		printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c);
		break;
	default:
		printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c);
		break;
	}
	return;
}
#endif
//=========================================================================================
// 47��-03.1���� �迭
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ColSize 2

void inputData(char[ColSize], int, int);
void printData(char[ColSize], int, int);
int main(void) {
	// -------�Է�-���� ����------------------------------
	char c[ColSize];
	int i, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	i = 0;
	CSize = ColSize;
	inputData(c, i, CSize);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(c, i, CSize);
	return 0;
}
void inputData(char c[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("���ڸ� �Է��Ͻÿ� : ");
		scanf(" %c", &c[i]);
	}
	return;
}
void printData(char c[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		switch (c[i]) {
		case 'a':
			printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c[i]);
			break;
		case 'e':
			printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c[i]);
			break;
		case 'i':
			printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c[i]);
			break;
		case 'u':
			printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c[i]);
			break;
		case 'o':
			printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c[i]);
			break;
		default:
			printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c[i]);
			break;
		}

	}
	return;
}
#endif
//=========================================================================================
// 47��-04.1���� ������
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define ColSize 2

void inputData(char*, int, int);
void printData(char*, int, int);
int main(void) {
	// -------�Է�-���� ����------------------------------
	char* c;
	int i, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	c = (char*)malloc(sizeof(char) * ColSize);
	i = 0;
	CSize = ColSize;
	inputData(c, i, CSize);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(c, i, CSize);
	free(c);
	return 0;
}
void inputData(char* c, int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("���ڸ� �Է��Ͻÿ� : ");
		//scanf(" %c", &*(c+i));
		scanf(" %c", (c + i));
	}
	return;
}
void printData(char* c, int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		switch (c[i]) {
		case 'a':
			printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", *(c + i));
			break;
		case 'e':
			printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", *(c + i));
			break;
		case 'i':
			printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", *(c + i));
			break;
		case 'u':
			printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", *(c + i));
			break;
		case 'o':
			printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", *(c + i));
			break;
		default:
			printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", *(c + i));
			break;
		}

	}
	return;
}
#endif
//=========================================================================================
// 47��-05.2���� �迭
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define RowSize 1
#define ColSize 2

void inputData(char[RowSize][ColSize], int, int, int, int);
void printData(char[RowSize][ColSize], int, int, int, int);
int main(void) {
	// -------�Է�-���� ����------------------------------
	char c[RowSize][ColSize];
	int i, j, RSize, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(c, i, j, RSize, CSize);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(c, i, j, RSize, CSize);
	return 0;
}
void inputData(char c[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("���ڸ� �Է��Ͻÿ� : ");
			scanf(" %c", &c[i][j]);
		}
	}
	return;
}
void printData(char c[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			switch (c[i][j]) {
			case 'a':
				printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c[i][j]);
				break;
			case 'e':
				printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c[i][j]);
				break;
			case 'i':
				printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c[i][j]);
				break;
			case 'u':
				printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c[i][j]);
				break;
			case 'o':
				printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c[i][j]);
				break;
			default:
				printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", c[i][j]);
				break;
			}
		}
	}
	return;
}
#endif
//=========================================================================================
// 47��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define RowSize 1
#define ColSize 2

void inputData(char* [RowSize], int, int, int, int);
void printData(char* [RowSize], int, int, int, int);
int main(void) {
	// -------�Է�-���� ����------------------------------
	char* c[RowSize];
	int i, j, RSize, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	for (i = 0; i < RowSize; i++)
	{
		c[i] = (char*)malloc(sizeof(char) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(c, i, j, RSize, CSize);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(c, i, j, RSize, CSize);
	for (i = 0; i < RSize; i++)
	{
		free(c[i]);
	}
	return 0;
}
void inputData(char* c[RowSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("���ڸ� �Է��Ͻÿ� : ");
			//scanf(" %c", &c[i][j]);
			//scanf(" %c", &(c[i][j]));
			//scanf(" %c", &(*(c[i]+j)));
			//scanf(" %c", (c[i] + j));
			scanf(" %c", (*(c + i) + j));
		}
	}
	return;
}
void printData(char* c[RowSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			switch (c[i][j]) {
			case 'a':
				printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", *(*(c + i) + j));
				break;
			case 'e':
				printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", *(*(c + i) + j));
				break;
			case 'i':
				printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", *(*(c + i) + j));
				break;
			case 'u':
				printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", *(*(c + i) + j));
				break;
			case 'o':
				printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", *(*(c + i) + j));
				break;
			default:
				printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", *(*(c + i) + j));
				break;
			}
		}
	}
	return;
}
#endif
//=========================================================================================
// 47��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 47��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define RowSize 1
#define ColSize 2

void inputData(char**, int, int, int, int);
void printData(char**, int, int, int, int);
int main(void) {
	// -------�Է�-���� ����------------------------------
	char** c;
	int i, j, RSize, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	c = (char**)malloc(sizeof(char*) * RowSize);
	for (i = 0; i < RowSize; i++)
	{
		c[i] = (char*)malloc(sizeof(char) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(c, i, j, RSize, CSize);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(c, i, j, RSize, CSize);
	for (i = 0; i < RSize; i++)
	{
		free(c[i]);
	}
	free(c);
	return 0;
}
void inputData(char** c, int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("���ڸ� �Է��Ͻÿ� : ");
			//scanf(" %c", &c[i][j]);
			//scanf(" %c", &(c[i][j]));
			//scanf(" %c", &(*(c[i]+j)));
			//scanf(" %c", (c[i] + j));
			scanf(" %c", (*(c + i) + j));
		}
	}
	return;
}
void printData(char** c, int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			switch (c[i][j]) {
			case 'a':
				printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", *(*(c + i) + j));
				break;
			case 'e':
				printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", *(*(c + i) + j));
				break;
			case 'i':
				printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", *(*(c + i) + j));
				break;
			case 'u':
				printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", *(*(c + i) + j));
				break;
			case 'o':
				printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", *(*(c + i) + j));
				break;
			default:
				printf("�Էµ� ���� %c��(��) �����Դϴ�. \n", *(*(c + i) + j));
				break;
			}
		}
	}
	return;
}
#endif










//=========================================================================================
// 48��. ���� - switch case��
//=========================================================================================
// 48��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	char command;
	int x, y;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// ����� ���� �޴��� �ۼ��Ͻÿ�.
	printf("=====�޴�===== \n");
	printf("+ : ���ϱ� \n");
	printf("- : ���� \n");
	printf("* : ���ϱ� \n");
	printf("/ : ������ \n");
	printf("=====�޴�===== \n");

	printf("�޴����� �����ڸ� �����Ͻÿ� : ");
	scanf(" %c", &command);

	printf("�ǿ����ڸ� �Է��Ͻÿ� : ");
	scanf("%d%d", &x, &y);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	switch (command) {
	case '+':
		printf("������ ��� : %d \n", x + y);	break;
	case '-':
		printf("������ ��� : %d \n", x - y);	break;
	case '*':
		printf("������ ��� : %d \n", x * y);	break;
	case '/':
		printf("������ ��� : %d \n", x / y);	break;
	default:
		printf("�������� �ʴ� �������Դϴ�. \n"); break;
	}
}
#endif

//=========================================================================================
// 48��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printData(int, int, char);

int main(void) {
	// -------�Է�-���� ����------------------------------
	char command;
	int x, y;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// ����� ���� �޴��� �ۼ��Ͻÿ�.
	printf("=====�޴�===== \n");
	printf("+ : ���ϱ� \n");
	printf("- : ���� \n");
	printf("* : ���ϱ� \n");
	printf("/ : ������ \n");
	printf("=====�޴�===== \n");

	printf("�޴����� �����ڸ� �����Ͻÿ� : ");
	scanf(" %c", &command);

	printf("�ǿ����ڸ� �Է��Ͻÿ� : ");
	scanf("%d%d", &x, &y);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, y, command);

}

void printData(int x, int y, char command)
{
	switch (command) {
	case '+':
		printf("������ ��� : %d \n", x + y);	break;
	case '-':
		printf("������ ��� : %d \n", x - y);	break;
	case '*':
		printf("������ ��� : %d \n", x * y);	break;
	case '/':
		printf("������ ��� : %d \n", x / y);	break;
	default:
		printf("�������� �ʴ� �������Դϴ�. \n"); break;
	}
}
#endif
// case 2. call-by-address
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void inputData(int*, int*, char*);
void printData(int*, int*, char*);

int main(void) {
	// -------�Է�-���� ����------------------------------
	char command;
	int x, y;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// ����� ���� �޴��� �ۼ��Ͻÿ�.
	inputData(&x, &y, &command);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(&x, &y, &command);

}
void inputData(int* x, int* y, char* command)
{
	printf("=====�޴�===== \n");
	printf("+ : ���ϱ� \n");
	printf("- : ���� \n");
	printf("* : ���ϱ� \n");
	printf("/ : ������ \n");
	printf("=====�޴�===== \n");

	printf("�޴����� �����ڸ� �����Ͻÿ� : ");
	scanf(" %c", command);

	printf("�ǿ����ڸ� �Է��Ͻÿ� : ");
	scanf("%d%d", x, y);
}
void printData(int* x, int* y, char* command)
{
	switch (*command) {
	case '+':
		printf("������ ��� : %d \n", *x + *y);	break;
	case '-':
		printf("������ ��� : %d \n", *x - *y);	break;
	case '*':
		printf("������ ��� : %d \n", *x * *y);	break;
	case '/':
		printf("������ ��� : %d \n", *x / *y);	break;
	default:
		printf("�������� �ʴ� �������Դϴ�. \n"); break;
	}
}
#endif
// case 3. call-by-reference
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void inputData(int&, int&, char&);
void printData(int&, int&, char&);

int main(void) {
	// -------�Է�-���� ����------------------------------
	char command;
	int x, y;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// ����� ���� �޴��� �ۼ��Ͻÿ�.
	inputData(x, y, command);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, y, command);

}
void inputData(int& x, int& y, char& command)
{
	printf("=====�޴�===== \n");
	printf("+ : ���ϱ� \n");
	printf("- : ���� \n");
	printf("* : ���ϱ� \n");
	printf("/ : ������ \n");
	printf("=====�޴�===== \n");

	printf("�޴����� �����ڸ� �����Ͻÿ� : ");
	scanf(" %c", &command);

	printf("�ǿ����ڸ� �Է��Ͻÿ� : ");
	scanf("%d%d", &x, &y);
}
void printData(int& x, int& y, char& command)
{
	switch (command) {
	case '+':
		printf("������ ��� : %d \n", x + y);	break;
	case '-':
		printf("������ ��� : %d \n", x - y);	break;
	case '*':
		printf("������ ��� : %d \n", x * y);	break;
	case '/':
		printf("������ ��� : %d \n", x / y);	break;
	default:
		printf("�������� �ʴ� �������Դϴ�. \n"); break;
	}
}
#endif
//=========================================================================================
// 48��-03.1���� �迭
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ColSize 2
void inputData(int[ColSize], char&, int, int);
void printData(int[ColSize], char&, int, int);

int main(void) {
	// -------�Է�-���� ����------------------------------
	char command;
	int x[ColSize];
	int i, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// ����� ���� �޴��� �ۼ��Ͻÿ�.
	i = 0;
	CSize = ColSize;
	inputData(x, command, i, CSize);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, command, i, CSize);

}
void inputData(int x[ColSize], char& command, int i, int CSize)
{
	printf("=====�޴�===== \n");
	printf("+ : ���ϱ� \n");
	printf("- : ���� \n");
	printf("* : ���ϱ� \n");
	printf("/ : ������ \n");
	printf("=====�޴�===== \n");

	printf("�޴����� �����ڸ� �����Ͻÿ� : ");
	scanf(" %c", &command);

	printf("�ǿ����ڸ� �Է��Ͻÿ� : ");
	for (i = 0; i < CSize; i++)
	{
		scanf("%d", &x[i]);
	}
}
void printData(int x[ColSize], char& command, int i, int CSize)
{
	switch (command) {
	case '+':
		printf("������ ��� : %d \n", x[0] + x[1]);	break;
	case '-':
		printf("������ ��� : %d \n", x[0] - x[1]);	break;
	case '*':
		printf("������ ��� : %d \n", x[0] * x[1]);	break;
	case '/':
		printf("������ ��� : %d \n", x[0] / x[1]);	break;
	default:
		printf("�������� �ʴ� �������Դϴ�. \n"); break;
	}
}
#endif
//=========================================================================================
// 48��-04.1���� ������
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define ColSize 2
void inputData(int*, char*, int, int);
void printData(int*, char*, int, int);

int main(void) {
	// -------�Է�-���� ����------------------------------
	char command;
	int* x;
	int i, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// ����� ���� �޴��� �ۼ��Ͻÿ�.
	x = (int*)malloc(sizeof(int) * ColSize);
	i = 0;
	CSize = ColSize;
	inputData(x, &command, i, CSize);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, &command, i, CSize);
	free(x);
}
void inputData(int* x, char* command, int i, int CSize)
{
	printf("=====�޴�===== \n");
	printf("+ : ���ϱ� \n");
	printf("- : ���� \n");
	printf("* : ���ϱ� \n");
	printf("/ : ������ \n");
	printf("=====�޴�===== \n");

	printf("�޴����� �����ڸ� �����Ͻÿ� : ");
	scanf(" %c", command);

	printf("�ǿ����ڸ� �Է��Ͻÿ� : ");
	for (i = 0; i < CSize; i++)
	{
		scanf("%d", &(*(x + i)));
	}
}
void printData(int* x, char* command, int i, int CSize)
{
	switch (*command) {
	case '+':
		printf("������ ��� : %d \n", *(x + 0) + *(x + 1));	break;
	case '-':
		printf("������ ��� : %d \n", *(x + 0) - *(x + 1));	break;
	case '*':
		printf("������ ��� : %d \n", *(x + 0) * *(x + 1));	break;
	case '/':
		printf("������ ��� : %d \n", *(x + 0) / *(x + 1));	break;
	default:
		printf("�������� �ʴ� �������Դϴ�. \n"); break;
	}
}
#endif
//=========================================================================================
// 48��-05.2���� �迭
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define RowSize 1
#define ColSize 2
void inputData(int[RowSize][ColSize], char&, int, int, int, int);
void printData(int[RowSize][ColSize], char&, int, int, int, int);

int main(void) {
	// -------�Է�-���� ����------------------------------
	char command;
	int x[RowSize][ColSize];
	int i, CSize, j, RSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// ����� ���� �޴��� �ۼ��Ͻÿ�.
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(x, command, i, j, RSize, CSize);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, command, i, j, RSize, CSize);

}
void inputData(int x[RowSize][ColSize], char& command, int i, int j, int RSize, int CSize)
{
	printf("=====�޴�===== \n");
	printf("+ : ���ϱ� \n");
	printf("- : ���� \n");
	printf("* : ���ϱ� \n");
	printf("/ : ������ \n");
	printf("=====�޴�===== \n");

	printf("�޴����� �����ڸ� �����Ͻÿ� : ");
	scanf(" %c", &command);


	for (i = 0; i < RSize; i++)
	{

		for (j = 0; j < CSize; j++)
		{
			printf("�ǿ����ڸ� �Է��Ͻÿ� : ");
			//scanf("%d", &x[i][j]);
			//scanf("%d", &(x[i][j]));
			//scanf("%d", &(*(x[i]+j)));
			//scanf("%d", &(*(*(x+i) + j)));
			scanf("%d", (*(x + i) + j));
		}

	}
}
void printData(int x[RowSize][ColSize], char& command, int i, int j, int RSize, int CSize)
{
	switch (command) {
	case '+':
		printf("������ ��� : %d \n", x[0][0] + x[0][1]);	break;
	case '-':
		printf("������ ��� : %d \n", x[0][0] - x[0][1]);	break;
	case '*':
		printf("������ ��� : %d \n", x[0][0] * x[0][1]);	break;
	case '/':
		printf("������ ��� : %d \n", x[0][0] / x[0][1]);	break;
	default:
		printf("�������� �ʴ� �������Դϴ�. \n"); break;
	}
}
#endif
//=========================================================================================
// 48��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define RowSize 1
#define ColSize 2

void inputData(int* [RowSize], char&, int, int, int, int);
void printData(int* [RowSize], char&, int, int, int, int);

int main(void) {
	// -------�Է�-���� ����------------------------------
	char command;
	int* x[RowSize];
	int i, CSize, j, RSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// ����� ���� �޴��� �ۼ��Ͻÿ�.
	for (i = 0; i < RowSize; i++)
	{
		x[i] = (int*)malloc(sizeof(int) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(x, command, i, j, RSize, CSize);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, command, i, j, RSize, CSize);

	for (i = 0; i < RowSize; i++)
	{
		free(x[i]);
	}
	return 0;

}
void inputData(int* x[RowSize], char& command, int i, int j, int RSize, int CSize)
{
	printf("=====�޴�===== \n");
	printf("+ : ���ϱ� \n");
	printf("- : ���� \n");
	printf("* : ���ϱ� \n");
	printf("/ : ������ \n");
	printf("=====�޴�===== \n");

	printf("�޴����� �����ڸ� �����Ͻÿ� : ");
	scanf(" %c", &command);


	for (i = 0; i < RSize; i++)
	{

		for (j = 0; j < CSize; j++)
		{
			printf("�ǿ����ڸ� �Է��Ͻÿ� : ");
			scanf("%d", (*(x + i) + j));
		}

	}
}
void printData(int* x[RowSize], char& command, int i, int j, int RSize, int CSize)
{
	switch (command) {
	case '+':
		printf("������ ��� : %d \n", *(*(x + 0) + 0) + *(*(x + 0) + 1));	break;
	case '-':
		printf("������ ��� : %d \n", *(*(x + 0) + 0) - *(*(x + 0) + 1));	break;
	case '*':
		printf("������ ��� : %d \n", *(*(x + 0) + 0) * *(*(x + 0) + 1));	break;
	case '/':
		printf("������ ��� : %d \n", *(*(x + 0) + 0) / *(*(x + 0) + 1));	break;
	default:
		printf("�������� �ʴ� �������Դϴ�. \n"); break;
	}
}
#endif
//=========================================================================================
// 48��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 48��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define RowSize 1
#define ColSize 2

void inputData(int**, char&, int, int, int, int);
void printData(int**, char&, int, int, int, int);

int main(void) {
	// -------�Է�-���� ����------------------------------
	char command;
	int** x;
	int i, CSize, j, RSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	// ����� ���� �޴��� �ۼ��Ͻÿ�.
	x = (int**)malloc(sizeof(int*) * RowSize);
	for (i = 0; i < RowSize; i++)
	{
		x[i] = (int*)malloc(sizeof(int) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(x, command, i, j, RSize, CSize);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, command, i, j, RSize, CSize);

	for (i = 0; i < RowSize; i++)
	{
		free(x[i]);
	}
	free(x);
	return 0;

}
void inputData(int** x, char& command, int i, int j, int RSize, int CSize)
{
	printf("=====�޴�===== \n");
	printf("+ : ���ϱ� \n");
	printf("- : ���� \n");
	printf("* : ���ϱ� \n");
	printf("/ : ������ \n");
	printf("=====�޴�===== \n");

	printf("�޴����� �����ڸ� �����Ͻÿ� : ");
	scanf(" %c", &command);


	for (i = 0; i < RSize; i++)
	{

		for (j = 0; j < CSize; j++)
		{
			printf("�ǿ����ڸ� �Է��Ͻÿ� : ");
			scanf("%d", (*(x + i) + j));
		}

	}
}
void printData(int** x, char& command, int i, int j, int RSize, int CSize)
{
	switch (command) {
	case '+':
		printf("������ ��� : %d \n", *(*(x + 0) + 0) + *(*(x + 0) + 1));	break;
	case '-':
		printf("������ ��� : %d \n", *(*(x + 0) + 0) - *(*(x + 0) + 1));	break;
	case '*':
		printf("������ ��� : %d \n", *(*(x + 0) + 0) * *(*(x + 0) + 1));	break;
	case '/':
		printf("������ ��� : %d \n", *(*(x + 0) + 0) / *(*(x + 0) + 1));	break;
	default:
		printf("�������� �ʴ� �������Դϴ�. \n"); break;
	}
}
#endif











//=========================================================================================
// 49��. ���� - switch case��
//=========================================================================================
// 49��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------�Է�-���� ����------------------------------
	int x, y, sum, diff;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	printf("������ �Է��Ͻÿ� : ");
	scanf("%d", &x);

	printf("������ �Է��Ͻÿ� : ");
	scanf("%d", &y)
		// -------ó��----------------------------------------
		// -------���----------------------------------------
		sum = x + y;

	if (x >= y) {			// x�� y���� ũ�ų� ������ �ǹ���. ���ǹ����� ���ǹ��� ������ ��� {}���� ���� ���� �����.
		diff = x - y;
	}
	else {					// (x < y)�� ���� x�� y���� ������ �ǹ���.
		diff = y - x;
	}

	printf("�� ���� ���� %d�Դϴ�. \n", sum);
	printf("�� ���� ���� %d�Դϴ�. \n", diff);

	return 0;
}
#endif

//=========================================================================================
// 49��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printData(int, int, int, int);
int main(void) {
	// -------�Է�-���� ����------------------------------
	int x, y, sum, diff;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	printf("������ �Է��Ͻÿ� : ");
	scanf("%d", &x);

	printf("������ �Է��Ͻÿ� : ");
	scanf("%d", &y);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, y, diff, sum);

	return 0;
}

void printData(int x, int y, int diff, int sum)
{
	sum = x + y;

	if (x >= y) {			// x�� y���� ũ�ų� ������ �ǹ���. ���ǹ����� ���ǹ��� ������ ��� {}���� ���� ���� �����.
		diff = x - y;
	}
	else {					// (x < y)�� ���� x�� y���� ������ �ǹ���.
		diff = y - x;
	}

	printf("�� ���� ���� %d�Դϴ�. \n", sum);
	printf("�� ���� ���� %d�Դϴ�. \n", diff);
}
#endif
// case 2. call-by-address
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void inputData(int*, int*);
void printData(int*, int*, int*, int*);

int main(void) {
	// -------�Է�-���� ����------------------------------
	int x, y, sum, diff;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	inputData(&x, &y);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(&x, &y, &diff, &sum);

	return 0;
}
void inputData(int* x, int* y)
{
	printf("������ �Է��Ͻÿ� : ");
	scanf("%d", x);

	printf("������ �Է��Ͻÿ� : ");
	scanf("%d", y);
}
void printData(int* x, int* y, int* diff, int* sum)
{
	*sum = *x + *y;

	if (*x >= *y) {			// x�� y���� ũ�ų� ������ �ǹ���. ���ǹ����� ���ǹ��� ������ ��� {}���� ���� ���� �����.
		*diff = *x - *y;
	}
	else {					// (x < y)�� ���� x�� y���� ������ �ǹ���.
		*diff = *y - *x;
	}

	printf("�� ���� ���� %d�Դϴ�. \n", *sum);
	printf("�� ���� ���� %d�Դϴ�. \n", *diff);
}
#endif
// case 3. call-by-reference
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void inputData(int&, int&);
void printData(int&, int&, int&, int&);

int main(void) {
	// -------�Է�-���� ����------------------------------
	int x, y, sum, diff;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	inputData(x, y);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, y, diff, sum);

	return 0;
}
void inputData(int& x, int& y)
{
	printf("������ �Է��Ͻÿ� : ");
	scanf("%d", &x);

	printf("������ �Է��Ͻÿ� : ");
	scanf("%d", &y);
}
void printData(int& x, int& y, int& diff, int& sum)
{
	sum = x + y;

	if (x >= y) {			// x�� y���� ũ�ų� ������ �ǹ���. ���ǹ����� ���ǹ��� ������ ��� {}���� ���� ���� �����.
		diff = x - y;
	}
	else {					// (x < y)�� ���� x�� y���� ������ �ǹ���.
		diff = y - x;
	}

	printf("�� ���� ���� %d�Դϴ�. \n", sum);
	printf("�� ���� ���� %d�Դϴ�. \n", diff);
}
#endif
//=========================================================================================
// 49��-03.1���� �迭
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ColSize 2

void inputData(int[ColSize], int[ColSize], int, int);
void printData(int[ColSize], int[ColSize], int&, int&, int, int);

int main(void) {
	// -------�Է�-���� ����------------------------------
	int x[ColSize], y[ColSize], sum, diff;
	int i, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	i = 0;
	CSize = ColSize;
	inputData(x, y, i, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, y, diff, sum, i, CSize);

	return 0;
}
void inputData(int x[ColSize], int y[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{

		printf("������ �Է��Ͻÿ� : ");
		scanf("%d", &x[i]);

		printf("������ �Է��Ͻÿ� : ");
		scanf("%d", &y[i]);
	}
}
void printData(int x[ColSize], int y[ColSize], int& diff, int& sum, int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		sum = x[i] + y[i];

		if (x[i] >= y[i]) {			// x�� y���� ũ�ų� ������ �ǹ���. ���ǹ����� ���ǹ��� ������ ��� {}���� ���� ���� �����.
			diff = x[i] - y[i];
		}
		else {					// (x < y)�� ���� x�� y���� ������ �ǹ���.
			diff = y[i] - x[i];
		}

		printf("�� ���� ���� %d�Դϴ�. \n", sum);
		printf("�� ���� ���� %d�Դϴ�. \n", diff);
	}
}
#endif
//=========================================================================================
// 49��-04.1���� ������
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define ColSize 2

void inputData(int*, int*, int, int);
void printData(int*, int*, int*, int*, int, int);

int main(void) {
	// -------�Է�-���� ����------------------------------
	int* x, * y, sum, diff;
	int i, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	x = (int*)malloc(sizeof(int) * ColSize);
	y = (int*)malloc(sizeof(int) * ColSize);
	i = 0;
	CSize = ColSize;
	inputData(x, y, i, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, y, &diff, &sum, i, CSize);
	free(x);
	free(y);
	return 0;
}
void inputData(int* x, int* y, int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{

		printf("������ �Է��Ͻÿ� : ");
		scanf("%d", (x + i));

		printf("������ �Է��Ͻÿ� : ");
		scanf("%d", (y + i));
	}
}
void printData(int* x, int* y, int* diff, int* sum, int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		*sum = *(x + i) + *(y + i);

		if (*(x + i) >= *(y + i)) {			// x�� y���� ũ�ų� ������ �ǹ���. ���ǹ����� ���ǹ��� ������ ��� {}���� ���� ���� �����.
			*diff = *(x + i) - *(y + i);
		}
		else {					// (x < y)�� ���� x�� y���� ������ �ǹ���.
			*diff = *(y + i) - *(x + i);
		}

		printf("�� ���� ���� %d�Դϴ�. \n", *sum);
		printf("�� ���� ���� %d�Դϴ�. \n", *diff);
	}
}
#endif
//=========================================================================================
// 49��-05.2���� �迭
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define RowSize 1
#define ColSize 2

void inputData(int[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
void printData(int[RowSize][ColSize], int[RowSize][ColSize], int*, int*, int, int, int, int);

int main(void) {
	// -------�Է�-���� ����------------------------------
	int x[RowSize][ColSize], y[RowSize][ColSize], sum, diff;
	int i, j, RSize, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	inputData(x, y, i, j, RSize, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, y, &diff, &sum, i, j, RSize, CSize);

	return 0;
}
void inputData(int x[RowSize][ColSize], int y[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			/*printf("������ �Է��Ͻÿ� : ");
			scanf("%d", &x[i][j]);

			printf("������ �Է��Ͻÿ� : ");
			scanf("%d", &y[i][j]);*/
			//printf("������ �Է��Ͻÿ� : ");
			//scanf("%d", &(*(x[i]+j)));

			//printf("������ �Է��Ͻÿ� : ");
			//scanf("%d", &(*(y[i]+j)));
			/*printf("������ �Է��Ͻÿ� : ");
			scanf("%d", (x[i] + j));

			printf("������ �Է��Ͻÿ� : ");
			scanf("%d", (y[i] + j));*/
			/*printf("������ �Է��Ͻÿ� : ");
			scanf("%d", &(*(*(x+i) + j)));

			printf("������ �Է��Ͻÿ� : ");
			scanf("%d", &(*(*(y+i) + j)));*/
			printf("������ �Է��Ͻÿ� : ");
			scanf("%d", (*(x + i) + j));

			printf("������ �Է��Ͻÿ� : ");
			scanf("%d", (*(y + i) + j));
		}
	}
}
void printData(int x[RowSize][ColSize], int y[RowSize][ColSize], int* diff, int* sum, int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//*sum = x[i][j] + y[i][j];

			//if (x[i][j] >= y[i][j]) {			// x�� y���� ũ�ų� ������ �ǹ���. ���ǹ����� ���ǹ��� ������ ��� {}���� ���� ���� �����.
			//	*diff = x[i][j] - y[i][j];
			//}
			//else {					// (x < y)�� ���� x�� y���� ������ �ǹ���.
			//	*diff = y[i][j] - x[i][j];
			//}
			//*sum = *(x[i]+j) + *(y[i]+j);

			//if (*(x[i] + j) >= *(y[i] + j)) {			// x�� y���� ũ�ų� ������ �ǹ���. ���ǹ����� ���ǹ��� ������ ��� {}���� ���� ���� �����.
			//	*diff = *(x[i] + j) - *(y[i] + j);
			//}
			//else {					// (x < y)�� ���� x�� y���� ������ �ǹ���.
			//	*diff = *(y[i] + j) - *(x[i] + j);
			//}
			* sum = *(*(x + i) + j) + *(*(y + i) + j);

			if (*(*(x + i) + j) >= *(*(y + i) + j)) {			// x�� y���� ũ�ų� ������ �ǹ���. ���ǹ����� ���ǹ��� ������ ��� {}���� ���� ���� �����.
				*diff = *(*(x + i) + j) - *(*(y + i) + j);
			}
			else {					// (x < y)�� ���� x�� y���� ������ �ǹ���.
				*diff = *(*(y + i) + j) - *(*(x + i) + j);
			}

			printf("�� ���� ���� %d�Դϴ�. \n", *sum);
			printf("�� ���� ���� %d�Դϴ�. \n", *diff);
		}
	}
}
#endif
//=========================================================================================
// 49��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define RowSize 1
#define ColSize 2

void inputData(int* [RowSize], int* [RowSize], int, int, int, int);
void printData(int* [RowSize], int* [RowSize], int*, int*, int, int, int, int);

int main(void) {
	// -------�Է�-���� ����------------------------------
	int* x[RowSize], * y[RowSize], sum, diff;
	int i, j, RSize, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	for (i = 0; i < RowSize; i++)
	{
		x[i] = (int*)malloc(sizeof(int) * ColSize);
		y[i] = (int*)malloc(sizeof(int) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	inputData(x, y, i, j, RSize, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, y, &diff, &sum, i, j, RSize, CSize);

	for (i = 0; i < RowSize; i++)
	{
		free(x[i]);
		free(y[i]);
	}
	return 0;
}
void inputData(int* x[RowSize], int* y[RowSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			/*printf("������ �Է��Ͻÿ� : ");
			scanf("%d", &x[i][j]);

			printf("������ �Է��Ͻÿ� : ");
			scanf("%d", &y[i][j]);*/
			//printf("������ �Է��Ͻÿ� : ");
			//scanf("%d", &(*(x[i]+j)));

			//printf("������ �Է��Ͻÿ� : ");
			//scanf("%d", &(*(y[i]+j)));
			/*printf("������ �Է��Ͻÿ� : ");
			scanf("%d", (x[i] + j));

			printf("������ �Է��Ͻÿ� : ");
			scanf("%d", (y[i] + j));*/
			/*printf("������ �Է��Ͻÿ� : ");
			scanf("%d", &(*(*(x+i) + j)));

			printf("������ �Է��Ͻÿ� : ");
			scanf("%d", &(*(*(y+i) + j)));*/
			printf("������ �Է��Ͻÿ� : ");
			scanf("%d", (*(x + i) + j));

			printf("������ �Է��Ͻÿ� : ");
			scanf("%d", (*(y + i) + j));
		}
	}
}
void printData(int* x[RowSize], int* y[RowSize], int* diff, int* sum, int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//*sum = x[i][j] + y[i][j];

			//if (x[i][j] >= y[i][j]) {			// x�� y���� ũ�ų� ������ �ǹ���. ���ǹ����� ���ǹ��� ������ ��� {}���� ���� ���� �����.
			//	*diff = x[i][j] - y[i][j];
			//}
			//else {					// (x < y)�� ���� x�� y���� ������ �ǹ���.
			//	*diff = y[i][j] - x[i][j];
			//}
			//*sum = *(x[i]+j) + *(y[i]+j);

			//if (*(x[i] + j) >= *(y[i] + j)) {			// x�� y���� ũ�ų� ������ �ǹ���. ���ǹ����� ���ǹ��� ������ ��� {}���� ���� ���� �����.
			//	*diff = *(x[i] + j) - *(y[i] + j);
			//}
			//else {					// (x < y)�� ���� x�� y���� ������ �ǹ���.
			//	*diff = *(y[i] + j) - *(x[i] + j);
			//}
			* sum = *(*(x + i) + j) + *(*(y + i) + j);

			if (*(*(x + i) + j) >= *(*(y + i) + j)) {			// x�� y���� ũ�ų� ������ �ǹ���. ���ǹ����� ���ǹ��� ������ ��� {}���� ���� ���� �����.
				*diff = *(*(x + i) + j) - *(*(y + i) + j);
			}
			else {					// (x < y)�� ���� x�� y���� ������ �ǹ���.
				*diff = *(*(y + i) + j) - *(*(x + i) + j);
			}

			printf("�� ���� ���� %d�Դϴ�. \n", *sum);
			printf("�� ���� ���� %d�Դϴ�. \n", *diff);
		}
	}
}
#endif
//=========================================================================================
// 49��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 49��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define RowSize 1
#define ColSize 2

void inputData(int**, int**, int, int, int, int);
void printData(int**, int**, int*, int*, int, int, int, int);

int main(void) {
	// -------�Է�-���� ����------------------------------
	int** x, ** y, sum, diff;
	int i, j, RSize, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	x = (int**)malloc(sizeof(int*) * RowSize);
	y = (int**)malloc(sizeof(int*) * RowSize);
	for (i = 0; i < RowSize; i++)
	{
		x[i] = (int*)malloc(sizeof(int) * ColSize);
		y[i] = (int*)malloc(sizeof(int) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	inputData(x, y, i, j, RSize, CSize);

	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, y, &diff, &sum, i, j, RSize, CSize);

	for (i = 0; i < RowSize; i++)
	{
		free(x[i]);
		free(y[i]);
	}
	free(x);
	free(y);
	return 0;
}
void inputData(int** x, int** y, int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			/*printf("������ �Է��Ͻÿ� : ");
			scanf("%d", &x[i][j]);

			printf("������ �Է��Ͻÿ� : ");
			scanf("%d", &y[i][j]);*/
			//printf("������ �Է��Ͻÿ� : ");
			//scanf("%d", &(*(x[i]+j)));

			//printf("������ �Է��Ͻÿ� : ");
			//scanf("%d", &(*(y[i]+j)));
			/*printf("������ �Է��Ͻÿ� : ");
			scanf("%d", (x[i] + j));

			printf("������ �Է��Ͻÿ� : ");
			scanf("%d", (y[i] + j));*/
			/*printf("������ �Է��Ͻÿ� : ");
			scanf("%d", &(*(*(x+i) + j)));

			printf("������ �Է��Ͻÿ� : ");
			scanf("%d", &(*(*(y+i) + j)));*/
			printf("������ �Է��Ͻÿ� : ");
			scanf("%d", (*(x + i) + j));

			printf("������ �Է��Ͻÿ� : ");
			scanf("%d", (*(y + i) + j));
		}
	}
}
void printData(int** x, int** y, int* diff, int* sum, int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//*sum = x[i][j] + y[i][j];

			//if (x[i][j] >= y[i][j]) {			// x�� y���� ũ�ų� ������ �ǹ���. ���ǹ����� ���ǹ��� ������ ��� {}���� ���� ���� �����.
			//	*diff = x[i][j] - y[i][j];
			//}
			//else {					// (x < y)�� ���� x�� y���� ������ �ǹ���.
			//	*diff = y[i][j] - x[i][j];
			//}
			//*sum = *(x[i]+j) + *(y[i]+j);

			//if (*(x[i] + j) >= *(y[i] + j)) {			// x�� y���� ũ�ų� ������ �ǹ���. ���ǹ����� ���ǹ��� ������ ��� {}���� ���� ���� �����.
			//	*diff = *(x[i] + j) - *(y[i] + j);
			//}
			//else {					// (x < y)�� ���� x�� y���� ������ �ǹ���.
			//	*diff = *(y[i] + j) - *(x[i] + j);
			//}
			* sum = *(*(x + i) + j) + *(*(y + i) + j);

			if (*(*(x + i) + j) >= *(*(y + i) + j)) {			// x�� y���� ũ�ų� ������ �ǹ���. ���ǹ����� ���ǹ��� ������ ��� {}���� ���� ���� �����.
				*diff = *(*(x + i) + j) - *(*(y + i) + j);
			}
			else {					// (x < y)�� ���� x�� y���� ������ �ǹ���.
				*diff = *(*(y + i) + j) - *(*(x + i) + j);
			}

			printf("�� ���� ���� %d�Դϴ�. \n", *sum);
			printf("�� ���� ���� %d�Դϴ�. \n", *diff);
		}
	}
}
#endif











//=========================================================================================
// 50��. ���� - switch case��
//=========================================================================================
// 50��-00. �⺻ �ڵ�
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	// -------�Է�-���� ����------------------------------
	double x, y, result;
	int op;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	printf("�� �Ǽ� �Է�: ");
	scanf("%lf%lf", &x, &y);
	printf("�������� ��ȣ���� 1(+), 2(-), 3(*), 4(/): ");
	scanf("%d", &op);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	if (op == 1)
		printf("������ �ְ� ����� �л��Դϴ�.\n");
	else if (op == 2)
		printf("������ �ſ� ����� �л��Դϴ�.\n");
	else if (op == 3)
		printf("������ ����� �л��Դϴ�.\n");
	else if (op == 4)
		printf("������ ����� �л��Դϴ�.\n");
	else
		printf("������ ����� �л��Դϴ�.\n");


	switch (op) {
	case 1:
		printf("%.2f + %.2f = %.2f\n", x, y, x + y);
		break;

	case 2:
		printf("%.2f - %.2f = %.2f\n", x, y, x - y);
		break;

	case 3:
		printf("%.2f * %.2f = %.2f\n", x, y, x * y);
		break;

	case 4:
		printf("%.2f / %.2f = %.2f\n", x, y, x / y);
		break;

	default:
		printf("��ȣ�� �߸� �����߽��ϴ�.\n");
	}

	return 0;
}
#endif

//=========================================================================================
// 50��-02. �Լ� ��ȯ
//=========================================================================================
// case 1. call-by-value
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void printData(double, double, int);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	double x, y, result;
	int op;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	printf("�� �Ǽ� �Է�: ");
	scanf("%lf%lf", &x, &y);
	printf("�������� ��ȣ���� 1(+), 2(-), 3(*), 4(/): ");
	scanf("%d", &op);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, y, op);

	return 0;
}


void printData(double x, double y, int op)
{
	if (op == 1)
		printf("������ �ְ� ����� �л��Դϴ�.\n");
	else if (op == 2)
		printf("������ �ſ� ����� �л��Դϴ�.\n");
	else if (op == 3)
		printf("������ ����� �л��Դϴ�.\n");
	else if (op == 4)
		printf("������ ����� �л��Դϴ�.\n");
	else
		printf("������ ����� �л��Դϴ�.\n");


	switch (op) {
	case 1:
		printf("%.2f + %.2f = %.2f\n", x, y, x + y);
		break;

	case 2:
		printf("%.2f - %.2f = %.2f\n", x, y, x - y);
		break;

	case 3:
		printf("%.2f * %.2f = %.2f\n", x, y, x * y);
		break;

	case 4:
		printf("%.2f / %.2f = %.2f\n", x, y, x / y);
		break;

	default:
		printf("��ȣ�� �߸� �����߽��ϴ�.\n");
	}

}
#endif
// case 2. call-by-address
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void inputData(double*, double*, int*);
void printData(double*, double*, int*);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	double x, y, result;
	int op;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	inputData(&x, &y, &op);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(&x, &y, &op);


	return 0;
}
void inputData(double* x, double* y, int* op)
{

	printf("�� �Ǽ� �Է�: ");
	scanf("%lf%lf", *(&x), *(&y));
	printf("�������� ��ȣ���� 1(+), 2(-), 3(*), 4(/): ");
	scanf("%d", *(&op));

}

void printData(double* x, double* y, int* op)
{
	if (*op == 1)
		printf("������ �ְ� ����� �л��Դϴ�.\n");
	else if (*op == 2)
		printf("������ �ſ� ����� �л��Դϴ�.\n");
	else if (*op == 3)
		printf("������ ����� �л��Դϴ�.\n");
	else if (*op == 4)
		printf("������ ����� �л��Դϴ�.\n");
	else
		printf("������ ����� �л��Դϴ�.\n");


	switch (*op) {
	case 1:
		printf("%.2f + %.2f = %.2f\n", *x, *y, *x + *y);
		break;

	case 2:
		printf("%.2f - %.2f = %.2f\n", *x, *y, *x - *y);
		break;

	case 3:
		printf("%.2f * %.2f = %.2f\n", *x, *y, *x * *y);
		break;

	case 4:
		printf("%.2f / %.2f = %.2f\n", *x, *y, *x / *y);
		break;

	default:
		printf("��ȣ�� �߸� �����߽��ϴ�.\n");
	}

}
#endif
// case 3. call-by-reference
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void inputData(double&, double&, int&);
void printData(double&, double&, int&);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	double x, y, result;
	int op;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	inputData(x, y, op);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, y, op);


	return 0;
}
void inputData(double& x, double& y, int& op)
{

	printf("�� �Ǽ� �Է�: ");
	scanf("%lf%lf", &x, &y);
	printf("�������� ��ȣ���� 1(+), 2(-), 3(*), 4(/): ");
	scanf("%d", &op);

}

void printData(double& x, double& y, int& op)
{
	if (op == 1)
		printf("������ �ְ� ����� �л��Դϴ�.\n");
	else if (op == 2)
		printf("������ �ſ� ����� �л��Դϴ�.\n");
	else if (op == 3)
		printf("������ ����� �л��Դϴ�.\n");
	else if (op == 4)
		printf("������ ����� �л��Դϴ�.\n");
	else
		printf("������ ����� �л��Դϴ�.\n");


	switch (op) {
	case 1:
		printf("%.2f + %.2f = %.2f\n", x, y, x + y);
		break;

	case 2:
		printf("%.2f - %.2f = %.2f\n", x, y, x - y);
		break;

	case 3:
		printf("%.2f * %.2f = %.2f\n", x, y, x * y);
		break;

	case 4:
		printf("%.2f / %.2f = %.2f\n", x, y, x / y);
		break;

	default:
		printf("��ȣ�� �߸� �����߽��ϴ�.\n");
	}

}
#endif
//=========================================================================================
// 50��-03.1���� �迭
//=========================================================================================

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ColSize 2

void inputData(double[ColSize], int&, int, int);
void printData(double[ColSize], int&, int, int);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	double x[ColSize];
	int op;
	int i, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	i = 0;
	CSize = ColSize;
	inputData(x, op, i, CSize);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, op, i, CSize);


	return 0;
}
void inputData(double x[ColSize], int& op, int i, int CSize)
{
	printf("�� �Ǽ� �Է�: ");
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &x[i]);
	}
	printf("�������� ��ȣ���� 1(+), 2(-), 3(*), 4(/): ");
	scanf("%d", &op);

}

void printData(double x[ColSize], int& op, int i, int CSize)
{
	if (op == 1)
		printf("������ �ְ� ����� �л��Դϴ�.\n");
	else if (op == 2)
		printf("������ �ſ� ����� �л��Դϴ�.\n");
	else if (op == 3)
		printf("������ ����� �л��Դϴ�.\n");
	else if (op == 4)
		printf("������ ����� �л��Դϴ�.\n");
	else
		printf("������ ����� �л��Դϴ�.\n");

	switch (op) {
	case 1:
		printf("%.2f + %.2f = %.2f\n", x[0], x[1], x[0] + x[1]);
		break;

	case 2:
		printf("%.2f - %.2f = %.2f\n", x[0], x[1], x[0] - x[1]);
		break;

	case 3:
		printf("%.2f * %.2f = %.2f\n", x[0], x[1], x[0] * x[1]);
		break;

	case 4:
		printf("%.2f / %.2f = %.2f\n", x[0], x[1], x[0] / x[1]);
		break;

	default:
		printf("��ȣ�� �߸� �����߽��ϴ�.\n");
	}

}
#endif
//=========================================================================================
// 50��-04.1���� ������
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define ColSize 2

void inputData(double*, int*, int, int);
void printData(double*, int*, int, int);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	double* x;
	int op;
	int i, CSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	x = (double*)malloc(sizeof(double) * ColSize);

	i = 0;
	CSize = ColSize;
	inputData(x, &op, i, CSize);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, &op, i, CSize);

	free(x);

	return 0;
}
void inputData(double* x, int* op, int i, int CSize)
{
	printf("�� �Ǽ� �Է�: ");
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &x[i]);
	}
	printf("�������� ��ȣ���� 1(+), 2(-), 3(*), 4(/): ");
	scanf("%d", op);

}

void printData(double x[ColSize], int* op, int i, int CSize)
{
	if (*op == 1)
		printf("������ �ְ� ����� �л��Դϴ�.\n");
	else if (*op == 2)
		printf("������ �ſ� ����� �л��Դϴ�.\n");
	else if (*op == 3)
		printf("������ ����� �л��Դϴ�.\n");
	else if (*op == 4)
		printf("������ ����� �л��Դϴ�.\n");
	else
		printf("������ ����� �л��Դϴ�.\n");

	switch (*op) {
	case 1:
		printf("%.2f + %.2f = %.2f\n", x[0], x[1], x[0] + x[1]);
		break;

	case 2:
		printf("%.2f - %.2f = %.2f\n", x[0], x[1], x[0] - x[1]);
		break;

	case 3:
		printf("%.2f * %.2f = %.2f\n", x[0], x[1], x[0] * x[1]);
		break;

	case 4:
		printf("%.2f / %.2f = %.2f\n", x[0], x[1], x[0] / x[1]);
		break;

	default:
		printf("��ȣ�� �߸� �����߽��ϴ�.\n");
	}

}
#endif
//=========================================================================================
// 50��-05.2���� �迭
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define RowSize 1
#define ColSize 2

void inputData(double x[RowSize][ColSize], int& op, int i, int j, int RSize, int CSize);
void printData(double x[RowSize][ColSize], int& op, int i, int j, int RSize, int CSize);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	double x[RowSize][ColSize];
	int op;
	int i, j, CSize, RSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(x, op, i, j, RSize, CSize);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, op, i, j, RSize, CSize);


	return 0;
}
void inputData(double x[RowSize][ColSize], int& op, int i, int j, int RSize, int CSize)
{
	printf("�� �Ǽ� �Է�: ");
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//scanf("%lf", &x[i][j]);
			//scanf("%lf", &(x[i][j]));
			//scanf("%lf", &(*(x[i]+j)));
			//scanf("%lf", (x[i] + j));
			//scanf("%lf", &(*(*(x+i)+j)));
			scanf("%lf", (*(x + i) + j));

		}
	}
	printf("�������� ��ȣ���� 1(+), 2(-), 3(*), 4(/): ");
	scanf("%d", &op);
}

void printData(double x[RowSize][ColSize], int& op, int i, int j, int RSize, int CSize)
{
	if (op == 1)
		printf("������ �ְ� ����� �л��Դϴ�.\n");
	else if (op == 2)
		printf("������ �ſ� ����� �л��Դϴ�.\n");
	else if (op == 3)
		printf("������ ����� �л��Դϴ�.\n");
	else if (op == 4)
		printf("������ ����� �л��Դϴ�.\n");
	else
		printf("������ ����� �л��Դϴ�.\n");

	/*switch (op) {
	case 1:
		printf("%.2f + %.2f = %.2f\n", x[0][0], x[0][1], x[0][0] + x[0][1]);
		break;

	case 2:
		printf("%.2f - %.2f = %.2f\n", x[0][0], x[0][1], x[0][0] - x[0][1]);
		break;

	case 3:
		printf("%.2f * %.2f = %.2f\n", x[0][0], x[0][1], x[0][0] * x[0][1]);
		break;

	case 4:
		printf("%.2f / %.2f = %.2f\n", x[0][0], x[0][1], x[0][0] / x[0][1]);
		break;

	default:
		printf("��ȣ�� �߸� �����߽��ϴ�.\n");
	}
*/
/*switch (op) {
case 1:
	printf("%.2f + %.2f = %.2f\n", *(x[0] + 0), *(x[0] + 1), *(x[0] + 0) + *(x[0] + 1));
	break;

case 2:
	printf("%.2f - %.2f = %.2f\n", *(x[0] + 0), *(x[0] + 1), *(x[0] + 0) - *(x[0] + 1));
	break;

case 3:
	printf("%.2f * %.2f = %.2f\n", *(x[0] + 0), *(x[0] + 1), *(x[0] + 0) * *(x[0] + 1));
	break;

case 4:
	printf("%.2f / %.2f = %.2f\n", *(x[0] + 0), *(x[0] + 1), *(x[0] + 0) / *(x[0] + 1));
	break;

default:
	printf("��ȣ�� �߸� �����߽��ϴ�.\n");
}*/
	switch (op) {
	case 1:
		printf("%.2f + %.2f = %.2f\n", *(*(x + 0) + 0), *(*(x + 0) + 1), *(*(x + 0) + 0) + *(*(x + 0) + 1));
		break;

	case 2:
		printf("%.2f - %.2f = %.2f\n", *(*(x + 0) + 0), *(*(x + 0) + 1), *(*(x + 0) + 0) - *(*(x + 0) + 1));
		break;

	case 3:
		printf("%.2f * %.2f = %.2f\n", *(*(x + 0) + 0), *(*(x + 0) + 1), *(*(x + 0) + 0) * *(*(x + 0) + 1));
		break;

	case 4:
		printf("%.2f / %.2f = %.2f\n", *(*(x + 0) + 0), *(*(x + 0) + 1), *(*(x + 0) + 0) / *(*(x + 0) + 1));
		break;

	default:
		printf("��ȣ�� �߸� �����߽��ϴ�.\n");
	}
}
#endif
//=========================================================================================
// 50��-06. 2���� �迭- �����͹迭 ��ȯ
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define RowSize 1
#define ColSize 2

void inputData(double* [RowSize], int&, int, int, int, int);
void printData(double* [RowSize], int&, int, int, int, int);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	double* x[RowSize];
	int op;
	int i, j, CSize, RSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	for (i = 0; i < RowSize; i++)
	{
		x[i] = (double*)malloc(sizeof(double) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(x, op, i, j, RSize, CSize);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, op, i, j, RSize, CSize);

	for (i = 0; i < RowSize; i++)
	{
		free(x[i]);
	}
	return 0;
}
void inputData(double* x[RowSize], int& op, int i, int j, int RSize, int CSize)
{
	printf("�� �Ǽ� �Է�: ");
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//scanf("%lf", &x[i][j]);
			//scanf("%lf", &(x[i][j]));
			//scanf("%lf", &(*(x[i]+j)));
			//scanf("%lf", (x[i] + j));
			//scanf("%lf", &(*(*(x+i)+j)));
			scanf("%lf", (*(x + i) + j));

		}
	}
	printf("�������� ��ȣ���� 1(+), 2(-), 3(*), 4(/): ");
	scanf("%d", &op);
}

void printData(double* x[RowSize], int& op, int i, int j, int RSize, int CSize)
{
	if (op == 1)
		printf("������ �ְ� ����� �л��Դϴ�.\n");
	else if (op == 2)
		printf("������ �ſ� ����� �л��Դϴ�.\n");
	else if (op == 3)
		printf("������ ����� �л��Դϴ�.\n");
	else if (op == 4)
		printf("������ ����� �л��Դϴ�.\n");
	else
		printf("������ ����� �л��Դϴ�.\n");

	/*switch (op) {
	case 1:
		printf("%.2f + %.2f = %.2f\n", x[0][0], x[0][1], x[0][0] + x[0][1]);
		break;

	case 2:
		printf("%.2f - %.2f = %.2f\n", x[0][0], x[0][1], x[0][0] - x[0][1]);
		break;

	case 3:
		printf("%.2f * %.2f = %.2f\n", x[0][0], x[0][1], x[0][0] * x[0][1]);
		break;

	case 4:
		printf("%.2f / %.2f = %.2f\n", x[0][0], x[0][1], x[0][0] / x[0][1]);
		break;

	default:
		printf("��ȣ�� �߸� �����߽��ϴ�.\n");
	}*/
	/*switch (op) {
	case 1:
		printf("%.2f + %.2f = %.2f\n", *(x[0] + 0), *(x[0] + 1), *(x[0] + 0) + *(x[0] + 1));
		break;

	case 2:
		printf("%.2f - %.2f = %.2f\n", *(x[0] + 0), *(x[0] + 1), *(x[0] + 0) - *(x[0] + 1));
		break;

	case 3:
		printf("%.2f * %.2f = %.2f\n", *(x[0] + 0), *(x[0] + 1), *(x[0] + 0) * *(x[0] + 1));
		break;

	case 4:
		printf("%.2f / %.2f = %.2f\n", *(x[0] + 0), *(x[0] + 1), *(x[0] + 0) / *(x[0] + 1));
		break;

	default:
		printf("��ȣ�� �߸� �����߽��ϴ�.\n");
	}*/
	switch (op) {
	case 1:
		printf("%.2f + %.2f = %.2f\n", *(*(x + 0) + 0), *(*(x + 0) + 1), *(*(x + 0) + 0) + *(*(x + 0) + 1));
		break;

	case 2:
		printf("%.2f - %.2f = %.2f\n", *(*(x + 0) + 0), *(*(x + 0) + 1), *(*(x + 0) + 0) - *(*(x + 0) + 1));
		break;

	case 3:
		printf("%.2f * %.2f = %.2f\n", *(*(x + 0) + 0), *(*(x + 0) + 1), *(*(x + 0) + 0) * *(*(x + 0) + 1));
		break;

	case 4:
		printf("%.2f / %.2f = %.2f\n", *(*(x + 0) + 0), *(*(x + 0) + 1), *(*(x + 0) + 0) / *(*(x + 0) + 1));
		break;

	default:
		printf("��ȣ�� �߸� �����߽��ϴ�.\n");
	}
}
#endif
//=========================================================================================
// 50��-07. 2���� �迭- �迭 ������ ��ȯ
//=========================================================================================

//=========================================================================================
// 50��-08. 2���� �迭- ���� ������ ��ȯ
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define RowSize 1
#define ColSize 2

void inputData(double**, int&, int, int, int, int);
void printData(double**, int&, int, int, int, int);

int main(void)
{
	// -------�Է�-���� ����------------------------------
	double** x;
	int op;
	int i, j, CSize, RSize;
	// -------�Է�-���� �ʱ�ȭ----------------------------
	x = (double**)malloc(sizeof(double*) * RowSize);
	for (i = 0; i < RowSize; i++)
	{
		x[i] = (double*)malloc(sizeof(double) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(x, op, i, j, RSize, CSize);
	// -------ó��----------------------------------------
	// -------���----------------------------------------
	printData(x, op, i, j, RSize, CSize);

	for (i = 0; i < RowSize; i++)
	{
		free(x[i]);
	}
	free(x);
	return 0;
}
void inputData(double** x, int& op, int i, int j, int RSize, int CSize)
{
	printf("�� �Ǽ� �Է�: ");
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//scanf("%lf", &x[i][j]);
			//scanf("%lf", &(x[i][j]));
			//scanf("%lf", &(*(x[i]+j)));
			//scanf("%lf", (x[i] + j));
			//scanf("%lf", &(*(*(x+i)+j)));
			scanf("%lf", (*(x + i) + j));

		}
	}
	printf("�������� ��ȣ���� 1(+), 2(-), 3(*), 4(/): ");
	scanf("%d", &op);
}

void printData(double** x, int& op, int i, int j, int RSize, int CSize)
{
	if (op == 1)
		printf("������ �ְ� ����� �л��Դϴ�.\n");
	else if (op == 2)
		printf("������ �ſ� ����� �л��Դϴ�.\n");
	else if (op == 3)
		printf("������ ����� �л��Դϴ�.\n");
	else if (op == 4)
		printf("������ ����� �л��Դϴ�.\n");
	else
		printf("������ ����� �л��Դϴ�.\n");

	/*switch (op) {
	case 1:
		printf("%.2f + %.2f = %.2f\n", x[0][0], x[0][1], x[0][0] + x[0][1]);
		break;

	case 2:
		printf("%.2f - %.2f = %.2f\n", x[0][0], x[0][1], x[0][0] - x[0][1]);
		break;

	case 3:
		printf("%.2f * %.2f = %.2f\n", x[0][0], x[0][1], x[0][0] * x[0][1]);
		break;

	case 4:
		printf("%.2f / %.2f = %.2f\n", x[0][0], x[0][1], x[0][0] / x[0][1]);
		break;

	default:
		printf("��ȣ�� �߸� �����߽��ϴ�.\n");
	}*/
	/*switch (op) {
	case 1:
		printf("%.2f + %.2f = %.2f\n", *(x[0] + 0), *(x[0] + 1), *(x[0] + 0) + *(x[0] + 1));
		break;

	case 2:
		printf("%.2f - %.2f = %.2f\n", *(x[0] + 0), *(x[0] + 1), *(x[0] + 0) - *(x[0] + 1));
		break;

	case 3:
		printf("%.2f * %.2f = %.2f\n", *(x[0] + 0), *(x[0] + 1), *(x[0] + 0) * *(x[0] + 1));
		break;

	case 4:
		printf("%.2f / %.2f = %.2f\n", *(x[0] + 0), *(x[0] + 1), *(x[0] + 0) / *(x[0] + 1));
		break;

	default:
		printf("��ȣ�� �߸� �����߽��ϴ�.\n");
	}*/
	switch (op) {
	case 1:
		printf("%.2f + %.2f = %.2f\n", *(*(x + 0) + 0), *(*(x + 0) + 1), *(*(x + 0) + 0) + *(*(x + 0) + 1));
		break;

	case 2:
		printf("%.2f - %.2f = %.2f\n", *(*(x + 0) + 0), *(*(x + 0) + 1), *(*(x + 0) + 0) - *(*(x + 0) + 1));
		break;

	case 3:
		printf("%.2f * %.2f = %.2f\n", *(*(x + 0) + 0), *(*(x + 0) + 1), *(*(x + 0) + 0) * *(*(x + 0) + 1));
		break;

	case 4:
		printf("%.2f / %.2f = %.2f\n", *(*(x + 0) + 0), *(*(x + 0) + 1), *(*(x + 0) + 0) / *(*(x + 0) + 1));
		break;

	default:
		printf("��ȣ�� �߸� �����߽��ϴ�.\n");
	}
}
#endif