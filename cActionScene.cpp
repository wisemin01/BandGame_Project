#include "DXUT.h"
#include "cActionScene.h"


cActionScene::cActionScene()
{
}


cActionScene::~cActionScene()
{
}

void cActionScene::Init()
{
	end = false;
	rotate = 0;
	rotateSpeed = 0.1;
	size = 0.0;
	backGround = IMAGEMANAGER->FindImage("StartScene");
}

void cActionScene::Update()

{
	rotate += rotateSpeed;

	if (size < 1)
		size += 0.01;

	if (rotate == 6.3)
		rotateSpeed *= 2;

	if (rotate >= 12.56)
		SCENEMANAGER->ChangeScene("intro");
}

void cActionScene::Render()
{
	backGround->CenterRender(WINSIZEX / 2, WINSIZEY / 2, size, rotate);
}

void cActionScene::Release()
{
}
