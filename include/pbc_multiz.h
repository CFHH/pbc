// Multinomnials with integer coefficients.

//requires
// * field.h

#ifndef __PBC_FIELDMULTI_H__
#define __PBC_FIELDMULTI_H__

#include <_pbc_export.h>

PBC_DECLSPEC_EXPORT void field_init_multiz(field_ptr f);

PBC_DECLSPEC_EXPORT element_ptr multiz_new_list(element_ptr e);
PBC_DECLSPEC_EXPORT void multiz_append(element_ptr l, element_ptr m);

PBC_DECLSPEC_EXPORT void multiz_to_mpz(mpz_ptr z, multiz ep);
PBC_DECLSPEC_EXPORT int multiz_is_z(multiz m);
PBC_DECLSPEC_EXPORT multiz multiz_at(multiz m, int i);
PBC_DECLSPEC_EXPORT int multiz_count(multiz m);
PBC_DECLSPEC_EXPORT int multiz_is0(multiz m);

#endif //__PBC_FIELDMULTI_H__
