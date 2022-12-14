/* 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴?
	File:			LL.C

	Notes:			General Link List Handling Code
	
	Author:			G Robert Liddon @ Croydon
	Created:		Wednesday 6th October 1994

	Copyright (C) 1994 G Robert Liddon
	All rights reserved. 
  컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴? */

/* 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴?
	Includes
	컴컴컴컴 */
#include "ll.h"

/* 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴?
	Defines
	컴컴컴? */

/* 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴?
	Detach from a list
	컴컴컴컴컴컴컴컴컴 */
void LL_DetachFromList(LinkList **Head,LinkList *ThisObj)
{
	if (ThisObj->Prev)
		ThisObj->Prev->Next=ThisObj->Next;
	else
		*Head=ThisObj->Next;

	if (ThisObj->Next)
		ThisObj->Next->Prev=ThisObj->Prev;
}

/* 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴?
	Add To A List
	컴컴컴컴컴컴? */
void LL_AddToList(LinkList **Head,LinkList *ThisObj)
{
	ThisObj->Prev=NULL;

	if ((ThisObj->Next=*Head))
		ThisObj->Next->Prev=ThisObj;

	*Head=ThisObj;
}


/* 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴?
	ends
	컴컴 */
