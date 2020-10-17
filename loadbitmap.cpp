#include"stdafx.h"
#include<math.h>
void*lpBitsInfo = NULL;
BOOL loadbitmap(char*bitmap){
	FILE*fp;
	BITMAPFILEHEADER bitmapfileheader;
	BITMAPINFOHEADER bitmapinfoheader;
	fp = fopen(bitmap,"rb");
	if(!fp)
		return FALSE;
	fread(&bitmapfileheader,sizeof(BITMAPFILEHEADER),1,fp);
	fread(&bitmapinfoheader,sizeof(BITMAPINFOHEADER),1,fp);
	int h = bitmapinfoheader.biHeight;
	int w = bitmapinfoheader.biWidth;
	int tColor;
	if(bitmapinfoheader.biClrUsed == 0)
		tColor = pow(2,bitmapinfoheader.biClrUsed);
	else
		tColor = bitmapinfoheader.biClrUsed;

	int size = 40 + tColor*4 + (w*bitmapinfoheader.biBitCount+31)/32*4*h;
	fseek(fp,14,SEEK_SET);
	lpBitsInfo = malloc(size);
	fread(lpBitsInfo,size,1,fp);
	return TRUE;
}