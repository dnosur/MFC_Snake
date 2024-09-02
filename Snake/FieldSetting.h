#pragma once
#include "afxdialogex.h"


// Диалоговое окно FieldSetting

class FieldSetting : public CDialogEx
{
	DECLARE_DYNAMIC(FieldSetting)

public:
	FieldSetting(int width, int height, CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~FieldSetting();

	int width, height, speed;
	bool isSuccess;

	void SetSlider(int& value, int sliderId, int staticId, int sliderSize = 30);
	void SetSliderPos(int value, int sliderId, int staticId, int sliderSize = 30);

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMCustomdrawSlider2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnNMCustomdrawSlider3(NMHDR* pNMHDR, LRESULT* pResult);
};
