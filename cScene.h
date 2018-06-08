#pragma once

// abstract Ŭ������ ��� �����̱� ������
// ���� �Ҵ��ؼ� ����Ҽ� ���� ��� �� �ڽ� Ŭ�������� PURE ó���� �Լ�����
// ������ �Ͽ� ����ؾ� ��


// ���⼱ ��� ���� ���� Ŭ������ cScene Ŭ������ �����ߴ�.

class cScene abstract
{
public:
	cScene();
	virtual ~cScene();

	// �ɹ� �Լ��� PURE�� ���� ��ӹ��� Ŭ�������� override �� ������.
	// ex) virtual void Init() override;

	virtual void Init()		PURE;
	virtual void Update()	PURE;
	virtual void Render()	PURE;
	virtual void Release()	PURE;
};

