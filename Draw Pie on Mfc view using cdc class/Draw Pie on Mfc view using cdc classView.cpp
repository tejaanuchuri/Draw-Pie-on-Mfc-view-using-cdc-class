
// Draw Pie on Mfc view using cdc classView.cpp : implementation of the CDrawPieonMfcviewusingcdcclassView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Draw Pie on Mfc view using cdc class.h"
#endif

#include "Draw Pie on Mfc view using cdc classDoc.h"
#include "Draw Pie on Mfc view using cdc classView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawPieonMfcviewusingcdcclassView

IMPLEMENT_DYNCREATE(CDrawPieonMfcviewusingcdcclassView, CView)

BEGIN_MESSAGE_MAP(CDrawPieonMfcviewusingcdcclassView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDrawPieonMfcviewusingcdcclassView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CDrawPieonMfcviewusingcdcclassView construction/destruction

CDrawPieonMfcviewusingcdcclassView::CDrawPieonMfcviewusingcdcclassView() noexcept
{
	// TODO: add construction code here

}

CDrawPieonMfcviewusingcdcclassView::~CDrawPieonMfcviewusingcdcclassView()
{
}

BOOL CDrawPieonMfcviewusingcdcclassView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CDrawPieonMfcviewusingcdcclassView drawing

void CDrawPieonMfcviewusingcdcclassView::OnDraw(CDC* pDC)
{
	CDrawPieonMfcviewusingcdcclassDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Pie(40, 20, 226, 144, 155, 32, 202, 115);

	// TODO: add draw code for native data here
}


// CDrawPieonMfcviewusingcdcclassView printing


void CDrawPieonMfcviewusingcdcclassView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDrawPieonMfcviewusingcdcclassView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDrawPieonMfcviewusingcdcclassView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDrawPieonMfcviewusingcdcclassView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CDrawPieonMfcviewusingcdcclassView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDrawPieonMfcviewusingcdcclassView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDrawPieonMfcviewusingcdcclassView diagnostics

#ifdef _DEBUG
void CDrawPieonMfcviewusingcdcclassView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawPieonMfcviewusingcdcclassView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawPieonMfcviewusingcdcclassDoc* CDrawPieonMfcviewusingcdcclassView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawPieonMfcviewusingcdcclassDoc)));
	return (CDrawPieonMfcviewusingcdcclassDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawPieonMfcviewusingcdcclassView message handlers
