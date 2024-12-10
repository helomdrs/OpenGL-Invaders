#include "Buffer.h"

Buffer::Buffer(unsigned int width, unsigned int height)
{
	m_Width = width;
	m_Height = height;
	m_Data = new unsigned int[m_Width * m_Height];
	ClearBuffer(RGBToUint32(0, 128, 0));
}

Buffer::~Buffer()
{
}

unsigned int Buffer::RGBToUint32(unsigned int r, unsigned int g, unsigned int b)
{
	return (r << 24) | (g << 16) | (b << 8) | 255;
}

void Buffer::ClearBuffer(unsigned int color)
{
	for (size_t i = 0; i < this->m_Width * this->m_Height; ++i)
	{
		this->m_Data[i] = color;
	}
}

void Buffer::SetData(int index, unsigned int color)
{
	m_Data[index] = color;
}
