#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <string.h>

static char buffer[2048];

char* readline(char* prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer)+1)
  strcpy(cpy, buffer)
  cpy[strlen(cpy)-1] = '\0';
  return cpy;
}

void add_history(char* unused) {}

#else
#include <editline/readline.h>
#endif

int main(int argc, char** argv) {

  puts("iceflame version 0.0.0.1");
  puts("Need help use --help");
  puts("Press Ctrl+c to Exit\n");

  while(1) {

    char* input = readline("iceflame> ");

    add_history(input);

    if ( strcmp(input, "--help") == 0) {
      printf("This is the help documentation\n");
    }
    else {
      printf("No you're a %s\n", input);
    }

    free(input);
  }
  return 0;
}
