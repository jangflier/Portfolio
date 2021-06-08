#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

/* -- 스택 초기화 함수 --
* 1. 스택의 메모리 공간(배열)을 초기화(확보)하는 함수입니다.
* 2. 배열을 위한 메모리 공간을 만들 때 스택의 데이터가 하나도 쌓여 있지 않은 상태여야 합니다.
* 3. 매개변수 int max로 받은 값을 스택 최대 용량을 나타내는 구조체의 멤버 max에 저장합니다.
* 4. 스택 포인터 ptr 값은 0, 요소의 개수는 max인 배열 stk를 생성합니다.
* 5. 스택의 개별 요소는 stk[0]부터 stk[max-1]이 됩니다. max-1인 이유 : 배열은 인덱스 값이 0부터 시작하기 때문에
*/
int Initialize(IntStack* s, int max)
{
	s->ptr = 0; // 처음에는 데이터가 쌀여있지 않으므로 0을 대입합니다.
	if ((s->stk = calloc(max, sizeof(int))) == NULL) {
		/* calloc함수는 메모리 할당에 실패했을 경우, NULL포인터를 반환합니다.
		* 구조체내의 stk값이 NULL포인터 일 경우 max에 0을 대입 후 -1을 반환합니다.
		*/
		s->max = 0; // 존재하지 않는 배열 stk에 다른 함수의 접근을 막기 위해서, max에 0을 대입합니다.
		return -1;
	}
	s->max = max; // 매개변수의 max값이 구조체내의 max에 대입됩니다.
	puts("\n!!!스택 생성 성공!!!\n");
	return 0;
}

/* -- 스택에 데이터를 푸시하는 함수 --
* 1. 스택에 데이터를 차례대로 추가하는 함수입니다.
* 2. 프로그램의 오류나 사용자의 잘못된 값의 입력으로 ptr값이 max를 초과할 수 있으므로, ==관계연산자가 아닌 >=와 같은 관계연산자를 사용 했습니다.
*/
int Push(IntStack* s, int x)
{
	if (IsFull(s)) { // 스택이 가득차서 푸시할 수 없는 경우, -1을 반환합니다.
		puts("\a스택이 가득 차있습니다.");
		return -1;
	}
	s->stk[s->ptr++] = x; // 스택이 가득차지 않았다면, 새로 추가할 데이터 x를 배열의 top에 저장하고, ptr의 값이 1 증가합니다.
	printf("stk[%d] = %d\n", s->ptr - 1, x); // 푸시하는 데이터의 위치와 값을 출력합니다.
	return 0;
}

/* -- 스택에서 데이터를 팝하는 함수 --
* 1. 스택의 top에서 데이터 하나를 제거합니다.
*/
int Pop(IntStack* s, int* x)
{
	if (IsEmpty(s)) {
		puts("\a스택이 비어있습니다.");
		return -1;
	}
	if (s->ptr <= 0) { // 현재 스택에 쌓여 있는 데이터의 개수가 0보다 작거나 같으면 -1을 반환합니다.
		return -1;
	}
	*x = s->stk[--(s->ptr)]; // top에 데이터가 존재하는 경우, top의 데이터를 포인터x가 가리키는 변수에 저장합니다.
	return 0;
}

/* -- 스택에서 데이터를 피크하는 함수 --
* 1. 스택의 top에 있는 데이터의 값을 확인하는 함수입니다.
*/
int Peek(const IntStack* s, int* x) // 스택내에 값의 변경이 이루어지지 않으므로, const를 사용하였습니다.
{
	if (IsEmpty(s)) { // 스택에 쌓여있는 데이터가 없을 경우, -1을 반환합니다.
		puts("\a스택이 비어있습니다.");
		return -1;
	}
	*x = s->stk[s->ptr - 1]; // 스택에 쌓여있는 데이터가 있을 경우, 포인터x가 가리키는 변수에 top의 데이터 값을 저장합니다.
	return 0;
}

/* -- 스택을 비우는 함수 --
* 1. 스택에 쌓여 있는 모든 데이터를 제거하는 함수입니다.
*/
void Clear(IntStack* s)
{
	s->ptr = 0; // 스택의 푸시와 팝 등 모든 작업은 ptr의 값을 바탕으로 이루어지기 때문에
}               // ptr값에 0을 대입하면 스택의 모든 데이터를 제거하는 효과를 얻을 수 있습니다.

