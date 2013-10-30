#include "stdafx.h"
#include "oldboy.h"
#include "RMjudgeManager.h"
#include "RMobjectManager.h"
#include "RMobject.h"
#include "RMsound.h"

// CRMjudgeManager* CRMjudgeManager::m_pInstance = nullptr;

CRMjudgeManager::CRMjudgeManager(void)
{
}


CRMjudgeManager::~CRMjudgeManager(void)
{
}

// CRMjudgeManager* CRMjudgeManager::GetInstance()
// {
// 	if ( m_pInstance == nullptr )
// 	{
// 		m_pInstance = new CRMjudgeManager();
// 	}
// 
// 	return m_pInstance;
// }
// 
// void CRMjudgeManager::ReleaseInstance()
// {
// 	if ( m_pInstance != nullptr )
// 	{
// 		delete m_pInstance;
// 		m_pInstance = nullptr;
// 	}
// }

void CRMjudgeManager::StartNote( PlayerNumber player , ObjectType objectType )
{
	std::list<CRMobject*>* notePoolList = CRMobjectManager::GetInstance()->GetObjectList( LAYER_MEMORY_POOL );

	if ( notePoolList->size() == 0 )
	{
		return; 
	}
		

	auto& iter = notePoolList->begin();
	auto thisNote = iter;
	switch ( player )
	{
	case PLAYER_ONE:
		(*thisNote)->SetObjectType( objectType );
		(*thisNote)->SetPosition( 395, -100 );
		(*thisNote)->SetSceneType( SCENE_PLAY );
		CRMobjectManager::GetInstance()->AddObject( *thisNote , LAYER_NOTE1 );
		notePoolList->erase(notePoolList->begin());
		break;
	case PLAYER_TWO:
		(*thisNote)->SetObjectType( objectType );
		(*thisNote)->SetPosition( 910, -100 );
		(*thisNote)->SetSceneType( SCENE_PLAY );
		CRMobjectManager::GetInstance()->AddObject( *thisNote , LAYER_NOTE2 );
		notePoolList->erase(notePoolList->begin());
		break;
	case NO_PLAYER:
	default:
		break;
	}
}

void CRMjudgeManager::JudgeNote()
{
	std::list<CRMobject*>* note1List = CRMobjectManager::GetInstance()->GetObjectList( LAYER_NOTE1 );
	std::list<CRMobject*>* note2List = CRMobjectManager::GetInstance()->GetObjectList( LAYER_NOTE2 );

	if( note1List->size() > 0 )
	{
		auto& iterP1 = note1List->begin();
		auto thisNoteP1 = iterP1;

		/*
			1. 노트한테 너 위치 어디야?

			2. 위치가 판별 범위 안이면 
			키보드 매니저한테 묻기 => 눌렸냐?  -> 구현해야 할 것 - 인풋매니저의 키 버튼 푸시

			3. 눌렸으면?
			
			3-1 하단의 사라짐 코드처럼 마찬가지로 메모리풀로 넣어줌

			3-2 판별 => 노트의 종류를 겟 

			3-3 이펙트 발동! (by 신동찬 - "char형 비트연산으로 하겠습니다.")
		*/

		printf( "note:%f \n" , (*thisNoteP1)->GetPositionY() );

		// Player1 Miss
		if ( (*thisNoteP1)->GetPositionY() > SCREEN_SIZE_Y-1 )
		{
			DeleteNote( note1List );
		}
		// Player1 Good
		else if ( (*thisNoteP1)->GetPositionY() > SCREEN_SIZE_Y-110 )
		{
			if ( (*thisNoteP1)->GetObjectType() == OBJECT_NOTE_NORMAL_1 )
			{
				if ( CRMinput::GetInstance()->GetKeyboardInput()[P1_TARGET1] == true )
				{
					CRMsound::GetInstance()->PlayEffect("se2.wav");
					DeleteNote( note1List );
				}
			}
			else if ( (*thisNoteP1)->GetObjectType() == OBJECT_NOTE_NORMAL_2 )
			{
				if ( CRMinput::GetInstance()->GetKeyboardInput()[P1_TARGET2] == true )
				{
					CRMsound::GetInstance()->PlayEffect("se2.wav");
					DeleteNote( note1List );
				}
			}
			
		}
		// Player1 Perfect
		else if ( (*thisNoteP1)->GetPositionY() > SCREEN_SIZE_Y-130 )
		{
			if ( (*thisNoteP1)->GetObjectType() == OBJECT_NOTE_NORMAL_1 )
			{
				if ( CRMinput::GetInstance()->GetKeyboardInput()[P1_TARGET1] == true )
				{
					CRMsound::GetInstance()->PlayEffect("se2.wav");
					DeleteNote( note1List );
				}
			}
			else if ( (*thisNoteP1)->GetObjectType() == OBJECT_NOTE_NORMAL_2 )
			{
				if ( CRMinput::GetInstance()->GetKeyboardInput()[P1_TARGET2] == true )
				{
					CRMsound::GetInstance()->PlayEffect("se2.wav");
					DeleteNote( note1List );
				}
			}

		}
		// Player1 Good
		else if ( (*thisNoteP1)->GetPositionY() > SCREEN_SIZE_Y-150 )
		{
			if ( (*thisNoteP1)->GetObjectType() == OBJECT_NOTE_NORMAL_1 )
			{
				if ( CRMinput::GetInstance()->GetKeyboardInput()[P1_TARGET1] == true )
				{
					CRMsound::GetInstance()->PlayEffect("se2.wav");
					DeleteNote( note1List );
				}
			}
			else if ( (*thisNoteP1)->GetObjectType() == OBJECT_NOTE_NORMAL_2 )
			{
				if ( CRMinput::GetInstance()->GetKeyboardInput()[P1_TARGET2] == true )
				{
					CRMsound::GetInstance()->PlayEffect("se2.wav");
					DeleteNote( note1List );
				}
			}

		}
	}
	
	if( note2List->size() > 0 )
	{
		auto& iterP2 = note2List->begin();
		auto thisNoteP2 = iterP2;


		if ( (*thisNoteP2)->GetPositionY() > SCREEN_SIZE_Y-1 )
		{
			DeleteNote( note2List );
		}
	}
}

void CRMjudgeManager::DeleteNote( std::list<CRMobject*>* objectList )
{
	CRMobjectManager::GetInstance()->AddObject( *objectList->begin() , LAYER_MEMORY_POOL );
	objectList->erase(objectList->begin());
}
