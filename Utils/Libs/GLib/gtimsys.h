/* 様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様?
	File:		GTIMSYS.C

	Notes:		Timing system stuff needed by gtim

	Author:		G Robert Liddon @ 73b

	Copyright (C) 1996 DCI Ltd All rights reserved. 
  様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様 */

#ifndef __GTIMSYS_H__
#define __GTIMSYS_H__

/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Includes
	陳陳陳陳 */

/*	Glib
	陳陳 */
#include "gtypes.h"

/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Defines
	陳陳陳? */

/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Typedefs
	陳陳陳陳 */

/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Enums
	陳陳? */

/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Structures
	陳陳陳陳陳 */

/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Supported Functions
	陳陳陳陳陳陳陳陳陳? */
#ifdef __cplusplus
extern "C" {
#endif

GLIB_API U32	GTIMSYS_InitTimer(void);
GLIB_API void	GTIMSYS_ResetTimer(void);
GLIB_API U32	GTIMSYS_GetTimer(void);

#ifdef __cplusplus
}
#endif

/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
#endif
/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	ends */

