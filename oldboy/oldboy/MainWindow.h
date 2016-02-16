#pragma once

#include "RMmacro.h"

static const WCHAR WINDOW_NAME[] = L"Rhythm Match v0.125";
const int WINDOW_WIDTH = 1282; // 1280;
const int WINDOW_HEIGHT = 722; // 720;

class MainWindow
{
	SINGLETON(MainWindow);
private:
	MainWindow();
	~MainWindow();

public:
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	PCWSTR	ClassName() const { return WINDOW_NAME; }
	LRESULT	HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) const;

	int		RunGame() const;

	HWND	Window() const { return m_HandleOfWindow; }
	BOOL	Display(int nCmdShow) const { return ShowWindow(Window(), nCmdShow); }

	BOOL	Create(	PCWSTR lpWindowName, DWORD dwStyle, DWORD dwExStyle = 0,
					int x = CW_USEDEFAULT, int y = CW_USEDEFAULT,
					// int x = -1, int y = -1,
					int nWidth = WINDOW_WIDTH, int nHeight = WINDOW_HEIGHT,
					HWND hWndParent = 0, HMENU hMenu = 0 );
private:
	HWND	m_HandleOfWindow = nullptr;
	HACCEL	m_HandleOfAccelTable = nullptr;
};

