#include "AlgoFunction.h"

////////////////////////////////////////////////////////////////////
// Show Case AlgoFunc 1~13 exit 9999
void ShowAlgorithm()
{
	printf("Yeah! ~@.@~\n");

	// Plan
	int nSelect = 0;
	while (TRUE)
	{
		printf("������ �˰����� �����Ͽ��ּ���\n");
		scanf_s("%d", &nSelect);

		if (nSelect == 9999) break;

		switch (nSelect)
		{
		case 1:
			printf("GCD�˰���\n");
			int a = 0, b = 0;
			int gcd = 0;
			printf("input a : ");
			scanf_s("%d", &a);
			printf("input b : ");
			scanf_s("%d", &b);
			printf("---------------------------------\n");
			gcd = getGCD(a, b);
			printf("---------------------------------\n");
			printf("result GCD : %d\n", gcd);
			break;
		case 2:
			printf("�ϳ��̾˰���\n");
			int n = 0;
			printf("Input board number : ");
			scanf_s("%d", &n);
			printf("---------------------------------\n");
			Hanoi(n, 'A', 'B', 'C');
			printf("---------------------------------\n");
			break;
		case 3:
			printf("�Ҽ��˰���\n");
			int n = 0;
			printf("Input number : ");
			scanf_s("%d", &n);
			printf("---------------------------------\n");
			if(IsPrimeNumber(n) == TRUE)
				printf("%d is a prime number.\n");
			else
				printf("%d is not prime number.\n");
			printf("---------------------------------\n");
			break;
		case 4:
			printf("�������˰���\n");
			int n = 0;
			printf("SELECT 3,5,7 : ");
			scanf_s("%d", &n);
			printf("---------------------------------\n");
			InitSquare();
			GetOddSquare(n);
			ShowSquare(n);
			printf("---------------------------------\n");
			break;
		default:
			printf("�ٽ� �������ּ���!\n");
			break;
		}
	}
}

////////////////////////////////////////////////////////////////////
// 01.�ִ����� Greatest Common Divisor
// �ִ�������? ���� a,b�� ��� �߿��� ����� �����
// �������� �ϸ� ����� �߿��� ���� ū ���� �ִ� ������� �մϴ�.
//
// �ִ������� ���ϱ� ���� ����
// 1.���� a�� ����� ������ ���� A�� ���Ѵ�.
// 2.���� b�� ����� ������ ���� B�� ���Ѵ�.
// 3.���� a�� b�� ������� ������ ���� C�� ���Ѵ�(���� A�� B�� ������).
// 4.���� C���� ���� ū���� c�� ���� a�� b�� �ִ������̴�.
//
// �Ѱ���
// 1.������ ����� ���ϴµ� �� ���� �ſ� ū ��쿡�� ���� �ð��� �ɸ���.
// 2.A���հ� B������ �������� ���ؼ� ����� ������ C�� ����µ� ����
//   �ɸ���. A�� B������ ��� ��ҵ��� ���ؼ� ���� ���� ã�� �۾���
//   ���ճ��� ����� ���� ���� ��� ���� �ð��� �ʿ�� �Ѵ�.
// 3.������� ������ C���� �ִ������� C�� ã�µ� ��� �񱳸� ����
//   ���� ū ���� ã�ƾ� �ϹǷ� ���� �ð��� �ҿ�ȴ�.
//
// ��Ŭ���� �˰���
// �־��� ���� �Ұ� �ƴ� �� �� a,b������ �ִ������� ã�� ������
// �ΰ��� ��Ģ�� ������ �ϰ� �ִ�.
// 1.b�� a�� ������ �������� �μ��� �ִ������� b�̴�.
// 2.a�� b�� ������ �� �������� r�̸�, �μ��� �ִ������� r�� b�� �ִ������� ����.
// GCD(120, 50) = GCD(50, 20) = GCD(20, 10) = GCD(10, 0)
// 120�� 50���� ������ r=20, 50�� 20���� ������ r=10
// 20�� 10���� ������ r=0, �ִ������� 10 = b
int getGCD(int nFir, int nSec)
{
	printf("GCD(%d, %d)\n", nFir, nSec);

	while (nSec != 0)
	{
		int temp = nSec;
		nSec = nFir % nSec;
		nFir = temp;

		printf("GCD(%d, %d)\n", nFir, nSec);
	}

	return nFir;
}

////////////////////////////////////////////////////////////////////
// 02.�ϳ���ž Hanoi Tower
//
void Hanoi(int n, char from, char middle, char to)
{
	if (n == 1)
		printf("board #%02d %c -> %c\n", n, from, to);
	else
	{
		Hanoi(n - 1, from, to, middle);
		printf("board #%02d %c -> %c\n", n, from, to);
		Hanoi(n - 1, middle, from, to);
	}
}

////////////////////////////////////////////////////////////////////
// 03. �Ҽ� Prime Number
void IsPrimeNumber(int n)
{
	int count = 0;

	for(int i = 0; i <=n; i++)
	{
		if(n % i == 0)
			count++;
	}

	if(count == 2)
		return TRUE;

	return FALSE;
}

////////////////////////////////////////////////////////////////////
// 04. ������ Magic Square
void InitSquare()
{
	for(int i = 0; i < MAX_SIZE; i++)
	{
		for(int j = 0; j < MAX_SIZE; j++)
			g_nSquare[i][j] = 0;
	}
}

void GetOddSquare(int n)
{
	int row = 0;
	int col = 0;
	int nValue = 1;

	col = n/2;

	while(nValue <= n*n)
	{
		g_nSquare[row][col] = nValue;

		if(nValue % n == 0)
			row++;
		else
		{
			row--;
			col++;
		}

		if(row < 0)
			row = n - 1;
		if(row >= n)
			col = n-1;
		if(col >= n)
			col = 0;
		
		nValue++;
	}
}

void ShowSquare(int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			printf("%02d", g_nSquare[i][j]);
		printf("\n");
	}
	printf("\n");
}

////////////////////////////////////////////////////////////////////
// 05. �迭 Array

////////////////////////////////////////////////////////////////////
// 06. ��ũ Link

////////////////////////////////////////////////////////////////////
// 07. ���� Stack

////////////////////////////////////////////////////////////////////
// 08. ť Queue

////////////////////////////////////////////////////////////////////
// 09. Ʈ�� Tree

////////////////////////////////////////////////////////////////////
// 10. ���� Sorting

////////////////////////////////////////////////////////////////////
// 11. �˻� Searching

////////////////////////////////////////////////////////////////////
// 12. ��ȣȭ Cryptography

////////////////////////////////////////////////////////////////////
// 13. ���� Compress
