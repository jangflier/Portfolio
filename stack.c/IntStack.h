#pragma once

// int형 스택 IntStack(헤더)
#ifndef __IntStack
#define __IntStack

// 스택을 구현하는 구조체, C++의 경우 class로 구현
typedef struct {
	int max;  // 스택 용량 : 스택으 최대 용량을 나아태는 멤버입니다.
	int ptr;  // 스택 포인터 : 스택에 쌓여 있는 데이터의 개수를 나타내는 멤버입니다.
	int* stk; // 스택의 첫 요소를 가리키는 포인터입니다.
} IntStack;


// 스택 초기화
int Initialize(IntStack* s, int max);

// 스택에 데이터를 푸시
int Push(IntStack* s, int x);

// 스택에 데이터를 팝
int Pop(IntStack* s, int* x);

// 스택에 데이터를 피크
int Peek(const IntStack* s, int* x);

// 스택 비우기
void Clear(IntStack* s);

// 스택의 최대 용량
int Capacity(const IntStack* s);

// 스택의 데이터 개수
int Size(const IntStack* s);

// 스택이 비어있는지 체크
int IsEmpty(const IntStack* s);

// 스택이 가득 찼는지 체크
int IsFull(const IntStack* s);

// 스택 검색
int Search(const IntStack* s, int x);

// 스택의 모든 데이터 출력
void Print(const IntStack* s);

// 스택 종료
void Terminate(IntStack* s);

// 문자입력 제한
int IntScanf(void);

#endif // !__IntStack