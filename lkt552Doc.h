// lkt552Doc.h : interface of the CLkt552Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LKT552DOC_H__BDCA99CA_5F02_4B61_B7F7_C739869E6A9F__INCLUDED_)
#define AFX_LKT552DOC_H__BDCA99CA_5F02_4B61_B7F7_C739869E6A9F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLkt552Doc : public CDocument
{
protected: // create from serialization only
	CLkt552Doc();
	DECLARE_DYNCREATE(CLkt552Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLkt552Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLkt552Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLkt552Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LKT552DOC_H__BDCA99CA_5F02_4B61_B7F7_C739869E6A9F__INCLUDED_)
