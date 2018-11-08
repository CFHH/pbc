// Requires:
// * gmp.h
#ifndef __PBC_RANDOM_H__
#define __PBC_RANDOM_H__

#include <_pbc_export.h>

/*@manual pbcrandom
Sets 'filename' as a source of random bytes. For example,
on Linux one might use `/dev/random`.
*/
PBC_DECLSPEC_EXPORT void PBC_STDCALL pbc_random_set_file(char *filename);

/*@manual pbcrandom
Uses a determinstic random number generator, seeded with 'seed'.
*/
PBC_DECLSPEC_EXPORT void PBC_STDCALL pbc_random_set_deterministic(unsigned int seed);

/*@manual pbcrandom
Uses given function as a random number generator.
*/
PBC_DECLSPEC_EXPORT void PBC_STDCALL pbc_random_set_function(void (*fun)(mpz_t, mpz_t, void *), void *data);

/*@manual pbcrandom
Selects a random 'z' that is less than 'limit'.
*/
PBC_DECLSPEC_EXPORT void PBC_STDCALL pbc_mpz_random(mpz_t z, mpz_t limit);

/*@manual pbcrandom
Selects a random 'bits'-bit integer 'z'.
*/
PBC_DECLSPEC_EXPORT void PBC_STDCALL pbc_mpz_randomb(mpz_t z, unsigned int bits);


PBC_DECLSPEC_EXPORT void PBC_STDCALL pbc_init_random(void);
#endif //__PBC_RANDOM_H__
