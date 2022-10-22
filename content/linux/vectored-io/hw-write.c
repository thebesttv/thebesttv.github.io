#include <stdio.h>              // perror()
#include <stdlib.h>             // exit(), EXIT_SUCCESS, EXIT_FAILURE
#include <unistd.h>             // write(), STDOUT_FILENO

int main() {
  const char buf[] = "Hello world from thebesttv!\n";
  if (write(STDOUT_FILENO, buf, sizeof(buf)) == -1) {
    perror("write()");
    exit(EXIT_FAILURE);
  }
  return EXIT_SUCCESS;
}
