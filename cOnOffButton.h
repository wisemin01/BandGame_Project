#pragma once
class cOnOffButton
{
	enum {
		E_PLAYMODE,
		E_PLAY_ON_MOUSE,
		E_STOPMODE,
		E_STOP_ON_MOUSE
	};
private:
	texture * buttonImage[4];
	int state;
	DWORD delay;
	std::function<void()> s_func;
	std::function<void()> p_func;

	D3DXVECTOR2 pos;
	DWORD pauseTime;
public:
	cOnOffButton(D3DXVECTOR2 position, const string& ImageIndex, DWORD startDelay, function<void()> _pFunc, function<void()> _sFunc);
	~cOnOffButton();

	void Update();
	void Render();
};

