#pragma once

// Int형 큐 IntQueue(헤더)
#ifndef __IntQueue
#define __IntQueue

// 큐를 구현하는 구조체(링 버퍼 이용), C++의 경우 class로 구현
typedef struct {
	int front; // 프론트 : 인큐한 데이터 중 제일 앞의 인덱스를 저장하는 멤버입니다. 
	int rear;  // 리어 : 인큐한 데이터 중 제일 뒤에서 한 칸 뒤의 인덱스를 저장하는 멤버입니다.
	int num;   // 현재 데이터 개수 : 큐에 쌓아 놓은 데이터수를 나타내는 멤버입니다.
	           // front와 rear가 같은 인덱스를 가르킬 경우, 큐가 비어있는지 가득찼는지 구별하기 위해서 사용됩니다.
	int max;   // 큐의 용량 : 큐의 최대 용량을 저장하는 멤버입니다.
	int* que;  // 큐의 첫 요소를 가리키는 포인터입니다.
} IntQueue;

// 큐 초기화
int Initialize(IntQueue* q, int max);

// 큐에 데이터를 인큐
int Enqueue(IntQueue* q, int en);

// 큐에 데이터를 디큐
int Dequeue(IntQueue* q, int* de);

// 큐에서 데이터를 피크
int Peek(const IntQueue* q, int* pk);

// 큐의 최대 용량
int Capacity(const IntQueue* q);

// 큐의 데이터 개수
int Size(const IntQueue* q);

// 큐가 비어있는지 체크
int IsEmpty(const IntQueue* q);

// 큐가 가득 찼는지 체크
int IsFull(const IntQueue* q);

// 큐 검색
int Search(const IntQueue* q,const int x);

// 큐의 모든 데이터 출력
void Print(const IntQueue* q);

// 큐 비우기
void Clear(IntQueue* q);

// 큐 종료
void Terminate(IntQueue* q);

// 문자입력 제한
int IntScanf(void);

#endif // !__IntQueue