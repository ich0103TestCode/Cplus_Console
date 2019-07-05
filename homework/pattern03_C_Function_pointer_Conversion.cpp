//=========================================================================================
// 1. 일반 변수(call by address) - 기본코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	double RATE;
	int MIN_BALANCE;

	inputData(&RATE, &MIN_BALANCE);
	printData(&RATE, &MIN_BALANCE);

	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}

void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif



//#if 0 //인천 작성
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//void inputData(double*, int*);
//void printData(double*, int*);
//
//int main(void) {
//	double RATE;
//	int MIN_BALANCE;
//	void (*FunctionPtr1)(double*, int*);
//	void (*FunctionPtr2)(double*, int*);
//	void(*FunctionPtr1)(double*, int*) = inputData;
//	void(*FunctionPtr2)(double*, int*) = printData;
//	void(*FunctionPtr1)(double*, int*) = &inputData;
//	void(*FunctionPtr2)(double*, int*) = &printData;
//
//	FunctionPtr1 = inputData;
//	FunctionPtr2 = printData;
//	FunctionPtr1 = &inputData;
//	FunctionPtr2 = &printData;
//
//	FunctionPtr1(&RATE, &MIN_BALANCE);
//	FunctionPtr2(&RATE, &MIN_BALANCE);
//	(*FunctionPtr1)(&RATE, &MIN_BALANCE);
//	(*FunctionPtr2)(&RATE, &MIN_BALANCE);
//
//	return 0;
//}
//
//void inputData(double* RATE, int* MIN_BALANCE)
//{
//	scanf("%lf", RATE);
//	scanf("%d", MIN_BALANCE);
//}
//
//void printData(double* RATE, int* MIN_BALANCE)
//{
//	printf("이자율: %lf\n", *RATE);
//	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
//}
//#endif




//=========================================================================================
// 1-1. 일반 변수(call by address) - 함수 포인터로 변환한 형태
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	double RATE;
	int MIN_BALANCE;
	//void(*FunctionPtr1)(double*, int*) = inputData;
	//void(*FunctionPtr2)(double*, int*) = printData;
	//void(*FunctionPtr1)(double*, int*) = &inputData;
	//void(*FunctionPtr2)(double*, int*) = &printData;
	void(*FunctionPtr1)(double*, int*);
	void(*FunctionPtr2)(double*, int*);

	//FunctionPtr1 = inputData;
	//FunctionPtr2 = printData;
	FunctionPtr1 = &inputData;
	FunctionPtr2 = &printData;

	//FunctionPtr1(&RATE, &MIN_BALANCE);
	//FunctionPtr2(&RATE, &MIN_BALANCE);
	(*FunctionPtr1)(&RATE, &MIN_BALANCE);
	(*FunctionPtr2)(&RATE, &MIN_BALANCE);

	return 0;
}
void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}
void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif

//=========================================================================================
// 1-2. 일반 변수(call by address) - 함수 포인터 1차원 배열로 변환한 형태
//=========================================================================================
// 가. 함수 포인터 호출 부분을 풀어서 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	//void(*FunctionPtr[FColSize])(double *RATE, int *MIN_BALANCE) = {inputData, printData};
	//void(*FunctionPtr[FColSize])(double *RATE, int *MIN_BALANCE) = { &inputData, &printData };
	void(*FunctionPtr[FColSize])(double* RATE, int* MIN_BALANCE);
	double RATE;
	int MIN_BALANCE;

	//FunctionPtr[0] = inputData;
	//FunctionPtr[1] = printData;
	FunctionPtr[0] = &inputData;
	FunctionPtr[1] = &printData;

	//FunctionPtr[0](&RATE, &MIN_BALANCE);
	//FunctionPtr[1](&RATE, &MIN_BALANCE);
	//(*FunctionPtr[0])(&RATE, &MIN_BALANCE);
	//(*FunctionPtr[1])(&RATE, &MIN_BALANCE);
	(*(*(FunctionPtr + 0)))(&RATE, &MIN_BALANCE);
	(*(*(FunctionPtr + 1)))(&RATE, &MIN_BALANCE);

	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}

void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	double RATE;
	int MIN_BALANCE;
	//void(*FunctionPtr1)(double*, int*) = inputData;
	//void(*FunctionPtr2)(double*, int*) = printData;
	//void(*FunctionPtr1)(double*, int*) = &inputData;
	//void(*FunctionPtr2)(double*, int*) = &printData;
	/*void(*FunctionPtr1)(double*, int*);
	void(*FunctionPtr2)(double*, int*);*/
	void(*FunctionPtr[FColSize])(double* RATE, int* MIN_BALANCE) = { inputData, printData };

	//FunctionPtr1 = inputData;
	//FunctionPtr2 = printData;
	FunctionPtr[0] = &inputData;
	FunctionPtr[1] = &printData;

	//FunctionPtr1(&RATE, &MIN_BALANCE);
	//FunctionPtr2(&RATE, &MIN_BALANCE);
	//(*FunctionPtr1)(&RATE, &MIN_BALANCE);
	//(*FunctionPtr2)(&RATE, &MIN_BALANCE);
	/*FunctionPtr[0](&RATE, &MIN_BALANCE);
	FunctionPtr[1](&RATE, &MIN_BALANCE);*/
	/*(*FunctionPtr[0])(&RATE, &MIN_BALANCE);
	(*FunctionPtr[1])(&RATE, &MIN_BALANCE);*/
	(*(*(FunctionPtr + 0)))(&RATE, &MIN_BALANCE);
	(*(*(FunctionPtr + 1)))(&RATE, &MIN_BALANCE);


	return 0;
}
void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}
void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}

#endif



// 나. 함수 포인터 호출 부분을 배열로 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	//void(*FunctionPtr[FColSize])(double*, int*) = { inputData, printData };
	//void(*FunctionPtr[FColSize])(double*, int*) = { &inputData, &printData };
	void(*FunctionPtr[FColSize])(double*, int*);
	double RATE;
	int MIN_BALANCE;
	int i;

	//FunctionPtr[0] = inputData;
	//FunctionPtr[1] = printData;
	FunctionPtr[0] = &inputData;
	FunctionPtr[1] = &printData;

	for (i = 0; i < FColSize; i++)
	{
		//FunctionPtr[i](&RATE, &MIN_BALANCE);
		//(*(FunctionPtr+i))(&RATE, &MIN_BALANCE);

		//(*FunctionPtr[i])(&RATE, &MIN_BALANCE);
		(*(*(FunctionPtr + i)))(&RATE, &MIN_BALANCE);
	}
	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}

void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	double RATE;
	int MIN_BALANCE;
	//void(*FunctionPtr1)(double*, int*) = inputData;
	//void(*FunctionPtr2)(double*, int*) = printData;
	//void(*FunctionPtr1)(double*, int*) = &inputData;
	//void(*FunctionPtr2)(double*, int*) = &printData;
	/*void(*FunctionPtr1)(double*, int*);
	void(*FunctionPtr2)(double*, int*);*/
	//void(*FunctionPtr[FColSize])(double* RATE, int* MIN_BALANCE) = { inputData, printData };
	//void(*FunctionPtr[FColSize])(double*, int*) = { &inputData, &printData };
	void(*FunctionPtr[FColSize])(double*, int*);
	int i;


	//FunctionPtr1 = inputData;
	//FunctionPtr2 = printData;
	FunctionPtr[0] = &inputData;
	FunctionPtr[1] = &printData;

	//FunctionPtr1(&RATE, &MIN_BALANCE);
	//FunctionPtr2(&RATE, &MIN_BALANCE);
	//(*FunctionPtr1)(&RATE, &MIN_BALANCE);
	//(*FunctionPtr2)(&RATE, &MIN_BALANCE);
	/*FunctionPtr[0](&RATE, &MIN_BALANCE);
	FunctionPtr[1](&RATE, &MIN_BALANCE);*/
	/*(*FunctionPtr[0])(&RATE, &MIN_BALANCE);
	(*FunctionPtr[1])(&RATE, &MIN_BALANCE);*/
	//(*(*(FunctionPtr + 0)))(&RATE, &MIN_BALANCE);
	//(*(*(FunctionPtr + 1)))(&RATE, &MIN_BALANCE);
	for (i = 0; i < FColSize; i++)
	{
		//		FunctionPtr[i](&RATE, &MIN_BALANCE);
		//		(*(FunctionPtr + i))(&RATE, &MIN_BALANCE);
				//(*FunctionPtr[i])(&RATE, &MIN_BALANCE);
		(*(*(FunctionPtr + i)))(&RATE, &MIN_BALANCE);
	}


	return 0;
}
void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}
void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}

#endif

//=========================================================================================
// 1-3. 일반 변수(call by address) - 함수 포인터 2차원 배열로 변환한 형태
//=========================================================================================
// 가. 함수 포인터 호출 부분을 풀어서 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	//void(*FunctionPtr[FRowSize][FColSize])(double *RATE, int *MIN_BALANCE) = {inputData, printData};
	//void(*FunctionPtr[FRowSize][FColSize])(double *RATE, int *MIN_BALANCE) = { &inputData, &printData };
	void(*FunctionPtr[FRowSize][FColSize])(double* RATE, int* MIN_BALANCE);
	double RATE;
	int MIN_BALANCE;

	//FunctionPtr[0][0] = inputData;
	//FunctionPtr[0][1] = printData;

	FunctionPtr[0][0] = &inputData;
	FunctionPtr[0][1] = &printData;

	//FunctionPtr[0][0](&RATE, &MIN_BALANCE);
	//FunctionPtr[0][1](&RATE, &MIN_BALANCE);

	(*FunctionPtr[0][0])(&RATE, &MIN_BALANCE);
	//(*FunctionPtr[0][1])(&RATE, &MIN_BALANCE);
	(*(*(*(FunctionPtr + 0) + 1)))(&RATE, &MIN_BALANCE);

	return 0;
}
void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}
void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	double RATE;
	int MIN_BALANCE;
	void(*FunctionPtr[FRowSize][FColSize])(double* RATE, int* MIN_BALANCE) = { &inputData, &printData };
	//void(*FunctionPtr[FRowSize][FColSize])(double* RATE, int* MIN_BALANCE) = { inputData, printData };
	/*void(*FunctionPtr[FRowSize][FColSize])(double* RATE, int* MIN_BALANCE);

	FunctionPtr[0][0] = &inputData;
	FunctionPtr[0][1] = &printData;*/

	(*FunctionPtr[0][0])(&RATE, &MIN_BALANCE);
	(*(*(*(FunctionPtr + 0) + 1)))(&RATE, &MIN_BALANCE);


	return 0;
}
void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}
void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}

#endif

// 나. 함수 포인터 호출 부분을 배열로 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	//void(*FunctionPtr[FRowSize][FColSize])(double*, int*) = { inputData, printData };
	//void(*FunctionPtr[FRowSize][FColSize])(double*, int*) = { &inputData, &printData };
	void(*FunctionPtr[FRowSize][FColSize])(double*, int*);
	double RATE;
	int MIN_BALANCE;
	int i, j;

	//FunctionPtr[0][0] = inputData;
	//FunctionPtr[0][1] = printData;
	FunctionPtr[0][0] = &inputData;
	FunctionPtr[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//FunctionPtr[i][j](&RATE, &MIN_BALANCE);
			//(*FunctionPtr[i][j])(&RATE, &MIN_BALANCE);
			(*(*(*(FunctionPtr + i) + j)))(&RATE, &MIN_BALANCE);
		}
	}
	return 0;
}
void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}
void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif

#if 00
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	double RATE;
	int MIN_BALANCE;
	//void(*FunctionPtr[FRowSize][FColSize])(double* RATE, int* MIN_BALANCE) = { &inputData, &printData };
	void(*FunctionPtr[FRowSize][FColSize])(double* RATE, int* MIN_BALANCE) = { inputData, printData };
	//void(*FunctionPtr[FRowSize][FColSize])(double* RATE, int* MIN_BALANCE);

	//FunctionPtr[0][0] = &inputData;
	//FunctionPtr[0][1] = &printData;

	(*FunctionPtr[0][0])(&RATE, &MIN_BALANCE);
	(*(*(*(FunctionPtr + 0) + 1)))(&RATE, &MIN_BALANCE);


	return 0;
}
void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}
void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}

#endif
//=========================================================================================
// 1-4. 일반 변수(call by address) -  typedef를 이용한 함수 포인터
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	double RATE;
	int MIN_BALANCE;
	typedef void(*FunctionPtr)(double*, int*);
	FunctionPtr p1, p2;

	//p1 = inputData;
	//p2 = printData;
	p1 = &inputData;
	p2 = &printData;

	//p1(&RATE, &MIN_BALANCE);
	//p2(&RATE, &MIN_BALANCE);
	(*p1)(&RATE, &MIN_BALANCE);
	(*p2)(&RATE, &MIN_BALANCE);

	return 0;
}
void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}

void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif


//#if 0
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//void inputData(double*, int*);
//void printData(double*, int*);
//
//int main(void) {
//	double RATE;
//	int MIN_BALANCE;
//	typedef void(*FunctionPtr)(double*, int*);
//	FunctionPtr p1, p2;
//	//void(*FunctionPtr1)(double*, int*) = inputData;
//	//void(*FunctionPtr2)(double*, int*) = printData;
//	//void(*FunctionPtr1)(double*, int*) = &inputData;
//	//void(*FunctionPtr2)(double*, int*) = &printData;
//
//
//	//void(*FunctionPtr1)(double*, int*);
//	//void(*FunctionPtr2)(double*, int*);
//
//	//FunctionPtr1 = inputData;
//	//FunctionPtr2 = printData;
//	//p1 = &inputData;
//	//p2 = &printData;
//	p1 = inputData;
//	p2 = printData;
//
//	//FunctionPtr1(&RATE, &MIN_BALANCE);
//	//FunctionPtr2(&RATE, &MIN_BALANCE);
//	(*p1)(&RATE, &MIN_BALANCE);
//	(*p2)(&RATE, &MIN_BALANCE);
//
//	return 0;
//}
//void inputData(double* RATE, int* MIN_BALANCE)
//{
//	scanf("%lf", RATE);
//	scanf("%d", MIN_BALANCE);
//}
//void printData(double* RATE, int* MIN_BALANCE)
//{
//	printf("이자율: %lf\n", *RATE);
//	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
//}
//#endif


#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	double RATE;
	int MIN_BALANCE;
	typedef void(*FunctionPtr[FColSize])(double*, int*);
	//FunctionPtr p = { inputData, printData };
	//FunctionPtr p = { &inputData, &printData };
	FunctionPtr p;

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	//p1(&RATE, &MIN_BALANCE);
	//p2(&RATE, &MIN_BALANCE);
	(*p[0])(&RATE, &MIN_BALANCE);
	(*p[1])(&RATE, &MIN_BALANCE);

	return 0;
}
void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}

void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif

//#if 0
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#define FColSize 2
//
//void inputData(double*, int*);
//void printData(double*, int*);
//
//int main(void) {
//	double RATE;
//	int MIN_BALANCE;
//	typedef void(*FunctionPtr[FColSize])(double*, int*);
//	FunctionPtr p;
//	//void(*FunctionPtr1)(double*, int*) = inputData;
//	//void(*FunctionPtr2)(double*, int*) = printData;
//	//void(*FunctionPtr1)(double*, int*) = &inputData;
//	//void(*FunctionPtr2)(double*, int*) = &printData;
//
//
//	//void(*FunctionPtr1)(double*, int*);
//	//void(*FunctionPtr2)(double*, int*);
//
//	//FunctionPtr1 = inputData;
//	//FunctionPtr2 = printData;
//	//p1 = &inputData;
//	//p2 = &printData;
//	p[0] = inputData;
//	p[1] = printData;
//
//	//FunctionPtr1(&RATE, &MIN_BALANCE);
//	//FunctionPtr2(&RATE, &MIN_BALANCE);
//	(*p[0])(&RATE, &MIN_BALANCE);
//	(*p[1])(&RATE, &MIN_BALANCE);
//
//	return 0;
//}
//void inputData(double* RATE, int* MIN_BALANCE)
//{
//	scanf("%lf", RATE);
//	scanf("%d", MIN_BALANCE);
//}
//void printData(double* RATE, int* MIN_BALANCE)
//{
//	printf("이자율: %lf\n", *RATE);
//	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
//}
//#endif


//=========================================================================================
// 1-5. 일반 변수(call by address) - typedef를 이용한 함수 포인터 - 1차원 배열
//=========================================================================================
// 가. 함수 포인터 호출 부분을 풀어서 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr)(double* RATE, int* MIN_BALANCE);
	//FunctionPtr p[FColSize] = { inputData, printData };
	//FunctionPtr p[FColSize] = { &inputData, &printData };
	FunctionPtr p[FColSize];
	double RATE;
	int MIN_BALANCE;

	//p[0]= inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	////p[0](&RATE, &MIN_BALANCE);
	////p[1](&RATE, &MIN_BALANCE);
	//*p[0](&RATE, &MIN_BALANCE);
	//*p[1](&RATE, &MIN_BALANCE);
	(*(*(p + 0)))(&RATE, &MIN_BALANCE);
	(*(*(p + 1)))(&RATE, &MIN_BALANCE);

	return 0;
}
void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}
void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif

//#if 0
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#define FColSize 2
//
//void inputData(double*, int*);
//void printData(double*, int*);
//
//int main(void) {
//	typedef void(*FunctionPtr)(double* RATE, int* MIN_BALANCE);
//	FunctionPtr p[FColSize];
//	double RATE;
//	int MIN_BALANCE;
//	
//	//p[0] = inputData;
//	//p[1] = printData;
//	p[0] = &inputData;
//	p[1] = &printData;
//
//
//	//p[0](&RATE, &MIN_BALANCE);
//	//p[1](&RATE, &MIN_BALANCE);
//	//*p[0](&RATE, &MIN_BALANCE); // -> 에러 발생
//	//*p[1](&RATE, &MIN_BALANCE);
//	(*(*(p + 0)))(&RATE, &MIN_BALANCE);
//	(*(*(p + 1)))(&RATE, &MIN_BALANCE);
//
//	return 0;
//}
//
//void inputData(double* RATE, int* MIN_BALANCE)
//{
//	scanf("%lf", RATE);
//	scanf("%d", MIN_BALANCE);
//}
//void printData(double* RATE, int* MIN_BALANCE)
//{
//	printf("이자율: %lf\n", *RATE);
//	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
//}
//#endif


#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr[FColSize])(double* RATE, int* MIN_BALANCE);
	//FunctionPtr p = { inputData, printData };
	//FunctionPtr p = { &inputData, &printData };
	FunctionPtr p;
	double RATE;
	int MIN_BALANCE;

	//p[0]= inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	////p[0](&RATE, &MIN_BALANCE);
	////p[1](&RATE, &MIN_BALANCE);
	//*p[0](&RATE, &MIN_BALANCE);
	//*p[1](&RATE, &MIN_BALANCE);
	(*(*(p + 0)))(&RATE, &MIN_BALANCE);
	(*(*(p + 1)))(&RATE, &MIN_BALANCE);

	return 0;
}
void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}
void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif

//#if 0
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#define FColSize 2
//
//void inputData(double*, int*);
//void printData(double*, int*);
//
//int main(void) {
//	typedef void(*FunctionPtr[FColSize])(double* RATE, int* MIN_BALANCE);
//	FunctionPtr p;
//	double RATE;
//	int MIN_BALANCE;
//
//	//p[0] = inputData;
//	//p[1] = printData;
//	p[0] = &inputData;
//	p[1] = &printData;
//
//
//	//p[0](&RATE, &MIN_BALANCE);
//	//p[1](&RATE, &MIN_BALANCE);
//	//*p[0](&RATE, &MIN_BALANCE); // -> 에러 발생
//	//*p[1](&RATE, &MIN_BALANCE);
//	(*(*(p + 0)))(&RATE, &MIN_BALANCE);
//	(*(*(p + 1)))(&RATE, &MIN_BALANCE);
//
//	return 0;
//}
//
//void inputData(double* RATE, int* MIN_BALANCE)
//{
//	scanf("%lf", RATE);
//	scanf("%d", MIN_BALANCE);
//}
//void printData(double* RATE, int* MIN_BALANCE)
//{
//	printf("이자율: %lf\n", *RATE);
//	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
//}
//#endif

// 나. 함수 포인터 호출 부분을 배열로 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr)(double*, int*);
	//FunctionPtr p[FColSize] = { inputData, printData };
	//FunctionPtr p[FColSize] = { &inputData, &printData };
	FunctionPtr p[FColSize];
	double RATE;
	int MIN_BALANCE;
	int i;

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	for (i = 0; i < 2; i++)
	{
		//p[i](&RATE, &MIN_BALANCE);
		//(*p[i])(&RATE, &MIN_BALANCE);
		(*(*(p + i)))(&RATE, &MIN_BALANCE);
	}

	return 0;
}
void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}
void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif

//#if 0
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#define FColSize 2
//
//void inputData(double*, int*);
//void printData(double*, int*);
//
//int main(void) {
//	typedef void(*FunctionPtr)(double* RATE, int* MIN_BALANCE);
//	FunctionPtr p[FColSize];
//	double RATE;
//	int MIN_BALANCE;
//	int i;
//	//p[0] = inputData;
//	//p[1] = printData;
//	p[0] = &inputData;
//	p[1] = &printData;
//
//
//	for (i = 0; i < 2; i++)
//	{
//		//p[i](&RATE, &MIN_BALANCE);
//		//(*p[i])(&RATE, &MIN_BALANCE);
//		(*(*(p + i)))(&RATE, &MIN_BALANCE);
//	}
//
//	//p[0](&RATE, &MIN_BALANCE);
//	//p[1](&RATE, &MIN_BALANCE);
//	//*p[0](&RATE, &MIN_BALANCE); // -> 에러 발생
//	//*p[1](&RATE, &MIN_BALANCE);
//	//(*(*(p + 0)))(&RATE, &MIN_BALANCE);
//	//(*(*(p + 1)))(&RATE, &MIN_BALANCE);
//
//	return 0;
//}
//
//void inputData(double* RATE, int* MIN_BALANCE)
//{
//	scanf("%lf", RATE);
//	scanf("%d", MIN_BALANCE);
//}
//void printData(double* RATE, int* MIN_BALANCE)
//{
//	printf("이자율: %lf\n", *RATE);
//	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
//}
//#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr[FColSize])(double*, int*);
	//FunctionPtr p = { inputData, printData };
	//FunctionPtr p = { &inputData, &printData };
	FunctionPtr p;
	double RATE;
	int MIN_BALANCE;
	int i;

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	for (i = 0; i < 2; i++)
	{
		//p[i](&RATE, &MIN_BALANCE);
		//(*p[i])(&RATE, &MIN_BALANCE);
		(*(*(p + i)))(&RATE, &MIN_BALANCE);
	}

	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}

void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr[FColSize])(double* RATE, int* MIN_BALANCE);
	FunctionPtr p;
	double RATE;
	int MIN_BALANCE;
	int i;
	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;


	for (i = 0; i < 2; i++)
	{
		//p[i](&RATE, &MIN_BALANCE);
		//(*p[i])(&RATE, &MIN_BALANCE);
		(*(*(p + i)))(&RATE, &MIN_BALANCE);
	}



	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}
void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr[FColSize])(double* RATE, int* MIN_BALANCE);
	//FunctionPtr p = { inputData, printData };
	//FunctionPtr p = { &inputData, &printData };
	FunctionPtr p;
	double RATE;
	int MIN_BALANCE;
	int i;

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	for (i = 0; i < 2; i++)
	{
		//p[i](&RATE, &MIN_BALANCE);
		//(*p[i])(&RATE, &MIN_BALANCE);
		(*(*(p + i)))(&RATE, &MIN_BALANCE);
	}

	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}

void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif
//=========================================================================================
// 1-6. 일반 변수(call by address) - typedef를 이용한 함수 포인터 - 1차원 포인터
//=========================================================================================
// 가. 함수 포인터 호출 부분을 풀어서 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <malloc.h>
#define ColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr)(double* RATE, int* MIN_BALANCE);
	FunctionPtr* p;
	double RATE;
	int MIN_BALANCE;

	//p = (FunctionPtr*)malloc(sizeof(FunctionPtr)* ColSize);
	p = new FunctionPtr[ColSize];
	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	//p[0](&RATE, &MIN_BALANCE);
	//p[1](&RATE, &MIN_BALANCE);
	//(*p[0])(&RATE, &MIN_BALANCE);
	//(*p[1])(&RATE, &MIN_BALANCE);
	(*(*(p + 0)))(&RATE, &MIN_BALANCE);
	(*(*(p + 1)))(&RATE, &MIN_BALANCE);

	//free(p);
	delete[] p;
	return 0;
}
void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}
void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <malloc.h>
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr)(double* RATE, int* MIN_BALANCE);
	FunctionPtr* p;
	double RATE;
	int MIN_BALANCE;
	int i;

	p = new FunctionPtr[FColSize];
	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;


	for (i = 0; i < 2; i++)
	{
		//p[i](&RATE, &MIN_BALANCE);
		//(*p[i])(&RATE, &MIN_BALANCE);
		(*(*(p + i)))(&RATE, &MIN_BALANCE);
	}



	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}
void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif


// 나. 함수 포인터 호출 부분을 배열로 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <malloc.h>
#define ColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr)(double* RATE, int* MIN_BALANCE);
	FunctionPtr* p;
	double RATE;
	int MIN_BALANCE;
	int i;

	//p = (FunctionPtr*)malloc(sizeof(FunctionPtr)* ColSize);
	p = new FunctionPtr[ColSize];

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	for (i = 0; i < ColSize; i++)
	{
		//p[i](&RATE, &MIN_BALANCE);
		//(*p[i])(&RATE, &MIN_BALANCE);
		(*(*(p + i)))(&RATE, &MIN_BALANCE);
	}
	//free(p);
	delete[] p;
	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}

void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <malloc.h>
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr)(double* RATE, int* MIN_BALANCE);
	FunctionPtr* p;
	double RATE;
	int MIN_BALANCE;
	int i;

	p = new FunctionPtr[FColSize];
	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;


	for (i = 0; i < FColSize; i++)
	{
		//p[i](&RATE, &MIN_BALANCE);
		//(*p[i])(&RATE, &MIN_BALANCE);
		(*(*(p + i)))(&RATE, &MIN_BALANCE);
	}

	delete[] p;


	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}
void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif
//=========================================================================================
// 1-7. 일반 변수(call by address) - typedef를 이용한 함수 포인터 - 2차원 배열
//=========================================================================================
// 가. 함수 포인터 호출 부분을 풀어서 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define RowSize 1
#define ColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr)(double* RATE, int* MIN_BALANCE);
	//FunctionPtr p[RowSize][ColSize] = {inputData, printData};
	//FunctionPtr p[RowSize][ColSize] = { &inputData, &printData };
	FunctionPtr p[RowSize][ColSize];
	double RATE;
	int MIN_BALANCE;

	//p[0][0]= inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	//p[0][0](&RATE, &MIN_BALANCE);
	//p[0][1](&RATE, &MIN_BALANCE);
	//(*p[0][0])(&RATE, &MIN_BALANCE);
	//(*p[0][1])(&RATE, &MIN_BALANCE);
	//(*(*(*(p+0)+0)))(&RATE, &MIN_BALANCE);
	//(*(*(*(p+0)+1)))(&RATE, &MIN_BALANCE);
	(*(*(*(p))))(&RATE, &MIN_BALANCE);
	(*(*(*(p)+1)))(&RATE, &MIN_BALANCE);
	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}

void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define RowSize 1
#define ColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr)(double* RATE, int* MIN_BALANCE);
	FunctionPtr p[RowSize][ColSize];
	double RATE;
	int MIN_BALANCE;



	//p[0] = inputData;
	//p[1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	//p[0][0](&RATE, &MIN_BALANCE);
	//p[0][1](&RATE, &MIN_BALANCE);
	//(*p[0][0])(&RATE, &MIN_BALANCE);
	//(*p[0][1])(&RATE, &MIN_BALANCE);
	(*(*(*(p))))(&RATE, &MIN_BALANCE);
	(*(*(*(p)+1)))(&RATE, &MIN_BALANCE);

	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}
void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif


#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr[FRowSize])(double* RATE, int* MIN_BALANCE);
	//FunctionPtr p[FColSize] = {inputData, printData};
	//FunctionPtr p[FColSize] = { &inputData, &printData };
	FunctionPtr p[FColSize];
	double RATE;
	int MIN_BALANCE;

	//p[0][0]= inputData;
	//p[1][0] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	//p[0][0](&RATE, &MIN_BALANCE);
	//p[0][1](&RATE, &MIN_BALANCE);
	//(*p[0][0])(&RATE, &MIN_BALANCE);
	//(*p[0][1])(&RATE, &MIN_BALANCE);
	//(*(*(*(p+0)+0)))(&RATE, &MIN_BALANCE);
	//(*(*(*(p+0)+1)))(&RATE, &MIN_BALANCE);
	(*(*(*(p))))(&RATE, &MIN_BALANCE);
	(*(*(*(p)+1)))(&RATE, &MIN_BALANCE);
	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}

void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr[FRowSize])(double* RATE, int* MIN_BALANCE);
	FunctionPtr p[FColSize];
	double RATE;
	int MIN_BALANCE;

	//p[0] = inputData;
	//p[1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	//p[0][0](&RATE, &MIN_BALANCE);
	//p[0][1](&RATE, &MIN_BALANCE);
	//(*p[0][0])(&RATE, &MIN_BALANCE);
	//(*p[0][1])(&RATE, &MIN_BALANCE);
	(*(*(*(p))))(&RATE, &MIN_BALANCE);
	(*(*(*(p)+1)))(&RATE, &MIN_BALANCE);

	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}
void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr[FRowSize][FColSize])(double* RATE, int* MIN_BALANCE);
	//FunctionPtr p = {inputData, printData};
	//FunctionPtr p = { &inputData, &printData };
	FunctionPtr p;
	double RATE;
	int MIN_BALANCE;

	//p[0][0]= inputData;
	//p[1][0] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	//p[0][0](&RATE, &MIN_BALANCE);
	//p[0][1](&RATE, &MIN_BALANCE);
	//(*p[0][0])(&RATE, &MIN_BALANCE);
	//(*p[0][1])(&RATE, &MIN_BALANCE);
	//(*(*(*(p+0)+0)))(&RATE, &MIN_BALANCE);
	//(*(*(*(p+0)+1)))(&RATE, &MIN_BALANCE);
	(*(*(*(p))))(&RATE, &MIN_BALANCE);
	(*(*(*(p)+1)))(&RATE, &MIN_BALANCE);
	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}

void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr[FRowSize][FColSize])(double* RATE, int* MIN_BALANCE);
	FunctionPtr p;
	double RATE;
	int MIN_BALANCE;

	//p[0] = inputData;
	//p[1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	//p[0][0](&RATE, &MIN_BALANCE);
	//p[0][1](&RATE, &MIN_BALANCE);
	//(*p[0][0])(&RATE, &MIN_BALANCE);
	//(*p[0][1])(&RATE, &MIN_BALANCE);
	(*(*(*(p))))(&RATE, &MIN_BALANCE);
	(*(*(*(p)+1)))(&RATE, &MIN_BALANCE);

	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}
void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif

// 나. 함수 포인터 호출 부분을 배열로 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr)(double*, int*);
	//FunctionPtr p[FRowSize][FColSize] = {inputData, printData};
	//FunctionPtr p[FRowSize][FColSize] = { &inputData, &printData };
	FunctionPtr p[FRowSize][FColSize];
	double RATE;
	int MIN_BALANCE;
	int i, j;

	p[0][0] = inputData;
	p[0][1] = printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](&RATE, &MIN_BALANCE);
			//(*p[i][j])(&RATE, &MIN_BALANCE);
			(*(*(*(p + i) + j)))(&RATE, &MIN_BALANCE);
		}
	}
	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}

void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif

//#if 0
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#define FRowSize 1
//#define FColSize 2
//
//void inputData(double*, int*);
//void printData(double*, int*);
//
//int main(void) {
//	typedef void(*FunctionPtr)(double*, int*);
//
//	FunctionPtr p[FRowSize][FColSize];
//	double RATE;
//	int MIN_BALANCE;
//	int i, j;
//
//	p[0][0] = inputData;
//	p[0][1] = printData;
//
//	for (i = 0; i < FRowSize; i++)
//	{
//		for (j = 0; j < FColSize; j++)
//		{
//			//p[i][j](&RATE, &MIN_BALANCE);
//			//(*p[i][j])(&RATE, &MIN_BALANCE);
//			(*(*(*(p + i) + j)))(&RATE, &MIN_BALANCE);
//		}
//	}
//
//	return 0;
//}
//
//void inputData(double* RATE, int* MIN_BALANCE)
//{
//	scanf("%lf", RATE);
//	scanf("%d", MIN_BALANCE);
//}
//void printData(double* RATE, int* MIN_BALANCE)
//{
//	printf("이자율: %lf\n", *RATE);
//	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
//}
//#endif


#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr[FRowSize])(double*, int*);
	//FunctionPtr p[FColSize] = {inputData, printData};
	//FunctionPtr p[FColSize] = { &inputData, &printData };
	FunctionPtr p[FColSize];
	double RATE;
	int MIN_BALANCE;
	int i, j;

	p[0][0] = inputData;
	p[0][1] = printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](&RATE, &MIN_BALANCE);
			//(*p[i][j])(&RATE, &MIN_BALANCE);
			(*(*(*(p + i) + j)))(&RATE, &MIN_BALANCE);
		}
	}
	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}

void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif


//#if 0
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#define FRowSize 1
//#define FColSize 2
//
//void inputData(double*, int*);
//void printData(double*, int*);
//
//int main(void) {
//	typedef void(*FunctionPtr[FRowSize])(double*, int*);
//	//FunctionPtr p[FColSize] = { inputData, printData };
//	//FunctionPtr p[FColSize] = { &inputData, &printData };
//	
//
//	FunctionPtr p[FColSize];
//	double RATE;
//	int MIN_BALANCE;
//	int i, j;
//
//	p[0][0] = inputData;
//	p[0][1] = printData;
//
//	for (i = 0; i < FRowSize; i++)
//	{
//		for (j = 0; j < FColSize; j++)
//		{
//			//p[i][j](&RATE, &MIN_BALANCE);
//			//(*p[i][j])(&RATE, &MIN_BALANCE);
//			(*(*(*(p + i) + j)))(&RATE, &MIN_BALANCE);
//		}
//	}
//
//	return 0;
//}
//
//void inputData(double* RATE, int* MIN_BALANCE)
//{
//	scanf("%lf", RATE);
//	scanf("%d", MIN_BALANCE);
//}
//void printData(double* RATE, int* MIN_BALANCE)
//{
//	printf("이자율: %lf\n", *RATE);
//	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
//}
//#endif


#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr[FRowSize][FColSize])(double*, int*);
	//FunctionPtr p = {inputData, printData};
	//FunctionPtr p = { &inputData, &printData };
	FunctionPtr p;
	double RATE;
	int MIN_BALANCE;
	int i, j;

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](&RATE, &MIN_BALANCE);
			//(*p[i][j])(&RATE, &MIN_BALANCE);
			(*(*(*(p + i) + j)))(&RATE, &MIN_BALANCE);
		}
	}
	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}

void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr[FRowSize][FColSize])(double*, int*);
	//FunctionPtr p[FColSize] = { inputData, printData };
	//FunctionPtr p[FColSize] = { &inputData, &printData };


	FunctionPtr p;
	double RATE;
	int MIN_BALANCE;
	int i, j;

	p[0][0] = inputData;
	p[0][1] = printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](&RATE, &MIN_BALANCE);
			//(*p[i][j])(&RATE, &MIN_BALANCE);
			(*(*(*(p + i) + j)))(&RATE, &MIN_BALANCE);
		}
	}

	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}
void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif

//=========================================================================================
// 1-8. 일반 변수(call by address) - typedef를 이용한 함수 포인터 - 포인터 배열
//=========================================================================================
// 가. 함수 포인터 호출 부분을 풀어서 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr)(double* RATE, int* MIN_BALANCE);
	FunctionPtr* p[FRowSize];
	double RATE;
	int MIN_BALANCE;
	int i;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}

	//p[0][0]= inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	//p[0][0](&RATE, &MIN_BALANCE);
	//p[0][1](&RATE, &MIN_BALANCE);
	//(*p[0][0])(&RATE, &MIN_BALANCE);
	//(*p[0][1])(&RATE, &MIN_BALANCE);
	//(*(*(*(p+0)+0)))(&RATE, &MIN_BALANCE);
	//(*(*(*(p+0)+1)))(&RATE, &MIN_BALANCE);
	(*(*(*(p))))(&RATE, &MIN_BALANCE);
	(*(*(*(p)+1)))(&RATE, &MIN_BALANCE);

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}

void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif



#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr[FRowSize])(double* RATE, int* MIN_BALANCE);
	FunctionPtr* p;
	double RATE;
	int MIN_BALANCE;

	//p = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
	p = new FunctionPtr[FColSize];

	//p[0][0]= inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	//p[0][0](&RATE, &MIN_BALANCE);
	//p[0][1](&RATE, &MIN_BALANCE);
	//(*p[0][0])(&RATE, &MIN_BALANCE);
	//(*p[0][1])(&RATE, &MIN_BALANCE);
	//(*(*(*(p+0)+0)))(&RATE, &MIN_BALANCE);
	//(*(*(*(p+0)+1)))(&RATE, &MIN_BALANCE);
	(*(*(*(p))))(&RATE, &MIN_BALANCE);
	(*(*(*(p)+1)))(&RATE, &MIN_BALANCE);

	//free(p);
	delete[] p;

	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}

void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif



