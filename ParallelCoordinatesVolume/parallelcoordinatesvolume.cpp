#include "parallelcoordinatesvolume.h"

ParallelCoordinatesVolume::ParallelCoordinatesVolume(QWidget *parent)
: QMainWindow(parent)
{
	ui.setupUi(this);
	initWidget();
}

ParallelCoordinatesVolume::~ParallelCoordinatesVolume()
{
}

void ParallelCoordinatesVolume::initWidget()
{
	// 平行轴控件
	ParallelWidget* parallelFile = new ParallelFile(0);
	ParallelWidget* parallelColor = new ParallelColor(1);
	ParallelWidget* parallelAlpha = new ParallelAlpha(2);
	ui.parallelLayoutFile->addWidget(parallelFile);
	ui.parallelLayoutColor->addWidget(parallelColor);
	ui.parallelLayoutAlpha->addWidget(parallelAlpha);

	// 设置视图区背景
	QPalette pal(ui.ViewArea->palette());
	pal.setColor(QPalette::Background, QColor(120, 120, 160));
	ui.ViewArea->setPalette(pal);
	ui.ViewArea->setAutoFillBackground(true);

	//视图1
	ModelWidget* img1 = new ModelWidget(0);
	ui.viewStack->addWidget(img1);

	ModelWidget* img2 = new ModelWidget(1);
	ui.viewStack->addWidget(img2);

	ModelWidget* img3 = new ModelWidget(2);
	ui.viewStack->addWidget(img3);

}