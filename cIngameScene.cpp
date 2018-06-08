#include "DXUT.h"
#include "cIngameScene.h"

// ���漱�� �� Ŭ������ include ���� ������ ����Ҽ� ����.

#include "cPatternLED.h"
#include "cSelectLED.h"
#include "cDisplaySong.h"
#include "cDisplayTime.h"
#include "cButton.h"
#include "cOnOffButton.h"
#include "cProgressBar.h"
#include "cPersonAdmin.h"

#include "FrameAni.h"

cIngameScene::cIngameScene()
{
}


cIngameScene::~cIngameScene()
{
}


void cIngameScene::Init()
{
	backGround1 = IMAGEMANAGER->FindImage("backGround1");
	backGround2 = IMAGEMANAGER->FindImage("backGround2");
	backGround3 = IMAGEMANAGER->FindImage("backGround3");

	for (int i = 0; i < 3; i++) {
		LEDs[i] = new cPatternLED("pattern" + to_string(i + 1));
	}
	for (int i = 0; i < 5; i++) {
		SLEDs[i] = new cSelectLED("selectLED" + to_string(i + 1));
	}

	nowLedIndex = rand() % 3;

	SOUNDMANAGER->SelectSound(0); // Default

	// =================================================
	// ��ư �ʱ�ȭ
	// =================================================

	gotoStartButton = new cButton(D3DXVECTOR2(0, WINSIZEY - 100), "GotoStartButton_", 200,
		[]() { SCENEMANAGER->ChangeScene("action"); });
	leftButton = new cButton(D3DXVECTOR2(WINSIZEX / 2 - 370, WINSIZEY / 2 - 240), "LeftButton_", 150,
		[&]() {
		if (SOUNDMANAGER->GetSoundNumber() <= 0) {
			if (SOUNDMANAGER->SelectSound(4)) RandomLED();
		}
		else
		{
			if (SOUNDMANAGER->SelectSound(SOUNDMANAGER->GetSoundNumber() - 1)) RandomLED();
		}
		});
	rightButton = new cButton(D3DXVECTOR2(WINSIZEX / 2 + 278, WINSIZEY / 2 - 240), "RightButton_", 150,
		[&]() {
		if (SOUNDMANAGER->GetSoundNumber() >= 4) {
			if (SOUNDMANAGER->SelectSound(0)) RandomLED();
		}
		else
		{
			if (SOUNDMANAGER->SelectSound(SOUNDMANAGER->GetSoundNumber() + 1)) RandomLED();
		}
		});
	stateButton = new cOnOffButton(D3DXVECTOR2(WINSIZEX / 2 - 269, WINSIZEY / 2 - 260), "PlayButton_", 10,
		[&]() {
		// TODO : p ������ ���� �Լ�
		SOUNDMANAGER->pPlaySound();
		},
		[&]() {
		// TODO : s ������ ���� �Լ�
		SOUNDMANAGER->pPauseSound();
		});

	// =================================================

	displaySong = new cDisplaySong;
	displayTime = new cDisplayTime;

	progressBar = new cProgressBar(D3DXVECTOR2(WINSIZEX / 2 - 275, WINSIZEY / 2 - 180));

	// =================================================

	fan = new FrameAni("Fan", 120, 3, D3DXVECTOR2(WINSIZEX / 2, WINSIZEY - 55));
	light = new FrameAni("Light", 300, 3, D3DXVECTOR2(WINSIZEX / 2, 262));

	persons = new cPersonAdmin();
}

void cIngameScene::Update()
{
	if (SOUNDMANAGER->IsOnPlay)
		LEDs[nowLedIndex]->Update();
	else
		SLEDs[SOUNDMANAGER->GetSoundNumber()]->Update();

	displayTime->Update();

	persons->Update();

	if (SOUNDMANAGER->soundState == EP_PLAY) {
		fan->Update();
		light->Update();
	}

	gotoStartButton->Update();
	leftButton->Update();
	rightButton->Update();
	stateButton->Update();

	progressBar->Update();

	// =================================================
}

void cIngameScene::Render()
{
	if (SOUNDMANAGER->soundState == EP_PLAY)
		LEDs[nowLedIndex]->Render();
	else
		SLEDs[SOUNDMANAGER->GetSoundNumber()]->Render();

	backGround3->Render(0, 0);

	// =================================================

	persons->Render();

	if (SOUNDMANAGER->soundState == EP_PLAY) {
		light->Render();
	}

	// =================================================

	backGround2->Render(0, 0);
	backGround1->Render(0, 0);

	fan->Render();

	progressBar->Render();

	displaySong->Render();
	displayTime->Render();

	gotoStartButton->Render();
	leftButton->Render();
	rightButton->Render();
	stateButton->Render();
}

void cIngameScene::Release()
{
	// �뷡 ����

	SOUNDMANAGER->pStopSound();
	SOUNDMANAGER->SelectSound("Amorfati");

	// �޸𸮸� new �� �Ҵ��ϰ� ����� ������ delete ���־�� �Ѵ�.

	for (auto iter : LEDs) SAFE_DELETE(iter);
	for (auto iter : SLEDs) SAFE_DELETE(iter);

	SAFE_DELETE(displaySong);
	SAFE_DELETE(displayTime);

	SAFE_DELETE(gotoStartButton);
	SAFE_DELETE(leftButton);
	SAFE_DELETE(rightButton);
	SAFE_DELETE(stateButton);

	SAFE_DELETE(progressBar);

	// =================================================
	// Persons
	// =================================================

	SAFE_DELETE(fan);
	SAFE_DELETE(light);

	SAFE_DELETE(persons);
}

void cIngameScene::RandomLED()
{
	// ���� (�� ��ġ�� �ϴ�)
	int r;
	do {
		r = rand() % 3;
	} while (r == nowLedIndex);
	nowLedIndex = r;
}
