#include"stdafx.h"
#include<math.h>
BITMAPINFO* lpBitsInfo;
BOOL loadbitmap(char*BmpFileName){
	FILE*fp;
	fp = fopen(BmpFileName,"rb");
	if(!fp)
		return FALSE;
	BITMAPFILEHEADER bitmapfileheader;
	BITMAPINFOHEADER bitmapinfoheader;
	fread(&bitmapfileheader,sizeof(BITMAPFILEHEADER),1,fp);
	fread(&bitmapinfoheader,sizeof(BITMAPINFOHEADER),1,fp);
	int w = bitmapinfoheader.biWidth;
	int h = bitmapinfoheader.biHeight;
	DWORD tColor;
	if(bitmapinfoheader.biClrUsed==0){
		if(bitmapinfoheader.biBitCount==24)
			tColor = 0;
		else
			tColor =(DWORD)pow(2,bitmapinfoheader.biBitCount); 	
	}
	else
		tColor = bitmapinfoheader.biClrUsed;

	long size = 40+4*tColor+(w*bitmapinfoheader.biBitCount+31)/32*4*h;
	lpBitsInfo =(BITMAPINFO*) malloc(size);
	
	fseek(fp,sizeof(BITMAPFILEHEADER),SEEK_SET);
	fread((char*)lpBitsInfo,size,1,fp);//!!如果没有将lpBitsInfo转为char*,会发生16色和二值图偏移的情况
	lpBitsInfo->bmiHeader.biClrUsed = tColor;
	return TRUE;
}