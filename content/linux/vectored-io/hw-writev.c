#include <stdio.h>              // perror()
#include <string.h>             // strlen()
#include <stdlib.h>             // exit(), EXIT_SUCCESS, EXIT_FAILURE
#include <unistd.h>             // STDOUT_FILENO
#include <sys/uio.h>            // vectored IO: iovec, writev()

#define LENGTH 3

int main() {
  const char *bufs[LENGTH] = {"Hello ", "world ", "from thebesttv!\n"};

  struct iovec vecs[LENGTH];
  for (int i = 0; i < LENGTH; i++) {
    vecs[i].iov_base = (void *)bufs[i];
    vecs[i].iov_len = strlen(bufs[i]);
  };

  if (writev(STDOUT_FILENO, vecs, LENGTH) == -1) {
    perror("writev()");
    exit(EXIT_FAILURE);
  }
  return EXIT_SUCCESS;
}
