#pragma once
class cProgressBar
{
private:
	texture * backBar;
	texture * fill;

	float percent;

	RECT renderRect;

	D3DXVECTOR2 position;

public:
	cProgressBar(D3DXVECTOR2 position);
	~cProgressBar();

	void Update();
	void Render();
};

