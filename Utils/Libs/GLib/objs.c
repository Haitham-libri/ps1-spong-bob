/* 様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様?
	File:			OBJS.C

	Notes:			Genric Object Server

	Author:			G Robert Liddon @ The Park

	Created:		Wednesday 5th April, 1995

	Copyright (C) 1995 G Robert Liddon
	All rights reserved. 
  様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様 */

/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Includes
	陳陳陳陳 */

/*	Glib
	陳陳 */
#include "objs.h"
#include "gal.h"
#include "gdebug.h"


/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function Prototypes
	陳陳陳陳陳陳陳陳陳? */
void OBJS_DetachOLFromList(OBJ_LIST **Head,OBJ_LIST *ThisObj);

static void OBJS_AddOLToList(OBJ_LIST **Head,OBJ_LIST *ThisObj);
static void OBJS_DetachFromList(OBJ_STRUCT **Head,OBJ_STRUCT *ThisObj);
static void OBJS_AddToList(OBJ_STRUCT **Head,OBJ_STRUCT *ThisObj);
static void SortList(OBJ_LIST *OL);

/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Vars
	陳陳 */
int				ObjsAlloced;			/* Number of currently active objs */
OBJ_LIST *		ListOfObjLists;			/* Head of the list of print Qs */
BOOL			AddVels;				/* Should vels be auto added or not */
U32				MemId;
void			(*ProcessEpilog)(void);	/* Called after processobj */
void			(*ProcessProlog)(void);	/* Called after processobj */
/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:		void OBJS_OpenModule(U32 MemType)
	Purpose:		Initialise the object module for use.
	Params:			MyMaxObjs = Max objs to alloc for
					MemType	 = GAL memtype to alloc in
	Returns:		TRUE if opened succesfuly
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
BOOL OBJS_OpenModule(U32 MemType)
{
	MemId=MemType;
	ObjsAlloced=0;
	ListOfObjLists=NULL;
	AddVels=TRUE;

	ProcessEpilog=NULL;
	ProcessProlog=NULL;

	return TRUE;
}	

/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	BOOL OBJS_CloseModule(void)
	Purpose:	Closes the active obj module
	Returns:	TRUE if closed succesfuly
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
BOOL OBJS_CloseModule(void)
{
	OBJS_DestroyAllObjs();
	return TRUE;
}



/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	void OBJS_AddDisplayList(OBJ_LIST *OL)
	Purpose:	Add a display list
	Params:		OL		->	Object List to add

	Returns:	-> Created object if succesfull
				NULL if not
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
void OBJS_AddDisplayList(OBJ_LIST *OL)
{
	OBJS_AddOLToList(&ListOfObjLists,OL);
	OL->Head=NULL;
	OL->Visible=TRUE;
	OL->SortCompare=NULL;
}	


/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	OBJ_STRUCT *OBJS_MakeObj(const OBJ_TYPE_INFO *OTI,OBJ_LIST *OL,void *Ptr)
	Purpose:	Make an object
	Params:		OTI	->	Obj type info
				OL	->	Object List to add to
				Ptr	->	Instance specefic info

	Returns:	-> Created object if succesfull
				NULL if not
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
OBJ_STRUCT *OBJS_CreateObjMulti(const OBJ_TYPE_INFO *OTI,OBJ_LIST *OL,GAL_STRUCT * G,void *Ptr)
{
	UINT	TotalMem;

	TotalMem=GAL_ProcessMultiStruct(G,MemId);

	return(OBJS_CreateObj(OTI,OL,(int)TotalMem,Ptr));
}

