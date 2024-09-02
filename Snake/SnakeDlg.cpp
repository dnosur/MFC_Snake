
// SnakeDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "Snake.h"
#include "SnakeDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
public:
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CSnakeDlg



CSnakeDlg::CSnakeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SNAKE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	gameStart = false;
}

void CSnakeDlg::DoDataExchange(CDataExchange* pDX)
{
	DDX_Control(pDX, IDC_SCORE_STATIC2, score);
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSnakeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


// Обработчики сообщений CSnakeDlg

void CSnakeDlg::Start()
{
	FieldSetting fieldSetting(field.GetWidth(), field.GetHeight());
	if (!fieldSetting.DoModal() || !fieldSetting.isSuccess) {
		EndDialog(IDOK);
		return;
	}

	field = Field(300, 300, 20, 20, fieldSetting.width, fieldSetting.height);
	scoreFont.CreatePointFont(400, _T("Arial"));
	SetTimer(1, fieldSetting.speed, NULL);
	gameStart = true;

	Invalidate();
}

void CSnakeDlg::Die()
{
	gameStart = false;
	FinalDialog final(field.GetSnake().GetSize());

	if (!final.DoModal()) {
		return;
	}

	EndDialog(IDOK);
}

BOOL CSnakeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	Start();

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CSnakeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CSnakeDlg::OnPaint()
{
	if (!gameStart) {
		return;
	}

	CPaintDC dc(this);
	GetClientRect(&clientRect);
	field.Draw(dc, clientRect);

	if (field.GetSnake().IsDie()) {
		Die();
		return;
	}

	scoreText.Format(_T("Score: %d"), field.GetSnake().GetSize());
	score.SetWindowText(scoreText);
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CSnakeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CSnakeDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	if (nIDEvent == 1 && gameStart) {
		return Invalidate();
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CSnakeDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == LEFT_KEY)
	{
		field.GetSnake().SetDirection(LEFT_DIRECTION);
		return;
	}

	if (nChar == UP_KEY)
	{
		field.GetSnake().SetDirection(UP_DIRECTION);
		return;
	}

	if (nChar == RIGHT_KEY)
	{
		field.GetSnake().SetDirection(RIGHT_DIRECTION);
		return;
	}

	if (nChar == DOWN_KEY)
	{
		field.GetSnake().SetDirection(DOWN_DIRECTION);
		return;
	}

	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}
