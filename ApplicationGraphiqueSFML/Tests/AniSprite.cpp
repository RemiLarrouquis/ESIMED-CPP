#include "AniSprite.h"
 
AniSprite::AniSprite(void)
	: sf::Sprite() 
{
	this->fps=1;
	this->currentFrame=0;
	this->isPlaying = false;
	this->loopStart = 0;
	this->SetFrameSize(0, 0);
}
 
AniSprite::AniSprite(const sf::Texture& Img, int frameW, int frameH)
		: sf::Sprite(Img)
{
	this->fps=1;
	this->currentFrame=0;
	this->isPlaying = false;
	this->loopStart = 0;
	this->SetFrameSize(frameW, frameH);
	//now calculate stuff
}
 
AniSprite::~AniSprite(void)
{
}
int AniSprite::GetFrameCount()
{
	unsigned int across = 
		this->getTexture()->getSize().x /
		this->frameWidth;
	unsigned int down = 
		this->getTexture()->getSize().y /
		this->frameHeight;
 
	return across*down;
}
//first frame is frame ZERO
sf::IntRect AniSprite::GetFramePosition(int frame)
{
	//get number across and down
	unsigned int across = 
		(this->getTexture()->getSize().x /
		this->frameWidth);
 
    int tileY = frame / across ; //get Y on grid
    int tileX = frame % across ; //get X on grid
 
// pour SFML 1.6
	/*	sf::IntRect result(
		tileX*this->frameWidth,
		tileY*this->frameHeight,
		tileX*this->frameWidth + this->frameWidth,
		tileY*this->frameHeight + this->frameHeight);*/
// pour SFML 2.2 
	    sf::IntRect result(
		tileX*this->frameWidth,
		tileY*this->frameHeight,
		this->frameWidth,
		this->frameHeight);

 
	//end
	return result;	
 
}
//
void 
AniSprite::SetFrameSize(int frameW, int frameH)
{
	this->frameWidth = frameW;
	this->frameHeight = frameH;
	this->setTextureRect(sf::IntRect(0,0,frameW,frameH));
}
//Sets current frame
void 
AniSprite::SetFrame(int frame)
{
	this->currentFrame = frame;
}
//sets loop speed in fps
void 
AniSprite::SetLoopSpeed(float newfps)
{
	this->fps = newfps;
}
//start looping
void 
AniSprite::Play()
{
	this->Play(0,GetFrameCount());
}
void 
AniSprite::Play(int start, int end)
{	
	loopStart = start;
	loopEnd = end;
	currentFrame = start;
	isPlaying = true;	
	clock.restart();
}
//stop
void
AniSprite::Stop()
{
	isPlaying = false;
}
//update function
void
AniSprite::Update()
{
	if(isPlaying)
	{
		int frameCount = loopEnd - loopStart;
                // for sfml 2.0 replace the above line with...
//		int frameCount = (loopEnd+1) - loopStart;
 
 		float timePosition = (clock.getElapsedTime().asSeconds() * fps);
		currentFrame = loopStart + 
			(int)timePosition % frameCount;
		//printf("%f:%i\n",clock.GetElapsedTime(),currentFrame);
 
		this->setTextureRect(GetFramePosition(currentFrame));		
	}
}

//update function sans gestions du temp
void
AniSprite::UpdateMan(int next)
{
	if (isPlaying)
	{
		if (next == 0) {
			currentFrame = 0;
		}
		else {
			currentFrame += next;
		}

		this->setTextureRect(GetFramePosition(currentFrame));
	}
}
