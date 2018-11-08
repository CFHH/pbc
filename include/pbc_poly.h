// Polynomial rings R[x], and polynomial rings modulo polynomials,
// i.e. R[x]_{f(x)}.

// Requires:
// * gmp.h
// * field.h
#ifndef __PBC_POLY_H__
#define __PBC_POLY_H__

#include <_pbc_export.h>

// Initializes a polynomial ring.
PBC_DECLSPEC_EXPORT void PBC_STDCALL field_init_poly(field_ptr f, field_ptr base_field);

// Initializes a polynomial modulo ring.
// Requires poly to be monic.
PBC_DECLSPEC_EXPORT void PBC_STDCALL field_init_polymod(field_ptr f, element_ptr poly);

#ifndef _MSC_VER
#pragma GCC visibility push(hidden)
#endif
// Internal library functions:

// Returns deg f.
/*PBC_DECLSPEC_EXPORT*/ static inline int PBC_STDCALL poly_degree(element_ptr f) {
  return element_item_count(f) - 1;
}

// Returns base field of f (where the coefficients live).
PBC_DECLSPEC_EXPORT field_ptr PBC_STDCALL poly_base_field(element_t f);

// Sets the coefficient of x^n to 0.
PBC_DECLSPEC_EXPORT void PBC_STDCALL poly_set_coeff0(element_ptr f, int n);

// Sets the coefficient of x^n to 1.
PBC_DECLSPEC_EXPORT void PBC_STDCALL poly_set_coeff1(element_ptr f, int n);

// Sets the coefficient of x^n to a.
PBC_DECLSPEC_EXPORT void PBC_STDCALL poly_set_coeff(element_ptr f, element_ptr a, int n);

// Sets f = x.
PBC_DECLSPEC_EXPORT void PBC_STDCALL poly_setx(element_ptr f);
PBC_DECLSPEC_EXPORT void PBC_STDCALL poly_const_mul(element_ptr res, element_ptr a, element_ptr poly);

// Returns 0 when a root exists and sets root to one of the roots.
PBC_DECLSPEC_EXPORT int PBC_STDCALL poly_findroot(element_ptr root, element_ptr poly);

// Returns 1 if polynomial is irreducible, 0 otherwise.
// Requires the polynomial to be monic.
PBC_DECLSPEC_EXPORT int PBC_STDCALL poly_is_irred(element_ptr f);
PBC_DECLSPEC_EXPORT void PBC_STDCALL poly_random_monic(element_ptr f, int deg);

PBC_DECLSPEC_EXPORT void PBC_STDCALL element_field_to_poly(element_t poly, element_t constant);
PBC_DECLSPEC_EXPORT void PBC_STDCALL element_field_to_polymod(element_ptr f, element_ptr a);

PBC_DECLSPEC_EXPORT void PBC_STDCALL polymod_const_mul(element_ptr res, element_ptr a, element_ptr e);
PBC_DECLSPEC_EXPORT int PBC_STDCALL polymod_field_degree(field_t f);

#ifndef _MSC_VER
#pragma GCC visibility pop
#endif

#endif //__PBC_POLY_H__
