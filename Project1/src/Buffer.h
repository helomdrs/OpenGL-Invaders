#pragma once

class Buffer
{
private:
	unsigned int m_Width, m_Height;
	unsigned int* m_Data;
public:
	Buffer(unsigned int width, unsigned int height);
	~Buffer();

	unsigned int RGBToUint32(unsigned int r, unsigned int g, unsigned int b);

	inline unsigned int* GetData() const { return m_Data; };
	inline unsigned int GetWidth() const { return m_Width; };
	inline unsigned int GetHeight() const { return m_Height; };

	void ClearBuffer(unsigned int color);
	void SetData(int index, unsigned int color);
};