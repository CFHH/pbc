// ring of integers Z
// wrappers around GMP's mpz_t

//requires
// * field.h

#ifndef __PBC_FIELDMPZ_H__
#define __PBC_FIELDMPZ_H__

#include <_pbc_export.h>

PBC_DECLSPEC_EXPORT void PBC_STDCALL field_init_z(field_ptr f);

#endif //__PBC_FIELDMPZ_H__
