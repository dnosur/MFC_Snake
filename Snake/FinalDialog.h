#pragma once
#include "afxdialogex.h"


// Диалоговое окно FinalDialog

class FinalDialog : public CDialogEx
{
	DECLARE_DYNAMIC(FinalDialog)

	int score;

	CFont m_fontGameOver;
	CFont m_fontScore;
	COLORREF m_colorGameOver;
	COLORREF m_colorScore;
	CString m_strScore;
public:
	FinalDialog(int score, CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~FinalDialog();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnIddDialog2();
};
