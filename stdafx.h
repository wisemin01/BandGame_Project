#pragma once

#include <iostream>
#include <functional>
#include <thread>
#include <vector>
#include <list>
#include <string>
#include <map>

using namespace std;

// 화면의 크기

#define WINSIZEX 1280
#define WINSIZEY 720
#define WINDOWMODE false

#define g_device	DXUTGetD3D9Device()		// 디바이스
#define deltaTime	DXUTGetElapsedTime()	// 프레임 지연 시간
#define g_nowTime	timeGetTime()			// 현재 시간
#define g_hWnd		DXUTGetHWND()			// 화면 핸들

// DEBUG_LOG : 콘솔 창에 로그를 표시합니다.

#if _DEBUG
#define DEBUG_LOG(log) cout << log << endl
#else
#define DEBUG_LOG(lob)  
#endif

#define MAP_CLEAR(map) { for(auto iter : map) { SAFE_DELETE(iter.second); }; map.clear(); }

// 매니저 추가

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