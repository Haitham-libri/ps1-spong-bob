/* 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴?
	File:			TICK.C

	Notes:			Game Frame Clock stuff
	
	Author:			G Robert Liddon @ Croydon
	Created:		Monday 2nd October 1995

	Copyright (C) 1994/1995 G Robert Liddon
	All rights reserved. 
  컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴? */


/* 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴?
	Glib Includes
	컴컴컴컴컴컴? */

/* 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴?
	Includes
	컴컴컴컴 */
#include "tick.h"

/* 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴?
	Vars
	컴컴 */
U32 GazTick;

/* 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴?
	Intialise the module
	컴컴컴컴컴컴컴컴컴컴 */
void TICK_InitModule(void)
{
	TICK_Set(0);
}	


/* 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴?
	Set the current tick value
	컴컴컴컴컴컴컴컴컴컴컴컴컴 */
void TICK_Set(U32 Val)
{
	GazTick=Val;
}	

/* 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴?
	Set the current tick value
	컴컴컴컴컴컴컴컴컴컴컴컴컴 */
U32 TICK_Get(void)
{
	return(GazTick);
}	


/* 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴?
	Update Tick
	컴컴컴컴컴? */
void TICK_Update(void)
{
	GazTick++;
}	

/* 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴?
	Get the frames passed since last tick
	컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴? */
U32 TICK_GetAge(U32 OldTick)
{
	return(TICK_Get()-OldTick);
}	

const char * TICK_GetDateString(void)
{
	return(__DATE__);
}	

const char * TICK_GetTimeString(void)
{
	return(__TIME__);
}	


/* 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴?
	ends */
