#pragma once

#include "RMmacro.h"

class GameManager
{
	SINGLETON(GameManager);
private:
	GameManager();
	~GameManager();

public:
	bool Init() const;
	bool Process() const;
	void Destroy() const;
	void Stop() { m_Continue = false; }

private:
	bool			m_Continue = true;
};