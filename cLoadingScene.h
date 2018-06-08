#pragma once
#include "cScene.h"

// cScene 클래스를 상속받아 만든
// cLoadingScene 클래스.

// 이미지 로딩을 담당하는 씬이다.

class cLoadingScene :
	public cScene
{
private:

public:
	cLoadingScene();
	virtual ~cLoadingScene();

	virtual void Init	()	override;
	virtual void Update	()	override;
	virtual void Render	()	override;
	virtual void Release()	override;

	void LoadingFunc();
};

