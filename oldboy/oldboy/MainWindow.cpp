#include "stdafx.h"
#include "MainWindow.h"
#include "GameManager.h"


MainWindow::MainWindow()
{
}


MainWindow::~MainWindow()
{
}

LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) const
{
	switch (uMsg)
	{
	case WM_CREATE:
	{
		// SetTimer( MainWindow::GetInstance()->Window(), 337, 20, NULL );
	}
	return 0;

	/*
	case WM_SOCKET:
	{
		NetworkManager::GetInstance()->HandleMessage(wParam, lParam);
	}
	return 0;
	*/

	case WM_SIZE:
	{
		RECT rect;
		GetWindowRect(m_HandleOfWindow, &rect);

		LONG width = static_cast<LONG>(LOWORD(lParam));
		LONG height = static_cast<LONG>(HIWORD(lParam));

		// TASK - ������ ����
		// Renderer::GetInstance()->ResizeWindow(width, height);
		InvalidateRect(m_HandleOfWindow, NULL, FALSE);
		// Log( " ������ : %d %d \n", width, height );
	}
	return 0;

	case WM_DESTROY:
	{
		// TASK - ���ӸŴ��� �ۼ�
		/*
		if (GameManager::GetInstance()->Process())
		{
			// â�� ���� ���� �Ǿ��� ��(â �ݱ� ��)
			// ���⼭ �� �̺�Ʈ�� �߻����Ѽ� RunGame()�� �������� ���������� �ؾ�
			// �����ϰ� ���ҽ��� ���� �Ǹ鼭 �޸� ���� ���� �� �ִ�.
			GameManager::GetInstance()->Stop();
		}
		*/
		PostQuitMessage(0);
	}
	return 0;

	case WM_SYSKEYDOWN:
	case WM_KEYDOWN:
	{
		// TASK - Ű���� ��ǲ �Ŵ��� �ۼ�
		/*
		KeyInput key;
		key.SetKeyValue(static_cast<unsigned char>(wParam));
		key.SetKeyStatus(KeyStatusType::KEY_DOWN);
		if (InputDispatcher::GetInstance()->IsPressed(key))
		{
			key.SetKeyStatus(KeyStatusType::KEY_PRESSED);
		}

		InputDispatcher::GetInstance()->EventKeyInput(key);
		InputDispatcher::GetInstance()->DispatchKeyInput();
		*/
	}
	return 0;

	case WM_SYSKEYUP:
	case WM_KEYUP:
	{
		// TASK - Ű���� ��ǲ �Ŵ��� �ۼ�
		/*
		KeyInput key;
		key.SetKeyValue(static_cast<unsigned char>(wParam));
		key.SetKeyStatus(KeyStatusType::KEY_UP);

		InputDispatcher::GetInstance()->EventKeyInput(key);
		InputDispatcher::GetInstance()->DispatchKeyInput();
		*/
	}
	return 0;

	case WM_ERASEBKGND:
		return 1;

		//���콺 Ŭ�� ����
	case WM_LBUTTONDOWN:
	{
		// MouseManager::GetInstance()->SetLeftClick(true);
	}
	return 0;

	case WM_LBUTTONUP:
	{
		// MouseManager::GetInstance()->SetLeftClick(false);
		// SoundManager::GetInstance()->PlaySound(SOUND_SYSTEM_MOUSE_CLICK);
	}
	return 0;

	case WM_RBUTTONDOWN:
	{
		// MouseManager::GetInstance()->SetRightClick(true);
	}
	return 0;

	case WM_RBUTTONUP:
	{
		// MouseManager::GetInstance()->SetRightClick(false);
		// SoundManager::GetInstance()->PlaySound(SOUND_SYSTEM_MOUSE_CLICK);
	}
	return 0;

	case WM_MOVE:
	{
		int LocationX = LOWORD(lParam);
		int LocationY = HIWORD(lParam);
		// MouseManager::GetInstance()->SetWndLocation(LocationX, LocationY);
	}
	return 0;

	case WM_SETFOCUS:
	{
		BringWindowToTop(m_HandleOfWindow);
		// MouseManager::GetInstance()->SetGameCursorMode(true);
		ShowCursor(false);
	}
	return 0;

	case WM_KILLFOCUS:
	{
		/*
		InputDispatcher::GetInstance()->ClearList();
		MouseManager::GetInstance()->MoveHiddenCursorToMousePos();
		MouseManager::GetInstance()->SetGameCursorMode(false);
		*/
		ShowCursor(true);
	}
	return 0;

	case WM_MOUSEMOVE:
	{
		int MouseX = LOWORD(lParam);
		int MouseY = HIWORD(lParam);
		// MouseManager::GetInstance()->MoveMousePosition(MouseX, MouseY);
		// MouseManager::GetInstance()->MoveHiddenCursorToCenter();

	}
	return 0;

	case WM_MOUSEWHEEL:
	{
		// CameraController::GetInstance()->ChangeMouseZoomStatus(static_cast<short>(HIWORD(wParam)));
	}
	return 0;

	default:
		return DefWindowProc(m_HandleOfWindow, uMsg, wParam, lParam);
	}

	return 0;
}

