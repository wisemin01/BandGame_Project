#pragma once
class FrameAni
{
private:
	texture * frame[10];

	DWORD currTime;
	DWORD changeTime;

	INT nowFrame;
	INT totalFrame;

	D3DXVECTOR2 position;
public:
	FrameAni(const string&frame, DWORD changeTime, INT totalFrame, D3DXVECTOR2 pos);
	~FrameAni();

	void Update();
	void Render();

	void SetFrameChangeTime(DWORD time) { changeTime = time; }
};

