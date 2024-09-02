
// Snake.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CSnakeApp:
// Сведения о реализации этого класса: Snake.cpp
//

class CSnakeApp : public CWinApp
{
public:
	CSnakeApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CSnakeApp theApp;