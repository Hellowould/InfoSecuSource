#include "InfoSecuAlgorithm.h"
#include "AlgoFunction.h"

int main()
{
	// Plan
	int nSelect = 0;
	while (1)
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
			if(IsPrimeNumber(n) == true)
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

	return 0;
}