

//=========================================================================================
//  01번. 문자 상수의 표현과 출력
//=========================================================================================
// 01번-00. 기본 코드
//=========================================================================================
#if 0
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	puts("문자 상수의 표현과 출력");
	printf("%C ", 'B');		// 형식지정문자는 대문자 소문자 구별없이 사용
	printf("%c", '\n');

	return 0;
}
#endif

//=========================================================================================
// 01번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	char a1, a2;
	// -------입력-변수 초기화----------------------------

	scanf(" %c %c", &a1, &a2);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	puts("문자 상수의 표현과 출력");
	printf("%c ", a1);		// 형식지정문자는 대문자 소문자 구별없이 사용
	printf("%c", a2);

	return 0;
}
#endif

// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 01번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value
#if 0
#include <stdio.h>
void printData(char, char);
int main(void) {
	// -------입력-변수 선언------------------------------
	char a1, a2;
	// -------입력-변수 초기화----------------------------

	scanf(" %c %c", &a1, &a2);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(a1, a2);
	return 0;
}

void printData(char a1, char a2)
{
	puts("문자 상수의 표현과 출력");
	printf("%c ", a1);		// 형식지정문자는 대문자 소문자 구별없이 사용
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
	// -------입력-변수 선언------------------------------
	char a1, a2;
	// -------입력-변수 초기화----------------------------
	inputData(&a1, &a2);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
	puts("문자 상수의 표현과 출력");
	printf("%c ", *a1);		// 형식지정문자는 대문자 소문자 구별없이 사용
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
	// -------입력-변수 선언------------------------------
	char a1, a2;
	// -------입력-변수 초기화----------------------------
	inputData(a1, a2);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
	puts("문자 상수의 표현과 출력");
	printf("%c ", a1);		// 형식지정문자는 대문자 소문자 구별없이 사용
	printf("%c", a2);
	return;
}
#endif
//=========================================================================================
// 01번-03.1차원 배열
//=========================================================================================
#if 0
#include <stdio.h>
#define ColSize 2               // 2 
void inputData(char[ColSize], int, int);      //12
void printData(char[ColSize], int, int);      //13   
int main(void) {
	// -------입력-변수 선언------------------------------
	char a[ColSize];            // 1
	int i, CSize;               // 3
	// -------입력-변수 초기화----------------------------
	i = 0;                  // 4
	CSize = ColSize;
	inputData(a, i, CSize);            // 5

	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(a, i, CSize);           // 6

	return 0;
}
void inputData(char a[ColSize], int i, int CSize)   //7
{
	for (i = 0; i < CSize; i++)            //9 for타이핑하고 나서 바로 탭키 누르면 자동완성
	{
		scanf(" %c", &a[i]);          //10
	}
	return;
}
void printData(char a[ColSize], int i, int CSize)   // 8
{
	puts("문자 상수의 표현과 출력");
	for (i = 0; i < CSize; i++)            //11
	{
		printf("%c ", a[i]);
	}
	return;
}
#endif

//=========================================================================================
// 01번-04.1차원 포인터
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define ColSize 2
void inputData(char*, int, int);
void printData(char*, int, int);

int main(void) {
	// -------입력-변수 선언------------------------------
	char* a;
	int i, CSize;
	// -------입력-변수 초기화----------------------------
	a = (char*)malloc(sizeof(char) * ColSize);
	i = 0;
	CSize = ColSize;
	inputData(a, i, CSize);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
	puts("문자 상수의 표현과 출력");
	for (i = 0; i < CSize; i++)
	{
		//printf("%c", a[i]);
		printf("%c", *(a + i));
	}
	return;
}
#endif

//=========================================================================================
// 01번-05.2차원 배열
//=========================================================================================
#if 0
#include <stdio.h>
#define RowSize 1
#define ColSize 2
void inputData(char[RowSize][ColSize], int, int, int, int);
void printData(char[RowSize][ColSize], int, int, int, int);

int main(void) {
	// -------입력-변수 선언------------------------------
	char a[RowSize][ColSize];
	int i, j, RSize, CSize;

	// -------입력-변수 초기화----------------------------
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(a, i, j, RSize, CSize);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
	puts("문자 상수의 표현과 출력");
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
// 01번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define RowSize 1
#define ColSize 2
void inputData(char* [RowSize], int, int, int, int);
void printData(char* [RowSize], int, int, int, int);

int main(void) {
	// -------입력-변수 선언------------------------------
	char* a[RowSize];
	int i, j, RSize, CSize;

	// -------입력-변수 초기화----------------------------
	for (i = 0; i < RowSize; i++)
	{
		a[i] = (char*)malloc(sizeof(char) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(a, i, j, RSize, CSize);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
	puts("문자 상수의 표현과 출력");
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
// 01번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 01번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define RowSize 1
#define ColSize 2
void inputData(char**, int, int, int, int);
void printData(char**, int, int, int, int);

int main(void) {
	// -------입력-변수 선언------------------------------
	char** a;
	int i, j, RSize, CSize;

	// -------입력-변수 초기화----------------------------
	a = (char**)malloc(sizeof(char*) * RowSize);
	for (i = 0; i < RowSize; i++)
	{
		a[i] = (char*)malloc(sizeof(char) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(a, i, j, RSize, CSize);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
	puts("문자 상수의 표현과 출력");
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
// 01번-09. 구조체 함수 변환
//=========================================================================================
// 01번-09-1. call-by-value
//=========================================================================================
// case 1. 구조체와 typdef을 분리하여 선언한 경우 
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
	puts("문자 상소의 표현과 출력");
	printf("%c", x.a1);
	printf("%c", (&x)->a2);
	return x;
}
#endif

//-----------------------------------------------------------------------------------------
// case 2. 구조체와 typdef을 결합하여  선언한 경우
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
	puts("정수 상수의 표현과 출력");
	printf("%c", x.a1);
	printf("%c", (&x)->a2);
	return x;
}

int main(void) {
	// -------입력-변수 선언------------------------------
	SData x;
	// -------입력-변수 초기화----------------------------
	x.a1 = '0';
	(&x)->a2 = '0';

	x = x.inputData(x);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
	x = x.printData(x);
	return 0;
}

#endif
//=========================================================================================
// 01번-09-3. call-by-reference
//=========================================================================================
// case 1. 함수의 반환값을 Call by reference 방식으로 반환하는 경우 
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
	// -------입력-변수 선언------------------------------
	SData x;
	// -------입력-변수 초기화----------------------------
	x = inputData(x);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
	puts("문자 상수의 표현과 출력");
	printf("%c", x.a1);
	printf("%c", (&x)->a2);
	return x;
}
#endif

//=========================================================================================
// 01번-09-2. call-by-address
//=========================================================================================
// case 1. 함수의 반환값을 call by address로 반환하는 경우 
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
	// -------입력-변수 선언------------------------------
	SData x;
	// -------입력-변수 초기화----------------------------
	x = *(inputData(&x));

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
	puts("문자 상수의 표현과 출력");
	printf("%c", (*x).a1);
	printf("%c", x->a2);
	return x;
}
#endif

//=========================================================================================
// 01번-10. 구조체 1차원 배열
//=========================================================================================
// case 1. 함수의 반환값을 call by value로 반환하는 경우 
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
	// -------입력-변수 선언------------------------------
	SData x[ColSize];
	int i, CSize;
	// -------입력변수 초기화----------------------------
	i = 0;
	CSize = ColSize;
	*x = inputData(x, i, CSize);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
	puts("문자 상수의 표현과 출력");
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
// 01번-11. 구조체 1차원 배열 - 포인터 변환
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
	// -------입력-변수 선언------------------------------
	SData* x;
	int i, CSize;

	// -------입력-변수 초기화----------------------------
	x = (SData*)malloc(sizeof(SData) * ColSize);
	i = 0;
	CSize = ColSize;

	*x = *(inputData(x, i, CSize));
	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
	puts("문자 상수의 표현과 출력");
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
// 01번-12. 구조체 2차원 배열
//=========================================================================================
// case 1. 함수의 반환값을 call by value로 반환하는 경우 
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
	// -------입력-변수 선언------------------------------
	SData x[RowSize][ColSize];
	int i, j, RSize, CSize;

	// -------입력-변수 초기화----------------------------
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	**x = *(inputData(x, i, j, RSize, CSize));
	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
	puts("문자 상수의 표현과 출력");
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
// 01번-13. 구조체 2차원 배열 - 포인터 배열 변환
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
	// -------입력-변수 선언------------------------------
	SData* x[RowSize];
	int i, j, RSize, CSize;

	// -------입력-변수 초기화----------------------------
	for (i = 0; i < RowSize; i++)
	{
		x[i] = (SData*)malloc(sizeof(SData) * ColSize);
	}

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	//**x = *(inputData(x, i, j, RSize, CSize));
	*x = inputData(x, i, j, RSize, CSize);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
	puts("문자 상수의 표현과 출력");
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
// 01번-15. 구조체 2차원 배열 - 이중 포인터 변환
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
	// -------입력-변수 선언------------------------------
	SData** x;
	int i, j, RSize, CSize;
	// -------입력-변수 초기화----------------------------
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

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
	puts("문자 상수의 표현과 출력");
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
// 02번. 정수 상수와 실수 상수의 표현과 출력
//=========================================================================================
// 02번-00. 기본 코드
//=========================================================================================
#if 0
#include <stdio.h>
int main(void)
{
	// -------입력-변수 선언------------------------------
	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("정수 상수의 표현과 출력\n");
	printf("%d ", 30);
	printf("%d ", 030);
	printf("%d ", 0X2F);

	printf("실수 상수의 표현과 출력\n");
	printf("%lf ", 3.14);
	printf("%lf ", 3.14);
	printf("%lf ", 3.14);

	return 0;
}
#endif

//=========================================================================================
// 02번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#include <stdio.h>
int main(void)
{
	// -------입력-변수 선언------------------------------
	int x1, x2, x3;
	double y1, y2, y3;

	// -------입력-변수 초기화----------------------------
	scanf("%d%d%d", &x1, &x2, &x3);
	scanf("%lf%lf%lf", &y1, &y2, &y3);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("정수 상수의 표현과 출력\n");
	printf("%d ", x1);
	printf("%d ", x2);
	printf("%d ", x3);

	printf("실수 상수의 표현과 출력\n");
	printf("%lf ", y1);
	printf("%lf ", y2);
	printf("%lf ", y3);

	return 0;
}
#endif

// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 02번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value
#if 0
#include <stdio.h>

void printData(int, int, int, double, double, double);

int main(void)
{
	// -------입력-변수 선언------------------------------
	int x1, x2, x3;
	double y1, y2, y3;

	// -------입력-변수 초기화----------------------------
	scanf("%d%d%d", &x1, &x2, &x3);
	scanf("%lf%lf%lf", &y1, &y2, &y3);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(x1, x2, x3, y1, y2, y3);
	return 0;
}

void printData(int x1, int x2, int x3, double y1, double y2, double y3)
{
	printf("정수 상수의 표현과 출력\n");
	printf("%d ", x1);
	printf("%d ", x2);
	printf("%d ", x3);

	printf("실수 상수의 표현과 출력\n");
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
	// -------입력-변수 선언------------------------------
	int x1, x2, x3;
	double y1, y2, y3;

	// -------입력-변수 초기화----------------------------
	inputData(&x1, &x2, &x3, &y1, &y2, &y3);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
	printf("정수 상수의 표현과 출력\n");
	printf("%d ", *x1);
	printf("%d ", *x2);
	printf("%d ", *x3);

	printf("실수 상수의 표현과 출력\n");
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
	// -------입력-변수 선언------------------------------
	int x1, x2, x3;
	double y1, y2, y3;

	// -------입력-변수 초기화----------------------------
	inputData(x1, x2, x3, y1, y2, y3);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
	printf("정수 상수의 표현과 출력\n");
	printf("%d ", x1);
	printf("%d ", x2);
	printf("%d ", x3);

	printf("실수 상수의 표현과 출력\n");
	printf("%lf ", y1);
	printf("%lf ", y2);
	printf("%lf ", y3);
	return;
}
#endif
//=========================================================================================
// 02번-03.1차원 배열
//=========================================================================================
#if 0
#include <stdio.h>
#define ColSize 3

void inputData(int[ColSize], double[ColSize], int, int);
void printData(int[ColSize], double[ColSize], int, int);
int main(void)
{
	// -------입력-변수 선언------------------------------
	int x[ColSize];
	double y[ColSize];
	int i, CSize;

	// -------입력-변수 초기화----------------------------
	i = 0;
	CSize = ColSize;
	inputData(x, y, i, CSize);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
	printf("정수 상수의 표현과 출력\n");
	for (i = 0; i < CSize; i++)
	{
		printf("%d ", x[i]);
	}

	printf("실수 상수의 표현과 출력\n");
	for (i = 0; i < CSize; i++)
	{
		printf("%lf ", y[i]);
	}
	return;
}
#endif
//=========================================================================================
// 02번-04.1차원 포인터
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define ColSize 3

void inputData(int*, double*, int, int);
void printData(int*, double*, int, int);
int main(void)
{
	// -------입력-변수 선언------------------------------
	int* x;
	double* y;
	int i, CSize;

	// -------입력-변수 초기화----------------------------
	x = (int*)malloc(sizeof(int) * ColSize);
	y = (double*)malloc(sizeof(double) * ColSize);
	i = 0;
	CSize = ColSize;
	inputData(x, y, i, CSize);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(x, y, i, CSize);
	free(y); // 순서 어떻게 하나? 
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
	printf("정수 상수의 표현과 출력\n");
	for (i = 0; i < CSize; i++)
	{
		printf("%d ", *(x + i));
	}

	printf("실수 상수의 표현과 출력\n");
	for (i = 0; i < CSize; i++)
	{
		printf("%lf ", *(y + i));
	}
	return;
}
#endif
//=========================================================================================
// 02번-05.2차원 배열
//=========================================================================================
#if 0
#include <stdio.h>
#define RowSize 1
#define ColSize 3

void inputData(int[RowSize][ColSize], double[RowSize][ColSize], int, int, int, int);
void printData(int[RowSize][ColSize], double[RowSize][ColSize], int, int, int, int);
int main(void)
{
	// -------입력-변수 선언------------------------------
	int x[RowSize][ColSize];
	double y[RowSize][ColSize];
	int i, j, RSize, CSize;

	// -------입력-변수 초기화----------------------------
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(x, y, i, j, RSize, CSize);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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

	printf("정수 상수의 표현과 출력\n");
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("%d ", *(*(x + i) + j));
		}
	}
	puts("");
	printf("실수 상수의 표현과 출력\n");
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
// 02번-06. 2차원 배열- 포인터배열 변환
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
	// -------입력-변수 선언------------------------------
	int* x[RowSize];
	double* y[RowSize];
	int i, j, RSize, CSize;

	// -------입력-변수 초기화----------------------------
	for (i = 0; i < RowSize; i++)
	{
		x[i] = (int*)malloc(sizeof(int) * ColSize);
		y[i] = (double*)malloc(sizeof(double) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(x, y, i, j, RSize, CSize);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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

	printf("정수 상수의 표현과 출력\n");
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("%d ", *(*(x + i) + j));
		}
	}
	puts("");
	printf("실수 상수의 표현과 출력\n");
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
// 02번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 02번-08. 2차원 배열- 이중 포인터 변환
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
	// -------입력-변수 선언------------------------------
	int** x;
	double** y;
	int i, j, RSize, CSize;

	// -------입력-변수 초기화----------------------------
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

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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

	printf("정수 상수의 표현과 출력\n");
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("%d ", *(*(x + i) + j));
		}
	}
	puts("");
	printf("실수 상수의 표현과 출력\n");
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
//  03번. 변수
//=========================================================================================
// 03번-00. 기본 코드
//=========================================================================================
#if 0
#include <stdio.h>
int main(void)
{
	// -------입력-변수 선언------------------------------
	int age;
	// -------입력-변수 초기화----------------------------
	age = 20;
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("%d\n", age);

	age = 21;			// 변수는 마지막에 할당한 값만 유지됨 기존의 20이라는 값이 21로 변경됨
	printf("%d\n", age);

	return 0;
}
#endif

//=========================================================================================
// 03번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#include <stdio.h>
int main(void)
{
	// -------입력-변수 선언------------------------------
	int age;
	// -------입력-변수 초기화----------------------------
	scanf("%d", &age);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("%d\n", age);

	scanf("%d", &age);	// 변수는 마지막에 할당한 값만 유지됨 기존의 20이라는 값이 21로 변경됨
	printf("%d\n", age);

	return 0;
}
#endif

// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 03번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value
#if 0
#include <stdio.h>

void printData(int);

