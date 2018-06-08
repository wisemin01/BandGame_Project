#include "DXUT.h"
#include "cDisplayTime.h"


cDisplayTime::cDisplayTime()
{
	s = 0;
	m = 0;
}


cDisplayTime::~cDisplayTime()
{
}

void cDisplayTime::Update()
{
	s = SOUNDMANAGER->GetNowSoundProgress();
	m = 0;

	for (; s >= 60; s -= 60) {
		m++;
	}

	outText = to_string(m) + ":";
	outText += (s < 10 ? "0" : "") + to_string(s);
}

void cDisplayTime::Render()
{
	FONTMANAGER->sDrawText(WINSIZEX / 2 - 40, WINSIZEY / 2 - 185, outText, 35);
}
