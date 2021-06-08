#pragma once

// int�� ���� IntStack(���)
#ifndef __IntStack
#define __IntStack

// ������ �����ϴ� ����ü, C++�� ��� class�� ����
typedef struct {
	int max;  // ���� �뷮 : ������ �ִ� �뷮�� �����´� ����Դϴ�.
	int ptr;  // ���� ������ : ���ÿ� �׿� �ִ� �������� ������ ��Ÿ���� ����Դϴ�.
	int* stk; // ������ ù ��Ҹ� ����Ű�� �������Դϴ�.
} IntStack;


// ���� �ʱ�ȭ
int Initialize(IntStack* s, int max);

// ���ÿ� �����͸� Ǫ��
int Push(IntStack* s, int x);

// ���ÿ� �����͸� ��
int Pop(IntStack* s, int* x);

// ���ÿ� �����͸� ��ũ
int Peek(const IntStack* s, int* x);

// ���� ����
void Clear(IntStack* s);

// ������ �ִ� �뷮
int Capacity(const IntStack* s);

// ������ ������ ����
int Size(const IntStack* s);

// ������ ����ִ��� üũ
int IsEmpty(const IntStack* s);

// ������ ���� á���� üũ
int IsFull(const IntStack* s);

// ���� �˻�
int Search(const IntStack* s, int x);

// ������ ��� ������ ���
void Print(const IntStack* s);

// ���� ����
void Terminate(IntStack* s);

// �����Է� ����
int IntScanf(void);

#endif // !__IntStack