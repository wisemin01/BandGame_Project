#pragma once
#include "cScene.h"

class cButton;
class cIntroScene :
	public cScene
{
private:
	texture * introBackGround;
	texture * CreditImage;
	texture * InfoImage;

	cButton* CreditButton;
	cButton* UseButton;
	cButton* StartButton;

	bool InfomationDisplay_Credit;
	bool InfomationDisplay_Info;

	float CreditSize;
	float InfoSize;

public:
	cIntroScene();
	virtual ~cIntroScene();

	virtual void Init	()	override;
	virtual void Update	()	override;
	virtual void Render	()	override;
	virtual void Release()	override;

};

