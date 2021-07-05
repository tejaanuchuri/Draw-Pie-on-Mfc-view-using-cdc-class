
// Draw Pie on Mfc view using cdc classDoc.cpp : implementation of the CDrawPieonMfcviewusingcdcclassDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Draw Pie on Mfc view using cdc class.h"
#endif

#include "Draw Pie on Mfc view using cdc classDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDrawPieonMfcviewusingcdcclassDoc

IMPLEMENT_DYNCREATE(CDrawPieonMfcviewusingcdcclassDoc, CDocument)

BEGIN_MESSAGE_MAP(CDrawPieonMfcviewusingcdcclassDoc, CDocument)
END_MESSAGE_MAP()


// CDrawPieonMfcviewusingcdcclassDoc construction/destruction

CDrawPieonMfcviewusingcdcclassDoc::CDrawPieonMfcviewusingcdcclassDoc() noexcept
{
	// TODO: add one-time construction code here

}

CDrawPieonMfcviewusingcdcclassDoc::~CDrawPieonMfcviewusingcdcclassDoc()
{
}

BOOL CDrawPieonMfcviewusingcdcclassDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CDrawPieonMfcviewusingcdcclassDoc serialization

void CDrawPieonMfcviewusingcdcclassDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CDrawPieonMfcviewusingcdcclassDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CDrawPieonMfcviewusingcdcclassDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CDrawPieonMfcviewusingcdcclassDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CDrawPieonMfcviewusingcdcclassDoc diagnostics

#ifdef _DEBUG
void CDrawPieonMfcviewusingcdcclassDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDrawPieonMfcviewusingcdcclassDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDrawPieonMfcviewusingcdcclassDoc commands
