#pragma once
#include "cScene.h"

// cScene Ŭ������ ��ӹ޾� ����
// cLoadingScene Ŭ����.

// �̹��� �ε��� ����ϴ� ���̴�.

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

