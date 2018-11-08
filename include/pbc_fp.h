/* There does not appear to be a succint name for rings of type Z/nZ.
 * Sage calls it integer mod ring.
 * NTL calls it ZZ_p.
 * I'll call it fp, as it's the quickest to type.
 * "zn" might be better since it can also handle composite numbers.
 */
// Requires:
// * field.h
// * gmp.h
#ifndef __PBC_FP_H__
#define __PBC_FP_H__

#include <_pbc_export.h>

PBC_DECLSPEC_EXPORT void PBC_STDCALL field_init_naive_fp(field_ptr f, mpz_t prime);
PBC_DECLSPEC_EXPORT void PBC_STDCALL field_init_tiny_fp(field_ptr f, mpz_t prime);
PBC_DECLSPEC_EXPORT void PBC_STDCALL field_init_fast_fp(field_ptr f, mpz_t prime);
PBC_DECLSPEC_EXPORT void PBC_STDCALL field_init_faster_fp(field_ptr f, mpz_t prime);
PBC_DECLSPEC_EXPORT void PBC_STDCALL field_init_mont_fp(field_ptr f, mpz_t prime);

PBC_DECLSPEC_EXPORT void PBC_STDCALL pbc_tweak_use_fp(char *s);

PBC_DECLSPEC_EXPORT void PBC_STDCALL element_tonelli(element_ptr x, element_ptr a);

PBC_DECLSPEC_EXPORT void PBC_STDCALL field_init_fp(field_ptr f, mpz_t prime);

PBC_DECLSPEC_EXPORT int PBC_STDCALL pbc_mpz_set_str(mpz_t z, const char *s, int base);
#endif //__PBC_FP_H__
