#include "shell.h"
int lsh_num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}