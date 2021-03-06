﻿#pragma once

class CRMrender
{
	SINGLETON(CRMrender);

private:
	CRMrender(void);
	~CRMrender(void);

public:
	// 팩토리 & 랜더 타겟 생성 및 반환
	HRESULT					CreateFactory();
	HRESULT					CreateRenderTarget();
	ID2D1Factory*			GetRenderFactory() { return m_pDisplayFactory; }
	ID2D1HwndRenderTarget*	GetRenderTarget() { return m_pDisplayRenderTarget; }

	HRESULT					CreateBrush();

	void					ReleaseFactory();

	// 랜더링 시작과 종료
	void					RenderInit();
	HRESULT					RenderEnd();

	// 게이지 그리기
	void					DrawGauge( int gaugePercent );

private:
	ID2D1Factory*			m_pDisplayFactory;
	ID2D1HwndRenderTarget*	m_pDisplayRenderTarget;

	ID2D1SolidColorBrush*	m_pGaugeBrush;
};

