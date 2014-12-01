//-----------------------------------------------------------------------------
//   swmm5.h
//
//   Project: EPA SWMM5
//   Version: 5.0
//   Date:    6/19/07   (Build 5.0.010)
//            1/21/09   (Build 5.0.014)
//            4/10/09   (Build 5.0.015)
//   Author:  L. Rossman
//
//   Prototypes for SWMM5 functions exported to swmm5.dll.
//
//   Modified to better accommodate non-Windows OS's (5.0.014)                 //(5.0.014 - LR)
//   Modified to accommodate usage in C++ programs (5.0.015)                   //(5.0.015 - LR)
//-----------------------------------------------------------------------------

#ifndef SWMM5_H
#define SWMM5_H

// --- define WINDOWS

#undef WINDOWS

#ifdef _WIN32
#define WINDOWS
#endif

#ifdef __WIN32__
#define WINDOWS
#endif

// --- define DLLEXPORT

#ifdef WINDOWS
#define DLLEXPORT __declspec(dllexport) __stdcall
#define SDLLEXPORT __declspec(dllexport) 
#define STDCALL __stdcall
#else
#define DLLEXPORT 
#define SDLLEXPORT
#define STDCALL
#pragma GCC visibility push(default)
#endif

// --- use "C" linkage for C++ programs

#ifdef __cplusplus
extern "C" { 
#endif

#include "datetime.h"
#include "objects.h"

	int  DLLEXPORT   swmm_run(char* f1, char* f2, char* f3);
	int  DLLEXPORT   swmm_open(char* f1, char* f2, char* f3);
	int  DLLEXPORT   swmm_start(int saveFlag);
	int  DLLEXPORT   swmm_step(double* elapsedTime);
	int  DLLEXPORT   swmm_end(void);
	int  DLLEXPORT   swmm_report(void);
	int  DLLEXPORT   swmm_getMassBalErr(float* runoffErr, float* flowErr, float* qualErr);
	int  DLLEXPORT   swmm_close(void);
	int  DLLEXPORT   swmm_getVersion(void);

	//additional
	double DLLEXPORT swmm_getDateTime(char* beginorend);
	void DLLEXPORT  datetime_decodeDateTime(DateTime dateTime, int* y, int* m, int* d, int* h, int* mm, int* s);
	SDLLEXPORT char * getErrorMsg(int errorCode);
	int DLLEXPORT getObjectTypeCount(int type);

	//TNode
	SDLLEXPORT TNode* STDCALL getNode(int index);
	SDLLEXPORT TNode* STDCALL getNodeById(char* id);
	void DLLEXPORT setNode(TNode* node, char* propertyName);

	//TLink
	SDLLEXPORT TLink*  STDCALL getLink(int index);
	SDLLEXPORT TLink* STDCALL getLinkById(char* id);
	void DLLEXPORT setLink(TLink* link, char* propertyName);

	//TSubcatch
	SDLLEXPORT TSubcatch*  STDCALL getSubcatch(int index);
	SDLLEXPORT TSubcatch* STDCALL getSubcatchById(char* id);
	void DLLEXPORT setSubcatch(TSubcatch* subCatch, char* propertyName);

#ifdef __cplusplus 
}   // matches the linkage specification from above */ 
#endif

#ifdef WINDOWS
#else
#pragma GCC visibility pop
#endif

#endif