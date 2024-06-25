#ifndef main_h
#define main_h
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
int _printf(const char *format, ...);
int check(va_list arg, const char *cp);
#endif /*main_h */