#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr[FRowSize])(double* RATE, int* MIN_BALANCE);
	FunctionPtr* p;
	double RATE;
	int MIN_BALANCE;


	p = new FunctionPtr[FColSize];

	p[0][0] = inputData;
	p[0][1] = printData;

	//p[0][0]= inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	//p[0][0](&RATE, &MIN_BALANCE);
	//p[0][1](&RATE, &MIN_BALANCE);
	//(*p[0][0])(&RATE, &MIN_BALANCE);
	//(*p[0][1])(&RATE, &MIN_BALANCE);
	//(*(*(*(p+0)+0)))(&RATE, &MIN_BALANCE);
	//(*(*(*(p+0)+1)))(&RATE, &MIN_BALANCE);
	(*(*(*(p))))(&RATE, &MIN_BALANCE);
	(*(*(*(p)+1)))(&RATE, &MIN_BALANCE);

	delete[] p;

	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}

void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif

// 나. 함수 포인터 호출 부분을 배열로 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr)(double* RATE, int* MIN_BALANCE);
	FunctionPtr* p[FRowSize];
	double RATE;
	int MIN_BALANCE;
	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}

	//p[0][0] = inputData;
	//p[1][0] = printData;
	p[0][0] = &inputData;
	p[1][0] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](&RATE, &MIN_BALANCE);
			//(*p[i][j])(&RATE, &MIN_BALANCE);
			(*(*(*(p + i) + j)))(&RATE, &MIN_BALANCE);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}

void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr[FRowSize])(double* RATE, int* MIN_BALANCE);
	FunctionPtr* p;
	double RATE;
	int MIN_BALANCE;
	int i, j;

	//p = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
	p = new FunctionPtr[FColSize];


	//p[0][0] = inputData;
	//p[1][0] = printData;
	p[0][0] = &inputData;
	p[1][0] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](&RATE, &MIN_BALANCE);
			//(*p[i][j])(&RATE, &MIN_BALANCE);
			(*(*(*(p + i) + j)))(&RATE, &MIN_BALANCE);
		}
	}

	//free(p);
	delete[] p;

	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}

void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr[FRowSize])(double* RATE, int* MIN_BALANCE);
	FunctionPtr* p;
	double RATE;
	int MIN_BALANCE;
	int i, j;

	p = new FunctionPtr[FColSize];

	//p[0][0] = inputData;
	//p[1][0] = printData;
	p[0][0] = &inputData;
	p[1][0] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](&RATE, &MIN_BALANCE);
			//(*p[i][j])(&RATE, &MIN_BALANCE);
			(*(*(*(p + i) + j)))(&RATE, &MIN_BALANCE);
		}
	}

	delete[] p;

	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}

void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif


//=========================================================================================
// 1-9. 일반 변수(call by address) - typedef를 이용한 함수 포인터 - 배열 포인터
//=========================================================================================
// 가. 함수 포인터 호출 부분을 풀어서 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2
void inputData(double*, int*);
void printData(double*, int*);
int main(void) {
	typedef void(*FunctionPtr)(double* RATE, int* MIN_BALANCE);
	FunctionPtr(*p)[FColSize];
	double RATE;
	int MIN_BALANCE;

	//p = (FunctionPtr(*)[FColSize])malloc(sizeof(FunctionPtr)*FRowSize*FColSize);
	p = new FunctionPtr[FRowSize][FColSize];

	//p[0][0] = inputData;
	//p[1][0] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	//p[0][0](&RATE, &MIN_BALANCE);
	//p[0][1](&RATE, &MIN_BALANCE);
	(*p[0][0])(&RATE, &MIN_BALANCE);
	(*p[0][1])(&RATE, &MIN_BALANCE);

	//free(p);
	delete[] p;
	return 0;
}
void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}
void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr)(double* RATE, int* MIN_BALANCE);
	FunctionPtr(*p)[FColSize];
	double RATE;
	int MIN_BALANCE;
	int i, j;

	p = new FunctionPtr[FColSize][FColSize];

	//p[0][0] = inputData;
	//p[1][0] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	(*p[0][0])(&RATE, &MIN_BALANCE);
	(*p[0][1])(&RATE, &MIN_BALANCE);


	delete[] p;

	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}

void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif
// 나. 함수 포인터 호출 부분을 배열로 작성한 코드

//에러발생
#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr)(double* RATE, int* MIN_BALANCE);
	FunctionPtr(*p)[FColSize];
	double RATE;
	int MIN_BALANCE;
	int i, j;

	//p = (FunctionPtr(*)[FColSize])malloc(sizeof(FunctionPtr)*FRowSize*FColSize);
	p = new FunctionPtr[FRowSize][FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	//p[0][0] = &inputData;
	//p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			p[i][j](&RATE, &MIN_BALANCE);
			//(*p[i][j])(&RATE, &MIN_BALANCE);
			//(*(*(*(p + i) + j)))(&RATE, &MIN_BALANCE);
		}
	}

	//free(p);
	delete[] p;
	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}

void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2

void inputData(double*, int*);
void printData(double*, int*);

int main(void) {
	typedef void(*FunctionPtr)(double* RATE, int* MIN_BALANCE);
	FunctionPtr(*p)[FColSize];
	double RATE;
	int MIN_BALANCE;
	int i, j;

	p = new FunctionPtr[FRowSize][FColSize];

	//p[0][0] = inputData;
	//p[1][0] = printData;
	//p[0][0] = &inputData;
	//p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](&RATE, &MIN_BALANCE);
			(*(*(*(p + i) + j)))(&RATE, &MIN_BALANCE);

		}
	}


	delete[] p;

	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}

void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif
//=========================================================================================
// 1-10. 일반 변수(call by address) - typedef를 이용한 함수 포인터 - 이중 포인터
//=========================================================================================
// 가. 함수 포인터 호출 부분을 풀어서 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2
void inputData(double*, int*);
void printData(double*, int*);
int main(void) {
	typedef void(*FunctionPtr)(double* RATE, int* MIN_BALANCE);
	FunctionPtr** p;
	double RATE;
	int MIN_BALANCE;
	int i;

	//p = (FunctionPtr**)malloc(sizeof(FunctionPtr*)*FRowSize);
	p = new FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}

	//p[0][0]= inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	//p[0][0](&RATE, &MIN_BALANCE);
	//p[0][1](&RATE, &MIN_BALANCE);
	(*p[0][0])(&RATE, &MIN_BALANCE);
	(*p[0][1])(&RATE, &MIN_BALANCE);

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;
	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}

void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif

// 나. 함수 포인터 호출 부분을 배열로 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2
void inputData(double*, int*);
void printData(double*, int*);
int main(void) {
	typedef void(*FunctionPtr)(double* RATE, int* MIN_BALANCE);
	FunctionPtr** p;
	double RATE;
	int MIN_BALANCE;
	int i, j;

	//p = (FunctionPtr**)malloc(sizeof(FunctionPtr*)*FRowSize);
	p = new FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](&RATE, &MIN_BALANCE);
			(*p[i][j])(&RATE, &MIN_BALANCE);
		}

	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;
	return 0;
}

void inputData(double* RATE, int* MIN_BALANCE)
{
	scanf("%lf", RATE);
	scanf("%d", MIN_BALANCE);
}

void printData(double* RATE, int* MIN_BALANCE)
{
	printf("이자율: %lf\n", *RATE);
	printf("계좌최소잔고: %d\n", *MIN_BALANCE);
}
#endif











//=========================================================================================
// 2. 일반 변수(call by reference) - 기본코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void inputData(double&, int&);
void printData(double&, int&);
int main(void) {
	double RATE;
	int MIN_BALANCE;

	inputData(RATE, MIN_BALANCE);
	printData(RATE, MIN_BALANCE);

	return 0;
}
void inputData(double& RATE, int& MIN_BALANCE)
{
	scanf("%lf", &RATE);
	scanf("%d", &MIN_BALANCE);
}
void printData(double& RATE, int& MIN_BALANCE)
{
	printf("이자율: %lf\n", RATE);
	printf("계좌최소잔고: %d\n", MIN_BALANCE);
}
#endif

//=========================================================================================
// 2-1. 일반 변수(call by reference) - 함수 포인터로 변환한 형태
//=========================================================================================
// 가. 함수 포인터 호출 부분을 풀어서 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void inputData(double&, int&);
void printData(double&, int&);

int main(void) {
	double RATE;
	int MIN_BALANCE;
	//void(*FunctionPtr1)(double&, int&) = inputData;
	//void(*FunctionPtr2)(double&, int&) = printData;
	//void(*FunctionPtr1)(double&, int&) = &inputData;
	//void(*FunctionPtr2)(double&, int&) = &printData;
	void(*FunctionPtr1)(double&, int&);
	void(*FunctionPtr2)(double&, int&);

	//FunctionPtr1 = inputData;
	//FunctionPtr2 = printData;
	FunctionPtr1 = &inputData;
	FunctionPtr2 = &printData;

	//FunctionPtr1(RATE, MIN_BALANCE);
	//FunctionPtr2(RATE, MIN_BALANCE);
	//(*FunctionPtr1)(RATE, MIN_BALANCE);
	//(*FunctionPtr2)(RATE, MIN_BALANCE);

	return 0;
}

void inputData(double& RATE, int& MIN_BALANCE)
{
	scanf("%lf", &RATE);
	scanf("%d", &MIN_BALANCE);
}

void printData(double& RATE, int& MIN_BALANCE)
{
	printf("이자율: %lf\n", RATE);
	printf("계좌최소잔고: %d\n", MIN_BALANCE);
}
#endif

//=========================================================================================
// 2-2. 일반 변수(call by reference) - 함수 포인터 1차원 배열로 변환한 형태
//=========================================================================================
// 가. 함수 포인터 호출 부분을 풀어서 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2

void inputData(double&, int&);
void printData(double&, int&);

int main(void) {
	//void(*FunctionPtr[FColSize])(double &RATE, int &MIN_BALANCE) = { inputData, printData};
	//void(*FunctionPtr[FColSize])(double &RATE, int &MIN_BALANCE) = { &inputData, &printData };
	void(*FunctionPtr[FColSize])(double& RATE, int& MIN_BALANCE);
	double RATE;
	int MIN_BALANCE;

	//FunctionPtr[0] = inputData;
	//FunctionPtr[1] = printData;
	FunctionPtr[0] = &inputData;
	FunctionPtr[1] = &printData;

	//FunctionPtr[0](RATE, MIN_BALANCE);
	//FunctionPtr[1](RATE, MIN_BALANCE);
	//(*FunctionPtr[0])(RATE, MIN_BALANCE);
	//(*FunctionPtr[1])(RATE, MIN_BALANCE);	
	(*(*(FunctionPtr + 0)))(RATE, MIN_BALANCE);
	(*(*(FunctionPtr + 1)))(RATE, MIN_BALANCE);

	return 0;
}

void inputData(double& RATE, int& MIN_BALANCE)
{
	scanf("%lf", &RATE);
	scanf("%d", &MIN_BALANCE);
}

void printData(double& RATE, int& MIN_BALANCE)
{
	printf("이자율: %lf\n", RATE);
	printf("계좌최소잔고: %d\n", MIN_BALANCE);
}
#endif

// 나. 함수 포인터 호출 부분을 배열로 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2

void inputData(double&, int&);
void printData(double&, int&);

int main(void) {
	//void(*FunctionPtr[FColSize])(double&, int&) = { inputData, printData };
	//void(*FunctionPtr[FColSize])(double&, int&) = { &inputData, &printData };
	void(*FunctionPtr[FColSize])(double&, int&);
	double RATE;
	int MIN_BALANCE;
	int i;

	//FunctionPtr[0] = inputData;
	//FunctionPtr[1] = printData;
	FunctionPtr[0] = &inputData;
	FunctionPtr[1] = &printData;

	for (i = 0; i < FColSize; i++)
	{
		//FunctionPtr[i](RATE, MIN_BALANCE);
		//(*FunctionPtr[i])(RATE, MIN_BALANCE);
		(*(*(FunctionPtr + i)))(RATE, MIN_BALANCE);
	}
	return 0;
}

void inputData(double& RATE, int& MIN_BALANCE)
{
	scanf("%lf", &RATE);
	scanf("%d", &MIN_BALANCE);
}

void printData(double& RATE, int& MIN_BALANCE)
{
	printf("이자율: %lf\n", RATE);
	printf("계좌최소잔고: %d\n", MIN_BALANCE);
}
#endif 

//=========================================================================================
// 2-3. 일반 변수(call by reference) - 함수 포인터 2차원 배열로 변환한 형태
//=========================================================================================
// 가. 함수 포인터 호출 부분을 풀어서 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2

void inputData(double&, int&);
void printData(double&, int&);

int main(void) {
	//void(*FunctionPtr[FRowSize][FColSize])(double &RATE, int &MIN_BALANCE) = { inputData, printData};
	//void(*FunctionPtr[FRowSize][FColSize])(double &RATE, int &MIN_BALANCE) = { &inputData, &printData };
	void(*FunctionPtr[FRowSize][FColSize])(double& RATE, int& MIN_BALANCE);
	double RATE;
	int MIN_BALANCE;

	//FunctionPtr[0][0] = inputData;
	//FunctionPtr[0][1] = printData;
	FunctionPtr[0][0] = &inputData;
	FunctionPtr[0][1] = &printData;

	//FunctionPtr[0][0](RATE, MIN_BALANCE);
	//FunctionPtr[0][1](RATE, MIN_BALANCE);
	//(*FunctionPtr[0][0])(RATE, MIN_BALANCE);
	//(*FunctionPtr[0][1])(RATE, MIN_BALANCE);
	//(*(*(*(FunctionPtr + 0) + 0)))(RATE, MIN_BALANCE);
	//(*(*(*(FunctionPtr + 0) + 1)))(RATE, MIN_BALANCE);
	(*(*(*(FunctionPtr))))(RATE, MIN_BALANCE);
	(*(*(*(FunctionPtr)+1)))(RATE, MIN_BALANCE);
	return 0;
}
void inputData(double& RATE, int& MIN_BALANCE)
{
	scanf("%lf", &RATE);
	scanf("%d", &MIN_BALANCE);
}
void printData(double& RATE, int& MIN_BALANCE)
{
	printf("이자율: %lf\n", RATE);
	printf("계좌최소잔고: %d\n", MIN_BALANCE);
}
#endif

// 나. 함수 포인터 호출 부분을 배열로 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2

void inputData(double&, int&);
void printData(double&, int&);

int main(void) {
	//void(*FunctionPtr[FRowSize][ColSize])(double&, int&) = { inputData, printData };
	//void(*FunctionPtr[FRowSize][FColSize])(double&, int&) = { &inputData, &printData };
	void(*FunctionPtr[FRowSize][FColSize])(double& RATE, int& MIN_BALANCE);
	double RATE;
	int MIN_BALANCE;
	int i, j;

	//FunctionPtr[0][0] = inputData;
	//FunctionPtr[0][1] = printData;
	FunctionPtr[0][0] = &inputData;
	FunctionPtr[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//FunctionPtr[i][j](RATE, MIN_BALANCE);
			//(*FunctionPtr[i][j])(RATE, MIN_BALANCE);
			(*(*(*(FunctionPtr + i) + j)))(RATE, MIN_BALANCE);
		}
	}
	return 0;
}

void inputData(double& RATE, int& MIN_BALANCE)
{
	scanf("%lf", &RATE);
	scanf("%d", &MIN_BALANCE);
}

void printData(double& RATE, int& MIN_BALANCE)
{
	printf("이자율: %lf\n", RATE);
	printf("계좌최소잔고: %d\n", MIN_BALANCE);
}
#endif 

//=========================================================================================
// 2-4. 일반 변수(call by reference) - typedef를 이용한 함수 포인터
//=========================================================================================
// 가. 함수 포인터 호출 부분을 풀어서 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void inputData(double&, int&);
void printData(double&, int&);

int main(void) {
	double RATE;
	int MIN_BALANCE;
	typedef void(*FunctionPtr1)(double&, int&);
	FunctionPtr1 p1, p2;
	//p1 = inputData;
	//p2 = printData;
	p1 = &inputData;
	p2 = &printData;

	//p1(RATE, MIN_BALANCE);
	//p2(RATE, MIN_BALANCE);
	(*p1)(RATE, MIN_BALANCE);
	(*p2)(RATE, MIN_BALANCE);

	return 0;
}

void inputData(double& RATE, int& MIN_BALANCE)
{
	scanf("%lf", &RATE);
	scanf("%d", &MIN_BALANCE);
}

void printData(double& RATE, int& MIN_BALANCE)
{
	printf("이자율: %lf\n", RATE);
	printf("계좌최소잔고: %d\n", MIN_BALANCE);
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2

void inputData(double&, int&);
void printData(double&, int&);

int main(void) {
	double RATE;
	int MIN_BALANCE;
	typedef void(*FunctionPtr1[FColSize])(double&, int&);
	//FunctionPtr1 p = { inputData, printData };
	FunctionPtr1 p = { &inputData, &printData };

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	//p[0](RATE, MIN_BALANCE);
	//p[1](RATE, MIN_BALANCE);
	//(*p[0])(RATE, MIN_BALANCE);
	//(*p[1])(RATE, MIN_BALANCE);
	//(*(*(p + 0)))(RATE, MIN_BALANCE);
	//(*(*(p + 1)))(RATE, MIN_BALANCE);
	(*(*(p)))(RATE, MIN_BALANCE);
	(*(*(p + 1)))(RATE, MIN_BALANCE);

	return 0;
}

void inputData(double& RATE, int& MIN_BALANCE)
{
	scanf("%lf", &RATE);
	scanf("%d", &MIN_BALANCE);
}

void printData(double& RATE, int& MIN_BALANCE)
{
	printf("이자율: %lf\n", RATE);
	printf("계좌최소잔고: %d\n", MIN_BALANCE);
}
#endif

//=========================================================================================
// 2-5. 일반 변수(call by reference) - typedef를 이용한 함수 포인터 - 1차원 배열
//=========================================================================================
// 가. 함수 포인터 호출 부분을 풀어서 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2

void inputData(double&, int&);
void printData(double&, int&);

int main(void) {
	typedef void(*FunctionPtr)(double& RATE, int& MIN_BALANCE);
	//FunctionPtr p[FColSize] = { inputData, printData };
	//FunctionPtr p[FColSize] = { &inputData, &printData };
	FunctionPtr p[FColSize];
	double RATE;
	int MIN_BALANCE;

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	//p[0](RATE, MIN_BALANCE);
	//p[1](RATE, MIN_BALANCE);
	//(*p[0])(RATE, MIN_BALANCE);
	//(*p[1])(RATE, MIN_BALANCE);
	//(*(*(p + 0)))(RATE, MIN_BALANCE);
	//(*(*(p + 1)))(RATE, MIN_BALANCE);
	(*(*(p)))(RATE, MIN_BALANCE);
	(*(*(p + 1)))(RATE, MIN_BALANCE);

	return 0;
}

void inputData(double& RATE, int& MIN_BALANCE)
{
	scanf("%lf", &RATE);
	scanf("%d", &MIN_BALANCE);
}

void printData(double& RATE, int& MIN_BALANCE)
{
	printf("이자율: %lf\n", RATE);
	printf("계좌최소잔고: %d\n", MIN_BALANCE);
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2

void inputData(double&, int&);
void printData(double&, int&);

int main(void) {
	typedef void(*FunctionPtr[FColSize])(double& RATE, int& MIN_BALANCE);
	//FunctionPtr p = { inputData, printData };
	//FunctionPtr p = { &inputData, &printData };
	FunctionPtr p;
	double RATE;
	int MIN_BALANCE;

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	//p[0](RATE, MIN_BALANCE);
	//p[1](RATE, MIN_BALANCE);
	//(*p[0])(RATE, MIN_BALANCE);
	//(*p[1])(RATE, MIN_BALANCE);
	//(*(*(p + 0)))(RATE, MIN_BALANCE);
	//(*(*(p + 1)))(RATE, MIN_BALANCE);
	(*(*(p)))(RATE, MIN_BALANCE);
	(*(*(p + 1)))(RATE, MIN_BALANCE);

	return 0;
}

void inputData(double& RATE, int& MIN_BALANCE)
{
	scanf("%lf", &RATE);
	scanf("%d", &MIN_BALANCE);
}

void printData(double& RATE, int& MIN_BALANCE)
{
	printf("이자율: %lf\n", RATE);
	printf("계좌최소잔고: %d\n", MIN_BALANCE);
}
#endif

// 나. 함수 포인터 호출 부분을 배열로 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2

void inputData(double&, int&);
void printData(double&, int&);

int main(void) {
	typedef void(*FunctionPtr)(double&, int&);
	//FunctionPtr p[FColSize] = { inputData, printData };
	//FunctionPtr p[FColSize] = { &inputData, &printData };
	FunctionPtr p[FColSize];
	double RATE;
	int MIN_BALANCE;
	int i;

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](RATE, MIN_BALANCE);
		//(*p[i])(RATE, MIN_BALANCE);
		(*(*(p + i)))(RATE, MIN_BALANCE);
	}
	return 0;
}

void inputData(double& RATE, int& MIN_BALANCE)
{
	scanf("%lf", &RATE);
	scanf("%d", &MIN_BALANCE);
}

void printData(double& RATE, int& MIN_BALANCE)
{
	printf("이자율: %lf\n", RATE);
	printf("계좌최소잔고: %d\n", MIN_BALANCE);
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2

void inputData(double&, int&);
void printData(double&, int&);

int main(void) {
	typedef void(*FunctionPtr[FColSize])(double&, int&);
	//FunctionPtr p = { inputData, printData };
	//FunctionPtr p = { &inputData, &printData };
	FunctionPtr p;
	double RATE;
	int MIN_BALANCE;
	int i;

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](RATE, MIN_BALANCE);
		//(*p[i])(RATE, MIN_BALANCE);
		(*(*(p + i)))(RATE, MIN_BALANCE);
	}
	return 0;
}

void inputData(double& RATE, int& MIN_BALANCE)
{
	scanf("%lf", &RATE);
	scanf("%d", &MIN_BALANCE);
}

void printData(double& RATE, int& MIN_BALANCE)
{
	printf("이자율: %lf\n", RATE);
	printf("계좌최소잔고: %d\n", MIN_BALANCE);
}
#endif

//=========================================================================================
// 2-6. 일반 변수(call by reference) - typedef를 이용한 함수 포인터 - 1차원 포인터
//=========================================================================================
// 가. 함수 포인터 호출 부분을 풀어서 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FColSize 2
void inputData(double&, int&);
void printData(double&, int&);
int main(void) {
	typedef void(*FunctionPtr)(double&, int&);
	FunctionPtr* p;
	double RATE;
	int MIN_BALANCE;

	//p = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
	p = new FunctionPtr[FColSize];

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	//p[0](RATE, MIN_BALANCE);
	//p[1](RATE, MIN_BALANCE);
	//(*p[0])(RATE, MIN_BALANCE);
	//(*p[1])(RATE, MIN_BALANCE);
	//(*(*(p + 0)))(RATE, MIN_BALANCE);
	//(*(*(p + 1)))(RATE, MIN_BALANCE);
	(*(*(p)))(RATE, MIN_BALANCE);
	(*(*(p + 1)))(RATE, MIN_BALANCE);

	//free(p);
	delete[] p;
	return 0;
}
void inputData(double& RATE, int& MIN_BALANCE)
{
	scanf("%lf", &RATE);
	scanf("%d", &MIN_BALANCE);
}
void printData(double& RATE, int& MIN_BALANCE)
{
	printf("이자율: %lf\n", RATE);
	printf("계좌최소잔고: %d\n", MIN_BALANCE);
}
#endif

// 나. 함수 포인터 호출 부분을 배열로 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FColSize 2

void inputData(double&, int&);
void printData(double&, int&);

int main(void) {
	typedef void(*FunctionPtr)(double&, int&);
	FunctionPtr* p;
	double RATE;
	int MIN_BALANCE;
	int i;

	//p = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
	p = new FunctionPtr[FColSize];

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](RATE, MIN_BALANCE);
		//(*p[i])(RATE, MIN_BALANCE);
		(*(*(p + i)))(RATE, MIN_BALANCE);
	}

	//free(p);
	delete[] p;
	return 0;
}

void inputData(double& RATE, int& MIN_BALANCE)
{
	scanf("%lf", &RATE);
	scanf("%d", &MIN_BALANCE);
}

void printData(double& RATE, int& MIN_BALANCE)
{
	printf("이자율: %lf\n", RATE);
	printf("계좌최소잔고: %d\n", MIN_BALANCE);
}
#endif


//=========================================================================================
// 2-7. 일반 변수(call by reference) - typedef를 이용한 함수 포인터 - 2차원 배열
//=========================================================================================
// 가. 함수 포인터 호출 부분을 풀어서 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2

void inputData(double&, int&);
void printData(double&, int&);

int main(void) {
	typedef void(*FunctionPtr)(double& RATE, int& MIN_BALANCE);
	//FunctionPtr p[FColSize] = {inputData, printData};
	//FunctionPtr p[FColSize] = { &inputData, &printData };
	FunctionPtr p[FRowSize][FColSize];
	double RATE;
	int MIN_BALANCE;

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	//p[0][0](RATE, MIN_BALANCE);
	//p[0][1](RATE, MIN_BALANCE);
	//(*p[0][0])(RATE, MIN_BALANCE);
	//(*p[0][1])(RATE, MIN_BALANCE);
	//(*(*(*(p + 0) + 0)))(RATE, MIN_BALANCE);
	//(*(*(*(p + 0) + 1)))(RATE, MIN_BALANCE);
	(*(*(*(p))))(RATE, MIN_BALANCE);
	(*(*(*(p)+1)))(RATE, MIN_BALANCE);

	return 0;
}

void inputData(double& RATE, int& MIN_BALANCE)
{
	scanf("%lf", &RATE);
	scanf("%d", &MIN_BALANCE);
}

void printData(double& RATE, int& MIN_BALANCE)
{
	printf("이자율: %lf\n", RATE);
	printf("계좌최소잔고: %d\n", MIN_BALANCE);
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2

void inputData(double&, int&);
void printData(double&, int&);

int main(void) {
	typedef void(*FunctionPtr[FRowSize])(double& RATE, int& MIN_BALANCE);
	//FunctionPtr p[FColSize] = {inputData, printData};
	//FunctionPtr p[FColSize] = { &inputData, &printData };
	FunctionPtr p[FColSize];
	double RATE;
	int MIN_BALANCE;

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	//p[0][0](RATE, MIN_BALANCE);
	//p[0][1](RATE, MIN_BALANCE);
	//(*p[0][0])(RATE, MIN_BALANCE);
	//(*p[0][1])(RATE, MIN_BALANCE);
	//(*(*(*(p + 0) + 0)))(RATE, MIN_BALANCE);
	//(*(*(*(p + 0) + 1)))(RATE, MIN_BALANCE);
	(*(*(*(p))))(RATE, MIN_BALANCE);
	(*(*(*(p)+1)))(RATE, MIN_BALANCE);

	return 0;
}

void inputData(double& RATE, int& MIN_BALANCE)
{
	scanf("%lf", &RATE);
	scanf("%d", &MIN_BALANCE);
}

void printData(double& RATE, int& MIN_BALANCE)
{
	printf("이자율: %lf\n", RATE);
	printf("계좌최소잔고: %d\n", MIN_BALANCE);
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2

void inputData(double&, int&);
void printData(double&, int&);

int main(void) {
	typedef void(*FunctionPtr[FRowSize][FColSize])(double& RATE, int& MIN_BALANCE);
	//FunctionPtr p = {inputData, printData};
	//FunctionPtr p = { &inputData, &printData };
	FunctionPtr p;
	double RATE;
	int MIN_BALANCE;

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	//p[0][0](RATE, MIN_BALANCE);
	//p[0][1](RATE, MIN_BALANCE);
	//(*p[0][0])(RATE, MIN_BALANCE);
	//(*p[0][1])(RATE, MIN_BALANCE);
	//(*(*(*(p + 0) + 0)))(RATE, MIN_BALANCE);
	//(*(*(*(p + 0) + 1)))(RATE, MIN_BALANCE);
	(*(*(*(p))))(RATE, MIN_BALANCE);
	(*(*(*(p)+1)))(RATE, MIN_BALANCE);

	return 0;
}

void inputData(double& RATE, int& MIN_BALANCE)
{
	scanf("%lf", &RATE);
	scanf("%d", &MIN_BALANCE);
}

void printData(double& RATE, int& MIN_BALANCE)
{
	printf("이자율: %lf\n", RATE);
	printf("계좌최소잔고: %d\n", MIN_BALANCE);
}
#endif

// 나. 함수 포인터 호출 부분을 배열로 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2

void inputData(double&, int&);
void printData(double&, int&);

int main(void) {
	typedef void(*FunctionPtr)(double&, int&);
	//FunctionPtr p[FRowSize][FColSize] = {inputData, printData};
	//FunctionPtr p[FRowSize][FColSize] = { &inputData, &printData };
	FunctionPtr p[FRowSize][FColSize];
	double RATE;
	int MIN_BALANCE;
	int i, j;

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](RATE, MIN_BALANCE);
			//(*p[i][j])(RATE, MIN_BALANCE);
			(*(*(*(p + i) + j)))(RATE, MIN_BALANCE);
		}
	}
	return 0;
}

void inputData(double& RATE, int& MIN_BALANCE)
{
	scanf("%lf", &RATE);
	scanf("%d", &MIN_BALANCE);
}

void printData(double& RATE, int& MIN_BALANCE)
{
	printf("이자율: %lf\n", RATE);
	printf("계좌최소잔고: %d\n", MIN_BALANCE);
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2

void inputData(double&, int&);
void printData(double&, int&);

int main(void) {
	typedef void(*FunctionPtr[FRowSize])(double&, int&);
	//FunctionPtr p[FColSize] = {inputData, printData};
	//FunctionPtr p[FColSize] = { &inputData, &printData };
	FunctionPtr p[FColSize];
	double RATE;
	int MIN_BALANCE;
	int i, j;

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](RATE, MIN_BALANCE);
			//(*p[i][j])(RATE, MIN_BALANCE);
			(*(*(*(p + i) + j)))(RATE, MIN_BALANCE);
		}
	}
	return 0;
}

void inputData(double& RATE, int& MIN_BALANCE)
{
	scanf("%lf", &RATE);
	scanf("%d", &MIN_BALANCE);
}

void printData(double& RATE, int& MIN_BALANCE)
{
	printf("이자율: %lf\n", RATE);
	printf("계좌최소잔고: %d\n", MIN_BALANCE);
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2

void inputData(double&, int&);
void printData(double&, int&);

int main(void) {
	typedef void(*FunctionPtr[FRowSize][FColSize])(double&, int&);
	//FunctionPtr p = {inputData, printData};
	//FunctionPtr p = { &inputData, &printData };
	FunctionPtr p;
	double RATE;
	int MIN_BALANCE;
	int i, j;

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](RATE, MIN_BALANCE);
			//(*p[i][j])(RATE, MIN_BALANCE);
			(*(*(*(p + i) + j)))(RATE, MIN_BALANCE);
		}
	}
	return 0;
}

void inputData(double& RATE, int& MIN_BALANCE)
{
	scanf("%lf", &RATE);
	scanf("%d", &MIN_BALANCE);
}

void printData(double& RATE, int& MIN_BALANCE)
{
	printf("이자율: %lf\n", RATE);
	printf("계좌최소잔고: %d\n", MIN_BALANCE);
}
#endif

//=========================================================================================
// 2-8. 일반 변수(call by reference) - typedef를 이용한 함수 포인터 - 포인터 배열
//=========================================================================================
// 가. 함수 포인터 호출 부분을 풀어서 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2

void inputData(double&, int&);
void printData(double&, int&);

int main(void) {
	typedef void(*FunctionPtr)(double& RATE, int& MIN_BALANCE);
	FunctionPtr* p[FRowSize];
	double RATE;
	int MIN_BALANCE;
	int i;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	//p[0][0](RATE, MIN_BALANCE);
	//p[0][1](RATE, MIN_BALANCE);
	//(*p[0][0])(RATE, MIN_BALANCE);
	//(*p[0][1])(RATE, MIN_BALANCE);
	//(*(*(*(p + 0) + 0)))(RATE, MIN_BALANCE);
	//(*(*(*(p + 0) + 1)))(RATE, MIN_BALANCE);
	(*(*(*(p))))(RATE, MIN_BALANCE);
	(*(*(*(p)+1)))(RATE, MIN_BALANCE);

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	return 0;
}

void inputData(double& RATE, int& MIN_BALANCE)
{
	scanf("%lf", &RATE);
	scanf("%d", &MIN_BALANCE);
}

void printData(double& RATE, int& MIN_BALANCE)
{
	printf("이자율: %lf\n", RATE);
	printf("계좌최소잔고: %d\n", MIN_BALANCE);
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2

void inputData(double&, int&);
void printData(double&, int&);

int main(void) {
	typedef void(*FunctionPtr[FRowSize])(double& RATE, int& MIN_BALANCE);
	FunctionPtr* p;
	double RATE;
	int MIN_BALANCE;
	int i;

	//p = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
	p = new FunctionPtr[FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	//p[0][0](RATE, MIN_BALANCE);
	//p[0][1](RATE, MIN_BALANCE);
	//(*p[0][0])(RATE, MIN_BALANCE);
	//(*p[0][1])(RATE, MIN_BALANCE);
	//(*(*(*(p + 0) + 0)))(RATE, MIN_BALANCE);
	//(*(*(*(p + 0) + 1)))(RATE, MIN_BALANCE);
	(*(*(*(p))))(RATE, MIN_BALANCE);
	(*(*(*(p)+1)))(RATE, MIN_BALANCE);

	//free(p);
	delete[] p;

	return 0;
}

void inputData(double& RATE, int& MIN_BALANCE)
{
	scanf("%lf", &RATE);
	scanf("%d", &MIN_BALANCE);
}

void printData(double& RATE, int& MIN_BALANCE)
{
	printf("이자율: %lf\n", RATE);
	printf("계좌최소잔고: %d\n", MIN_BALANCE);
}
#endif

// 나. 함수 포인터 호출 부분을 배열로 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2

void inputData(double&, int&);
void printData(double&, int&);

int main(void) {
	typedef void(*FunctionPtr)(double& RATE, int& MIN_BALANCE);
	FunctionPtr* p[FRowSize];
	double RATE;
	int MIN_BALANCE;
	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](RATE, MIN_BALANCE);
			//(*p[i][j])(RATE, MIN_BALANCE);
			(*(*(*(p + i) + j)))(RATE, MIN_BALANCE);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	return 0;
}

void inputData(double& RATE, int& MIN_BALANCE)
{
	scanf("%lf", &RATE);
	scanf("%d", &MIN_BALANCE);
}

void printData(double& RATE, int& MIN_BALANCE)
{
	printf("이자율: %lf\n", RATE);
	printf("계좌최소잔고: %d\n", MIN_BALANCE);
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2

void inputData(double&, int&);
void printData(double&, int&);

int main(void) {
	typedef void(*FunctionPtr[FRowSize])(double& RATE, int& MIN_BALANCE);
	FunctionPtr* p;
	double RATE;
	int MIN_BALANCE;
	int i, j;


	//p = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
	p = new FunctionPtr[FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](RATE, MIN_BALANCE);
			//(*p[i][j])(RATE, MIN_BALANCE);
			(*(*(*(p + i) + j)))(RATE, MIN_BALANCE);
		}
	}

	//free(p);
	delete[] p;

	return 0;
}

void inputData(double& RATE, int& MIN_BALANCE)
{
	scanf("%lf", &RATE);
	scanf("%d", &MIN_BALANCE);
}

void printData(double& RATE, int& MIN_BALANCE)
{
	printf("이자율: %lf\n", RATE);
	printf("계좌최소잔고: %d\n", MIN_BALANCE);
}
#endif

//=========================================================================================
// 2-9. 일반 변수(call by reference) - typedef를 이용한 함수 포인터 - 배열 포인터
//=========================================================================================
// 가. 함수 포인터 호출 부분을 풀어서 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2

void inputData(double&, int&);
void printData(double&, int&);

int main(void) {
	typedef void(*FunctionPtr)(double& RATE, int& MIN_BALANCE);
	FunctionPtr(*p)[FColSize];
	double RATE;
	int MIN_BALANCE;

	//p = (FunctionPtr(*)[ColSize])malloc(sizeof(FunctionPtr)*FRowSize*FColSize);
	p = new FunctionPtr[FRowSize][FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	//p[0][0](RATE, MIN_BALANCE);
	//p[0][1](RATE, MIN_BALANCE);
	//(*p[0][0])(RATE, MIN_BALANCE);
	//(*p[0][1])(RATE, MIN_BALANCE);
	//(*(*(*(p + 0) + 0)))(RATE, MIN_BALANCE);
	//(*(*(*(p + 0) + 1)))(RATE, MIN_BALANCE);
	(*(*(*(p))))(RATE, MIN_BALANCE);
	(*(*(*(p)+1)))(RATE, MIN_BALANCE);

	//free(p);
	delete[] p;
	return 0;
}
void inputData(double& RATE, int& MIN_BALANCE)
{
	scanf("%lf", &RATE);
	scanf("%d", &MIN_BALANCE);
}
void printData(double& RATE, int& MIN_BALANCE)
{
	printf("이자율: %lf\n", RATE);
	printf("계좌최소잔고: %d\n", MIN_BALANCE);
}
#endif

// 나. 함수 포인터 호출 부분을 배열로 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2

void inputData(double&, int&);
void printData(double&, int&);

int main(void) {
	typedef void(*FunctionPtr)(double& RATE, int& MIN_BALANCE);
	FunctionPtr(*p)[FColSize];
	double RATE;
	int MIN_BALANCE;
	int i, j;

	//p = (FunctionPtr(*)[ColSize])malloc(sizeof(FunctionPtr)*FRowSize*FColSize);
	p = new FunctionPtr[FRowSize][FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](RATE, MIN_BALANCE);
			//(*p[i][j])(RATE, MIN_BALANCE);
			(*(*(*(p + i) + j)))(RATE, MIN_BALANCE);
		}
	}
	//free(p);
	delete[] p;
	return 0;
}

