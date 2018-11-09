//requires
// * stdio.h
// * gmp.h
// * field.h
#ifndef __PBC_SINGULAR_H__
#define __PBC_SINGULAR_H__

#include <_pbc_export.h>

PBC_EXTERN void PBC_STDCALL field_init_curve_singular_with_node(field_t c, field_t field);
PBC_EXTERN void PBC_STDCALL pairing_init_singular_with_node(pairing_t pairing, mpz_t q);

#endif //__PBC_SINGULAR_H__
