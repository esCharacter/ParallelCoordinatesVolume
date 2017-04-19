#include "ParallelFile.h"



ParallelFile::ParallelFile(int id) :ParallelWidget(id)
{
	vector<QString> f;
	typeFile.push_back(f);

	vector<QString> f1;
	f1.push_back("cube,200");
	f1.push_back("sphere,80");
	f1.push_back("cube,60");
	typeFile.push_back(f1);

	vector<QString> f2;
	f2.push_back("cube,200");
	f2.push_back("cube,80");
	f2.push_back("cube,60");
	typeFile.push_back(f2);

	vector<QString> f3;
	f3.push_back("cube,200");
	f3.push_back("cube,80");
	f3.push_back("sphere,60");
	typeFile.push_back(f3);
}


ParallelFile::~ParallelFile()
{
}


//鼠标按下
void ParallelFile::mousePressEvent(QMouseEvent *e)
{
	nodeValue.clear();//重新开始选择

	//选择节点
	int idx = fitNode(e->pos());
	if (0 != idx)
	{
		nodeValue.push_back(idx);
	}

	ParallelWidget::mousePressEvent(e);
}

//鼠标进入
void ParallelFile::enterEvent(QEvent *e)
{
	ParallelWidget::enterEvent(e);
}


//重绘客户区
void ParallelFile::paintEvent(QPaintEvent *e)
{
	ParallelWidget::paintEvent(e);
}

void ParallelFile::paraLine()
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
		painter->drawLine(node[nodeHistroy[i][0]].x, node[nodeHistroy[i][0]].y, this->width()*1.5, node[nodeHistroy[i][1]].y);	//0-1
		painter->end();
	}


}

void ParallelFile::paraImg()
{
	QPainter *painter = new QPainter;				//绘制
	QPen pen;//画笔
	QPen pen2;//边框画笔
	QColor shapeColor(200, 50, 100);//图形颜色
	pen.setStyle(Qt::PenStyle::SolidLine);
	pen.setWidth(3);
	pen.setColor(shapeColor);
	pen2.setStyle(Qt::PenStyle::SolidLine);
	pen2.setWidth(2);
	pen2.setColor(QColor(230, 230, 230));
	painter->begin(pixmap);
	//对每个节点，绘制略缩图
	for (int i = 1; i < node.size(); i++)
	{
		const int iw = 18;
		const int ih = 18;
		for (int j = 0; j < 3; j++)
		{	
			painter->setPen(pen);
			QStringList strList = typeFile[i][j].split(',');
			if (strList[0] == "cube")
			{
				painter->drawRect(QRect(node[i].x + (j + 1) * iw+3*j, node[i].y, iw, ih));
			}
			else if (strList[0] == "sphere")
			{
				painter->drawEllipse(QRect(node[i].x + (j + 1) * iw+j*3, node[i].y, iw, ih));
			}

		}

		painter->setPen(pen2);
		painter->drawRect(node[i].x + iw-3, node[i].y-2, iw * 3+12, ih+5);//边框
	}
	painter->end();
}