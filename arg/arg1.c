#include <stdio.h>

int main()
{
	int input;
	int sum = 0;

	printf("수를 입력 : ");
	scanf("%d",&input);

	/*
	//시간복잡도 Big-O = n 
	for(char i = 1; i <= input; i++)
	{
		sum += i;
	}
	*/

	/*
	//시간복잡도 Big-O = n/2
	for(char i = 1;  i <= input/2 ; i++)
	{
		sum += input + 1 + (input%2)*(1 + i/(input/2));
	}
	*/

	//시간복잡도 Big-O = 1
	sum = input * (input+1) / 2;

	printf("합계 : %d \n",sum);
	return 0;
}
