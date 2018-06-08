#pragma once

// abstract 클래스는 상속 전용이기 때문에
// 직접 할당해서 사용할순 없고 상속 후 자식 클래스에서 PURE 처리된 함수들을
// 재정의 하여 사용해야 함


// 여기선 모든 씬의 상위 클래스인 cScene 클래스를 정의했다.

class cScene abstract
{
public:
	cScene();
	virtual ~cScene();

	// 맴버 함수에 PURE이 들어가면 상속받은 클래스에서 override 로 재정의.
	// ex) virtual void Init() override;

	virtual void Init()		PURE;
	virtual void Update()	PURE;
	virtual void Render()	PURE;
	virtual void Release()	PURE;
};