int main(void)
{
	// -------입력-변수 선언------------------------------
	int age;
	// -------입력-변수 초기화----------------------------
	scanf("%d", &age);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(age);

	scanf("%d", &age);	// 변수는 마지막에 할당한 값만 유지됨 기존의 20이라는 값이 21로 변경됨
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
	// -------입력-변수 선언------------------------------
	int age;
	// -------입력-변수 초기화----------------------------
	inputData(&age);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
	// -------입력-변수 선언------------------------------
	int age;
	// -------입력-변수 초기화----------------------------
	inputData(age);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(age);

	scanf("%d", &age);	// 변수는 마지막에 할당한 값만 유지됨 기존의 20이라는 값이 21로 변경됨
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
// 03번-03.1차원 배열
//=========================================================================================
#if 0
#include <stdio.h>
#define ColSize 2
void inputData(int[ColSize], int, int);
void printData(int[ColSize], int, int);

int main(void)
{
	// -------입력-변수 선언------------------------------
	int age[ColSize];
	int i, CSize;
	// -------입력-변수 초기화----------------------------
	i = 0;
	CSize = ColSize;
	inputData(age, i, CSize);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
// 03번-04.1차원 포인터
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define ColSize 2

void inputData(int*, int, int);
void printData(int*, int, int);

int main(void)
{
	// -------입력-변수 선언------------------------------
	int* age;
	int i, CSize;
	// -------입력-변수 초기화----------------------------
	age = (int*)malloc(sizeof(char) * ColSize);
	i = 0;
	CSize = ColSize;
	inputData(age, i, CSize);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
// 03번-05.2차원 배열
//=========================================================================================
#if 0
#include <stdio.h>
#define RowSize 1
#define ColSize 2
void inputData(int[RowSize][ColSize], int, int, int, int);
void printData(int[RowSize][ColSize], int, int, int, int);

int main(void)
{
	// -------입력-변수 선언------------------------------
	int age[RowSize][ColSize];
	int i, j, RSize, CSize;
	// -------입력-변수 초기화----------------------------
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(age, i, j, RSize, CSize);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
// 03번-06. 2차원 배열- 포인터배열 변환
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
	// -------입력-변수 선언------------------------------
	int* age[RowSize];
	int i, j, RSize, CSize;
	// -------입력-변수 초기화----------------------------
	for (i = 0; i < RowSize; i++)
	{
		age[i] = (int*)malloc(sizeof(char) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(age, i, j, RSize, CSize);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
// 03번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 03번-08. 2차원 배열- 이중 포인터 변환
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
	// -------입력-변수 선언------------------------------
	int** age;
	int i, j, RSize, CSize;
	// -------입력-변수 초기화----------------------------
	age = (int**)malloc(sizeof(char*) * RowSize);
	for (i = 0; i < RowSize; i++)
	{
		age[i] = (int*)malloc(sizeof(char) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(age, i, j, RSize, CSize);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
// 04번. 변수
//=========================================================================================
// 04번-00. 기본 코드
//=========================================================================================
#if 0
#include <stdio.h>
int main(void)
{
	// -------입력-변수 선언------------------------------
	int year = 1972; //변수 선언과 초기화를 한꺼번에 형태(축약된 형태)
	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("C 언어는 %d년도에 개발되었다.\n", year);

	return 0;
}
#endif

//=========================================================================================
// 04번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#include <stdio.h>
int main(void)
{
	// -------입력-변수 선언------------------------------
	int year = 1972; //변수 선언과 초기화를 한꺼번에 형태(축약된 형태)

	// -------입력-변수 초기화----------------------------
	scanf("%d", &year);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("C 언어는 %d년도에 개발되었다.\n", year);

	return 0;
}
#endif
// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 04번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value
#if 0
#include <stdio.h>

void printData(int);

int main(void)
{
	// -------입력-변수 선언------------------------------
	int year;

	// -------입력-변수 초기화----------------------------
	scanf("%d", &year);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(year);


	return 0;
}

void printData(int year) {
	printf("C 언어는 %d년도에 개발되었다.\n", year);
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
	// -------입력-변수 선언------------------------------
	int year;

	// -------입력-변수 초기화----------------------------
	inputData(&year);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(&year);


	return 0;
}
void inputData(int* year) {
	scanf("%d", *(&year));
	return;
}
void printData(int* year) {
	printf("C 언어는 %d년도에 개발되었다.\n", *year);
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
	// -------입력-변수 선언------------------------------
	int year;

	// -------입력-변수 초기화----------------------------
	inputData(year);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(year);


	return 0;
}
void inputData(int& year) {
	scanf("%d", &year);
	return;
}
void printData(int& year) {
	printf("C 언어는 %d년도에 개발되었다.\n", year);
	return;
}
#endif
//=========================================================================================
// 04번-03.1차원 배열
//=========================================================================================
#if 0
#include <stdio.h>
#define ColSize 2

void inputData(int[ColSize], int, int);
void printData(int[ColSize], int, int);

int main(void)
{
	// -------입력-변수 선언------------------------------
	int year[ColSize];
	int i, CSize;

	// -------입력-변수 초기화----------------------------
	i = 0;
	CSize = ColSize;
	inputData(year, i, CSize);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
		printf("C 언어는 %d년도에 개발되었다.\n", year[i]);
	}
	return;
}
#endif
//=========================================================================================
// 04번-04.1차원 포인터
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define ColSize 2

void inputData(int*, int, int);
void printData(int*, int, int);

int main(void)
{
	// -------입력-변수 선언------------------------------
	int* year;
	int i, CSize;

	// -------입력-변수 초기화----------------------------
	year = (int*)malloc(sizeof(int) * ColSize);
	i = 0;
	CSize = ColSize;
	inputData(year, i, CSize);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
		printf("C 언어는 %d년도에 개발되었다.\n", *(year + i));
	}
	return;
}
#endif
//=========================================================================================
// 04번-05.2차원 배열
//=========================================================================================
#if 0
#include <stdio.h>
#define RowSize 1
#define ColSize 2

void inputData(int[RowSize][ColSize], int, int, int, int);
void printData(int[RowSize][ColSize], int, int, int, int);

int main(void)
{
	// -------입력-변수 선언------------------------------
	int year[RowSize][ColSize];
	int i, j, RSize, CSize;

	// -------입력-변수 초기화----------------------------
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(year, i, j, RSize, CSize);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(year, i, j, RSize, CSize);
	return 0;
}
void inputData(int year[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			//scanf("%d", &year[i][j]); // 배열
			//scanf("%d", &(*(year[i]+j))); // 포인터 배열
			//scanf("%d", (year[i]+j)); // 포인터배열
			//scanf("%d", &(*(*(year+i) + j)));  // 이중 포인터
			scanf("%d", (*(year + i) + j)); // 이중 포인터


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
			//printf("C 언어는 %d년도에 개발되었다.\n", year[i][j]);
			//printf("C 언어는 %d년도에 개발되었다.\n", *(year[i]+j));
			printf("C 언어는 %d년도에 개발되었다.\n", *(*(year + i) + j));
		}
	}
	return;
}
#endif
//=========================================================================================
// 04번-06. 2차원 배열- 포인터배열 변환
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
	// -------입력-변수 선언------------------------------
	int* year[RowSize];
	int i, j, RSize, CSize;

	// -------입력-변수 초기화----------------------------
	for (i = 0; i < RowSize; i++)
	{
		year[i] = (int*)malloc(sizeof(char) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(year, i, j, RSize, CSize);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
			//scanf("%d", &year[i][j]); // 배열
			//scanf("%d", &(*(year[i]+j))); // 포인터 배열
			//scanf("%d", (year[i]+j)); // 포인터배열
			//scanf("%d", &(*(*(year+i) + j)));  // 이중 포인터
			scanf("%d", (*(year + i) + j)); // 이중 포인터


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
			//printf("C 언어는 %d년도에 개발되었다.\n", year[i][j]);
			//printf("C 언어는 %d년도에 개발되었다.\n", *(year[i]+j));
			printf("C 언어는 %d년도에 개발되었다.\n", *(*(year + i) + j));
		}
	}
	return;
}
#endif
//=========================================================================================
// 04번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 04번-08. 2차원 배열- 이중 포인터 변환
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
	// -------입력-변수 선언------------------------------
	int** year;
	int i, j, RSize, CSize;

	// -------입력-변수 초기화----------------------------
	year = (int**)malloc(sizeof(int*) * RowSize);
	for (i = 0; i < RowSize; i++)
	{
		year[i] = (int*)malloc(sizeof(char) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(year, i, j, RSize, CSize);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
			//scanf("%d", &year[i][j]); // 배열
			//scanf("%d", &(*(year[i]+j))); // 포인터 배열
			//scanf("%d", (year[i]+j)); // 포인터배열
			//scanf("%d", &(*(*(year+i) + j)));  // 이중 포인터
			scanf("%d", (*(year + i) + j)); // 이중 포인터


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
			//printf("C 언어는 %d년도에 개발되었다.\n", year[i][j]);
			//printf("C 언어는 %d년도에 개발되었다.\n", *(year[i]+j));
			printf("C 언어는 %d년도에 개발되었다.\n", *(*(year + i) + j));
		}
	}
	return;
}
#endif


//=========================================================================================
// 05번. 자료형
//=========================================================================================
// 05번-00. 기본 코드
//=========================================================================================
#if 0
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	short sVar = 32000;							//-32767에서 32767까지
	int   iVar = 2140000000;					//약  21억 정도까지 저장 가능
	long  gVar = -2140000000;					//약 -21억 정도까지 저장 가능

	unsigned short int	usVar = 65000;			//0에서 65535까지 저장 가능
	unsigned int		uiVar = 2140000000;		//약 0에서 42억 정도까지 저장 가능
	unsigned long int	ugVar = 4280000000;		//약 0에서 42억 정도까지 저장 가능

	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("저장 값: %hd %d %ld\n", sVar, iVar, gVar);
	printf("저장 값: %hu %u %lu\n", usVar, uiVar, ugVar);

	return 0;
}
#endif

//=========================================================================================
// 05번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	short sVar;
	int   iVar;
	long  gVar;

	unsigned short int	usVar;
	unsigned int		uiVar;
	unsigned long int	ugVar;

	// -------입력-변수 초기화----------------------------
	scanf("%hd%d%ld", &sVar, &iVar, &gVar);
	scanf("%hu%u%lu", &usVar, &uiVar, &ugVar);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("저장 값: %hd %d %ld\n", sVar, iVar, gVar);
	printf("저장 값: %hu %u %lu\n", usVar, uiVar, ugVar);

	return 0;
}
#endif
// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 05번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value
#if 0
#include <stdio.h>

void printData(short, int, long, unsigned short int, unsigned int, unsigned long int);

int main(void) {
	// -------입력-변수 선언------------------------------
	short sVar;
	int   iVar;
	long  gVar;

	unsigned short int	usVar;
	unsigned int		uiVar;
	unsigned long int	ugVar;

	// -------입력-변수 초기화----------------------------
	scanf("%hd%d%ld", &sVar, &iVar, &gVar);
	scanf("%hu%u%lu", &usVar, &uiVar, &ugVar);

	// -------처리----------------------------------------
	// -------출력----------------------------------------

	printData(sVar, iVar, gVar, usVar, uiVar, ugVar);


	return 0;
}

void printData(short sVar, int  iVar, long gVar, unsigned short int usVar, unsigned int uiVar, unsigned long int ugVar) {
	printf("저장 값: %hd %d %ld\n", sVar, iVar, gVar);
	printf("저장 값: %hu %u %lu\n", usVar, uiVar, ugVar);
	return;
}
#endif
// case 2. call-by-address
#if 0
#include <stdio.h>
void inputData(short*, int*, long*, unsigned short int*, unsigned int*, unsigned long int*);
void printData(short*, int*, long*, unsigned short int*, unsigned int*, unsigned long int*);

int main(void) {
	// -------입력-변수 선언------------------------------
	short sVar;
	int   iVar;
	long  gVar;

	unsigned short int	usVar;
	unsigned int		uiVar;
	unsigned long int	ugVar;

	// -------입력-변수 초기화----------------------------

	inputData(&sVar, &iVar, &gVar, &usVar, &uiVar, &ugVar);

	// -------처리----------------------------------------
	// -------출력----------------------------------------

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
	printf("저장 값: %hd %d %ld\n", *sVar, *iVar, *gVar);
	printf("저장 값: %hu %u %lu\n", *usVar, *uiVar, *ugVar);
	return;
}
#endif
// case 3. call-by-reference
#if 0
#include <stdio.h>
void inputData(short&, int&, long&, unsigned short int&, unsigned int&, unsigned long int&);
void printData(short&, int&, long&, unsigned short int&, unsigned int&, unsigned long int&);

int main(void) {
	// -------입력-변수 선언------------------------------
	short sVar;
	int   iVar;
	long  gVar;

	unsigned short int	usVar;
	unsigned int		uiVar;
	unsigned long int	ugVar;

	// -------입력-변수 초기화----------------------------

	inputData(sVar, iVar, gVar, usVar, uiVar, ugVar);

	// -------처리----------------------------------------
	// -------출력----------------------------------------

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
	printf("저장 값: %hd %d %ld\n", sVar, iVar, gVar);
	printf("저장 값: %hu %u %lu\n", usVar, uiVar, ugVar);
	return;
}
#endif
//=========================================================================================
// 05번-03.1차원 배열
//=========================================================================================
#if 0
#include <stdio.h>
#define ColSize 1

void inputData(short[ColSize], int[ColSize], long[ColSize], unsigned short int[ColSize], unsigned int[ColSize], unsigned long int[ColSize], int, int);
void printData(short[ColSize], int[ColSize], long[ColSize], unsigned short int[ColSize], unsigned int[ColSize], unsigned long int[ColSize], int, int);

int main(void) {
	// -------입력-변수 선언------------------------------
	short sVar[ColSize];
	int   iVar[ColSize];
	long  gVar[ColSize];

	unsigned short int	usVar[ColSize];
	unsigned int		uiVar[ColSize];
	unsigned long int	ugVar[ColSize];

	int i, CSize;
	// -------입력-변수 초기화----------------------------
	i = 0;
	CSize = ColSize;

	inputData(sVar, iVar, gVar, usVar, uiVar, ugVar, i, CSize);

	// -------처리----------------------------------------
	// -------출력----------------------------------------

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
		printf("저장 값: %hd %d %ld\n", sVar[i], iVar[i], gVar[i]);
		printf("저장 값: %hu %u %lu\n", usVar[i], uiVar[i], ugVar[i]);
	}
	return;
}
#endif
//=========================================================================================
// 05번-04.1차원 포인터
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
	// -------입력-변수 선언------------------------------
	short* sVar;
	int* iVar;
	long* gVar;

	unsigned short int* usVar;
	unsigned int* uiVar;
	unsigned long int* ugVar;

	int i, CSize;
	// -------입력-변수 초기화----------------------------
	sVar = (short*)malloc(sizeof(short) * ColSize);
	iVar = (int*)malloc(sizeof(int) * ColSize);
	gVar = (long*)malloc(sizeof(long) * ColSize);
	usVar = (unsigned short int*)malloc(sizeof(unsigned short int) * ColSize);
	uiVar = (unsigned int*)malloc(sizeof(unsigned int) * ColSize);
	ugVar = (unsigned long int*)malloc(sizeof(unsigned long int) * ColSize);

	i = 0;
	CSize = ColSize;

	inputData(sVar, iVar, gVar, usVar, uiVar, ugVar, i, CSize);

	// -------처리----------------------------------------
	// -------출력----------------------------------------

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
		printf("저장 값: %hd %d %ld\n", *(sVar + i), *(iVar + i), *(gVar + i));
		printf("저장 값: %hu %u %lu\n", *(usVar + i), *(uiVar + i), *(ugVar + i));
	}
	return;
}
#endif
//=========================================================================================
// 05번-05.2차원 배열
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
	// -------입력-변수 선언------------------------------
	short sVar[RowSize][ColSize];
	int   iVar[RowSize][ColSize];
	long  gVar[RowSize][ColSize];

	unsigned short int	usVar[RowSize][ColSize];
	unsigned int		uiVar[RowSize][ColSize];
	unsigned long int	ugVar[RowSize][ColSize];

	int i, j, RSize, CSize;
	// -------입력-변수 초기화----------------------------
	i = 0;
	RSize = RowSize;
	CSize = ColSize;

	inputData(sVar, iVar, gVar, usVar, uiVar, ugVar, i, j, RSize, CSize);

	// -------처리----------------------------------------
	// -------출력----------------------------------------

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
			//printf("저장 값: %hd %d %ld\n", sVar[i][j], iVar[i][j], gVar[i][j]);
			//printf("저장 값: %hu %u %lu\n", usVar[i][j], uiVar[i][j], ugVar[i][j]);
			/*printf("저장 값: %hd %d %ld\n", *(sVar[i]+j), *(iVar[i]+j), *(gVar[i]+j));
			printf("저장 값: %hu %u %lu\n", *(usVar[i]+j), *(uiVar[i]+j), *(ugVar[i]+j));*/
			printf("저장 값: %hd %d %ld\n", *(*(sVar + i) + j), *(*(iVar + i) + j), *(*(gVar + i) + j));
			printf("저장 값: %hu %u %lu\n", *(*(usVar + i) + j), *(*(uiVar + i) + j), *(*(ugVar + i) + j));
		}
	}
	return;
}
#endif
//=========================================================================================
// 05번-06. 2차원 배열- 포인터배열 변환
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
	// -------입력-변수 선언------------------------------
	short* sVar[RowSize];
	int* iVar[RowSize];
	long* gVar[RowSize];

	unsigned short int* usVar[RowSize];
	unsigned int* uiVar[RowSize];
	unsigned long int* ugVar[RowSize];

	int i, j, RSize, CSize;
	// -------입력-변수 초기화----------------------------
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

	// -------처리----------------------------------------
	// -------출력----------------------------------------

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
			//printf("저장 값: %hd %d %ld\n", sVar[i][j], iVar[i][j], gVar[i][j]);
			//printf("저장 값: %hu %u %lu\n", usVar[i][j], uiVar[i][j], ugVar[i][j]);
			/*printf("저장 값: %hd %d %ld\n", *(sVar[i]+j), *(iVar[i]+j), *(gVar[i]+j));
			printf("저장 값: %hu %u %lu\n", *(usVar[i]+j), *(uiVar[i]+j), *(ugVar[i]+j));*/
			printf("저장 값: %hd %d %ld\n", *(*(sVar + i) + j), *(*(iVar + i) + j), *(*(gVar + i) + j));
			printf("저장 값: %hu %u %lu\n", *(*(usVar + i) + j), *(*(uiVar + i) + j), *(*(ugVar + i) + j));
		}
	}
	return;
}
#endif
//=========================================================================================
// 05번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 05번-08. 2차원 배열- 이중 포인터 변환
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
	// -------입력-변수 선언------------------------------
	short** sVar;
	int** iVar;
	long** gVar;

	unsigned short int** usVar;
	unsigned int** uiVar;
	unsigned long int** ugVar;

	int i, j, RSize, CSize;
	// -------입력-변수 초기화----------------------------
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

	// -------처리----------------------------------------
	// -------출력----------------------------------------

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
			//printf("저장 값: %hd %d %ld\n", sVar[i][j], iVar[i][j], gVar[i][j]);
			//printf("저장 값: %hu %u %lu\n", usVar[i][j], uiVar[i][j], ugVar[i][j]);
			/*printf("저장 값: %hd %d %ld\n", *(sVar[i]+j), *(iVar[i]+j), *(gVar[i]+j));
			printf("저장 값: %hu %u %lu\n", *(usVar[i]+j), *(uiVar[i]+j), *(ugVar[i]+j));*/
			printf("저장 값: %hd %d %ld\n", *(*(sVar + i) + j), *(*(iVar + i) + j), *(*(gVar + i) + j));
			printf("저장 값: %hu %u %lu\n", *(*(usVar + i) + j), *(*(uiVar + i) + j), *(*(ugVar + i) + j));
		}
	}
	return;
}
#endif










