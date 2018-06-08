#include "DXUT.h"
#include "FrameAni.h"



FrameAni::FrameAni(const string & frame, DWORD changeTime, INT totalFrame, D3DXVECTOR2 pos)
	:changeTime(changeTime), totalFrame(totalFrame)
{
	for (int i = 0; i < totalFrame; i++) {
		FrameAni::frame[i] = IMAGEMANAGER->FindImage(frame + to_string(i + 1));
	}
	nowFrame = 0;
	currTime = 0;

	position = pos;
}

FrameAni::~FrameAni()
{
}

void FrameAni::Update()
{
	if (currTime <= g_nowTime) {

		nowFrame++;

		if (nowFrame >= totalFrame)
			nowFrame = 0;

		currTime = g_nowTime + changeTime;
	}
}

void FrameAni::Render()
{
	frame[nowFrame]->CenterRender(position.x, position.y);
}
