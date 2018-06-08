#pragma once
#include "cScene.h"
class cActionScene :
	public cScene
{
private:
	texture * backGround;

	bool end;
	float rotate;
	float rotateSpeed;
	float size;
public:
	cActionScene();
	virtual ~cActionScene();

	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Release();
};

