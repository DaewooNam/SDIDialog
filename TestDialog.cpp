// TestDialog.cpp: 구현 파일
//

#include "stdafx.h"
#include "SDIDialog.h"
#include "TestDialog.h"
#include "afxdialogex.h"


// TestDialog 대화 상자

IMPLEMENT_DYNAMIC(TestDialog, CDialogEx)

TestDialog::TestDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

TestDialog::~TestDialog()
{
}

void TestDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TestDialog, CDialogEx)
END_MESSAGE_MAP()


// TestDialog 메시지 처리기
