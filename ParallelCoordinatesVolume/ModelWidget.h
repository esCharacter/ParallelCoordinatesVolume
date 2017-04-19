#ifndef MW
#define MW

#include <QtOpenGL/QtOpenGL>
#include "VolumeControl.h"

using namespace std;

extern vector<int> nodeValue;//参数数据栈
extern vector<vector<QColor>> color3;
extern vector<vector<QColor>> alpha3; 
extern vector<vector<QString>> typeFile;
extern int nodeHistroy[10][10];

class ModelWidget : public QOpenGLWidget
{
public:
	ModelWidget(int id, QWidget* parent = 0);

	GLint iWinWidth;			//窗口尺寸
	GLint iWinHeight;

	void initWidget();

protected:
	/*
	*响应函数，opengl
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
	*环境变量
	*/
	int mouseX, mouseY;			//当前鼠标位置
	bool isMouseDown;			//鼠标是否按下
	int id;
public:
	void setColor(vector<QColor> &c);
	void setShape(vector<QString> &str);
};

#endif 