void inputData(double& RATE, int& MIN_BALANCE)
{
	scanf("%lf", &RATE);
	scanf("%d", &MIN_BALANCE);
}

void printData(double& RATE, int& MIN_BALANCE)
{
	printf("이자율: %lf\n", RATE);
	printf("계좌최소잔고: %d\n", MIN_BALANCE);
}
#endif

//=========================================================================================
// 2-10. 일반 변수(call by reference) - typedef를 이용한 함수 포인터 - 이중 포인터
//=========================================================================================
// 가. 함수 포인터 호출 부분을 풀어서 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2

void inputData(double&, int&);
void printData(double&, int&);

int main(void) {
	typedef void(*FunctionPtr)(double& RATE, int& MIN_BALANCE);
	FunctionPtr** p;
	double RATE;
	int MIN_BALANCE;
	int i, j;

	//p = (FunctionPtr**)malloc(sizeof(FunctionPtr*)*FRowSize);
	p = new FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	//p[0][0](RATE, MIN_BALANCE);
	//p[0][1](RATE, MIN_BALANCE);
	//(*p[0][0])(RATE, MIN_BALANCE);
	//(*p[0][1])(RATE, MIN_BALANCE);
	//(*(*(*(p + 0) + 0)))(RATE, MIN_BALANCE);
	//(*(*(*(p + 0) + 1)))(RATE, MIN_BALANCE);
	(*(*(*(p))))(RATE, MIN_BALANCE);
	(*(*(*(p)+1)))(RATE, MIN_BALANCE);

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;
	return 0;
}
void inputData(double& RATE, int& MIN_BALANCE)
{
	scanf("%lf", &RATE);
	scanf("%d", &MIN_BALANCE);
}
void printData(double& RATE, int& MIN_BALANCE)
{
	printf("이자율: %lf\n", RATE);
	printf("계좌최소잔고: %d\n", MIN_BALANCE);
}
#endif

// 나. 함수 포인터 호출 부분을 배열로 작성한 코드
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define RowSize 2
#define ColSize 1
void inputData(double&, int&);
void printData(double&, int&);
int main(void) {
	typedef void(*FunctionPtr)(double& RATE, int& MIN_BALANCE);
	FunctionPtr** p;
	double RATE;
	int MIN_BALANCE;
	int i, j;

	//p = (FunctionPtr**)malloc(sizeof(FunctionPtr*)*RowSize);
	p = new FunctionPtr * [RowSize];
	for (i = 0; i < RowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*ColSize);
		p[i] = new FunctionPtr[ColSize];
	}

	//p[0][0] = inputData;
	//p[1][0] = printData;
	p[0][0] = &inputData;
	p[1][0] = &printData;

	for (i = 0; i < RowSize; i++)
	{
		for (j = 0; j < ColSize; j++)
		{
			//p[i][j](RATE, MIN_BALANCE);
			(*p[i][j])(RATE, MIN_BALANCE);
		}
	}

	for (i = 0; i < RowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;
	return 0;
}
void inputData(double& RATE, int& MIN_BALANCE)
{
	scanf("%lf", &RATE);
	scanf("%d", &MIN_BALANCE);
}
void printData(double& RATE, int& MIN_BALANCE)
{
	printf("이자율: %lf\n", RATE);
	printf("계좌최소잔고: %d\n", MIN_BALANCE);
}
#endif










//=========================================================================================
// 3. 1차원 배열 - 기본코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ColSize 2

void inputData(double[ColSize], int[ColSize], int, int);
void printData(double[ColSize], int[ColSize], int, int);

int main(void) {
	double RATE[ColSize];
	int MIN_BALANCE[ColSize];
	int i, CSize;

	i = 0;
	CSize = ColSize;

	inputData(RATE, MIN_BALANCE, i, CSize);
	printData(RATE, MIN_BALANCE, i, CSize);

	return 0;
}

void inputData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &RATE[i]);
		scanf("%d", &MIN_BALANCE[i]);
	}
}

void printData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", RATE[i]);
		printf("계좌최소잔고: %d\n", MIN_BALANCE[i]);
	}
}
#endif

//=========================================================================================
// 3-1. 1차원 배열 - 함수 포인터로 변환한 형태
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ColSize 2

void inputData(double[ColSize], int[ColSize], int, int);
void printData(double[ColSize], int[ColSize], int, int);

int main(void) {
	double RATE[ColSize];
	int MIN_BALANCE[ColSize];
	//void(*FunctionPtr1)(double[ColSize], int[ColSize], int, int) = inputData;
	//void(*FunctionPtr2)(double[ColSize], int[ColSize], int, int) = printData;
	//void(*FunctionPtr1)(double[ColSize], int[ColSize], int, int) = &inputData;
	//void(*FunctionPtr2)(double[ColSize], int[ColSize], int, int) = &printData;
	void(*FunctionPtr1)(double[ColSize], int[ColSize], int, int);
	void(*FunctionPtr2)(double[ColSize], int[ColSize], int, int);
	int i, CSize;

	//FunctionPtr1 = inputData;
	//FunctionPtr2 = printData;
	FunctionPtr1 = &inputData;
	FunctionPtr2 = &printData;

	i = 0;
	CSize = ColSize;

	//FunctionPtr1(RATE, MIN_BALANCE, i, CSize);
	//FunctionPtr2(RATE, MIN_BALANCE, i, CSize);
	(*FunctionPtr1)(RATE, MIN_BALANCE, i, CSize);
	(*FunctionPtr2)(RATE, MIN_BALANCE, i, CSize);

	return 0;
}

void inputData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &RATE[i]);
		scanf("%d", &MIN_BALANCE[i]);
	}
}

void printData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", RATE[i]);
		printf("계좌최소잔고: %d\n", MIN_BALANCE[i]);
	}
}
#endif

//=========================================================================================
// 3-2. 1차원 배열 - 함수 포인터 1차원 배열로 변환한 형태
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
#define ColSize 2

void inputData(double[ColSize], int[ColSize], int, int);
void printData(double[ColSize], int[ColSize], int, int);

int main(void) {
	double RATE[ColSize];
	int MIN_BALANCE[ColSize];
	int i, CSize;
	//void(*FunctionPtr[FColSize])(double[ColSize], int[ColSize], int, int) = { inputData, printData };
	//void(*FunctionPtr[FColSize])(double[ColSize], int[ColSize], int, int) = { &inputData, &printData };
	void(*FunctionPtr[FColSize])(double[ColSize], int[ColSize], int, int);

	//FunctionPtr[0] = inputData;
	//FunctionPtr[1] = printData;
	FunctionPtr[0] = &inputData;
	FunctionPtr[1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//FunctionPtr[i](RATE, MIN_BALANCE, i, CSize);
		//(*FunctionPtr[i])(RATE, MIN_BALANCE, i, CSize);
		(*(*(FunctionPtr + i)))(RATE, MIN_BALANCE, i, CSize);
	}
	return 0;
}

void inputData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &RATE[i]);
		scanf("%d", &MIN_BALANCE[i]);
	}
}

void printData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", RATE[i]);
		printf("계좌최소잔고: %d\n", MIN_BALANCE[i]);
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
#define ColSize 2

void inputData(double[ColSize], int[ColSize], int, int);
void printData(double[ColSize], int[ColSize], int, int);

int main(void) {
	double RATE[ColSize];
	int MIN_BALANCE[ColSize];
	int i, CSize;
	typedef void(*FunctionPtr[FColSize])(double[ColSize], int[ColSize], int, int);
	FunctionPtr p;

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](RATE, MIN_BALANCE, i, CSize);
		//(*p[i])(RATE, MIN_BALANCE, i, CSize);
		(*(*(p + i)))(RATE, MIN_BALANCE, i, CSize);
	}
	return 0;
}

void inputData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &RATE[i]);
		scanf("%d", &MIN_BALANCE[i]);
	}
}

void printData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", RATE[i]);
		printf("계좌최소잔고: %d\n", MIN_BALANCE[i]);
	}
}
#endif


//=========================================================================================
// 3-3. 1차원 배열 - 함수 포인터 2차원 배열로 변환한 형태
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
#define ColSize 2

void inputData(double[ColSize], int[ColSize], int, int);
void printData(double[ColSize], int[ColSize], int, int);

int main(void) {
	double RATE[ColSize];
	int MIN_BALANCE[ColSize];
	int i, j, CSize;
	//void(*FunctionPtr[FRowSize][FColSize])(double[ColSize], int[ColSize], int, int) = { inputData, printData };
	//void(*FunctionPtr[FRowSize][FColSize])(double[ColSize], int[ColSize], int, int) = { &inputData, &printData };
	void(*FunctionPtr[FRowSize][FColSize])(double[ColSize], int[ColSize], int, int);

	i = 0;
	CSize = ColSize;

	//FunctionPtr[0][0] = inputData;
	//FunctionPtr[0][1] = printData;
	FunctionPtr[0][0] = &inputData;
	FunctionPtr[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//FunctionPtr[i][j](RATE, MIN_BALANCE, i, CSize);
			//(*FunctionPtr[i][j])(RATE, MIN_BALANCE, i, CSize);
			(*(*(*(FunctionPtr + i) + j)))(RATE, MIN_BALANCE, i, CSize);
		}
	}
	return 0;
}

void inputData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &RATE[i]);
		scanf("%d", &MIN_BALANCE[i]);
	}
}

void printData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", RATE[i]);
		printf("계좌최소잔고: %d\n", MIN_BALANCE[i]);
	}
}
#endif

//=========================================================================================
// 3-4. 1차원 배열 - typedef를 이용한 함수 포인터
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ColSize 2

void inputData(double[ColSize], int[ColSize], int, int);
void printData(double[ColSize], int[ColSize], int, int);

int main(void) {
	double RATE[ColSize];
	int MIN_BALANCE[ColSize];
	typedef void(*FunctionPtr1)(double[ColSize], int[ColSize], int, int);
	FunctionPtr1 p1, p2;
	int i, CSize;

	//p1 = inputData;
	//p2 = printData;
	p1 = &inputData;
	p2 = &printData;

	i = 0;
	CSize = ColSize;

	//p1(RATE, MIN_BALANCE, i, CSize);
	//p2(RATE, MIN_BALANCE, i, CSize);
	//(*p1)(RATE, MIN_BALANCE, i, CSize);
	//(*p2)(RATE, MIN_BALANCE, i, CSize);
	(*p1)(RATE, MIN_BALANCE, i, CSize);
	(*p2)(RATE, MIN_BALANCE, i, CSize);

	return 0;
}

void inputData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &RATE[i]);
		scanf("%d", &MIN_BALANCE[i]);
	}
}

void printData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", RATE[i]);
		printf("계좌최소잔고: %d\n", MIN_BALANCE[i]);
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
#define ColSize 2

void inputData(double[ColSize], int[ColSize], int, int);
void printData(double[ColSize], int[ColSize], int, int);

int main(void) {
	double RATE[ColSize];
	int MIN_BALANCE[ColSize];
	typedef void(*FunctionPtr[FColSize])(double[ColSize], int[ColSize], int, int);
	FunctionPtr p;
	int i, CSize;

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](RATE, MIN_BALANCE, i, CSize);
		//(*p[i])(RATE, MIN_BALANCE, i, CSize);
		(*(*(p + i)))(RATE, MIN_BALANCE, i, CSize);
	}
	return 0;
}

void inputData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &RATE[i]);
		scanf("%d", &MIN_BALANCE[i]);
	}
}

void printData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", RATE[i]);
		printf("계좌최소잔고: %d\n", MIN_BALANCE[i]);
	}
}
#endif

//=========================================================================================
// 3-5. 1차원 배열 - typedef를 이용한 함수 포인터 - 1차원 배열
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
#define ColSize 2

void inputData(double[ColSize], int[ColSize], int, int);
void printData(double[ColSize], int[ColSize], int, int);

int main(void) {
	typedef void(*FunctionPtr)(double[ColSize], int[ColSize], int, int);
	//FunctionPtr p[FColSize] = { inputData, printData };
	//FunctionPtr p[FColSize] = { &inputData, &printData };
	FunctionPtr p[FColSize];
	double RATE[ColSize];
	int MIN_BALANCE[ColSize];
	int i, CSize;

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](RATE, MIN_BALANCE, i, CSize);
		//(*p[i])(RATE, MIN_BALANCE, i, CSize);
		(*(*(p + i)))(RATE, MIN_BALANCE, i, CSize);
	}
	return 0;
}

void inputData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &RATE[i]);
		scanf("%d", &MIN_BALANCE[i]);
	}
}

void printData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", RATE[i]);
		printf("계좌최소잔고: %d\n", MIN_BALANCE[i]);
	}
}
#endif

//=========================================================================================
// 3-6. 1차원 배열 - typedef를 이용한 함수 포인터 - 1차원 포인터
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FColSize 2
#define ColSize 2

void inputData(double[ColSize], int[ColSize], int, int);
void printData(double[ColSize], int[ColSize], int, int);

int main(void) {
	typedef void(*FunctionPtr)(double[ColSize], int[ColSize], int, int);
	FunctionPtr* p;
	double RATE[ColSize];
	int MIN_BALANCE[ColSize];
	int i, CSize;

	//p = (FunctionPtr*)malloc(sizeof(FunctionPtr)* FColSize);
	p = new FunctionPtr[FColSize];

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < 2; i++)
	{
		//p[i](RATE, MIN_BALANCE, i, CSize);
		//(*p[i])(RATE, MIN_BALANCE, i, CSize);
		(*(*(p + i)))(RATE, MIN_BALANCE, i, CSize);
	}
	//free(p);
	delete[] p;
	return 0;
}

void inputData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &RATE[i]);
		scanf("%d", &MIN_BALANCE[i]);
	}
}

void printData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", RATE[i]);
		printf("계좌최소잔고: %d\n", MIN_BALANCE[i]);
	}
}
#endif

//=========================================================================================
// 3-7. 1차원 배열 - typedef를 이용한 함수 포인터 - 2차원 배열
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
#define ColSize 2

void inputData(double[ColSize], int[ColSize], int, int);
void printData(double[ColSize], int[ColSize], int, int);

int main(void) {
	typedef void(*FunctionPtr)(double[ColSize], int[ColSize], int, int);
	//FunctionPtr p[FRowSize][FColSize] = { inputData, printData };
	//FunctionPtr p[FRowSize][FColSize] = { &inputData, &printData };
	FunctionPtr p[FRowSize][FColSize];
	double RATE[ColSize];
	int MIN_BALANCE[ColSize];
	int i, j, CSize;

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](RATE, MIN_BALANCE, i, CSize);
			//(*p[i][j])(RATE, MIN_BALANCE, i, CSize);
			(*(*(*(p + i) + j)))(RATE, MIN_BALANCE, i, CSize);
		}
	}
	return 0;
}

void inputData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &RATE[i]);
		scanf("%d", &MIN_BALANCE[i]);
	}
}

void printData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", RATE[i]);
		printf("계좌최소잔고: %d\n", MIN_BALANCE[i]);
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
#define ColSize 2

void inputData(double[ColSize], int[ColSize], int, int);
void printData(double[ColSize], int[ColSize], int, int);

int main(void) {
	typedef void(*FunctionPtr[FRowSize])(double[ColSize], int[ColSize], int, int);
	//FunctionPtr p[FColSize] = { inputData, printData };
	//FunctionPtr p[FColSize] = { &inputData, &printData };
	FunctionPtr p[FColSize];
	double RATE[ColSize];
	int MIN_BALANCE[ColSize];
	int i, j, CSize;

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](RATE, MIN_BALANCE, i, CSize);
			//(*p[i][j])(RATE, MIN_BALANCE, i, CSize);
			(*(*(*(p + i) + j)))(RATE, MIN_BALANCE, i, CSize);
		}
	}
	return 0;
}

void inputData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &RATE[i]);
		scanf("%d", &MIN_BALANCE[i]);
	}
}

void printData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", RATE[i]);
		printf("계좌최소잔고: %d\n", MIN_BALANCE[i]);
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
#define ColSize 2

void inputData(double[ColSize], int[ColSize], int, int);
void printData(double[ColSize], int[ColSize], int, int);

int main(void) {
	typedef void(*FunctionPtr[FRowSize][FColSize])(double[ColSize], int[ColSize], int, int);
	//FunctionPtr p = { inputData, printData };
	//FunctionPtr p = { &inputData, &printData };
	FunctionPtr p;
	double RATE[ColSize];
	int MIN_BALANCE[ColSize];
	int i, j, CSize;

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](RATE, MIN_BALANCE, i, CSize);
			//(*p[i][j])(RATE, MIN_BALANCE, i, CSize);
			(*(*(*(p + i) + j)))(RATE, MIN_BALANCE, i, CSize);
		}
	}
	return 0;
}

void inputData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &RATE[i]);
		scanf("%d", &MIN_BALANCE[i]);
	}
}

void printData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", RATE[i]);
		printf("계좌최소잔고: %d\n", MIN_BALANCE[i]);
	}
}
#endif

//=========================================================================================
// 3-8. 1차원 배열 - typedef를 이용한 함수 포인터 - 포인터 배열
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2
#define ColSize 2

void inputData(double[ColSize], int[ColSize], int, int);
void printData(double[ColSize], int[ColSize], int, int);

int main(void) {
	typedef void(*FunctionPtr[FRowSize])(double[ColSize], int[ColSize], int, int);
	FunctionPtr* p;
	double RATE[ColSize];
	int MIN_BALANCE[ColSize];
	int i, j, CSize;

	//p = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
	p = new FunctionPtr[FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;
	i = 0;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](RATE, MIN_BALANCE, i, CSize);
			(*p[i][j])(RATE, MIN_BALANCE, i, CSize);
		}
	}

	//free(p);
	delete[] p;

	return 0;
}

void inputData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &RATE[i]);
		scanf("%d", &MIN_BALANCE[i]);
	}
}

void printData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", RATE[i]);
		printf("계좌최소잔고: %d\n", MIN_BALANCE[i]);
	}
}
#endif

//=========================================================================================
// 3-9. 1차원 배열 - typedef를 이용한 함수 포인터 - 배열 포인터
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2
#define ColSize 2

void inputData(double[ColSize], int[ColSize], int, int);
void printData(double[ColSize], int[ColSize], int, int);

int main(void) {
	typedef void(*FunctionPtr)(double[ColSize], int[ColSize], int, int);
	FunctionPtr(*p)[FColSize];
	double RATE[ColSize];
	int MIN_BALANCE[ColSize];
	int i, j, CSize;

	//p = (FunctionPtr(*)[FColSize])malloc(sizeof(FunctionPtr)*FRowSize*FColSize);
	p = new FunctionPtr[FRowSize][FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](RATE, MIN_BALANCE, i, CSize);
			//(*p[i][j])(RATE, MIN_BALANCE, i, CSize);
			(*(*(*(p + i) + j)))(RATE, MIN_BALANCE, i, CSize);
		}
	}
	//free(p);
	delete[] p;
	return 0;
}

void inputData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &RATE[i]);
		scanf("%d", &MIN_BALANCE[i]);
	}
}

void printData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", RATE[i]);
		printf("계좌최소잔고: %d\n", MIN_BALANCE[i]);
	}
}
#endif

//=========================================================================================
// 3-10. 1차원 배열 - typedef를 이용한 함수 포인터 - 이중 포인터
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2
#define ColSize 2

void inputData(double[ColSize], int[ColSize], int, int);
void printData(double[ColSize], int[ColSize], int, int);

int main(void) {
	typedef void(*FunctionPtr)(double[ColSize], int[ColSize], int, int);
	FunctionPtr** p;
	double RATE[ColSize];
	int MIN_BALANCE[ColSize];
	int i, j, CSize;

	//p = (FunctionPtr**)malloc(sizeof(FunctionPtr*)*FRowSize);
	p = new FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](RATE, MIN_BALANCE, i, CSize);
			(*p[i][j])(RATE, MIN_BALANCE, i, CSize);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;
	return 0;
}

void inputData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &RATE[i]);
		scanf("%d", &MIN_BALANCE[i]);
	}
}

void printData(double RATE[ColSize], int MIN_BALANCE[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", RATE[i]);
		printf("계좌최소잔고: %d\n", MIN_BALANCE[i]);
	}
}
#endif











//=========================================================================================
// 4. 2차원 배열 - 기본코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define RowSize 1
#define ColSize 2

void inputData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
void printData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);

int main(void) {
	double RATE[RowSize][ColSize];
	int MIN_BALANCE[RowSize][ColSize];
	int i, j, RSize, CSize;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	inputData(RATE, MIN_BALANCE, i, j, RSize, CSize);
	printData(RATE, MIN_BALANCE, i, j, RSize, CSize);

	return 0;
}

void inputData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &RATE[i][j]);
			scanf("%d", &MIN_BALANCE[i][j]);
		}
	}
}

void printData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", RATE[i][j]);
			printf("계좌최소잔고: %d\n", MIN_BALANCE[i][j]);
		}
	}
}
#endif

//=========================================================================================
// 4-1. 2차원 배열 - 함수 포인터로 변환한 형태
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define RowSize 1
#define ColSize 2

void inputData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
void printData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);

int main(void) {
	double RATE[RowSize][ColSize];
	int MIN_BALANCE[RowSize][ColSize];
	//void(*FunctionPtr1)(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int) = inputData;
	//void(*FunctionPtr2)(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int) = printData;
	//void(*FunctionPtr1)(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int) = &inputData;
	//void(*FunctionPtr2)(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int) = &printData;
	void(*FunctionPtr1)(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
	void(*FunctionPtr2)(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
	int i, j, RSize, CSize;

	FunctionPtr1 = inputData;
	FunctionPtr2 = printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	//FunctionPtr1(RATE, MIN_BALANCE, i, j, RSize, CSize);
	//FunctionPtr2(RATE, MIN_BALANCE, i, j, RSize, CSize);
	(*FunctionPtr1)(RATE, MIN_BALANCE, i, j, RSize, CSize);
	(*FunctionPtr2)(RATE, MIN_BALANCE, i, j, RSize, CSize);

	return 0;
}

void inputData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &RATE[i][j]);
			scanf("%d", &MIN_BALANCE[i][j]);
		}
	}
}

void printData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", RATE[i][j]);
			printf("계좌최소잔고: %d\n", MIN_BALANCE[i][j]);
		}
	}
}
#endif

//=========================================================================================
// 4-2. 2차원 배열 - 함수 포인터 1차원 배열로 변환한 형태
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
#define RowSize 1
#define ColSize 2

void inputData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
void printData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);

int main(void) {
	//void(*FunctionPtr[FColSize])(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int) = {inputData, printData};
	//void(*FunctionPtr[FColSize])(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int) = { &inputData, &printData };
	void(*FunctionPtr[FColSize])(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
	double RATE[RowSize][ColSize];
	int MIN_BALANCE[RowSize][ColSize];
	int i, j, RSize, CSize;

	//FunctionPtr[0] = inputData;
	//FunctionPtr[1] = printData;
	FunctionPtr[0] = &inputData;
	FunctionPtr[1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//FunctionPtr[i](RATE, MIN_BALANCE, i, j, RSize, CSize);
		//(*FunctionPtr[i])(RATE, MIN_BALANCE, i, j, RSize, CSize);
		(*(*(FunctionPtr + i)))(RATE, MIN_BALANCE, i, j, RSize, CSize);
	}
	return 0;
}

void inputData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &RATE[i][j]);
			scanf("%d", &MIN_BALANCE[i][j]);
		}
	}
}

void printData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", RATE[i][j]);
			printf("계좌최소잔고: %d\n", MIN_BALANCE[i][j]);
		}
	}
}
#endif

//=========================================================================================
// 4-3. 2차원 배열 - 함수 포인터 2차원 배열로 변환한 형태
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2

void inputData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
void printData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);

int main(void) {
	//void(*FunctionPtr[FRowSize][FColSize])(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int) = {inputData, printData};
	//void(*FunctionPtr[FRowSize][FColSize])(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int) = { &inputData, &printData };
	void(*FunctionPtr[FRowSize][FColSize])(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
	double RATE[RowSize][ColSize];
	int MIN_BALANCE[RowSize][ColSize];
	int i, j, RSize, CSize;

	//FunctionPtr[0][0] = inputData;
	//FunctionPtr[0][1] = printData;
	FunctionPtr[0][0] = &inputData;
	FunctionPtr[0][1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//FunctionPtr[i][j](RATE, MIN_BALANCE, i, j, RSize, CSize);
			//(*FunctionPtr[i][j])(RATE, MIN_BALANCE, i, j, RSize, CSize);
			(*(*(*(FunctionPtr + i) + j)))(RATE, MIN_BALANCE, i, j, RSize, CSize);
		}
	}
	return 0;
}

void inputData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &RATE[i][j]);
			scanf("%d", &MIN_BALANCE[i][j]);
		}
	}
}

void printData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", RATE[i][j]);
			printf("계좌최소잔고: %d\n", MIN_BALANCE[i][j]);
		}
	}
}
#endif

//=========================================================================================
// 4-4. 2차원 배열 - typedef를 이용한 함수 포인터
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define RowSize 1
#define ColSize 2
void inputData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
void printData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
int main(void) {
	double RATE[RowSize][ColSize];
	int MIN_BALANCE[RowSize][ColSize];
	typedef void(*FunctionPtr1)(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
	FunctionPtr1 p1, p2;
	int i, j, RSize, CSize;

	//p1 = inputData;
	//p2 = printData;
	p1 = &inputData;
	p2 = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	//p1(RATE, MIN_BALANCE, i, j, RSize, CSize);
	//p2(RATE, MIN_BALANCE, i, j, RSize, CSize);
	(*p1)(RATE, MIN_BALANCE, i, j, RSize, CSize);
	(*p2)(RATE, MIN_BALANCE, i, j, RSize, CSize);

	return 0;
}
void inputData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &RATE[i][j]);
			scanf("%d", &MIN_BALANCE[i][j]);
		}
	}
}
void printData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", RATE[i][j]);
			printf("계좌최소잔고: %d\n", MIN_BALANCE[i][j]);
		}
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
#define RowSize 1
#define ColSize 2

void inputData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
void printData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);

int main(void) {
	double RATE[RowSize][ColSize];
	int MIN_BALANCE[RowSize][ColSize];
	typedef void(*FunctionPtr[FColSize])(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
	FunctionPtr p;
	int i, j, RSize, CSize;

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	//p[0](RATE, MIN_BALANCE, i, j, RSize, CSize);
	//p[1](RATE, MIN_BALANCE, i, j, RSize, CSize);
	//(*p[0])(RATE, MIN_BALANCE, i, j, RSize, CSize);
	//(*p[1])(RATE, MIN_BALANCE, i, j, RSize, CSize);
	//(*(*(p + 0)))(RATE, MIN_BALANCE, i, j, RSize, CSize);
	//(*(*(p + 1)))(RATE, MIN_BALANCE, i, j, RSize, CSize);
	(*(*(p)))(RATE, MIN_BALANCE, i, j, RSize, CSize);
	(*(*(p + 1)))(RATE, MIN_BALANCE, i, j, RSize, CSize);
	return 0;
}

void inputData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &RATE[i][j]);
			scanf("%d", &MIN_BALANCE[i][j]);
		}
	}
}

void printData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", RATE[i][j]);
			printf("계좌최소잔고: %d\n", MIN_BALANCE[i][j]);
		}
	}
}
#endif

//=========================================================================================
// 4-5. 2차원 배열 - typedef를 이용한 함수 포인터 - 1차원 배열
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
#define RowSize 1
#define ColSize 2

void inputData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
void printData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);

int main(void) {
	typedef void(*FunctionPtr)(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
	//FunctionPtr p[FColSize] = {inputData, printData};
	//FunctionPtr p[FColSize] = { &inputData, &printData };
	FunctionPtr p[FColSize];
	double RATE[RowSize][ColSize];
	int MIN_BALANCE[RowSize][ColSize];
	int i, j, RSize, CSize;

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](RATE, MIN_BALANCE, i, j, RSize, CSize);
		//(*p[i])(RATE, MIN_BALANCE, i, j, RSize, CSize);
		(*(*(p + i)))(RATE, MIN_BALANCE, i, j, RSize, CSize);
	}
	return 0;
}

void inputData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &RATE[i][j]);
			scanf("%d", &MIN_BALANCE[i][j]);
		}
	}
}

void printData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", RATE[i][j]);
			printf("계좌최소잔고: %d\n", MIN_BALANCE[i][j]);
		}
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
#define RowSize 1
#define ColSize 2

void inputData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
void printData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);

int main(void) {
	typedef void(*FunctionPtr[FColSize])(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
	//FunctionPtr p = {inputData, printData};
	//FunctionPtr p = { &inputData, &printData };
	FunctionPtr p;
	double RATE[RowSize][ColSize];
	int MIN_BALANCE[RowSize][ColSize];
	int i, j, RSize, CSize;

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](RATE, MIN_BALANCE, i, j, RSize, CSize);
		//(*p[i])(RATE, MIN_BALANCE, i, j, RSize, CSize);
		(*(*(p + i)))(RATE, MIN_BALANCE, i, j, RSize, CSize);
	}
	return 0;
}

void inputData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &RATE[i][j]);
			scanf("%d", &MIN_BALANCE[i][j]);
		}
	}
}

void printData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", RATE[i][j]);
			printf("계좌최소잔고: %d\n", MIN_BALANCE[i][j]);
		}
	}
}
#endif

//=========================================================================================
// 4-6. 2차원 배열 - typedef를 이용한 함수 포인터 - 1차원 포인터
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FColSize 2
#define RowSize 1
#define ColSize 2

void inputData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
void printData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);

int main(void) {
	typedef void(*FunctionPtr)(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
	FunctionPtr* p;
	double RATE[RowSize][ColSize];
	int MIN_BALANCE[RowSize][ColSize];
	int i, j, RSize, CSize;

	//p = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
	p = new FunctionPtr[FColSize];

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](RATE, MIN_BALANCE, i, j, RSize, CSize);
		//(*p[i])(RATE, MIN_BALANCE, i, j, RSize, CSize);
		(*(*(p + i)))(RATE, MIN_BALANCE, i, j, RSize, CSize);
	}
	//free(p);
	delete[] p;
	return 0;
}

void inputData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &RATE[i][j]);
			scanf("%d", &MIN_BALANCE[i][j]);
		}
	}
}

void printData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", RATE[i][j]);
			printf("계좌최소잔고: %d\n", MIN_BALANCE[i][j]);
		}
	}
}
#endif

//=========================================================================================
// 4-7. 2차원 배열 - typedef를 이용한 함수 포인터 - 2차원 배열
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2

void inputData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
void printData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);

int main(void) {
	typedef void(*FunctionPtr)(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
	//FunctionPtr p[FRowSize][FColSize] = { inputData, printData };
	//FunctionPtr p[FRowSize][FColSize] = { &inputData, &printData };
	FunctionPtr p[FRowSize][FColSize];
	double RATE[RowSize][ColSize];
	int MIN_BALANCE[RowSize][ColSize];
	int i, j, RSize, CSize;

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](RATE, MIN_BALANCE, i, j, RSize, CSize);
			//(*p[i][j])(RATE, MIN_BALANCE, i, j, RSize, CSize);
			(*(*(*(p + i) + j)))(RATE, MIN_BALANCE, i, j, RSize, CSize);
		}
	}
	return 0;
}

void inputData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &RATE[i][j]);
			scanf("%d", &MIN_BALANCE[i][j]);
		}
	}
}

void printData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", RATE[i][j]);
			printf("계좌최소잔고: %d\n", MIN_BALANCE[i][j]);
		}
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2

void inputData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
void printData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);

int main(void) {
	typedef void(*FunctionPtr[FRowSize])(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
	//FunctionPtr p[FColSize] = { inputData, printData };
	//FunctionPtr p[FColSize] = { &inputData, &printData };
	FunctionPtr p[FColSize];
	double RATE[RowSize][ColSize];
	int MIN_BALANCE[RowSize][ColSize];
	int i, j, RSize, CSize;

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](RATE, MIN_BALANCE, i, j, RSize, CSize);
			//(*p[i][j])(RATE, MIN_BALANCE, i, j, RSize, CSize);
			(*(*(*(p + i) + j)))(RATE, MIN_BALANCE, i, j, RSize, CSize);
		}
	}
	return 0;
}

void inputData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &RATE[i][j]);
			scanf("%d", &MIN_BALANCE[i][j]);
		}
	}
}

void printData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", RATE[i][j]);
			printf("계좌최소잔고: %d\n", MIN_BALANCE[i][j]);
		}
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2

void inputData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
void printData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);

int main(void) {
	typedef void(*FunctionPtr[FRowSize][FColSize])(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
	//FunctionPtr p = { inputData, printData };
	//FunctionPtr p = { &inputData, &printData };
	FunctionPtr p;
	double RATE[RowSize][ColSize];
	int MIN_BALANCE[RowSize][ColSize];
	int i, j, RSize, CSize;

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](RATE, MIN_BALANCE, i, j, RSize, CSize);
			//(*p[i][j])(RATE, MIN_BALANCE, i, j, RSize, CSize);
			(*(*(*(p + i) + j)))(RATE, MIN_BALANCE, i, j, RSize, CSize);
		}
	}
	return 0;
}

void inputData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &RATE[i][j]);
			scanf("%d", &MIN_BALANCE[i][j]);
		}
	}
}

void printData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", RATE[i][j]);
			printf("계좌최소잔고: %d\n", MIN_BALANCE[i][j]);
		}
	}
}
#endif

//=========================================================================================
// 4-8. 2차원 배열 - typedef를 이용한 함수 포인터 - 포인터 배열
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2

void inputData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
void printData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);

int main(void) {
	typedef void(*FunctionPtr)(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
	FunctionPtr* p[FRowSize];
	double RATE[RowSize][ColSize];
	int MIN_BALANCE[RowSize][ColSize];
	int i, j, RSize, CSize;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](RATE, MIN_BALANCE, i, j, RSize, CSize);
			//(*p[i][j])(RATE, MIN_BALANCE, i, j, RSize, CSize);
			(*(*(*(p + i) + j)))(RATE, MIN_BALANCE, i, j, RSize, CSize);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	return 0;
}

void inputData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &RATE[i][j]);
			scanf("%d", &MIN_BALANCE[i][j]);
		}
	}
}

void printData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", RATE[i][j]);
			printf("계좌최소잔고: %d\n", MIN_BALANCE[i][j]);
		}
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2

void inputData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
void printData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);

int main(void) {
	typedef void(*FunctionPtr[FRowSize])(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
	FunctionPtr* p;
	double RATE[RowSize][ColSize];
	int MIN_BALANCE[RowSize][ColSize];
	int i, j, RSize, CSize;

	//p = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
	p = new FunctionPtr[FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](RATE, MIN_BALANCE, i, j, RSize, CSize);
			//(*p[i][j])(RATE, MIN_BALANCE, i, j, RSize, CSize);
			(*(*(*(p + i) + j)))(RATE, MIN_BALANCE, i, j, RSize, CSize);
		}
	}

	//free(p);
	delete[] p;
	return 0;
}

void inputData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &RATE[i][j]);
			scanf("%d", &MIN_BALANCE[i][j]);
		}
	}
}

void printData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", RATE[i][j]);
			printf("계좌최소잔고: %d\n", MIN_BALANCE[i][j]);
		}
	}
}
#endif
//=========================================================================================
// 4-9. 2차원 배열 - typedef를 이용한 함수 포인터 - 배열 포인터
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2

void inputData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
void printData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);

int main(void) {
	typedef void(*FunctionPtr)(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
	FunctionPtr(*p)[FColSize];
	double RATE[RowSize][ColSize];
	int MIN_BALANCE[RowSize][ColSize];
	int i, j, RSize, CSize;

	//p = (FunctionPtr(*)[FColSize])malloc(sizeof(FunctionPtr)*FRowSize*FColSize);
	p = new FunctionPtr[FRowSize][FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](RATE, MIN_BALANCE, i, j, RSize, CSize);
			(*p[i][j])(RATE, MIN_BALANCE, i, j, RSize, CSize);
		}
	}
	//free(p);
	delete[] p;
	return 0;
}

void inputData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &RATE[i][j]);
			scanf("%d", &MIN_BALANCE[i][j]);
		}
	}
}

void printData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", RATE[i][j]);
			printf("계좌최소잔고: %d\n", MIN_BALANCE[i][j]);
		}
	}
}
#endif

//=========================================================================================
// 4-10. 2차원 배열 - typedef를 이용한 함수 포인터 - 이중 포인터
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2

void inputData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
void printData(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);

int main(void) {
	typedef void(*FunctionPtr)(double[RowSize][ColSize], int[RowSize][ColSize], int, int, int, int);
	FunctionPtr** p;
	double RATE[RowSize][ColSize];
	int MIN_BALANCE[RowSize][ColSize];
	int i, j, RSize, CSize;

	//p = (FunctionPtr**)malloc(sizeof(FunctionPtr*)*FRowSize);
	p = new FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](RATE, MIN_BALANCE, i, j, RSize, CSize);
			(*p[i][j])(RATE, MIN_BALANCE, i, j, RSize, CSize);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;
	return 0;
}

void inputData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &RATE[i][j]);
			scanf("%d", &MIN_BALANCE[i][j]);
		}
	}
}

void printData(double RATE[RowSize][ColSize], int MIN_BALANCE[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", RATE[i][j]);
			printf("계좌최소잔고: %d\n", MIN_BALANCE[i][j]);
		}
	}
}
#endif










