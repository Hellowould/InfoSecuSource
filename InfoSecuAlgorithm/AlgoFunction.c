#include "AlgoFunction.h"

int getGCD(int nFir, int nSec)
{
	// 최대공약수란?
	// 정수 a,b의 약수 중에서 공통된 약수를
	// 공약수라고 하며 공약수 중에서
	// 가장 큰 수를 최대 공약수라 합니다.
	//
	// 최대공약수를 구하기 위한 과정
	// 1.정수 a의 약수로 구성된 집합 A를 구한다.
	// 2.정수 b의 약수로 구성된 집합 B를 구한다.
	// 3.정수 a와 b의 공약수로 구성된 집합 C를 구한다(집합 A와 B의 교집합).
	// 4.집합 C에서 가장 큰수인 c가 정수 a와 b의 최대공약수이다.
	//
	// 한계점
	// 1.정수의 약수를 구하는데 그 값이 매우 큰 경우에는 많은 시간이 걸린다.
	// 2.A집합과 B집합의 교집합을 구해서 공약수 집합인 C를 만드는데 오래
	//   걸린다. A와 B집합의 모든 요소들을 비교해서 같은 값을 찾는 작업이
	//   집합내의 요소의 수가 많을 경우 많은 시간을 필요로 한다.
	// 3.공약수의 집합인 C에서 최대공약수인 C를 찾는데 대소 비교를 통해
	//   가장 큰 수를 찾아야 하므로 많은 시간이 소요된다.
	//
	// 유클리드 알고리즘
	// 주어진 서로 소가 아닌 두 수 a,b에대해 최대공약수를 찾는 것으로
	// 두개의 규칙을 전제로 하고 있다.
	// 1.b가 a로 나눠서 떨어지면 두수의 최대공약수는 b이다.
	// 2.a를 b로 나웠을 때 나머지가 r이면, 두수의 최대공약수는
	//   r과 b의 최대공약수와 같다.
	// GCD(120, 50) = GCD(50, 20) = GCD(20, 10) = GCD(10, 0)
	// 120을 50으로 나누면 r=20,
	// 50을 20으로 나누면 r=10
	// 20을 10으로 나누면 r=0, 최대공약수는 10 = b
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
