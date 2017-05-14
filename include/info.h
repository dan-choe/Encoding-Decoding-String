#ifndef INFO_H
#define INFO_H
#include <stdlib.h>
#include <stdio.h>

#ifdef INFO
	#define DINFO(fmt, ...) do{fprintf(stderr, "" fmt, ##__VA_ARGS__);}while(0)
#else
	#define DINFO(fmt, ...)
#endif

#endif /* DEBUG_H */
