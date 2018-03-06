// SetTxtDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Hello_World.h"
#include "SetTxtDlg.h"
#include "afxdialogex.h"


// CSetTxtDlg dialog

IMPLEMENT_DYNAMIC(CSetTxtDlg, CDialog)

CSetTxtDlg::CSetTxtDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_txt(_T(""))
{

}

CSetTxtDlg::~CSetTxtDlg()
{
}

void CSetTxtDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_Txt, m_txt);
}


BEGIN_MESSAGE_MAP(CSetTxtDlg, CDialog)
END_MESSAGE_MAP()


// CSetTxtDlg message handlers
