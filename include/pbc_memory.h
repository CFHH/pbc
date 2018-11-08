// Requires:
// * stdlib.h
#ifndef __PBC_MEMORY_H__
#define __PBC_MEMORY_H__

#include <_pbc_export.h>

// Memory allocation functions used by PBC.
PBC_DECLSPEC_EXPORT extern void *(*pbc_malloc)(size_t);
PBC_DECLSPEC_EXPORT extern void *(*pbc_realloc)(void *, size_t);
PBC_DECLSPEC_EXPORT extern void (*pbc_free)(void *);

PBC_DECLSPEC_EXPORT void *pbc_calloc(size_t, size_t);

/*@manual alloc
Set custom allocation functions.  The parameters must be function pointers to
drop-in replacements for malloc, realloc and free, except that malloc and
realloc should terminate the program on failure: they must not return in this
case.
*/
PBC_DECLSPEC_EXPORT void pbc_set_memory_functions(void *(*malloc_fn)(size_t),
        void *(*realloc_fn)(void *, size_t), void (*free_fn)(void *));

PBC_DECLSPEC_EXPORT char *pbc_strdup(const char *s);

#endif //__PBC_MEMORY_H__
