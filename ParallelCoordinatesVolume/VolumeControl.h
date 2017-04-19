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
	void GenerateVolume1(int *Data, int* Dim);//����������
	void GenerateVolume2(int *Data, int* Dim);//����������
	void GenerateVolume3(int *Data, int* Dim);//����������

private:
	void GenCube(int x, int y, int z, int side, int density, int *Data, int *Dim);//��������������
	void GenSphere(int x, int y, int z, int radius, int density, int *Data, int *Dim);//������������
	void Classify(float* CData, int *Data, int *Dim);//���ݷ���
	void RotationMatrix(float *R, float *eye, float *center, float *up);//��ȡͼ��ռ䵽����ռ�任����ת����
	void Composite(float *rgba, int x0, int y0, float *CData, int *Dim, float *R, float *T);//�ϳ�������ɫֵ
	bool Intersection(float *startpos, float *pos, float *dir, int *Dim);//��������Χ�н�������
	void TrInterpolation(float *rgba, float *pos, float *CData, int *Dim);//�����Բ�ֵ
	bool CheckinBox(float *point, int *Dim);//�жϵ��Ƿ��ڰ�Χ����
	void MatrixmulVec(float *c, float *a, float *b);//���������˻�
	void CrossProd(float *c, float *a, float *b);//�������
	void Normalize(float *norm, float *a);//������һ��
	void GenerateVolume(int *Data, int* Dim);//����������

public:
	float scaleV = 1.0;
	int shape = 0;
	void display();//��ʾͼ��
	void setShape(int i);
	void update();
	void setColor(ColorV* c);
	int getWidth();
	int getHeight();
};

