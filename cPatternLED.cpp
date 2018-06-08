#include "DXUT.h"
#include "cPatternLED.h"



cPatternLED::cPatternLED(const string & pathList)
{
	for (int i = 0; i < 10; i++) {
		patterns[i] = IMAGEMANAGER->FindImage(pathList + to_string(i + 1));
	}
	patternIndex = 0;

	changeTime = g_nowTime;
}

cPatternLED::~cPatternLED()
{
}

void cPatternLED::Update()
{
	if (changeTime < g_nowTime) {
		patternIndex++;
		if (patternIndex >= 10) {
			patternIndex = 0;
		}
		changeTime = g_nowTime + 200;
	}
}

void cPatternLED::Render()
{
	patterns[patternIndex]->CenterRender( WINSIZEX / 2, WINSIZEY / 2 );
}
