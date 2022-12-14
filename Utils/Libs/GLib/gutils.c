/* 様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様?
	File:		GUTILS.C

	Notes:		Machine indepnant util code

	Author:		G Robert Liddon @ 73b

	Project:	NBA Hang Time PSX

	Copyright (C) 1996 DCI Ltd All rights reserved. 
  様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様 */


/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Includes
	陳陳陳陳 */

/*	Glib 
	陳陳 */
#include "gsys.h"
#include "gdebug.h"

/*	Game
	陳陳 */
#include "gutils.h"


/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function Prototypes
	陳陳陳陳陳陳陳陳陳? */

/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Vars
	陳陳 */
U32 RndTabs[6];

/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Tables
	陳陳陳 */
U32 DefaultRnd[6]=
{
	0xabcd1234,
	0xffde1534,
	0xffde1534,
	0x001a1010,
	0xf61a1890,
	0x00000002,
};


/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Init the general utilities module
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
BOOL GU_InitModule(void)
{
	GU_SetRndSeed(DefaultRnd);
	return(TRUE);
}	


/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Init the general utilities module
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
void GU_SetRndSeed(U32 *Tab)
{
	int		f;

	for (f=0;f<6;f++)
		RndTabs[f]=Tab[f];
}	

/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Get a random 32 bit unsigned number
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
U32 GU_GetRnd(void)
{
	U32		RetVal;

	RetVal=RndTabs[1]+RndTabs[4];

	if (RetVal< RndTabs[1] && RetVal < RndTabs[4])
		RetVal++;

	RetVal++;

	RndTabs[0]=RetVal;

	RndTabs[5]=RndTabs[4];
	RndTabs[4]=RndTabs[3];
	RndTabs[3]=RndTabs[2];
	RndTabs[2]=RndTabs[1];
	RndTabs[1]=RndTabs[0];

	return(RndTabs[0]);
}

/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:		S32 GU_GetSRnd(void)
	Notes:			Get a signed random number
	Returns:		Signed Number
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 */
S32 GU_GetSRnd(void)
{
	return((S32)GU_GetRnd());
}	

/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:		U32 GU_GetRndRange(UINT Range)
	Notes:			Returns a number between 0 and Range-1
	Params:			Range	->	Max number returned -1
	Returns:		unsigned number
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 */
U32 GU_GetRndRange(UINT Range)
{
	return(GU_GetRnd()%Range);
}	

/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:		UINT GU_AlignVal(UINT w,UINT round)
	Notes:			Align a value to a boundary (7 round to boundaries of 4 = 8)
	Params:			w =	Value to align
					round =	Boundaries to align it to			
	Returns:		Aligned number
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 */
UINT GU_AlignVal(UINT w,UINT round)
{
	w += round - 1;
	return (w - w % round);
}	

/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	ends */
