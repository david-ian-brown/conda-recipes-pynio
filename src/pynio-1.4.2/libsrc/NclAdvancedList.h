/*
 *      $Id: NclList.h,v 1.4 2010-04-14 21:29:47 huangwei Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  2011			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		NclAdvancedList.h
 *
 *	Author:		Wei Huang
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Wed Jun  1 10:10:19 MDT 2011
 *
 *	Description:	
 */
#ifndef NclAdvancedList_h
#define NclAdvancedList_h
#include <assert.h>

#include <ncarg/hlu/hlu.h>
#include <ncarg/hlu/NresDB.h>
#include <ncarg/hlu/Callbacks.h>
#include "defs.h"
#include "NclDataDefs.h"
#include "Symbol.h"
#include "NclData.h"
#include "NclList.h"
#include "NclMultiDValData.h"
#include "DataSupport.h"
#include "ListSupport.h"
#include "NclVar.h"
#include "NclHLUVar.h"
#include "NclFileVar.h"
#include "VarSupport.h"

#define NCL_MIN_LIST_ITEMS	8

typedef struct _NclAdvancedListRec *NclAdvancedList;
typedef struct _NclAdvancedListClassRec *NclAdvancedListClass;

typedef NhlErrorTypes (*NclListAppendFunction)(NclObj thelistobj, NclObj theobj);

typedef struct _NclAdvancedListClassPart
{
    NclListAppendFunction append;
} NclAdvancedListClassPart;

typedef struct _NclAdvancedListPart
{
    NclQuark           name;
    NclBasicDataTypes  type;
    struct _NclSymbol *thesym;

    int max_elem;
    int n_elem;
    int state;

    NclListObjList **item;
} NclAdvancedListPart;

typedef struct _NclAdvancedListClassRec
{
    NclObjClassPart     obj_class;
    NclListClassPart    list_class;
    NclAdvancedListClassPart advancedlist_class;
} NclAdvancedListClassRec;

typedef struct _NclAdvancedListRec
{
    NclObjPart     obj;
    NclListPart    list;
    NclAdvancedListPart advancedlist;
} NclAdvancedListRec;

extern NclObjClass nclAdvancedListClass;

extern NclAdvancedListClassRec nclAdvancedListClassRec;

extern struct _NclObjRec *_NclAdvancedListCreate(struct _NclObjRec      *inst,
                                            struct _NclObjClassRec *theclass,
                                            NclObjTypes             obj_type,
                                            unsigned int            obj_type_mask,
                                            ng_size_t               listsize,
                                            int                     list_type);

#endif /* NclAdvancedList_h */

