#ifndef PARALLELCOORDINATESVOLUME_H
#define PARALLELCOORDINATESVOLUME_H

#include <QtWidgets/QMainWindow>
#include <memory>
#include "ui_parallelcoordinatesvolume.h"
#include "ModelWidget.h"
#include "ParallelColor.h"
#include "ParallelFile.h"
#include "ParallelAlpha.h"

class ParallelCoordinatesVolume : public QMainWindow
{
	Q_OBJECT

public:
	ParallelCoordinatesVolume(QWidget *parent = 0);
	~ParallelCoordinatesVolume();

private:
	Ui::ParallelCoordinatesVolumeClass ui;

	void initWidget();

private:
	
};

#endif // PARALLELCOORDINATESVOLUME_H
