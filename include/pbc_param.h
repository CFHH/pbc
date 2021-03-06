// Requires:
// * gmp.h
#ifndef __PBC_PARAM_H__
#define __PBC_PARAM_H__

#include <_pbc_export.h>

struct pairing_s;
struct pbc_param_interface_s {
  void (PBC_STDCALL *clear)(void *);
  void (PBC_STDCALL *init_pairing)(struct pairing_s *, void *);
  void (PBC_STDCALL *out_str)(FILE *stream, void *data);
};
typedef struct pbc_param_interface_s pbc_param_interface_t[1];
typedef struct pbc_param_interface_s *pbc_param_interface_ptr;

struct pbc_param_s {
  pbc_param_interface_ptr api;
  void *data;
};
typedef struct pbc_param_s *pbc_param_ptr;
typedef struct pbc_param_s pbc_param_t[1];

/*@manual param
Initializes pairing parameters from the string 's'.
Returns 0 if successful, 1 otherwise.
*/
PBC_EXTERN int PBC_STDCALL pbc_param_init_set_str(pbc_param_t par, const char *s);

/*@manual param
Same, but read at most 'len' bytes.
If 'len' is 0, it behaves as the previous function.
Returns 0 if successful, 1 otherwise.
*/
PBC_EXTERN int PBC_STDCALL pbc_param_init_set_buf(pbc_param_t par, const char *s, size_t len);

/*@manual param
Write pairing parameters to ''stream'' in a text format.
*/
/*PBC_EXTERN*/ static inline void PBC_STDCALL pbc_param_out_str(FILE *stream, pbc_param_ptr p) {
  p->api->out_str(stream, p->data);
}

/*@manual param
Clear 'p'. Call after 'p' is no longer needed.
*/
/*PBC_EXTERN*/ static inline void PBC_STDCALL pbc_param_clear(pbc_param_ptr p) {
  p->api->clear(p->data);
}

#endif //__PBC_PARAM_H__
