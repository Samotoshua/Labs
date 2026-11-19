// Допоміжне малювання засобами Windows. Алгоритм міститься в main.cpp.
#pragma once
#define NOMINMAX
#include <windows.h>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include "gif.h"

const int W = 1200, H = 820;
HDC canvas;
HBITMAP bitmap;
HGDIOBJ oldBitmap, oldFont;
HFONT canvasFont;
unsigned char* pixels;
GifWriter animation = {};
int frameNumber = 0;

void openCanvas() {
    canvas = CreateCompatibleDC(nullptr);
    BITMAPINFO info = {};
    info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    info.bmiHeader.biWidth = W;
    info.bmiHeader.biHeight = -H;
    info.bmiHeader.biPlanes = 1;
    info.bmiHeader.biBitCount = 32;
    info.bmiHeader.biCompression = BI_RGB;
    bitmap = CreateDIBSection(canvas,&info,DIB_RGB_COLORS,(void**)&pixels,nullptr,0);
    oldBitmap = SelectObject(canvas,bitmap);
    canvasFont = CreateFontW(-22,0,0,0,FW_NORMAL,0,0,0,DEFAULT_CHARSET,
        0,0,ANTIALIASED_QUALITY,0,L"Arial");
    oldFont = SelectObject(canvas,canvasFont);
    SetBkMode(canvas,TRANSPARENT);
}
void closeCanvas() {
    SelectObject(canvas,oldFont); SelectObject(canvas,oldBitmap);
    DeleteObject(canvasFont); DeleteObject(bitmap); DeleteDC(canvas);
}
void clearCanvas() {
    RECT area={0,0,W,H}; FillRect(canvas,&area,(HBRUSH)GetStockObject(WHITE_BRUSH));
}
void text(int x,int y,const std::wstring& s,COLORREF color=RGB(0,0,0)) {
    SetTextColor(canvas,color); TextOutW(canvas,x,y,s.c_str(),(int)s.size());
}
void line(int x,int y,int x2,int y2,COLORREF color=RGB(100,100,100)) {
    HPEN pen=CreatePen(PS_SOLID,2,color); HGDIOBJ old=SelectObject(canvas,pen);
    MoveToEx(canvas,x,y,nullptr); LineTo(canvas,x2,y2);
    SelectObject(canvas,old); DeleteObject(pen);
}
void box(int x,int y,int w,int h,COLORREF color,bool point=false) {
    HBRUSH brush=CreateSolidBrush(color);HGDIOBJ old=SelectObject(canvas,brush);
    HGDIOBJ pen=SelectObject(canvas,GetStockObject(NULL_PEN));
    if(point) Ellipse(canvas,x,y,x+w,y+h); else Rectangle(canvas,x,y,x+w,y+h);
    SelectObject(canvas,pen);SelectObject(canvas,old);DeleteObject(brush);
}
void saveBitmap(const char* name) {
    GdiFlush();
    BITMAPFILEHEADER head={};BITMAPINFOHEADER info={};
    head.bfType=0x4D42;head.bfOffBits=sizeof(head)+sizeof(info);
    head.bfSize=head.bfOffBits+W*H*4;
    info.biSize=sizeof(info);info.biWidth=W;info.biHeight=-H;
    info.biPlanes=1;info.biBitCount=32;info.biSizeImage=W*H*4;
    std::ofstream f(name,std::ios::binary);
    f.write((char*)&head,sizeof(head));f.write((char*)&info,sizeof(info));
    f.write((char*)pixels,W*H*4);
}
void beginAnimation() { openCanvas(); GifBegin(&animation,"animation.gif",W,H,35); }
void endAnimation() { GifEnd(&animation); closeCanvas(); }

void drawFrame(const std::vector<int>& a,const std::vector<int>& b,
               int source,int target,long long exp) {
    clearCanvas();
    text(30,15,L"Сортування за розрядами");
    std::wstring status=exp<0?L"Готово":exp==0?L"Початковий масив":L"Розряд: "+std::to_wstring(exp);
    text(30,48,status+L". Червоний — джерело, синій — місце запису.");
    const wchar_t* labels[]={L"A. Гістограма",L"B. Точки",L"C. Послідовність чисел"};
    int maximum=std::max(1,*std::max_element(a.begin(),a.end()));
    for(int mode=0;mode<3;++mode) {
        int top=100+mode*235;
        text(30,top,labels[mode]);
        for(int side=0;side<2;++side) {
            int left=50+side*590, bottom=top+175;
            text(left,top+30,side?L"Допоміжний масив":L"Вхідний масив");
            const auto& values=side?b:a;
            if(mode<2) {
                line(left,bottom-110,left,bottom);line(left,bottom,left+510,bottom);
                text(left+235,bottom+25,L"Індекс");
            }
            for(int i=0;i<(int)values.size();++i) {
                int x=left+10+i*50,v=values[i];
                COLORREF color=side==0&&i==source?RGB(210,30,30):
                    side==1&&i==target?RGB(20,95,215):RGB(110,130,150);
                if(mode==2) text(x,top+110,v<0?L"·":std::to_wstring(v),color);
                else {
                    text(x,bottom+3,std::to_wstring(i));
                    if(v<0) continue;
                    int height=100*v/maximum;
                    if(mode==0) box(x,bottom-std::max(1,height),30,std::max(1,height),color);
                    else box(x,bottom-height-5,10,10,color,true);
                }
            }
        }
    }
    if(frameNumber==5) saveBitmap("step.bmp");
    if(exp<0) saveBitmap("final.bmp");
    GdiFlush();
    std::vector<unsigned char> rgba(W*H*4);
    for(int i=0;i<W*H;++i) {
        rgba[i*4]=pixels[i*4+2];rgba[i*4+1]=pixels[i*4+1];
        rgba[i*4+2]=pixels[i*4];rgba[i*4+3]=255;
    }
    GifWriteFrame(&animation,rgba.data(),W,H,exp<0?150:35);
    ++frameNumber;
}

void saveChart(const std::vector<std::pair<double,double>>& points) {
    openCanvas();clearCanvas();
    text(100,25,L"Залежність часу сортування від кількості елементів");
    double maximum=0;
    for(auto p:points) maximum=std::max(maximum,p.second);
    maximum*=1.15;
    text(20,65,L"Час, мс");
    for(int i=0;i<=5;++i) {
        int y=680-i*110;
        line(110,y,1140,y,RGB(220,220,220));
        std::wostringstream label;
        label << std::fixed << std::setprecision(1) << maximum*i/5;
        text(15,y-12,label.str());
        int x=110+i*206;
        text(x-20,700,std::to_wstring(i*200));
    }
    line(110,130,110,680);line(110,680,1140,680);
    text(440,760,L"Кількість елементів, тисячі");
    int prevX=0,prevY=0;
    for(auto p:points) {
        int x=110+(int)(1030*p.first/1000000), y=680-(int)(550*p.second/maximum);
        if(prevX) line(prevX,prevY,x,y,RGB(30,90,170));
        box(x-4,y-4,8,8,RGB(30,90,170),true);prevX=x;prevY=y;
    }
    saveBitmap("chart.bmp");closeCanvas();
}