/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	OBJ_STRUCT *OBJS_MakeObj(const OBJ_TYPE_INFO *OTI,OBJ_LIST *OL,void *Ptr)
	Purpose:	Make an object
	Params:		OTI	->	Obj type info
				OL	->	Object List to add to
				Ptr	->	Instance specefic info

	Returns:	-> Created object if succesfull
				NULL if not
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
OBJ_STRUCT *OBJS_CreateObj(const OBJ_TYPE_INFO *OTI,OBJ_LIST *OL,int DataSize,void *Ptr)
{
	MHANDLE			ObjHandle;

	int				SizeOfObjstruct;
	int				SizeOfData;

	OBJ_STRUCT *	ThisObj;


	SizeOfObjstruct=GAL_AlignSizeToType(sizeof(OBJ_STRUCT),MemId);
	if (SizeOfObjstruct==-1)
		return(NULL);

	SizeOfData=GAL_AlignSizeToType((U32)DataSize,MemId);
	if (SizeOfData==-1)
		return(NULL);

	ObjHandle=GAL_Alloc((U32)(SizeOfObjstruct+SizeOfData),MemId,"OBJ");
	if (ObjHandle==NULL_HANDLE)
		return(NULL);


	ThisObj=GAL_Lock(ObjHandle);

	if (ThisObj)
		{
		OBJS_AddToList(&OL->Head,ThisObj);

		ThisObj->MemHandle=ObjHandle;
		ThisObj->Data=(void *)((U32)ThisObj + SizeOfObjstruct);

		ThisObj->OTI=OTI;
		ThisObj->OL=OL;

		ThisObj->ID=0;
		ThisObj->XVel=0;
		ThisObj->YVel=0;
		ThisObj->ZVel=0;

		if (ThisObj->OTI->Constructor)
			ThisObj->OTI->Constructor(ThisObj,Ptr);

		ObjsAlloced++;
		}

	return ThisObj;
}



/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	void OBJS_ProcessObjsEpilogue(void (*Func)(void))

	Purpose:	Add a call back that's executed after OBJS_ProcessObjs

	Params:		Func	->	Function
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
void OBJS_ProcessObjsEpilogue(void (*Func)(void))
{
	ProcessEpilog=Func;
}	

/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	void OBJS_ProcessObjsPrologue(void (*Func)(void))

	Purpose:	Add a call back that's executed before OBJS_ProcessObjs

	Params:		Func	->	Function
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
void OBJS_ProcessObjsPrologue(void (*Func)(void))
{
	ProcessProlog=Func;
}	

/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	void OBJS_DetachFromList(OBJ_STRUCT **Head,OBJ_STRUCT *ThisObj)
	Purpose:	Take an object from an obj list
	Params:		Head	->	Head ptr of list
				ThisObj	->	Obj to add
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
static void OBJS_DetachFromList(OBJ_STRUCT **Head,OBJ_STRUCT *ThisObj)
{
	if (ThisObj->Prev)
		ThisObj->Prev->Next=ThisObj->Next;
	else
		*Head=ThisObj->Next;

	if (ThisObj->Next)
		ThisObj->Next->Prev=ThisObj->Prev;
}


/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	void OBJS_AddToList(OBJ_STRUCT **Head,OBJ_STRUCT *ThisObj)
	Purpose:	Add an object to a obj list
	Params:		Head	->	Head ptr of list
				ThisObj	->	Obj to add
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
static void OBJS_AddToList(OBJ_STRUCT **Head,OBJ_STRUCT *ThisObj)
{
	ThisObj->Prev=NULL;

	if ((ThisObj->Next=*Head))
		ThisObj->Next->Prev=ThisObj;

	*Head=ThisObj;
}



/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	void OBJS_DetachFromList(OBJ_STRUCT **Head,OBJ_STRUCT *ThisObj)
	Purpose:	Take an object from an obj list
	Params:		Head	->	Head ptr of list
				ThisObj	->	Obj to add
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
void OBJS_DetachOLFromList(OBJ_LIST **Head,OBJ_LIST *ThisObj)
{
	if (ThisObj->Prev)
		ThisObj->Prev->Next=ThisObj->Next;
	else
		*Head=ThisObj->Next;

	if (ThisObj->Next)
		ThisObj->Next->Prev=ThisObj->Prev;
}


/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	void OBJS_AddToList(OBJ_STRUCT **Head,OBJ_STRUCT *ThisObj)
	Purpose:	Add an object to a obj list
	Params:		Head	->	Head ptr of list
				ThisObj	->	Obj to add
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
static void OBJS_AddOLToList(OBJ_LIST **Head,OBJ_LIST *ThisObj)
{
	ThisObj->Prev=NULL;

	if ((ThisObj->Next=*Head))
		ThisObj->Next->Prev=ThisObj;

	*Head=ThisObj;
}



/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Change this Object's Print List
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
void OBJS_ChangeDisplayList(OBJ_STRUCT *O,OBJ_LIST *NewList)
{
	if (NewList != O->OL)
		{
		OBJS_DetachFromList(&O->OL->Head,O);
		OBJS_AddToList(&NewList->Head,O);
		O->OL=NewList;
		}
}

