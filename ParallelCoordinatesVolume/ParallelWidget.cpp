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
	//ƽ����ؼ�����
	backgroundColor = QColor(240, 240, 240);

	this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	//��ʼ���ؼ����ƶ���
	pixmap = new QPixmap(size());

	setNode();

	//���ƿؼ�
	draw();
	update();
	setMouseTracking(true);

	QTimer *testTimer = new QTimer(this);
	connect(testTimer, SIGNAL(timeout()), this, SLOT(update()));
	testTimer->start(500);
}


//���ƿؼ�
void ParallelWidget::draw()
{
	if (!pixmap)
		return;

	pixmap->fill(backgroundColor);	//��䱳��ɫ

	QPainter *painter = new QPainter;				//����
	QPen pen;//����

	const int bound = 2;	//�߿���
	const int aw = 3;		//���
	QColor acolor = QColor(160, 160, 160, 200);	//������ɫ,����ɫ
	QRect axis(this->width() / 2 - aw / 2, 2, aw, this->height() - 2);//��
	pen.setStyle(Qt::PenStyle::SolidLine);
	pen.setWidth(bound);
	pen.setColor(acolor);
	painter->begin(pixmap);
	painter->setPen(pen);
	painter->fillRect(axis, QColor(200, 200, 200, 200));	//�����
	painter->drawRect(axis);								//��߿�
	painter->end();
	pen.setWidth(5);//�ڵ�߿�	

	//���ƽڵ�
	for (int i = 1; i < node.size(); i++)
	{
		pen.setColor(node[i].color);//�ڵ���ɫ
		painter->begin(pixmap);
		painter->setPen(pen);
		painter->drawEllipse(QPoint(node[i].x, node[i].y), 3, 3);	//��ڵ�
		painter->end();
	}
}

void ParallelWidget::setNode()
{
	//���ɽڵ�
	node.clear();
	node.push_back(Node(65536, 65536));

	int stepy = (this->height() - 60) / (nodeCount - 1);//�ڵ�����
	int cirx = this->width() / 2;	//�ڵ�x����
	int ciry = 30;
	for (int i = 0; i < nodeCount; i++)
	{
		Node n(cirx, ciry, QColor(120, 120, 120, 240));
		node.push_back(n);
		ciry += stepy;
	}
}

//��갴��
void ParallelWidget::mousePressEvent(QMouseEvent *e)
{
	int idx = fitNode(e->pos());

	pressNode = idx;


}

//����ͷ�
void ParallelWidget::mouseReleaseEvent(QMouseEvent *e)
{
	pressNode = 0;
	update();
}

//����ƶ�
void ParallelWidget::mouseMoveEvent(QMouseEvent *e)
{
	//���ָ���ƶ����ڵ��ϣ�������ڵ�
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
		QPainter *painter = new QPainter;				//����
		QPen pen;//����
		pen.setStyle(Qt::PenStyle::SolidLine);
		pen.setWidth(1);
		pen.setColor(QColor(200, 0, 0));
		painter->begin(pixmap);
		painter->setPen(pen);
		painter->drawLine(node[pressNode].x, node[pressNode].y, e->x(), e->y());	//�����
		painter->end();
	}
	update();

}

//����뿪
void ParallelWidget::leaveEvent(QEvent *e)
{
	pressNode = 0;

	draw();
}

//������
void ParallelWidget::enterEvent(QEvent *e)
{
	pressNode = 0;

}

//�����ߴ�
void ParallelWidget::resizeEvent(QResizeEvent *e)
{
	if (height() > pixmap->height() || width() > pixmap->width())
	{
		QPixmap *newPix = new QPixmap(size());
		newPix->fill(backgroundColor);			//��䱳��ɫ
		QPainter p(newPix);
		p.drawPixmap(QPoint(0, 0), *pixmap);
		pixmap = newPix;
	}
	setNode();
	draw();
	QWidget::resizeEvent(e);
}

//�ػ�ͻ���
void ParallelWidget::paintEvent(QPaintEvent *e)
{
	draw();
	paraImg();//���ƽڵ�����ͼ
	paraLine();
	QPainter painter(this);
	painter.drawPixmap(QPoint(0, 0), *pixmap);

	QWidget::paintEvent(e);
}

int ParallelWidget::fitNode(QPoint pos)
{
	int wr = 10;//ʶ�����뾶
	//x�����Ƿ���ʶ����
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