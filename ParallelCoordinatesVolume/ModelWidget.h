#ifndef MW
#define MW

#include <QtOpenGL/QtOpenGL>
#include "VolumeControl.h"

using namespace std;

extern vector<int> nodeValue;//��������ջ
extern vector<vector<QColor>> color3;
extern vector<vector<QColor>> alpha3; 
extern vector<vector<QString>> typeFile;
extern int nodeHistroy[10][10];

class ModelWidget : public QOpenGLWidget
{
public:
	ModelWidget(int id, QWidget* parent = 0);

	GLint iWinWidth;			//���ڳߴ�
	GLint iWinHeight;

	void initWidget();

protected:
	/*
	*��Ӧ������opengl
	*/
	void mouseMoveEvent(QMouseEvent *e);
	void mousePressEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
	void mouseDoubleClickEvent(QMouseEvent *e);
	void enterEvent(QEvent *e);

private:
	VolumeControl volume;

	/*
	*OpenGL
	*/
	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);

	/*
	*��������
	*/
	int mouseX, mouseY;			//��ǰ���λ��
	bool isMouseDown;			//����Ƿ���
	int id;
public:
	void setColor(vector<QColor> &c);
	void setShape(vector<QString> &str);
};

#endif 
