#include "stdafx.h"
#include "GameManager.h"


GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}

//////////////////////////////////////////////////////////////////////////
// ������ �ڿ� �ʱ�ȭ�� �̰�����
//////////////////////////////////////////////////////////////////////////
bool GameManager::Init() const
{
	//////////////////////////////////////////////////////////////////////////
	// �ϴ��� �ڵ���� ����ڵ尡 �ʿ��մϴ�.
	//////////////////////////////////////////////////////////////////////////

	// ���� �ʱ�ȭ
	// SoundManager::GetInstance();

	// ������ ���� �� �ʱ�ȭ
	// Renderer::GetInstance()->Init();

	// ���ҽ� �ε� �� �ʱ�ȭ
	// ���ҽ��� ������ ���� �����ؾ� ��
	// ResourceManager::GetInstance()->Init();

	// UI �Ŵ��� ���� �� �ʱ�ȭ
	// UIManager::GetInstance()->Init();

	// �� ���� �� �ʱ�ȭ
	// SceneManager::GetInstance()->Init();
	// SceneManager::GetInstance()->ChangeScene(SCENE_LOAD);

	// ��Ʈ��ũ ���� �� �ʱ�ȭ
	// NetworkManager::GetInstance()->Init();
	// NetworkManager::GetInstance()->Connect();

	// ī�޶� �ʱ�ȭ
	// ī�޶� �ʱ�ȭ�� ���� ���� ��Ŷ�� �޴� �κ����� �����ϴ�.

	// �ؽ�Ʈ �Ŵ���
	// Ÿ�̸�
	// �÷��̾�

	return true;
}

//////////////////////////////////////////////////////////////////////////
// ������Ʈ �κ�
//////////////////////////////////////////////////////////////////////////
bool GameManager::Process() const
{
	if (!m_Continue)
	{
		return false;
	}
	// ������Ʈ

	// Timer::GetInstance()->Tick();
	// InputDispatcher::GetInstance()->DispatchKeyInput();
	// NetworkManager::GetInstance()->ProcessPacket();

	// CameraController::GetInstance()->Update();
	// SceneManager::GetInstance()->Update();

	// UIManager::GetInstance()->Update();

	{
		// ���� ����
		// DummyRender dRender;

		// SceneManager::GetInstance()->Render();
		// UIManager::GetInstance()->Render();
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////
// �ڿ� ������ �̰����� �մϴ�.
//////////////////////////////////////////////////////////////////////////
void GameManager::Destroy() const
{
	// �ؽ�Ʈ �Ŵ��� ����
	// TextManager::Release();

	// ��Ʈ��ũ���� ���� �����ϴ� �κ��� �����Ƿ� ���� ���� �����ϸ� �� ��
	// NetworkManager::GetInstance()->Destroy();
	// NetworkManager::Release();

	// UI �Ŵ��� ����
	// UIManager::GetInstance()->Destroy();
	// UIManager::Release();

	// �� ����
	// SceneManager::GetInstance()->Destroy();
	// SceneManager::Release();

	// �浹 üũ �Ŵ����� ���Ŵ������� ���߿� ����
	// CollisionManager::GetInstance()->ClearList();
	// CollisionManager::Release();

	// ���ҽ� ����
	// ResourceManager::GetInstance()->Destroy();
	// ResourceManager::Release();

	// ������ ����
	// Renderer::GetInstance()->Destroy();
	// Renderer::Release();

	// CameraController::Release();
	// InputDispatcher::Release();

	// Timer::Release();
	// PlayerManager::Release();
	// MouseManager::Release();

	// SoundManager::Release();
}