/* -- 스택의 최대용량을 확인하는 함수 --
*/
int Capacity(const IntStack* s)
{
	return s->max; // 스택의 최대용량인 max를 반환하는 함수입니다.
}

/* -- 스택에 쌓여 있는 데이터 개수를 확인하는 함수 --
*/
int Size(const IntStack* s)
{
	return s->ptr; // 스택의 데이터의 개수는 ptr의 값과 같으므로, ptr값을 반환합니다.
}

/* -- 스택이 비어있는지 검사하는 함수 --
*/
int IsEmpty(const IntStack* s)
{
	return s->ptr <= 0; // 스택이 비어있으면 1을, 그렇지 않으면 0을 반환합니다.
}

/* -- 스택이 가득 찼는지 검사하는 함수 --
*/
int IsFull(const IntStack* s)
{
	return s->ptr >= s->max; // 스택이 가득 찼으면 1을, 그렇지 않으면 0을 반환합니다.
}

/* -- 스택내의 데이터를 검색하는 함수 --
* 1. 임의의 값의 데이터가 스택의 어느 위치에 쌓여 있는지 검색하는 함수입니다.
*/
int Search(const IntStack* s, int x)
{
	int i;            // for문을 위해서 지역변수 i를 선언합니다.
	if (IsEmpty(s)) { // 데이터가 비어 있는지 먼저 체크합니다.
		puts("\a데이터가 비어 있습니다.");
		return -1;
	}
	for (i = s->ptr - 1; i >= 0; i--) // 스택의 top부터 bottom까지 선형검색합니다. ptr -1 인 이유는 ptr값은 항상 top보다 +1한 지점을 가리키기 때문입니다.
		if (s->stk[i] == x) {         // 스택의 데이터위치에 원하는 값이 존재하면, 그 값이 위치한 인덱스 값(i)을 반환합니다.
			return i;                 // 스택의 top부터 검색하는 이유는 먼저 팝 되는 데이터를 찾기 위해서입니다.
		}                             // 중복되는 데이터가 있을 경우, 제일 먼저 팝 되는 데이터의 인덱스 값을 반환합니다.
	return -1;                        // 원하는 값과 동일한 데이터가 존재하지 않는 경우, -1을 반환합니다.
}

/* -- 스택의 모든 데이터를 출력하는 함수 --
* 1. 스택에 쌓여 있는 ptr개의 모든 데이터를 bottom부터 순서대로 출력합니다.
*/
void Print(const IntStack* s)
{
	int i;
	if (IsEmpty(s)) { // 데이터가 비어 있는지 먼저 체크합니다.
		puts("\a데이터가 비어 있습니다.");
	}
	for (i = 0; i < s->ptr; i++) { // 스택의 bottom부터 top까지 순서대로 출력합니다.
		printf("stack[%d] = %d\n", i, s->stk[i]);
	}
}

/* -- 스택을 종료하는 함수 --
* 1. 스택의 배열을 해제하고, 정리하는 함수입니다.
*/
void Terminate(IntStack* s)
{
	if (s->stk != NULL)  // 스택의 배열이 존재할 경우(NULL이 아닌 경우), free함수로 배열을 해제합니다.
		free(s->stk);
	s->max = s->ptr = 0; // 배열을 제거하고 구조체내의 max와 ptr값을 0으로 초기화 합니다.
	printf("\n\n!!!스택 제거 완료!!!\n\n");
}

/* -- 문자 입력을 제한하는 함수 --
* 1. 숫자가 아닌 문자가 입력되었을 경우, 입력버퍼를 비워서 무한루프에 빠지는 것을 방지합니다.
*/
int IntScanf(void)
{
	int x;
	if (scanf_s("%d", &x) == 0) { // 문자가 입력되어 scanf 함수가 0을 반환했을 경우, 입력버퍼를 비우고 -1을 반환합니다.
		rewind(stdin);
		return -1;
	}
	else // 문자 입력 외의 값이 입력된 경우, 입력되었던 값을 반환합니다.
		return x;
}