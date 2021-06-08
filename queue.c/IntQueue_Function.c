#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"

/* -- 큐 초기화 함수 --
* 1. 큐의 메모리 공간(배열)을 초기화(확보)하는 함수입니다.
*/
int Initialize(IntQueue* q, int max)
{
	q->num = q->front = q->rear = 0; // 처음에는 데이터가 쌓여있지 않으므로 0을 대입합니다.
	if ((q->que = calloc(max, sizeof(int))) == NULL) { // 동적배열 생성에 실패했을 경우, max에 0을 대입하고, -1을 반환합니다.
		q->max = 0; // 존재하지 않는 배열 que에 다른 함수의 접근을 막기 위해서, max에 0을 대입합니다.
		return -1;
	}
	q->max = max; // 배열생성에 성공했을 경우, 구조체 안의 max멤버에 매개변수로 입력된 max를 대입합니다.
	puts("\n!!!큐 생성 성공!!!\n");
	return 0;
}

/* -- 큐에 데이터를 인큐하는 함수 --
* 1. 큐에 데이터를 순서대로 추가하는 함수입니다.
*/
int Enqueue(IntQueue* q, int x)
{
	if (IsFull(q)) { // 큐가 가득 차서 인큐할 수 없는 경우, -1을 반환합니다.
		puts("큐가 가득 차있습니다.");
		return -1;
	}
	else { // 아래의 코드는 큐가 가득차지 않은 경우 실행됩니다.
		printf("queue[%d] = %d\n", q->rear, x);
		q->num++;              // num은 큐에 쌓여있는 데이터 개수를 알려주는 멤버이므로, 인큐에 성공할 때마다 +1씩 증가시켜줍니다.
		q->que[q->rear++] = x;   // 매개변수로 들어온 x값을 que[0]에 저장 시킨 후, rear값을 +1 증가시켜줍니다.
		if (q->rear == q->max) // 큐가 가득 차지 않아도 큐의 원형 구조상 rear와 max의 값이 같아질 수 있기 때문에
			                   // rear와 max의 값이 같을 경우, rear를 0으로 초기화 해줍니다.
			q->rear = 0;
		return 0;
	}
}

/* -- 큐에 데이터를 디큐하는 함수 --
* 1. 큐에 데이터를 순서대로 삭제하는 함수입니다.
*/
int Dequeue(IntQueue* q, int* x)
{
	if (IsEmpty(q)) { // 큐가 비어있을 경우. -1을 반환합니다.
		puts("큐가 비어있습니다.");
		return -1;
	}
	else { // 아래의 코드는 큐가 비어있지 않은 경우 실행됩니다.
		q->num--;                // 디큐에 성공할 때마다 -1씩 감소시켜줍니다.
		*x = q->que[q->front++]; // 매개변수가 가리키는 곳인 포인터 x로 디큐한 값을 전송하고, 맨 앞에 위치한 front의 값을 +1 증가시켜줍니다.
		if (q->front == q->max)  // 큐가 비어있지 않아도 큐의 원형 구조상 front와 max의 값이 같아질 수 있기 때문에
			                     // front와 max의 값이 같을 경우, front를 0으로 초기화 해줍니다.
			q->front = 0;
		return 0;
	}
}

/* -- 큐에서 데이터를 피크하는 함수 --
* 1. 큐의 맨 앞의 데이터(front) 값을 확인하는 함수입니다.
*/
int Peek(const IntQueue* q, int* pk)
{
	if (IsEmpty(q)) { // 큐가 비어있다면, -1을 반환합니다.
		puts("큐가 비어있습니다.");
		return -1;
	}
	else {
		*pk = q->que[q->front]; // 큐에 데이터가 있을 경우, 포인터pk가 가리키는 변수에, front가 가리키는 값을 저장한 후, 0을 반환합니다.
		return 0;
	}
}

/* -- 큐의 최대용량을 확인하는 함수 --
*/
int Capacity(const IntQueue* q)
{
	return q->max; // 큐 구조체 내의 max멤버(큐의 최대용량)에 저장된 값을 반환합니다.
}

/* -- 큐에 쌓여 있는 데이터 개수를 확인하는 함수 -- 
*/
int Size(const IntQueue* q)
{
	return q->num; // 큐 구조체 내의 num멤버(큐의 데이터 개수)에 저장된 값을 반환합니다.
}

/* -- 큐가 비어있는지 검사하는 함수 --
*/
int IsEmpty(const IntQueue* q)
{
	return q->num <= 0; // 데이터가 비어있으면 1을, 그렇지 않으면 0을 반환합니다.
}

/* -- 큐가 가득 찼는지 검사하는 함수 --
*/
int IsFull(const IntQueue* q)
{
	return q->num >= q->max; // 데이터가 최대용량을 넘거나 같으면 1을, 그렇지 않으면 0을 반환합니다.
}

/* -- 큐내의 데이터를 검색하는 함수 --
* 1. 임의의 값의 데이터가 큐의 어느 위치에 쌓여 있는지 검색하는 함수입니다.
*/
int Search(const IntQueue* q,const int x)
{
	int i, idx;
	if (IsEmpty(q)) {
		puts("큐가 비어있습니다.");
		return -1;
	}
	for (i = 0; i < q->num; i++) { // 현재 쌓여진 데이터 개수만큼 for문을 반복합니다.
		if (q->que[idx = (i + q->front) % q->max] == x) // front의 값은 디큐를 하면서 변하기 때문에, front의 값이 0이 아닌 경우를 포함해야 합니다.
														// 그래서 현재 검색하고 있는 위치의 인덱스 값은 (i+front) % max로 구할 수 있습니다.
			return idx;                                 // 만약 중복된 숫자가 있다면 제일 먼저 디큐 될 데이터가 있는 인덱스 값을 반환합니다.
	}
	return -1; // 검색에 실패할 경우, -1을 반환합니다.
}

/* -- 큐의 모든 데이터를 출력하는 함수 --
* 1. front부터 큐의 모든 데이터를 출력하는 함수입니다.
*/
void Print(const IntQueue* q)
{
	int i;
	if (IsEmpty(q)) { // 데이터가 비어 있는지 먼저 체크 합니다.
		puts("\a큐가 비어있습니다.");
		return;
	}
	for (i = 0; i <q->num; i++) { // 큐의 데이터 수 만큼 반복합니다.
		printf("queue[%d] = %d\n", (i + q->front) % q->max, q->que[(i + q->front) % q->max]);
	}
	return;
}

/* -- 큐를 비우는 함수 --
* 1. 큐에 쌓여 있는 모든 데이터를 제거하는 함수입니다.
*/
void Clear(IntQueue* q)
{
	q->num = q->front = q->rear = 0; // 초기화 할 때 처럼 front, rear, num에 0을 대입하는 것만으로도 큐의 데이터를 제거하는 효과를 얻을 수 있습니다.
}

/* -- 큐를 종료하는 함수 --
* 1. 큐의 배열을 해제하고, 정리하는 함수입니다.
*/
void Terminate(IntQueue* q)
{
	if (q->que != NULL) // 큐의 배열이 존재하는 경우, 구조체 내의 배열을 해제합니다.
		free(q->que);
	q->max = q->num = q->front = q->rear = 0; // 구조체 내의 멤버들을 모두 0으로 초기화 합니다.
	printf("\n!!!큐 제거 성공!!!\n");
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