//=========================================================================================
// 5. 구조체 변수(call by value) - 기본코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	x = inputData(x);
	x = printData(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	return 0;
}

SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}

SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

//=========================================================================================
// 5-1. 구조체 변수(call by value) - 함수 포인터로 변환한 형태
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData inputData(SData);
SData printData(SData);

int main(void) {
	SData x;
	//SData(*FunctionPtr1)(SData) = inputData;
	//SData(*FunctionPtr2)(SData) = printData;
	//SData(*FunctionPtr1)(SData) = &inputData;
	//SData(*FunctionPtr2)(SData) = &printData;
	SData(*FunctionPtr1)(SData);
	SData(*FunctionPtr2)(SData);
	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	//FunctionPtr1 = inputData;
	//FunctionPtr2 = printData;
	FunctionPtr1 = &inputData;
	FunctionPtr2 = &printData;

	//x = FunctionPtr1(x);
	//x = FunctionPtr2(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성
	x = (*FunctionPtr1)(x);
	x = (*FunctionPtr2)(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성
	return 0;
}

SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}

SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData(*FunctionPtr1)(struct _SData);
	struct _SData(*FunctionPtr2)(struct _SData);
}SData;

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.
	//x.FunctionPtr1 = inputData;
	//x.FunctionPtr2 = printData;
	x.FunctionPtr1 = &inputData;
	x.FunctionPtr2 = &printData;

	//x = x.FunctionPtr1(x);
	//x = x.FunctionPtr2(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성
	x = (*x.FunctionPtr1)(x);
	x = (*x.FunctionPtr2)(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData inputData(struct _SData);
	struct _SData printData(struct _SData);
}SData;

SData SData::inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData SData::printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
int main(void) {
	SData x;
	//SData(SData::*FunctionPtr1)(SData) = &(SData::inputData);
	//SData(SData::*FunctionPtr2)(SData) = &(SData::printData);
	SData(SData:: * FunctionPtr1)(SData);
	SData(SData:: * FunctionPtr2)(SData);

	FunctionPtr1 = &(SData::inputData);
	FunctionPtr2 = &(SData::printData);

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = (x.SData::inputData)(x);
	//x = (x.SData::printData)(x);

	x = ((x.*FunctionPtr1))(x);
	x = ((x.*FunctionPtr2))(x);

	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData inputData(struct _SData);
	struct _SData printData(struct _SData);
}SData;

SData SData::inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData SData::printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}

typedef struct _Type
{
	SData(SData::* FunctionPtr1)(SData);
	SData(SData::* FunctionPtr2)(SData);
}Type;

int main(void) {
	SData x;
	Type fp;

	fp.FunctionPtr1 = &(SData::inputData);
	fp.FunctionPtr2 = &(SData::printData);

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = (x.SData::inputData)(x);
	//x = (x.SData::printData)(x);

	x = (x.*fp.FunctionPtr1)(x);
	x = (x.*fp.FunctionPtr2)(x);

	return 0;
}
#endif

//=========================================================================================
// 5-2. 구조체 변수(call by value) - 함수 포인터 1차원 배열로 변환한 형태
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData inputData(SData);
SData printData(SData);
int main(void) {
	//SData(*FunctionPtr[FColSize])(SData) = { inputData, printData };
	SData(*FunctionPtr[FColSize])(SData) = { &inputData, &printData };
	SData x;
	int i;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < FColSize; i++)
	{
		//x = FunctionPtr[i](x);
		x = (*FunctionPtr[i])(x);
	}
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData(*FunctionPtr[FColSize])(struct _SData);
}SData;

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;
	int i;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.
	//x.FunctionPtr[0] = inputData;
	//x.FunctionPtr[1] = printData;
	x.FunctionPtr[0] = &inputData;
	x.FunctionPtr[1] = &printData;

	for (i = 0; i < FColSize; i++)
	{
		//x = x.FunctionPtr[i](x);
		x = (*x.FunctionPtr[i])(x);
	}
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData inputData(struct _SData);
	struct _SData printData(struct _SData);
}SData;

SData SData::inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData SData::printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	int i;
	//SData(SData::*FunctionPtr[FColSize])(SData) = { &SData::inputData, &SData::printData };
	SData(SData:: * FunctionPtr[FColSize])(SData);

	FunctionPtr[0] = &SData::inputData;
	FunctionPtr[1] = &SData::printData;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = (x.SData::inputData)(x);
	//x = (x.SData::printData)(x);

	for (i = 0; i < FColSize; i++)
	{
		// = ((x.*FunctionPtr[i]))(x);
		x = ((x.*FunctionPtr[i]))(x);
	}
	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData inputData(struct _SData);
	struct _SData printData(struct _SData);
}SData;

SData SData::inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData SData::printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
typedef struct _Type
{
	SData(SData::* FunctionPtr[FColSize])(SData);
}Type;

int main(void) {
	SData x;
	Type fp;
	int i;

	fp.FunctionPtr[0] = &SData::inputData;
	fp.FunctionPtr[1] = &SData::printData;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = (x.SData::inputData)(x);
	//x = (x.SData::printData)(x);

	for (i = 0; i < FColSize; i++)
	{
		x = ((x.*fp.FunctionPtr[i]))(x);
	}
	return 0;
}
#endif

//=========================================================================================
// 5-3. 구조체 변수(call by value) - 함수 포인터 2차원 배열로 변환한 형태
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData inputData(SData);
SData printData(SData);
int main(void) {
	//SData(*FunctionPtr[FRowSize][FColSize])(SData) = { inputData, printData };
	SData(*FunctionPtr[FRowSize][FColSize])(SData) = { &inputData, &printData };
	SData x;
	int i, j;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = FunctionPtr[i][j](x);
			x = (*FunctionPtr[i][j])(x);
		}
	}
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData(*FunctionPtr[FRowSize][FColSize])(struct _SData);
}SData;

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;
	int i, j;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.
	//x.FunctionPtr[0][0] = inputData;
	//x.FunctionPtr[0][1] = printData;
	x.FunctionPtr[0][0] = &inputData;
	x.FunctionPtr[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = x.FunctionPtr[i][j](x);
			x = (*x.FunctionPtr[i][j])(x);
		}
	}
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData inputData(struct _SData);
	struct _SData printData(struct _SData);
}SData;
SData SData::inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData SData::printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	//SData(SData::*FunctionPtr[FRowSize][FColSize])(SData) = { &SData::inputData, &SData::printData };
	SData(SData:: * FunctionPtr[FRowSize][FColSize])(SData);
	FunctionPtr[0][0] = &SData::inputData;
	FunctionPtr[0][1] = &SData::printData;
	int i, j;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = (x.*FunctionPtr[i][j])(x);
		}
	}

	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData inputData(struct _SData);
	struct _SData printData(struct _SData);
}SData;

SData SData::inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData SData::printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
typedef struct _Type
{
	SData(SData::* FunctionPtr[FRowSize][FColSize])(SData);

}Type;

int main(void) {
	SData x;
	Type fp;

	fp.FunctionPtr[0][0] = &SData::inputData;
	fp.FunctionPtr[0][1] = &SData::printData;
	int i, j;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = (x.*fp.FunctionPtr[i][j])(x);
		}
	}

	return 0;
}
#endif

//=========================================================================================
// 5-5. 구조체 변수(call by value) - typedef를 이용한 함수 포인터
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData inputData(SData);
SData printData(SData);
int main(void) {
	typedef SData(*FunctionPtr1)(SData);
	FunctionPtr1 p1, p2;
	SData x;
	int i;

	//p1 = inputData;
	//p2 = printData;
	p1 = &inputData;
	p2 = &printData;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	//x = p1(x);
	//x = p2(x);
	x = (*p1)(x);
	x = (*p2)(x);

	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef struct _SData(*FunctionPtr)(struct _SData);
}SData;

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData::FunctionPtr p1, p2;
	SData x;
	int i;

	//p1 = inputData;
	//p2 = printData;
	p1 = &inputData;
	p2 = &printData;
	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	//x = p1(x);
	//x = p2(x);
	x = (*p1)(x);
	x = (*p2)(x);

	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData inputData(struct _SData);
	struct _SData printData(struct _SData);
}SData;

SData SData::inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData SData::printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	typedef SData(SData:: * FunctionPtr)(SData);
	FunctionPtr p1, p2;
	int i;

	p1 = &(SData::inputData);
	p2 = &(SData::printData);
	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	x = (x.*p1)(x);
	x = (x.*p2)(x);
	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData inputData(struct _SData);
	struct _SData printData(struct _SData);
}SData;

SData SData::inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData SData::printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}

typedef struct _Type
{
	typedef SData(SData::* FunctionPtr)(SData);
}Type;

int main(void) {
	SData x;
	Type::FunctionPtr p1, p2;
	int i;

	p1 = &(SData::inputData);
	p2 = &(SData::printData);
	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	x = (x.*p1)(x);
	x = (x.*p2)(x);

	return 0;
}
#endif


//=========================================================================================
// 5-5. 구조체 변수(call by value) - typedef를 이용한 함수 포인터 - 1차원 배열
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData inputData(SData);
SData printData(SData);
int main(void) {
	typedef SData(*FunctionPtr)(SData);
	//FunctionPtr p[FColSize] = { inputData, printData };
	FunctionPtr p[FColSize] = { &inputData, &printData };
	SData x;
	int i;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < FColSize; i++)
	{
		//x = p[i](x);
		x = (*p[i])(x);
	}
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef struct _SData(*FunctionPtr)(struct _SData);
}SData;

SData inputData(SData);
SData printData(SData);
int main(void) {
	//SData::FunctionPtr p[FColSize] = { inputData, printData };
	SData::FunctionPtr p[FColSize] = { &inputData, &printData };
	SData x;
	int i;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < FColSize; i++)
	{
		//x = p[i](x);
		x = (*p[i])(x);
	}
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData inputData(struct _SData);
	struct _SData printData(struct _SData);
}SData;

SData SData::inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData SData::printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	typedef SData(SData:: * FunctionPtr)(SData);
	FunctionPtr p[FColSize];
	int i;

	p[0] = &(SData::inputData);
	p[1] = &(SData::printData);
	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FColSize; i++)
	{
		x = (x.*p[i])(x);
	}
	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData inputData(struct _SData);
	struct _SData printData(struct _SData);
}SData;

SData SData::inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData SData::printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}

typedef struct _Type
{
	typedef SData(SData::* FunctionPtr)(SData);
}Type;

int main(void) {
	SData x;
	Type::FunctionPtr p[FColSize];
	int i;

	p[0] = &(SData::inputData);
	p[1] = &(SData::printData);
	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FColSize; i++)
	{
		x = (x.*p[i])(x);
	}
	return 0;
}
#endif

//=========================================================================================
// 5-6. 구조체 변수(call by value) - typedef를 이용한 함수 포인터 - 1차원 포인터
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData inputData(SData);
SData printData(SData);
int main(void) {
	typedef SData(*FunctionPtr)(SData);
	FunctionPtr* p;
	SData x;
	int i;

	//p = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
	p = new FunctionPtr[FColSize];
	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;
	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < FColSize; i++)
	{
		//x = p[i](x);
		x = (*p[i])(x);
	}

	//free(p);
	delete[] p;
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef struct _SData(*FunctionPtr)(struct _SData);
}SData;

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData::FunctionPtr* p;
	SData x;
	int i;

	//p = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
	p = new SData::FunctionPtr[FColSize];

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < FColSize; i++)
	{
		//x = p[i](x);
		x = (*p[i])(x);
	}

	//free(p);
	delete[] p;
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData inputData(struct _SData);
	struct _SData printData(struct _SData);
}SData;

SData SData::inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData SData::printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	typedef SData(SData:: * FunctionPtr)(SData);
	FunctionPtr* p;
	int i;

	//p = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
	p = new FunctionPtr[FColSize];

	p[0] = &(SData::inputData);
	p[1] = &(SData::printData);
	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FColSize; i++)
	{
		x = (x.*p[i])(x);
	}
	//free(p);
	delete[] p;

	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData inputData(struct _SData);
	struct _SData printData(struct _SData);
}SData;

SData SData::inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData SData::printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
typedef struct _Type
{
	typedef SData(SData::* FunctionPtr)(SData);
}Type;

int main(void) {
	SData x;
	Type::FunctionPtr* p;
	int i;

	//p = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
	p = new Type::FunctionPtr[FColSize];

	p[0] = &(SData::inputData);
	p[1] = &(SData::printData);
	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FColSize; i++)
	{
		x = (x.*p[i])(x);
	}
	//free(p);
	delete[] p;

	return 0;
}
#endif

//=========================================================================================
// 5-7. 구조체 변수(call by value) - typedef를 이용한 함수 포인터 - 2차원 배열
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData inputData(SData);
SData printData(SData);
int main(void) {
	typedef SData(*FunctionPtr)(SData);
	//FunctionPtr p[FRowSize][FColSize] = { inputData, printData };
	FunctionPtr p[FRowSize][FColSize] = { &inputData, &printData };
	SData x;
	int i, j;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef struct _SData(*FunctionPtr)(struct _SData);
}SData;

SData inputData(SData);
SData printData(SData);
int main(void) {
	//SData::FunctionPtr p[FRowSize][FColSize] = { inputData, printData };
	SData::FunctionPtr p[FRowSize][FColSize] = { &inputData, &printData };
	SData x;
	int i, j;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData inputData(struct _SData);
	struct _SData printData(struct _SData);
}SData;

SData SData::inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData SData::printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	typedef SData(SData:: * FunctionPtr)(SData);
	FunctionPtr p[FRowSize][FColSize];
	int i, j;

	p[0][0] = &(SData::inputData);
	p[0][1] = &(SData::printData);
	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = (x.*p[i][j])(x);
		}
	}
	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData inputData(struct _SData);
	struct _SData printData(struct _SData);
}SData;

SData SData::inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData SData::printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}

typedef struct _Type
{
	typedef SData(SData::* FunctionPtr)(SData);
}Type;

int main(void) {
	SData x;
	Type::FunctionPtr p[FRowSize][FColSize];
	int i, j;

	p[0][0] = &(SData::inputData);
	p[0][1] = &(SData::printData);
	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = (x.*p[i][j])(x);
		}
	}
	return 0;
}
#endif

//=========================================================================================
// 5-8. 구조체 변수(call by value) - typedef를 이용한 함수 포인터 - 포인터 배열
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData inputData(SData);
SData printData(SData);
int main(void) {
	typedef SData(*FunctionPtr)(SData);
	FunctionPtr* p[FRowSize];
	SData x;
	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}
	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef struct _SData(*FunctionPtr)(struct _SData);
}SData;

SData inputData(SData);
SData printData(SData);
int main(void) {

	SData::FunctionPtr* p[FRowSize];
	SData x;
	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
		p[i] = new SData::FunctionPtr[FColSize];
	}
	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;


	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData inputData(struct _SData);
	struct _SData printData(struct _SData);
}SData;

SData SData::inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData SData::printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	typedef SData(SData:: * FunctionPtr)(SData);
	FunctionPtr* p[FRowSize];
	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}

	p[0][0] = &(SData::inputData);
	p[0][1] = &(SData::printData);
	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = (x.*p[i][j])(x);
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}

	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData inputData(struct _SData);
	struct _SData printData(struct _SData);
}SData;

SData SData::inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData SData::printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
typedef struct _Type
{
	typedef SData(SData::* FunctionPtr)(SData);
}Type;

int main(void) {
	SData x;
	Type::FunctionPtr* p[FRowSize];
	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
		p[i] = new Type::FunctionPtr[FColSize];
	}

	p[0][0] = &(SData::inputData);
	p[0][1] = &(SData::printData);
	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = (x.*p[i][j])(x);
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}

	return 0;
}
#endif


//=========================================================================================
// 5-9 구조체 변수(call by value) - typedef를 이용한 함수 포인터 - 배열 포인터
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData inputData(SData);
SData printData(SData);
int main(void) {
	typedef SData(*FunctionPtr)(SData);
	FunctionPtr(*p)[FColSize];
	SData x;
	int i, j;

	//p = (FunctionPtr(*)[FColSize])malloc(sizeof(FunctionPtr)*FRowSize*FColSize);
	p = new FunctionPtr[FRowSize][FColSize];

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p);
		delete[] p;
	}
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef struct _SData(*FunctionPtr)(struct _SData);
}SData;

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData::FunctionPtr(*p)[FColSize];
	SData x;
	int i, j;

	//p = (SData::FunctionPtr(*)[FColSize])malloc(sizeof(SData::FunctionPtr)*FRowSize*FColSize);
	p = new SData::FunctionPtr[FRowSize][FColSize];

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p);
		delete[] p;
	}
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData inputData(struct _SData);
	struct _SData printData(struct _SData);
}SData;

SData SData::inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData SData::printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	typedef SData(SData:: * FunctionPtr)(SData);
	FunctionPtr(*p)[FColSize];
	int i, j;

	//p = (FunctionPtr(*)[FColSize])malloc(sizeof(FunctionPtr)*FRowSize*FColSize);
	p = new FunctionPtr[FRowSize][FColSize];


	p[0][0] = &(SData::inputData);
	p[0][1] = &(SData::printData);
	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = (x.*p[i][j])(x);
		}
	}

	//free(p);
	delete[] p;

	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData inputData(struct _SData);
	struct _SData printData(struct _SData);
}SData;

SData SData::inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData SData::printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
typedef struct _Type
{
	typedef SData(SData::* FunctionPtr)(SData);
}Type;
int main(void) {
	SData x;
	Type::FunctionPtr(*p)[FColSize];
	int i, j;

	//p = (Type::FunctionPtr(*)[FColSize])malloc(sizeof(Type::FunctionPtr)*FRowSize*FColSize);
	p = new Type::FunctionPtr[FRowSize][FColSize];


	p[0][0] = &(SData::inputData);
	p[0][1] = &(SData::printData);
	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = (x.*p[i][j])(x);
		}
	}

	//free(p);
	delete[] p;

	return 0;
}
#endif


//=========================================================================================
// 5-10. 구조체 변수(call by value) - typedef를 이용한 함수 포인터 - 이중 포인터
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData inputData(SData);
SData printData(SData);
int main(void) {
	typedef SData(*FunctionPtr)(SData);
	FunctionPtr** p;
	SData x;
	int i, j;

	//p = (FunctionPtr**)malloc(sizeof(FunctionPtr*)*FRowSize);
	p = new FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}
	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef struct _SData(*FunctionPtr)(struct _SData);
}SData;

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData::FunctionPtr** p;
	SData x;
	int i, j;

	//p = (SData::FunctionPtr**)malloc(sizeof(SData::FunctionPtr*)*FRowSize);
	p = new SData::FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
		p[i] = new SData::FunctionPtr[FColSize];
	}
	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.
	//p[0][0] = inputData;
	//p[0][1] = printData;

	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData inputData(struct _SData);
	struct _SData printData(struct _SData);
}SData;

SData SData::inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData SData::printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	typedef SData(SData:: * FunctionPtr)(SData);
	FunctionPtr** p;
	int i, j;

	//p = (FunctionPtr**)malloc(sizeof(FunctionPtr*)*FRowSize);
	p = new FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}

	p[0][0] = &(SData::inputData);
	p[0][1] = &(SData::printData);
	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = (x.*p[i][j])(x);
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;
	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData inputData(struct _SData);
	struct _SData printData(struct _SData);
}SData;

SData SData::inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData SData::printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
typedef struct _Type
{
	typedef SData(SData::* FunctionPtr)(SData);
}Type;
int main(void) {
	SData x;
	Type::FunctionPtr** p;
	int i, j;

	//p = (Type::FunctionPtr**)malloc(sizeof(Type::FunctionPtr*)*FRowSize);
	p = new Type::FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
		p[i] = new Type::FunctionPtr[FColSize];
	}

	p[0][0] = &(SData::inputData);
	p[0][1] = &(SData::printData);
	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = (x.*p[i][j])(x);
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;
	return 0;
}
#endif











//=========================================================================================
// 6. 구조체 변수(call by address) - 기본코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData* inputData(SData*);
SData* printData(SData*);
int main(void) {
	SData x;

	x = *(inputData(&x));
	x = *(printData(&x)); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

//=========================================================================================
// 6-1. 구조체 변수(call by address) - 함수 포인터로 변환한 형태
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData* inputData(SData*);
SData* printData(SData*);
int main(void) {
	SData x;
	//SData*(*Functionptr1)(SData*) = inputData;
	//SData*(*Functionptr2)(SData*) = printData;
	SData* (*Functionptr1)(SData*) = &inputData;
	SData* (*Functionptr2)(SData*) = &printData;

	//x = *(Functionptr1(&x));
	//x = *(Functionptr1(&x)); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성
	x = *((*Functionptr1)(&x));
	x = *((*Functionptr2)(&x)); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성
	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData* (*FunctionPtr1)(struct _SData*);
	struct _SData* (*FunctionPtr2)(struct _SData*);

}SData;

SData* inputData(SData*);
SData* printData(SData*);
int main(void) {
	SData x;

	//x.FunctionPtr1 = inputData;
	//x.FunctionPtr2 = printData;
	x.FunctionPtr1 = &inputData;
	x.FunctionPtr2 = &printData;

	//x = *(x.FunctionPtr1(&x));
	//x = *(x.FunctionPtr2(&x)); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성
	x = *((*x.FunctionPtr1)(&x));
	x = *((*x.FunctionPtr2)(&x)); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData* inputData(struct _SData*);
	struct _SData* printData(struct _SData*);
}SData;

SData* SData::inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* SData::printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	//SData* (SData::*FunctionPtr1)(SData *x) = &(SData::inputData);
	//SData* (SData::*FunctionPtr2)(SData *x) = &(SData::printData);
	SData* (SData:: * FunctionPtr1)(SData * x);
	SData* (SData:: * FunctionPtr2)(SData * x);
	FunctionPtr1 = &(SData::inputData);
	FunctionPtr2 = &(SData::printData);

	//x = *(x.inputData(&x));
	//x = *(x.printData(&x));

	//x = *(x.SData::inputData(&x));
	//x = *(x.SData::printData(&x));

	x = *((x.*FunctionPtr1)(&x));
	x = *((x.*FunctionPtr2)(&x));

	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData* inputData(struct _SData*);
	struct _SData* printData(struct _SData*);
}SData;

SData* SData::inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* SData::printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
typedef struct _Type
{
	SData* (SData::* FunctionPtr1)(SData* x);
	SData* (SData::* FunctionPtr2)(SData* x);
}Type;

int main(void) {
	SData x;
	Type fp;
	fp.FunctionPtr1 = &(SData::inputData);
	fp.FunctionPtr2 = &(SData::printData);

	//x = *(x.inputData(&x));
	//x = *(x.printData(&x));

	//x = *(x.SData::inputData(&x));
	//x = *(x.SData::printData(&x));

	x = *((x.*fp.FunctionPtr1)(&x));
	x = *((x.*fp.FunctionPtr2)(&x));

	return 0;
}
#endif

//=========================================================================================
// 6-2. 구조체 변수(call by address) - 함수 포인터 1차원 배열로 변환한 형태
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData* inputData(SData*);
SData* printData(SData*);
int main(void) {
	//SData* (*FunctionPtr[FColSize])(SData*) = { inputData, printData };
	SData* (*FunctionPtr[FColSize])(SData*) = { &inputData, &printData };
	SData x;
	int i;

	for (i = 0; i < FColSize; i++)
	{
		//x = *(FunctionPtr[i](&x));
		x = *((*FunctionPtr[i])(&x));
	}
	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData* (*FunctionPtr[FColSize])(struct _SData*);
}SData;

SData* inputData(SData*);
SData* printData(SData*);
int main(void) {
	SData x;
	int i;

	//x.FunctionPtr[0] = inputData;
	//x.FunctionPtr[1] = printData;
	x.FunctionPtr[0] = &inputData;
	x.FunctionPtr[1] = &printData;

	for (i = 0; i < FColSize; i++)
	{
		//x = *(x.FunctionPtr[i](&x));
		x = *((*x.FunctionPtr[i])(&x));
	}
	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData* inputData(struct _SData*);
	struct _SData* printData(struct _SData*);
}SData;

SData* SData::inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* SData::printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	//SData* (SData::*FunctionPtr[FColSize])(SData *x) = {&(SData::inputData), &(SData::printData)};
	SData* (SData:: * FunctionPtr[FColSize])(SData * x);
	int i;

	FunctionPtr[0] = &(SData::inputData);
	FunctionPtr[1] = &(SData::printData);
	//x = *(x.inputData(&x));
	//x = *(x.printData(&x));

	//x = *(x.SData::inputData(&x));
	//x = *(x.SData::printData(&x));

	for (i = 0; i < FColSize; i++)
	{
		x = *((x.*FunctionPtr[i])(&x));
	}

	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData* inputData(struct _SData*);
	struct _SData* printData(struct _SData*);
}SData;

SData* SData::inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* SData::printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
typedef struct _Type
{
	SData* (SData::* FunctionPtr[FColSize])(SData* x);
}Type;
int main(void) {
	SData x;
	Type fp;
	int i;

	fp.FunctionPtr[0] = &(SData::inputData);
	fp.FunctionPtr[1] = &(SData::printData);
	//x = *(x.inputData(&x));
	//x = *(x.printData(&x));

	//x = *(x.SData::inputData(&x));
	//x = *(x.SData::printData(&x));

	for (i = 0; i < FColSize; i++)
	{
		x = *((x.*fp.FunctionPtr[i])(&x));
	}

	return 0;
}
#endif

//=========================================================================================
// 6-3. 구조체 변수(call by address) - 함수 포인터 2차원 배열로 변환한 형태
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData* inputData(SData*);
SData* printData(SData*);
int main(void) {
	//SData* (*FunctionPtr[FRowSize][FColSize])(SData*) = { inputData, printData };
	SData* (*FunctionPtr[FRowSize][FColSize])(SData*) = { &inputData, &printData };
	SData x;
	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = *(FunctionPtr[i][j](&x));
			x = *((*FunctionPtr[i][j])(&x));
		}
	}
	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData* (*FunctionPtr[FRowSize][FColSize])(struct _SData*);
}SData;

SData* inputData(SData*);
SData* printData(SData*);
int main(void) {
	SData x;
	int i, j;

	//x.FunctionPtr[0][0] = inputData;
	//x.FunctionPtr[0][1] = printData;
	x.FunctionPtr[0][0] = &inputData;
	x.FunctionPtr[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = *(x.FunctionPtr[i][j](&x));
			x = *((*x.FunctionPtr[i][j])(&x));
		}
	}
	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData* inputData(struct _SData*);
	struct _SData* printData(struct _SData*);
}SData;

SData* SData::inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* SData::printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	//SData* (SData::*FunctionPtr[FRowSize][FColSize])(SData *x) = {&(SData::inputData), &(SData::printData)};
	SData* (SData:: * FunctionPtr[FRowSize][FColSize])(SData * x);
	int i, j;

	FunctionPtr[0][0] = &(SData::inputData);
	FunctionPtr[0][1] = &(SData::printData);
	//x = *(x.inputData(&x));
	//x = *(x.printData(&x));

	//x = *(x.SData::inputData(&x));
	//x = *(x.SData::printData(&x));

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = *((x.*FunctionPtr[i][j])(&x));
		}
	}

	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData* inputData(struct _SData*);
	struct _SData* printData(struct _SData*);
}SData;

SData* SData::inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* SData::printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
typedef struct _Type
{
	SData* (SData::* FunctionPtr[FRowSize][FColSize])(SData* x);
}Type;

int main(void) {
	SData x;
	Type fp;
	int i, j;

	fp.FunctionPtr[0][0] = &(SData::inputData);
	fp.FunctionPtr[0][1] = &(SData::printData);
	//x = *(x.inputData(&x));
	//x = *(x.printData(&x));

	//x = *(x.SData::inputData(&x));
	//x = *(x.SData::printData(&x));

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = *((x.*fp.FunctionPtr[i][j])(&x));
		}
	}

	return 0;
}
#endif

//=========================================================================================
// 6-4. 구조체 변수(call by address) - typedef를 이용한 함수 포인터
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData* inputData(SData*);
SData* printData(SData*);
int main(void) {
	SData x;
	typedef SData* (*Functionptr)(SData*);
	Functionptr p1, p2;

	//p1 = inputData;
	//p2 = printData;
	p1 = &inputData;
	p2 = &printData;

	//x = *(p1(&x));
	//x = *(p2(&x)); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성
	x = *((*p1)(&x));
	x = *((*p2)(&x)); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성
	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef struct _SData* (*FunctionPtr)(struct _SData*);
}SData;

SData* inputData(SData*);
SData* printData(SData*);
int main(void) {
	SData x;
	SData::FunctionPtr p1, p2;

	//x.p1 = inputData;
	//x.p2 = printData;
	p1 = &inputData;
	p2 = &printData;

	//x = *(p1(&x));
	//x = *(p2(&x)); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성
	x = *((*p1)(&x));
	x = *((*p2)(&x)); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData* inputData(struct _SData*);
	struct _SData* printData(struct _SData*);
}SData;

SData* SData::inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* SData::printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	typedef SData* (SData:: * FunctionPtr)(SData * x);
	FunctionPtr p1, p2;

	p1 = &(SData::inputData);
	p2 = &(SData::printData);

	//x = *(x.inputData(&x));
	//x = *(x.printData(&x));

	//x = *(x.SData::inputData(&x));
	//x = *(x.SData::printData(&x));

	x = *(x.*p1)(&x);
	x = *(x.*p2)(&x);

	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData* inputData(struct _SData*);
	struct _SData* printData(struct _SData*);
}SData;

SData* SData::inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* SData::printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
typedef struct _Type
{
	typedef SData* (SData::* FunctionPtr)(SData* x);
}Type;

int main(void) {
	SData x;
	Type::FunctionPtr p1, p2;
	p1 = &(SData::inputData);
	p2 = &(SData::printData);

	//x = *(x.inputData(&x));
	//x = *(x.printData(&x));

	//x = *(x.SData::inputData(&x));
	//x = *(x.SData::printData(&x));

	x = *((x.*p1)(&x));
	x = *((x.*p2)(&x));

	return 0;
}
#endif

//=========================================================================================
// 6-5. 구조체 변수(call by address) - typedef를 이용한 함수 포인터 - 1차원 배열
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData* inputData(SData*);
SData* printData(SData*);
int main(void) {
	typedef SData* (*FunctionPtr)(SData*);
	//FunctionPtr p[FColSize] = { inputData, printData };
	FunctionPtr p[FColSize] = { &inputData, &printData };
	SData x;
	int i;

	for (i = 0; i < FColSize; i++)
	{
		//x = *(p[i](&x));
		x = *((*p[i])(&x));
	}
	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef struct _SData* (*FunctionPtr)(struct _SData*);
}SData;

SData* inputData(SData*);
SData* printData(SData*);
int main(void) {
	//SData::FunctionPtr p[FColSize] = { inputData, printData };
	SData::FunctionPtr p[FColSize] = { &inputData, &printData };
	SData x;
	int i;

	for (i = 0; i < FColSize; i++)
	{
		//x = *(p[i](&x));
		x = *((*p[i])(&x));
	}
	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData* inputData(struct _SData*);
	struct _SData* printData(struct _SData*);
}SData;

SData* SData::inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* SData::printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	typedef SData* (SData:: * FunctionPtr)(SData * x);
	FunctionPtr p[FColSize];
	int i;


	p[0] = &(SData::inputData);
	p[1] = &(SData::printData);
	//x = *(x.inputData(&x));
	//x = *(x.printData(&x));

	//x = *(x.SData::inputData(&x));
	//x = *(x.SData::printData(&x));

	for (i = 0; i < FColSize; i++)
	{
		x = *((x.*p[i])(&x));
	}

	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData* inputData(struct _SData*);
	struct _SData* printData(struct _SData*);
}SData;

SData* SData::inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* SData::printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
typedef struct _Type
{
	typedef SData* (SData::* FunctionPtr)(SData* x);
}Type;

int main(void) {
	SData x;
	Type::FunctionPtr p[FColSize];
	int i;

	p[0] = &(SData::inputData);
	p[1] = &(SData::printData);

	//x = *(x.inputData(&x));
	//x = *(x.printData(&x));

	//x = *(x.SData::inputData(&x));
	//x = *(x.SData::printData(&x));

	for (i = 0; i < FColSize; i++)
	{
		x = *((x.*p[i])(&x));
	}
	return 0;
}
#endif

//=========================================================================================
// 6-6. 구조체 변수(call by address) - typedef를 이용한 함수 포인터 - 1차원 포인터
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

#define FColSize 2

typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData* inputData(SData*);
SData* printData(SData*);
int main(void) {
	typedef SData* (*FunctionPtr)(SData*);
	FunctionPtr* p;
	SData x;
	int i;

	//p = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
	p = new FunctionPtr[FColSize];
	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	for (i = 0; i < FColSize; i++)
	{
		//x = *(p[i](&x));
		x = *((*p[i])(&x));
	}
	//free(p);
	delete[] p;
	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

#define FColSize 2

typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef struct _SData* (*FunctionPtr)(struct _SData*);
}SData;

SData* inputData(SData*);
SData* printData(SData*);
int main(void) {
	SData::FunctionPtr* p;
	SData x;
	int i;

	//p = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
	p = new SData::FunctionPtr[FColSize];

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	for (i = 0; i < FColSize; i++)
	{
		//x = *(p[i](&x));
		x = *((*p[i])(&x));
	}
	//free(p);
	delete[] p;

	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData* inputData(struct _SData*);
	struct _SData* printData(struct _SData*);
}SData;

SData* SData::inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* SData::printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	typedef SData* (SData:: * FunctionPtr)(SData * x);
	FunctionPtr* p;
	int i;

	//p = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
	p = new FunctionPtr[FColSize];

	p[0] = &(SData::inputData);
	p[1] = &(SData::printData);
	//x = *(x.inputData(&x));
	//x = *(x.printData(&x));

	//x = *(x.SData::inputData(&x));
	//x = *(x.SData::printData(&x));

	for (i = 0; i < FColSize; i++)
	{
		x = *((x.*p[i])(&x));
	}

	//free(p);
	delete[] p;
	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData* inputData(struct _SData*);
	struct _SData* printData(struct _SData*);
}SData;

SData* SData::inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* SData::printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
typedef struct _Type
{
	typedef SData* (SData::* FunctionPtr)(SData* x);
}Type;

int main(void) {
	SData x;
	Type::FunctionPtr* p;
	int i;

	//p = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
	p = new Type::FunctionPtr[FColSize];

	p[0] = &(SData::inputData);
	p[1] = &(SData::printData);

	//x = *(x.inputData(&x));
	//x = *(x.printData(&x));

	//x = *(x.SData::inputData(&x));
	//x = *(x.SData::printData(&x));

	for (i = 0; i < FColSize; i++)
	{
		x = *((x.*p[i])(&x));
	}

	//free(p);
	delete[] p;
	return 0;
}
#endif

//=========================================================================================
// 6-7. 구조체 변수(call by address) - typedef를 이용한 함수 포인터 - 2차원 배열
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData* inputData(SData*);
SData* printData(SData*);
int main(void) {
	typedef SData* (*FunctionPtr)(SData*);
	//FunctionPtr p[FRowSize][FColSize] = { inputData, printData };
	FunctionPtr p[FRowSize][FColSize] = { &inputData, &printData };
	SData x;
	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = *(p[i][j](&x));
			x = *((*p[i][j])(&x));
		}
	}
	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef struct _SData* (*FunctionPtr)(struct _SData*);
}SData;

SData* inputData(SData*);
SData* printData(SData*);
int main(void) {
	//SData::FunctionPtr p[FRowSize][FColSize] = { inputData, printData };
	SData::FunctionPtr p[FRowSize][FColSize] = { &inputData, &printData };
	SData x;
	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = *(p[i][j](&x));
			x = *((*p[i][j])(&x));
		}
	}
	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData* inputData(struct _SData*);
	struct _SData* printData(struct _SData*);
}SData;

SData* SData::inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* SData::printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	typedef SData* (SData:: * FunctionPtr)(SData * x);
	FunctionPtr p[FRowSize][FColSize];
	int i, j;


	p[0][0] = &(SData::inputData);
	p[0][1] = &(SData::printData);
	//x = *(x.inputData(&x));
	//x = *(x.printData(&x));

	//x = *(x.SData::inputData(&x));
	//x = *(x.SData::printData(&x));

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = *((x.*p[i][j])(&x));
		}
	}
	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData* inputData(struct _SData*);
	struct _SData* printData(struct _SData*);
}SData;

SData* SData::inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* SData::printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
typedef struct _Type
{
	typedef SData* (SData::* FunctionPtr)(SData* x);
}Type;

int main(void) {
	SData x;
	Type::FunctionPtr p[FRowSize][FColSize];
	int i, j;

	p[0][0] = &(SData::inputData);
	p[0][1] = &(SData::printData);

	//x = *(x.inputData(&x));
	//x = *(x.printData(&x));

	//x = *(x.SData::inputData(&x));
	//x = *(x.SData::printData(&x));

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = *((x.*p[i][j])(&x));
		}
	}
	return 0;
}
#endif

//=========================================================================================
// 6-8. 구조체 변수(call by address) - typedef를 이용한 함수 포인터 - 포인터 배열
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData* inputData(SData*);
SData* printData(SData*);
int main(void) {
	typedef SData* (*FunctionPtr)(SData*);
	FunctionPtr* p[FRowSize];
	SData x;
	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = *(p[i][j](&x));
			x = *((*p[i][j])(&x));
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		free(p[i]);
	}

	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef struct _SData* (*FunctionPtr)(struct _SData*);
}SData;