//=========================================================================================
// 06번. 자료형
//=========================================================================================
// 06번-00. 기본 코드
//=========================================================================================
#if 0
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	float 		x = 3.14;		//float x = 3.14;인경우, 경고 발생
	double		y = -3.14;	//double 저장공간 크기는 float의 2배	
	long double	z = 3.14;	//double과 long double은 저장공간이 모두 64비트	
	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("저장 값: %f %lf %lf\n", x, y, z);

	return 0;
}
#endif

//=========================================================================================
// 06번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	float 		x;
	double		y;
	long double	z;
	// -------입력-변수 초기화----------------------------
	scanf("%f%lf%lf", &x, &y, &z);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("저장 값: %f %lf %lf\n", x, y, z);

	return 0;
}
#endif
// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 06번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value
#if 0
#include <stdio.h>
void printData(float, double, long double);

int main(void) {
	// -------입력-변수 선언------------------------------
	float 		x;
	double		y;
	long double	z;
	// -------입력-변수 초기화----------------------------
	scanf("%f%lf%lf", &x, &y, &z);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(x, y, z);


	return 0;
}

void printData(float x, double y, long double z)
{
	printf("저장 값: %f %lf %lf\n", x, y, z);
	return;
}

#endif
// case 2. call-by-address

#if 0
#include <stdio.h>

void inputData(float*, double*, long double*);
void printData(float*, double*, long double*);

int main(void) {
	// -------입력-변수 선언------------------------------
	float 		x;
	double		y;
	long double	z;
	// -------입력-변수 초기화----------------------------
	inputData(&x, &y, &z);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
	printf("저장 값: %f %lf %lf\n", *x, *y, *z);
	return;
}

#endif

// case 3. call-by-reference
#if 0
#include <stdio.h>

void inputData(float&, double&, long double&);
void printData(float&, double&, long double&);

int main(void) {
	// -------입력-변수 선언------------------------------
	float 		x;
	double		y;
	long double	z;
	// -------입력-변수 초기화----------------------------
	inputData(x, y, z);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
	printf("저장 값: %f %lf %lf\n", x, y, z);
	return;
}

#endif

//=========================================================================================
// 06번-03.1차원 배열
//=========================================================================================
#if 0
#include <stdio.h>
#define ColSize 1

void inputData(float[ColSize], double[ColSize], long double[ColSize], int, int);
void printData(float[ColSize], double[ColSize], long double[ColSize], int, int);

int main(void) {
	// -------입력-변수 선언------------------------------
	float 		x[ColSize];
	double		y[ColSize];
	long double	z[ColSize];
	int i, CSize;
	// -------입력-변수 초기화----------------------------
	i = 0;
	CSize = ColSize;
	inputData(x, y, z, i, CSize);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
		printf("저장 값: %f %lf %lf\n", x[i], y[i], z[i]);
	}
	return;
}
#endif

//=========================================================================================
// 06번-04.1차원 포인터
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define ColSize 1

void inputData(float*, double*, long double*, int, int);
void printData(float*, double*, long double*, int, int);

int main(void) {
	// -------입력-변수 선언------------------------------
	float* x;
	double* y;
	long double* z;
	int i, CSize;
	// -------입력-변수 초기화----------------------------
	x = (float*)malloc(sizeof(float) * ColSize);
	y = (double*)malloc(sizeof(double) * ColSize);
	z = (long double*)malloc(sizeof(long double) * ColSize);
	i = 0;
	CSize = ColSize;
	inputData(x, y, z, i, CSize);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
		printf("저장 값: %f %lf %lf\n", *(x + i), *(y + i), *(z + i));
	}
	return;
}
#endif
//=========================================================================================
// 06번-05.2차원 배열
//=========================================================================================
#if 0
#include <stdio.h>
#define RowSize 1
#define ColSize 2


void inputData(float[RowSize][ColSize], double[RowSize][ColSize], long double[RowSize][ColSize], int, int, int, int);
void printData(float[RowSize][ColSize], double[RowSize][ColSize], long double[RowSize][ColSize], int, int, int, int);

int main(void) {
	// -------입력-변수 선언------------------------------
	float 		x[RowSize][ColSize];
	double		y[RowSize][ColSize];
	long double	z[RowSize][ColSize];
	int i, j, RSize, CSize;
	// -------입력-변수 초기화----------------------------
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(x, y, z, i, j, RSize, CSize);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
			printf("저장 값: %f %lf %lf\n", x[i][j], y[i][j], z[i][j]);
		}
	}

	return;
}
#endif

//=========================================================================================
// 06번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define RowSize 1
#define ColSize 2


void inputData(float* [RowSize], double* [RowSize], long double* [RowSize], int, int, int, int);
void printData(float* [RowSize], double* [RowSize], long double* [RowSize], int, int, int, int);

int main(void) {
	// -------입력-변수 선언------------------------------

	float* x[RowSize];
	double* y[RowSize];
	long double* z[RowSize];
	int i, j, RSize, CSize;

	// -------입력-변수 초기화----------------------------
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

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
			printf("저장 값: %f %lf %lf\n", x[i][j], y[i][j], z[i][j]);
		}
	}

	return;
}
#endif

//=========================================================================================
// 06번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 06번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================
#if 0
#include <stdio.h>
#include <malloc.h>
#define RowSize 1
#define ColSize 2


void printData(float**, double**, long double**, int, int, int, int);
void inputData(float**, double**, long double**, int, int, int, int);

int main(void) {
	// -------입력-변수 선언------------------------------

	float** x;
	double** y;
	long double** z;
	int i, j, RSize, CSize;

	x = (float**)malloc(sizeof(float*) * RowSize);
	y = (double**)malloc(sizeof(double*) * RowSize);
	z = (long double**)malloc(sizeof(long double*) * RowSize);

	// -------입력-변수 초기화----------------------------
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

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
			//printf("저장 값: %f %lf %lf\n", x[i][j], y[i][j], z[i][j]);
			//printf("저장 값: %f %lf %lf\n", *(x[i]+j), *(y[i]+j), *(z[i]+j));
			printf("저장 값: %f %lf %lf\n", *(*(x + i) + j), *(*(y + i) + j), *(*(z + i) + j));
		}
	}

	return;
}
#endif








//=========================================================================================
// 07번. 자료형
//=========================================================================================
// 07번-00. 기본 코드
//=========================================================================================
#if 0
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	char c1 = 'a';		//소문자 a
	char c2 = 65;		//대문자 A가 코드 값 65
	char c3 = '\132';	//대문자 Z의 8진수 코드 값 132 //scanf로 입력받을때는 '\132'로 입력하면 안됨
	// scanf 변환 시에에는 아무 문자나 입력하면 됨
	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("저장 값(문자): %c %c %c\n", c1, c2, c3);
	printf("저장 값(정수): %d %d %d\n", c1, c2, c3);

	return 0;
}
#endif

//=========================================================================================
// 07번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#include <stdio.h> 
int main(void) {
	// -------입력-변수 선언------------------------------
	char c1, c2, c3;
	// scanf 변환 시에에는 아무 문자나 입력하면 됨
	// -------입력-변수 초기화----------------------------
	scanf(" %c %c %c", &c1, &c2, &c3);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("저장 값(문자): %c %c %c\n", c1, c2, c3);
	printf("저장 값(정수): %d %d %d\n", c1, c2, c3);

	return 0;
}
#endif
// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 07번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

void printData(char, char, char);

int main(void) {
	// -------입력-변수 선언------------------------------
	char c1, c2, c3;
	// scanf 변환 시에에는 아무 문자나 입력하면 됨
	// -------입력-변수 초기화----------------------------
	scanf(" %c %c %c", &c1, &c2, &c3);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(c1, c2, c3);

	return 0;
}


void printData(char c1, char c2, char c3)
{
	printf("저장 값(문자): %c %c %c\n", c1, c2, c3);
	printf("저장 값(정수): %d %d %d\n", c1, c2, c3);
	return;
}
#endif
// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 07번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 07번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 07번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 07번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 07번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 07번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================










//=========================================================================================
// 08번. 자료형-define
//=========================================================================================
// 08번-00. 기본 코드
//=========================================================================================
#if 0
#include <stdio.h>
#define	KPOP 50000000			//정수 매크로 상수
#define	PHI 3.14				//실수 매크로 상수
#define	PRT printf("종료\n")	//문자열 매크로 상수
int main(void)
{
	// -------입력-변수 선언------------------------------
	double radius = 2.83;
	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("한국인구: %d명\n", KPOP);
	printf("원 면적: %f\n", radius * radius * PHI);
	PRT;

	return 0;
}
#endif

//=========================================================================================
// 08번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#include <stdio.h>
#define	KPOP 50000000			//정수 매크로 상수
#define	PHI 3.14				//실수 매크로 상수
#define	PRT printf("종료\n")	//문자열 매크로 상수
int main(void)
{
	// -------입력-변수 선언------------------------------
	double radius;
	// -------입력-변수 초기화----------------------------
	scanf(" %lf", &radius);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("한국인구: %d명\n", KPOP);
	printf("원 면적: %f\n", radius * radius * PHI);
	PRT;

	return 0;
}
#endif

// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 08번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value
#if 0
#include <stdio.h>
#define	KPOP 50000000			//정수 매크로 상수
#define	PHI 3.14				//실수 매크로 상수
#define	PRT printf("종료\n")	//문자열 매크로 상수

void printData(double);

int main(void)
{
	// -------입력-변수 선언------------------------------
	double radius;
	// -------입력-변수 초기화----------------------------

	scanf(" %lf", &radius);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(radius);

	return 0;
}

void printData(double radius)
{
	printf("한국인구: %d명\n", KPOP);
	printf("원 면적: %f\n", radius * radius * PHI);
	PRT;
}
#endif
// case 2. call-by-address

#if 0
#include <stdio.h>
#define	KPOP 50000000			//정수 매크로 상수
#define	PHI 3.14				//실수 매크로 상수
#define	PRT printf("종료\n")	//문자열 매크로 상수

void inputData(double*);
void printData(double*);

int main(void)
{
	// -------입력-변수 선언------------------------------
	double radius;
	// -------입력-변수 초기화----------------------------
	inputData(&radius);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(&radius);

	return 0;
}
void inputData(double* radius) {

	scanf(" %lf", radius);
}
void printData(double* radius)
{
	printf("한국인구: %d명\n", KPOP);
	printf("원 면적: %f\n", (*radius) * (*radius) * PHI);
	PRT;
}
#endif
// case 3. call-by-reference
#if 0
#include <stdio.h>
#define	KPOP 50000000			//정수 매크로 상수
#define	PHI 3.14				//실수 매크로 상수
#define	PRT printf("종료\n")	//문자열 매크로 상수

void inputData(double&);
void printData(double&);

int main(void)
{
	// -------입력-변수 선언------------------------------
	double radius;
	// -------입력-변수 초기화----------------------------
	inputData(radius);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(radius);

	return 0;
}
void inputData(double& radius) {

	scanf(" %lf", &radius);
}
void printData(double& radius)
{
	printf("한국인구: %d명\n", KPOP);
	printf("원 면적: %f\n", radius * radius * PHI);
	PRT;
}
#endif
//=========================================================================================
// 08번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 08번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 08번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 08번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 08번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 08번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 09번. 자료형-escape
//=========================================================================================
// 09번-00. 기본 코드
//=========================================================================================
#if 0
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	char sq = '\'';
	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("BCPL\tB\tC\tJava\n");
	printf("%c\7\n", '\a');
	printf("%c자바언어'\n", sq);
	printf("\"C언어\" 정말 재미있다!\n");
	return 0;
}
#endif

//=========================================================================================
// 09번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	char sq;
	// -------입력-변수 초기화----------------------------
	scanf("%c", &sq);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("BCPL\tB\tC\tJava\n");
	printf("%c\7\n", '\a');
	printf("%c자바언어'\n", sq);
	printf("\"C언어\" 정말 재미있다!\n");
	return 0;
}
#endif
// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 09번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value
#if 0
#include <stdio.h>
void printData(char);
int main(void) {
	// -------입력-변수 선언------------------------------
	char sq;
	// -------입력-변수 초기화----------------------------
	scanf("%c", &sq);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(sq);

	return 0;
}

void printData(char sq) {

	printf("BCPL\tB\tC\tJava\n");
	printf("%c\7\n", '\a');
	printf("%c자바언어'\n", sq);
	printf("\"C언어\" 정말 재미있다!\n");
	return;

}

#endif
// case 2. call-by-address
#if 0
#include <stdio.h>
void inputData(char*);
void printData(char*);
int main(void) {
	// -------입력-변수 선언------------------------------
	char sq;
	// -------입력-변수 초기화----------------------------
	inputData(&sq);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
	printf("%c자바언어'\n", *sq);
	printf("\"C언어\" 정말 재미있다!\n");
	return;

}

#endif

// case 3. call-by-reference
#if 0
#include <stdio.h>
void printData(char&);
int main(void) {
	// -------입력-변수 선언------------------------------
	char sq;
	// -------입력-변수 초기화----------------------------
	scanf("%c", &sq);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(sq);

	return 0;
}

void printData(char& sq) {

	printf("BCPL\tB\tC\tJava\n");
	printf("%c\7\n", '\a');
	printf("%c자바언어'\n", sq);
	printf("\"C언어\" 정말 재미있다!\n");
	return;

}

#endif
//=========================================================================================
// 09번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 09번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 09번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 09번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 09번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 09번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 10번. 자료형-출력형태 조정
//=========================================================================================
// 10번-00. 기본 코드
//=========================================================================================
#if 0
#include <stdio.h>
int main(void)
{
	// -------입력-변수 선언------------------------------
	int		n = 255;
	float	f = 3.141592F;
	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
// 10번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#include <stdio.h>
int main(void)
{
	// -------입력-변수 선언------------------------------
	int	n;
	float f;
	// -------입력-변수 초기화----------------------------

	scanf("%d%f", &n, &f);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 10번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value
#if 0
#include <stdio.h>

void printData(int, float);

int main(void)
{
	// -------입력-변수 선언------------------------------
	int	n;
	float f;
	// -------입력-변수 초기화----------------------------

	scanf("%d%f", &n, &f);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
	// -------입력-변수 선언------------------------------
	int	n;
	float f;
	// -------입력-변수 초기화----------------------------
	inputData(&n, &f);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
	// -------입력-변수 선언------------------------------
	int	n;
	float f;
	// -------입력-변수 초기화----------------------------
	inputData(n, f);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
// 10번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 10번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 10번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 10번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 10번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 10번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 11번. 연산자- 산술 연산자
//=========================================================================================
// 11번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int x, y, z;
	// -------입력-변수 초기화----------------------------
	x = 3;
	y = 2;
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("%d \n", z = x + y);		// 출력 값 : 5
	printf("%d \n", z = x - y);		// 출력 값 : 1
	printf("%d \n", x * y);		// 출력 값 : 6
	printf("%d \n", x / y);		// 출력 값 : 1
	printf("%d \n", x % y);		// 출력 값 : 1
	return 0;
}
#endif

//=========================================================================================
// 11번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0

#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int x, y, z;
	// -------입력-변수 초기화----------------------------
	scanf("%d %d %d", &x, &y, &z);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("%d \n", z = x + y);		// 출력 값 : 5
	printf("%d \n", z = x - y);		// 출력 값 : 1
	printf("%d \n", x * y);		// 출력 값 : 6
	printf("%d \n", x / y);		// 출력 값 : 1
	printf("%d \n", x % y);		// 출력 값 : 1
	return 0;
}
#endif
// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 11번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value
#if 0

#include <stdio.h>

void printData(int, int, int);

int main(void) {
	// -------입력-변수 선언------------------------------
	int x, y, z;
	// -------입력-변수 초기화----------------------------

	scanf("%d %d %d", &x, &y, &z);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(x, y, z);
	return 0;
}

void printData(int x, int y, int z)
{
	printf("%d \n", z = x + y);		// 출력 값 : 5
	printf("%d \n", z = x - y);		// 출력 값 : 1
	printf("%d \n", x * y);		// 출력 값 : 6
	printf("%d \n", x / y);		// 출력 값 : 1
	printf("%d \n", x % y);		// 출력 값 : 1
}
#endif
// case 2. call-by-address
#if 0

#include <stdio.h>
void inputData(int*, int*, int*);
void printData(int*, int*, int*);

int main(void) {
	// -------입력-변수 선언------------------------------
	int x, y, z;
	// -------입력-변수 초기화----------------------------
	inputData(&x, &y, &z);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(&x, &y, &z);
	return 0;
}
void inputData(int* x, int* y, int* z)
{
	scanf("%d %d %d", *(&x), *(&y), *(&z));
}
void printData(int* x, int* y, int* z)
{
	printf("%d \n", *z = *x + *y);		// 출력 값 : 5
	printf("%d \n", *z = *x - *y);		// 출력 값 : 1
	printf("%d \n", *x * *y);		// 출력 값 : 6
	printf("%d \n", *x / *y);		// 출력 값 : 1
	printf("%d \n", *x % *y);		// 출력 값 : 1
}
#endif
// case 3. call-by-reference
#if 0

#include <stdio.h>
void inputData(int&, int&, int&);
void printData(int&, int&, int&);

int main(void) {
	// -------입력-변수 선언------------------------------
	int x, y, z;
	// -------입력-변수 초기화----------------------------
	inputData(x, y, z);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(x, y, z);
	return 0;
}
void inputData(int& x, int& y, int& z)
{
	scanf("%d %d %d", &x, &y, &z);
}
void printData(int& x, int& y, int& z)
{
	printf("%d \n", z = x + y);		// 출력 값 : 5
	printf("%d \n", z = x - y);		// 출력 값 : 1
	printf("%d \n", x * y);		// 출력 값 : 6
	printf("%d \n", x / y);		// 출력 값 : 1
	printf("%d \n", x % y);		// 출력 값 : 1
}
#endif
//=========================================================================================
// 11번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 11번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 11번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 11번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 11번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 11번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 12번. 연산자-산술연산자
//=========================================================================================
// 12번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int time, minute, second;
	// -------입력-변수 초기화----------------------------
	printf("시간을 입력하시오(초). \n");
	scanf("%d", &time);	// scanf를 이용하여 time(초)를 입력 받음
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	minute = time / 60;	// 분을 계산하여 minute에 저장 -> 시간을 60으로 나눈 몫
	second = time % 60;	// 초를 계산하여 second에 저장 -> 시간을 60으로 나눈 나머지

	printf("%d 초는 %d 분 %d 초 입니다.\n", time, minute, second);

	return 0;
}
#endif

