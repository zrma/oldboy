﻿#include "stdafx.h"
#include "RMmacro.h"
#include "RMdefine.h"
#include "RMchildNote.h"
#include "RMmainLoop.h"
#include "RMrender.h"
#include "RMresourceManager.h"
#include "RMimage.h"
#include "RMitemManager.h"


CRMchildNote::CRMchildNote(void)
{
}


CRMchildNote::~CRMchildNote(void)
{
}

void CRMchildNote::Update()
{
	//SetVisibleByScene();

	if ( m_Scene != CRMmainLoop::GetInstance()->GetNowScene() )
	{
		return;
	}
	
	if ( m_Scene == CRMmainLoop::GetInstance()->GetNowScene() && m_Visible == false )
	{
		m_PositionX = DEFAULT_POSITION_X;
		m_PositionY = DEFAULT_POSITION_Y;
		m_Rotation = 0;

		return;
	}

	if ( m_PositionY < SCREEN_SIZE_Y + NOTE_SIZE )
	{
		m_PositionY += 5;

		if ( CRMitemManager::GetInstance()->GetActivatedItem(m_playerNumber) == ITEM_T2_ROTATE )
		{
			if ( m_PositionY > NOTE_JUDGE_PERFECT_START_LINE - 540 )
			{
				m_Rotation = 180 + ( m_PositionY - ( NOTE_JUDGE_PERFECT_START_LINE - 540 ) ) / 3;
			}
		}
		else
		{
			m_Rotation = 0;
		}
		
	}
	else
	{
		m_Visible = false;
	}
}

void CRMchildNote::Render()
{
	// 원래 좌표축으로 돌리기 위한 현재 좌표축 임시 저장
	CRMrender::GetInstance()->GetRenderTarget()->GetTransform( &m_PrevMatrix );

	if ( m_Width != 0 && m_Height != 0 )
	{
		m_Matrix = D2D1::Matrix3x2F::Translation( -m_PositionX, -m_PositionY ) * 
			D2D1::Matrix3x2F::Rotation( m_Rotation, D2D1::Point2F( m_Width / 2 , m_Height / 2 ) ) * 
			D2D1::Matrix3x2F::Translation(m_PositionX, m_PositionY);
	}

	CRMrender::GetInstance()->GetRenderTarget()->SetTransform( m_Matrix );

	//부모의 렌더함수를 빌려서 바로 적용하도록 함	
	CRMobject::Render();

	//원래의 좌표축으로 돌려 놓는 것
	CRMrender::GetInstance()->GetRenderTarget()->SetTransform( m_PrevMatrix );
}
