#include "DXUT.h"
#include "cOnOffButton.h"


cOnOffButton::cOnOffButton(D3DXVECTOR2 position, const string & ImageIndex, DWORD startDelay, function<void()> _pFunc, function<void()> _sFunc)
{
	for (int i = 0; i < 4; i++) {
		buttonImage[i] = IMAGEMANAGER->FindImage(ImageIndex + std::to_string(i + 1));
	}
	state = E_PLAYMODE;
	delay = startDelay;
	p_func = _pFunc;
	s_func = _sFunc;

	pos = position;
	pauseTime = 0;
}

cOnOffButton::~cOnOffButton()
{
}

void cOnOffButton::Update()
{
	if (SOUNDMANAGER->soundState == E_NONE &&
		(state == E_STOPMODE || state == E_STOP_ON_MOUSE))
		state = E_PLAYMODE;

	D3DXVECTOR2 point = INPUTMANAGER->GetMousePos();

	if (pos.x < point.x && pos.x + buttonImage[0]->info.Width > point.x &&
		pos.y < point.y && pos.y + buttonImage[0]->info.Height > point.y) {
		if (state == E_PLAYMODE)
			state = E_PLAY_ON_MOUSE;
		if (state == E_STOPMODE)
			state = E_STOP_ON_MOUSE;

	}
	else if (state == E_PLAY_ON_MOUSE)
		state = E_PLAYMODE;
	else if (state == E_STOP_ON_MOUSE)
		state = E_STOPMODE;

	if (state == E_PLAY_ON_MOUSE || state == E_STOP_ON_MOUSE) {
		if (GETKEY_DOWN(VK_LBUTTON)) {
			pauseTime = g_nowTime + delay;
		}
	}

	if (pauseTime != 0 && state == E_PLAY_ON_MOUSE && g_nowTime > pauseTime) {
		p_func();
		state = E_STOPMODE;
		pauseTime = 0;
	}
	if (pauseTime != 0 && state == E_STOP_ON_MOUSE && g_nowTime > pauseTime) {
		s_func();
		state = E_PLAYMODE;
		pauseTime = 0;
	}
}

void cOnOffButton::Render()
{
	buttonImage[state]->Render(pos.x, pos.y);
}
