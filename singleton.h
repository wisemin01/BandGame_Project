#pragma once

// �� singleton Ŭ������ ��ӹ�����
// ���α׷� ���� �ϳ��� Ŭ������ �����ȴ�.

template <typename T>
class singleton {
private:
	static T* p;
public:
	virtual ~singleton() {}

	static T * GetInstance() {
		if (!p) p = new T;
		return p;
	}
	static void ReleaseInstance() {
		SAFE_DELETE(p);
	}
};

template<typename T>
T* singleton<T>::p = nullptr;