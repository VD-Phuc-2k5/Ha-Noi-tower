#include <stdio.h>
#include <stdlib.h>

struct Item_Tower
{
	int num;
	char sour, midl, dest;
	void assign(int n, char a, char b, char c)
	{
		num = n; sour = a; midl = b; dest = c;	
	}
};
struct Node
{
	Item_Tower item;
	Node* next;
};	
struct Stack
{
	Node *head;
	void init() {head = NULL;}
	bool isEmpty() {return head == NULL;}
	Node* createNode(Item_Tower t)
	{
		Node* node = new Node;
		if (node == NULL)
		{
			printf("khong du bo nho!\n");
			return NULL;
		}
		node->item = t;
		node->next = NULL;
	}
	void push(Item_Tower t)
	{
		Node* p = createNode(t);
		if (p == NULL) return;
		if (isEmpty() == false)
			p->next = head;
		head = p;
	}
	Item_Tower pop()
	{
		Node* temp = head;
		head = head->next;
		Item_Tower t = temp->item;
		delete temp;
		temp = NULL;
		return t;
	}
};

void hanoi_Tower(int n, char a, char b, char c);

int main()
{
	int n;
	printf("Nhap so luong dia: ");
	scanf("%d", &n);
	hanoi_Tower(n, 'A', 'B', 'C');
	printf("\n");
	system("pause");
	return 0;
}

void hanoi_Tower(int n, char a, char b, char c)
{
	Item_Tower t;
	Stack sTower;
	sTower.init();
	int d = 0;
	t.assign(n, a, b, c);
	sTower.push(t);
	while(sTower.isEmpty() == false)
	{
		Item_Tower temp = sTower.pop();
		if (temp.num == 1)
			printf("\n B%d. %c -----> %c", ++d, temp.sour, temp.dest);
		else
		{
			t.assign(temp.num - 1, temp.midl, temp.sour, temp.dest);
			sTower.push(t);
			t.assign(1, temp.sour, temp.midl, temp.dest);
			sTower.push(t);
			t.assign(temp.num - 1, temp.sour, temp.dest, temp.midl);
			sTower.push(t);
		}
	}
}
