// lkt552Doc.cpp : implementation of the CLkt552Doc class
//

#include "stdafx.h"
#include "lkt552.h"

#include "lkt552Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLkt552Doc

IMPLEMENT_DYNCREATE(CLkt552Doc, CDocument)

BEGIN_MESSAGE_MAP(CLkt552Doc, CDocument)
	//{{AFX_MSG_MAP(CLkt552Doc)
	ON_COMMAND(bmp_to_gray, Ontogray)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLkt552Doc construction/destruction

CLkt552Doc::CLkt552Doc()
{
	// TODO: add one-time construction code here

}

CLkt552Doc::~CLkt552Doc()
{
}

BOOL CLkt552Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLkt552Doc serialization

void CLkt552Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CLkt552Doc diagnostics

#ifdef _DEBUG
void CLkt552Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLkt552Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLkt552Doc commands
BOOL loadbitmap(char*bitmap);
BOOL CLkt552Doc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	loadbitmap((char*)lpszPathName);
	

	return TRUE;
}
extern BITMAPINFO* lpBitsInfo;
void CLkt552Doc::Ontogray() 
{
	// TODO: Add your command handler code here

}
