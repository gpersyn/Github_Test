
// Hello_WorldView.cpp : implementation of the CHello_WorldView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Hello_World.h"
#endif

#include "Hello_WorldDoc.h"
#include "Hello_WorldView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHello_WorldView

IMPLEMENT_DYNCREATE(CHello_WorldView, CView)

BEGIN_MESSAGE_MAP(CHello_WorldView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CHello_WorldView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DRAW_CIRCLE, &CHello_WorldView::OnDrawCircle)
	ON_COMMAND(ID_DRAW_RECTANGLE, &CHello_WorldView::OnDrawRectangle)
	ON_UPDATE_COMMAND_UI(ID_DRAW_CIRCLE, &CHello_WorldView::OnUpdateDrawCircle)
	ON_UPDATE_COMMAND_UI(ID_DRAW_RECTANGLE, &CHello_WorldView::OnUpdateDrawRectangle)
END_MESSAGE_MAP()

// CHello_WorldView construction/destruction

CHello_WorldView::CHello_WorldView()
{
	// TODO: add construction code here

}

CHello_WorldView::~CHello_WorldView()
{
}

BOOL CHello_WorldView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CHello_WorldView drawing

void CHello_WorldView::OnDraw(CDC* pDC)
{
	CHello_WorldDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here 
	pDC->TextOutW(600,400, _T("Hello World!"));
	if (m_drawCirle)
		pDC->Ellipse(100, 100, 300, 300);
	else
		pDC->Rectangle(100,100,400,600);
}


// CHello_WorldView printing


void CHello_WorldView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CHello_WorldView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHello_WorldView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHello_WorldView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CHello_WorldView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CHello_WorldView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CHello_WorldView diagnostics

#ifdef _DEBUG
void CHello_WorldView::AssertValid() const
{
	CView::AssertValid();
}

void CHello_WorldView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHello_WorldDoc* CHello_WorldView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHello_WorldDoc)));
	return (CHello_WorldDoc*)m_pDocument;
}
#endif //_DEBUG


// CHello_WorldView message handlers


void CHello_WorldView::OnDrawCircle()
{
	// TODO: Add your command handler code here
	m_drawCirle = true;
	Invalidate();
	UpdateWindow();
}


void CHello_WorldView::OnDrawRectangle()
{
	// TODO: Add your command handler code here
	m_drawCirle = false;
	Invalidate();
	UpdateWindow();
}


void CHello_WorldView::OnUpdateDrawCircle(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(!m_drawCirle);
}


void CHello_WorldView::OnUpdateDrawRectangle(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_drawCirle);
}
