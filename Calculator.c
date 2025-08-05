#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
  int i;
  char name[50];
  printf("Enter your name:");
  fgets(name, sizeof(name), stdin);
  name[strcspn(name, "\n")] = '\0';
  do
  {
    printf("\nWelcome to the  Simple Calculator Programme, %s", name);
    printf("\nChoose one of the following options(1-7):\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Mod\n6.Power\n7.Exit");
    printf("\nNow,enter your choice:");
    scanf("%d", &i);
    if (i >= 1 && i <= 6)
    {
      int a, b;
      printf("\nEnter the first number:");
      scanf("%d", &a);
      printf("\nEnter the second number:");
      scanf("%d", &b);
      if (i == 1)
      {
        printf("\nThe addition of %d & %d is:%d", a, b, a + b);
      }
      else if (i == 2)
      {
        printf("\nThe subtraction of %d & %d is:%d", a, b, a - b);
      }
      else if (i == 3)
      {
        printf("\nThe Multliplication of %d & %d is:%d", a, b, a * b);
      }
      else if (i == 4)
      {
        if (b == 0)
        {
          printf("\nDivision by 0 cannot be executed");
        }
        else
        {
          printf("\nThe Division of %d & %d is:%.2f", a, b, (float)a / b);
        }
      }
      else if (i == 5)
      {
        if (b == 0)
        {
          printf("Input error!");
        }
        else
        {

          printf("\nThe Mod of %d & %d is:%d", a, b, a % b);
        }
      }
      else if (i == 6)
      {
        double c = pow(a, b);
        printf("\nThe Result of %d & %d is:%.2f", a, b, c);
      }
    }
    else if (i == 7)
    {
      printf("\nThank you for using the calculator, %s!\n", name);
    }
    else
    {
      printf("\nInvalid choice! Please enter a number between 1 and 7.");
    }
  } while (i != 7);
  return 0;
}