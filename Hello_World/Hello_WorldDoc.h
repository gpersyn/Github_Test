
// Hello_WorldDoc.h : interface of the CHello_WorldDoc class
//


#pragma once


class CHello_WorldDoc : public CDocument
{
protected: // create from serialization only
	CHello_WorldDoc();
	DECLARE_DYNCREATE(CHello_WorldDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	CString GetTxt() { return m_txt;  } //Get function for m_txt since its private

	virtual ~CHello_WorldDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnDrawChangetext();

private: 
	CString m_txt;
};
