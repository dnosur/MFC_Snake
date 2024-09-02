
// SnakeDlg.h: файл заголовка
//

#pragma once
#include "Field.h"
#include "KeyRefs.h"

#include "FieldSetting.h"
#include "FinalDialog.h"

class Field;

// Диалоговое окно CSnakeDlg
class CSnakeDlg : public CDialogEx
{
// Создание
public:
	CSnakeDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SNAKE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	CStatic score;

	CString scoreText;
	CString dieText;

	CFont scoreFont;
	CFont dieFont;

	CRect clientRect;
	Field field;

	bool gameStart;

	void Start();
	void Die();

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};
