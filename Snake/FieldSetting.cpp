// FieldSetting.cpp: файл реализации
//

#include "pch.h"
#include "Snake.h"
#include "afxdialogex.h"
#include "FieldSetting.h"


// Диалоговое окно FieldSetting

IMPLEMENT_DYNAMIC(FieldSetting, CDialogEx)

FieldSetting::FieldSetting(int width, int height, CWnd* pParent /*=nullptr*/)
	: width(width), height(height), speed(800), CDialogEx(IDD_DIALOG1, pParent)
{
	isSuccess = false;
}

FieldSetting::~FieldSetting()
{
}

void FieldSetting::SetSlider(int& value, int sliderId, int staticId, int sliderSize)
{
	CSliderCtrl* slider = (CSliderCtrl*)GetDlgItem(sliderId);
	CStatic* label = (CStatic*)GetDlgItem(staticId);

	slider->SetRange(0, sliderSize);
	value = slider->GetPos();

	CString str;
	str.Format(L"%d", value);
	label->SetWindowTextW(str);
}

void FieldSetting::SetSliderPos(int value, int sliderId, int staticId, int sliderSize)
{
	CSliderCtrl* slider = (CSliderCtrl*)GetDlgItem(sliderId);
	CStatic* label = (CStatic*)GetDlgItem(staticId);

	slider->SetRange(0, sliderSize);
	slider->SetPos(value);

	CString str;
	str.Format(L"%d", value);
	label->SetWindowTextW(str);
}

void FieldSetting::DoDataExchange(CDataExchange* pDX)
{
	
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FieldSetting, CDialogEx)
	ON_WM_ACTIVATE()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &FieldSetting::OnNMCustomdrawSlider1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, &FieldSetting::OnNMCustomdrawSlider2)
	ON_BN_CLICKED(IDOK, &FieldSetting::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &FieldSetting::OnBnClickedCancel)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER3, &FieldSetting::OnNMCustomdrawSlider3)
END_MESSAGE_MAP()


// Обработчики сообщений FieldSetting


void FieldSetting::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	CDialogEx::OnActivate(nState, pWndOther, bMinimized);
	SetSliderPos(width, IDC_SLIDER1, IDC_WIDTH_STATIC);
	SetSliderPos(height, IDC_SLIDER2, IDC_HEIGHT_STATIC);
	SetSliderPos(speed, IDC_SLIDER3, IDC_SPEED_STATIC, 1000);
}


void FieldSetting::OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	SetSlider(width, IDC_SLIDER1, IDC_WIDTH_STATIC);
	*pResult = 0;
}


void FieldSetting::OnNMCustomdrawSlider2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	SetSlider(height, IDC_SLIDER2, IDC_HEIGHT_STATIC);
	*pResult = 0;
}


void FieldSetting::OnBnClickedOk()
{
	isSuccess = true;
	CDialogEx::OnOK();
}


void FieldSetting::OnBnClickedCancel()
{
	isSuccess = false;
	CDialogEx::OnCancel();
}


void FieldSetting::OnNMCustomdrawSlider3(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	SetSlider(speed, IDC_SLIDER3, IDC_SPEED_STATIC, 1000);
	*pResult = 0;
}
