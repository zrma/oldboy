#include "stdafx.h"
#include "RMchildAlertGrow.h"
#include "RMmainLoop.h"
#include "RMitemManager.h"
#include "RMdefine.h"


CRMchildAlertGrow::CRMchildAlertGrow(void) :
	m_AnimationFrame(0)
{
}


CRMchildAlertGrow::~CRMchildAlertGrow(void)
{
}

void CRMchildAlertGrow::Update()
{
	if ( m_Scene != CRMmainLoop::GetInstance()->GetNowScene() )
	{
		m_Visible = false;
		return;
	}
	m_Visible = true;

	//////////////////////////////////////////////////////////////////////////



	if ( CRMitemManager::GetInstance()->GetActivatedItem(m_PlayerNumber) == ITEM_TYPE_NONE )
	{
		m_AnimationFrame = 0;
		m_Alpha = 0.f;
	}
	else
	{
		
		switch ( CRMitemManager::GetInstance()->GetActivatedItem(m_PlayerNumber) )
		{
		case ITEM_T1_SCORE_UP:
		case ITEM_T2_BARRIER:
		case ITEM_T3_RECOVERY:
			m_WidgetType = WIDGET_PLAY_ALERT_GROW_BLUE;
			break;
		default:
			m_WidgetType = WIDGET_PLAY_ALERT_GROW_RED;
			break;
		}

		++m_AnimationFrame;

		m_Alpha = static_cast<float>(m_AnimationFrame) / PLAY_ALERT_GROW_ANIMATION_SPEED;

		if ( m_AnimationFrame > PLAY_ALERT_GROW_ANIMATION_SPEED )
		{
			m_Alpha = 1 - ( static_cast<float>( m_AnimationFrame - PLAY_ALERT_GROW_ANIMATION_SPEED ) / PLAY_ALERT_GROW_ANIMATION_SPEED );
		}

		if ( m_AnimationFrame > ( PLAY_ALERT_GROW_ANIMATION_SPEED * 2 ) )
		{
			m_AnimationFrame = 0;
		}
	}
	

	

}
