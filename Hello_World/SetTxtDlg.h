#pragma once


// CSetTxtDlg dialog

class CSetTxtDlg : public CDialog
{
	DECLARE_DYNAMIC(CSetTxtDlg)

public:
	CSetTxtDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSetTxtDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_txt;
};
