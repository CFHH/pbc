/*
 * Quadratic field extensions.
 */

//requires
// * field.h
#ifndef __PBC_FIELDQUADRATIC_H__
#define __PBC_FIELDQUADRATIC_H__

#include <_pbc_export.h>

// Initialize L as K[sqrt(a)], where a is a quadratic nonresidue of K. We
// automatically randomly generate a if necessary (see field_get_nqr() in
// field.c).
PBC_DECLSPEC_EXPORT void PBC_STDCALL field_init_quadratic(field_ptr L, field_ptr K);

// Initialize L as K[i], where i = sqrt(-1). Faster than the generic version.
// Requires -1 to be a quadratic nonresidue in K.
PBC_DECLSPEC_EXPORT void PBC_STDCALL field_init_fi(field_ptr L, field_ptr K);

// Naturally map an element from a field K to K[a].
PBC_DECLSPEC_EXPORT void PBC_STDCALL element_field_to_quadratic(element_ptr out, element_ptr in);
PBC_DECLSPEC_EXPORT void PBC_STDCALL element_field_to_fi(element_ptr a, element_ptr b);

#endif //__PBC_FIELDQUADRATIC_H__
