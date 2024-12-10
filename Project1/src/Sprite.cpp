#include "Sprite.h"

Sprite::Sprite(unsigned int width, unsigned int height, unsigned int data[])
{
	m_Width = width;
	m_Height = height;
	m_Data = data;
}

Sprite::~Sprite()
{
}

void Sprite::BufferSpriteDraw(Buffer& buffer, const Sprite& sprite, unsigned int x, unsigned int y, unsigned int color)
{
	for (unsigned int i = 0; i < sprite.m_Width; i++)
	{
		for (unsigned int j = 0; j < sprite.m_Height; j++)
		{
			unsigned int sY = sprite.m_Height - 1 + y - j;
			unsigned int sX = x + i;
			if (sprite.m_Data[j * sprite.m_Width + i] &&
				sY < buffer.GetHeight() &&
				sX < buffer.GetWidth())
			{
				int index = sY * buffer.GetWidth() + sX;
				buffer.SetData(index, color);
			}
		}
	}
}


