/***********************/
/*** Layer Collision ***/
/***********************/

#ifndef	__LAYER_COLLISION_HEADER__
#define	__LAYER_COLLISION_HEADER__

#include	"Layer.h"

/*****************************************************************************/
class	CCore;
//class	CMapEditView;
class	CLayerCollision : public CLayerTile
{

public:
		CLayerCollision(int SubType,int Width,int Height);					// New Layer
		CLayerCollision(CFile *File,int Version);							// Load Layer
		~CLayerCollision();

		int				GetType()			{return(LAYER_TYPE_COLLISION);}

		void			InitGUI(CCore *Core);
		void			UpdateGUI(CCore *Core);

		void			Load(CFile *File,int Version);
		void			Save(CFile *File);

		void			Export(CCore *Core,CExport &Exp);

// Functions
		void			DeleteSet(int Set);
		void			RemapSet(int OrigSet,int NewSet);
protected:

};

/*****************************************************************************/
#endif
