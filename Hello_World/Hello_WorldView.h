
// Hello_WorldView.h : interface of the CHello_WorldView class
//

#pragma once

constexpr UINT IDC_BUTTON1{ 101 };

class CHello_WorldView : public CView
{
protected: // create from serialization only
	CHello_WorldView();
	DECLARE_DYNCREATE(CHello_WorldView)

// Attributes
public:
	CHello_WorldDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CHello_WorldView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawCircle();

private:
	bool m_drawCirle{true}; //If not circle then rectangle
	CButton m_button;

public:
	afx_msg void OnDrawRectangle();
	afx_msg void OnUpdateDrawCircle(CCmdUI *pCmdUI);
	afx_msg void OnUpdateDrawRectangle(CCmdUI *pCmdUI);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // debug version in Hello_WorldView.cpp
inline CHello_WorldDoc* CHello_WorldView::GetDocument() const
   { return reinterpret_cast<CHello_WorldDoc*>(m_pDocument); }
#endif

