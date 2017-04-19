#include "ParallelWidget.h"


ParallelWidget::ParallelWidget(int id)
{
	this->id = id;

	init();
}

ParallelWidget::~ParallelWidget()
{
}

void ParallelWidget::init()
{
	//平行轴控件背景
	backgroundColor = QColor(240, 240, 240);

	this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	//初始化控件绘制对象
	pixmap = new QPixmap(size());

	setNode();

	//绘制控件
	draw();
	update();
	setMouseTracking(true);

	QTimer *testTimer = new QTimer(this);
	connect(testTimer, SIGNAL(timeout()), this, SLOT(update()));
	testTimer->start(500);
}


//绘制控件
void ParallelWidget::draw()
{
	if (!pixmap)
		return;

	pixmap->fill(backgroundColor);	//填充背景色

	QPainter *painter = new QPainter;				//绘制
	QPen pen;//画笔

	const int bound = 2;	//边框宽度
	const int aw = 3;		//轴宽
	QColor acolor = QColor(160, 160, 160, 200);	//画笔颜色,轴颜色
	QRect axis(this->width() / 2 - aw / 2, 2, aw, this->height() - 2);//轴
	pen.setStyle(Qt::PenStyle::SolidLine);
	pen.setWidth(bound);
	pen.setColor(acolor);
	painter->begin(pixmap);
	painter->setPen(pen);
	painter->fillRect(axis, QColor(200, 200, 200, 200));	//轴填充
	painter->drawRect(axis);								//轴边框
	painter->end();
	pen.setWidth(5);//节点边框	

	//绘制节点
	for (int i = 1; i < node.size(); i++)
	{
		pen.setColor(node[i].color);//节点颜色
		painter->begin(pixmap);
		painter->setPen(pen);
		painter->drawEllipse(QPoint(node[i].x, node[i].y), 3, 3);	//轴节点
		painter->end();
	}
}

void ParallelWidget::setNode()
{
	//生成节点
	node.clear();
	node.push_back(Node(65536, 65536));

	int stepy = (this->height() - 60) / (nodeCount - 1);//节点间距离
	int cirx = this->width() / 2;	//节点x坐标
	int ciry = 30;
	for (int i = 0; i < nodeCount; i++)
	{
		Node n(cirx, ciry, QColor(120, 120, 120, 240));
		node.push_back(n);
		ciry += stepy;
	}
}

//鼠标按下
void ParallelWidget::mousePressEvent(QMouseEvent *e)
{
	int idx = fitNode(e->pos());

	pressNode = idx;


}

//鼠标释放
void ParallelWidget::mouseReleaseEvent(QMouseEvent *e)
{
	pressNode = 0;
	update();
}

//鼠标移动
void ParallelWidget::mouseMoveEvent(QMouseEvent *e)
{
	//如果指针移动至节点上，则高亮节点
	int idx = fitNode(e->pos());
	if (0 != idx)
	{
		node[idx].color = QColor(255, 0, 0);
	}
	else
	{
		for (int i = 0; i < node.size(); i++)
		{
			node[i].color = QColor(120, 120, 120, 240);
		}
	}
	draw();

	if (0 != pressNode)
	{
		QPainter *painter = new QPainter;				//绘制
		QPen pen;//画笔
		pen.setStyle(Qt::PenStyle::SolidLine);
		pen.setWidth(1);
		pen.setColor(QColor(200, 0, 0));
		painter->begin(pixmap);
		painter->setPen(pen);
		painter->drawLine(node[pressNode].x, node[pressNode].y, e->x(), e->y());	//轴填充
		painter->end();
	}
	update();

}

//鼠标离开
void ParallelWidget::leaveEvent(QEvent *e)
{
	pressNode = 0;

	draw();
}

//鼠标进入
void ParallelWidget::enterEvent(QEvent *e)
{
	pressNode = 0;

}

//重整尺寸
void ParallelWidget::resizeEvent(QResizeEvent *e)
{
	if (height() > pixmap->height() || width() > pixmap->width())
	{
		QPixmap *newPix = new QPixmap(size());
		newPix->fill(backgroundColor);			//填充背景色
		QPainter p(newPix);
		p.drawPixmap(QPoint(0, 0), *pixmap);
		pixmap = newPix;
	}
	setNode();
	draw();
	QWidget::resizeEvent(e);
}

//重绘客户区
void ParallelWidget::paintEvent(QPaintEvent *e)
{
	draw();
	paraImg();//绘制节点略缩图
	paraLine();
	QPainter painter(this);
	painter.drawPixmap(QPoint(0, 0), *pixmap);

	QWidget::paintEvent(e);
}

int ParallelWidget::fitNode(QPoint pos)
{
	int wr = 10;//识别区半径
	//x坐标是否在识别区
	if ((width() / 2 - wr) < pos.x() && pos.x() < (width() / 2 + wr))
	{
		for (int i = 1; i < node.size(); i++)
		{
			if ((node[i].y - wr) < pos.y() && pos.y() < (node[i].y + wr))
			{
				return i;
			}
		}
	}

	return 0;
}