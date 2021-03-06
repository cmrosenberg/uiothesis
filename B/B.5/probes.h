/*
 * Generated by dtrace(1M).
 */

#ifndef	_PROBES_H
#define	_PROBES_H

#include <unistd.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define STACK_STABILITY "___dtrace_stability$stack$v1$5_5_5_1_1_5_1_1_5_5_5_5_5_5_5"

#define STACK_TYPEDEFS "___dtrace_typedefs$stack$v2"

#if !defined(DTRACE_PROBES_DISABLED) || !DTRACE_PROBES_DISABLED

#define	STACK_EMPTY(arg0) \
do { \
	__asm__ volatile(".reference " STACK_TYPEDEFS); \
	__dtrace_probe$stack$empty$v1$756e7369676e656420696e74(arg0); \
	__asm__ volatile(".reference " STACK_STABILITY); \
} while (0)
#define	STACK_EMPTY_ENABLED() \
	({ int _r = __dtrace_isenabled$stack$empty$v1(); \
		__asm__ volatile(""); \
		_r; })
#define	STACK_FULL(arg0) \
do { \
	__asm__ volatile(".reference " STACK_TYPEDEFS); \
	__dtrace_probe$stack$full$v1$756e7369676e656420696e74202a(arg0); \
	__asm__ volatile(".reference " STACK_STABILITY); \
} while (0)
#define	STACK_FULL_ENABLED() \
	({ int _r = __dtrace_isenabled$stack$full$v1(); \
		__asm__ volatile(""); \
		_r; })
#define	STACK_POP(arg0) \
do { \
	__asm__ volatile(".reference " STACK_TYPEDEFS); \
	__dtrace_probe$stack$pop$v1$756e7369676e656420696e74202a(arg0); \
	__asm__ volatile(".reference " STACK_STABILITY); \
} while (0)
#define	STACK_POP_ENABLED() \
	({ int _r = __dtrace_isenabled$stack$pop$v1(); \
		__asm__ volatile(""); \
		_r; })
#define	STACK_PUSH(arg0, arg1) \
do { \
	__asm__ volatile(".reference " STACK_TYPEDEFS); \
	__dtrace_probe$stack$push$v1$696e74$756e7369676e656420696e74202a(arg0, arg1); \
	__asm__ volatile(".reference " STACK_STABILITY); \
} while (0)
#define	STACK_PUSH_ENABLED() \
	({ int _r = __dtrace_isenabled$stack$push$v1(); \
		__asm__ volatile(""); \
		_r; })


extern void __dtrace_probe$stack$empty$v1$756e7369676e656420696e74(unsigned int);
extern int __dtrace_isenabled$stack$empty$v1(void);
extern void __dtrace_probe$stack$full$v1$756e7369676e656420696e74202a(const unsigned int *);
extern int __dtrace_isenabled$stack$full$v1(void);
extern void __dtrace_probe$stack$pop$v1$756e7369676e656420696e74202a(const unsigned int *);
extern int __dtrace_isenabled$stack$pop$v1(void);
extern void __dtrace_probe$stack$push$v1$696e74$756e7369676e656420696e74202a(int, const unsigned int *);
extern int __dtrace_isenabled$stack$push$v1(void);

#else

#define	STACK_EMPTY(arg0) \
do { \
	} while (0)
#define	STACK_EMPTY_ENABLED() (0)
#define	STACK_FULL(arg0) \
do { \
	} while (0)
#define	STACK_FULL_ENABLED() (0)
#define	STACK_POP(arg0) \
do { \
	} while (0)
#define	STACK_POP_ENABLED() (0)
#define	STACK_PUSH(arg0, arg1) \
do { \
	} while (0)
#define	STACK_PUSH_ENABLED() (0)

#endif /* !defined(DTRACE_PROBES_DISABLED) || !DTRACE_PROBES_DISABLED */


#ifdef	__cplusplus
}
#endif

#endif	/* _PROBES_H */
