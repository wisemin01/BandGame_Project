#include "DXUT.h"
#include "cProgressBar.h"


cProgressBar::cProgressBar(D3DXVECTOR2 position)
	:position(position)
{
	backBar = IMAGEMANAGER->FindImage("progressBar1");
	fill = IMAGEMANAGER->FindImage("progressBar2");
}


cProgressBar::~cProgressBar()
{
}

void cProgressBar::Update()
{
	percent = (float)SOUNDMANAGER->GetNowSoundProgress() / (float)SOUNDMANAGER->GetSoundSize();

	renderRect = { 0, 0 ,
		(long)((float)fill->info.Width * (float)percent) ,
		(long)fill->info.Height };
}

void cProgressBar::Render()
{
	backBar->Render(position.x, position.y);
	fill->RectRender(position.x, position.y, &renderRect);
}
