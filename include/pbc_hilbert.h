// Requires:
// * gmp.h
#ifndef __PBC_HILBERT_H__
#define __PBC_HILBERT_H__

#include <_pbc_export.h>

// Allocate an array of mpz_t and fill it with the coefficients of the Hilbert
// polynomial H_D(x). Returns the size of array.
PBC_EXTERN size_t PBC_STDCALL pbc_hilbert(mpz_t **arr, int D);

// Free an array allocated by `pbc_hilbert()`.
PBC_EXTERN void PBC_STDCALL pbc_hilbert_free(mpz_t *arr, size_t n);

#endif //__PBC_HILBERT_H__
