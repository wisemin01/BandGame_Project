#pragma once
class cPatternLED
{
private:
	texture * patterns[10];
	int patternIndex;
	DWORD changeTime;
public:
	cPatternLED(const string& pathList);
	~cPatternLED();

	void Update();
	void Render();
};