//=========================================================================================
// 12번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int time, minute, second;
	// -------입력-변수 초기화----------------------------
	printf("시간을 입력하시오(초). \n");
	scanf("%d", &time);	// scanf를 이용하여 time(초)를 입력 받음
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	minute = time / 60;	// 분을 계산하여 minute에 저장 -> 시간을 60으로 나눈 몫
	second = time % 60;	// 초를 계산하여 second에 저장 -> 시간을 60으로 나눈 나머지

	printf("%d 초는 %d 분 %d 초 입니다.\n", time, minute, second);

	return 0;
}
#endif

// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 12번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void printData(int, int, int);
int main(void) {
	// -------입력-변수 선언------------------------------
	int time, minute, second;
	// -------입력-변수 초기화----------------------------
	printf("시간을 입력하시오(초). \n");
	scanf("%d", &time);	// scanf를 이용하여 time(초)를 입력 받음
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(time, minute, second);
	return 0;
}

void printData(int time, int minute, int second)
{

	minute = time / 60;	// 분을 계산하여 minute에 저장 -> 시간을 60으로 나눈 몫
	second = time % 60;	// 초를 계산하여 second에 저장 -> 시간을 60으로 나눈 나머지

	printf("%d 초는 %d 분 %d 초 입니다.\n", time, minute, second);

}
#endif
// case 2. call-by-address
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void inputData(int*);
void printData(int*, int*, int*);
int main(void) {
	// -------입력-변수 선언------------------------------
	int time, minute, second;
	// -------입력-변수 초기화----------------------------
	printf("시간을 입력하시오(초). \n");
	inputData(&time);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(&time, &minute, &second);
	return 0;
}
void inputData(int* time)
{
	scanf("%d", *(&time));	// scanf를 이용하여 time(초)를 입력 받음
}
void printData(int* time, int* minute, int* second)
{

	*minute = *time / 60;	// 분을 계산하여 minute에 저장 -> 시간을 60으로 나눈 몫
	*second = *time % 60;	// 초를 계산하여 second에 저장 -> 시간을 60으로 나눈 나머지

	printf("%d 초는 %d 분 %d 초 입니다.\n", *time, *minute, *second);

}
#endif
// case 3. call-by-reference
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void inputData(int&);
void printData(int&, int&, int&);
int main(void) {
	// -------입력-변수 선언------------------------------
	int time, minute, second;
	// -------입력-변수 초기화----------------------------
	printf("시간을 입력하시오(초). \n");
	inputData(time);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(time, minute, second);
	return 0;
}
void inputData(int& time)
{
	scanf("%d", &time);	// scanf를 이용하여 time(초)를 입력 받음
}
void printData(int& time, int& minute, int& second)
{

	minute = time / 60;	// 분을 계산하여 minute에 저장 -> 시간을 60으로 나눈 몫
	second = time % 60;	// 초를 계산하여 second에 저장 -> 시간을 60으로 나눈 나머지

	printf("%d 초는 %d 분 %d 초 입니다.\n", time, minute, second);

}
#endif
//=========================================================================================
// 12번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 12번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 12번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 12번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 12번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 12번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================











//=========================================================================================
// 13번. 연산자-산술 연산자
//=========================================================================================
// 13번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	
void main() {
	// -------입력-변수 선언------------------------------
	int a, b, c;
	// -------입력-변수 초기화----------------------------
	a = 10, b = 20, c = a + b
		// -------처리----------------------------------------
		// -------출력----------------------------------------
		printf("더하기 연산 \n");
	printf("----------- \n");
	printf("a = %d \n", a);
	printf("b = %d \n", b);
	printf("a + b = %d \n", a + b); // 더하기 연산
	printf("a * b = %d \n", a * b); // 곱하기 연산
	printf("a - b = %d \n", a - b); // 빼기 연산
	printf("b / a = %d \n", b / a); // 나누기 연산
	printf("b %% a = %d \n", b % a); // 나머지 연산
}
#endif

//=========================================================================================
// 13번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	
int main() {
	// -------입력-변수 선언------------------------------
	int a, b, c;
	// -------입력-변수 초기화----------------------------
	scanf("%d %d", &a, &b);
	c = a + b;
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("더하기 연산 \n");
	printf("----------- \n");
	printf("a = %d \n", a);
	printf("b = %d \n", b);
	printf("a + b = %d \n", a + b); // 더하기 연산
	printf("a * b = %d \n", a * b); // 곱하기 연산
	printf("a - b = %d \n", a - b); // 빼기 연산
	printf("b / a = %d \n", b / a); // 나누기 연산
	printf("b %% a = %d \n", b % a); // 나머지 연산

	return 0;
}
#endif
// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 13번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 13번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 13번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 13번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 13번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 13번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 13번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 14번. 연산자-산술연산자
//=========================================================================================
// 14번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
// 14번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 14번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 14번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 14번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 14번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 14번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 14번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 14번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 15번. 연산자 - 대입 연산자
//=========================================================================================
// 15번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int a, b, c;
	// -------입력-변수 초기화----------------------------
	a = b = c = 5;	//(a = (b = (c = 5)))
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("a = a + 2 ==> %d\n", a = a + 2);
	printf("a ==> %d\n", a);
	printf("a = b + c ==> %d\n", b + c);
	printf("a ==> %d\n", a);
	return 0;
}
#endif

//=========================================================================================
// 15번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int a, b, c;
	// -------입력-변수 초기화----------------------------
	scanf("%d %d %d", &a, &b, &c);
	//(a = (b = (c = 5)))
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("a = a + 2 ==> %d\n", a = a + 2);
	printf("a ==> %d\n", a);
	printf("a = b + c ==> %d\n", b + c);
	printf("a ==> %d\n", a);
	return 0;
}
#endif
// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 15번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printData(int, int, int);

int main(void) {
	// -------입력-변수 선언------------------------------
	int a, b, c;
	// -------입력-변수 초기화----------------------------
	scanf("%d %d %d", &a, &b, &c);
	//(a = (b = (c = 5)))
	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
	// -------입력-변수 선언------------------------------
	int a, b, c;
	// -------입력-변수 초기화----------------------------

	inputData(a, b, c);

	//(a = (b = (c = 5)))
	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
// 15번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 15번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 15번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 15번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 15번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 15번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 16번. 연산자 - 대입 연산자
//=========================================================================================
// 16번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int n = 10, m = 5;
	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	//우측에서 좌측으로 결합
	printf("%d ", n += m /= 3);
	n = 10; m = 5;
	printf("%d\n", (n += (m /= 3)));

	//좌측에서 우측으로 결합
	printf("%d ", 10 * 3 / 2);
	printf("%d ", (10 * 3) / 2);
	printf("%d\n", 10 * (3 / 2));

	return 0;
}
#endif

//=========================================================================================
// 16번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int n, m;
	// -------입력-변수 초기화----------------------------
	scanf("%d%d", &n, &m);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	//우측에서 좌측으로 결합
	printf("%d ", n += m /= 3);
	n = 10; m = 5;
	printf("%d\n", (n += (m /= 3)));

	//좌측에서 우측으로 결합
	printf("%d ", 10 * 3 / 2);
	printf("%d ", (10 * 3) / 2);
	printf("%d\n", 10 * (3 / 2));

	return 0;
}
#endif
// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 16번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 16번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 16번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 16번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 16번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 16번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 16번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 17번. 연산자-콤마 연산자
//=========================================================================================
// 17번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int a = 100, b = 50, c;
	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("%d ", sizeof(short));
	printf("%d ", sizeof(a * 2));
	printf("%d ", sizeof 3.5F);
	printf("%d\n", sizeof 3.14);

	c = ++a, b++;		// a = 101, b는 이 문장이 종료된 이후 1증가
	printf("%d %d %d\n", a, b, c);	// a = 101, b = 51, c = 101

	c = (3 + a, b * 2); // 3+a의 값은 할당되는 부분이 없으며,
	// b*2한 값, 51*2 = 102의 값이 C에 할당됨
	// a와 b의 값은 변경되지 않은 상태임
	printf("%d %d %d\n", a, b, c); // a = 101, b = 51, c = 102

	return 0;
}
#endif

//=========================================================================================
// 17번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int a, b, c;
	scanf("%d%d", &a, &b);
	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("%d ", sizeof(short));
	printf("%d ", sizeof(a * 2));
	printf("%d ", sizeof 3.5F);
	printf("%d\n", sizeof 3.14);

	c = ++a, b++;		// a = 101, b는 이 문장이 종료된 이후 1증가
	printf("%d %d %d\n", a, b, c);	// a = 101, b = 51, c = 101

	c = (3 + a, b * 2); // 3+a의 값은 할당되는 부분이 없으며,
	// b*2한 값, 51*2 = 102의 값이 C에 할당됨
	// a와 b의 값은 변경되지 않은 상태임
	printf("%d %d %d\n", a, b, c); // a = 101, b = 51, c = 102

	return 0;
}
#endif
// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 17번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 17번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 17번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 17번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 17번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 17번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 17번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 18번. 연산자 - 비교 연산자
//=========================================================================================
// 18번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	// -------입력-변수 선언------------------------------
	int x = 5, y = 10;
	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
// 18번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	// -------입력-변수 선언------------------------------
	int x, y;
	// -------입력-변수 초기화----------------------------
	scanf("%d%d", &x, &y);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 18번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 18번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 18번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 18번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 18번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 18번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 18번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 19번. 연산자 - 비교 연산자
//=========================================================================================
// 19번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int x, y;
	// -------입력-변수 초기화----------------------------
	x = 10;
	y = 20;
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("%d \n", (x > y) ? x : y); // -> 구해지는 값은 큰 수인 20

	return 0;
}
#endif

//=========================================================================================
// 19번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int x, y;
	// -------입력-변수 초기화----------------------------
	scanf("%d%d", &x, &y);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("%d \n", (x > y) ? x : y); // -> 구해지는 값은 큰 수인 20

	return 0;
}
#endif
// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 19번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 19번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 19번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 19번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 19번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 19번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 19번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 20번. 연산자 - 조건 연산자
//=========================================================================================
// 20번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	// -------입력-변수 선언------------------------------
	int a = 10, b = -5;
	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("최대값: %d\n", (a > b) ? a : b);
	printf("최소값: %d\n", (a < b) ? a : b);
	printf("절대값: %d\n", (a > 0) ? a : -a);
	printf("절대값: %d\n", (b > 0) ? b : -b);

	((a % 2) == 0) ? printf("짝수\n") : printf("홀수\n");;

	return 0;
}
#endif

//=========================================================================================
// 20번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	// -------입력-변수 선언------------------------------
	int a, b;
	// -------입력-변수 초기화----------------------------
	scanf("%d%d", &a, &b);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("최대값: %d\n", (a > b) ? a : b);
	printf("최소값: %d\n", (a < b) ? a : b);
	printf("절대값: %d\n", (a > 0) ? a : -a);
	printf("절대값: %d\n", (b > 0) ? b : -b);

	((a % 2) == 0) ? printf("짝수\n") : printf("홀수\n");;

	return 0;
}
#endif
// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 20번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 20번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 20번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 20번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 20번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 20번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 20번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 21번. 연산자 - 증감 연산자
//=========================================================================================
// 21번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	// -------입력-변수 선언------------------------------
	int a = 5, b = 10, c = 15;
	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("a=%d, b=%d, c=%d\n", a, b, c);						//a=5, b=10, c=15
	printf("\ta + b++ - --c 의 결과 = %5d\n\n", a + b++ - --c);	//a=5, b=11, c=14

	printf("a=%d, b=%d, c=%d\n", a, b, c);						//a=5, b=11, c=14
	printf("\t--a + ++b %% 3 의 결과 = %5d\n\n", --a + ++b % 3);	//a=4, b=12, c=14
	printf("a=%d, b=%d, c=%d\n", a, b, c);						//a=4, b=12, c=14

	return 0;
}
#endif

//=========================================================================================
// 21번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	// -------입력-변수 선언------------------------------
	int a = 5, b = 10, c = 15;
	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("a=%d, b=%d, c=%d\n", a, b, c);						//a=5, b=10, c=15
	printf("\ta + b++ - --c 의 결과 = %5d\n\n", a + b++ - --c);	//a=5, b=11, c=14

	printf("a=%d, b=%d, c=%d\n", a, b, c);						//a=5, b=11, c=14
	printf("\t--a + ++b %% 3 의 결과 = %5d\n\n", --a + ++b % 3);	//a=4, b=12, c=14
	printf("a=%d, b=%d, c=%d\n", a, b, c);						//a=4, b=12, c=14

	return 0;
}
#endif
// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 21번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 21번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 21번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 21번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 21번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 21번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 21번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 22번. 연산자 - 증감 연산자
//=========================================================================================
// 22번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int x;
	// -------입력-변수 초기화----------------------------
	x = 10;
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("%d \n", x++);	// x++ = 10, 이 문장이 끝나고 x = 11이 됨
	printf("%d \n", ++x);	// ++x = 12, 전위이기 때문에 11+1이 되어 12
	printf("%d \n", x--);	// x-- = 12, 이 문장이 끝나고 나서 12-1=11이 됨
	return 0;
}
#endif

//=========================================================================================
// 22번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int x;
	// -------입력-변수 초기화----------------------------
	scanf("%d", &x);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("%d \n", x++);	// x++ = 10, 이 문장이 끝나고 x = 11이 됨
	printf("%d \n", ++x);	// ++x = 12, 전위이기 때문에 11+1이 되어 12
	printf("%d \n", x--);	// x-- = 12, 이 문장이 끝나고 나서 12-1=11이 됨
	return 0;
}
#endif
// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 22번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 22번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 22번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 22번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 22번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 22번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 22번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================











//=========================================================================================
// 23번. 연산자 - 증감 연산자
//=========================================================================================
// 23번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int a, b, c, d, x;
	// -------입력-변수 초기화----------------------------
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	x = 1;
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("a=%d \n", x++);		//a = x++ = 1, 후위이기 때문에 이문장이 끝나고 나서 2로 변경됨
	printf("b=%d \n", ++x);		//b = ++x = 3, 전위이기 때문에 2+1한 값이 출력
	printf("c=%d \n", x--);		//c = x-- = 3, 후위이기 때문에 3이 출력되고 나서 이 문장 종료후 1감소
	printf("d=%d \n", --x);		//d = --x = 1, 전위이기 때문에 2-1한 값이 출력됨

	return 0;
}
#endif

//=========================================================================================
// 23번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int a, b, c, d, x;
	// -------입력-변수 초기화----------------------------
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &x);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("a=%d \n", x++);		//a = x++ = 1, 후위이기 때문에 이문장이 끝나고 나서 2로 변경됨
	printf("b=%d \n", ++x);		//b = ++x = 3, 전위이기 때문에 2+1한 값이 출력
	printf("c=%d \n", x--);		//c = x-- = 3, 후위이기 때문에 3이 출력되고 나서 이 문장 종료후 1감소
	printf("d=%d \n", --x);		//d = --x = 1, 전위이기 때문에 2-1한 값이 출력됨

	return 0;
}
#endif
// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 23번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 23번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 23번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 23번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 23번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 23번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 23번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 24번. 연산자 - 증감 연산자
//=========================================================================================
// 24번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int m = 10, n = 5;
	int result;
	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	result = m++ + --n;
	printf("m=%d n=%d result=%d\n", m, n, result);

	result = ++m - n--;
	printf("m=%d n=%d result=%d\n", m, n, result);

	return 0;
}
#endif

//=========================================================================================
// 24번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int m, n;
	int result;
	// -------입력-변수 초기화----------------------------
	scanf("%d%d", &m, &n);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	result = m++ + --n;
	printf("m=%d n=%d result=%d\n", m, n, result);

	result = ++m - n--;
	printf("m=%d n=%d result=%d\n", m, n, result);

	return 0;
}
#endif
// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 24번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 24번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 24번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 24번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 24번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 24번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 24번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 25번. 연산자 - 논리 연산자
//=========================================================================================
// 25번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("(3 > 4) 결과 값: %d\n", (3 > 4));
	printf("(3 < 4.0) 결과 값: %d\n", (3 < 4.0));
	printf("('a' <= 'b') 결과 값: %d\n", ('a' <= 'b'));
	printf("(4.27 >= 4.35) 결과 값: %d\n", (4.27 >= 4.35));
	printf("(4 != 4.0) 결과 값: %d\n", (4 != 4.0));
	printf("(4.0F == 4.0) 결과 값: %d\n", (4.0F == 4.0));

	return 0;
}
#endif

//=========================================================================================
// 25번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("(3 > 4) 결과 값: %d\n", (3 > 4));
	printf("(3 < 4.0) 결과 값: %d\n", (3 < 4.0));
	printf("('a' <= 'b') 결과 값: %d\n", ('a' <= 'b'));
	printf("(4.27 >= 4.35) 결과 값: %d\n", (4.27 >= 4.35));
	printf("(4 != 4.0) 결과 값: %d\n", (4 != 4.0));
	printf("(4.0F == 4.0) 결과 값: %d\n", (4.0F == 4.0));

	return 0;
}
#endif
// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 25번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 25번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 25번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 25번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 25번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 25번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 25번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 26번. 연산자 - 우선순위
//=========================================================================================
// 26번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	// -------입력-변수 선언------------------------------
	int a = 3, b = 5;
	double x = 3.5, y = 2.7;
	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("%d ", a++ - --b * 2);			//단항 > 곱셈 > 뺄셈
	printf("%f ", a > b ? x + 1 : y * 2);	//산술 > 관계 > 조건

	return 0;
}
#endif

