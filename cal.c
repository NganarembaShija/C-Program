#include <stdio.h>
int main()
{
	float num1, num2, res;
	char op;
	printf("~~~~~Calculator~~~~\n\n");
	printf("-->  ");
	scanf("%f %c %f", &num1, &op, &num2 );
	switch(op)
	{
		case '+': res = num1 + num2;
				  break;

		case '-': res = num1 - num2;
				  break;

		case '/': res= num1 / num2;
				  break;

		case '*': res = num1 * num2;
				  break;

		default: printf("Please Enter a Valid Operator eg. + , -, /, *\n");
	}
	printf("%.2f\n",res );
}