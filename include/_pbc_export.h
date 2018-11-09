#ifndef __PBC_EXPORT_H__
#define __PBC_EXPORT_H__

#define PBC_DECLSPEC_EXPORT  __declspec(dllexport)
#define PBC_DECLSPEC_IMPORT __declspec(dllimport)
#define PBC_STDCALL __stdcall

#ifdef MSC_BUILD_DLL
#define PBC_EXTERN PBC_DECLSPEC_EXPORT
#else
#define PBC_EXTERN PBC_DECLSPEC_IMPORT
#endif

#endif  //__PBC_EXPORT_H__
