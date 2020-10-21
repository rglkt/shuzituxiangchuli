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
void gray(){
	if (lpBitsInfo==NULL) return;
	int bitBitCount = lpBitsInfo->bmiHeader.biBitCount;
	if(bitBitCount!=24) return;
	int w = lpBitsInfo->bmiHeader.biWidth;
	int h = lpBitsInfo->bmiHeader.biHeight;
	int lineBytes = (w*bitBitCount+31)/32*4;
	int gray_lineBytes = (w*8+31)/32*4;
	int size = 40+4*256+gray_lineBytes*h;
	BITMAPINFO* gray_bf = (BITMAPINFO*)malloc(size);
	BYTE *gray_bits =(BYTE*)&gray_bf->bmiColors[256];
	gray_bf->bmiHeader = lpBitsInfo->bmiHeader;
	gray_bf->bmiHeader.biBitCount = 8;
	gray_bf->bmiHeader.biClrUsed = 256;
	for(int k=0;k<256;k++){
		gray_bf->bmiColors[k].rgbBlue=gray_bf->bmiColors[k].rgbGreen=gray_bf->bmiColors[k].rgbRed=k;
		gray_bf->bmiColors[k].rgbReserved=255;
	}
	BYTE*B,*G,*R;
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++){
				B =(BYTE*)lpBitsInfo->bmiColors+(h-i-1)*lineBytes+j*3;
				G = B+1;
				R = G+1;
				BYTE avg = (*B+*G+*R)/3;
				*B=*R=*G=avg;
				*(gray_bits+(h-i-1)*gray_lineBytes+j)=avg;
	}	 
		lpBitsInfo = gray_bf;
}
void pixel(int i,int j){
	int w = lpBitsInfo->bmiHeader.biWidth;
	int h = lpBitsInfo->bmiHeader.biHeight;
	int lineBytes = (w*lpBitsInfo->bmiHeader.biBitCount+31)/32*4;
	char str[256];
	BYTE*pixel=NULL;
	int r,g,b;
	switch(lpBitsInfo->bmiHeader.biBitCount){
	case 24:
		pixel = (BYTE*)lpBitsInfo->bmiColors+(h-i-1)*lineBytes+j*3;
		b = *pixel;
		g = *(pixel+1);
		r = *(pixel+2);
		sprintf(str,"RGB(%d,%d,%d)",r,g,b);
		AfxMessageBox(str);
		break;
	case 8:
		pixel = (BYTE*)lpBitsInfo->bmiColors+(h-i-1)*lineBytes+j;
		if(lpBitsInfo->bmiColors[128].rgbRed==128&&lpBitsInfo->bmiColors[128].rgbGreen==128&&lpBitsInfo->bmiColors[128].rgbBlue==128)
			sprintf(str,"灰度图，亮度：%d",*pixel);
		else{
		r = lpBitsInfo->bmiColors[*pixel].rgbRed;
		g = lpBitsInfo->bmiColors[*pixel].rgbGreen;
		b = lpBitsInfo->bmiColors[*pixel].rgbBlue;
		sprintf(str,"RGB(%d,%d,%d)",r,g,b);
		}
		AfxMessageBox(str);
		break;
	case 4:
		pixel = ((BYTE*)lpBitsInfo->bmiColors+(h-i-1)*lineBytes+j/2);
		if(j%2==0)
			*pixel=*pixel>>4;
		else
			*pixel=*pixel&(240);
		
		//*pixel = *pixel&(15<<(4*((j+1)%2)));
		//*pixel = *pixel>>(4*((j+1)%2));
		r = lpBitsInfo->bmiColors[*pixel].rgbRed;
		g = lpBitsInfo->bmiColors[*pixel].rgbGreen;
		b = lpBitsInfo->bmiColors[*pixel].rgbBlue;
		sprintf(str,"RGB(%d,%d,%d)",r,g,b);
		AfxMessageBox(str);
		break;

	case 1:
		pixel = ((BYTE*)lpBitsInfo->bmiColors+(h-i-1)*lineBytes+j/8);
		*pixel = *pixel&(1<<(7-j%8));
		if(*pixel!=0)
			sprintf(str,"%s","前景");
		else
			sprintf(str,"%s","背景");
		AfxMessageBox(str);
		break;
	}
}