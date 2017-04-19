#pragma once
#include "ParallelWidget.h"

extern vector<vector<QColor>> color3;

class ParallelColor :
	public ParallelWidget
{
public:
	ParallelColor(int id);
	~ParallelColor();

	void mousePressEvent(QMouseEvent *e);
	void enterEvent(QEvent *e);

public:
	void paraLine();
	void paraImg();
};