/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:		void OBJS_ProcessObjs(void)
	Purpose:		Print the display lists
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
void OBJS_ProcessObjs(void)
{
	OBJ_LIST *ThisList;

	if (ProcessProlog)
		ProcessProlog();

	ThisList=ListOfObjLists;

	while (ThisList)
		{

 		if (ThisList->Visible)
			{
				{
				OBJ_STRUCT *ObjList;

				SortList(ThisList);

				ObjList=ThisList->Head;

				while (ObjList)
					{
					if (AddVels)
						{
						ObjList->XPos+=ObjList->XVel;
						ObjList->YPos+=ObjList->YVel;
						ObjList->ZPos+=ObjList->ZVel;
						}

					if (ObjList->OTI->Printer)
						ObjList->OTI->Printer(ObjList,ThisList);

					ObjList=ObjList->Next;
					}
				}
			}

		ThisList=ThisList->Next;
		}

	if (ProcessEpilog)
		ProcessEpilog();
}


/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:		void OBJS_ProcessObjs(void)
	Purpose:		Print the display lists
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
void OBJS_ObjsVelAddOnly(void)
{
	OBJ_LIST *ThisList;

	ThisList=ListOfObjLists;

	while (ThisList)
		{

 		if (ThisList->Visible)
			{
				{
				OBJ_STRUCT *ObjList;

				SortList(ThisList);

				ObjList=ThisList->Head;

				while (ObjList)
					{
					if (AddVels)
						{
						ObjList->XPos+=ObjList->XVel;
						ObjList->YPos+=ObjList->YVel;
						ObjList->ZPos+=ObjList->ZVel;
						}

					ObjList=ObjList->Next;
					}
				}
			}

		ThisList=ThisList->Next;
		}
}


/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	void OBJS_DestroyAllObjs(void)
	Purpose:	Delete all objects in all lists
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
void OBJS_DestroyAllObjs(void)
{
	OBJ_LIST *ThisList;
	ThisList=ListOfObjLists;

	while (ThisList)
		{
		OBJS_DestroyListObjs(ThisList);
		ThisList=ThisList->Next;
		}
}


/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	void OBJS_DestroyListObjs(OBJ_LIST *OL)
	Purpose:	Destroy all the objs in a list if list is killable
	Params:		OL -> List
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
void OBJS_DestroyListObjs(OBJ_LIST *OL)
{

	if (OL->Killable)
		{
		OBJ_STRUCT *O;
		O=OL->Head;

		while (O)
			O=OBJS_DestroyObj(O);
		}
}

/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	void OBJS_DestroyAllObjsOfAType(U32 Type,U32 AndMask)
	Purpose:	Go through all display lists and destroy objs
				of a certain type.
				if (O->ID&AndMask)==Type then obj is destroyed
	Params:		Type	= Type of objs to destroy
				AndMask	= And maks
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
void OBJS_DestroyAllObjsOfAType(U32 Type,U32 AndMask)
{
	OBJ_LIST *ThisList;

	ThisList=ListOfObjLists;

	while (ThisList)
		{
		OBJS_DestroyListObjsOfAType(ThisList,Type,AndMask);
		ThisList=ThisList->Next;
		}
}

/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	void OBJS_DestroyListObjsOfAType(OBJ_LIST *OL,U32 Type,U32 AndMask)
	Purpose:	Go through a single display list and destroy objs
				of a certain type.
				if (O->ID&AndMask)==Type then obj is destroyed
	Params:		Type	= Type of objs to destroy
				AndMask	= And maks
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
void OBJS_DestroyListObjsOfAType(OBJ_LIST *OL,U32 Type,U32 AndMask)
{
	OBJ_STRUCT *O;

	O=OL->Head;

	while (O)
		{
		OBJ_STRUCT *	NextO;

		NextO=O->Next;

		if (((O->ID)&AndMask)==Type)
			OBJS_DestroyObj(O);

		O=NextO;
		}
}

