#pragma once
#if !defined(_WIN32_WINNT)
#define _WIN32_WINNT 0x0501
#endif
#if !defined(WIN32_LEAN_AND_MEAN)
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <string>
#include <utility>

class Image
{
public:
	Image();
	~Image();

	void New(unsigned long width, unsigned long height);
	void Load(const std::string& file);
	void Save(const std::string& file);
	
	unsigned long GetWidth() const;
	unsigned long GetHeight() const;
	bool IsDirty() const;
	
	std::pair<bool, COLORREF> GetPixel(unsigned long x, unsigned long y) const;
	void SetPixel(unsigned long x, unsigned long y, COLORREF color);
	void ClearPixel(unsigned long x, unsigned long y);
	void Fill(unsigned long x, unsigned long y, COLORREF color);
	void ClearFill(unsigned long x, unsigned long y);
	
private:
	unsigned long IndexOf(unsigned long x, unsigned long y) const;
	void FreeImage();
	
private:	
	Image(const Image& rhs);
	Image& operator=(const Image& rhs);
	
private:
	unsigned long mWidth;
	unsigned long mHeight;
	unsigned char* mData;
	bool mDirty;
};
