#include "DXUT.h"
#include "cButton.h"


cButton::cButton(D3DXVECTOR2 position, const string & ImageIndex, DWORD startDelay, function<void()> _func)
{
	for (int i = 0; i < 3; i++) {
		buttonImage[i] = IMAGEMANAGER->FindImage(ImageIndex + std::to_string(i + 1));
	}
	state = E_IDLE;
	delay = startDelay;
	func = _func;

	pos = position;
	pauseTime = 0;
}

cButton::~cButton()
{
}

void cButton::Update()
{
	D3DXVECTOR2 point = INPUTMANAGER->GetMousePos();

	if (pos.x < point.x && pos.x + buttonImage[0]->info.Width > point.x &&
		pos.y < point.y && pos.y + buttonImage[0]->info.Height > point.y) {
		if (state == E_IDLE)
			state = E_ON_MOUSE;
	}
	else if (state == E_ON_MOUSE)
		state = E_IDLE;

	if (state == E_ON_MOUSE) {
		if (GETKEY_DOWN(VK_LBUTTON)) {
			state = E_CLICK;
			pauseTime = g_nowTime + delay;
		}
	}

	if (state == E_CLICK && g_nowTime > pauseTime) {
		func();
		state = E_IDLE;
	}
}

void cButton::Render()
{
	buttonImage[state]->Render(pos.x, pos.y);
}
