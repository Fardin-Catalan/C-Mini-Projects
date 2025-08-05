#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
const int MAX_LENGTH = 50;
const int MAX_TASK = 5;
typedef struct
{
  int id;
  int progress;
  int step;
} Task;
void print_bar(Task task);
void clear_screen();
int main()
{
  Task tasks[MAX_TASK];
  for (int i = 0; i < MAX_TASK; i++)
  {
    tasks[i].id = (i + 1);
    tasks[i].progress = 0;
    tasks[i].step = 3;
  }
  int tasks_incomplete = 1;
  while (tasks_incomplete)
  {
    clear_screen();
    tasks_incomplete = 0;

    for (int i = 0; i < MAX_TASK; i++)
    {
      print_bar(tasks[i]);
    }
    sleep(1);
    for (int i = 0; i < MAX_TASK; i++)
    {
      if (tasks[i].progress < 100)
      {
        tasks[i].progress += tasks[i].step;
        if (tasks[i].progress > 100)
        {
          tasks[i].progress = 100;
        }
        tasks_incomplete = 1;
      }
    }
  }
  printf("\n\nAll tasks completed!\n");
}
void clear_screen()
{
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}
void print_bar(Task task)
{
  int bars_to_show = (task.progress * MAX_LENGTH) / 100; // কতগুলো '=' দেখাবো

  printf("Task %d: [", task.id); // Task নম্বর ও bar শুরু

  for (int i = 0; i < MAX_LENGTH; i++)
  {
    if (i < bars_to_show)
      printf("="); // যতটুকু progress হয়েছে সেখানে '='
    else
      printf(" "); // বাকিটা ফাঁকা
  }

  printf("] %d%%\n", task.progress); // progress percentage দেখাও
}