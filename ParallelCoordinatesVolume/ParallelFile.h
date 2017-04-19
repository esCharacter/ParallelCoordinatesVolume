#pragma once
#include "ParallelWidget.h"

extern vector<vector<QString>> typeFile;

class ParallelFile :
	public ParallelWidget
{
public:
	ParallelFile(int id);
	~ParallelFile();

	void mousePressEvent(QMouseEvent *e);
	void enterEvent(QEvent *e);
	void paintEvent(QPaintEvent *);

public:


	void paraLine();
	void paraImg();
};

