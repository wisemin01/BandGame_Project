#pragma once

#include <iostream>
#include <functional>
#include <thread>
#include <vector>
#include <list>
#include <string>
#include <map>

using namespace std;

// ȭ���� ũ��

#define WINSIZEX 1280
#define WINSIZEY 720
#define WINDOWMODE false

#define g_device	DXUTGetD3D9Device()		// ����̽�
#define deltaTime	DXUTGetElapsedTime()	// ������ ���� �ð�
#define g_nowTime	timeGetTime()			// ���� �ð�
#define g_hWnd		DXUTGetHWND()			// ȭ�� �ڵ�

// DEBUG_LOG : �ܼ� â�� �α׸� ǥ���մϴ�.

#if _DEBUG
#define DEBUG_LOG(log) cout << log << endl
#else
#define DEBUG_LOG(lob)  
#endif

#define MAP_CLEAR(map) { for(auto iter : map) { SAFE_DELETE(iter.second); }; map.clear(); }

// �Ŵ��� �߰�

#include "cSceneManager.h"
#include "cImageManager.h"
#include "cInputManager.h"
#include "cSoundManager.h"

namespace utility {
	template<typename T>
	void lerp(T& dot, T d1, T d2, float speed) {
		dot = d1 + (d2 - dot) * speed;
	}
};