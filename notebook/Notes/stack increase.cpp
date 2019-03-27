#include <sys/resource.h>
int main() { 
  const rlim_t rlm=1024*1024*1024;
  struct rlimit rl;
  getrlimit(RLIMIT_STACK,&rl);
  rl.rlim_cur=rlm;
  setrlimit(RLIMIT_STACK, &rl);
}