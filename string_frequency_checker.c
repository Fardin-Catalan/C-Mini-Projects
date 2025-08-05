#include <stdio.h>
#include <string.h>
int main()
{
  char line[200];
  char *words[50];
  int count = 0;
  int freq[50] = {0};
  printf("Enter the strings:");
  fgets(line, sizeof(line), stdin);
  line[strcspn(line, "\n")] = '\0';
  char *word = strtok(line, " ");
  while (word != NULL)
  {
    int found = 0;
    for (int i = 0; i < count; i++)
    {
      if (strcmp(words[i], word) == 0)
      {
        freq[i]++;
        found = 1;
        break;
      }
    }

    if (found != 1)
    {
      words[count] = word;
      freq[count] = 1;
      count++;
    }
    word = strtok(NULL, " ");
  }
  printf("\nThe frequencies are respectively shown below:\n");
  for (int i = 0; i < count; i++)
  {
    printf("%s:%d times\n", words[i], freq[i]);
  }
  return 0;
}