int MainWindow::RunGame() const
{
	MSG msg = { 0, };

	if (false == GameManager::GetInstance()->Init())
	{
		// ��� ���� �̷��� �׳� �ξ�����,
		// Init() �Լ� ���ο��� ��� �ڵ� �������� �ɹ��ɷ� ���� �� �κ� ���� ��Ƽ� Release() ����� ��.
		GameManager::GetInstance()->Destroy();

		MessageBox(m_HandleOfWindow, L"Gama Manager Initialization Error", L"Game Manager Init Error!", MB_ICONINFORMATION | MB_OK);
		SendMessage(m_HandleOfWindow, WM_DESTROY, NULL, NULL);
		return false;
	}

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (false == GameManager::GetInstance()->Process())
		{
			GameManager::GetInstance()->Destroy();
			PostQuitMessage(0);
			break;
		}
	}
	
	return (int)msg.wParam;
}

BOOL MainWindow::Create(PCWSTR lpWindowName, DWORD dwStyle, DWORD dwExStyle /*= 0*/, int x /*= CW_USEDEFAULT*/, int y /*= CW_USEDEFAULT*/, int nWidth /*= WINDOW_WIDTH*/, int nHeight /*= WINDOW_HEIGHT*/, HWND hWndParent /*= 0*/, HMENU hMenu /*= 0 */)
{
	WNDCLASS wc = { 0 };

	wc.lpfnWndProc = WindowProc;
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpszClassName = ClassName();

	wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	RegisterClass(&wc);

	//////////////////////////////////////////////////////////////////////////
	// ȭ�� �ػ󵵸� �ҷ��ͼ� �ӽ÷� ��ü ȭ�� ���� ��
	//////////////////////////////////////////////////////////////////////////
	x = -1;
	y = -1;
	nWidth = GetSystemMetrics(SM_CXSCREEN) + 2;
	nHeight = GetSystemMetrics(SM_CYSCREEN) + 2;

	m_HandleOfWindow = CreateWindowEx(dwExStyle, ClassName(), lpWindowName, dwStyle,
		x, y, nWidth, nHeight, hWndParent, hMenu, GetModuleHandle(NULL), this);

	return (m_HandleOfWindow ? TRUE : FALSE);
}

LRESULT CALLBACK MainWindow::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	MainWindow * pThis = NULL;

	if (uMsg == WM_NCCREATE)
	{
		CREATESTRUCT* pCreate = (CREATESTRUCT*)lParam;
		pThis = (MainWindow*)pCreate->lpCreateParams;
		SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pThis);

		pThis->m_HandleOfWindow = hwnd;
	}
	else
	{
		pThis = (MainWindow*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
	}

	if (pThis)
	{
		return pThis->HandleMessage(uMsg, wParam, lParam);
	}
	else
	{
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}