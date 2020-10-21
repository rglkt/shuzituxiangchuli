// lkt552View.h : interface of the CLkt552View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LKT552VIEW_H__941D190B_E632_4461_8FF3_5CB4746F8282__INCLUDED_)
#define AFX_LKT552VIEW_H__941D190B_E632_4461_8FF3_5CB4746F8282__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLkt552View : public CScrollView
{
protected: // create from serialization only
	CLkt552View();
	DECLARE_DYNCREATE(CLkt552View)

// Attributes
public:
	CLkt552Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLkt552View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLkt552View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLkt552View)
	afx_msg void Ontogray();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in lkt552View.cpp
inline CLkt552Doc* CLkt552View::GetDocument()
   { return (CLkt552Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LKT552VIEW_H__941D190B_E632_4461_8FF3_5CB4746F8282__INCLUDED_)
