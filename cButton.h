#pragma once
class cButton
{
	enum {
		E_IDLE,
		E_ON_MOUSE,
		E_CLICK
	};
private:
	texture * buttonImage[3];
	int state;
	DWORD delay;
	std::function<void()> func;

	D3DXVECTOR2 pos;
	DWORD pauseTime;
public:
	cButton(D3DXVECTOR2 position,const string& ImageIndex, DWORD startDelay, function<void()> _func);
	virtual ~cButton();

	void Update();
	void Render();
};

