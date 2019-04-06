// Queue2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
typedef struct PNode* Queue;
struct Node
{
	int data;
	struct Node* next;
};

struct PNode
{
	struct Node* front;
	struct Node* rear;
};

int DeQueue(Queue q)
{
	if (q->front == NULL)
	{
		cout << "栈空" << endl;
		return -1;
	}
	struct Node* ptr=q->front;
	int e = ptr->data;
	//如果只有一个元素，删除之后rear也会变化
	if (q->front->next == q->rear)
	{
		q->front =q->rear= NULL;
	}
	else
	{
		q->front = ptr->next;
	}
	free(ptr);
	return e;
}

void addQueue(Queue q, int x)
{
	struct Node* S = (struct Node*)malloc(sizeof(Node));
	S->next = NULL;
	S->data = x;
	q->rear->next = S;
	q->rear = S;
}


