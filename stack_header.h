#ifndef __stack_header__
#define __stack_header__
#include "stack.cpp"

void my_write(stack <string> &s1);
void my_read(stack <string> &s1,stack <string> &s2,char *);
void my_save(stack <string> &s1,char *);
void my_undo(stack <string> &s1,stack <string> &s2);
void my_redo(stack <string> &s1,stack <string> &s2);
void my_exit(stack <string> &s1,char *);
void my_cut(stack<string> &s1,stack<string> &s2);

#endif