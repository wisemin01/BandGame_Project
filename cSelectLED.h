#pragma once
class cSelectLED
{
private:
	texture * image[2];
	int nowImage;
	DWORD changeTime;
public:
	cSelectLED(const string &image);
	~cSelectLED();

	void Update();
	void Render();

};

