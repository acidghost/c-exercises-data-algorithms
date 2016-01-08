#ifndef _UTILS_H_
#define _UTILS_H_

typedef void *T;
typedef enum { true = 1, false = 0 } bool;
typedef unsigned int uint;

#define empty_placeholder(name) static int _ee; if (!name) name = &_ee;

#endif /* _UTILS_H_ */
