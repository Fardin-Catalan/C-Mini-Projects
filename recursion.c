#include <stdio.h>
int factorial(int);
int main()
{
  char name[10];
  int num;
  printf("Enter your name:");
  fgets(name, sizeof(name), stdin);
  printf("Welcome to the recursion programme,%s", name);
  printf("Enter the number:");
  scanf("%d", &num);
  long long result = factorial(num);
  printf("The factorial of %d is %lld", num, result);
}
int factorial(int num)
{
  if (num == 0 || num == 1)
    return 1;
  return num * factorial(num - 1);
}