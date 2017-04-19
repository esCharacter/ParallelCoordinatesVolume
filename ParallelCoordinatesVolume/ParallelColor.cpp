#include "ParallelColor.h"


ParallelColor::ParallelColor(int id) :ParallelWidget(id)
{
	vector<QColor> color0;
	color3.push_back(color0);

	vector<QColor> color1;
	color1.push_back(QColor(255, 255, 255));
	color1.push_back(QColor(255, 0, 0));
	color1.push_back(QColor(0, 0, 255));
	color3.push_back(color1);

	vector<QColor> color2;
	color2.push_back(QColor(255, 250, 240));
	color2.push_back(QColor(255, 255, 0.0));
	color2.push_back(QColor(255, 0.0, 255));
	color3.push_back(color2);

	vector<QColor> color33;
	color33.push_back(QColor(0, 255, 255));
	color33.push_back(QColor(255, 0.0, 0.0));
	color33.push_back(QColor(255, 255, 1.0));
	color3.push_back(color33);


}

ParallelColor::~ParallelColor()
{
}


//鼠标按下
void ParallelColor::mousePressEvent(QMouseEvent *e)
{
	//选择节点
	int idx = fitNode(e->pos());

	if (2 == nodeValue.size())
	{
		if (nodeValue.back() != idx)
		{
			nodeValue.pop_back();
		}
	}

	ParallelWidget::mousePressEvent(e);
}

//鼠标进入
void ParallelColor::enterEvent(QEvent *e)
{
	if (1 != nodeValue.size())
		return;

	QPoint globalPoint = QCursor::pos();					//鼠标全局坐标
	QPoint curPoint = this->mapFromGlobal(globalPoint);		//鼠标对话框内坐标

	//选择节点
	int idx = fitNode(curPoint);
	if (0 != idx)
	{
		nodeValue.push_back(idx);
	}

	ParallelWidget::enterEvent(e);
}

void ParallelColor::paraLine()
{
	QPainter *painter = new QPainter;				//绘制
	QPen pen;//画笔
	pen.setStyle(Qt::PenStyle::SolidLine);
	pen.setWidth(2);


	for (int i = 0; i < 3; i++)
	{
		if (nodeHistroy[i][0] == 0 || nodeHistroy[i][1] == 0)
			continue;

		switch (i)
		{
		case 0:pen.setColor(QColor(255, 0, 0)); break;
		case 1:pen.setColor(QColor(255, 255, 0)); break;
		default:pen.setColor(QColor(0, 255, 255));
		}
		painter->begin(pixmap);
		painter->setPen(pen);
		painter->drawLine(-this->width() / 2, node[nodeHistroy[i][0]].y, node[nodeHistroy[i][1]].x, node[nodeHistroy[i][1]].y);	//0-1
		painter->drawLine(node[nodeHistroy[i][1]].x, node[nodeHistroy[i][1]].y, this->width()*1.5, node[nodeHistroy[i][2]].y);	//1-2
		painter->end();
	}
}

void ParallelColor::paraImg()
{
	QPainter *painter = new QPainter;				//绘制
	QPen pen;//画笔
	pen.setStyle(Qt::PenStyle::SolidLine);
	pen.setWidth(2);
	pen.setColor(QColor(200, 200, 200));
	painter->begin(pixmap);
	//对每个节点，绘制略缩图
	for (int i = 1; i < node.size(); i++)
	{
		QRect img[3];//不同颜色的略缩图
		const int iw = 18;
		const int ih = 18;
		for (int j = 0; j < 3; j++)
		{
			img[j] = QRect(node[i].x + (j + 1) * iw, node[i].y, iw, ih);

			painter->fillRect(img[j], color3[i][j]);
		}
		painter->setPen(pen);
		painter->drawRect(node[i].x + iw, node[i].y, iw * 3, ih);//边框
	}
	painter->end();
}