/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	OBJ_STRUCT *OBJS_DestroyObj(OBJ_STRUCT *O)
	Purpose:	Destroy an object
	Params:		O	->	Obj to destroy
	Returns:	-> to what was next in list
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
OBJ_STRUCT *OBJS_DestroyObj(OBJ_STRUCT *O)
{
	MHANDLE			ObjHandle;
	OBJ_STRUCT *	RetObj;
	BOOL			GalRet;

	ObjHandle=O->MemHandle;

	RetObj=O->Next;

	if (O->OTI->Destructor)
		O->OTI->Destructor(O);

	OBJS_DetachFromList(&O->OL->Head,O);

	O->Next=NULL;			/* Handy for debugging */
	O->Prev=NULL;

	GalRet=GAL_Free(ObjHandle);
	ASSERT(GalRet);

	ObjsAlloced--;

	return RetObj;
}

/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	void OBJS_IterateAllObjs(U32 Type,U32 AndMask,void (*CallBack)(OBJ_STRUCT *O))
	Purpose:	Go through all display lists and do a callback for objs
				of a certain type.
				if (O->ID&AndMask)==Type then obj is callbacked
	Params:		Type	= Type of objs to callback
				AndMask	= And maks
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
void OBJS_IterateAllObjs(U32 Type,U32 AndMask,void (*CallBack)(OBJ_STRUCT *O))
{
	OBJ_LIST *ThisList;

	ThisList=ListOfObjLists;

	while (ThisList)
		{
		OBJS_IterateListObjs(ThisList,Type,AndMask,CallBack);
		ThisList=ThisList->Next;
		}
}

/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	void OBJS_IterateListObjs(OBJ_LIST *OL,U32 Type,U32 AndMask,void (*CallBack)(OBJ_STRUCT *O))
	Purpose:	Go through a single display list and do a callback for objs
				of a certain type.
				if (O->ID&AndMask)==Type then obj is callbacked
	Params:		Type	= Type of objs to callback
				AndMask	= And maks
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
void OBJS_IterateListObjs(OBJ_LIST *OL,U32 Type,U32 AndMask,void (*CallBack)(OBJ_STRUCT *O))
{
	OBJ_STRUCT *O;

	O=OL->Head;

	while (O)
		{
		OBJ_STRUCT  *	NextO;

		NextO=O->Next;

		if (((O->ID)&AndMask)==Type)
			CallBack(O);

		O=NextO;
		}
}

/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Set the World's XY 
	陳陳陳陳陳陳陳陳陳 */
void OBJS_SetListXY(OBJ_LIST *OL,S32 X,S32 Y)
{
	OBJS_SetListX(OL,X);
	OBJS_SetListY(OL,Y);
}

/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Set the World's X
	陳陳陳陳陳陳陳陳陳 */
void OBJS_SetListX(OBJ_LIST *OL,S32 X)
{
	OL->X=X;
}

/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Set the World's X
	陳陳陳陳陳陳陳陳陳 */
void OBJS_SetListY(OBJ_LIST *OL,S32 Y)
{
	OL->Y=Y;
}

/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Make a Priority level of sprites undestroyable
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 */
void OBJS_MakeListImmortal(OBJ_LIST *OL)
{
	OL->Killable=FALSE;
}

/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Make a Priority level of sprites Destroyable
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
void OBJS_MakeListMortal(OBJ_LIST *OL)
{
	OL->Killable=TRUE;
}

/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:		void MKOBJS_NoVels(void)
	Purpose:		Say no vels to be addes
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
BOOL OBJS_NoAddVels(void)
{
	BOOL	OldVels;

	OldVels=AddVels;
	AddVels=FALSE;
	return(OldVels);
}	

/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	void MKOBJS_AddVels(void)
	Purpose:	Say vels to be addes
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
BOOL OBJS_AddVels(void)
{
	BOOL	OldVels;

	OldVels=AddVels;
	AddVels=TRUE;
	return(OldVels);
}	

/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	void OBJS_MakeListInvisible(OBJ_LIST *OL)
	Purpose:	Mark this list as invisble
	Params:		OL - > List to mark
	Returns:	Previous visible / invisible state of list
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
BOOL OBJS_MakeListInvisible(OBJ_LIST *OL)
{
	BOOL	OldState;
	OldState=OL->Visible;
	OL->Visible=FALSE;
	return(OldState);
}	

/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	void OBJS_MakeListInvisible(OBJ_LIST *OL)
	Purpose:	Mark this list as visble
	Params:		OL - > List to mark
	Returns:	Previous visible / invisible state of list
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
BOOL OBJS_MakeListVisible(OBJ_LIST *OL)
{
	BOOL	OldState;
	OldState=OL->Visible;
	OL->Visible=TRUE;
	return(OldState);
}

