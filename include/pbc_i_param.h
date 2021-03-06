// Eta_T pairing over ternary extension field
//
// Requires:
// * pbc_param.h
#ifndef __PBC_I_PARAM_H__
#define __PBC_I_PARAM_H__

#include <_pbc_export.h>

struct symtab_s;
PBC_EXTERN int PBC_STDCALL pbc_param_init_i(pbc_param_ptr par, struct symtab_s *);

/*@manual aparam
Generate type I pairing parameters and store them in 'p',
where the group order is at least 2^'group_size'.

To be as secure as 64 bit symmetric encryption, 'group_size' may be 150.
To get 128 bit symmetric secure level, 'group_size' may be 696.

The file `param/i.param` contains parameters for a type I pairing suitable for
cryptographic use.
*/
PBC_EXTERN void PBC_STDCALL pbc_param_init_i_gen(pbc_param_ptr par, int group_size);

#endif //__PBC_I_PARAM_H__
