#include <iostream>
#include "HexViewer.h"
#include <fstream>
int main() {
	//int x = 25409;
	//int y = 15555;
	//std::ofstream file("myData.dat", std::ios::binary);
	//file.write((const char*)&x, sizeof(x));
	//file.write((const char*)&y, sizeof(y));

	
	HexViewer hexViewer("myData.dat");
	HexViewer hexViewer2("otherData.dat");
	//hexViewer.view();
	//hexViewer.remove();
	//hexViewer.remove();
	//hexViewer.add("F1");
	//hexViewer.add("15");
	//hexViewer.add("00");
	//hexViewer.view();
	//hexViewer.saveAs("otherData.dat");
	hexViewer.view();
	hexViewer2.view();
//	hexViewer2.saveAs("myData.dat");
}