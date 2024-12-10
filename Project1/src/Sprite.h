#pragma once

#include "Buffer.h"

class Sprite
{
private:
	unsigned int m_Width, m_Height;
	unsigned int* m_Data;

public:
	Sprite(unsigned int width, unsigned int height, unsigned int data[]);
	~Sprite();

	void BufferSpriteDraw(Buffer& buffer, const Sprite& sprite, unsigned int x, unsigned int y, unsigned int color);
};