SData* inputData(SData*);
SData* printData(SData*);
int main(void) {
	SData::FunctionPtr* p[FRowSize];
	SData x;
	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
		p[i] = new SData::FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = *(p[i][j](&x));
			x = *((*p[i][j])(&x));
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}

	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData* inputData(struct _SData*);
	struct _SData* printData(struct _SData*);
}SData;

SData* SData::inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* SData::printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	typedef SData* (SData:: * FunctionPtr)(SData * x);
	FunctionPtr* p[FRowSize];
	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}

	p[0][0] = &(SData::inputData);
	p[0][1] = &(SData::printData);
	//x = *(x.inputData(&x));
	//x = *(x.printData(&x));

	//x = *(x.SData::inputData(&x));
	//x = *(x.SData::printData(&x));

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = *((x.*p[i][j])(&x));
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData* inputData(struct _SData*);
	struct _SData* printData(struct _SData*);
}SData;

SData* SData::inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* SData::printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
typedef struct _Type
{
	typedef SData* (SData::* FunctionPtr)(SData* x);
}Type;

int main(void) {
	SData x;
	Type::FunctionPtr* p[FRowSize];
	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
		p[i] = new Type::FunctionPtr[FColSize];
	}

	p[0][0] = &(SData::inputData);
	p[0][1] = &(SData::printData);

	//x = *(x.inputData(&x));
	//x = *(x.printData(&x));

	//x = *(x.SData::inputData(&x));
	//x = *(x.SData::printData(&x));

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = *((x.*p[i][j])(&x));
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}

	return 0;
}
#endif

//=========================================================================================
// 6-9 구조체 변수(call by address) - typedef를 이용한 함수 포인터 - 배열 포인터
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData* inputData(SData*);
SData* printData(SData*);
int main(void) {
	typedef SData* (*FunctionPtr)(SData*);
	FunctionPtr(*p)[FColSize];
	SData x;
	int i, j;

	//p = (FunctionPtr(*)[FColSize])malloc(sizeof(FunctionPtr)* FRowSize * FColSize);
	p = new FunctionPtr[FRowSize][FColSize];
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = *((*p[i][j])(&x));
		}
	}

	//free(p);
	delete[] p;

	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef struct _SData* (*FunctionPtr)(struct _SData*);
}SData;

SData* inputData(SData*);
SData* printData(SData*);
int main(void) {
	SData::FunctionPtr(*p)[FColSize];
	SData x;
	int i, j;

	//p = (SData::FunctionPtr(*)[FColSize])malloc(sizeof(SData::FunctionPtr)* FRowSize * FColSize);
	p = new SData::FunctionPtr[FRowSize][FColSize];
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = *((*p[i][j])(&x));
		}
	}

	//free(p);
	delete[] p;

	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData* inputData(struct _SData*);
	struct _SData* printData(struct _SData*);
}SData;

SData* SData::inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* SData::printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	typedef SData* (SData:: * FunctionPtr)(SData * x);
	FunctionPtr(*p)[FColSize];
	int i, j;

	//p = (FunctionPtr(*)[FColSize])malloc(sizeof(FunctionPtr)*FRowSize*FColSize);
	p = new FunctionPtr[FRowSize][FColSize];


	p[0][0] = &(SData::inputData);
	p[0][1] = &(SData::printData);
	//x = *(x.inputData(&x));
	//x = *(x.printData(&x));

	//x = *(x.SData::inputData(&x));
	//x = *(x.SData::printData(&x));

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = *((x.*p[i][j])(&x));
		}
	}

	//free(p);
	delete[] p;

	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData* inputData(struct _SData*);
	struct _SData* printData(struct _SData*);
}SData;

SData* SData::inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* SData::printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
typedef struct _Type
{
	typedef SData* (SData::* FunctionPtr)(SData* x);
}Type;

int main(void) {
	SData x;
	Type::FunctionPtr(*p)[FColSize];
	int i, j;

	//p = (Type::FunctionPtr**)malloc(sizeof(Type::FunctionPtr*)*FRowSize);
	p = new Type::FunctionPtr[FRowSize][FColSize];

	p[0][0] = &(SData::inputData);
	p[0][1] = &(SData::printData);

	//x = *(x.inputData(&x));
	//x = *(x.printData(&x));

	//x = *(x.SData::inputData(&x));
	//x = *(x.SData::printData(&x));

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = *((x.*p[i][j])(&x));
		}
	}

	//free(p);
	delete[] p;

	return 0;
}
#endif

//=========================================================================================
// 6-10. 구조체 변수(call by address) - typedef를 이용한 함수 포인터 - 이중 포인터
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData* inputData(SData*);
SData* printData(SData*);
int main(void) {
	typedef SData* (*FunctionPtr)(SData*);
	FunctionPtr** p;
	SData x;
	int i, j;

	//p = (FunctionPtr**)malloc(sizeof(FunctionPtr*)*FRowSize);
	p = new FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = *(p[i][j](&x));
			x = *((*p[i][j])(&x));
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;

	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef struct _SData* (*FunctionPtr)(struct _SData*);
}SData;

SData* inputData(SData*);
SData* printData(SData*);
int main(void) {
	SData::FunctionPtr** p;
	SData x;
	int i, j;

	//p = (SData::FunctionPtr**)malloc(sizeof(SData::FunctionPtr*)*FRowSize);
	p = new SData::FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
		p[i] = new SData::FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = *(p[i][j](&x));
			x = *((*p[i][j])(&x));
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;

	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData* inputData(struct _SData*);
	struct _SData* printData(struct _SData*);
}SData;

SData* SData::inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* SData::printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	typedef SData* (SData:: * FunctionPtr)(SData * x);
	FunctionPtr** p;
	int i, j;

	//p = (FunctionPtr**)malloc(sizeof(FunctionPtr*)*FRowSize);
	p = new FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}

	p[0][0] = &(SData::inputData);
	p[0][1] = &(SData::printData);
	//x = *(x.inputData(&x));
	//x = *(x.printData(&x));

	//x = *(x.SData::inputData(&x));
	//x = *(x.SData::printData(&x));

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = *((x.*p[i][j])(&x));
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;
	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData* inputData(struct _SData*);
	struct _SData* printData(struct _SData*);
}SData;

SData* SData::inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* SData::printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
typedef struct _Type
{
	typedef SData* (SData::* FunctionPtr)(SData* x);
}Type;

int main(void) {
	SData x;
	Type::FunctionPtr** p;
	int i, j;

	//p = (Type::FunctionPtr**)malloc(sizeof(Type::FunctionPtr*)*FRowSize);
	p = new Type::FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
		p[i] = new Type::FunctionPtr[FColSize];
	}

	p[0][0] = &(SData::inputData);
	p[0][1] = &(SData::printData);

	//x = *(x.inputData(&x));
	//x = *(x.printData(&x));

	//x = *(x.SData::inputData(&x));
	//x = *(x.SData::printData(&x));

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = *((x.*p[i][j])(&x));
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;
	return 0;
}
#endif










//=========================================================================================
// 7. 구조체 변수(call by reference) - 기본코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;

	x = inputData(x);
	x = printData(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

//=========================================================================================
// 7-1. 구조체 변수(call by reference) - 함수 포인터로 변환한 형태
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;
	//SData&(*FuncitonPtr1)(SData&) = inputData;
	//SData&(*FuncitonPtr2)(SData&) = printData;
	SData& (*FuncitonPtr1)(SData&) = &inputData;
	SData& (*FuncitonPtr2)(SData&) = &printData;

	//x = (FuncitonPtr1)(x);
	//x = (FuncitonPtr2)(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성
	x = (*FuncitonPtr1)(x);
	x = (*FuncitonPtr2)(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData& (*Functionptr1)(struct _SData&);
	struct _SData& (*Functionptr2)(struct _SData&);
}SData;

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;

	//x.Functionptr1 = inputData;
	//x.Functionptr2 = printData;
	x.Functionptr1 = &inputData;
	x.Functionptr2 = &printData;

	//x = x.Functionptr1(x);
	//x = x.Functionptr2(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성
	x = (*x.Functionptr1)(x);
	x = (*x.Functionptr2)(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData& inputData(struct _SData&);
	struct _SData& printData(struct _SData&);
}SData;

SData& SData::inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& SData::printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	//SData& (SData::*FunctionPtr1)(SData &x) = &(SData::inputData);
	//SData& (SData::*FunctionPtr2)(SData &x) = &(SData::printData);
	SData& (SData:: * FunctionPtr1)(SData & x);
	SData& (SData:: * FunctionPtr2)(SData & x);

	FunctionPtr1 = &(SData::inputData);
	FunctionPtr2 = &(SData::printData);

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	x = (x.*FunctionPtr1)(x);
	x = (x.*FunctionPtr2)(x);

	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData& inputData(struct _SData&);
	struct _SData& printData(struct _SData&);
}SData;

SData& SData::inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& SData::printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
typedef struct _Type
{
	SData& (SData::* FunctionPtr1)(SData& x);
	SData& (SData::* FunctionPtr2)(SData& x);
}Type;
int main(void) {
	SData x;
	Type fp;

	fp.FunctionPtr1 = &(SData::inputData);
	fp.FunctionPtr2 = &(SData::printData);

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	x = (x.*fp.FunctionPtr1)(x);
	x = (x.*fp.FunctionPtr2)(x);

	return 0;
}
#endif

//=========================================================================================
// 7-2. 구조체 변수(call by reference) - 함수 포인터 1차원 배열로 변환한 형태
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	//SData& (*FunctionPtr[FColSize])(SData&) = { inputData, printData };
	SData& (*FunctionPtr[FColSize])(SData&) = { &inputData, &printData };
	SData x;
	int i;

	for (i = 0; i < FColSize; i++)
	{
		//x = FunctionPtr[i](x);
		x = (*FunctionPtr[i])(x);
	}
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData& (*FunctionPtr[FColSize])(struct _SData&);
}SData;

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;
	int i;

	//x.FunctionPtr[0] = inputData;
	//x.FunctionPtr[1] = printData;
	x.FunctionPtr[0] = &inputData;
	x.FunctionPtr[1] = &printData;

	for (i = 0; i < FColSize; i++)
	{
		//x = x.FunctionPtr[i](x);	
		x = (*x.FunctionPtr[i])(x);
	}
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData& inputData(struct _SData&);
	struct _SData& printData(struct _SData&);
}SData;

SData& SData::inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& SData::printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	//SData& (SData::*FunctionPtr[FColSize])(SData &x) ={ &(SData::inputData), &(SData::printData) };
	SData& (SData:: * FunctionPtr[FColSize])(SData & x);
	int i;

	FunctionPtr[0] = &(SData::inputData);
	FunctionPtr[1] = &(SData::printData);

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FColSize; i++)
	{
		x = (x.*FunctionPtr[i])(x);
	}
	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData& inputData(struct _SData&);
	struct _SData& printData(struct _SData&);
}SData;

SData& SData::inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& SData::printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
typedef struct _Type
{
	SData& (SData::* FunctionPtr[FColSize])(SData& x);
}Type;

int main(void) {
	SData x;
	Type fp;
	int i;

	fp.FunctionPtr[0] = &(SData::inputData);
	fp.FunctionPtr[1] = &(SData::printData);

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FColSize; i++)
	{
		x = (x.*fp.FunctionPtr[i])(x);
	}
	return 0;
}
#endif

//=========================================================================================
// 7-3. 구조체 변수(call by reference) - 함수 포인터 2차원 배열로 변환한 형태
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	//SData& (*FunctionPtr[FRowSize][FColSize])(SData&) = { inputData, printData };
	SData& (*FunctionPtr[FRowSize][FColSize])(SData&) = { &inputData, &printData };
	SData x;
	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = FunctionPtr[i][j](x);
			x = (*FunctionPtr[i][j])(x);
		}
	}
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData& (*FunctionPtr[FRowSize][FColSize])(struct _SData&);
}SData;

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;
	int i, j;

	//x.FunctionPtr[0][0] = inputData;
	//x.FunctionPtr[0][1] = printData;
	x.FunctionPtr[0][0] = &inputData;
	x.FunctionPtr[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = x.FunctionPtr[i][j](x);	
			x = (*x.FunctionPtr[i][j])(x);
		}
	}
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData& inputData(struct _SData&);
	struct _SData& printData(struct _SData&);
}SData;

SData& SData::inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& SData::printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	//SData& (SData::*FunctionPtr[FRowSize][FColSize])(SData &x) ={ &(SData::inputData), &(SData::printData) };
	SData& (SData:: * FunctionPtr[FRowSize][FColSize])(SData & x);
	int i, j;

	FunctionPtr[0][0] = &(SData::inputData);
	FunctionPtr[0][1] = &(SData::printData);

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = (x.*FunctionPtr[i][j])(x);
		}
	}
	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData& inputData(struct _SData&);
	struct _SData& printData(struct _SData&);
}SData;

SData& SData::inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& SData::printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
typedef struct type
{
	SData& (SData::* FunctionPtr[FRowSize][FColSize])(SData& x);
}Type;
int main(void) {
	SData x;
	Type fp;
	int i, j;

	fp.FunctionPtr[0][0] = &(SData::inputData);
	fp.FunctionPtr[0][1] = &(SData::printData);

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = (x.*fp.FunctionPtr[i][j])(x);
		}
	}
	return 0;
}
#endif

//=========================================================================================
// 7-4. 구조체 변수(call by reference) - typedef를 이용한 함수 포인터
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;
	typedef SData& (*FuncitonPtr)(SData&);
	FuncitonPtr p1, p2;

	//p1 = inputData;
	//p2 = printData;
	p1 = &inputData;
	p2 = &printData;

	//x = (p1)(x);
	//x = (p2)(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성
	x = (*p1)(x);
	x = (*p2)(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef struct _SData& (*Functionptr)(struct _SData&);
}SData;

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;
	SData::Functionptr p1, p2;

	p1 = &inputData;
	p2 = &printData;

	//x = x.Functionptr1(x);
	//x = x.Functionptr2(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성
	x = (*p1)(x);
	x = (*p2)(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData& inputData(struct _SData&);
	struct _SData& printData(struct _SData&);
}SData;

SData& SData::inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& SData::printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	typedef SData& (SData:: * FunctionPtr)(SData & x);
	FunctionPtr p1, p2;

	p1 = &(SData::inputData);
	p2 = &(SData::printData);

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	x = (x.*p1)(x);
	x = (x.*p2)(x);

	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData& inputData(struct _SData&);
	struct _SData& printData(struct _SData&);
}SData;

SData& SData::inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& SData::printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
typedef struct _Type
{
	typedef SData& (SData::* FunctionPtr)(SData& x);
}Type;
int main(void) {
	SData x;
	Type::FunctionPtr p1, p2;

	p1 = &(SData::inputData);
	p2 = &(SData::printData);

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	x = (x.*p1)(x);
	x = (x.*p2)(x);

	return 0;
}
#endif

//=========================================================================================
// 7-5. 구조체 변수(call by reference) - typedef를 이용한 함수 포인터 - 1차원 배열
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	typedef SData& (*FunctionPtr)(SData&);
	//FunctionPtr p[FColSize] = { inputData, printData };
	FunctionPtr p[FColSize] = { &inputData, &printData };
	SData x;
	int i;

	for (i = 0; i < FColSize; i++)
	{
		//x = p[i](x);
		x = (*p[i])(x);
	}
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef struct _SData& (*FunctionPtr)(struct _SData&);
}SData;

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	//SData::FunctionPtr p[FColSize] = { inputData, printData };
	SData::FunctionPtr p[FColSize] = { &inputData, &printData };
	SData x;
	int i;

	for (i = 0; i < FColSize; i++)
	{
		//x = p[i](x);
		x = (*p[i])(x);
	}
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData& inputData(struct _SData&);
	struct _SData& printData(struct _SData&);
}SData;

SData& SData::inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& SData::printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	typedef SData& (SData:: * FunctionPtr)(SData & x);
	FunctionPtr p[FColSize];
	int i;

	p[0] = &(SData::inputData);
	p[1] = &(SData::printData);

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FColSize; i++)
	{
		x = (x.*p[i])(x);
	}
	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData& inputData(struct _SData&);
	struct _SData& printData(struct _SData&);
}SData;

SData& SData::inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& SData::printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
typedef struct _Type
{
	typedef SData& (SData::* FunctionPtr)(SData& x);
}Type;
int main(void) {
	SData x;
	Type::FunctionPtr p[FColSize];
	int i;

	p[0] = &(SData::inputData);
	p[1] = &(SData::printData);

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FColSize; i++)
	{
		x = (x.*p[i])(x);
	}
	return 0;
}
#endif

//=========================================================================================
// 7-6. 구조체 변수(call by reference) - typedef를 이용한 함수 포인터 - 1차원 포인터
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	typedef SData& (*FunctionPtr)(SData&);
	FunctionPtr* p;
	SData x;
	int i;

	//p = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
	p = new FunctionPtr[FColSize];

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;


	for (i = 0; i < FColSize; i++)
	{
		//x = p[i](x);
		x = (*p[i])(x);
	}
	//free(p);
	delete[] p;
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef struct _SData& (*FunctionPtr)(struct _SData&);
}SData;

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData::FunctionPtr* p;
	SData x;
	int i;

	//p = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
	p = new SData::FunctionPtr[FColSize];

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;


	for (i = 0; i < FColSize; i++)
	{
		//x = p[i](x);
		x = (*p[i])(x);
	}

	//free(p);
	delete[] p;
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData& inputData(struct _SData&);
	struct _SData& printData(struct _SData&);
}SData;

SData& SData::inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& SData::printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	typedef SData& (SData:: * FunctionPtr)(SData & x);
	FunctionPtr* p;
	int i;

	//p = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
	p = new FunctionPtr[FColSize];

	p[0] = &(SData::inputData);
	p[1] = &(SData::printData);

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FColSize; i++)
	{
		x = (x.*p[i])(x);
	}
	//free(p);
	delete[] p;

	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData& inputData(struct _SData&);
	struct _SData& printData(struct _SData&);
}SData;

SData& SData::inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& SData::printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
typedef struct _Type
{
	typedef SData& (SData::* FunctionPtr)(SData& x);
}Type;

int main(void) {
	SData x;
	Type::FunctionPtr* p;
	int i;

	//p = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
	p = new Type::FunctionPtr[FColSize];

	p[0] = &(SData::inputData);
	p[1] = &(SData::printData);

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FColSize; i++)
	{
		x = (x.*p[i])(x);
	}

	//free(p);
	delete[] p;

	return 0;
}
#endif

//=========================================================================================
// 7-7. 구조체 변수(call by reference) - typedef를 이용한 함수 포인터 - 2차원 배열
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	typedef SData& (*FunctionPtr)(SData&);
	//FunctionPtr p[FRowSize][FColSize] = { inputData, printData };
	FunctionPtr p[FRowSize][FColSize] = { &inputData, &printData };
	SData x;
	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef struct _SData& (*FunctionPtr)(struct _SData&);
}SData;

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	//SData::FunctionPtr p[FRowSize][FColSize] = { inputData, printData };
	SData::FunctionPtr p[FRowSize][FColSize] = { &inputData, &printData };
	SData x;
	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData& inputData(struct _SData&);
	struct _SData& printData(struct _SData&);
}SData;

SData& SData::inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& SData::printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	typedef SData& (SData:: * FunctionPtr)(SData & x);
	FunctionPtr p[FRowSize][FColSize];
	int i, j;

	p[0][0] = &(SData::inputData);
	p[0][1] = &(SData::printData);

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = (x.*p[i][j])(x);
		}
	}
	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData& inputData(struct _SData&);
	struct _SData& printData(struct _SData&);
}SData;

SData& SData::inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& SData::printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
typedef struct _Type
{
	typedef SData& (SData::* FunctionPtr)(SData& x);
}Type;
int main(void) {
	SData x;
	Type::FunctionPtr p[FRowSize][FColSize];
	int i, j;

	p[0][0] = &(SData::inputData);
	p[0][1] = &(SData::printData);

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = (x.*p[i][j])(x);
		}
	}
	return 0;
}
#endif

//=========================================================================================
// 7-8. 구조체 변수(call by reference) - typedef를 이용한 함수 포인터 - 포인터 배열
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	typedef SData& (*FunctionPtr)(SData&);
	FunctionPtr* p[FRowSize];
	SData x;
	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef struct _SData& (*FunctionPtr)(struct _SData&);
}SData;

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData::FunctionPtr* p[FRowSize];
	SData x;
	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
		p[i] = new SData::FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;


	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData& inputData(struct _SData&);
	struct _SData& printData(struct _SData&);
}SData;

SData& SData::inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& SData::printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	typedef SData& (SData:: * FunctionPtr)(SData & x);
	FunctionPtr* p[FRowSize];
	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}

	p[0][0] = &(SData::inputData);
	p[0][1] = &(SData::printData);

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = (x.*p[i][j])(x);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData& inputData(struct _SData&);
	struct _SData& printData(struct _SData&);
}SData;

SData& SData::inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& SData::printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
typedef struct _Type
{
	typedef SData& (SData::* FunctionPtr)(SData& x);
}Type;
int main(void) {
	SData x;
	Type::FunctionPtr* p[FRowSize];
	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
		p[i] = new Type::FunctionPtr[FColSize];
	}

	p[0][0] = &(SData::inputData);
	p[0][1] = &(SData::printData);

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = (x.*p[i][j])(x);
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}

	return 0;
}
#endif

//=========================================================================================
// 7-9 구조체 변수(call by reference) - typedef를 이용한 함수 포인터 - 배열 포인터
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	typedef SData& (*FunctionPtr)(SData&);
	FunctionPtr(*p)[FColSize];
	SData x;
	int i, j;

	//p = (FunctionPtr(*)[FColSize])malloc(sizeof(FunctionPtr)*FRowSize*FColSize);
	p = new FunctionPtr[FRowSize][FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}

	//free(p);
	delete[] p;
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef struct _SData& (*FunctionPtr)(struct _SData&);
}SData;

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData::FunctionPtr(*p)[FColSize];
	SData x;
	int i, j;

	//p = (SData::FunctionPtr(*)[FColSize])malloc(sizeof(SData::FunctionPtr)*FRowSize*FColSize);
	p = new SData::FunctionPtr[FRowSize][FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;


	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}

	//free(p);
	delete[] p;
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData& inputData(struct _SData&);
	struct _SData& printData(struct _SData&);
}SData;

SData& SData::inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& SData::printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	typedef SData& (SData:: * FunctionPtr)(SData & x);
	FunctionPtr(*p)[FColSize];
	int i, j;

	//p = (FunctionPtr(*)[FColSize])malloc(sizeof(FunctionPtr)*FRowSize*FColSize);
	p = new FunctionPtr[FRowSize][FColSize];


	p[0][0] = &(SData::inputData);
	p[0][1] = &(SData::printData);

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = (x.*p[i][j])(x);
		}
	}

	//free(p);
	delete[] p;

	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData& inputData(struct _SData&);
	struct _SData& printData(struct _SData&);
}SData;

SData& SData::inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& SData::printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
typedef struct _Type
{
	typedef SData& (SData::* FunctionPtr)(SData& x);
}Type;
int main(void) {
	SData x;
	Type::FunctionPtr(*p)[FColSize];
	int i, j;

	//p = (Type::FunctionPtr(*)[FColSize])malloc(sizeof(Type::FunctionPtr)*FRowSize*FColSize);
	p = new Type::FunctionPtr[FRowSize][FColSize];


	p[0][0] = &(SData::inputData);
	p[0][1] = &(SData::printData);

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = (x.*p[i][j])(x);
		}
	}

	//free(p);
	delete[] p;


	return 0;
}
#endif

//=========================================================================================
// 7-10. 구조체 변수(call by reference) - typedef를 이용한 함수 포인터 - 이중 포인터
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	typedef SData& (*FunctionPtr)(SData&);
	FunctionPtr** p;
	SData x;
	int i, j;

	//p = (FunctionPtr**)malloc(sizeof(FunctionPtr*)*FRowSize);
	p = new FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = inputData;
	p[0][1] = printData;


	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef struct _SData& (*FunctionPtr)(struct _SData&);
}SData;

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData::FunctionPtr** p;
	SData x;
	int i, j;

	//p = (SData::FunctionPtr**)malloc(sizeof(SData::FunctionPtr*)*FRowSize);
	p = new SData::FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
		p[i] = new SData::FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData& inputData(struct _SData&);
	struct _SData& printData(struct _SData&);
}SData;

SData& SData::inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& SData::printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	typedef SData& (SData:: * FunctionPtr)(SData & x);
	FunctionPtr** p;
	int i, j;

	//p = (FunctionPtr**)malloc(sizeof(FunctionPtr*)*FRowSize);
	p = new FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}

	p[0][0] = &(SData::inputData);
	p[0][1] = &(SData::printData);

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = (x.*p[i][j])(x);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;
	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	struct _SData& inputData(struct _SData&);
	struct _SData& printData(struct _SData&);
}SData;

SData& SData::inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& SData::printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
typedef struct _Type
{
	typedef SData& (SData::* FunctionPtr)(SData& x);
}Type;
int main(void) {
	SData x;
	Type::FunctionPtr** p;
	int i, j;

	//p = (Type::FunctionPtr**)malloc(sizeof(Type::FunctionPtr*)*FRowSize);
	p = new Type::FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
		p[i] = new Type::FunctionPtr[FColSize];
	}

	p[0][0] = &(SData::inputData);
	p[0][1] = &(SData::printData);

	//x = x.inputData(x);
	//x = x.printData(x);

	//x = x.SData::inputData(x);
	//x = x.SData::printData(x);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = (x.*p[i][j])(x);
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;

	return 0;
}
#endif











//=========================================================================================
// 8. 구조체 1차원 배열 - 기본코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

void inputData(SData x[ColSize], int i, int CSize);
void printData(SData x[ColSize], int i, int CSize);

int main(void) {
	SData x[ColSize];
	int i, CSize;

	i = 0;
	CSize = ColSize;

	inputData(x, i, CSize);
	printData(x, i, CSize);

	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

//=========================================================================================
// 8-1. 구조체 1차원 배열 - 함수 포인터로 변환한 형태
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

void inputData(SData x[ColSize], int i, int CSize);
void printData(SData x[ColSize], int i, int CSize);

int main(void) {
	SData x[ColSize];
	//void(*FunctionPtr1)(SData x[ColSize], int i, int CSize) = inputData;
	//void(*FunctionPtr2)(SData x[ColSize], int i, int CSize) = printData;
	void(*FunctionPtr1)(SData x[ColSize], int i, int CSize) = &inputData;
	void(*FunctionPtr2)(SData x[ColSize], int i, int CSize) = &printData;
	int i, CSize;

	i = 0;
	CSize = ColSize;

	//FunctionPtr1(x, i, CSize);
	//FunctionPtr2(x, i, CSize);
	(*FunctionPtr1)(x, i, CSize);
	(*FunctionPtr2)(x, i, CSize);

	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void(*FunctionPtr1)(struct _SData[ColSize], int, int);
	void(*FunctionPtr2)(struct _SData[ColSize], int, int);
}SData;

void inputData(SData[ColSize], int, int);
void printData(SData[ColSize], int, int);

int main(void) {
	SData x[ColSize];
	int i, CSize;

	for (i = 0; i < 1; i++)
	{
		//x[i].FunctionPtr1 = inputData;
		//x[i].FunctionPtr2 = printData;
		x[i].FunctionPtr1 = &inputData;
		x[i].FunctionPtr2 = &printData;
	}

	i = 0;
	CSize = ColSize;

	for (i = 0; i < 1; i++)
	{
		//x[i].FunctionPtr1(x, i, CSize);
		//x[i].FunctionPtr2(x, i, CSize);
		(*x[i].FunctionPtr1)(x, i, CSize);
		(*x[i].FunctionPtr2)(x, i, CSize);
	}
	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[ColSize], int, int);
	void printData(struct _SData[ColSize], int, int);
}SData;

void SData::inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void SData::printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}

int main(void) {
	SData x[ColSize];
	void (SData:: * FunctionPtr1)(SData[ColSize], int, int) = &SData::inputData;
	void (SData:: * FunctionPtr2)(SData[ColSize], int, int) = &SData::printData;
	int i, CSize;

	i = 0;
	CSize = ColSize;

	//x[0].inputData(x, i, CSize);
	//x[0].printData(x, i, CSize);

	//x[0].SData::inputData(x, i, CSize);
	//x[0].SData::printData(x, i, CSize);

	(x[0].*FunctionPtr1)(x, i, CSize);
	(x[0].*FunctionPtr2)(x, i, CSize);

	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[ColSize], int, int);
	void printData(struct _SData[ColSize], int, int);
}SData;

void SData::inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void SData::printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
typedef struct Type
{
	void (SData::* FunctionPtr1)(SData[ColSize], int, int);
	void (SData::* FunctionPtr2)(SData[ColSize], int, int);
}Type;

int main(void) {
	SData x[ColSize];
	Type fp;

	int i, CSize;

	fp.FunctionPtr1 = &(SData::inputData);
	fp.FunctionPtr2 = &(SData::printData);

	i = 0;
	CSize = ColSize;

	//x[0].inputData(x, i, CSize);
	//x[0].printData(x, i, CSize);

	//x[0].SData::inputData(x, i, CSize);
	//x[0].SData::printData(x, i, CSize);

	(x[0].*fp.FunctionPtr1)(x, i, CSize);
	(x[0].*fp.FunctionPtr2)(x, i, CSize);

	return 0;
}
#endif

//=========================================================================================
// 8-2. 구조체 1차원 배열 - 함수 포인터 1차원 배열로 변환한 형태
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

void inputData(SData x[ColSize], int i, int CSize);
void printData(SData x[ColSize], int i, int CSize);

int main(void) {
	//void(*FunctionPtr[2])(SData[ColSize], int, int) = {inputData, printData};
	void(*FunctionPtr[2])(SData[ColSize], int, int) = { &inputData, &printData };
	SData x[ColSize];
	int i, CSize;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//FunctionPtr[i](x, i, CSize);
		(*FunctionPtr[i])(x, i, CSize);
	}
	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void(*FunctionPtr[2])(struct _SData[ColSize], int, int);
}SData;

void inputData(SData x[ColSize], int i, int CSize);
void printData(SData x[ColSize], int i, int CSize);

int main(void) {
	SData x[ColSize];
	int i, j, CSize;

	for (i = 0; i < 1; i++)
	{
		//x[i].FunctionPtr[0] = inputData;
		//x[i].FunctionPtr[1] = printData;
		x[i].FunctionPtr[0] = &inputData;
		x[i].FunctionPtr[1] = &printData;
	}

	i = 0;
	CSize = ColSize;

	for (i = 0; i < 1; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x[i].FunctionPtr[j](x, i, CSize);
			(*x[i].FunctionPtr[j])(x, i, CSize);
		}
	}
	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[ColSize], int, int);
	void printData(struct _SData[ColSize], int, int);
}SData;

void SData::inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void SData::printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}

int main(void) {
	SData x[ColSize];
	//void (SData::*FunctionPtr[FColSize])(SData[ColSize], int, int) = { &SData::inputData, &SData::printData};
	void (SData:: * FunctionPtr[FColSize])(SData[ColSize], int, int);
	int i, CSize;

	FunctionPtr[0] = &SData::inputData;
	FunctionPtr[1] = &SData::printData;
	i = 0;
	CSize = ColSize;

	//x[0].inputData(x, i, CSize);
	//x[0].printData(x, i, CSize);

	//x[0].SData::inputData(x, i, CSize);
	//x[0].SData::printData(x, i, CSize);

	for (i = 0; i < FColSize; i++)
	{
		(x[0].*FunctionPtr[i])(x, i, CSize);
	}
	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[ColSize], int, int);
	void printData(struct _SData[ColSize], int, int);
}SData;

void SData::inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void SData::printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
typedef struct Type
{
	void (SData::* FunctionPtr[FColSize])(SData[ColSize], int, int);
}Type;

int main(void) {
	SData x[ColSize];
	Type fp;
	int i, CSize;

	fp.FunctionPtr[0] = &(SData::inputData);
	fp.FunctionPtr[1] = &(SData::printData);

	i = 0;
	CSize = ColSize;

	//x[0].inputData(x, i, CSize);
	//x[0].printData(x, i, CSize);

	//x[0].SData::inputData(x, i, CSize);
	//x[0].SData::printData(x, i, CSize);

	for (i = 0; i < FColSize; i++)
	{
		(x[0].*fp.FunctionPtr[i])(x, i, CSize);
	}
	return 0;
}
#endif

//=========================================================================================
// 8-3. 구조체 1차원 배열 - 함수 포인터 2차원 배열로 변환한 형태
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

void inputData(SData x[ColSize], int i, int CSize);
void printData(SData x[ColSize], int i, int CSize);

int main(void) {
	//void(*FunctionPtr[FRowSize][FColSize])(SData[ColSize], int, int) = {inputData, printData};
	void(*FunctionPtr[FRowSize][FColSize])(SData[ColSize], int, int) = { &inputData, &printData };
	SData x[ColSize];
	int i, j, CSize;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//FunctionPtr[i][j](x, i, CSize);
			(*FunctionPtr[i][j])(x, i, CSize);
		}
	}
	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void(*FunctionPtr[FRowSize][FColSize])(struct _SData[ColSize], int, int);
}SData;

void inputData(SData x[ColSize], int i, int CSize);
void printData(SData x[ColSize], int i, int CSize);

int main(void) {
	SData x[ColSize];
	int i, j, CSize;

	//x[0].FunctionPtr[0][0] = inputData;
	//x[0].FunctionPtr[0][1] = printData;
	x[0].FunctionPtr[0][0] = &inputData;
	x[0].FunctionPtr[0][1] = &printData;


	i = 0;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x[0].FunctionPtr[i][j](x, i, CSize);
			(*x[0].FunctionPtr[i][j])(x, i, CSize);
		}
	}
	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[ColSize], int, int);
	void printData(struct _SData[ColSize], int, int);
}SData;

void SData::inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void SData::printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}

int main(void) {
	SData x[ColSize];
	//void (SData::*FunctionPtr[FRowSize][FColSize])(SData[ColSize], int, int) = { &SData::inputData, &SData::printData};
	void (SData:: * FunctionPtr[FRowSize][FColSize])(SData[ColSize], int, int);
	int i, j, CSize;

	FunctionPtr[0][0] = &SData::inputData;
	FunctionPtr[0][1] = &SData::printData;
	i = 0;
	CSize = ColSize;

	//x[0].inputData(x, i, CSize);
	//x[0].printData(x, i, CSize);

	//x[0].SData::inputData(x, i, CSize);
	//x[0].SData::printData(x, i, CSize);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			(x[0].*FunctionPtr[i][j])(x, i, CSize);
		}
	}
	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[ColSize], int, int);
	void printData(struct _SData[ColSize], int, int);
}SData;

void SData::inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void SData::printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
typedef struct Type
{
	void (SData::* FunctionPtr[FRowSize][FColSize])(SData[ColSize], int, int);
}Type;

int main(void) {
	SData x[ColSize];
	Type fp;
	int i, j, CSize;

	fp.FunctionPtr[0][0] = &(SData::inputData);
	fp.FunctionPtr[0][1] = &(SData::printData);

	i = 0;
	CSize = ColSize;

	//x[0].inputData(x, i, CSize);
	//x[0].printData(x, i, CSize);

	//x[0].SData::inputData(x, i, CSize);
	//x[0].SData::printData(x, i, CSize);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			(x[0].*fp.FunctionPtr[i][j])(x, i, CSize);
		}
	}
	return 0;
}
#endif

//=========================================================================================
// 8-4. 구조체 1차원 배열 - typedef를 이용한 함수 포인터
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

void inputData(SData x[ColSize], int i, int CSize);
void printData(SData x[ColSize], int i, int CSize);

int main(void) {
	SData x[ColSize];
	typedef void(*FunctionPtr)(SData[ColSize], int, int);
	FunctionPtr p1, p2;
	int i, CSize;

	//p1 = inputData;
	//p2 = printData;
	p1 = &inputData;
	p2 = &printData;

	i = 0;
	CSize = ColSize;

	//p1(x, i, CSize);
	//p2(x, i, CSize);
	(*p1)(x, i, CSize);
	(*p2)(x, i, CSize);

	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef void(*FunctionPtr)(struct _SData[ColSize], int, int);
}SData;

void inputData(SData[ColSize], int, int);
void printData(SData[ColSize], int, int);

int main(void) {
	SData x[ColSize];
	SData::FunctionPtr p1, p2;
	int i, CSize;

	//p1 = inputData;
	//p2 = printData;
	p1 = &inputData;
	p2 = &printData;


	i = 0;
	CSize = ColSize;

	//p1(x, i, CSize);
	//p2(x, i, CSize);
	(*p1)(x, i, CSize);
	(*p2)(x, i, CSize);

	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[ColSize], int, int);
	void printData(struct _SData[ColSize], int, int);
}SData;

void SData::inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void SData::printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}

int main(void) {
	SData x[ColSize];
	typedef void (SData:: * FunctionPtr)(SData[ColSize], int, int);
	FunctionPtr p1, p2;
	int i, CSize;

	p1 = &SData::inputData;
	p2 = &SData::printData;

	i = 0;
	CSize = ColSize;

	//x[0].inputData(x, i, CSize);
	//x[0].printData(x, i, CSize);

	//x[0].SData::inputData(x, i, CSize);
	//x[0].SData::printData(x, i, CSize);

	(x[0].*p1)(x, i, CSize);
	(x[0].*p2)(x, i, CSize);

	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[ColSize], int, int);
	void printData(struct _SData[ColSize], int, int);
}SData;

void SData::inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void SData::printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
typedef struct Type
{
	typedef void (SData::* FunctionPtr)(SData[ColSize], int, int);
}Type;

