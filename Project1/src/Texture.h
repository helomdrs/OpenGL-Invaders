#pragma once

#include "Renderer.h"
#include "Buffer.h"

class Texture
{
private:
	unsigned int m_RendererID;
	std::string m_FilePath;
	unsigned int* m_LocalBuffer;
	int m_Width, m_Height, m_BytesPerPixel;

public:
	Texture(unsigned int width, unsigned int height, unsigned int* data);
	~Texture();

	void Bind(unsigned int slot = 0) const;
	void Unbind() const;

	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }

};