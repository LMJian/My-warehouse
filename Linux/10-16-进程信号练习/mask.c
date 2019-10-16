#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<signal.h>

int main()
{
  sigset_t set,oldset;
  sigemptyset(&set);
  sigfillset(&set);
  sigprocmask(SIG_BLOCK,&set,&oldset);
  printf("press enter to continue");
  getchar();

  return 0;

}
