#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <freeglut.h>

#define EPSILON 0.000001

typedef struct{
	float r;
	float g;
	float b;
	float a;
} ColorV;

class VolumeControl
{
public:
	VolumeControl(int w = 400, int h = 450);
	~VolumeControl();

private:
	float* Image;
	int width;
	int height;
	ColorV color[3];
	void GenerateVolume1(int *Data, int* Dim);//生成体数据
	void GenerateVolume2(int *Data, int* Dim);//生成体数据
	void GenerateVolume3(int *Data, int* Dim);//生成体数据

private:
	void GenCube(int x, int y, int z, int side, int density, int *Data, int *Dim);//生成正方体数据
	void GenSphere(int x, int y, int z, int radius, int density, int *Data, int *Dim);//生成球体数据
	void Classify(float* CData, int *Data, int *Dim);//数据分类
	void RotationMatrix(float *R, float *eye, float *center, float *up);//求取图像空间到物体空间变换的旋转矩阵
	void Composite(float *rgba, int x0, int y0, float *CData, int *Dim, float *R, float *T);//合成像素颜色值
	bool Intersection(float *startpos, float *pos, float *dir, int *Dim);//求光线与包围盒交点坐标
	void TrInterpolation(float *rgba, float *pos, float *CData, int *Dim);//三线性插值
	bool CheckinBox(float *point, int *Dim);//判断点是否在包围盒内
	void MatrixmulVec(float *c, float *a, float *b);//矩阵向量乘积
	void CrossProd(float *c, float *a, float *b);//向量叉乘
	void Normalize(float *norm, float *a);//向量归一化
	void GenerateVolume(int *Data, int* Dim);//生成体数据

public:
	float scaleV = 1.0;
	int shape = 0;
	void display();//显示图像
	void setShape(int i);
	void update();
	void setColor(ColorV* c);
	int getWidth();
	int getHeight();
};

