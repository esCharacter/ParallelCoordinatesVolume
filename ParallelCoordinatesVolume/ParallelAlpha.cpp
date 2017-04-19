#include "ParallelAlpha.h"


ParallelAlpha::ParallelAlpha(int id) :ParallelWidget(id)
{

	vector<QColor> color0;
	alpha3.push_back(color0);

	vector<QColor> color1;
	color1.push_back(QColor(0.0, 0.0, 0.0, 1));
	color1.push_back(QColor(0.0, 0.0, 0.0, 3));
	color1.push_back(QColor(0.0, 0.0, 0.0, 13));
	alpha3.push_back(color1);

	vector<QColor> color2;
	color2.push_back(QColor(0.0, 0.0, 0.0, 2));
	color2.push_back(QColor(0.0, 0.0, 0.0, 4));
	color2.push_back(QColor(0.0, 0.0, 0.0, 12));
	alpha3.push_back(color2);

	vector<QColor> color33;
	color33.push_back(QColor(0.0, 0.0, 0.0, 5));
	color33.push_back(QColor(0.0, 0.0, 0.0, 6));
	color33.push_back(QColor(0.0, 0.0, 0.0, 15));
	alpha3.push_back(color33);
}


ParallelAlpha::~ParallelAlpha()
{
}

//��갴��
void ParallelAlpha::mousePressEvent(QMouseEvent *e)
{
	//ѡ��ڵ�
	int idx = fitNode(e->pos());
	if (3 == nodeValue.size())
	{
		if (nodeValue.back() != idx)
		{
			nodeValue.pop_back();
		}
	}

	ParallelWidget::mousePressEvent(e);
}

//������
void ParallelAlpha::enterEvent(QEvent *e)
{
	if (2 != nodeValue.size())
		return;

	QPoint globalPoint = QCursor::pos();					//���ȫ������
	QPoint curPoint = this->mapFromGlobal(globalPoint);		//���Ի���������

	//ѡ��ڵ�
	int idx = fitNode(curPoint);
	if (0 != idx)
	{
		nodeValue.push_back(idx);
	}

	ParallelWidget::enterEvent(e);
}

//�ػ�ͻ���
void ParallelAlpha::paintEvent(QPaintEvent *e)
{
	if (3 == node.size())
	{
		QPainter painter(this);
		QPen pen;//����
		pen.setStyle(Qt::PenStyle::DashDotLine);
		pen.setWidth(2);
		pen.setColor(QColor(255, 0, 0, 150));
		painter.setPen(pen);

		QLine line(0, 0, 1, 1);
		painter.drawLine(line);//����
	}


	ParallelWidget::paintEvent(e);
}

void ParallelAlpha::paraLine()
{
	QPainter *painter = new QPainter;				//����
	QPen pen;//����
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
		painter->drawLine(-this->width() / 2, node[nodeHistroy[i][1]].y, node[nodeHistroy[i][2]].x, node[nodeHistroy[i][2]].y);	//1-2
		painter->drawLine(node[nodeHistroy[i][2]].x, node[nodeHistroy[i][2]].y, this->width(), node[i + 1].y);	//2--
		painter->end();
	}


}

void ParallelAlpha::paraImg()
{
	QPainter *painter = new QPainter;				//����
	QPen pen;//����
	QPen pen2;//����
	pen.setStyle(Qt::PenStyle::SolidLine);
	pen.setWidth(2);
	pen.setColor(QColor(200, 200, 200));
	pen2.setColor(QColor(0, 150, 150, 255));
	painter->begin(pixmap);
	//��ÿ���ڵ㣬��������ͼ
	for (int i = 1; i < node.size(); i++)
	{
		QRect img[3];//����ͼ
		const int iw = 18;
		const int ih = 18;
		for (int j = 0; j < 3; j++)
		{
			img[j] = QRect(node[i].x + (j + 1) * iw, node[i].y, iw, ih);

			painter->fillRect(img[j], QColor(0, 0, 0, alpha3[i][j].alpha()));//��ͬ͸���ȵ�����ͼ
			painter->setPen(pen2);
			painter->drawText(node[i].x + (j + 1) * iw + 3, node[i].y - 3, QString("%1").arg(alpha3[i][j].alpha()));//͸����ֵ
		}
		painter->setPen(pen);
		painter->drawRect(node[i].x + iw, node[i].y, iw * 3, ih);//�߿�
	}
	painter->end();
}