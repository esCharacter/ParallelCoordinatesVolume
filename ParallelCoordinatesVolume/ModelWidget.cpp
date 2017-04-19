#include "ModelWidget.h"
#include <QWheelEvent>
#include <freeglut.h>

ModelWidget::ModelWidget(int id, QWidget* parent)
:QOpenGLWidget(parent)
{
	this->id = id;
	initializeGL();
	initWidget();
}

void ModelWidget::initializeGL()
{
	glClearColor(1, 1, 1, 1);//������Ϊ��ɫ
}

void ModelWidget::initWidget()
{
	isMouseDown = false;			//����Ƿ���
}

void ModelWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	float scaleW = float(this->rect().width()) / float(volume.getWidth());
	float scaleH = float(this->rect().height()) / float(volume.getHeight());
	volume.scaleV = scaleW < scaleH ? scaleW : scaleH;
	volume.display();
}

void ModelWidget::resizeGL(int width, int height)
{
	if (0 == height)
	{
		height = 1;
	}
	iWinWidth = (GLint)width;
	iWinHeight = (GLint)height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//ͶӰ��ʽ��͸��ͶӰ
	gluPerspective(60, (GLfloat)iWinWidth / (GLfloat)iWinHeight, 0.1, 100);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
}

void ModelWidget::mouseMoveEvent(QMouseEvent *e)
{

}
void ModelWidget::mousePressEvent(QMouseEvent *e)
{

}
void ModelWidget::mouseReleaseEvent(QMouseEvent *e)
{

}
void ModelWidget::mouseDoubleClickEvent(QMouseEvent *e)
{

}

void ModelWidget::setColor(vector<QColor> &c)
{
	ColorV cv[3];
	for (int i = 0; i < 3; i++)
	{
		cv[i].r = float(c[i].red()) / 255;
		cv[i].g = float(c[i].green()) / 255;
		cv[i].b = float(c[i].blue()) / 255;
		cv[i].a = float(c[i].alpha()) / 255;
	}
	volume.setColor(cv);
}

void ModelWidget::setShape(vector<QString> &str)
{
	for (int i = 0; i < 3; i++)
	{
		QStringList strList = str[i].split(',');
		if (str.size() < 2)
			return;

		QString shape = strList[0];
		int len = strList[1].toInt();
		if (shape == "cube")
		{
			
		}
		else if (shape == "sphere")
		{
			
		}
	}
}

//������
void ModelWidget::enterEvent(QEvent *e)
{
	//���������ѡ�����
	if (3 == nodeValue.size())
	{
		//������ɫ��͸���Ȳ���
		vector<QColor> c;
		for (int i = 0; i < 3; i++)
		{
			QColor color(color3[nodeValue[1]][i]);
			color.setAlpha(alpha3[nodeValue[2]][i].alpha());

			c.push_back(color);
		}
		setColor(c);//������ɫ��͸����

		//vector<QString> str;
		//for (int i = 0; i < 3; i++)
		//{
		//	str.push_back(typeFile[nodeValue[0]][i]);
		//}

		volume.setShape(nodeValue[0]);//������״

		volume.update();

		//�������,ÿ��id��Ӧһ�����
		for (int i = 0; i < 3; i++)
		{
			nodeHistroy[this->id][i] = nodeValue[i];
		}
		nodeValue.clear();
		update();
	}


}