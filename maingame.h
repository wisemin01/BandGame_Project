#pragma once

// ������ ��ü ������ ���� Ŭ����

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

	void Init();	// Init�� �ʱ�ȭ �Լ�
	void Update();	// Update�� �� �����Ӹ��� ȣ��Ǵ� �Լ�
	void Render();	// Render�� �׷��� ����� ����ϴ� �Լ�
	void Release();	// Release�� ���� �޸� �Ҵ��̳� ���� ����

	void OnLostDevice();
	void OnResetDevice();
};

