// FinalDialog.cpp: файл реализации
//

#include "pch.h"
#include "Snake.h"
#include "afxdialogex.h"
#include "FinalDialog.h"


// Диалоговое окно FinalDialog

IMPLEMENT_DYNAMIC(FinalDialog, CDialogEx)

FinalDialog::FinalDialog(int score, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent), score(score)
{
}

FinalDialog::~FinalDialog()
{
}

void FinalDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FinalDialog, CDialogEx)
	ON_WM_PAINT()
	ON_WM_ACTIVATE()
	ON_COMMAND(IDD_DIALOG2, &FinalDialog::OnIddDialog2)
END_MESSAGE_MAP()


void FinalDialog::OnPaint()
{
    CPaintDC dc(this);

    m_fontGameOver.CreatePointFont(300, _T("Arial"));
    m_colorGameOver = RGB(255, 0, 0);

    m_fontScore.CreatePointFont(200, _T("Arial"));
    m_colorScore = RGB(229, 200, 130);

    m_strScore.Format(_T("Результат: %d"), score);

    CFont* pOldFont = dc.SelectObject(&m_fontGameOver);
    dc.SetTextColor(m_colorGameOver);
    dc.SetBkMode(TRANSPARENT);

    CRect rectGameOver;
    GetClientRect(&rectGameOver);
    rectGameOver.top = 20;
    rectGameOver.bottom = 100;
    dc.DrawText(_T("Конец игры"), &rectGameOver, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    dc.SelectObject(&m_fontScore);
    dc.SetTextColor(m_colorScore);

    CRect rectScore;
    GetClientRect(&rectScore);
    rectScore.top = 100;
    rectScore.bottom = 180;
    dc.DrawText(m_strScore, &rectScore, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    dc.SelectObject(pOldFont);
}


void FinalDialog::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	CDialogEx::OnActivate(nState, pWndOther, bMinimized);
}


void FinalDialog::OnIddDialog2()
{
}