//=========================================================================================
// 26번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	// -------입력-변수 선언------------------------------
	int a, b;
	double x, y;
	scanf("%d%d", &a, &b);
	scanf("%lf%lf", &x, &y);

	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("%d ", a++ - --b * 2);			//단항 > 곱셈 > 뺄셈
	printf("%f ", a > b ? x + 1 : y * 2);	//산술 > 관계 > 조건

	return 0;
}
#endif
// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 26번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 26번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 26번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 26번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 26번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 26번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 26번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 27번. 연산자 - 관계 연산자
//=========================================================================================
// 27번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	char null = '\0', a = 'a';
	int zero = 0, n = 10;
	double dzero = 0.0, x = 3.56;
	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------	
	printf("%d\n", !zero);
	printf("%d\n", zero && x);
	printf("%d\n", dzero || null);
	printf("%d\n", n && x);
	printf("%d\n", a || null);
	return 0;
}
#endif
//=========================================================================================
// 27번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	char null = '\0', a = 'a';
	int zero = 0, n = 10;
	double dzero = 0.0, x = 3.56;
	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------	
	printf("%d\n", !zero);
	printf("%d\n", zero && x);
	printf("%d\n", dzero || null);
	printf("%d\n", n && x);
	printf("%d\n", a || null);
	return 0;
}
#endif
// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 27번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 27번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 27번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 27번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 27번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 27번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 27번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 28번. 연산자 - 관계 연산자
//=========================================================================================
// 28번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int x, y;
	// -------입력-변수 초기화----------------------------
	x = 10;
	y = 20;
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("%d \n", x < y);		// 출력 값 : 1
	printf("%d \n", x == y);	// 출력 값 : 0
	printf("%d \n", x = y);		// 출력 값 : 20 // 할당연산자이기 때문에 y의 값을 x에 할당함
	printf("%d \n", x != y);	// 출력 값 : 0
	printf("%d \n", !x);		// 출력 값 : 0

	return 0;
}
#endif

//=========================================================================================
// 28번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	char null = '\0', a = 'a';
	int zero = 0, n = 10;
	double dzero = 0.0, x = 3.56;
	// -------입력-변수 초기화----------------------------
	scanf(" %c", &a);
	scanf(" %d %d", &zero, &n);
	scanf(" %lf %lf", &dzero, &x);

	// -------처리----------------------------------------
	// -------출력----------------------------------------	
	printf("%d\n", !zero);
	printf("%d\n", zero && x);
	printf("%d\n", dzero || null);
	printf("%d\n", n && x);
	printf("%d\n", a || null);
	return 0;
}
#endif
// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 28번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 28번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 28번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 28번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 28번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 28번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 28번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 29번. 연산자 - 관계 연산자
//=========================================================================================
// 29번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int x;
	// -------입력-변수 초기화----------------------------
	x = 0;
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("%d \n", !0);					// 출력 값 : 1
	printf("%d \n", !!2);					// 출력 값 : 1
	printf("%d \n", !(1 == 2) + (1 == 1));	// 출력 값 : 2
	printf("%d \n", (1 == 2) && (1 == 1));	// 출력 값 : 0
	printf("%d \n", (1 == 2) || (1 == 1));	// 출력 값 : 1
	printf("%d \n", (x != 0) || (x != 1));	// 출력 값 : 1
	return 0;
}
// 논리 연산자에서 0일 경우에는 거짓(0)이 됨. 0이 아닌 나머지의 경우에는 모두 참(1)이 되기
// 때문에 !!2의 경우에는 2는 참, !2는 거짓, !!2는 참이 됨
#endif

//=========================================================================================
// 29번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int x;
	// -------입력-변수 초기화----------------------------
	scanf("%d", &x);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("%d \n", !0);					// 출력 값 : 1
	printf("%d \n", !!2);					// 출력 값 : 1
	printf("%d \n", !(1 == 2) + (1 == 1));	// 출력 값 : 2
	printf("%d \n", (1 == 2) && (1 == 1));	// 출력 값 : 0
	printf("%d \n", (1 == 2) || (1 == 1));	// 출력 값 : 1
	printf("%d \n", (x != 0) || (x != 1));	// 출력 값 : 1
	return 0;
}
// 논리 연산자에서 0일 경우에는 거짓(0)이 됨. 0이 아닌 나머지의 경우에는 모두 참(1)이 되기
// 때문에 !!2의 경우에는 2는 참, !2는 거짓, !!2는 참이 됨
#endif
// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 29번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 29번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 29번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 29번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 29번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 29번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 29번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 30번. 연산자 - 관계 연산자
//=========================================================================================
// 30번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int year, result;
	// -------입력-변수 초기화----------------------------
	printf("연도를 입력하시오. \n");
	scanf("%d", &year);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	result = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	// 윤년이면 1이고 윤년이 아니면 0임을 의미
	printf("result=%d \n", result);

	return 0;
}
#endif

//=========================================================================================
// 30번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int year, result;
	// -------입력-변수 초기화----------------------------
	printf("연도를 입력하시오. \n");
	scanf("%d", &year);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	result = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	// 윤년이면 1이고 윤년이 아니면 0임을 의미
	printf("result=%d \n", result);

	return 0;
}
#endif
// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 30번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 30번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 30번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 30번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 30번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 30번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 30번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 31번. 연산자 - 관계 연산자
//=========================================================================================
// 31번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("(3 > 4) 결과 값: %d\n", (3 > 4));
	printf("(3 < 4.0) 결과 값: %d\n", (3 < 4.0));
	printf("('a' <= 'b') 결과 값: %d\n", ('a' <= 'b'));
	printf("(4.27 >= 4.35) 결과 값: %d\n", (4.27 >= 4.35));
	printf("(4 != 4.0) 결과 값: %d\n", (4 != 4.0));
	printf("(4.0F == 4.0) 결과 값: %d\n", (4.0F == 4.0));

	return 0;
}
// 문자의 경우 각 문자별로 ASCII 코드 값이 할당되어 있기 때문에 
// printf("('a' <= 'b') 결과 값: %d\n", ('a' <= 'b'));와 같은 비교가 가능함
#endif

//=========================================================================================
// 31번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("(3 > 4) 결과 값: %d\n", (3 > 4));
	printf("(3 < 4.0) 결과 값: %d\n", (3 < 4.0));
	printf("('a' <= 'b') 결과 값: %d\n", ('a' <= 'b'));
	printf("(4.27 >= 4.35) 결과 값: %d\n", (4.27 >= 4.35));
	printf("(4 != 4.0) 결과 값: %d\n", (4 != 4.0));
	printf("(4.0F == 4.0) 결과 값: %d\n", (4.0F == 4.0));

	return 0;
}
// 문자의 경우 각 문자별로 ASCII 코드 값이 할당되어 있기 때문에 
// printf("('a' <= 'b') 결과 값: %d\n", ('a' <= 'b'));와 같은 비교가 가능함
#endif
// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 31번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 31번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 31번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 31번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 31번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 31번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 31번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 32번. 연산자 - 단축 연산자
//=========================================================================================
// 32번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int x, y;
	// -------입력-변수 초기화----------------------------
	x = 5;
	y = 2;
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("%d \n", x += 2);		// 출력 값 : 7
	printf("%d \n", y *= 10);		// 출력 값 : 20
	printf("%d \n", y /= x + 1);	// 출력 값 : 2
	printf("%d \n", x %= x - y);	// 출력 값 : 2

	return 0;
}
#endif

//=========================================================================================
// 32번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int x, y;
	// -------입력-변수 초기화----------------------------
	scanf("%d%d", &x, &y);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printf("%d \n", x += 2);		// 출력 값 : 7
	printf("%d \n", y *= 10);		// 출력 값 : 20
	printf("%d \n", y /= x + 1);	// 출력 값 : 2
	printf("%d \n", x %= x - y);	// 출력 값 : 2

	return 0;
}
#endif
// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 32번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 32번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 32번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 32번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 32번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 32번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 32번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 33번. 연산자 - 형변환
//=========================================================================================
// 33번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	// -------입력-변수 선언------------------------------
	int a = 3.4;	//자동으로 내림변환되어 변수 a에는 3이 저장 
	double d = 3;	//자동으로 올림변환되어 변수 d에는 3.0이 저장
	double  result = (double)7 / 2;
	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
// 33번-01. scanf/scanf_s 변환
//=========================================================================================
// case 1. 변수 초기화 부분을 scanf() 함수를 사용하여 변환한 형태
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	// -------입력-변수 선언------------------------------
	int a;	//자동으로 내림변환되어 변수 a에는 3이 저장 
	double d;	//자동으로 올림변환되어 변수 d에는 3.0이 저장
	double  result = (double)7 / 2;

	scanf("%d %lf", &a, &d);
	// -------입력-변수 초기화----------------------------
	// -------처리----------------------------------------
	// -------출력----------------------------------------
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

// case 2. 변수 초기화 부분을 scanf_s() 함수를 사용하여 변환한 형태

//=========================================================================================
// 33번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 33번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 33번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 33번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 33번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 33번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 33번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 34번. 문장-goto문
//=========================================================================================
// 34번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	char a;
	// -------입력-변수 초기화----------------------------
	scanf(" %c", &a);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	if (a == 'Q' || a == 'q') {		// end 부분으로 점프
		goto end;
	}
	printf("%c pressed \n", a);

end:
	printf("Program terminated ... \n");

	return 0;
}
#endif

//=========================================================================================
// 34번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 34번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 34번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 34번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 34번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 34번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 34번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 35번. 문장-goto문
//=========================================================================================
// 35번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	// -------입력-변수 선언------------------------------
	int a, b;
	char c;
	// -------입력-변수 초기화----------------------------
	scanf("%d %c%d", &a, &c, &b);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	if (c == '+') {						// 'c=+'을 의미, 조건문으로 조건문을 만족할 경우 printf 실행.
		printf("a+b=%d \n", a + b);
	}
	else if (c == '-') {				// 'c=-'을 의미, 조건문으로 조건문을 만족할 경우 printf 실행.
		printf("a-b=%d \n", a - b);
	}
	else if (c == '*') {				// 'c=*'을 의미, 조건문으로 조건문을 만족할 경우 printf 실행.
		printf("a*b=%d \n", a * b);
	}
	else if (c == '/') {				// 'c=/'을 의미, 조건문으로 조건문을 만족할 경우 printf 실행.
		printf("a/b=%d \n", a / b);
	}
	else goto end;					// if문과 else if문을 만족시키지 못한 경우에 해당. goto문에 의해 end부분으로 점프.
	return;
end:
	printf("Program terminated... \n");
	return;

	return 0;	// return 값이 없다.
}
#endif

//=========================================================================================
// 35번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 35번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 35번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 35번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 35번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 35번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 35번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 36번. 문장 - if문
//=========================================================================================
// 36번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(void) {
	// -------입력-변수 선언------------------------------
	int a;
	// -------입력-변수 초기화----------------------------
	printf("10보다 큰 수를 입력 : ");
	scanf("%d", &a);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	if (a > 10) {	// 조건문으로 조건문을 만족할 경우 printf를 출력함.
		printf("%d는(은) 10보다 큽니다. \n", a);
		printf("%d는(은) 10보다 %d만큼 큽니다. \n", a, a - 10);
	}
}
#endif

//=========================================================================================
// 36번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 36번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 36번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 36번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 36번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 36번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 36번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 37번. 문장 - if문
//=========================================================================================
// 37번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	double grade;
	// -------입력-변수 초기화----------------------------
	printf("평균평점 입력: ");
	scanf("%lf", &grade);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	if (grade >= 4.0)
	{
		printf("삼성에 지원할 수 있습니다.\n");
	}
	printf("졸업을 축하합니다.\n");
	return 0;
}
#endif

//=========================================================================================
// 37번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 37번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 37번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 37번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 37번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 37번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 37번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 38번. 문장 - if-else문
//=========================================================================================
// 38번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(void) {
	// -------입력-변수 선언------------------------------
	int a;
	// -------입력-변수 초기화----------------------------
	printf("a의 정수 값을 입력 : ");
	scanf("%d", &a);
	// -------처리----------------------------------------
	// -------출력----------------------------------------	
	if (a > 10) {				// 조건문으로 조건문을 만족할 경우 printf를 출력함.
		printf("a는(은) 10보다 큽니다. \n");
	}
	else {					// if문을 만족시키지 못한 경우 다음의 printf를 출력함.
		printf("a는(은) 10보다 작거나 같다. \n");
	}
}
#endif

//=========================================================================================
// 38번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 38번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 38번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 38번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 38번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 38번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 38번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 39번. 문장 - if-else문
//=========================================================================================
// 39번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	
int main(void) {
	// -------입력-변수 선언------------------------------
	int score;
	// -------입력-변수 초기화----------------------------
	printf("성적을 입력하시오 : ");
	scanf("%d", &score);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	if (score >= 60) {		// 조건문으로 조건문을 만족할 경우 printf를 출력
		printf("합격! \n");
	}
	else {					// if문을 만족시키지 못한 경우 다음의 printf 출력
		printf("불합격! \n");
	}
	return 0;
}
#endif

//=========================================================================================
// 39번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 39번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 39번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 39번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 39번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 39번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 39번-08. 2차원 배열- 이중 포인터 변환
//========================================================================================


//=========================================================================================
// 40번. 문장 - if-else문
//=========================================================================================
// 40번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int n;
	// -------입력-변수 초기화----------------------------
	printf("정수 입력: ");
	scanf("%d", &n);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	if (n % 2)
		printf("홀수");
	else
		printf("짝수");

	printf("입니다.\n");

	return 0;
}
#endif

//=========================================================================================
// 40번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 40번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 40번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 40번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 40번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 40번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 40번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 41번. 문장 - 중첩 if문
//=========================================================================================
// 41번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>	// 수학관련함수를 사용하기 위해 math.h 헤더파일 삽입
int main(void) {
	// -------입력-변수 선언------------------------------
	double a, b, c, dis;
	// -------입력-변수 초기화----------------------------
	printf("계수 a를 입력하시오 : ");
	scanf("%lf", &a);

	printf("계수 b를 입력하시오 : ");
	scanf("%lf", &b);

	printf("계수 c를 입력하시오 : ");
	scanf("%lf", &c);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	if (a == 0) {	// a는 0과 같다라는 의미, 조건문을 만족할 경우 {}안의 문장 실행.
		printf("방정식의 근은 %f입니다. \n", -c / b);
	}
	else {			// a != 0인 경우, 즉 a는 0이 아닌 경우를 의미
		dis = sqrt(b * b - 4.0 * a * c);	// dis값 초기화

		if (dis >= 0) {				// dis가 0보다 크거나 같은 경우를 의미
			printf("방정식의 근은 %f입니다. \n", (-b + dis) / (2.0 * a));
			printf("방정식의 근은 %f입니다. \n", (b + dis) / (2.0 * a));
		}
		else {		// dis가 0보다 작은 경우를 의미
			printf("실근이 존재하지 않습니다. \n");
		}
	}
	return 0;
}
#endif

//=========================================================================================
// 41번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 41번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 41번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 41번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 41번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 41번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 41번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 42번. 문장 - 중첩 if문
//=========================================================================================
// 42번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
int main(void) {
	// -------입력-변수 선언------------------------------
	int type, point;
	// -------입력-변수 초기화----------------------------
	printf("번호를 선택: 1(1종면허), 2(2종면허): ");
	scanf("%d", &type);
	printf("필기시험 점수 입력: ");
	scanf("%d", &point);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	if (type == 1)
	{
		if (point >= 70)
			printf("1종면허 합격\n");
		else
			printf("1종면허 불합격\n");
	}
	else if (type == 2)
	{
		if (point >= 60)
			printf("2종면허 합격\n");
		else
			printf("2종면허 불합격\n");
	}
	return 0;
}
#endif

//=========================================================================================
// 42번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 42번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 42번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 42번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 42번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 42번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 42번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 43번. 문장 - if-elseif문
//=========================================================================================
// 43번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int a;
	// -------입력-변수 초기화----------------------------
	printf("성적을 입력하시오 : ");
	scanf("%d", &a);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	if (a < 50) {	// 조건문으로 조건문을 만족할 경우 printf를 출력.
		printf("불합격입니다. \n");
	}
	else if (a < 60) {						// a >= 50 && a < 60
		printf("안타깝게 불합격입니다. \n");
	}
	else if (a < 70) {						// a >= 60 && a < 70
		printf("합격입니다. \n");
	}
	else if (a < 80) {						// a >= 70 && a < 80
		printf("우수하게 합격하였습니다. \n");
	}
	else {									// a >= 80
		printf("아주 우수하게 합격하였습니다. \n");
	}

	return 0;
}
#endif

//=========================================================================================
// 43번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 43번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 43번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 43번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 43번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 43번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 43번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 44번. 문장 - if-elseif문
//=========================================================================================
// 44번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	unsigned long income;
	unsigned long tax;
	// -------입력-변수 초기화----------------------------
	printf("과세 표준을 입력하시오(만원) : ");
	scanf("%d", &income);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	if (income <= 1000) {			// 1000만원 이하, 조건문으로 조건문을 만족할 경우 {}안의 문장을 적용함.
		tax = income * 0.08;
	}
	else if (income > 1000 && income <= 4000) {	// 1000만원 초과 4000만원 이하, 조건문으로 조건문을 만족할 경우 {}안의 문장을 적용함.
		tax = income * 0.17;
	}
	else if (income > 4000 && income <= 8000) {	// 4000만원 초과 8000만원 이하, 조건문으로 조건문을 만족할 경우 {}안의 문장을 적용함.
		tax = income * 0.26;	// 세율 26%
	}
	else {										// (income > 8000) 8000만원 초과
		tax = income * 0.35;	// 세율 35%
	}
	printf("소득세: %d만원\n", tax);
	return 0;
}
#endif

//=========================================================================================
// 44번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 44번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 44번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 44번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 44번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 44번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 44번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 45번. 문장 - if-elseif문
//=========================================================================================
// 45번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	double gpa;
	// -------입력-변수 초기화----------------------------
	printf("평균 평점 입력: ");
	scanf("%lf", &gpa);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	if (gpa >= 4.3)
		printf("성적이 최고 우수한 학생입니다.\n");
	else if (gpa >= 3.8)
		printf("성적이 매우 우수한 학생입니다.\n");
	else if (gpa >= 3.0)
		printf("성적이 우수한 학생입니다.\n");
	else
		printf("성적이 3.0 미만인 학생입니다.\n");

	return 0;
}
#endif

//=========================================================================================
// 45번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value

// case 2. call-by-address

// case 3. call-by-reference

//=========================================================================================
// 45번-03.1차원 배열
//=========================================================================================

//=========================================================================================
// 45번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 45번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 45번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 45번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 45번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 46번. 문장 - switch case문
//=========================================================================================
// 46번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int a, b, c;
	char d;
	// -------입력-변수 초기화----------------------------
	printf("수식을 입력하시오 : ");
	scanf("%d %c%d", &a, &d, &b);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	switch (d) {			// switch문은 여러 개의 정수형 변수 중에서 하나의 값을 선택하는 구문. () 안의 표현식 값 중에서 case의 값과 일치하는 것을 처리하는 문장이다.
	case '+': c = a + b; break;	// 문장 break를 만나면 switch문을 종료한다. 만일 break가 없다면 다음 값과 상관없이 아래 문장을 실행한다.
	case '-': c = a - b; break;	// 문장 break를 만나면 switch문을 종료한다.
	case '*': c = a * b; break;	// 문장 break를 만나면 switch문을 종료한다.
	case '/': c = a / b; break;	// 문장 break를 만나면 switch문을 종료한다.
	default: 0;	  break;	// 일치된 case 값을 만나지 못하여 default를 만나면 default 내부의 문장을 실행한다.
	}
	printf("%d %c %d = %d \n", a, d, b, c);
	return 0;
}
#endif

