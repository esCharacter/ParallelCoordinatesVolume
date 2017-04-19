#pragma once
#include "ParallelWidget.h"

extern vector<vector<QColor>> alpha3;

class ParallelAlpha :
	public ParallelWidget
{
public:
	ParallelAlpha(int id);
	~ParallelAlpha();

	void mousePressEvent(QMouseEvent *e);
	void enterEvent(QEvent *e);
	void paintEvent(QPaintEvent *);

	void paraLine();
	void paraImg();
};

