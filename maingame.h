#pragma once

// 게임의 전체 구조를 담은 클래스

class maingame
{
#if (FALSE)
private:
	DEVMODE devMode;
	INT defaultX, defaultY;
#endif
public:
	maingame() {}
	~maingame() {}

	void Init();	// Init은 초기화 함수
	void Update();	// Update는 매 프레임마다 호출되는 함수
	void Render();	// Render는 그래픽 출력을 담당하는 함수
	void Release();	// Release는 각종 메모리 할당이나 값의 해제

	void OnLostDevice();
	void OnResetDevice();
};

