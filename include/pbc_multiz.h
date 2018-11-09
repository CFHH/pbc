// Multinomnials with integer coefficients.

//requires
// * field.h

#ifndef __PBC_FIELDMULTI_H__
#define __PBC_FIELDMULTI_H__

#include <_pbc_export.h>

PBC_EXTERN void PBC_STDCALL field_init_multiz(field_ptr f);

PBC_EXTERN element_ptr PBC_STDCALL multiz_new_list(element_ptr e);
PBC_EXTERN void PBC_STDCALL multiz_append(element_ptr l, element_ptr m);

PBC_EXTERN void PBC_STDCALL multiz_to_mpz(mpz_ptr z, multiz ep);
PBC_EXTERN int PBC_STDCALL multiz_is_z(multiz m);
PBC_EXTERN multiz PBC_STDCALL multiz_at(multiz m, int i);
PBC_EXTERN int PBC_STDCALL multiz_count(multiz m);
PBC_EXTERN int PBC_STDCALL multiz_is0(multiz m);

#endif //__PBC_FIELDMULTI_H__