int main(void) {
	SData x[ColSize];
	Type::FunctionPtr p1, p2;

	int i, CSize;

	p1 = &(SData::inputData);
	p2 = &(SData::printData);

	i = 0;
	CSize = ColSize;

	//x[0].inputData(x, i, CSize);
	//x[0].printData(x, i, CSize);

	//x[0].SData::inputData(x, i, CSize);
	//x[0].SData::printData(x, i, CSize);

	(x[0].*p1)(x, i, CSize);
	(x[0].*p2)(x, i, CSize);

	return 0;
}
#endif

//=========================================================================================
// 8-5. 구조체 1차원 배열 - typedef를 이용한 함수 포인터 - 1차원 배열
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

void inputData(SData x[ColSize], int i, int CSize);
void printData(SData x[ColSize], int i, int CSize);

int main(void) {
	typedef void(*FunctionPtr)(SData[ColSize], int, int);
	//FunctionPtr p[FColSize] = { inputData, printData };
	FunctionPtr p[FColSize] = { &inputData, &printData };
	SData x[ColSize];
	int i, CSize;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](x, i, CSize);
		(*p[i])(x, i, CSize);
	}
	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef void(*FunctionPtr)(struct _SData[ColSize], int, int);
}SData;

void inputData(SData x[ColSize], int i, int CSize);
void printData(SData x[ColSize], int i, int CSize);

int main(void) {
	SData x[ColSize];
	//SData::FunctionPtr p[FColSize] = {inputData, printData};
	SData::FunctionPtr p[FColSize] = { &inputData, &printData };
	int i, j, CSize;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](x, i, CSize);
		(*p[i])(x, i, CSize);
	}
	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[ColSize], int, int);
	void printData(struct _SData[ColSize], int, int);
}SData;

void SData::inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void SData::printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}

int main(void) {
	SData x[ColSize];
	typedef void (SData:: * FunctionPtr)(SData[ColSize], int, int);
	FunctionPtr p[FColSize];
	int i, CSize;

	p[0] = &SData::inputData;
	p[1] = &SData::printData;

	i = 0;
	CSize = ColSize;

	//x[0].inputData(x, i, CSize);
	//x[0].printData(x, i, CSize);

	//x[0].SData::inputData(x, i, CSize);
	//x[0].SData::printData(x, i, CSize);

	for (i = 0; i < FColSize; i++)
	{
		(x[0].*p[i])(x, i, CSize);
	}

	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[ColSize], int, int);
	void printData(struct _SData[ColSize], int, int);
}SData;

void SData::inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void SData::printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
typedef struct Type
{
	typedef void (SData::* FunctionPtr)(SData[ColSize], int, int);
}Type;

int main(void) {
	SData x[ColSize];
	Type::FunctionPtr p[FColSize];
	int i, CSize;

	p[0] = &(SData::inputData);
	p[1] = &(SData::printData);

	i = 0;
	CSize = ColSize;

	//x[0].inputData(x, i, CSize);
	//x[0].printData(x, i, CSize);

	//x[0].SData::inputData(x, i, CSize);
	//x[0].SData::printData(x, i, CSize);

	for (i = 0; i < FColSize; i++)
	{
		(x[0].*p[i])(x, i, CSize);
	}
	return 0;
}
#endif

//=========================================================================================
// 8-6. 구조체 1차원 배열 - typedef를 이용한 함수 포인터 - 1차원 포인터
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

void inputData(SData x[ColSize], int i, int CSize);
void printData(SData x[ColSize], int i, int CSize);

int main(void) {
	typedef void(*FunctionPtr)(SData[ColSize], int, int);
	FunctionPtr* p;
	SData x[ColSize];
	int i, CSize;

	//p = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
	p = new FunctionPtr[FColSize];
	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](x, i, CSize);
		(*p[i])(x, i, CSize);
	}
	//free(p);
	delete[] p;
	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef void(*FunctionPtr)(struct _SData[ColSize], int, int);
}SData;

void inputData(SData x[ColSize], int i, int CSize);
void printData(SData x[ColSize], int i, int CSize);

int main(void) {
	SData x[ColSize];
	SData::FunctionPtr* p;
	int i, j, CSize;

	//p = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
	p = new SData::FunctionPtr[FColSize];
	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](x, i, CSize);
		(*p[i])(x, i, CSize);
	}
	free(p);
	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[ColSize], int, int);
	void printData(struct _SData[ColSize], int, int);
}SData;

void SData::inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void SData::printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}

int main(void) {
	SData x[ColSize];
	typedef void (SData:: * FunctionPtr)(SData[ColSize], int, int);
	FunctionPtr* p;
	int i, CSize;

	//p = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
	p = new FunctionPtr[FColSize];
	p[0] = &SData::inputData;
	p[1] = &SData::printData;

	i = 0;
	CSize = ColSize;

	//x[0].inputData(x, i, CSize);
	//x[0].printData(x, i, CSize);

	//x[0].SData::inputData(x, i, CSize);
	//x[0].SData::printData(x, i, CSize);

	for (i = 0; i < FColSize; i++)
	{
		(x[0].*p[i])(x, i, CSize);
	}

	//free(p);
	delete[] p;
	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[ColSize], int, int);
	void printData(struct _SData[ColSize], int, int);
}SData;

void SData::inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void SData::printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
typedef struct Type
{
	typedef void (SData::* FunctionPtr)(SData[ColSize], int, int);
}Type;

int main(void) {
	SData x[ColSize];
	Type::FunctionPtr* p;
	int i, CSize;

	//p = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
	p = new Type::FunctionPtr[FColSize];

	p[0] = &(SData::inputData);
	p[1] = &(SData::printData);

	i = 0;
	CSize = ColSize;

	//x[0].inputData(x, i, CSize);
	//x[0].printData(x, i, CSize);

	//x[0].SData::inputData(x, i, CSize);
	//x[0].SData::printData(x, i, CSize);

	for (i = 0; i < FColSize; i++)
	{
		(x[0].*p[i])(x, i, CSize);
	}

	//free(p);
	delete[] p;
	return 0;
}
#endif

//=========================================================================================
// 8-7. 구조체 1차원 배열 - typedef를 이용한 함수 포인터 - 2차원 배열
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

void inputData(SData x[ColSize], int i, int CSize);
void printData(SData x[ColSize], int i, int CSize);

int main(void) {
	typedef void(*FunctionPtr)(SData[ColSize], int, int);
	//FunctionPtr p[FRowSize][FColSize] = { inputData, printData };
	FunctionPtr p[FRowSize][FColSize] = { &inputData, &printData };
	SData x[ColSize];
	int i, j, CSize;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, CSize);
			(*p[i][j])(x, i, CSize);
		}
	}
	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef void(*FunctionPtr)(struct _SData[ColSize], int, int);
}SData;

void inputData(SData x[ColSize], int i, int CSize);
void printData(SData x[ColSize], int i, int CSize);

int main(void) {
	SData x[ColSize];
	//SData::FunctionPtr p[FRowSize][FColSize] = { inputData, printData };
	SData::FunctionPtr p[FRowSize][FColSize] = { &inputData, &printData };
	int i, j, CSize;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, CSize);
			(*p[i][j])(x, i, CSize);
		}
	}
	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[ColSize], int, int);
	void printData(struct _SData[ColSize], int, int);
}SData;

void SData::inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void SData::printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}

int main(void) {
	SData x[ColSize];
	typedef void (SData:: * FunctionPtr)(SData[ColSize], int, int);
	FunctionPtr p[FRowSize][FColSize];
	int i, j, CSize;

	p[0][0] = &SData::inputData;
	p[0][1] = &SData::printData;

	i = 0;
	CSize = ColSize;

	//x[0].inputData(x, i, CSize);
	//x[0].printData(x, i, CSize);

	//x[0].SData::inputData(x, i, CSize);
	//x[0].SData::printData(x, i, CSize);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			(x[0].*p[i][j])(x, i, CSize);
		}
	}
	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[ColSize], int, int);
	void printData(struct _SData[ColSize], int, int);
}SData;

void SData::inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}

void SData::printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}

typedef struct Type
{
	typedef void (SData::* FunctionPtr)(SData[ColSize], int, int);
}Type;

int main(void) {
	SData x[ColSize];
	Type::FunctionPtr p[FRowSize][FColSize];
	int i, j, CSize;

	p[0][0] = &(SData::inputData);
	p[0][1] = &(SData::printData);

	i = 0;
	CSize = ColSize;

	//x[0].inputData(x, i, CSize);
	//x[0].printData(x, i, CSize);

	//x[0].SData::inputData(x, i, CSize);
	//x[0].SData::printData(x, i, CSize);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			(x[0].*p[i][j])(x, i, CSize);
		}
	}
	return 0;
}
#endif

//=========================================================================================
// 8-8. 구조체 1차원 배열 - typedef를 이용한 함수 포인터 - 포인터 배열
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

#define FRowSize 1
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

void inputData(SData x[ColSize], int i, int CSize);
void printData(SData x[ColSize], int i, int CSize);

int main(void) {
	typedef void(*FunctionPtr)(SData[ColSize], int, int);
	FunctionPtr* p[FRowSize];
	SData x[ColSize];
	int i, j, CSize;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, CSize);
			(*p[i][j])(x, i, CSize);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef void(*FunctionPtr)(struct _SData[ColSize], int, int);
}SData;

void inputData(SData x[ColSize], int i, int CSize);
void printData(SData x[ColSize], int i, int CSize);

int main(void) {
	SData x[ColSize];
	SData::FunctionPtr* p[FRowSize];
	int i, j, CSize;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
		p[i] = new SData::FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, CSize);
			(*p[i][j])(x, i, CSize);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[ColSize], int, int);
	void printData(struct _SData[ColSize], int, int);
}SData;

void SData::inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void SData::printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}

int main(void) {
	SData x[ColSize];
	typedef void (SData:: * FunctionPtr)(SData[ColSize], int, int);
	FunctionPtr* p[FRowSize];
	int i, j, CSize;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}
	p[0][0] = &SData::inputData;
	p[0][1] = &SData::printData;

	i = 0;
	CSize = ColSize;

	//x[0].inputData(x, i, CSize);
	//x[0].printData(x, i, CSize);

	//x[0].SData::inputData(x, i, CSize);
	//x[0].SData::printData(x, i, CSize);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			(x[0].*p[i][j])(x, i, CSize);
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}

	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[ColSize], int, int);
	void printData(struct _SData[ColSize], int, int);
}SData;

void SData::inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}

void SData::printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}

typedef struct Type
{
	typedef void (SData::* FunctionPtr)(SData[ColSize], int, int);
}Type;

int main(void) {
	SData x[ColSize];
	Type::FunctionPtr* p[FRowSize];
	int i, j, CSize;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
		p[i] = new Type::FunctionPtr[FColSize];

	}

	p[0][0] = &(SData::inputData);
	p[0][1] = &(SData::printData);

	i = 0;
	CSize = ColSize;

	//x[0].inputData(x, i, CSize);
	//x[0].printData(x, i, CSize);

	//x[0].SData::inputData(x, i, CSize);
	//x[0].SData::printData(x, i, CSize);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			(x[0].*p[i][j])(x, i, CSize);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	return 0;
}
#endif

//=========================================================================================
// 8-9. 구조체 1차원 배열 - typedef를 이용한 함수 포인터 - 배열 포인터
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

#define FRowSize 1
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

void inputData(SData x[ColSize], int i, int CSize);
void printData(SData x[ColSize], int i, int CSize);

int main(void) {
	typedef void(*FunctionPtr)(SData[ColSize], int, int);
	FunctionPtr(*p)[FColSize];
	SData x[ColSize];
	int i, j, CSize;

	//p = (FunctionPtr(*)[FColSize])malloc(sizeof(FunctionPtr)*FRowSize*FColSize);
	p = new FunctionPtr[FRowSize][FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, CSize);
			(*p[i][j])(x, i, CSize);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef void(*FunctionPtr)(struct _SData[ColSize], int, int);
}SData;

void inputData(SData x[ColSize], int i, int CSize);
void printData(SData x[ColSize], int i, int CSize);

int main(void) {
	SData x[ColSize];
	SData::FunctionPtr(*p)[FColSize];
	int i, j, CSize;

	//p = (SData::FunctionPtr(*)[FColSize])malloc(sizeof(SData::FunctionPtr)*FRowSize*FColSize);
	p = new SData::FunctionPtr[FRowSize][FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, CSize);
			(*p[i][j])(x, i, CSize);
		}
	}

	//free(p);
	delete[] p;

	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[ColSize], int, int);
	void printData(struct _SData[ColSize], int, int);
}SData;

void SData::inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void SData::printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}

int main(void) {
	SData x[ColSize];
	typedef void (SData:: * FunctionPtr)(SData[ColSize], int, int);
	FunctionPtr(*p)[FColSize];
	int i, j, CSize;

	//p = (FunctionPtr(*)[FColSize])malloc(sizeof(FunctionPtr)*FRowSize*FColSize);
	p = new FunctionPtr[FRowSize][FColSize];

	p[0][0] = &SData::inputData;
	p[0][1] = &SData::printData;

	i = 0;
	CSize = ColSize;

	//x[0].inputData(x, i, CSize);
	//x[0].printData(x, i, CSize);

	//x[0].SData::inputData(x, i, CSize);
	//x[0].SData::printData(x, i, CSize);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			(x[0].*p[i][j])(x, i, CSize);
		}
	}

	//free(p);
	delete[] p;

	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[ColSize], int, int);
	void printData(struct _SData[ColSize], int, int);
}SData;

void SData::inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}

void SData::printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}

typedef struct Type
{
	typedef void (SData::* FunctionPtr)(SData[ColSize], int, int);
}Type;

int main(void) {
	SData x[ColSize];
	Type::FunctionPtr(*p)[FColSize];
	int i, j, CSize;

	//p = (Type::FunctionPtr(*)[FColSize])malloc(sizeof(Type::FunctionPtr)*FRowSize*FColSize);
	p = new Type::FunctionPtr[FRowSize][FColSize];


	p[0][0] = &(SData::inputData);
	p[0][1] = &(SData::printData);

	i = 0;
	CSize = ColSize;

	//x[0].inputData(x, i, CSize);
	//x[0].printData(x, i, CSize);

	//x[0].SData::inputData(x, i, CSize);
	//x[0].SData::printData(x, i, CSize);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			(x[0].*p[i][j])(x, i, CSize);
		}
	}
	//free(p);
	delete[] p;

	return 0;
}
#endif

//=========================================================================================
// 8-10. 구조체 1차원 배열 - typedef를 이용한 함수 포인터 - 이중 포인터
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

#define FRowSize 1
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

void inputData(SData x[ColSize], int i, int CSize);
void printData(SData x[ColSize], int i, int CSize);

int main(void) {
	typedef void(*FunctionPtr)(SData[ColSize], int, int);
	FunctionPtr** p;
	SData x[ColSize];
	int i, j, CSize;

	//p = (FunctionPtr**)malloc(sizeof(FunctionPtr*)*FRowSize);
	p = new FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, CSize);
			(*p[i][j])(x, i, CSize);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;
	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define FRowSize 1
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef void(*FunctionPtr)(struct _SData[ColSize], int, int);
}SData;

void inputData(SData x[ColSize], int i, int CSize);
void printData(SData x[ColSize], int i, int CSize);

int main(void) {
	SData x[ColSize];
	SData::FunctionPtr** p;
	int i, j, CSize;

	//p = (SData::FunctionPtr**)malloc(sizeof(SData::FunctionPtr*)*FRowSize);
	p = new SData::FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
		p[i] = new SData::FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, CSize);
			(*p[i][j])(x, i, CSize);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;
	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[ColSize], int, int);
	void printData(struct _SData[ColSize], int, int);
}SData;

void SData::inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void SData::printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}

int main(void) {
	SData x[ColSize];
	typedef void (SData:: * FunctionPtr)(SData[ColSize], int, int);
	FunctionPtr** p;
	int i, j, CSize;

	//p = (FunctionPtr**)malloc(sizeof(FunctionPtr*)*FRowSize);
	p = new FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}
	p[0][0] = &SData::inputData;
	p[0][1] = &SData::printData;

	i = 0;
	CSize = ColSize;

	//x[0].inputData(x, i, CSize);
	//x[0].printData(x, i, CSize);

	//x[0].SData::inputData(x, i, CSize);
	//x[0].SData::printData(x, i, CSize);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			(x[0].*p[i][j])(x, i, CSize);
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;
	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[ColSize], int, int);
	void printData(struct _SData[ColSize], int, int);
}SData;

void SData::inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}

void SData::printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}

typedef struct Type
{
	typedef void (SData::* FunctionPtr)(SData[ColSize], int, int);
}Type;

int main(void) {
	SData x[ColSize];
	Type::FunctionPtr** p;
	int i, j, CSize;

	//p = (Type::FunctionPtr**)malloc(sizeof(Type::FunctionPtr*)*FRowSize);
	p = new Type::FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
		p[i] = new Type::FunctionPtr[FColSize];

	}

	p[0][0] = &(SData::inputData);
	p[0][1] = &(SData::printData);

	i = 0;
	CSize = ColSize;

	//x[0].inputData(x, i, CSize);
	//x[0].printData(x, i, CSize);

	//x[0].SData::inputData(x, i, CSize);
	//x[0].SData::printData(x, i, CSize);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			(x[0].*p[i][j])(x, i, CSize);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;
	return 0;
}
#endif










//=========================================================================================
// 9. 구조체 2차원 배열 - 기본코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

void inputData(SData[RowSize][ColSize], int, int, int, int);
void printData(SData[RowSize][ColSize], int, int, int, int);

int main(void) {
	SData x[RowSize][ColSize];
	int i, j, RSize, CSize;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	inputData(x, i, j, RSize, CSize);
	printData(x, i, j, RSize, CSize);

	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

//=========================================================================================
// 9-1. 구조체 2차원 배열 - 함수 포인터로 변환한 형태
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

void inputData(SData[RowSize][ColSize], int, int, int, int);
void printData(SData[RowSize][ColSize], int, int, int, int);

int main(void) {
	SData x[RowSize][ColSize];
	//void(*FunctionPtr1)(SData[RowSize][ColSize], int, int, int, int) = inputData;
	//void(*FunctionPtr2)(SData[RowSize][ColSize], int, int, int, int) = printData;
	void(*FunctionPtr1)(SData[RowSize][ColSize], int, int, int, int) = &inputData;
	void(*FunctionPtr2)(SData[RowSize][ColSize], int, int, int, int) = &printData;
	int i, j, RSize, CSize;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	//(FunctionPtr1)(x, i, j, RSize, CSize);
	//(FunctionPtr2)(x, i, j, RSize, CSize);
	(*FunctionPtr1)(x, i, j, RSize, CSize);
	(*FunctionPtr2)(x, i, j, RSize, CSize);

	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void(*Functionptr1)(struct _SData[RowSize][ColSize], int, int, int, int);
	void(*Functionptr2)(struct _SData[RowSize][ColSize], int, int, int, int);

}SData;

void inputData(SData[RowSize][ColSize], int, int, int, int);
void printData(SData[RowSize][ColSize], int, int, int, int);

int main(void) {
	SData x[RowSize][ColSize];
	int i, j, RSize, CSize;

	for (i = 0; i < 1; i++)
	{
		for (j = 0; j < 1; j++)
		{
			//x[i][j].Functionptr1 = inputData;
			//x[i][j].Functionptr2 = printData;
			x[i][j].Functionptr1 = &inputData;
			x[i][j].Functionptr2 = &printData;
		}
	}

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < 1; i++)
	{
		for (j = 0; j < 1; j++)
		{
			//x[i][j].Functionptr1(x, i, j, RSize, CSize);
			//x[i][j].Functionptr2(x, i, j, RSize, CSize);
			(*x[i][j].Functionptr1)(x, i, j, RSize, CSize);
			(*x[i][j].Functionptr2)(x, i, j, RSize, CSize);
		}
	}
	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[RowSize][ColSize], int, int, int, int);
	void printData(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void SData::inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void SData::printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}

int main(void) {
	SData x[RowSize][ColSize];
	//void(SData::*FunctionPtr1)(SData[RowSize][ColSize], int, int, int, int) = &SData::inputData;
	//void(SData::*FunctionPtr2)(SData[RowSize][ColSize], int, int, int, int) = &SData::printData;
	void(SData:: * FunctionPtr1)(SData[RowSize][ColSize], int, int, int, int);
	void(SData:: * FunctionPtr2)(SData[RowSize][ColSize], int, int, int, int);
	int i, j, RSize, CSize;

	FunctionPtr1 = &SData::inputData;
	FunctionPtr2 = &SData::printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	//x[0][0].inputData(x, i, j, RSize, CSize);
	//x[0][0].printData(x, i, j, RSize, CSize);

	//x[0][0].SData::inputData(x, i, j, RSize, CSize);
	//x[0][0].SData::printData(x, i, j, RSize, CSize);

	(x[0][0].*FunctionPtr1)(x, i, j, RSize, CSize);
	(x[0][0].*FunctionPtr2)(x, i, j, RSize, CSize);

	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[RowSize][ColSize], int, int, int, int);
	void printData(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void SData::inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void SData::printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}

typedef struct Type
{
	void(SData::* FunctionPtr1)(SData[RowSize][ColSize], int, int, int, int);
	void(SData::* FunctionPtr2)(SData[RowSize][ColSize], int, int, int, int);
}Type;

int main(void) {
	SData x[RowSize][ColSize];
	Type fp;
	int i, j, RSize, CSize;

	fp.FunctionPtr1 = &SData::inputData;
	fp.FunctionPtr2 = &SData::printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	//x[0][0].inputData(x, i, j, RSize, CSize);
	//x[0][0].printData(x, i, j, RSize, CSize);

	//x[0][0].SData::inputData(x, i, j, RSize, CSize);
	//x[0][0].SData::printData(x, i, j, RSize, CSize);

	(x[0][0].*fp.FunctionPtr1)(x, i, j, RSize, CSize);
	(x[0][0].*fp.FunctionPtr2)(x, i, j, RSize, CSize);

	return 0;
}
#endif

//=========================================================================================
// 9-2. 구조체 2차원 배열 - 함수 포인터 1차원 배열로 변환한 형태
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);

int main(void) {
	//void(*FunctionPtr[FColSize])(SData[RowSize][ColSize], int, int, int, int) = { inputData, printData };
	void(*FunctionPtr[FColSize])(SData[RowSize][ColSize], int, int, int, int) = { &inputData, &printData };
	SData x[RowSize][ColSize];
	int i, j, RSize, CSize;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//FunctionPtr[i](x, i, j, RSize, CSize);
		(*FunctionPtr[i])(x, i, j, RSize, CSize);
	}
	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void(*FunctionPtr[FColSize])(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);

int main(void) {
	SData x[RowSize][ColSize];
	int i, j, k, RSize, CSize;

	//x[0][0].FunctionPtr[0] = inputData;
	//x[0][0].FunctionPtr[1] = printData;
	x[0][0].FunctionPtr[0] = &inputData;
	x[0][0].FunctionPtr[1] = &printData;


	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < 1; i++)
	{
		for (j = 0; j < 1; j++)
		{
			for (k = 0; k < FColSize; k++)
			{
				//x[i][j].FunctionPtr[k](x, i, j, RSize, CSize);
				(*x[i][j].FunctionPtr[k])(x, i, j, RSize, CSize);
			}
		}
	}


	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[RowSize][ColSize], int, int, int, int);
	void printData(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void SData::inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void SData::printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}

int main(void) {
	SData x[RowSize][ColSize];
	//void(SData::*FunctionPtr[FColSize])(SData[RowSize][ColSize], int, int, int, int) = { &SData::inputData, &SData::printData };
	void(SData:: * FunctionPtr[FColSize])(SData[RowSize][ColSize], int, int, int, int);
	int i, j, RSize, CSize;

	FunctionPtr[0] = &SData::inputData;
	FunctionPtr[1] = &SData::printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	//x[0][0].inputData(x, i, j, RSize, CSize);
	//x[0][0].printData(x, i, j, RSize, CSize);

	//x[0][0].SData::inputData(x, i, j, RSize, CSize);
	//x[0][0].SData::printData(x, i, j, RSize, CSize);

	for (i = 0; i < FColSize; i++)
	{
		(x[0][0].*FunctionPtr[i])(x, i, j, RSize, CSize);
	}

	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[RowSize][ColSize], int, int, int, int);
	void printData(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void SData::inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void SData::printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}

typedef struct Type
{
	void(SData::* FunctionPtr[FColSize])(SData[RowSize][ColSize], int, int, int, int);
}Type;

int main(void) {
	SData x[RowSize][ColSize];
	Type fp;
	int i, j, RSize, CSize;

	fp.FunctionPtr[0] = &SData::inputData;
	fp.FunctionPtr[1] = &SData::printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	//x[0][0].inputData(x, i, j, RSize, CSize);
	//x[0][0].printData(x, i, j, RSize, CSize);

	//x[0][0].SData::inputData(x, i, j, RSize, CSize);
	//x[0][0].SData::printData(x, i, j, RSize, CSize);

	for (i = 0; i < FColSize; i++)
	{
		(x[0][0].*fp.FunctionPtr[i])(x, i, j, RSize, CSize);
	}

	return 0;
}
#endif

//=========================================================================================
// 9-3. 구조체 2차원 배열 - 함수 포인터 2차원 배열로 변환한 형태
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);

int main(void) {
	//void(*FunctionPtr[FRowSize][FColSize])(SData[RowSize][ColSize], int, int, int, int) = { inputData, printData };
	void(*FunctionPtr[FRowSize][FColSize])(SData[RowSize][ColSize], int, int, int, int) = { &inputData, &printData };
	SData x[RowSize][ColSize];
	int i, j, RSize, CSize;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//FunctionPtr[i][j](x, i, j, RSize, CSize);
			(*FunctionPtr[i][j])(x, i, j, RSize, CSize);
		}
	}
	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void(*FunctionPtr[FRowSize][FColSize])(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);

int main(void) {
	SData x[RowSize][ColSize];
	int i, j, k, l, RSize, CSize;

	//x[0][0].FunctionPtr[0][0] = inputData;
	//x[0][0].FunctionPtr[0][1] = printData;
	x[0][0].FunctionPtr[0][0] = &inputData;
	x[0][0].FunctionPtr[0][1] = &printData;


	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < 1; i++)
	{
		for (j = 0; j < 1; j++)
		{
			for (k = 0; k < FRowSize; k++)
			{
				for (l = 0; l < FColSize; l++)
				{
					//x[i][j].FunctionPtr[k][l](x, i, j, RSize, CSize);
					(*x[i][j].FunctionPtr[k][l])(x, i, j, RSize, CSize);
				}
			}
		}
	}
	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[RowSize][ColSize], int, int, int, int);
	void printData(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void SData::inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void SData::printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}

int main(void) {
	SData x[RowSize][ColSize];
	//void(SData::*FunctionPtr[FRowSize][FColSize])(SData[RowSize][ColSize], int, int, int, int) = { &SData::inputData, &SData::printData };
	void(SData:: * FunctionPtr[FRowSize][FColSize])(SData[RowSize][ColSize], int, int, int, int);
	int i, j, RSize, CSize;

	FunctionPtr[0][0] = &SData::inputData;
	FunctionPtr[0][1] = &SData::printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	//x[0][0].inputData(x, i, j, RSize, CSize);
	//x[0][0].printData(x, i, j, RSize, CSize);

	//x[0][0].SData::inputData(x, i, j, RSize, CSize);
	//x[0][0].SData::printData(x, i, j, RSize, CSize);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			(x[0][0].*FunctionPtr[i][j])(x, i, j, RSize, CSize);
		}
	}
	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[RowSize][ColSize], int, int, int, int);
	void printData(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void SData::inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void SData::printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}

typedef struct Type
{
	void(SData::* FunctionPtr[FRowSize][FColSize])(SData[RowSize][ColSize], int, int, int, int);
}Type;

int main(void) {
	SData x[RowSize][ColSize];
	Type fp;
	int i, j, RSize, CSize;

	fp.FunctionPtr[0][0] = &SData::inputData;
	fp.FunctionPtr[0][1] = &SData::printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	//x[0][0].inputData(x, i, j, RSize, CSize);
	//x[0][0].printData(x, i, j, RSize, CSize);

	//x[0][0].SData::inputData(x, i, j, RSize, CSize);
	//x[0][0].SData::printData(x, i, j, RSize, CSize);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			(x[0][0].*fp.FunctionPtr[i][j])(x, i, j, RSize, CSize);
		}
	}

	return 0;
}
#endif

//=========================================================================================
// 9-4. 구조체 2차원 배열 - typedef를 이용한 함수 포인터
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

void inputData(SData[RowSize][ColSize], int, int, int, int);
void printData(SData[RowSize][ColSize], int, int, int, int);

int main(void) {
	SData x[RowSize][ColSize];
	typedef void(*FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
	FunctionPtr p1, p2;
	int i, j, RSize, CSize;

	//p1 = inputData;
	//p2 = printData;
	p1 = &inputData;
	p2 = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	//(p1)(x, i, j, RSize, CSize);
	//(p2)(x, i, j, RSize, CSize);
	(*p1)(x, i, j, RSize, CSize);
	(*p2)(x, i, j, RSize, CSize);

	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef void(*Functionptr)(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void inputData(SData[RowSize][ColSize], int, int, int, int);
void printData(SData[RowSize][ColSize], int, int, int, int);

int main(void) {
	SData x[RowSize][ColSize];
	SData::Functionptr p1, p2;
	int i, j, RSize, CSize;

	//p1 = inputData;
	//p2 = printData;
	p1 = &inputData;
	p2 = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	//p1(x, i, j, RSize, CSize);
	//p2(x, i, j, RSize, CSize);
	(*p1)(x, i, j, RSize, CSize);
	(*p2)(x, i, j, RSize, CSize);
	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[RowSize][ColSize], int, int, int, int);
	void printData(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void SData::inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void SData::printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}

int main(void) {
	SData x[RowSize][ColSize];
	typedef void(SData:: * FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
	FunctionPtr p1, p2;
	int i, j, RSize, CSize;

	p1 = &SData::inputData;
	p2 = &SData::printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	//x[0][0].inputData(x, i, j, RSize, CSize);
	//x[0][0].printData(x, i, j, RSize, CSize);

	//x[0][0].SData::inputData(x, i, j, RSize, CSize);
	//x[0][0].SData::printData(x, i, j, RSize, CSize);

	(x[0][0].*p1)(x, i, j, RSize, CSize);
	(x[0][0].*p2)(x, i, j, RSize, CSize);

	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[RowSize][ColSize], int, int, int, int);
	void printData(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void SData::inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void SData::printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}

typedef struct Type
{
	typedef void(SData::* FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
}Type;

int main(void) {
	SData x[RowSize][ColSize];
	Type::FunctionPtr p1, p2;
	int i, j, RSize, CSize;

	p1 = &SData::inputData;
	p2 = &SData::printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	//x[0][0].inputData(x, i, j, RSize, CSize);
	//x[0][0].printData(x, i, j, RSize, CSize);

	//x[0][0].SData::inputData(x, i, j, RSize, CSize);
	//x[0][0].SData::printData(x, i, j, RSize, CSize);

	(x[0][0].*p1)(x, i, j, RSize, CSize);
	(x[0][0].*p2)(x, i, j, RSize, CSize);

	return 0;
}
#endif

//=========================================================================================
// 9-5. 구조체 2차원 배열 - typedef를 이용한 함수 포인터 - 1차원 배열
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);

int main(void) {
	typedef void(*FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
	//FunctionPtr p[FColSize] = { inputData, printData };
	FunctionPtr p[FColSize] = { &inputData, &printData };
	SData x[RowSize][ColSize];
	int i, j, RSize, CSize;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](x, i, j, RSize, CSize);
		(*p[i])(x, i, j, RSize, CSize);
	}
	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef void(*FunctionPtr)(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);

int main(void) {
	//SData::FunctionPtr p[FColSize] = { inputData, printData };
	SData::FunctionPtr p[FColSize] = { &inputData, &printData };
	SData x[RowSize][ColSize];
	int i, j, RSize, CSize;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](x, i, j, RSize, CSize);
		(*p[i])(x, i, j, RSize, CSize);
	}
	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[RowSize][ColSize], int, int, int, int);
	void printData(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void SData::inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void SData::printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}

int main(void) {
	SData x[RowSize][ColSize];
	typedef void (SData:: * FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
	FunctionPtr p[FColSize];
	int i, j, RSize, CSize;

	p[0] = &SData::inputData;
	p[1] = &SData::printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	//x[0][0].inputData(x, i, j, RSize, CSize);
	//x[0][0].printData(x, i, j, RSize, CSize);

	//x[0][0].SData::inputData(x, i, j, RSize, CSize);
	//x[0][0].SData::printData(x, i, j, RSize, CSize);

	for (i = 0; i < FColSize; i++)
	{
		(x[0][0].*p[i])(x, i, j, RSize, CSize);
	}
	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[RowSize][ColSize], int, int, int, int);
	void printData(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void SData::inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void SData::printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}

typedef struct Type
{
	typedef void(SData::* FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
}Type;

int main(void) {
	SData x[RowSize][ColSize];
	Type::FunctionPtr p[FColSize];
	int i, j, RSize, CSize;

	p[0] = &SData::inputData;
	p[1] = &SData::printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	//x[0][0].inputData(x, i, j, RSize, CSize);
	//x[0][0].printData(x, i, j, RSize, CSize);

	//x[0][0].SData::inputData(x, i, j, RSize, CSize);
	//x[0][0].SData::printData(x, i, j, RSize, CSize);

	for (i = 0; i < FColSize; i++)
	{
		(x[0][0].*p[i])(x, i, j, RSize, CSize);
	}

	return 0;
}
#endif

//=========================================================================================
// 9-6. 구조체 2차원 배열 - typedef를 이용한 함수 포인터 - 1차원 포인터
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);

int main(void) {
	typedef void(*FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
	FunctionPtr* p;
	SData x[RowSize][ColSize];
	int i, j, RSize, CSize;

	//p = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
	p = new FunctionPtr[FColSize];
	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](x, i, j, RSize, CSize);
		(*p[i])(x, i, j, RSize, CSize);
	}

	//free(p);
	delete[] p;
	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef void(*FunctionPtr)(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);

int main(void) {
	SData::FunctionPtr* p;
	SData x[RowSize][ColSize];
	int i, j, RSize, CSize;

	//p = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
	p = new SData::FunctionPtr[FColSize];
	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](x, i, j, RSize, CSize);
		(*p[i])(x, i, j, RSize, CSize);
	}

	//free(p);
	delete[] p;
	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[RowSize][ColSize], int, int, int, int);
	void printData(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void SData::inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void SData::printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}

int main(void) {
	SData x[RowSize][ColSize];
	typedef void (SData:: * FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
	FunctionPtr* p;
	int i, j, RSize, CSize;

	//p = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
	p = new FunctionPtr[FColSize];

	p[0] = &SData::inputData;
	p[1] = &SData::printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	//x[0][0].inputData(x, i, j, RSize, CSize);
	//x[0][0].printData(x, i, j, RSize, CSize);

	//x[0][0].SData::inputData(x, i, j, RSize, CSize);
	//x[0][0].SData::printData(x, i, j, RSize, CSize);

	for (i = 0; i < FColSize; i++)
	{
		(x[0][0].*p[i])(x, i, j, RSize, CSize);
	}

	//free(p);
	delete[] p;
	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[RowSize][ColSize], int, int, int, int);
	void printData(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void SData::inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void SData::printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}

typedef struct Type
{
	typedef void(SData::* FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
}Type;

int main(void) {
	SData x[RowSize][ColSize];
	Type::FunctionPtr* p;
	int i, j, RSize, CSize;

	//p = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
	p = new Type::FunctionPtr[FColSize];

	p[0] = &SData::inputData;
	p[1] = &SData::printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	//x[0][0].inputData(x, i, j, RSize, CSize);
	//x[0][0].printData(x, i, j, RSize, CSize);

	//x[0][0].SData::inputData(x, i, j, RSize, CSize);
	//x[0][0].SData::printData(x, i, j, RSize, CSize);

	for (i = 0; i < FColSize; i++)
	{
		(x[0][0].*p[i])(x, i, j, RSize, CSize);
	}

	//free(p);
	delete[] p;

	return 0;
}
#endif

//=========================================================================================
// 9-7. 구조체 2차원 배열 - typedef를 이용한 함수 포인터 - 2차원 배열
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);

int main(void) {
	typedef void(*FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
	//FunctionPtr p[FRowSize][FColSize] = { inputData, printData };
	FunctionPtr p[FRowSize][FColSize] = { &inputData, &printData };
	SData x[RowSize][ColSize];
	int i, j, RSize, CSize;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, j, RSize, CSize);
			(*p[i][j])(x, i, j, RSize, CSize);
		}
	}
	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef void(*FunctionPtr)(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);

int main(void) {
	//SData::FunctionPtr p[FRowSize][FColSize] = { inputData, printData };
	SData::FunctionPtr p[FRowSize][FColSize] = { &inputData, &printData };
	SData x[RowSize][ColSize];
	int i, j, RSize, CSize;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, j, RSize, CSize);
			(*p[i][j])(x, i, j, RSize, CSize);
		}
	}
	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[RowSize][ColSize], int, int, int, int);
	void printData(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void SData::inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void SData::printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}

int main(void) {
	SData x[RowSize][ColSize];
	typedef void (SData:: * FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
	FunctionPtr p[FRowSize][FColSize];
	int i, j, RSize, CSize;

	p[0][0] = &SData::inputData;
	p[0][1] = &SData::printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	//x[0][0].inputData(x, i, j, RSize, CSize);
	//x[0][0].printData(x, i, j, RSize, CSize);

	//x[0][0].SData::inputData(x, i, j, RSize, CSize);
	//x[0][0].SData::printData(x, i, j, RSize, CSize);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			(x[0][0].*p[i][j])(x, i, j, RSize, CSize);
		}
	}
	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[RowSize][ColSize], int, int, int, int);
	void printData(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void SData::inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void SData::printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}