//=========================================================================================
// 46번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printData(int, int, int, char);
int main(void) {
	// -------입력-변수 선언------------------------------
	int a, b, c;
	char d;
	// -------입력-변수 초기화----------------------------
	printf("수식을 입력하시오 : ");
	scanf("%d %c%d", &a, &d, &b);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(a, b, c, d);
	return 0;
}

void printData(int a, int b, int c, char d)
{

	switch (d) {			// switch문은 여러 개의 정수형 변수 중에서 하나의 값을 선택하는 구문. () 안의 표현식 값 중에서 case의 값과 일치하는 것을 처리하는 문장이다.
	case '+': c = a + b; break;	// 문장 break를 만나면 switch문을 종료한다. 만일 break가 없다면 다음 값과 상관없이 아래 문장을 실행한다.
	case '-': c = a - b; break;	// 문장 break를 만나면 switch문을 종료한다.
	case '*': c = a * b; break;	// 문장 break를 만나면 switch문을 종료한다.
	case '/': c = a / b; break;	// 문장 break를 만나면 switch문을 종료한다.
	default: 0;	  break;	// 일치된 case 값을 만나지 못하여 default를 만나면 default 내부의 문장을 실행한다.
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
	// -------입력-변수 선언------------------------------
	int a, b, c;
	char d;
	// -------입력-변수 초기화----------------------------
	inputData(&a, &b, &d);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(&a, &b, &c, &d);
	return 0;
}
void inputData(int* a, int* b, char* d)
{
	printf("수식을 입력하시오 : ");
	scanf("%d %c%d", a, d, b);

}
void printData(int* a, int* b, int* c, char* d)
{

	switch (*d) {			// switch문은 여러 개의 정수형 변수 중에서 하나의 값을 선택하는 구문. () 안의 표현식 값 중에서 case의 값과 일치하는 것을 처리하는 문장이다.
	case '+': *c = *a + *b; break;	// 문장 break를 만나면 switch문을 종료한다. 만일 break가 없다면 다음 값과 상관없이 아래 문장을 실행한다.
	case '-': *c = *a - *b; break;	// 문장 break를 만나면 switch문을 종료한다.
	case '*': *c = *a * *b; break;	// 문장 break를 만나면 switch문을 종료한다.
	case '/': *c = *a / *b; break;	// 문장 break를 만나면 switch문을 종료한다.
	default: 0;	  break;	// 일치된 case 값을 만나지 못하여 default를 만나면 default 내부의 문장을 실행한다.
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
	// -------입력-변수 선언------------------------------
	int a, b, c;
	char d;
	// -------입력-변수 초기화----------------------------
	inputData(a, b, d);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(a, b, c, d);
	return 0;
}
void inputData(int& a, int& b, char& d)
{
	printf("수식을 입력하시오 : ");
	scanf("%d %c%d", &a, &d, &b);

}
void printData(int& a, int& b, int& c, char& d)
{

	switch (d) {			// switch문은 여러 개의 정수형 변수 중에서 하나의 값을 선택하는 구문. () 안의 표현식 값 중에서 case의 값과 일치하는 것을 처리하는 문장이다.
	case '+': c = a + b; break;	// 문장 break를 만나면 switch문을 종료한다. 만일 break가 없다면 다음 값과 상관없이 아래 문장을 실행한다.
	case '-': c = a - b; break;	// 문장 break를 만나면 switch문을 종료한다.
	case '*': c = a * b; break;	// 문장 break를 만나면 switch문을 종료한다.
	case '/': c = a / b; break;	// 문장 break를 만나면 switch문을 종료한다.
	default: 0;	  break;	// 일치된 case 값을 만나지 못하여 default를 만나면 default 내부의 문장을 실행한다.
	}
	printf("%d %c %d = %d \n", a, d, b, c);
}
#endif
//=========================================================================================
// 46번-03.1차원 배열
//=========================================================================================

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void inputData(int&, int&, char&);
void printData(int&, int&, int&, char&);
int main(void) {
	// -------입력-변수 선언------------------------------
	int a, b, c;
	char d;
	// -------입력-변수 초기화----------------------------
	inputData(a, b, d);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(a, b, c, d);
	return 0;
}
void inputData(int& a, int& b, char& d)
{
	printf("수식을 입력하시오 : ");
	scanf("%d %c%d", &a, &d, &b);

}
void printData(int& a, int& b, int& c, char& d)
{

	switch (d) {			// switch문은 여러 개의 정수형 변수 중에서 하나의 값을 선택하는 구문. () 안의 표현식 값 중에서 case의 값과 일치하는 것을 처리하는 문장이다.
	case '+': c = a + b; break;	// 문장 break를 만나면 switch문을 종료한다. 만일 break가 없다면 다음 값과 상관없이 아래 문장을 실행한다.
	case '-': c = a - b; break;	// 문장 break를 만나면 switch문을 종료한다.
	case '*': c = a * b; break;	// 문장 break를 만나면 switch문을 종료한다.
	case '/': c = a / b; break;	// 문장 break를 만나면 switch문을 종료한다.
	default: 0;	  break;	// 일치된 case 값을 만나지 못하여 default를 만나면 default 내부의 문장을 실행한다.
	}
	printf("%d %c %d = %d \n", a, d, b, c);
}
#endif
//=========================================================================================
// 46번-04.1차원 포인터
//=========================================================================================

//=========================================================================================
// 46번-05.2차원 배열
//=========================================================================================

//=========================================================================================
// 46번-06. 2차원 배열- 포인터배열 변환
//=========================================================================================

//=========================================================================================
// 46번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 46번-08. 2차원 배열- 이중 포인터 변환
//=========================================================================================












//=========================================================================================
// 47번. 문장 - switch case문
//=========================================================================================
// 47번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	char c;
	// -------입력-변수 초기화----------------------------
	printf("문자를 입력하시오 : ");
	scanf(" %c", &c);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	switch (c) {
	case 'a':
		printf("입력된 문자 %c은(는) 모음입니다. \n", c);
		break;
	case 'e':
		printf("입력된 문자 %c은(는) 모음입니다. \n", c);
		break;
	case 'i':
		printf("입력된 문자 %c은(는) 모음입니다. \n", c);
		break;
	case 'u':
		printf("입력된 문자 %c은(는) 모음입니다. \n", c);
		break;
	case 'o':
		printf("입력된 문자 %c은(는) 모음입니다. \n", c);
		break;
	default:
		printf("입력된 문자 %c은(는) 자음입니다. \n", c);
		break; .
	}
	return 0;
}
#endif

//=========================================================================================
// 47번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printData(char);
int main(void) {
	// -------입력-변수 선언------------------------------
	char c;
	// -------입력-변수 초기화----------------------------
	printf("문자를 입력하시오 : ");
	scanf(" %c", &c);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(c);
	return 0;
}

void printData(char c)
{
	switch (c) {
	case 'a':
		printf("입력된 문자 %c은(는) 모음입니다. \n", c);
		break;
	case 'e':
		printf("입력된 문자 %c은(는) 모음입니다. \n", c);
		break;
	case 'i':
		printf("입력된 문자 %c은(는) 모음입니다. \n", c);
		break;
	case 'u':
		printf("입력된 문자 %c은(는) 모음입니다. \n", c);
		break;
	case 'o':
		printf("입력된 문자 %c은(는) 모음입니다. \n", c);
		break;
	default:
		printf("입력된 문자 %c은(는) 자음입니다. \n", c);
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
	// -------입력-변수 선언------------------------------
	char c;
	// -------입력-변수 초기화----------------------------
	inputData(&c);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(&c);
	return 0;
}
void inputData(char* c)
{
	printf("문자를 입력하시오 : ");
	scanf(" %c", c);
	return;
}
void printData(char* c)
{
	switch (*c) {
	case 'a':
		printf("입력된 문자 %c은(는) 모음입니다. \n", *c);
		break;
	case 'e':
		printf("입력된 문자 %c은(는) 모음입니다. \n", *c);
		break;
	case 'i':
		printf("입력된 문자 %c은(는) 모음입니다. \n", *c);
		break;
	case 'u':
		printf("입력된 문자 %c은(는) 모음입니다. \n", *c);
		break;
	case 'o':
		printf("입력된 문자 %c은(는) 모음입니다. \n", *c);
		break;
	default:
		printf("입력된 문자 %c은(는) 자음입니다. \n", c);
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
	// -------입력-변수 선언------------------------------
	char c;
	// -------입력-변수 초기화----------------------------
	inputData(c);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(c);
	return 0;
}
void inputData(char& c)
{
	printf("문자를 입력하시오 : ");
	scanf(" %c", &c);
	return;
}
void printData(char& c)
{
	switch (c) {
	case 'a':
		printf("입력된 문자 %c은(는) 모음입니다. \n", c);
		break;
	case 'e':
		printf("입력된 문자 %c은(는) 모음입니다. \n", c);
		break;
	case 'i':
		printf("입력된 문자 %c은(는) 모음입니다. \n", c);
		break;
	case 'u':
		printf("입력된 문자 %c은(는) 모음입니다. \n", c);
		break;
	case 'o':
		printf("입력된 문자 %c은(는) 모음입니다. \n", c);
		break;
	default:
		printf("입력된 문자 %c은(는) 자음입니다. \n", c);
		break;
	}
	return;
}
#endif
//=========================================================================================
// 47번-03.1차원 배열
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ColSize 2

void inputData(char[ColSize], int, int);
void printData(char[ColSize], int, int);
int main(void) {
	// -------입력-변수 선언------------------------------
	char c[ColSize];
	int i, CSize;
	// -------입력-변수 초기화----------------------------
	i = 0;
	CSize = ColSize;
	inputData(c, i, CSize);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(c, i, CSize);
	return 0;
}
void inputData(char c[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("문자를 입력하시오 : ");
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
			printf("입력된 문자 %c은(는) 모음입니다. \n", c[i]);
			break;
		case 'e':
			printf("입력된 문자 %c은(는) 모음입니다. \n", c[i]);
			break;
		case 'i':
			printf("입력된 문자 %c은(는) 모음입니다. \n", c[i]);
			break;
		case 'u':
			printf("입력된 문자 %c은(는) 모음입니다. \n", c[i]);
			break;
		case 'o':
			printf("입력된 문자 %c은(는) 모음입니다. \n", c[i]);
			break;
		default:
			printf("입력된 문자 %c은(는) 자음입니다. \n", c[i]);
			break;
		}

	}
	return;
}
#endif
//=========================================================================================
// 47번-04.1차원 포인터
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define ColSize 2

void inputData(char*, int, int);
void printData(char*, int, int);
int main(void) {
	// -------입력-변수 선언------------------------------
	char* c;
	int i, CSize;
	// -------입력-변수 초기화----------------------------
	c = (char*)malloc(sizeof(char) * ColSize);
	i = 0;
	CSize = ColSize;
	inputData(c, i, CSize);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(c, i, CSize);
	free(c);
	return 0;
}
void inputData(char* c, int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("문자를 입력하시오 : ");
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
			printf("입력된 문자 %c은(는) 모음입니다. \n", *(c + i));
			break;
		case 'e':
			printf("입력된 문자 %c은(는) 모음입니다. \n", *(c + i));
			break;
		case 'i':
			printf("입력된 문자 %c은(는) 모음입니다. \n", *(c + i));
			break;
		case 'u':
			printf("입력된 문자 %c은(는) 모음입니다. \n", *(c + i));
			break;
		case 'o':
			printf("입력된 문자 %c은(는) 모음입니다. \n", *(c + i));
			break;
		default:
			printf("입력된 문자 %c은(는) 자음입니다. \n", *(c + i));
			break;
		}

	}
	return;
}
#endif
//=========================================================================================
// 47번-05.2차원 배열
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define RowSize 1
#define ColSize 2

void inputData(char[RowSize][ColSize], int, int, int, int);
void printData(char[RowSize][ColSize], int, int, int, int);
int main(void) {
	// -------입력-변수 선언------------------------------
	char c[RowSize][ColSize];
	int i, j, RSize, CSize;
	// -------입력-변수 초기화----------------------------
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(c, i, j, RSize, CSize);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(c, i, j, RSize, CSize);
	return 0;
}
void inputData(char c[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("문자를 입력하시오 : ");
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
				printf("입력된 문자 %c은(는) 모음입니다. \n", c[i][j]);
				break;
			case 'e':
				printf("입력된 문자 %c은(는) 모음입니다. \n", c[i][j]);
				break;
			case 'i':
				printf("입력된 문자 %c은(는) 모음입니다. \n", c[i][j]);
				break;
			case 'u':
				printf("입력된 문자 %c은(는) 모음입니다. \n", c[i][j]);
				break;
			case 'o':
				printf("입력된 문자 %c은(는) 모음입니다. \n", c[i][j]);
				break;
			default:
				printf("입력된 문자 %c은(는) 자음입니다. \n", c[i][j]);
				break;
			}
		}
	}
	return;
}
#endif
//=========================================================================================
// 47번-06. 2차원 배열- 포인터배열 변환
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
	// -------입력-변수 선언------------------------------
	char* c[RowSize];
	int i, j, RSize, CSize;
	// -------입력-변수 초기화----------------------------
	for (i = 0; i < RowSize; i++)
	{
		c[i] = (char*)malloc(sizeof(char) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(c, i, j, RSize, CSize);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
			printf("문자를 입력하시오 : ");
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
				printf("입력된 문자 %c은(는) 모음입니다. \n", *(*(c + i) + j));
				break;
			case 'e':
				printf("입력된 문자 %c은(는) 모음입니다. \n", *(*(c + i) + j));
				break;
			case 'i':
				printf("입력된 문자 %c은(는) 모음입니다. \n", *(*(c + i) + j));
				break;
			case 'u':
				printf("입력된 문자 %c은(는) 모음입니다. \n", *(*(c + i) + j));
				break;
			case 'o':
				printf("입력된 문자 %c은(는) 모음입니다. \n", *(*(c + i) + j));
				break;
			default:
				printf("입력된 문자 %c은(는) 자음입니다. \n", *(*(c + i) + j));
				break;
			}
		}
	}
	return;
}
#endif
//=========================================================================================
// 47번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 47번-08. 2차원 배열- 이중 포인터 변환
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
	// -------입력-변수 선언------------------------------
	char** c;
	int i, j, RSize, CSize;
	// -------입력-변수 초기화----------------------------
	c = (char**)malloc(sizeof(char*) * RowSize);
	for (i = 0; i < RowSize; i++)
	{
		c[i] = (char*)malloc(sizeof(char) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(c, i, j, RSize, CSize);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
			printf("문자를 입력하시오 : ");
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
				printf("입력된 문자 %c은(는) 모음입니다. \n", *(*(c + i) + j));
				break;
			case 'e':
				printf("입력된 문자 %c은(는) 모음입니다. \n", *(*(c + i) + j));
				break;
			case 'i':
				printf("입력된 문자 %c은(는) 모음입니다. \n", *(*(c + i) + j));
				break;
			case 'u':
				printf("입력된 문자 %c은(는) 모음입니다. \n", *(*(c + i) + j));
				break;
			case 'o':
				printf("입력된 문자 %c은(는) 모음입니다. \n", *(*(c + i) + j));
				break;
			default:
				printf("입력된 문자 %c은(는) 자음입니다. \n", *(*(c + i) + j));
				break;
			}
		}
	}
	return;
}
#endif










//=========================================================================================
// 48번. 문장 - switch case문
//=========================================================================================
// 48번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	char command;
	int x, y;
	// -------입력-변수 초기화----------------------------
	// 결과를 보고 메뉴를 작성하시오.
	printf("=====메뉴===== \n");
	printf("+ : 더하기 \n");
	printf("- : 빼기 \n");
	printf("* : 곱하기 \n");
	printf("/ : 나누기 \n");
	printf("=====메뉴===== \n");

	printf("메뉴에서 연산자를 선택하시오 : ");
	scanf(" %c", &command);

	printf("피연산자를 입력하시오 : ");
	scanf("%d%d", &x, &y);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	switch (command) {
	case '+':
		printf("연산의 결과 : %d \n", x + y);	break;
	case '-':
		printf("연산의 결과 : %d \n", x - y);	break;
	case '*':
		printf("연산의 결과 : %d \n", x * y);	break;
	case '/':
		printf("연산의 결과 : %d \n", x / y);	break;
	default:
		printf("지원되지 않는 연산자입니다. \n"); break;
	}
}
#endif

//=========================================================================================
// 48번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printData(int, int, char);

int main(void) {
	// -------입력-변수 선언------------------------------
	char command;
	int x, y;
	// -------입력-변수 초기화----------------------------
	// 결과를 보고 메뉴를 작성하시오.
	printf("=====메뉴===== \n");
	printf("+ : 더하기 \n");
	printf("- : 빼기 \n");
	printf("* : 곱하기 \n");
	printf("/ : 나누기 \n");
	printf("=====메뉴===== \n");

	printf("메뉴에서 연산자를 선택하시오 : ");
	scanf(" %c", &command);

	printf("피연산자를 입력하시오 : ");
	scanf("%d%d", &x, &y);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(x, y, command);

}

