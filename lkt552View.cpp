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


void CLkt552View::Ontogray() 
{
	// TODO: Add your command handler code here
	if (lpBitsInfo==NULL) return;
	int bitBitCount = lpBitsInfo->bmiHeader.biBitCount;
	if(bitBitCount!=24) return;
	int w = lpBitsInfo->bmiHeader.biWidth;
	int h = lpBitsInfo->bmiHeader.biHeight;
	int lineBytes = (w*bitBitCount+31)/32*4;
	int gray_lineBytes = (w*8+31)/32*4;
	int size = 40+4*256+gray_lineBytes*h;
	BITMAPINFO* gray_bf = (BITMAPINFO*)malloc(size);
	BYTE *gray_bits =(BYTE*)&gray_bf->bmiColors[256];
	gray_bf->bmiHeader = lpBitsInfo->bmiHeader;
	gray_bf->bmiHeader.biBitCount = 8;
	gray_bf->bmiHeader.biClrUsed = 256;
	for(int k=0;k<256;k++){
		gray_bf->bmiColors[k].rgbBlue=gray_bf->bmiColors[k].rgbGreen=gray_bf->bmiColors[k].rgbRed=k;
		gray_bf->bmiColors[k].rgbReserved=255;
	}
	BYTE*B,*G,*R;
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++){
				B =(BYTE*)lpBitsInfo->bmiColors+(h-i-1)*lineBytes+j*3;
				G = B+1;
				R = G+1;
				BYTE avg = (*B+*G+*R)/3;
				*B=*R=*G=avg;
				*(gray_bits+(h-i-1)*gray_lineBytes+j)=avg;
	}	 
	lpBitsInfo = gray_bf;
	Invalidate();
}
