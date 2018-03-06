
// Hello_WorldDoc.cpp : implementation of the CHello_WorldDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Hello_World.h"
#endif

#include "Hello_WorldDoc.h"
#include "SetTxtDlg.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CHello_WorldDoc

IMPLEMENT_DYNCREATE(CHello_WorldDoc, CDocument)

BEGIN_MESSAGE_MAP(CHello_WorldDoc, CDocument)
	ON_COMMAND(ID_DRAW_CHANGETEXT, &CHello_WorldDoc::OnDrawChangetext)
END_MESSAGE_MAP()


// CHello_WorldDoc construction/destruction

CHello_WorldDoc::CHello_WorldDoc()
{
	// TODO: add one-time construction code here

}

CHello_WorldDoc::~CHello_WorldDoc()
{
}

BOOL CHello_WorldDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	m_txt.Empty();

	return TRUE;
}




// CHello_WorldDoc serialization

void CHello_WorldDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		ar << m_txt;
		SetModifiedFlag(false);
	}
	else
	{
		// TODO: add loading code here
		ar >> m_txt;
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CHello_WorldDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CHello_WorldDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CHello_WorldDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CHello_WorldDoc diagnostics

#ifdef _DEBUG
void CHello_WorldDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHello_WorldDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CHello_WorldDoc commands


void CHello_WorldDoc::OnDrawChangetext()
{
	// TODO: Add your command handler code here
	CSetTxtDlg dlg_SetTxt;
	//DdModal is on top of everything. Have to press cancle or ok
	if (dlg_SetTxt.DoModal() == IDOK ) { //If user presses ok
		//m_txt happen to have the same name but they are different variables
		m_txt = dlg_SetTxt.m_txt; //store value read from text box into document
		UpdateAllViews(NULL); //Redraws window
		SetModifiedFlag(true);
	}
}