void printData(int x, int y, char command)
{
	switch (command) {
	case '+':
		printf("연산의 결과 : %d \n", x + y);	break;
	case '-':
		printf("연산의 결과 : %d \n", x - y);	break;
	case '*':
		printf("연산의 결과 : %d \n", x * y);	break;
	case '/':
		printf("연산의 결과 : %d \n", x / y);	break;
	default:
		printf("지원되지 않는 연산자입니다. \n"); break;
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
	// -------입력-변수 선언------------------------------
	char command;
	int x, y;
	// -------입력-변수 초기화----------------------------
	// 결과를 보고 메뉴를 작성하시오.
	inputData(&x, &y, &command);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(&x, &y, &command);

}
void inputData(int* x, int* y, char* command)
{
	printf("=====메뉴===== \n");
	printf("+ : 더하기 \n");
	printf("- : 빼기 \n");
	printf("* : 곱하기 \n");
	printf("/ : 나누기 \n");
	printf("=====메뉴===== \n");

	printf("메뉴에서 연산자를 선택하시오 : ");
	scanf(" %c", command);

	printf("피연산자를 입력하시오 : ");
	scanf("%d%d", x, y);
}
void printData(int* x, int* y, char* command)
{
	switch (*command) {
	case '+':
		printf("연산의 결과 : %d \n", *x + *y);	break;
	case '-':
		printf("연산의 결과 : %d \n", *x - *y);	break;
	case '*':
		printf("연산의 결과 : %d \n", *x * *y);	break;
	case '/':
		printf("연산의 결과 : %d \n", *x / *y);	break;
	default:
		printf("지원되지 않는 연산자입니다. \n"); break;
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
	// -------입력-변수 선언------------------------------
	char command;
	int x, y;
	// -------입력-변수 초기화----------------------------
	// 결과를 보고 메뉴를 작성하시오.
	inputData(x, y, command);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(x, y, command);

}
void inputData(int& x, int& y, char& command)
{
	printf("=====메뉴===== \n");
	printf("+ : 더하기 \n");
	printf("- : 빼기 \n");
	printf("* : 곱하기 \n");
	printf("/ : 나누기 \n");
	printf("=====메뉴===== \n");

	printf("메뉴에서 연산자를 선택하시오 : ");
	scanf(" %c", &command);

	printf("피연산자를 입력하시오 : ");
	scanf("%d%d", &x, &y);
}
void printData(int& x, int& y, char& command)
{
	switch (command) {
	case '+':
		printf("연산의 결과 : %d \n", x + y);	break;
	case '-':
		printf("연산의 결과 : %d \n", x - y);	break;
	case '*':
		printf("연산의 결과 : %d \n", x * y);	break;
	case '/':
		printf("연산의 결과 : %d \n", x / y);	break;
	default:
		printf("지원되지 않는 연산자입니다. \n"); break;
	}
}
#endif
//=========================================================================================
// 48번-03.1차원 배열
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ColSize 2
void inputData(int[ColSize], char&, int, int);
void printData(int[ColSize], char&, int, int);

int main(void) {
	// -------입력-변수 선언------------------------------
	char command;
	int x[ColSize];
	int i, CSize;
	// -------입력-변수 초기화----------------------------
	// 결과를 보고 메뉴를 작성하시오.
	i = 0;
	CSize = ColSize;
	inputData(x, command, i, CSize);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(x, command, i, CSize);

}
void inputData(int x[ColSize], char& command, int i, int CSize)
{
	printf("=====메뉴===== \n");
	printf("+ : 더하기 \n");
	printf("- : 빼기 \n");
	printf("* : 곱하기 \n");
	printf("/ : 나누기 \n");
	printf("=====메뉴===== \n");

	printf("메뉴에서 연산자를 선택하시오 : ");
	scanf(" %c", &command);

	printf("피연산자를 입력하시오 : ");
	for (i = 0; i < CSize; i++)
	{
		scanf("%d", &x[i]);
	}
}
void printData(int x[ColSize], char& command, int i, int CSize)
{
	switch (command) {
	case '+':
		printf("연산의 결과 : %d \n", x[0] + x[1]);	break;
	case '-':
		printf("연산의 결과 : %d \n", x[0] - x[1]);	break;
	case '*':
		printf("연산의 결과 : %d \n", x[0] * x[1]);	break;
	case '/':
		printf("연산의 결과 : %d \n", x[0] / x[1]);	break;
	default:
		printf("지원되지 않는 연산자입니다. \n"); break;
	}
}
#endif
//=========================================================================================
// 48번-04.1차원 포인터
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define ColSize 2
void inputData(int*, char*, int, int);
void printData(int*, char*, int, int);

int main(void) {
	// -------입력-변수 선언------------------------------
	char command;
	int* x;
	int i, CSize;
	// -------입력-변수 초기화----------------------------
	// 결과를 보고 메뉴를 작성하시오.
	x = (int*)malloc(sizeof(int) * ColSize);
	i = 0;
	CSize = ColSize;
	inputData(x, &command, i, CSize);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(x, &command, i, CSize);
	free(x);
}
void inputData(int* x, char* command, int i, int CSize)
{
	printf("=====메뉴===== \n");
	printf("+ : 더하기 \n");
	printf("- : 빼기 \n");
	printf("* : 곱하기 \n");
	printf("/ : 나누기 \n");
	printf("=====메뉴===== \n");

	printf("메뉴에서 연산자를 선택하시오 : ");
	scanf(" %c", command);

	printf("피연산자를 입력하시오 : ");
	for (i = 0; i < CSize; i++)
	{
		scanf("%d", &(*(x + i)));
	}
}
void printData(int* x, char* command, int i, int CSize)
{
	switch (*command) {
	case '+':
		printf("연산의 결과 : %d \n", *(x + 0) + *(x + 1));	break;
	case '-':
		printf("연산의 결과 : %d \n", *(x + 0) - *(x + 1));	break;
	case '*':
		printf("연산의 결과 : %d \n", *(x + 0) * *(x + 1));	break;
	case '/':
		printf("연산의 결과 : %d \n", *(x + 0) / *(x + 1));	break;
	default:
		printf("지원되지 않는 연산자입니다. \n"); break;
	}
}
#endif
//=========================================================================================
// 48번-05.2차원 배열
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define RowSize 1
#define ColSize 2
void inputData(int[RowSize][ColSize], char&, int, int, int, int);
void printData(int[RowSize][ColSize], char&, int, int, int, int);

int main(void) {
	// -------입력-변수 선언------------------------------
	char command;
	int x[RowSize][ColSize];
	int i, CSize, j, RSize;
	// -------입력-변수 초기화----------------------------
	// 결과를 보고 메뉴를 작성하시오.
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(x, command, i, j, RSize, CSize);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(x, command, i, j, RSize, CSize);

}
void inputData(int x[RowSize][ColSize], char& command, int i, int j, int RSize, int CSize)
{
	printf("=====메뉴===== \n");
	printf("+ : 더하기 \n");
	printf("- : 빼기 \n");
	printf("* : 곱하기 \n");
	printf("/ : 나누기 \n");
	printf("=====메뉴===== \n");

	printf("메뉴에서 연산자를 선택하시오 : ");
	scanf(" %c", &command);


	for (i = 0; i < RSize; i++)
	{

		for (j = 0; j < CSize; j++)
		{
			printf("피연산자를 입력하시오 : ");
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
		printf("연산의 결과 : %d \n", x[0][0] + x[0][1]);	break;
	case '-':
		printf("연산의 결과 : %d \n", x[0][0] - x[0][1]);	break;
	case '*':
		printf("연산의 결과 : %d \n", x[0][0] * x[0][1]);	break;
	case '/':
		printf("연산의 결과 : %d \n", x[0][0] / x[0][1]);	break;
	default:
		printf("지원되지 않는 연산자입니다. \n"); break;
	}
}
#endif
//=========================================================================================
// 48번-06. 2차원 배열- 포인터배열 변환
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
	// -------입력-변수 선언------------------------------
	char command;
	int* x[RowSize];
	int i, CSize, j, RSize;
	// -------입력-변수 초기화----------------------------
	// 결과를 보고 메뉴를 작성하시오.
	for (i = 0; i < RowSize; i++)
	{
		x[i] = (int*)malloc(sizeof(int) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(x, command, i, j, RSize, CSize);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(x, command, i, j, RSize, CSize);

	for (i = 0; i < RowSize; i++)
	{
		free(x[i]);
	}
	return 0;

}
void inputData(int* x[RowSize], char& command, int i, int j, int RSize, int CSize)
{
	printf("=====메뉴===== \n");
	printf("+ : 더하기 \n");
	printf("- : 빼기 \n");
	printf("* : 곱하기 \n");
	printf("/ : 나누기 \n");
	printf("=====메뉴===== \n");

	printf("메뉴에서 연산자를 선택하시오 : ");
	scanf(" %c", &command);


	for (i = 0; i < RSize; i++)
	{

		for (j = 0; j < CSize; j++)
		{
			printf("피연산자를 입력하시오 : ");
			scanf("%d", (*(x + i) + j));
		}

	}
}
void printData(int* x[RowSize], char& command, int i, int j, int RSize, int CSize)
{
	switch (command) {
	case '+':
		printf("연산의 결과 : %d \n", *(*(x + 0) + 0) + *(*(x + 0) + 1));	break;
	case '-':
		printf("연산의 결과 : %d \n", *(*(x + 0) + 0) - *(*(x + 0) + 1));	break;
	case '*':
		printf("연산의 결과 : %d \n", *(*(x + 0) + 0) * *(*(x + 0) + 1));	break;
	case '/':
		printf("연산의 결과 : %d \n", *(*(x + 0) + 0) / *(*(x + 0) + 1));	break;
	default:
		printf("지원되지 않는 연산자입니다. \n"); break;
	}
}
#endif
//=========================================================================================
// 48번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 48번-08. 2차원 배열- 이중 포인터 변환
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
	// -------입력-변수 선언------------------------------
	char command;
	int** x;
	int i, CSize, j, RSize;
	// -------입력-변수 초기화----------------------------
	// 결과를 보고 메뉴를 작성하시오.
	x = (int**)malloc(sizeof(int*) * RowSize);
	for (i = 0; i < RowSize; i++)
	{
		x[i] = (int*)malloc(sizeof(int) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(x, command, i, j, RSize, CSize);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
	printf("=====메뉴===== \n");
	printf("+ : 더하기 \n");
	printf("- : 빼기 \n");
	printf("* : 곱하기 \n");
	printf("/ : 나누기 \n");
	printf("=====메뉴===== \n");

	printf("메뉴에서 연산자를 선택하시오 : ");
	scanf(" %c", &command);


	for (i = 0; i < RSize; i++)
	{

		for (j = 0; j < CSize; j++)
		{
			printf("피연산자를 입력하시오 : ");
			scanf("%d", (*(x + i) + j));
		}

	}
}
void printData(int** x, char& command, int i, int j, int RSize, int CSize)
{
	switch (command) {
	case '+':
		printf("연산의 결과 : %d \n", *(*(x + 0) + 0) + *(*(x + 0) + 1));	break;
	case '-':
		printf("연산의 결과 : %d \n", *(*(x + 0) + 0) - *(*(x + 0) + 1));	break;
	case '*':
		printf("연산의 결과 : %d \n", *(*(x + 0) + 0) * *(*(x + 0) + 1));	break;
	case '/':
		printf("연산의 결과 : %d \n", *(*(x + 0) + 0) / *(*(x + 0) + 1));	break;
	default:
		printf("지원되지 않는 연산자입니다. \n"); break;
	}
}
#endif











//=========================================================================================
// 49번. 문장 - switch case문
//=========================================================================================
// 49번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// -------입력-변수 선언------------------------------
	int x, y, sum, diff;
	// -------입력-변수 초기화----------------------------
	printf("정수를 입력하시오 : ");
	scanf("%d", &x);

	printf("정수를 입력하시오 : ");
	scanf("%d", &y)
		// -------처리----------------------------------------
		// -------출력----------------------------------------
		sum = x + y;

	if (x >= y) {			// x가 y보다 크거나 같음을 의미함. 조건문으로 조건문을 만족할 경우 {}안의 문장 값을 출력함.
		diff = x - y;
	}
	else {					// (x < y)인 경우로 x가 y보다 작음을 의미함.
		diff = y - x;
	}

	printf("두 수의 합은 %d입니다. \n", sum);
	printf("두 수의 차는 %d입니다. \n", diff);

	return 0;
}
#endif

//=========================================================================================
// 49번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printData(int, int, int, int);
int main(void) {
	// -------입력-변수 선언------------------------------
	int x, y, sum, diff;
	// -------입력-변수 초기화----------------------------
	printf("정수를 입력하시오 : ");
	scanf("%d", &x);

	printf("정수를 입력하시오 : ");
	scanf("%d", &y);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(x, y, diff, sum);

	return 0;
}

void printData(int x, int y, int diff, int sum)
{
	sum = x + y;

	if (x >= y) {			// x가 y보다 크거나 같음을 의미함. 조건문으로 조건문을 만족할 경우 {}안의 문장 값을 출력함.
		diff = x - y;
	}
	else {					// (x < y)인 경우로 x가 y보다 작음을 의미함.
		diff = y - x;
	}

	printf("두 수의 합은 %d입니다. \n", sum);
	printf("두 수의 차는 %d입니다. \n", diff);
}
#endif
// case 2. call-by-address
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void inputData(int*, int*);
void printData(int*, int*, int*, int*);

int main(void) {
	// -------입력-변수 선언------------------------------
	int x, y, sum, diff;
	// -------입력-변수 초기화----------------------------
	inputData(&x, &y);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(&x, &y, &diff, &sum);

	return 0;
}
void inputData(int* x, int* y)
{
	printf("정수를 입력하시오 : ");
	scanf("%d", x);

	printf("정수를 입력하시오 : ");
	scanf("%d", y);
}
void printData(int* x, int* y, int* diff, int* sum)
{
	*sum = *x + *y;

	if (*x >= *y) {			// x가 y보다 크거나 같음을 의미함. 조건문으로 조건문을 만족할 경우 {}안의 문장 값을 출력함.
		*diff = *x - *y;
	}
	else {					// (x < y)인 경우로 x가 y보다 작음을 의미함.
		*diff = *y - *x;
	}

	printf("두 수의 합은 %d입니다. \n", *sum);
	printf("두 수의 차는 %d입니다. \n", *diff);
}
#endif
// case 3. call-by-reference
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void inputData(int&, int&);
void printData(int&, int&, int&, int&);

int main(void) {
	// -------입력-변수 선언------------------------------
	int x, y, sum, diff;
	// -------입력-변수 초기화----------------------------
	inputData(x, y);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(x, y, diff, sum);

	return 0;
}
void inputData(int& x, int& y)
{
	printf("정수를 입력하시오 : ");
	scanf("%d", &x);

	printf("정수를 입력하시오 : ");
	scanf("%d", &y);
}
void printData(int& x, int& y, int& diff, int& sum)
{
	sum = x + y;

	if (x >= y) {			// x가 y보다 크거나 같음을 의미함. 조건문으로 조건문을 만족할 경우 {}안의 문장 값을 출력함.
		diff = x - y;
	}
	else {					// (x < y)인 경우로 x가 y보다 작음을 의미함.
		diff = y - x;
	}

	printf("두 수의 합은 %d입니다. \n", sum);
	printf("두 수의 차는 %d입니다. \n", diff);
}
#endif
//=========================================================================================
// 49번-03.1차원 배열
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ColSize 2

void inputData(int[ColSize], int[ColSize], int, int);
void printData(int[ColSize], int[ColSize], int&, int&, int, int);

int main(void) {
	// -------입력-변수 선언------------------------------
	int x[ColSize], y[ColSize], sum, diff;
	int i, CSize;
	// -------입력-변수 초기화----------------------------
	i = 0;
	CSize = ColSize;
	inputData(x, y, i, CSize);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(x, y, diff, sum, i, CSize);

	return 0;
}
void inputData(int x[ColSize], int y[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{

		printf("정수를 입력하시오 : ");
		scanf("%d", &x[i]);

		printf("정수를 입력하시오 : ");
		scanf("%d", &y[i]);
	}
}
void printData(int x[ColSize], int y[ColSize], int& diff, int& sum, int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		sum = x[i] + y[i];

		if (x[i] >= y[i]) {			// x가 y보다 크거나 같음을 의미함. 조건문으로 조건문을 만족할 경우 {}안의 문장 값을 출력함.
			diff = x[i] - y[i];
		}
		else {					// (x < y)인 경우로 x가 y보다 작음을 의미함.
			diff = y[i] - x[i];
		}

		printf("두 수의 합은 %d입니다. \n", sum);
		printf("두 수의 차는 %d입니다. \n", diff);
	}
}
#endif
//=========================================================================================
// 49번-04.1차원 포인터
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define ColSize 2

void inputData(int*, int*, int, int);
void printData(int*, int*, int*, int*, int, int);

int main(void) {
	// -------입력-변수 선언------------------------------
	int* x, * y, sum, diff;
	int i, CSize;
	// -------입력-변수 초기화----------------------------
	x = (int*)malloc(sizeof(int) * ColSize);
	y = (int*)malloc(sizeof(int) * ColSize);
	i = 0;
	CSize = ColSize;
	inputData(x, y, i, CSize);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(x, y, &diff, &sum, i, CSize);
	free(x);
	free(y);
	return 0;
}
void inputData(int* x, int* y, int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{

		printf("정수를 입력하시오 : ");
		scanf("%d", (x + i));

		printf("정수를 입력하시오 : ");
		scanf("%d", (y + i));
	}
}
void printData(int* x, int* y, int* diff, int* sum, int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		*sum = *(x + i) + *(y + i);

		if (*(x + i) >= *(y + i)) {			// x가 y보다 크거나 같음을 의미함. 조건문으로 조건문을 만족할 경우 {}안의 문장 값을 출력함.
			*diff = *(x + i) - *(y + i);
		}
		else {					// (x < y)인 경우로 x가 y보다 작음을 의미함.
			*diff = *(y + i) - *(x + i);
		}

		printf("두 수의 합은 %d입니다. \n", *sum);
		printf("두 수의 차는 %d입니다. \n", *diff);
	}
}
#endif
//=========================================================================================
// 49번-05.2차원 배열
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define RowSize 1
#define ColSize 2

void inputData(int[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
void printData(int[RowSize][ColSize], int[RowSize][ColSize], int*, int*, int, int, int, int);

int main(void) {
	// -------입력-변수 선언------------------------------
	int x[RowSize][ColSize], y[RowSize][ColSize], sum, diff;
	int i, j, RSize, CSize;
	// -------입력-변수 초기화----------------------------
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	inputData(x, y, i, j, RSize, CSize);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(x, y, &diff, &sum, i, j, RSize, CSize);

	return 0;
}
void inputData(int x[RowSize][ColSize], int y[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			/*printf("정수를 입력하시오 : ");
			scanf("%d", &x[i][j]);

			printf("정수를 입력하시오 : ");
			scanf("%d", &y[i][j]);*/
			//printf("정수를 입력하시오 : ");
			//scanf("%d", &(*(x[i]+j)));

			//printf("정수를 입력하시오 : ");
			//scanf("%d", &(*(y[i]+j)));
			/*printf("정수를 입력하시오 : ");
			scanf("%d", (x[i] + j));

			printf("정수를 입력하시오 : ");
			scanf("%d", (y[i] + j));*/
			/*printf("정수를 입력하시오 : ");
			scanf("%d", &(*(*(x+i) + j)));

			printf("정수를 입력하시오 : ");
			scanf("%d", &(*(*(y+i) + j)));*/
			printf("정수를 입력하시오 : ");
			scanf("%d", (*(x + i) + j));

			printf("정수를 입력하시오 : ");
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

			//if (x[i][j] >= y[i][j]) {			// x가 y보다 크거나 같음을 의미함. 조건문으로 조건문을 만족할 경우 {}안의 문장 값을 출력함.
			//	*diff = x[i][j] - y[i][j];
			//}
			//else {					// (x < y)인 경우로 x가 y보다 작음을 의미함.
			//	*diff = y[i][j] - x[i][j];
			//}
			//*sum = *(x[i]+j) + *(y[i]+j);

			//if (*(x[i] + j) >= *(y[i] + j)) {			// x가 y보다 크거나 같음을 의미함. 조건문으로 조건문을 만족할 경우 {}안의 문장 값을 출력함.
			//	*diff = *(x[i] + j) - *(y[i] + j);
			//}
			//else {					// (x < y)인 경우로 x가 y보다 작음을 의미함.
			//	*diff = *(y[i] + j) - *(x[i] + j);
			//}
			* sum = *(*(x + i) + j) + *(*(y + i) + j);

			if (*(*(x + i) + j) >= *(*(y + i) + j)) {			// x가 y보다 크거나 같음을 의미함. 조건문으로 조건문을 만족할 경우 {}안의 문장 값을 출력함.
				*diff = *(*(x + i) + j) - *(*(y + i) + j);
			}
			else {					// (x < y)인 경우로 x가 y보다 작음을 의미함.
				*diff = *(*(y + i) + j) - *(*(x + i) + j);
			}

			printf("두 수의 합은 %d입니다. \n", *sum);
			printf("두 수의 차는 %d입니다. \n", *diff);
		}
	}
}
#endif
//=========================================================================================
// 49번-06. 2차원 배열- 포인터배열 변환
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
	// -------입력-변수 선언------------------------------
	int* x[RowSize], * y[RowSize], sum, diff;
	int i, j, RSize, CSize;
	// -------입력-변수 초기화----------------------------
	for (i = 0; i < RowSize; i++)
	{
		x[i] = (int*)malloc(sizeof(int) * ColSize);
		y[i] = (int*)malloc(sizeof(int) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	inputData(x, y, i, j, RSize, CSize);

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
			/*printf("정수를 입력하시오 : ");
			scanf("%d", &x[i][j]);

			printf("정수를 입력하시오 : ");
			scanf("%d", &y[i][j]);*/
			//printf("정수를 입력하시오 : ");
			//scanf("%d", &(*(x[i]+j)));

			//printf("정수를 입력하시오 : ");
			//scanf("%d", &(*(y[i]+j)));
			/*printf("정수를 입력하시오 : ");
			scanf("%d", (x[i] + j));

			printf("정수를 입력하시오 : ");
			scanf("%d", (y[i] + j));*/
			/*printf("정수를 입력하시오 : ");
			scanf("%d", &(*(*(x+i) + j)));

			printf("정수를 입력하시오 : ");
			scanf("%d", &(*(*(y+i) + j)));*/
			printf("정수를 입력하시오 : ");
			scanf("%d", (*(x + i) + j));

			printf("정수를 입력하시오 : ");
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

			//if (x[i][j] >= y[i][j]) {			// x가 y보다 크거나 같음을 의미함. 조건문으로 조건문을 만족할 경우 {}안의 문장 값을 출력함.
			//	*diff = x[i][j] - y[i][j];
			//}
			//else {					// (x < y)인 경우로 x가 y보다 작음을 의미함.
			//	*diff = y[i][j] - x[i][j];
			//}
			//*sum = *(x[i]+j) + *(y[i]+j);

			//if (*(x[i] + j) >= *(y[i] + j)) {			// x가 y보다 크거나 같음을 의미함. 조건문으로 조건문을 만족할 경우 {}안의 문장 값을 출력함.
			//	*diff = *(x[i] + j) - *(y[i] + j);
			//}
			//else {					// (x < y)인 경우로 x가 y보다 작음을 의미함.
			//	*diff = *(y[i] + j) - *(x[i] + j);
			//}
			* sum = *(*(x + i) + j) + *(*(y + i) + j);

			if (*(*(x + i) + j) >= *(*(y + i) + j)) {			// x가 y보다 크거나 같음을 의미함. 조건문으로 조건문을 만족할 경우 {}안의 문장 값을 출력함.
				*diff = *(*(x + i) + j) - *(*(y + i) + j);
			}
			else {					// (x < y)인 경우로 x가 y보다 작음을 의미함.
				*diff = *(*(y + i) + j) - *(*(x + i) + j);
			}

			printf("두 수의 합은 %d입니다. \n", *sum);
			printf("두 수의 차는 %d입니다. \n", *diff);
		}
	}
}
#endif
//=========================================================================================
// 49번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 49번-08. 2차원 배열- 이중 포인터 변환
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
	// -------입력-변수 선언------------------------------
	int** x, ** y, sum, diff;
	int i, j, RSize, CSize;
	// -------입력-변수 초기화----------------------------
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

	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
			/*printf("정수를 입력하시오 : ");
			scanf("%d", &x[i][j]);

			printf("정수를 입력하시오 : ");
			scanf("%d", &y[i][j]);*/
			//printf("정수를 입력하시오 : ");
			//scanf("%d", &(*(x[i]+j)));

			//printf("정수를 입력하시오 : ");
			//scanf("%d", &(*(y[i]+j)));
			/*printf("정수를 입력하시오 : ");
			scanf("%d", (x[i] + j));

			printf("정수를 입력하시오 : ");
			scanf("%d", (y[i] + j));*/
			/*printf("정수를 입력하시오 : ");
			scanf("%d", &(*(*(x+i) + j)));

			printf("정수를 입력하시오 : ");
			scanf("%d", &(*(*(y+i) + j)));*/
			printf("정수를 입력하시오 : ");
			scanf("%d", (*(x + i) + j));

			printf("정수를 입력하시오 : ");
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

			//if (x[i][j] >= y[i][j]) {			// x가 y보다 크거나 같음을 의미함. 조건문으로 조건문을 만족할 경우 {}안의 문장 값을 출력함.
			//	*diff = x[i][j] - y[i][j];
			//}
			//else {					// (x < y)인 경우로 x가 y보다 작음을 의미함.
			//	*diff = y[i][j] - x[i][j];
			//}
			//*sum = *(x[i]+j) + *(y[i]+j);

			//if (*(x[i] + j) >= *(y[i] + j)) {			// x가 y보다 크거나 같음을 의미함. 조건문으로 조건문을 만족할 경우 {}안의 문장 값을 출력함.
			//	*diff = *(x[i] + j) - *(y[i] + j);
			//}
			//else {					// (x < y)인 경우로 x가 y보다 작음을 의미함.
			//	*diff = *(y[i] + j) - *(x[i] + j);
			//}
			* sum = *(*(x + i) + j) + *(*(y + i) + j);

			if (*(*(x + i) + j) >= *(*(y + i) + j)) {			// x가 y보다 크거나 같음을 의미함. 조건문으로 조건문을 만족할 경우 {}안의 문장 값을 출력함.
				*diff = *(*(x + i) + j) - *(*(y + i) + j);
			}
			else {					// (x < y)인 경우로 x가 y보다 작음을 의미함.
				*diff = *(*(y + i) + j) - *(*(x + i) + j);
			}

			printf("두 수의 합은 %d입니다. \n", *sum);
			printf("두 수의 차는 %d입니다. \n", *diff);
		}
	}
}
#endif











