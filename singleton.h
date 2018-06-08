#pragma once

// 이 singleton 클래스를 상속받으면
// 프로그램 내에 하나의 클래스만 생성된다.

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