typedef struct Type
{
	typedef void(SData::* FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
}Type;

int main(void) {
	SData x[RowSize][ColSize];
	Type::FunctionPtr p[FRowSize][FColSize];
	int i, j, RSize, CSize;

	p[0][0] = &SData::inputData;
	p[0][1] = &SData::printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	//x[0][0].inputData(x, i, j, RSize, CSize);
	//x[0][0].printData(x, i, j, RSize, CSize);

	//x[0][0].SData::inputData(x, i, j, RSize, CSize);
	//x[0][0].SData::printData(x, i, j, RSize, CSize);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			(x[0][0].*p[i][j])(x, i, j, RSize, CSize);
		}
	}
	return 0;
}
#endif

//=========================================================================================
// 9-8. 구조체 2차원 배열 - typedef를 이용한 함수 포인터 - 포인터 배열
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);

int main(void) {
	typedef void(*FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
	FunctionPtr* p[FRowSize];
	SData x[RowSize][ColSize];
	int i, j, RSize, CSize;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, j, RSize, CSize);
			(*p[i][j])(x, i, j, RSize, CSize);
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef void(*FunctionPtr)(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);

int main(void) {
	SData::FunctionPtr* p[FRowSize];
	SData x[RowSize][ColSize];
	int i, j, RSize, CSize;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
		p[i] = new SData::FunctionPtr[FColSize];
	}

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, j, RSize, CSize);
			(*p[i][j])(x, i, j, RSize, CSize);
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[RowSize][ColSize], int, int, int, int);
	void printData(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void SData::inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void SData::printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}

int main(void) {
	SData x[RowSize][ColSize];
	typedef void (SData:: * FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
	FunctionPtr* p[FRowSize];
	int i, j, RSize, CSize;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}

	p[0][0] = &SData::inputData;
	p[0][1] = &SData::printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	//x[0][0].inputData(x, i, j, RSize, CSize);
	//x[0][0].printData(x, i, j, RSize, CSize);

	//x[0][0].SData::inputData(x, i, j, RSize, CSize);
	//x[0][0].SData::printData(x, i, j, RSize, CSize);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			(x[0][0].*p[i][j])(x, i, j, RSize, CSize);
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}

	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[RowSize][ColSize], int, int, int, int);
	void printData(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void SData::inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void SData::printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}

typedef struct Type
{
	typedef void(SData::* FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
}Type;

int main(void) {
	SData x[RowSize][ColSize];
	Type::FunctionPtr* p[FRowSize];
	int i, j, RSize, CSize;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
		p[i] = new Type::FunctionPtr[FColSize];
	}

	p[0][0] = &SData::inputData;
	p[0][1] = &SData::printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	//x[0][0].inputData(x, i, j, RSize, CSize);
	//x[0][0].printData(x, i, j, RSize, CSize);

	//x[0][0].SData::inputData(x, i, j, RSize, CSize);
	//x[0][0].SData::printData(x, i, j, RSize, CSize);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			(x[0][0].*p[i][j])(x, i, j, RSize, CSize);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}

	return 0;
}
#endif

//=========================================================================================
// 9-9. 구조체 2차원 배열 - typedef를 이용한 함수 포인터 - 배열 포인터
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);

int main(void) {
	typedef void(*FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
	FunctionPtr(*p)[FColSize];
	SData x[RowSize][ColSize];
	int i, j, RSize, CSize;

	//p = (FunctionPtr(*)[FColSize])malloc(sizeof(FunctionPtr)*FRowSize*FColSize);
	p = new FunctionPtr[FRowSize][FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, j, RSize, CSize);
			(*p[i][j])(x, i, j, RSize, CSize);
		}
	}

	//free(p);
	delete[] p;
	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef void(*FunctionPtr)(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);

int main(void) {
	SData::FunctionPtr(*p)[FColSize];
	SData x[RowSize][ColSize];
	int i, j, RSize, CSize;

	//p = (SData::FunctionPtr(*)[FColSize])malloc(sizeof(SData::FunctionPtr)*FRowSize*FColSize);
	p = new SData::FunctionPtr[FRowSize][FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, j, RSize, CSize);
			(*p[i][j])(x, i, j, RSize, CSize);
		}
	}

	free(p);
	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[RowSize][ColSize], int, int, int, int);
	void printData(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void SData::inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void SData::printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}

int main(void) {
	SData x[RowSize][ColSize];
	typedef void (SData:: * FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
	FunctionPtr(*p)[FColSize];
	int i, j, RSize, CSize;

	//p = (FunctionPtr(*)[FColSize])malloc(sizeof(FunctionPtr)*FRowSize*FColSize);
	p = new FunctionPtr[FRowSize][FColSize];

	p[0][0] = &SData::inputData;
	p[0][1] = &SData::printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	//x[0][0].inputData(x, i, j, RSize, CSize);
	//x[0][0].printData(x, i, j, RSize, CSize);

	//x[0][0].SData::inputData(x, i, j, RSize, CSize);
	//x[0][0].SData::printData(x, i, j, RSize, CSize);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			(x[0][0].*p[i][j])(x, i, j, RSize, CSize);
		}
	}

	//free(p);
	delete[] p;

	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[RowSize][ColSize], int, int, int, int);
	void printData(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void SData::inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void SData::printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}

typedef struct Type
{
	typedef void(SData::* FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
}Type;

int main(void) {
	SData x[RowSize][ColSize];
	Type::FunctionPtr(*p)[FColSize];
	int i, j, RSize, CSize;

	//p = (Type::FunctionPtr(*)[FColSize])malloc(sizeof(Type::FunctionPtr)*FRowSize*FColSize);
	p = new Type::FunctionPtr[FRowSize][FColSize];


	p[0][0] = &SData::inputData;
	p[0][1] = &SData::printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	//x[0][0].inputData(x, i, j, RSize, CSize);
	//x[0][0].printData(x, i, j, RSize, CSize);

	//x[0][0].SData::inputData(x, i, j, RSize, CSize);
	//x[0][0].SData::printData(x, i, j, RSize, CSize);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			(x[0][0].*p[i][j])(x, i, j, RSize, CSize);
		}
	}

	//free(p);
	delete[] p;

	return 0;
}
#endif

//=========================================================================================
// 9-10. 구조체 2차원 배열 - typedef를 이용한 함수 포인터 - 이중 포인터
//=========================================================================================
// 가. C언어-main 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
}SData;

void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);

int main(void) {
	typedef void(*FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
	FunctionPtr** p;
	SData x[RowSize][ColSize];
	int i, j, RSize, CSize;

	//p = (FunctionPtr**)malloc(sizeof(FunctionPtr*)*FRowSize);
	p = new FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, j, RSize, CSize);
			(*p[i][j])(x, i, j, RSize, CSize);
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;
	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

// 나. C언어-구조체 내부에 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	typedef void(*FunctionPtr)(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize);

int main(void) {
	SData::FunctionPtr** p;
	SData x[RowSize][ColSize];
	int i, j, RSize, CSize;

	//p = (SData::FunctionPtr**)malloc(sizeof(SData::FunctionPtr*)*FRowSize);
	p = new SData::FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
		p[i] = new SData::FunctionPtr[FColSize];
	}

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, j, RSize, CSize);
			(*p[i][j])(x, i, j, RSize, CSize);
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;
	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

// 다. 구조체 멤버로 inputData, printData 함수를 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[RowSize][ColSize], int, int, int, int);
	void printData(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void SData::inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void SData::printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}

int main(void) {
	SData x[RowSize][ColSize];
	typedef void (SData:: * FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
	FunctionPtr** p;
	int i, j, RSize, CSize;

	//p = (FunctionPtr**)malloc(sizeof(FunctionPtr*)*FRowSize);
	p = new FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}

	p[0][0] = &SData::inputData;
	p[0][1] = &SData::printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	//x[0][0].inputData(x, i, j, RSize, CSize);
	//x[0][0].printData(x, i, j, RSize, CSize);

	//x[0][0].SData::inputData(x, i, j, RSize, CSize);
	//x[0][0].SData::printData(x, i, j, RSize, CSize);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			(x[0][0].*p[i][j])(x, i, j, RSize, CSize);
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;

	return 0;
}
#endif

// 라. 구조체 멤버로 inputData, printData 함수를 포함 + Type 구조체에 함수 포인터 포함시킨 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
typedef struct _SData
{
	double RATE;
	int MIN_BALANCE;
	void inputData(struct _SData[RowSize][ColSize], int, int, int, int);
	void printData(struct _SData[RowSize][ColSize], int, int, int, int);
}SData;

void SData::inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void SData::printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}

typedef struct Type
{
	typedef void(SData::* FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
}Type;

int main(void) {
	SData x[RowSize][ColSize];
	Type::FunctionPtr** p;
	int i, j, RSize, CSize;

	//p = (Type::FunctionPtr**)malloc(sizeof(Type::FunctionPtr*)*FRowSize);
	p = new Type::FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
		p[i] = new Type::FunctionPtr[FColSize];
	}

	p[0][0] = &SData::inputData;
	p[0][1] = &SData::printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	//x[0][0].inputData(x, i, j, RSize, CSize);
	//x[0][0].printData(x, i, j, RSize, CSize);

	//x[0][0].SData::inputData(x, i, j, RSize, CSize);
	//x[0][0].SData::printData(x, i, j, RSize, CSize);

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			(x[0][0].*p[i][j])(x, i, j, RSize, CSize);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;

	return 0;
}
#endif











//=========================================================================================
// 10. 클래스 변수(call by value) - 기본코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	x = inputData(x);
	x = printData(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

//=========================================================================================
// 10-1. 클래스 변수(call by value) - 함수 포인터로 변환한 형태
//=========================================================================================
// 가.메인 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;
	//SData(*FunctionPtr1)(SData) = inputData;
	//SData(*FunctionPtr2)(SData) = printData;
	SData(*FunctionPtr1)(SData) = &inputData;
	SData(*FunctionPtr2)(SData) = &printData;
	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	//x = FunctionPtr1(x);
	//x = FunctionPtr2(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성
	x = (*FunctionPtr1)(x);
	x = (*FunctionPtr2)(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 나. 클래스 내부에서 함수 포인터를 사용한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	SData(*FunctionPtr1)(SData);
	SData(*FunctionPtr2)(SData);
};

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;
	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	//x.FunctionPtr1 = inputData;
	//x.FunctionPtr2 = printData;
	x.FunctionPtr1 = &inputData;
	x.FunctionPtr2 = &printData;

	//x = (x.FunctionPtr1)(x);
	//x = (x.FunctionPtr2)(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	x = ((*x.FunctionPtr1))(x);
	x = ((*x.FunctionPtr2))(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	//x = (x.SData::FunctionPtr1)(x);
	//x = (x.SData::FunctionPtr2)(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	//x = (*x.SData::FunctionPtr1)(x);
	//x = (*x.SData::FunctionPtr2)(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 다. 클래스 멤버 함수로 inputData, printData 사용한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	SData inputData(SData);
	SData printData(SData);
};
SData SData::inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData SData::printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
int main(void) {
	SData x;
	//SData(SData::*FunctionPtr1)(SData x) = &(SData::inputData);
	//SData(SData::*FunctionPtr2)(SData x) = &(SData::printData);
	SData(SData:: * FunctionPtr1)(SData x);
	SData(SData:: * FunctionPtr2)(SData x);

	FunctionPtr1 = &SData::inputData;
	FunctionPtr2 = &SData::printData;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	x = (x.*FunctionPtr1)(x);
	x = (x.*FunctionPtr2)(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	return 0;
}
#endif

// 라. 다른 클래스에서 함수 포인터를 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	SData(*FunctionPtr1)(SData);
	SData(*FunctionPtr2)(SData);
};

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;
	Type p;

	//p.FunctionPtr1 = inputData;
	//p.FunctionPtr2 = printData;
	p.FunctionPtr1 = &inputData;
	p.FunctionPtr2 = &printData;

	x.RATE = x.MIN_BALANCE = 0;

	//x = (p.FunctionPtr1)(x);
	//x = (p.FunctionPtr2)(x);

	x = (*p.FunctionPtr1)(x);
	x = (*p.FunctionPtr2)(x);

	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 마. 다른 클래스에서 함수 포인터를 선언 + inputData, printData는 SData 클래스에 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	SData inputData(SData);
	SData printData(SData);
};
SData SData::inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData SData::printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
class Type
{
public:
	SData(SData::* FunctionPtr1)(SData x);
	SData(SData::* FunctionPtr2)(SData x);
};
int main(void) {
	SData x;
	Type p;

	p.FunctionPtr1 = &SData::inputData;
	p.FunctionPtr2 = &SData::printData;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	x = (x.*p.FunctionPtr1)(x);
	x = (x.*p.FunctionPtr2)(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	return 0;
}
#endif

//=========================================================================================
// 10-2. 클래스 변수(call by value) - 함수 포인터 1차원 배열로 변환한 형태
//=========================================================================================
// 가.메인 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;
	//SData(*FunctionPtr[FColSize])(SData x) = { inputData, printData };
	SData(*FunctionPtr[FColSize])(SData x) = { &inputData, &printData };
	int i;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < FColSize; i++)
	{
		//x = FunctionPtr[i](x);
		x = (*FunctionPtr[i])(x);
	}
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 나. 클래스 내부에서 함수 포인터를 사용한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	SData(*FunctionPtr[FColSize])(SData x);
};

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;
	int i;

	//x.FunctionPtr[0] = inputData;
	//x.FunctionPtr[1] = printData;
	x.FunctionPtr[0] = &inputData;
	x.FunctionPtr[1] = &printData;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < FColSize; i++)
	{
		//x = x.FunctionPtr[i](x);
		x = (*x.FunctionPtr[i])(x);
	}
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 다. 클래스 멤버 함수로 inputData, printData 사용한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	SData inputData(SData);
	SData printData(SData);
};
SData SData::inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData SData::printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
int main(void) {
	SData x;
	SData(SData:: * FunctionPtr[FColSize])(SData x) = { &(SData::inputData), &(SData::printData) };
	int i;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < FColSize; i++)
	{
		x = (x.*FunctionPtr[i])(x);
	}
	return 0;
}
#endif

//=========================================================================================
// 10-3. 클래스 변수(call by value) - 함수 포인터 2차원 배열로 변환한 형태
//=========================================================================================
// 가.메인 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;
	//SData(*FunctionPtr[FRowSize][FColSize])(SData x) = { inputData, printData };
	SData(*FunctionPtr[FRowSize][FColSize])(SData x) = { &inputData, &printData };
	int i, j;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = FunctionPtr[i][j](x);
			x = (*FunctionPtr[i][j])(x);
		}
	}
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 나. 클래스 내부에서 함수 포인터를 사용한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	SData(*FunctionPtr[FRowSize][FColSize])(SData x);
};

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;
	int i, j;

	//x.FunctionPtr[0][0] = inputData;
	//x.FunctionPtr[0][1] = printData;
	x.FunctionPtr[0][0] = &inputData;
	x.FunctionPtr[0][1] = &printData;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = x.FunctionPtr[i][j](x);
			x = (*x.FunctionPtr[i][j])(x);
		}
	}
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 다. 클래스 멤버 함수로 inputData, printData 사용한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	SData inputData(SData);
	SData printData(SData);
};
SData SData::inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData SData::printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
int main(void) {
	SData x;
	//SData(SData::*FunctionPtr[FRowSize][FColSize])(SData x) = { &(SData::inputData), &(SData::printData) };
	SData(SData:: * FunctionPtr[FRowSize][FColSize])(SData x);
	int i, j;

	FunctionPtr[0][0] = &SData::inputData;
	FunctionPtr[0][1] = &SData::printData;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			x = (x.*FunctionPtr[i][j])(x);
		}
	}
	return 0;
}
#endif

//=========================================================================================
// 10-5. 클래스 변수(call by value) - typedef를 이용한 함수 포인터 - 1차원 배열
//=========================================================================================
// 가.메인 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;
	typedef SData(*FunctionPtr)(SData);
	//FunctionPtr p[FColSize] = { inputData, printData };
	FunctionPtr p[FColSize] = { &inputData, &printData };
	int i;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < 2; i++)
	{
		//x = p[i](x);
		x = (*p[i])(x);
	}
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 나. 클래스 내부에서 함수 포인터를 사용한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
using namespace std;
class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef SData(*FunctionPtr)(SData);
};

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;
	//Type::FunctionPtr p[FColSize] = { inputData, printData };
	Type::FunctionPtr p[FColSize] = { &inputData, &printData };
	int i;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < 2; i++)
	{
		//x = p[i](x);
		x = (*p[i])(x);
	}
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
using namespace std;
class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef SData(*FunctionPtr)(SData);
};

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;
	//SData::FunctionPtr p[FColSize] = { inputData, printData };
	SData::FunctionPtr p[FColSize] = { &inputData, &printData };
	int i;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < 2; i++)
	{
		//x = p[i](x);
		x = (*p[i])(x);
	}
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

//=========================================================================================
// 10-6. 클래스 변수(call by value) - typedef를 이용한 함수 포인터 - 1차원 포인터
//=========================================================================================
// 가.메인 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;
	typedef SData(*FunctionPtr)(SData);
	FunctionPtr* p;
	int i;

	//p = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);'
	p = new FunctionPtr[FColSize];

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < 2; i++)
	{
		x = p[i](x);
		//x = (*p[i])(x);
	}

	//free(p);
	delete[] p;
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 나. 클래스 내부에서 함수 포인터를 사용한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
using namespace std;
class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef SData(*FunctionPtr)(SData);
};

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;
	Type::FunctionPtr* p;
	int i;

	//p = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
	p = new Type::FunctionPtr[FColSize];

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < 2; i++)
	{
		//x = p[i](x);
		x = (*p[i])(x);
	}
	//free(p);
	delete[] p;
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

// 다. 클래스 멤버 함수로 inputData, printData 사용한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
using namespace std;
class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef SData(*FunctionPtr)(SData);
};

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;
	SData::FunctionPtr* p;
	int i;

	//p = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
	p = new SData::FunctionPtr[FColSize];

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < 2; i++)
	{
		//x = p[i](x);
		x = (*p[i])(x);
	}

	//free(p);
	delete[] p;

	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

//=========================================================================================
// 10-7. 클래스 변수(call by value) - typedef를 이용한 함수 포인터 - 2차원 배열
//=========================================================================================
// 가.메인 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;
	typedef SData(*FunctionPtr)(SData);
	//FunctionPtr p[FRowSize][FColSize] = { inputData, printData };
	FunctionPtr p[FRowSize][FColSize] = { &inputData, &printData };

	int i, j;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;
class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef SData(*FunctionPtr)(SData);
};

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;
	Type::FunctionPtr p[FRowSize][FColSize] = { inputData, printData };

	int i, j;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;
class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef SData(*FunctionPtr)(SData);
};

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;
	SData::FunctionPtr p[FRowSize][FColSize] = { inputData, printData };

	int i, j;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

//=========================================================================================
// 10-8. 클래스 변수(call by value) - typedef를 이용한 함수 포인터 - 포인터 배열
//=========================================================================================
// 가.메인 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;
	typedef SData(*FunctionPtr)(SData);
	FunctionPtr* p[FRowSize];


	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}

	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;
class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef SData(*FunctionPtr)(SData);
};

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;
	Type::FunctionPtr* p[FRowSize];

	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
		p[i] = new Type::FunctionPtr[FColSize];
	}

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;
class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef SData(*FunctionPtr)(SData);
};

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;
	SData::FunctionPtr* p[FRowSize];

	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
		p[i] = new SData::FunctionPtr[FColSize];
	}

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}

	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

//=========================================================================================
// 10-9. 클래스 변수(call by value) - typedef를 이용한 함수 포인터 - 배열 포인터
//=========================================================================================
// 가.메인 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;
	typedef SData(*FunctionPtr)(SData);
	FunctionPtr(*p)[FColSize];

	int i, j;

	//p = (FunctionPtr(*)[FColSize])malloc(sizeof(FunctionPtr)*FRowSize*FColSize);
	p = new FunctionPtr[FRowSize][FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}

	//free(p);
	delete[] p;
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;
class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef SData(*FunctionPtr)(SData);
};

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;
	Type::FunctionPtr(*p)[FColSize];

	int i, j;

	//p = (Type::FunctionPtr(*)[FColSize])malloc(sizeof(Type::FunctionPtr)*FRowSize*FColSize);
	p = new Type::FunctionPtr[FRowSize][FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}

	//free(p[i]);
	delete[] p;

	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;
class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef SData(*FunctionPtr)(SData);
};

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;
	SData::FunctionPtr(*p)[FColSize];

	int i, j;

	//p = (SData::FunctionPtr(*)[FColSize])malloc(sizeof(SData::FunctionPtr)*FRowSize*FColSize);
	p = new SData::FunctionPtr[FRowSize][FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}

	//free(p);
	delete[] p;

	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

//=========================================================================================
// 10-10. 클래스 변수(call by value) - typedef를 이용한 함수 포인터 - 이중 포인터
//=========================================================================================
// 가.메인 함수 내부에서 함수 포인터 선언한 경우
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;
	typedef SData(*FunctionPtr)(SData);
	FunctionPtr** p;


	int i, j;

	//p = (FunctionPtr**)malloc(sizeof(FunctionPtr*)*FRowSize);
	p = new FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;
	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;
class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef SData(*FunctionPtr)(SData);
};

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;
	Type::FunctionPtr** p;

	int i, j;

	//p = (Type::FunctionPtr**)malloc(sizeof(Type::FunctionPtr*)*FRowSize);
	p = new Type::FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
		p[i] = new Type::FunctionPtr[FColSize];
	}

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;

	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;
class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef SData(*FunctionPtr)(SData);
};

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;
	SData::FunctionPtr** p;

	int i, j;

	//p = (SData::FunctionPtr**)malloc(sizeof(SData::FunctionPtr*)*FRowSize);
	p = new SData::FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
		p[i] = new SData::FunctionPtr[FColSize];
	}

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	x.RATE = x.MIN_BALANCE = 0; // call by value인 경우 초기화해야함.

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;

	return 0;
}
SData inputData(SData x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif












//=========================================================================================
// 11. 클래스 변수(call by address) - 기본코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData* inputData(SData*);
SData* printData(SData*);
int main(void) {
	SData x;

	x = *(inputData(&x));
	x = *(printData(&x)); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

//=========================================================================================
// 11-1. 클래스 변수(call by address) - 함수 포인터로 변환한 형태
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData* inputData(SData*);
SData* printData(SData*);
int main(void) {
	SData x;
	//SData*(*FunctionPtr1)(SData*) = inputData;
	//SData*(*FunctionPtr2)(SData*) = printData;
	SData* (*FunctionPtr1)(SData*) = &inputData;
	SData* (*FunctionPtr2)(SData*) = &printData;

	//x = *(FunctionPtr1(&x));
	//x = *(FunctionPtr2(&x)); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성
	x = *((*FunctionPtr1)(&x));
	x = *((*FunctionPtr2)(&x)); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	SData* (*FunctionPtr1)(SData*);
	SData* (*FunctionPtr2)(SData*);
};

SData* inputData(SData*);
SData* printData(SData*);
int main(void) {
	SData x;

	//x.FunctionPtr1 = inputData;
	//x.FunctionPtr2 = printData;
	x.FunctionPtr1 = &inputData;
	x.FunctionPtr2 = &printData;

	//x = *(x.FunctionPtr1(&x));
	//x = *(x.FunctionPtr2(&x)); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	//x = *((*x.FunctionPtr1)(&x));
	//x = *((*x.FunctionPtr2)(&x)); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	1	//x = *(x.SData::FunctionPtr1(&x));
		//x = *(x.SData::FunctionPtr2(&x)); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

		x = *((*x.SData::FunctionPtr1)(&x));
	x = *((*x.SData::FunctionPtr2)(&x)); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성
	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	SData* inputData(SData*);
	SData* printData(SData*);
};
SData* SData::inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* SData::printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
int main(void) {
	SData x;
	SData* (SData:: * FunctionPtr1)(SData * x) = &(SData::inputData);
	SData* (SData:: * FunctionPtr2)(SData * x) = &(SData::printData);

	x = *(x.*FunctionPtr1)(&x);
	x = *(x.*FunctionPtr2)(&x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	return 0;
}
#endif

//=========================================================================================
// 11-2. 클래스 변수(call by address) - 함수 포인터 1차원 배열로 변환한 형태
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData* inputData(SData*);
SData* printData(SData*);

int main(void) {
	SData x;
	//SData* (*FunctionPtr[FColSize])(SData*) = {inputData, printData};
	SData* (*FunctionPtr[FColSize])(SData*) = { &inputData, &printData };
	int i;

	for (i = 0; i < FColSize; i++)
	{
		//x = *(FunctionPtr[i](&x));
		x = *((*FunctionPtr[i])(&x));
	}
	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

//=========================================================================================
// 11-3. 클래스 변수(call by address) - 함수 포인터 2차원 배열로 변환한 형태
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData* inputData(SData*);
SData* printData(SData*);

int main(void) {
	SData x;
	//SData* (*FunctionPtr[FColSize])(SData*) = {inputData, printData};
	SData* (*FunctionPtr[FRowSize][FColSize])(SData*) = { &inputData, &printData };
	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = *(FunctionPtr[i][j](&x));
			x = *((*FunctionPtr[i][j])(&x));
		}
	}
	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

//=========================================================================================
// 11-5. 클래스 변수(call by address) - typedef를 이용한 함수 포인터 - 1차원 배열
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData* inputData(SData*);
SData* printData(SData*);

int main(void) {
	SData x;
	typedef SData* (*FunctionPtr)(SData*);
	//FunctionPtr p[FColSize] = { inputData, printData };
	FunctionPtr p[FColSize] = { &inputData, &printData };
	int i;

	for (i = 0; i < FColSize; i++)
	{

		//x = *(p[i](&x));
		x = *((*p[i])(&x));
	}
	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef SData* (*FunctionPtr)(SData*);
};

SData* inputData(SData*);
SData* printData(SData*);

int main(void) {
	SData x;
	//Type::FunctionPtr p[FColSize] = { inputData, printData };
	Type::FunctionPtr p[FColSize] = { &inputData, &printData };
	int i;

	for (i = 0; i < FColSize; i++)
	{
		//x = *(p[i](&x));
		x = *((*p[i])(&x));
	}
	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef SData* (*FunctionPtr)(SData*);
};

SData* inputData(SData*);
SData* printData(SData*);

int main(void) {
	SData x;
	//SData::FunctionPtr p[FColSize] = { inputData, printData };
	SData::FunctionPtr p[FColSize] = { &inputData, &printData };
	int i;

	for (i = 0; i < FColSize; i++)
	{

		//x = *(p[i](&x));
		x = *((*p[i])(&x));
	}
	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

//=========================================================================================
// 11-6. 클래스 변수(call by address) - typedef를 이용한 함수 포인터 - 1차원 포인터
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData* inputData(SData*);
SData* printData(SData*);

int main(void) {
	SData x;
	typedef SData* (*FunctionPtr)(SData*);
	FunctionPtr* p;
	int i;

	//p = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
	p = new FunctionPtr[FColSize];

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	for (i = 0; i < FColSize; i++)
	{

		//x = *(p[i](&x));
		x = *((*p[i])(&x));
	}

	//free(p);
	delete[] p;
	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef SData* (*FunctionPtr)(SData*);
};

SData* inputData(SData*);
SData* printData(SData*);

int main(void) {
	SData x;
	Type::FunctionPtr* p;

	int i;

	//p = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
	p = new Type::FunctionPtr[FColSize];

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	for (i = 0; i < FColSize; i++)
	{
		//x = *(p[i](&x));
		x = *((*p[i])(&x));
	}

	//free(p);
	delete[] p;
	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef SData* (*FunctionPtr)(SData*);
};

SData* inputData(SData*);
SData* printData(SData*);

int main(void) {
	SData x;
	SData::FunctionPtr* p;
	int i;

	//p = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
	p = new SData::FunctionPtr[FColSize];

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	for (i = 0; i < FColSize; i++)
	{

		//x = *(p[i](&x));
		x = *((*p[i])(&x));
	}

	//free(p);
	delete[] p;
	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

//=========================================================================================
// 11-7. 클래스 변수(call by address) - typedef를 이용한 함수 포인터 - 2차원 배열
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData* inputData(SData*);
SData* printData(SData*);

int main(void) {
	SData x;
	typedef SData* (*FunctionPtr)(SData*);
	//FunctionPtr p[FRowSize][FColSize] = { inputData, printData };
	FunctionPtr p[FRowSize][FColSize] = { &inputData, &printData };
	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = *(p[i][j](&x));
			x = *((*p[i][j])(&x));
		}
	}
	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef SData* (*FunctionPtr)(SData*);
};

SData* inputData(SData*);
SData* printData(SData*);

int main(void) {
	SData x;
	//Type::FunctionPtr p[FRowSize][FColSize] = { inputData, printData };
	Type::FunctionPtr p[FRowSize][FColSize] = { &inputData, &printData };

	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = *(p[i][j](&x));
			x = *((*p[i][j])(&x));
		}
	}
	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef SData* (*FunctionPtr)(SData*);
};

SData* inputData(SData*);
SData* printData(SData*);

int main(void) {
	SData x;
	//SData::FunctionPtr p[FRowSize][FColSize] = { inputData, printData };
	SData::FunctionPtr p[FRowSize][FColSize] = { &inputData, &printData };

	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FRowSize; j++)
		{
			//x = *(p[i][j](&x));
			x = *((*p[i][j])(&x));
		}
	}
	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

//=========================================================================================
// 11-8. 클래스 변수(call by address) - typedef를 이용한 함수 포인터 - 포인터 배열
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData* inputData(SData*);
SData* printData(SData*);

int main(void) {
	SData x;
	typedef SData* (*FunctionPtr)(SData*);
	FunctionPtr* p[FRowSize];

	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = *(p[i][j](&x));
			x = *((*p[i][j])(&x));
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef SData* (*FunctionPtr)(SData*);
};

SData* inputData(SData*);
SData* printData(SData*);

int main(void) {
	SData x;
	Type::FunctionPtr* p[FRowSize];

	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
		p[i] = new Type::FunctionPtr[FColSize];
	}

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = *(p[i][j](&x));
			x = *((*p[i][j])(&x));
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef SData* (*FunctionPtr)(SData*);
};

SData* inputData(SData*);
SData* printData(SData*);

int main(void) {
	SData x;
	SData::FunctionPtr* p[FRowSize];

	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
		p[i] = new SData::FunctionPtr[FColSize];
	}

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FRowSize; j++)
		{
			//x = *(p[i][j](&x));
			x = *((*p[i][j])(&x));
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);;
		delete[] p[i];
	}
	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

//=========================================================================================
// 11-9. 클래스 변수(call by address) - typedef를 이용한 함수 포인터 - 배열 포인터
//=========================================================================================
// case 2. call by address 
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData* inputData(SData*);
SData* printData(SData*);

int main(void) {
	SData x;
	typedef SData* (*FunctionPtr)(SData*);
	FunctionPtr(*p)[FColSize];

	int i, j;

	//p = (FunctionPtr(*)[FColSize])malloc(sizeof(FunctionPtr)*FRowSize*FColSize);
	p = new FunctionPtr[FRowSize][FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = *(p[i][j](&x));
			x = *((*p[i][j])(&x));
		}
	}

	//free(p);
	delete[] p;
	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef SData* (*FunctionPtr)(SData*);
};

SData* inputData(SData*);
SData* printData(SData*);

int main(void) {
	SData x;
	Type::FunctionPtr(*p)[FColSize];

	int i, j;

	//p = (Type::FunctionPtr(*)[FColSize])malloc(sizeof(Type::FunctionPtr)*FRowSize*FColSize);
	p = new Type::FunctionPtr[FRowSize][FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = *(p[i][j](&x));
			x = *((*p[i][j])(&x));
		}
	}

	//free(p);
	delete[] p;

	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef SData* (*FunctionPtr)(SData*);
};

SData* inputData(SData*);
SData* printData(SData*);

int main(void) {
	SData x;
	SData::FunctionPtr(*p)[FColSize];

	int i, j;

	//p = (SData::FunctionPtr(*)[FColSize])malloc(sizeof(SData::FunctionPtr)*FRowSize*FColSize);
	p = new SData::FunctionPtr[FRowSize][FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FRowSize; j++)
		{
			//x = *(p[i][j](&x));
			x = *((*p[i][j])(&x));
		}
	}

	//free(p);
	delete[] p;

	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

//=========================================================================================
// 11-10. 클래스 변수(call by address) - typedef를 이용한 함수 포인터 - 이중 포인터
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData* inputData(SData*);
SData* printData(SData*);

int main(void) {
	SData x;
	typedef SData* (*FunctionPtr)(SData*);
	FunctionPtr** p;

	int i, j;

	//p = (FunctionPtr**)malloc(sizeof(FunctionPtr*)*FRowSize);
	p = new FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = *(p[i][j](&x));
			x = *((*p[i][j])(&x));
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;

	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef SData* (*FunctionPtr)(SData*);
};

SData* inputData(SData*);
SData* printData(SData*);

int main(void) {
	SData x;
	Type::FunctionPtr** p;

	int i, j;

	//p = (Type::FunctionPtr**)malloc(sizeof(Type::FunctionPtr*)*FRowSize);
	p = new Type::FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
		p[i] = new Type::FunctionPtr[FColSize];
	}

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = *(p[i][j](&x));
			x = *((*p[i][j])(&x));
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;

	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef SData* (*FunctionPtr)(SData*);
};

SData* inputData(SData*);
SData* printData(SData*);

int main(void) {
	SData x;
	SData::FunctionPtr** p;

	int i, j;

	//p = (SData::FunctionPtr**)malloc(sizeof(SData::FunctionPtr*)*FRowSize);
	p = new SData::FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
		p[i] = new SData::FunctionPtr[FColSize];
	}

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FRowSize; j++)
		{
			//x = *(p[i][j](&x));
			x = *((*p[i][j])(&x));
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);;
		delete[] p[i];
	}
	//free(p);;
	delete[] p;

	return 0;
}
SData* inputData(SData* x)
{
	scanf("%lf", &(x->RATE));
	scanf("%d", &(x->MIN_BALANCE));
	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->RATE);
	printf("계좌최소잔고: %d\n", x->MIN_BALANCE);
	return x;
}
#endif











//=========================================================================================
// 12. 클래스 변수(calㅣ by reference) - 기본코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;

	x = inputData(x);
	x = printData(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

//=========================================================================================
// 12-1. 클래스 변수(calㅣ by reference) - 함수 포인터로 변환한 형태
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;
	//SData&(*FunctionPtr1)(SData&) = inputData;
	//SData&(*FunctionPtr2)(SData&) = printData;
	SData& (*FunctionPtr1)(SData&) = &inputData;
	SData& (*FunctionPtr2)(SData&) = &printData;

	//x = FunctionPtr1(x);
	//x = FunctionPtr2(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	x = (*FunctionPtr1)(x);
	x = (*FunctionPtr2)(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	SData& (*FunctionPtr1)(SData&);
	SData& (*FunctionPtr2)(SData&);
};

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;

	//x.FunctionPtr1 = inputData;
	//x.FunctionPtr2 = printData;
	x.FunctionPtr1 = &inputData;
	x.FunctionPtr2 = &printData;

	//x = x.FunctionPtr1(x);
	//x = x.FunctionPtr2(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	//x = (*x.FunctionPtr1)(x);
	//x = (*x.FunctionPtr2)(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	//x = x.SData::FunctionPtr1(x);
	//x = x.SData::FunctionPtr2(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	x = (*x.SData::FunctionPtr1)(x);
	x = (*x.SData::FunctionPtr2)(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	SData& inputData(SData&);
	SData& printData(SData&);
};

SData& SData::inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& SData::printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}

int main(void) {
	SData x;
	SData& (SData:: * FunctionPtr1)(SData&) = &(SData::inputData);
	SData& (SData:: * FunctionPtr2)(SData&) = &(SData::printData);

	x = (x.*FunctionPtr1)(x);
	x = (x.*FunctionPtr2)(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	return 0;
}
#endif

//=========================================================================================
// 12-2. 클래스 변수(calㅣ by reference) - 함수 포인터 1차원 배열로 변환한 형태
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;
	//SData& (*FunctionPtr[FColSize])(SData&) = {inputData, printData};
	SData& (*FunctionPtr[FColSize])(SData&) = { &inputData, &printData };
	int i;

	for (i = 0; i < FColSize; i++)
	{
		//x = FunctionPtr[i](x);
		x = (*FunctionPtr[i])(x);
	}
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

//=========================================================================================
// 12-3. 클래스 변수(calㅣ by reference) - 함수 포인터 2차원 배열로 변환한 형태
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;
	//SData& (*FunctionPtr[FRowSize][FColSize])(SData&) = {inputData, printData};
	SData& (*FunctionPtr[FRowSize][FColSize])(SData&) = { &inputData, &printData };
	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = FunctionPtr[i][j](x);
			x = (*FunctionPtr[i][j])(x);
		}
	}
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

