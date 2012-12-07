#ifndef DE_BUFFER_H
#define DE_BUFFER_H

#include <windows.h>

class CBuffer
{
private:
  HDC m_hBufferDC;
  HBITMAP m_hBufferBmp;
  HBITMAP m_hOldBmp;
  int m_iWidth, m_iHeight;

public:
  // Constructor(s) / Destructor
  CBuffer(HDC hDC, int iWidth, int iHeight);
  CBuffer(HWND hWindow, int iWidth, int iHeight);
  ~CBuffer();

  // General Methods
  void CreateBuffer(HDC hDC, int iWidth, int iHeight);
  void Paint(HDC hDC);
  void Paint(HDC hDC, int winX, int winY);
  void Cleanup();

  // Accesor Methods
  HDC GetBufferDC() { return m_hBufferDC; };
};

CBuffer::CBuffer(HDC hDC, int iWidth, int iHeight)
{
  CreateBuffer(hDC, iWidth, iHeight);
}

CBuffer::CBuffer(HWND hWindow, int iWidth, int iHeight)
{
  HDC hDC = GetDC(hWindow);
  CreateBuffer(hDC, iWidth, iHeight);
  ReleaseDC(hWindow, hDC);
}

CBuffer::~CBuffer()
{
  Cleanup();
}

// General Methods
void CBuffer::CreateBuffer(HDC hDC, int iWidth, int iHeight)
{
  Cleanup();

  m_iWidth = iWidth;
  m_iHeight = iHeight;

  m_hBufferDC = CreateCompatibleDC(hDC);
  m_hBufferBmp = CreateCompatibleBitmap(hDC, m_iWidth, m_iHeight);
  m_hOldBmp = (HBITMAP)SelectObject(m_hBufferDC, m_hBufferBmp);
}

void CBuffer::Cleanup()
{
  if (m_hBufferDC != NULL && m_hBufferBmp != NULL)
  {
    SelectObject(m_hBufferDC, m_hOldBmp);
    DeleteDC(m_hBufferDC);
    DeleteObject(m_hBufferBmp);
  }
}

void CBuffer::Paint(HDC hDC)
{
  Paint(hDC, 0, 0);
}

void CBuffer::Paint(HDC hDC, int winX, int winY)
{
  BitBlt(hDC, winX, winY, m_iWidth, m_iHeight, m_hBufferDC, 0, 0, SRCCOPY);
}

#endif
