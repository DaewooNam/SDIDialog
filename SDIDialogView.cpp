
// SDIDialogView.cpp: CSDIDialogView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "SDIDialog.h"
#endif

#include "SDIDialogDoc.h"
#include "SDIDialogView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSDIDialogView

IMPLEMENT_DYNCREATE(CSDIDialogView, CView)

BEGIN_MESSAGE_MAP(CSDIDialogView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSDIDialogView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CSDIDialogView 생성/소멸

CSDIDialogView::CSDIDialogView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CSDIDialogView::~CSDIDialogView()
{
}

BOOL CSDIDialogView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CSDIDialogView 그리기

void CSDIDialogView::OnDraw(CDC* /*pDC*/)
{
	CSDIDialogDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CSDIDialogView 인쇄


void CSDIDialogView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSDIDialogView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CSDIDialogView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CSDIDialogView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CSDIDialogView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSDIDialogView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSDIDialogView 진단

#ifdef _DEBUG
void CSDIDialogView::AssertValid() const
{
	CView::AssertValid();
}

void CSDIDialogView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSDIDialogDoc* CSDIDialogView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDIDialogDoc)));
	return (CSDIDialogDoc*)m_pDocument;
}
#endif //_DEBUG


// CSDIDialogView 메시지 처리기




void CSDIDialogView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	m_Dlg.Create(IDD_DIALOG1, this);
	m_Dlg.SetWindowPos(NULL, 0, 0, 0, 0, SWP_SHOWWINDOW | SWP_NOSIZE);

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
}
