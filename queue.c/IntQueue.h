#pragma once

// Int�� ť IntQueue(���)
#ifndef __IntQueue
#define __IntQueue

// ť�� �����ϴ� ����ü(�� ���� �̿�), C++�� ��� class�� ����
typedef struct {
	int front; // ����Ʈ : ��ť�� ������ �� ���� ���� �ε����� �����ϴ� ����Դϴ�. 
	int rear;  // ���� : ��ť�� ������ �� ���� �ڿ��� �� ĭ ���� �ε����� �����ϴ� ����Դϴ�.
	int num;   // ���� ������ ���� : ť�� �׾� ���� �����ͼ��� ��Ÿ���� ����Դϴ�.
	           // front�� rear�� ���� �ε����� ����ų ���, ť�� ����ִ��� ����á���� �����ϱ� ���ؼ� ���˴ϴ�.
	int max;   // ť�� �뷮 : ť�� �ִ� �뷮�� �����ϴ� ����Դϴ�.
	int* que;  // ť�� ù ��Ҹ� ����Ű�� �������Դϴ�.
} IntQueue;

// ť �ʱ�ȭ
int Initialize(IntQueue* q, int max);

// ť�� �����͸� ��ť
int Enqueue(IntQueue* q, int en);

// ť�� �����͸� ��ť
int Dequeue(IntQueue* q, int* de);

// ť���� �����͸� ��ũ
int Peek(const IntQueue* q, int* pk);

// ť�� �ִ� �뷮
int Capacity(const IntQueue* q);

// ť�� ������ ����
int Size(const IntQueue* q);

// ť�� ����ִ��� üũ
int IsEmpty(const IntQueue* q);

// ť�� ���� á���� üũ
int IsFull(const IntQueue* q);

// ť �˻�
int Search(const IntQueue* q,const int x);

// ť�� ��� ������ ���
void Print(const IntQueue* q);

// ť ����
void Clear(IntQueue* q);

// ť ����
void Terminate(IntQueue* q);

// �����Է� ����
int IntScanf(void);

#endif // !__IntQueue