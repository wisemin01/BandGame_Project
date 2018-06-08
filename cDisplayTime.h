#pragma once
class cDisplayTime
{
private:
	int m;
	int s;
	string outText;
public:
	cDisplayTime();
	~cDisplayTime();

	void Update();
	void Render();
};