//=========================================================================================
// 12-5. 클래스 변수 - typedef를 이용한 함수 포인터 - 1차원 배열
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;
	typedef SData& (*FunctionPtr)(SData&);
	//FunctionPtr p[FColSize] = { inputData, printData };
	FunctionPtr p[FColSize] = { &inputData, &printData };
	int i;

	for (i = 0; i < FColSize; i++)
	{
		//x = p[i](x);
		x = (*p[i])(x);
	}
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef SData& (*FunctionPtr)(SData&);
};

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;
	//Type::FunctionPtr p[FColSize] = { inputData, printData };
	Type::FunctionPtr p[FColSize] = { &inputData, &printData };
	int i;

	for (i = 0; i < FColSize; i++)
	{
		//x = p[i](x);
		x = (*p[i])(x);
	}
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef SData& (*FunctionPtr)(SData&);
};

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;
	//SData::FunctionPtr p[FColSize] = { inputData, printData };
	SData::FunctionPtr p[FColSize] = { &inputData, &printData };
	int i;

	for (i = 0; i < FColSize; i++)
	{
		//x = p[i](x);
		x = (*p[i])(x);
	}
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

//=========================================================================================
// 12-6. 클래스 변수(calㅣ by reference) - typedef를 이용한 함수 포인터 - 1차원 포인터
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;
	typedef SData& (*FunctionPtr)(SData&);
	FunctionPtr* p;
	int i;

	//p = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
	p = new FunctionPtr[FColSize];

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	for (i = 0; i < FColSize; i++)
	{
		//x = p[i](x);
		x = (*p[i])(x);
	}

	//free(p);
	delete[] p;
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef SData& (*FunctionPtr)(SData&);
};

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;
	Type::FunctionPtr* p;
	int i;

	//p = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
	p = new Type::FunctionPtr[FColSize];
	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	for (i = 0; i < FColSize; i++)
	{
		//x = p[i](x);
		x = (*p[i])(x);
	}
	//free(p);
	delete[] p;
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef SData& (*FunctionPtr)(SData&);
};

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;
	SData::FunctionPtr* p;
	int i;

	//p = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
	p = new SData::FunctionPtr[FColSize];
	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	for (i = 0; i < FColSize; i++)
	{
		//x = p[i](x);
		x = (*p[i])(x);
	}

	//free(p);
	delete[] p;

	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

//=========================================================================================
// 12-7. 클래스 변수(calㅣ by reference) - typedef를 이용한 함수 포인터 - 2차원 배열
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;
	typedef SData& (*FunctionPtr)(SData&);
	//FunctionPtr p[FRowSize][FColSize] = { inputData, printData };
	FunctionPtr p[FRowSize][FColSize] = { &inputData, &printData };
	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef SData& (*FunctionPtr)(SData&);
};

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;
	//Type::FunctionPtr p[FRowSize][FColSize] = { inputData, printData };
	Type::FunctionPtr p[FRowSize][FColSize] = { &inputData, &printData };

	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef SData& (*FunctionPtr)(SData&);
};

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;
	//SData::FunctionPtr p[FRowSize][FColSize] = { inputData, printData };
	SData::FunctionPtr p[FRowSize][FColSize] = { &inputData, &printData };

	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

//=========================================================================================
// 12-8. 클래스 변수(calㅣ by reference) - typedef를 이용한 함수 포인터 - 포인터 배열
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;
	typedef SData& (*FunctionPtr)(SData&);
	FunctionPtr* p[FRowSize];

	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}

	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef SData& (*FunctionPtr)(SData&);
};

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;
	Type::FunctionPtr* p[FRowSize];
	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
		p[i] = new Type::FunctionPtr[FColSize];
	}

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;


	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef SData& (*FunctionPtr)(SData&);
};

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;
	SData::FunctionPtr* p[FRowSize];

	int i, j;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
		p[i] = new SData::FunctionPtr[FColSize];
	}

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}

	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

//=========================================================================================
// 12-9. 클래스 변수(calㅣ by reference) - typedef를 이용한 함수 포인터 - 배열 포인터
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;
	typedef SData& (*FunctionPtr)(SData&);
	FunctionPtr(*p)[FColSize];

	int i, j;

	//p = (FunctionPtr(*)[FColSize])malloc(sizeof(FunctionPtr)*FRowSize*FColSize);
	p = new FunctionPtr[FRowSize][FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}

	//free(p);
	delete[] p;

	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef SData& (*FunctionPtr)(SData&);
};

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;
	Type::FunctionPtr(*p)[FColSize];
	int i, j;

	//p = (Type::FunctionPtr(*)[FColSize])malloc(sizeof(Type::FunctionPtr)*FRowSize*FColSize);
	p = new Type::FunctionPtr[FRowSize][FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;


	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}

	//free(p);
	delete[] p;

	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef SData& (*FunctionPtr)(SData&);
};

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;
	SData::FunctionPtr(*p)[FColSize];

	int i, j;

	//p = (SData::FunctionPtr(*)[FColSize])malloc(sizeof(SData::FunctionPtr)*FRowSize*FColSize);
	p = new SData::FunctionPtr[FRowSize][FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}

	//free(p);
	delete[] p;

	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

//=========================================================================================
// 12-10. 클래스 변수(calㅣ by reference) - typedef를 이용한 함수 포인터 - 이중 포인터
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;
	typedef SData& (*FunctionPtr)(SData&);
	FunctionPtr** p;

	int i, j;

	//p = (FunctionPtr**)malloc(sizeof(FunctionPtr*)*FRowSize);
	p = new FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;

	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef SData& (*FunctionPtr)(SData&);
};

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;
	Type::FunctionPtr** p;
	int i, j;

	//p = (Type::FunctionPtr**)malloc(sizeof(Type::FunctionPtr*)*FRowSize);
	p = new Type::FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
		p[i] = new Type::FunctionPtr[FColSize];
	}

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;


	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;

	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef SData& (*FunctionPtr)(SData&);
};

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;
	SData::FunctionPtr** p;

	int i, j;

	//p = (SData::FunctionPtr**)malloc(sizeof(SData::FunctionPtr*)*FRowSize);
	p = new SData::FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
		p[i] = new SData::FunctionPtr[FColSize];
	}

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//x = p[i][j](x);
			x = (*p[i][j])(x);
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;
	return 0;
}
SData& inputData(SData& x)
{
	scanf("%lf", &(x.RATE));
	scanf("%d", &(x.MIN_BALANCE));
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.RATE);
	printf("계좌최소잔고: %d\n", x.MIN_BALANCE);
	return x;
}
#endif




//=========================================================================================
// 13. 클래스 1차원 배열 - 기본코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

void inputData(SData[ColSize], int, int);
void printData(SData[ColSize], int, int);
int main(void) {
	SData x[ColSize];
	int i, CSize;

	i = 0;
	CSize = ColSize;

	inputData(x, i, CSize);
	printData(x, i, CSize); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

//=========================================================================================
// 13-1. 클래스 1차원 배열 - 함수 포인터로 변환한 형태
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

void inputData(SData[ColSize], int, int);
void printData(SData[ColSize], int, int);
int main(void) {
	SData x[ColSize];
	//void(*FunctionPtr1)(SData[ColSize], int, int) = { inputData };
	//void(*FunctionPtr2)(SData[ColSize], int, int) = { printData };
	void(*FunctionPtr1)(SData[ColSize], int, int) = { &inputData };
	void(*FunctionPtr2)(SData[ColSize], int, int) = { &printData };
	int i, CSize;

	i = 0;
	CSize = ColSize;


	//FunctionPtr1(x, i, CSize);
	//FunctionPtr2(x, i, CSize);

	(*FunctionPtr1)(x, i, CSize);
	(*FunctionPtr2)(x, i, CSize);

	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

//=========================================================================================
// 13-2. 클래스 1차원 배열 - 함수 포인터 1차원 배열로 변환한 형태
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

void inputData(SData[ColSize], int, int);
void printData(SData[ColSize], int, int);
int main(void) {
	SData x[ColSize];
	//void(*FunctionPtr[FColSize])(SData[ColSize], int, int) = { inputData, printData };
	void(*FunctionPtr[FColSize])(SData[ColSize], int, int) = { &inputData, &printData };
	int i, CSize;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//FunctionPtr[i](x, i, CSize);
		(*FunctionPtr[i])(x, i, CSize);
	}

	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

//=========================================================================================
// 13-3. 클래스 1차원 배열 - 함수 포인터 2차원 배열로 변환한 형태
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

void inputData(SData[ColSize], int, int);
void printData(SData[ColSize], int, int);
int main(void) {
	SData x[ColSize];
	//void(*FunctionPtr[FColSize])(SData[ColSize], int, int) = { inputData, printData };
	void(*FunctionPtr[FColSize])(SData[ColSize], int, int) = { &inputData, &printData };
	int i, CSize;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//FunctionPtr[i](x, i, CSize);
		(*FunctionPtr[i])(x, i, CSize);
	}

	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

//=========================================================================================
// 13-5. 클래스 1차원 배열 - typedef를 이용한 함수 포인터 - 1차원 배열
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

void inputData(SData[ColSize], int, int);
void printData(SData[ColSize], int, int);
int main(void) {
	SData x[ColSize];
	typedef void(*FunctionPtr)(SData[ColSize], int, int);
	//FunctionPtr p[FColSize] = { inputData, printData };
	FunctionPtr p[FColSize] = { &inputData, &printData };
	int i, CSize;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](x, i, CSize);
		(*p[i])(x, i, CSize);
	}

	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef void(*FunctionPtr)(SData[ColSize], int, int);
};

void inputData(SData[ColSize], int, int);
void printData(SData[ColSize], int, int);
int main(void) {
	SData x[ColSize];
	//Type::FunctionPtr p[FColSize] = { inputData, printData };
	Type::FunctionPtr p[FColSize] = { &inputData, &printData };
	int i, CSize;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](x, i, CSize);
		(*p[i])(x, i, CSize);
	}

	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef void(*FunctionPtr)(SData[ColSize], int, int);
};

void inputData(SData[ColSize], int, int);
void printData(SData[ColSize], int, int);
int main(void) {
	SData x[ColSize];
	//SData::FunctionPtr p[FColSize] = { inputData, printData };
	SData::FunctionPtr p[FColSize] = { &inputData, &printData };
	int i, CSize;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](x, i, CSize);
		(*p[i])(x, i, CSize);
	}

	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

//=========================================================================================
// 13-6. 클래스 1차원 배열 - typedef를 이용한 함수 포인터 - 1차원 포인터
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

void inputData(SData[ColSize], int, int);
void printData(SData[ColSize], int, int);
int main(void) {
	SData x[ColSize];
	typedef void(*FunctionPtr)(SData[ColSize], int, int);
	FunctionPtr* p;
	int i, CSize;

	//p = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
	p = new FunctionPtr[FColSize];

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](x, i, CSize);
		(*p[i])(x, i, CSize);
	}

	//free(p);
	delete[] p;
	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef void(*FunctionPtr)(SData[ColSize], int, int);
};

void inputData(SData[ColSize], int, int);
void printData(SData[ColSize], int, int);
int main(void) {
	SData x[ColSize];
	Type::FunctionPtr* p;
	int i, CSize;

	//p = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
	p = new Type::FunctionPtr[ColSize];

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](x, i, CSize);
		(*p[i])(x, i, CSize);
	}

	//free(p);
	delete[] p;
	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef void(*FunctionPtr)(SData[ColSize], int, int);
};

void inputData(SData[ColSize], int, int);
void printData(SData[ColSize], int, int);
int main(void) {
	SData x[ColSize];
	SData::FunctionPtr* p;
	int i, CSize;

	//p = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
	p = new SData::FunctionPtr[FColSize];

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](x, i, CSize);
		(*p[i])(x, i, CSize);
	}

	//free(p);
	delete[] p;
	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

//=========================================================================================
// 13-7. 클래스 1차원 배열 - typedef를 이용한 함수 포인터 - 2차원 배열
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

void inputData(SData[ColSize], int, int);
void printData(SData[ColSize], int, int);
int main(void) {
	SData x[ColSize];
	typedef void(*FunctionPtr)(SData[ColSize], int, int);
	//FunctionPtr p[FRowSize][FColSize] = { inputData, printData };
	FunctionPtr p[FRowSize][FColSize] = { &inputData, &printData };
	int i, j, CSize;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, CSize);
			(*p[i][j])(x, i, CSize);
		}
	}

	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef void(*FunctionPtr)(SData[ColSize], int, int);
};

void inputData(SData[ColSize], int, int);
void printData(SData[ColSize], int, int);
int main(void) {
	SData x[ColSize];
	//Type::FunctionPtr p[FRowSize][FColSize] = { inputData, printData };
	Type::FunctionPtr p[FRowSize][FColSize] = { &inputData, &printData };

	int i, j, CSize;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, CSize);
			(*p[i][j])(x, i, CSize);
		}
	}

	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef void(*FunctionPtr)(SData[ColSize], int, int);
};

void inputData(SData[ColSize], int, int);
void printData(SData[ColSize], int, int);
int main(void) {
	SData x[ColSize];
	//SData::FunctionPtr p[FRowSize][FColSize] = { inputData, printData };
	SData::FunctionPtr p[FRowSize][FColSize] = { &inputData, &printData };
	int i, j, CSize;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, CSize);
			(*p[i][j])(x, i, CSize);
		}
	}

	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

//=========================================================================================
// 13-8. 클래스 1차원 배열 - typedef를 이용한 함수 포인터 - 포인터 배열
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

void inputData(SData[ColSize], int, int);
void printData(SData[ColSize], int, int);
int main(void) {
	SData x[ColSize];
	typedef void(*FunctionPtr)(SData[ColSize], int, int);
	FunctionPtr* p[FRowSize];
	int i, j, CSize;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, CSize);
			(*p[i][j])(x, i, CSize);
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef void(*FunctionPtr)(SData[ColSize], int, int);
};

void inputData(SData[ColSize], int, int);
void printData(SData[ColSize], int, int);
int main(void) {
	SData x[ColSize];
	Type::FunctionPtr* p[FRowSize];

	int i, j, CSize;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
		p[i] = new Type::FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, CSize);
			(*p[i][j])(x, i, CSize);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}

	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef void(*FunctionPtr)(SData[ColSize], int, int);
};

void inputData(SData[ColSize], int, int);
void printData(SData[ColSize], int, int);
int main(void) {
	SData x[ColSize];
	SData::FunctionPtr* p[FRowSize];
	int i, j, CSize;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
		p[i] = new SData::FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, CSize);
			(*p[i][j])(x, i, CSize);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

//=========================================================================================
// 13-9. 클래스 1차원 배열 - typedef를 이용한 함수 포인터 - 배열 포인터
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

void inputData(SData[ColSize], int, int);
void printData(SData[ColSize], int, int);
int main(void) {
	SData x[ColSize];
	typedef void(*FunctionPtr)(SData[ColSize], int, int);
	FunctionPtr(*p)[FColSize];
	int i, j, CSize;

	//p = (FunctionPtr(*)[FColSize])malloc(sizeof(FunctionPtr)*FRowSize*FColSize);
	p = new FunctionPtr[FRowSize][FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, CSize);
			(*p[i][j])(x, i, CSize);
		}
	}

	//free(p);
	delete[] p;
	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef void(*FunctionPtr)(SData[ColSize], int, int);
};

void inputData(SData[ColSize], int, int);
void printData(SData[ColSize], int, int);
int main(void) {
	SData x[ColSize];
	Type::FunctionPtr(*p)[FColSize];

	int i, j, CSize;

	//p = (Type::FunctionPtr(*)[FColSize])malloc(sizeof(Type::FunctionPtr)*FRowSize*FColSize);
	p = new Type::FunctionPtr[FRowSize][FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, CSize);
			(*p[i][j])(x, i, CSize);
		}
	}

	//free(p);
	delete[] p;
	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef void(*FunctionPtr)(SData[ColSize], int, int);
};

void inputData(SData[ColSize], int, int);
void printData(SData[ColSize], int, int);
int main(void) {
	SData x[ColSize];
	SData::FunctionPtr(*p)[FColSize];
	int i, j, CSize;

	//p = (SData::FunctionPtr(*)[FColSize])malloc(sizeof(SData::FunctionPtr)*FRowSize*FColSize);
	p = new SData::FunctionPtr[FRowSize][FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, CSize);
			(*p[i][j])(x, i, CSize);
		}
	}

	//free(p);
	delete[] p;

	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

//=========================================================================================
// 13-10. 클래스 1차원 배열 - typedef를 이용한 함수 포인터 - 이중 포인터
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

void inputData(SData[ColSize], int, int);
void printData(SData[ColSize], int, int);
int main(void) {
	SData x[ColSize];
	typedef void(*FunctionPtr)(SData[ColSize], int, int);
	FunctionPtr** p;
	int i, j, CSize;

	//p = (FunctionPtr**)malloc(sizeof(FunctionPtr*)*FRowSize);
	p = new FunctionPtr * [FColSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, CSize);
			(*p[i][j])(x, i, CSize);
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;

	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef void(*FunctionPtr)(SData[ColSize], int, int);
};

void inputData(SData[ColSize], int, int);
void printData(SData[ColSize], int, int);
int main(void) {
	SData x[ColSize];
	Type::FunctionPtr** p;
	int i, j, CSize;

	//p = (Type::FunctionPtr**)malloc(sizeof(Type::FunctionPtr*)*FRowSize);
	p = new Type::FunctionPtr * [FColSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
		p[i] = new Type::FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, CSize);
			(*p[i][j])(x, i, CSize);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;

	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef void(*FunctionPtr)(SData[ColSize], int, int);
};

void inputData(SData[ColSize], int, int);
void printData(SData[ColSize], int, int);
int main(void) {
	SData x[ColSize];
	SData::FunctionPtr** p;
	int i, j, CSize;

	//p = (SData::FunctionPtr**)malloc(sizeof(SData::FunctionPtr*)*FRowSize);
	p = new SData::FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
		p[i] = new SData::FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = 0;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, CSize);
			(*p[i][j])(x, i, CSize);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;

	return 0;
}
void inputData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		scanf("%lf", &(x[i].RATE));
		scanf("%d", &(x[i].MIN_BALANCE));
	}
}
void printData(SData x[ColSize], int i, int CSize)
{
	for (i = 0; i < CSize; i++)
	{
		printf("이자율: %lf\n", x[i].RATE);
		printf("계좌최소잔고: %d\n", x[i].MIN_BALANCE);
	}
}
#endif










//=========================================================================================
// 14. 클래스 2차원 배열 - 기본코드
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define RowSize 1
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

void inputData(SData[RowSize][ColSize], int, int, int, int);
void printData(SData[RowSize][ColSize], int, int, int, int);
int main(void) {
	SData x[RowSize][ColSize];
	int i, j, RSize, CSize;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	inputData(x, i, j, RSize, CSize);
	printData(x, i, j, RSize, CSize); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

//=========================================================================================
// 14-1. 클래스 2차원 배열 - 함수 포인터로 변환한 형태
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define RowSize 1
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

void inputData(SData[RowSize][ColSize], int, int, int, int);
void printData(SData[RowSize][ColSize], int, int, int, int);
int main(void) {
	SData x[RowSize][ColSize];
	//void(*FunctionPtr1)(SData[RowSize][ColSize], int, int, int, int) = { inputData };
	//void(*FunctionPtr2)(SData[RowSize][ColSize], int, int, int, int) = { printData };
	void(*FunctionPtr1)(SData[RowSize][ColSize], int, int, int, int) = { &inputData };
	void(*FunctionPtr2)(SData[RowSize][ColSize], int, int, int, int) = { &printData };
	int i, j, RSize, CSize;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	//FunctionPtr1(x, i, j, RSize, CSize);
	//FunctionPtr2(x, i, j, RSize, CSize);
	(*FunctionPtr1)(x, i, j, RSize, CSize);
	(*FunctionPtr2)(x, i, j, RSize, CSize);


	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

//=========================================================================================
// 14-2. 클래스 2차원 배열 - 함수 포인터 1차원 배열로 변환한 형태
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
#define RowSize 1
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

void inputData(SData[RowSize][ColSize], int, int, int, int);
void printData(SData[RowSize][ColSize], int, int, int, int);
int main(void) {
	SData x[RowSize][ColSize];
	//void(*FunctionPtr[FColSize])(SData[RowSize][ColSize], int, int, int, int) = {inputData, printData};
	void(*FunctionPtr[FColSize])(SData[RowSize][ColSize], int, int, int, int) = { &inputData, &printData };
	int i, j, RSize, CSize;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//FunctionPtr[i](x, i, j, RSize, CSize);
		(*FunctionPtr[i])(x, i, j, RSize, CSize);
	}

	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

//=========================================================================================
// 14-3. 클래스 2차원 배열 - 함수 포인터 2차원 배열로 변환한 형태
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

void inputData(SData[RowSize][ColSize], int, int, int, int);
void printData(SData[RowSize][ColSize], int, int, int, int);
int main(void) {
	SData x[RowSize][ColSize];
	//void(*FunctionPtr[FRowSize][FColSize])(SData[RowSize][ColSize], int, int, int, int) = {inputData, printData};
	void(*FunctionPtr[FRowSize][FColSize])(SData[RowSize][ColSize], int, int, int, int) = { &inputData, &printData };
	int i, j, RSize, CSize;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//FunctionPtr[i][j](x, i, j, RSize, CSize);
			(*FunctionPtr[i][j])(x, i, j, RSize, CSize);
		}
	}

	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

//=========================================================================================
// 14-5. 클래스 2차원 배열 - typedef를 이용한 함수 포인터 - 1차원 배열
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
#define RowSize 1
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

void inputData(SData[RowSize][ColSize], int, int, int, int);
void printData(SData[RowSize][ColSize], int, int, int, int);
int main(void) {
	SData x[RowSize][ColSize];
	typedef void(*FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
	//FunctionPtr p[FColSize] = { inputData, printData };
	FunctionPtr p[FColSize] = { &inputData, &printData };
	int i, j, RSize, CSize;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](x, i, j, RSize, CSize);
		(*p[i])(x, i, j, RSize, CSize);
	}

	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
#define RowSize 1
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef void(*FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
};

void inputData(SData[RowSize][ColSize], int, int, int, int);
void printData(SData[RowSize][ColSize], int, int, int, int);
int main(void) {
	SData x[RowSize][ColSize];
	//Type::FunctionPtr p[FColSize] = { inputData, printData };
	Type::FunctionPtr p[FColSize] = { &inputData, &printData };
	int i, j, RSize, CSize;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](x, i, j, RSize, CSize);
		(*p[i])(x, i, j, RSize, CSize);
	}

	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
#define RowSize 1
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef void(*FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
};
void inputData(SData[RowSize][ColSize], int, int, int, int);
void printData(SData[RowSize][ColSize], int, int, int, int);
int main(void) {
	SData x[RowSize][ColSize];
	//SData::FunctionPtr p[FColSize] = { inputData, printData };
	SData::FunctionPtr p[FColSize] = { &inputData, &printData };
	int i, j, RSize, CSize;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](x, i, j, RSize, CSize);
		(*p[i])(x, i, j, RSize, CSize);
	}

	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

//=========================================================================================
// 14-6. 클래스 2차원 배열 - typedef를 이용한 함수 포인터 - 1차원 포인터
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
#define RowSize 1
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

void inputData(SData[RowSize][ColSize], int, int, int, int);
void printData(SData[RowSize][ColSize], int, int, int, int);
int main(void) {
	SData x[RowSize][ColSize];
	typedef void(*FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
	FunctionPtr* p;
	int i, j, RSize, CSize;

	//p = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
	p = new FunctionPtr[FColSize];

	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](x, i, j, RSize, CSize);
		(*p[i])(x, i, j, RSize, CSize);
	}

	//free(p);
	delete[] p;
	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
#define RowSize 1
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef void(*FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
};

void inputData(SData[RowSize][ColSize], int, int, int, int);
void printData(SData[RowSize][ColSize], int, int, int, int);
int main(void) {
	SData x[RowSize][ColSize];
	Type::FunctionPtr* p;
	int i, j, RSize, CSize;

	//p = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
	p = new Type::FunctionPtr[FColSize];
	//p[0] = inputData;
	//p[1] = printData;
	p[0] = &inputData;
	p[1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](x, i, j, RSize, CSize);
		(*p[i])(x, i, j, RSize, CSize);
	}

	//free(p);
	delete[] p;

	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
#define RowSize 1
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef void(*FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
};
void inputData(SData[RowSize][ColSize], int, int, int, int);
void printData(SData[RowSize][ColSize], int, int, int, int);
int main(void) {
	SData x[RowSize][ColSize];
	SData::FunctionPtr* p;
	int i, j, RSize, CSize;

	//p = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
	p = new SData::FunctionPtr[FColSize];

	p[0] = inputData;
	p[1] = printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FColSize; i++)
	{
		//p[i](x, i, j, RSize, CSize);
		(*p[i])(x, i, j, RSize, CSize);
	}

	//free(p);
	delete[]  p;

	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

//=========================================================================================
// 14-7. 클래스 2차원 배열 - typedef를 이용한 함수 포인터 - 2차원 배열
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

void inputData(SData[RowSize][ColSize], int, int, int, int);
void printData(SData[RowSize][ColSize], int, int, int, int);
int main(void) {
	SData x[RowSize][ColSize];
	typedef void(*FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
	//FunctionPtr p[FRowSize][FColSize] = { inputData, printData };
	FunctionPtr p[FRowSize][FColSize] = { &inputData, &printData };
	int i, j, RSize, CSize;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, j, RSize, CSize);
			(*p[i][j])(x, i, j, RSize, CSize);
		}
	}

	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef void(*FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
};

void inputData(SData[RowSize][ColSize], int, int, int, int);
void printData(SData[RowSize][ColSize], int, int, int, int);
int main(void) {
	SData x[RowSize][ColSize];
	//Type::FunctionPtr p[FRowSize][FColSize] = { inputData, printData };
	Type::FunctionPtr p[FRowSize][FColSize] = { &inputData, &printData };

	int i, j, RSize, CSize;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, j, RSize, CSize);
			(*p[i][j])(x, i, j, RSize, CSize);
		}
	}

	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef void(*FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
};
void inputData(SData[RowSize][ColSize], int, int, int, int);
void printData(SData[RowSize][ColSize], int, int, int, int);
int main(void) {
	SData x[RowSize][ColSize];
	//SData::FunctionPtr p[FRowSize][FColSize] = { inputData, printData };
	SData::FunctionPtr p[FRowSize][FColSize] = { &inputData, &printData };

	int i, j, RSize, CSize;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, j, RSize, CSize);
			(*p[i][j])(x, i, j, RSize, CSize);
		}
	}

	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif


//=========================================================================================
// 14-8. 클래스 2차원 배열 - typedef를 이용한 함수 포인터 - 포인터 배열
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

void inputData(SData[RowSize][ColSize], int, int, int, int);
void printData(SData[RowSize][ColSize], int, int, int, int);
int main(void) {
	SData x[RowSize][ColSize];
	typedef void(*FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
	FunctionPtr* p[FRowSize];
	int i, j, RSize, CSize;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, j, RSize, CSize);
			(*p[i][j])(x, i, j, RSize, CSize);
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}

	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef void(*FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
};

void inputData(SData[RowSize][ColSize], int, int, int, int);
void printData(SData[RowSize][ColSize], int, int, int, int);
int main(void) {
	SData x[RowSize][ColSize];
	Type::FunctionPtr* p[FRowSize];
	int i, j, RSize, CSize;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
		p[i] = new Type::FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, j, RSize, CSize);
			(*p[i][j])(x, i, j, RSize, CSize);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef void(*FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
};
void inputData(SData[RowSize][ColSize], int, int, int, int);
void printData(SData[RowSize][ColSize], int, int, int, int);
int main(void) {
	SData x[RowSize][ColSize];
	SData::FunctionPtr* p[FRowSize];
	int i, j, RSize, CSize;

	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
		p[i] = new SData::FunctionPtr[FColSize];
	}

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, j, RSize, CSize);
			(*p[i][j])(x, i, j, RSize, CSize);
		}
	}


	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}

	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

//=========================================================================================
// 14-9. 클래스 2차원 배열 - typedef를 이용한 함수 포인터 - 배열 포인터
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

void inputData(SData[RowSize][ColSize], int, int, int, int);
void printData(SData[RowSize][ColSize], int, int, int, int);
int main(void) {
	SData x[RowSize][ColSize];
	typedef void(*FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
	FunctionPtr(*p)[FColSize];
	int i, j, RSize, CSize;

	//p = (FunctionPtr(*)[FColSize])malloc(sizeof(FunctionPtr)*FRowSize*FColSize);
	p = new FunctionPtr[FRowSize][FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, j, RSize, CSize);
			(*p[i][j])(x, i, j, RSize, CSize);
		}
	}

	//free(p);
	delete[] p;


	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef void(*FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
};

void inputData(SData[RowSize][ColSize], int, int, int, int);
void printData(SData[RowSize][ColSize], int, int, int, int);
int main(void) {
	SData x[RowSize][ColSize];
	Type::FunctionPtr(*p)[FColSize];
	int i, j, RSize, CSize;

	//p = (Type::FunctionPtr(*)[FColSize])malloc(sizeof(Type::FunctionPtr)*FRowSize*FColSize);
	p = new Type::FunctionPtr[FRowSize][FColSize];

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, j, RSize, CSize);
			(*p[i][j])(x, i, j, RSize, CSize);
		}
	}

	//free(p);
	delete[] p;

	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef void(*FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
};
void inputData(SData[RowSize][ColSize], int, int, int, int);
void printData(SData[RowSize][ColSize], int, int, int, int);
int main(void) {
	SData x[RowSize][ColSize];
	SData::FunctionPtr(*p)[FColSize];
	int i, j, RSize, CSize;

	//p = (SData::FunctionPtr(*)[FColSize])malloc(sizeof(SData::FunctionPtr)*FRowSize*FColSize);
	p = new SData::FunctionPtr[FRowSize][FColSize];


	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, j, RSize, CSize);
			(*p[i][j])(x, i, j, RSize, CSize);
		}
	}

	//free(p);
	delete[] p;

	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

//=========================================================================================
// 14-10. 클래스 2차원 배열 - typedef를 이용한 함수 포인터 - 이중 포인터
//=========================================================================================
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

void inputData(SData[RowSize][ColSize], int, int, int, int);
void printData(SData[RowSize][ColSize], int, int, int, int);
int main(void) {
	SData x[RowSize][ColSize];
	typedef void(*FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
	FunctionPtr** p;
	int i, j, RSize, CSize;

	//p = (FunctionPtr**)malloc(sizeof(FunctionPtr*)*FRowSize);
	p = new FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (FunctionPtr*)malloc(sizeof(FunctionPtr)*FColSize);
		p[i] = new FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, j, RSize, CSize);
			(*p[i][j])(x, i, j, RSize, CSize);
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;

	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

class Type
{
public:
	typedef void(*FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
};

void inputData(SData[RowSize][ColSize], int, int, int, int);
void printData(SData[RowSize][ColSize], int, int, int, int);
int main(void) {
	SData x[RowSize][ColSize];
	Type::FunctionPtr** p;
	int i, j, RSize, CSize;

	//p = (Type::FunctionPtr**)malloc(sizeof(Type::FunctionPtr*)*FRowSize);
	p = new Type::FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (Type::FunctionPtr*)malloc(sizeof(Type::FunctionPtr)*FColSize);
		p[i] = new Type::FunctionPtr[FColSize];
	}
	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, j, RSize, CSize);
			(*p[i][j])(x, i, j, RSize, CSize);
		}
	}
	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;
	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FRowSize 1
#define FColSize 2
#define RowSize 1
#define ColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
protected:
public:
	double RATE;
	int MIN_BALANCE;
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
	typedef void(*FunctionPtr)(SData[RowSize][ColSize], int, int, int, int);
};
void inputData(SData[RowSize][ColSize], int, int, int, int);
void printData(SData[RowSize][ColSize], int, int, int, int);
int main(void) {
	SData x[RowSize][ColSize];
	SData::FunctionPtr** p;
	int i, j, RSize, CSize;

	//p = (SData::FunctionPtr**)malloc(sizeof(SData::FunctionPtr*)*FRowSize);
	p = new SData::FunctionPtr * [FRowSize];
	for (i = 0; i < FRowSize; i++)
	{
		//p[i] = (SData::FunctionPtr*)malloc(sizeof(SData::FunctionPtr)*FColSize);
		p[i] = new SData::FunctionPtr[FColSize];
	}

	//p[0][0] = inputData;
	//p[0][1] = printData;
	p[0][0] = &inputData;
	p[0][1] = &printData;

	i = j = 0;
	RSize = RowSize;
	CSize = ColSize;

	for (i = 0; i < FRowSize; i++)
	{
		for (j = 0; j < FColSize; j++)
		{
			//p[i][j](x, i, j, RSize, CSize);
			(*p[i][j])(x, i, j, RSize, CSize);
		}
	}

	for (i = 0; i < FRowSize; i++)
	{
		//free(p[i]);
		delete[] p[i];
	}
	//free(p);
	delete[] p;
	return 0;
}
void inputData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			scanf("%lf", &(x[i][j].RATE));
			scanf("%d", &(x[i][j].MIN_BALANCE));
		}
	}
}
void printData(SData x[RowSize][ColSize], int i, int j, int RSize, int CSize)
{
	for (i = 0; i < RSize; i++)
	{
		for (j = 0; j < CSize; j++)
		{
			printf("이자율: %lf\n", x[i][j].RATE);
			printf("계좌최소잔고: %d\n", x[i][j].MIN_BALANCE);
		}
	}
}
#endif










//=========================================================================================
// 15. 클래스 변수 - 기본코드 // private로 선언한 경우
//=========================================================================================
// case 1. call by value
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class SData {
	// 멤버 속성
private:
	double RATE;
	int MIN_BALANCE;
protected:
public:

	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData inputData(SData);
SData printData(SData);
int main(void) {
	SData x;

	x.setRATE(0);
	x.setMIN_BALANCE(0); // call by value인 경우 초기화해야함.

	x = inputData(x);
	x = printData(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	return 0;
}
SData inputData(SData x)
{
	int min_balance;
	double rate;

	scanf("%lf", &(rate));
	scanf("%d", &(min_balance));

	x.setRATE(rate);
	x.setMIN_BALANCE(min_balance);

	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.getRATE());
	printf("계좌최소잔고: %d\n", x.getMIN_BALANCE());
	return x;
}
#endif

// case 2. call by address
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class SData {
	// 멤버 속성
private:
	double RATE;
	int MIN_BALANCE;
protected:
public:
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData* inputData(SData*);
SData* printData(SData*);
int main(void) {
	SData x;

	x = *(inputData(&x));
	x = *(printData(&x)); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	return 0;
}
SData* inputData(SData* x)
{
	int min_balance;
	double rate;

	scanf("%lf", &(rate));
	scanf("%d", &(min_balance));

	x->setRATE(rate);
	x->setMIN_BALANCE(min_balance);

	return x;
}
SData* printData(SData* x)
{
	printf("이자율: %lf\n", x->getRATE());
	printf("계좌최소잔고: %d\n", x->getMIN_BALANCE());
	return x;
}
#endif

// case 3. cassl by reference
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class SData {
	// 멤버 속성
private:
	double RATE;
	int MIN_BALANCE;
protected:
public:
	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData& inputData(SData&);
SData& printData(SData&);
int main(void) {
	SData x;

	x = inputData(x);
	x = printData(x); // 반환할 필요가 없으나 함수 포인터 사용하기 위해 반환형으로 작성

	return 0;
}
SData& inputData(SData& x)
{
	int min_balance;
	double rate;

	scanf("%lf", &(rate));
	scanf("%d", &(min_balance));

	x.setRATE(rate);
	x.setMIN_BALANCE(min_balance);
	return x;
}
SData& printData(SData& x)
{
	printf("이자율: %lf\n", x.getRATE());
	printf("계좌최소잔고: %d\n", x.getMIN_BALANCE());
	return x;
}
#endif

//=========================================================================================
// 15-2. 클래스 변수 - 함수 포인터 배열로 변환한 형태
//=========================================================================================
// case 1. call by value
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define FColSize 2
using namespace std;

class SData {
	// 멤버 속성
private:
	double RATE;
	int MIN_BALANCE;
protected:
public:

	//멤버 메서드
private:
protected:
public:
	SData() { cout << "기본 생성자" << endl; }
	~SData() { cout << "기본 소멸자" << endl; }
	void	setRATE(double rate) { this->RATE = rate; }
	void	setMIN_BALANCE(int min_balance) { this->MIN_BALANCE = min_balance; }
	double	getRATE(void) { return this->RATE; }
	int		getMIN_BALANCE(void) { return this->MIN_BALANCE; }
	void	DisplayRATE(void) { cout << this->RATE << endl; }
	void	DisplayMIN_BALANCE(void) { cout << this->MIN_BALANCE << endl; }
};

SData inputData(SData);
SData printData(SData);
int main(void) {
	//SData(*FunctionPtr[FColSize])(SData) = { inputData, printData };
	SData(*FunctionPtr[FColSize])(SData) = { &inputData, &printData };
	void (SData:: * FunctionPtr1)(double);
	void (SData:: * FunctionPtr2)(int);
	SData x;
	int i;

	FunctionPtr1 = &(SData::setRATE);
	FunctionPtr2 = &(SData::setMIN_BALANCE);

	(x.*FunctionPtr1)(0);
	(x.*FunctionPtr2)(0); // call by value인 경우 초기화해야함.

	for (i = 0; i < FColSize; i++)
	{
		x = FunctionPtr[i](x);
	}
	return 0;
}
SData inputData(SData x)
{
	int min_balance;
	double rate;

	scanf("%lf", &(rate));
	scanf("%d", &(min_balance));

	x.setRATE(rate);
	x.setMIN_BALANCE(min_balance);

	return x;
}
SData printData(SData x)
{
	printf("이자율: %lf\n", x.getRATE());
	printf("계좌최소잔고: %d\n", x.getMIN_BALANCE());
	return x;
}
#endif

