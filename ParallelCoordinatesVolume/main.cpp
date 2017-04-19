#include "parallelcoordinatesvolume.h"
#include <QtWidgets/QApplication>

vector<int> nodeValue;
int nodeHistroy[10][10] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
vector<vector<QColor>> color3;
vector<vector<QColor>> alpha3;
vector<vector<QString>> typeFile;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ParallelCoordinatesVolume w;
	w.show();
	return a.exec();
}
