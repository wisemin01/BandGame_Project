#pragma once
#include "cScene.h"

// �� ������ ����� Ŭ�������� ���漱�� ���ص� cpp���Ͽ��� 
// �ش� Ŭ������ ��������� include�ϸ� �ȴ�.

class cSampleObject;
class cPatternLED;
class cSelectLED;
class cDisplaySong;
class cButton;
class cOnOffButton;
class cDisplayTime;
class cProgressBar;
class cPersonAdmin;

// Persons

class FrameAni;
class cFan;

class cIngameScene :
	public cScene
{
private:
	texture * backGround1;
	texture * backGround2;
	texture * backGround3;
	
	cPatternLED * LEDs[3];
	cSelectLED * SLEDs[5];

	cDisplaySong * displaySong;
	cDisplayTime * displayTime;

	FrameAni * fan;
	FrameAni * light;

	cPersonAdmin * persons;

	cButton * gotoStartButton;
	cButton * leftButton;
	cButton * rightButton;

	cOnOffButton * stateButton;

	cProgressBar * progressBar;

	int nowLedIndex;

public:
	cIngameScene();
	virtual ~cIngameScene();

	virtual void Init	()	override;
	virtual void Update	()	override;
	virtual void Render	()	override;
	virtual void Release()	override;
	
	void RandomLED();
};

