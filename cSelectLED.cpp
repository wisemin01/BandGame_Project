#include "DXUT.h"
#include "cSelectLED.h"


cSelectLED::cSelectLED(const string & image)
{
	for (int i = 0; i < 2; i++) {
		cSelectLED::image[i] = IMAGEMANAGER->FindImage(image + to_string(i + 1));
	}
	nowImage = 0;

	changeTime = g_nowTime;
}


cSelectLED::~cSelectLED()
{

}

void cSelectLED::Update()
{
	if (changeTime < g_nowTime) {
		nowImage = !nowImage;
		changeTime = g_nowTime + 200;
	}
}

void cSelectLED::Render()
{
	image[nowImage]->CenterRender(WINSIZEX / 2, WINSIZEY / 2);
}