/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Make a Priority level of sprites Invisible
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?*/
BOOL OBJS_GetVelState(void)
{
	return AddVels;
}	

/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	BOOL OBJS_SetVelState(BOOL NewState)
	Purpose:	Set wether to add vels
	Params:		Newstate	=	
	Returns:	Previous addvel state of list
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
BOOL OBJS_SetVelState(BOOL NewState)
{
	BOOL	OldState;

	OldState=AddVels;
	AddVels=NewState;
	return(OldState);
}	


/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	void OBJS_SetSortCompare(OBJ_LIST *OL,void (*CompRout)(OBJ_STRUCT *O1,OBJ_STRUCT *O1))
	Purpose:	Set the call back used in the sort routine
	Params:		OL -> 			List to set sort routine for
				CompRout ->		Function to do the compare
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
void OBJS_SetSortCompare(OBJ_LIST *OL,BOOL (*CompRout)(OBJ_STRUCT *O1,OBJ_STRUCT *O2))
{
	OL->SortCompare=CompRout;
}

/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	int OBJS_GetWidth(OBJ_STRUCT *O)
	Purpose:	Get an objs width
	Params:		O	->		Obj 2 get width off
	Returns:	Width, zero if no width routine
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
int OBJS_GetWidth(OBJ_STRUCT *O)
{
	if (O->OTI->GetWidth)
		return(O->OTI->GetWidth(O));
	else
		return(0);
}	

/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	int OBJS_GetWidth(OBJ_STRUCT *O)
	Purpose:	Get an objs width
	Params:		O	->		Obj 2 get width off
	Returns:	Width, zero if no width routine
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
int OBJS_GetHeight(OBJ_STRUCT *O)
{
	if (O->OTI->GetHeight)
		return(O->OTI->GetHeight(O));
	else
		return(0);
}	

/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	int OBJS_GetXOff(OBJ_STRUCT *O)
	Purpose:	Get an objs X offset
	Params:		O	->		Obj 2 get width off
	Returns:	Width, zero if no width routine
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
int OBJS_GetXOff(OBJ_STRUCT *O)
{
	if (O->OTI->GetXOff)
		return(O->OTI->GetXOff(O));
	else
		return(0);
}	

/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	int OBJS_GetYOff(OBJ_STRUCT *O)
	Purpose:	Get an objs X offset
	Params:		O	->		Obj 2 get width off
	Returns:	Width, zero if no width routine
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
int OBJS_GetYOff(OBJ_STRUCT *O)
{
	if (O->OTI->GetYOff)
		return(O->OTI->GetYOff(O));
	else
		return(0);
}	

/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	int OBJS_GetYOff(OBJ_STRUCT *O)
	Purpose:	Get an objs X offset
	Params:		O	->		Obj 2 get width off
	Returns:	Width, zero if no width routine
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
int OBJS_GetPal(OBJ_STRUCT *O)
{
	if (O->OTI->GetPal)
		return(O->OTI->GetPal(O));
	else
		return(0);
}	

/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	static void SortList(OBJ_LIST *OL)
	Purpose:	Sort this list
	Params:		OL	->		List to sort
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
static void SortList(OBJ_LIST *OL)
{
	if (OL->SortCompare && OL->Head && OL->Head->Next)
		{
		BOOL		DidSwap;

		do
			{
			OBJ_STRUCT	*	O;
			OBJ_STRUCT	*	NO;

			O=OL->Head;

			DidSwap=FALSE;

			do
				{
				NO=O->Next;

				if (OL->SortCompare(O,NO))
					{
					O->Next=NO->Next;
					NO->Next=O;

					NO->Prev=O->Prev;
					O->Prev=NO;

					if (NO->Prev)
						NO->Prev->Next=NO;
					else
						OL->Head=NO;

					if (O->Next)
						O->Next->Prev=O;
		
					DidSwap=TRUE;
					}
				else
					O=O->Next;
				}
			while (O->Next);
			}
		while(DidSwap);

		}
}


/*	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	Function:	int	OBJS_GetObjsAlloced(void)
	Purpose:	Tell us how many objects are out
	陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳? */
int	OBJS_GetObjsAlloced(void)
{
	return(ObjsAlloced);
}

/* 陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳?
	ends */
