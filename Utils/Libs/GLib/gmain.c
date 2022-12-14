/* 様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様?
	File:		GMAIN.C

	Notes:		Main!

	Author:		G Robert Liddon @ 73b

	Created:	Wednesday 27th March 1996

	Copyright (C) 1996 DCI Ltd All rights reserved. 
  様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様 */


/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Glib Includes
	陳陳陳陳陳陳? */
#include "gmain.h"
#include "gal.h"
#include "gsys.h"
#include "tick.h"
#include "gutils.h"
				 
/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function Prototypes
	陳陳陳陳陳陳陳陳陳? */

/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Main
	陳陳 */
void main(void)
{
	GSYS_InitMachine();
	GAL_InitModule();
	TICK_InitModule();
	GU_InitModule();

	AppMain();

	while (1)
		{
		}
}	

/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Ends
	陳陳 */
