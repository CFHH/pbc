#ifndef __PBC_EXPORT_H__
#define __PBC_EXPORT_H__

#ifdef MSC_BUILD_DLL
#define PBC_DECLSPEC_EXPORT  __declspec(dllexport)
#define PBC_STDCALL __stdcall
#else
#define PBC_DECLSPEC_EXPORT
#define PBC_STDCALL
#endif

#endif
