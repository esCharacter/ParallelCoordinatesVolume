#pragma once
#include <qwidget.h>
#include <QMouseEvent>
#include <QColor>
#include <QPixmap>
#include <QPoint>
#include <QPainter>
#include <vector>
#include <qtimer.h>
#include "afx.h"

using namespace std;

extern vector<int> nodeValue;//参数数据栈
extern int nodeHistroy[10][10];

typedef struct ND{
	int x;
	int y;
	QColor color;

public:
	ND(int x, int y, QColor c = QColor(0, 0, 0))
	{
		this->x = x; this->y = y; this->color = c;
	}
} Node;

class ParallelWidget :public QWidget
{
	Q_OBJECT
public:
	ParallelWidget(int id);
	~ParallelWidget();

protected:
	void init();
	void draw();

public:
	void mouseReleaseEvent(QMouseEvent *);
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
	void resizeEvent(QResizeEvent *);
	void paintEvent(QPaintEvent *);
	void enterEvent(QEvent *e);
	void leaveEvent(QEvent *);

	int fitNode(QPoint pos);
	void setNode();
	virtual void paraLine() = 0;
	virtual void paraImg() = 0;

protected:
	int id;
	int x;//客户区横坐标
	int y;//客户区纵坐标
	int pressNode = 0;
	QColor backgroundColor;//控件背景色

	QPixmap *pixmap;//控件绘制对象

	vector<Node> node;//节点,索引0置空

public:
	int nodeCount = 3;
};

