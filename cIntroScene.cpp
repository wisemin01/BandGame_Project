#include "DXUT.h"
#include "cIntroScene.h"

#include "cButton.h"

cIntroScene::cIntroScene()
{
}


cIntroScene::~cIntroScene()
{
}

void cIntroScene::Init()
{
	introBackGround = IMAGEMANAGER->FindImage("StartScene");
	CreditImage = IMAGEMANAGER->FindImage("Credit");
	InfoImage = IMAGEMANAGER->FindImage("Info");

	InfomationDisplay_Credit = false;
	InfomationDisplay_Info = false;

	CreditSize = 0.01;
	InfoSize = 3.0;

	CreditButton = new cButton(D3DXVECTOR2(20, 170), "CreditButton_", 200,
		[&]() { InfomationDisplay_Credit = true; });
	UseButton = new cButton(D3DXVECTOR2(20, 275), "UseButton_", 200,
		[&]() { InfomationDisplay_Info = true; });
	StartButton = new cButton(D3DXVECTOR2(20, 360), "StartButton_", 200,
		[]() { SCENEMANAGER->ChangeScene("ingame"); });
}

void cIntroScene::Update()
{
	if (InfomationDisplay_Credit && CreditSize < 1.0) {
		utility::lerp(CreditSize, CreditSize, 1.0f, 0.15f);
	}
	if (InfomationDisplay_Info && InfoSize > 1.0) {
		utility::lerp(InfoSize, InfoSize, 1.0f, 0.15f);
	}

	CreditButton->Update();
	UseButton->Update();
	StartButton->Update();

	if (GETKEY_DOWN(VK_LBUTTON)) {
		if (InfomationDisplay_Credit) {
			InfomationDisplay_Credit = false;
			CreditSize = 0.01;
		}
		if (InfomationDisplay_Info) {
			InfomationDisplay_Info = false;
			InfoSize = 3.0;
		}
	}
}

void cIntroScene::Render()
{
	introBackGround->Render(0, 0);

	CreditButton->Render();
	UseButton->Render();
	StartButton->Render();

	if (InfomationDisplay_Credit)
		CreditImage->CenterRender(WINSIZEX / 2, WINSIZEY / 2, CreditSize);
	if (InfomationDisplay_Info)
		InfoImage->CenterRender(WINSIZEX / 2, WINSIZEY / 2 , InfoSize);
}

void cIntroScene::Release()
{
	SAFE_DELETE(CreditButton);
	SAFE_DELETE(UseButton);
	SAFE_DELETE(StartButton);
}
