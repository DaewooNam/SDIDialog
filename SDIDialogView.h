
// SDIDialogView.h: CSDIDialogView 클래스의 인터페이스
//

#pragma once

#include "TestDialog.h"

class CSDIDialogView : public CView
{
protected: // serialization에서만 만들어집니다.
	CSDIDialogView();
	DECLARE_DYNCREATE(CSDIDialogView)

// 특성입니다.
public:
	CSDIDialogDoc* GetDocument() const;

// 작업입니다.
public:

	TestDialog		m_Dlg;

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CSDIDialogView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // SDIDialogView.cpp의 디버그 버전
inline CSDIDialogDoc* CSDIDialogView::GetDocument() const
   { return reinterpret_cast<CSDIDialogDoc*>(m_pDocument); }
#endif

