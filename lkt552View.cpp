// lkt552View.cpp : implementation of the CLkt552View class
//

#include "stdafx.h"
#include "lkt552.h"

#include "lkt552Doc.h"
#include "lkt552View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLkt552View

IMPLEMENT_DYNCREATE(CLkt552View, CScrollView)

BEGIN_MESSAGE_MAP(CLkt552View, CScrollView)
	//{{AFX_MSG_MAP(CLkt552View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLkt552View construction/destruction

CLkt552View::CLkt552View()
{
	// TODO: add construction code here

}

CLkt552View::~CLkt552View()
{
}

BOOL CLkt552View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLkt552View drawing

void CLkt552View::OnDraw(CDC* pDC)
{
	CLkt552Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CLkt552View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 1200;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/////////////////////////////////////////////////////////////////////////////
// CLkt552View printing

BOOL CLkt552View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLkt552View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLkt552View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CLkt552View diagnostics

#ifdef _DEBUG
void CLkt552View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CLkt552View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CLkt552Doc* CLkt552View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLkt552Doc)));
	return (CLkt552Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLkt552View message handlers

