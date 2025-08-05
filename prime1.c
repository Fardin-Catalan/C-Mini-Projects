#include <stdio.h>

int main()
{
  long long num;
  printf("Enter number: ");
  scanf("%lld", &num);

  if (num < 2)
  {
    printf("%lld is not a prime number.\n", num);
    return 0;
  }
  for (long long i = 2; i * i <= num; i++)
  {
    if (num % i == 0)
    {
      printf("%lld is not a prime number.\n", num);
      return 0;
    }
  }

  printf("%lld is a prime number.\n", num);
  return 0;
}