//=========================================================================================
// 50번. 문장 - switch case문
//=========================================================================================
// 50번-00. 기본 코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	// -------입력-변수 선언------------------------------
	double x, y, result;
	int op;
	// -------입력-변수 초기화----------------------------
	printf("두 실수 입력: ");
	scanf("%lf%lf", &x, &y);
	printf("연산종류 번호선택 1(+), 2(-), 3(*), 4(/): ");
	scanf("%d", &op);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	if (op == 1)
		printf("성적이 최고 우수한 학생입니다.\n");
	else if (op == 2)
		printf("성적이 매우 우수한 학생입니다.\n");
	else if (op == 3)
		printf("성적이 우수한 학생입니다.\n");
	else if (op == 4)
		printf("성적이 우수한 학생입니다.\n");
	else
		printf("성적이 우수한 학생입니다.\n");


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
		printf("번호를 잘못 선택했습니다.\n");
	}

	return 0;
}
#endif

//=========================================================================================
// 50번-02. 함수 변환
//=========================================================================================
// case 1. call-by-value
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void printData(double, double, int);

int main(void)
{
	// -------입력-변수 선언------------------------------
	double x, y, result;
	int op;
	// -------입력-변수 초기화----------------------------
	printf("두 실수 입력: ");
	scanf("%lf%lf", &x, &y);
	printf("연산종류 번호선택 1(+), 2(-), 3(*), 4(/): ");
	scanf("%d", &op);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(x, y, op);

	return 0;
}


void printData(double x, double y, int op)
{
	if (op == 1)
		printf("성적이 최고 우수한 학생입니다.\n");
	else if (op == 2)
		printf("성적이 매우 우수한 학생입니다.\n");
	else if (op == 3)
		printf("성적이 우수한 학생입니다.\n");
	else if (op == 4)
		printf("성적이 우수한 학생입니다.\n");
	else
		printf("성적이 우수한 학생입니다.\n");


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
		printf("번호를 잘못 선택했습니다.\n");
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
	// -------입력-변수 선언------------------------------
	double x, y, result;
	int op;
	// -------입력-변수 초기화----------------------------
	inputData(&x, &y, &op);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(&x, &y, &op);


	return 0;
}
void inputData(double* x, double* y, int* op)
{

	printf("두 실수 입력: ");
	scanf("%lf%lf", *(&x), *(&y));
	printf("연산종류 번호선택 1(+), 2(-), 3(*), 4(/): ");
	scanf("%d", *(&op));

}

void printData(double* x, double* y, int* op)
{
	if (*op == 1)
		printf("성적이 최고 우수한 학생입니다.\n");
	else if (*op == 2)
		printf("성적이 매우 우수한 학생입니다.\n");
	else if (*op == 3)
		printf("성적이 우수한 학생입니다.\n");
	else if (*op == 4)
		printf("성적이 우수한 학생입니다.\n");
	else
		printf("성적이 우수한 학생입니다.\n");


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
		printf("번호를 잘못 선택했습니다.\n");
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
	// -------입력-변수 선언------------------------------
	double x, y, result;
	int op;
	// -------입력-변수 초기화----------------------------
	inputData(x, y, op);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(x, y, op);


	return 0;
}
void inputData(double& x, double& y, int& op)
{

	printf("두 실수 입력: ");
	scanf("%lf%lf", &x, &y);
	printf("연산종류 번호선택 1(+), 2(-), 3(*), 4(/): ");
	scanf("%d", &op);

}

void printData(double& x, double& y, int& op)
{
	if (op == 1)
		printf("성적이 최고 우수한 학생입니다.\n");
	else if (op == 2)
		printf("성적이 매우 우수한 학생입니다.\n");
	else if (op == 3)
		printf("성적이 우수한 학생입니다.\n");
	else if (op == 4)
		printf("성적이 우수한 학생입니다.\n");
	else
		printf("성적이 우수한 학생입니다.\n");


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
		printf("번호를 잘못 선택했습니다.\n");
	}

}
#endif
//=========================================================================================
// 50번-03.1차원 배열
//=========================================================================================

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ColSize 2

void inputData(double[ColSize], int&, int, int);
void printData(double[ColSize], int&, int, int);

int main(void)
{
	// -------입력-변수 선언------------------------------
	double x[ColSize];
	int op;
	int i, CSize;
	// -------입력-변수 초기화----------------------------
	i = 0;
	CSize = ColSize;
	inputData(x, op, i, CSize);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(x, op, i, CSize);


	return 0;
}
void inputData(double x[ColSize], int& op, int i, int CSize)
{
	printf("두 실수 입력: ");
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &x[i]);
	}
	printf("연산종류 번호선택 1(+), 2(-), 3(*), 4(/): ");
	scanf("%d", &op);

}

void printData(double x[ColSize], int& op, int i, int CSize)
{
	if (op == 1)
		printf("성적이 최고 우수한 학생입니다.\n");
	else if (op == 2)
		printf("성적이 매우 우수한 학생입니다.\n");
	else if (op == 3)
		printf("성적이 우수한 학생입니다.\n");
	else if (op == 4)
		printf("성적이 우수한 학생입니다.\n");
	else
		printf("성적이 우수한 학생입니다.\n");

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
		printf("번호를 잘못 선택했습니다.\n");
	}

}
#endif
//=========================================================================================
// 50번-04.1차원 포인터
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
	// -------입력-변수 선언------------------------------
	double* x;
	int op;
	int i, CSize;
	// -------입력-변수 초기화----------------------------
	x = (double*)malloc(sizeof(double) * ColSize);

	i = 0;
	CSize = ColSize;
	inputData(x, &op, i, CSize);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(x, &op, i, CSize);

	free(x);

	return 0;
}
void inputData(double* x, int* op, int i, int CSize)
{
	printf("두 실수 입력: ");
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &x[i]);
	}
	printf("연산종류 번호선택 1(+), 2(-), 3(*), 4(/): ");
	scanf("%d", op);

}

void printData(double x[ColSize], int* op, int i, int CSize)
{
	if (*op == 1)
		printf("성적이 최고 우수한 학생입니다.\n");
	else if (*op == 2)
		printf("성적이 매우 우수한 학생입니다.\n");
	else if (*op == 3)
		printf("성적이 우수한 학생입니다.\n");
	else if (*op == 4)
		printf("성적이 우수한 학생입니다.\n");
	else
		printf("성적이 우수한 학생입니다.\n");

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
		printf("번호를 잘못 선택했습니다.\n");
	}

}
#endif
//=========================================================================================
// 50번-05.2차원 배열
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
	// -------입력-변수 선언------------------------------
	double x[RowSize][ColSize];
	int op;
	int i, j, CSize, RSize;
	// -------입력-변수 초기화----------------------------
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(x, op, i, j, RSize, CSize);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(x, op, i, j, RSize, CSize);


	return 0;
}
void inputData(double x[RowSize][ColSize], int& op, int i, int j, int RSize, int CSize)
{
	printf("두 실수 입력: ");
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
	printf("연산종류 번호선택 1(+), 2(-), 3(*), 4(/): ");
	scanf("%d", &op);
}

void printData(double x[RowSize][ColSize], int& op, int i, int j, int RSize, int CSize)
{
	if (op == 1)
		printf("성적이 최고 우수한 학생입니다.\n");
	else if (op == 2)
		printf("성적이 매우 우수한 학생입니다.\n");
	else if (op == 3)
		printf("성적이 우수한 학생입니다.\n");
	else if (op == 4)
		printf("성적이 우수한 학생입니다.\n");
	else
		printf("성적이 우수한 학생입니다.\n");

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
		printf("번호를 잘못 선택했습니다.\n");
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
	printf("번호를 잘못 선택했습니다.\n");
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
		printf("번호를 잘못 선택했습니다.\n");
	}
}
#endif
//=========================================================================================
// 50번-06. 2차원 배열- 포인터배열 변환
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
	// -------입력-변수 선언------------------------------
	double* x[RowSize];
	int op;
	int i, j, CSize, RSize;
	// -------입력-변수 초기화----------------------------
	for (i = 0; i < RowSize; i++)
	{
		x[i] = (double*)malloc(sizeof(double) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(x, op, i, j, RSize, CSize);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
	printData(x, op, i, j, RSize, CSize);

	for (i = 0; i < RowSize; i++)
	{
		free(x[i]);
	}
	return 0;
}
void inputData(double* x[RowSize], int& op, int i, int j, int RSize, int CSize)
{
	printf("두 실수 입력: ");
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
	printf("연산종류 번호선택 1(+), 2(-), 3(*), 4(/): ");
	scanf("%d", &op);
}

void printData(double* x[RowSize], int& op, int i, int j, int RSize, int CSize)
{
	if (op == 1)
		printf("성적이 최고 우수한 학생입니다.\n");
	else if (op == 2)
		printf("성적이 매우 우수한 학생입니다.\n");
	else if (op == 3)
		printf("성적이 우수한 학생입니다.\n");
	else if (op == 4)
		printf("성적이 우수한 학생입니다.\n");
	else
		printf("성적이 우수한 학생입니다.\n");

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
		printf("번호를 잘못 선택했습니다.\n");
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
		printf("번호를 잘못 선택했습니다.\n");
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
		printf("번호를 잘못 선택했습니다.\n");
	}
}
#endif
//=========================================================================================
// 50번-07. 2차원 배열- 배열 포인터 변환
//=========================================================================================

//=========================================================================================
// 50번-08. 2차원 배열- 이중 포인터 변환
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
	// -------입력-변수 선언------------------------------
	double** x;
	int op;
	int i, j, CSize, RSize;
	// -------입력-변수 초기화----------------------------
	x = (double**)malloc(sizeof(double*) * RowSize);
	for (i = 0; i < RowSize; i++)
	{
		x[i] = (double*)malloc(sizeof(double) * ColSize);
	}
	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;
	inputData(x, op, i, j, RSize, CSize);
	// -------처리----------------------------------------
	// -------출력----------------------------------------
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
	printf("두 실수 입력: ");
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
	printf("연산종류 번호선택 1(+), 2(-), 3(*), 4(/): ");
	scanf("%d", &op);
}

void printData(double** x, int& op, int i, int j, int RSize, int CSize)
{
	if (op == 1)
		printf("성적이 최고 우수한 학생입니다.\n");
	else if (op == 2)
		printf("성적이 매우 우수한 학생입니다.\n");
	else if (op == 3)
		printf("성적이 우수한 학생입니다.\n");
	else if (op == 4)
		printf("성적이 우수한 학생입니다.\n");
	else
		printf("성적이 우수한 학생입니다.\n");

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
		printf("번호를 잘못 선택했습니다.\n");
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
		printf("번호를 잘못 선택했습니다.\n");
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
		printf("번호를 잘못 선택했습니다.\n");
	}
}
#endif