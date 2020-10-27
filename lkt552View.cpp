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
	ON_COMMAND(bmp_to_gray, Ontogray)
	ON_WM_LBUTTONDOWN()
<<<<<<< HEAD
	ON_WM_MOUSEMOVE()
	ON_UPDATE_COMMAND_UI(bmp_to_gray, OnUpdatetogray)
=======
>>>>>>> dea7637321101d4ad1814172b15e7c7319dc1507
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
extern BITMAPINFO* lpBitsInfo;

void CLkt552View::OnDraw(CDC* pDC)
{
	CLkt552Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	if(lpBitsInfo!=NULL){
	LPVOID lpBits = (LPVOID)&lpBitsInfo->bmiColors[lpBitsInfo->bmiHeader.biClrUsed];
	long w = lpBitsInfo->bmiHeader.biWidth;
	long h = lpBitsInfo->bmiHeader.biHeight;
	StretchDIBits(
		pDC->GetSafeHdc(),
		0,0,w,h,
		0,0,w,h,
		lpBits,lpBitsInfo,
		DIB_RGB_COLORS,SRCCOPY);
	}
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

void gray();
void CLkt552View::Ontogray() 
{
	// TODO: Add your command handler code here
	gray();
	Invalidate();
}
<<<<<<< HEAD
char* pixel(int i,int j);
void CLkt552View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//pixel(point.y,point.x);
	CScrollView::OnLButtonDown(nFlags, point);
}

void CLkt552View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (lpBitsInfo!=NULL){
	char xy[81];
	//memset(xy,0,100);
	sprintf(xy,"x:%d y:%d   ",point.x,point.y);
	char*rgb;
	rgb = pixel(point.y,point.x);
	if(rgb!=NULL)
	{
	strcat(xy,rgb);
	((CFrameWnd*)GetParent())->SetMessageText(xy);
	}
	}

	CScrollView::OnMouseMove(nFlags, point);


}

void CLkt552View::OnUpdatetogray(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (lpBitsInfo==NULL){
		pCmdUI->Enable(0);
		return;
	}
	int bitBitCount = lpBitsInfo->bmiHeader.biBitCount;
	pCmdUI->Enable(bitBitCount==24);
	
}
=======
void pixel(int i,int j);
void CLkt552View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	pixel(point.y,point.x);
	CScrollView::OnLButtonDown(nFlags, point);
}
>>>>>>> dea7637321101d4ad1814172b15e7c7319dc1507
