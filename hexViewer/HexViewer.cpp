#include "HexViewer.h";
#include <iostream>
#include <fstream>	
#pragma warning(disable: 4996)

HexViewer::HexViewer(const char* name) {
	setName(name);
	fileSize = getFileSize();
	valuesOfBytes = new char[fileSize];
	bytes = new char* [fileSize];
	for (int i = 0; i < fileSize; i++) {
		bytes[i] = new char[2];
	}
	wasLoadedBefore = false;
	std::cout << "File loaded successfully! Size: " << fileSize << " bytes" << std::endl;
}

HexViewer::~HexViewer() {
	delete[] name;
	delete[] valuesOfBytes;

	for (int i = 0; i < fileSize; i++) {
		delete[] bytes[i];
	}
	delete[] bytes;
}

void HexViewer::setName(const char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void HexViewer::charToHex(unsigned char ch, char*& bytes) {
	if (ch != '\0') {
		bytes[0] = hexValues[ch / 16];
		bytes[1] = hexValues[ch % 16];
	}
	else {
		bytes[0] = '0';
		bytes[1] = '0';
	}

}

char HexViewer::hexToChar(const char* hex) const {
	char firstVal = corespondingValue(hex[0]) * 16;
	char secondVal = corespondingValue(hex[1]) * 1;
	return firstVal + secondVal;
}

bool HexViewer::isLetter(char ch) const {
	return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

int HexViewer::getFileSize() const {
	std::fstream file(name, std::ios::in | std::ios::binary);
	int currentPosition = file.tellg();
	file.seekg(0, std::ios::end);
	int result = file.tellg();
	file.seekg(currentPosition);
	return result;
}

void HexViewer::loadBytesAndTheirValues() const {
	for (int i = 0; i < fileSize; i++){
		std::cout<<bytes[i][0];
		std::cout<<bytes[i][1]<<" ";
	}
	std::cout << std::endl;
	for (int i = 0; i < fileSize; i++) {
		if (isLetter(valuesOfBytes[i])) {
			std::cout << valuesOfBytes[i] << "  ";
		}
		else {
			std::cout << '.' << "  ";
		}
	}
	std::cout << std::endl;
}

int HexViewer::corespondingValue(char ch) const{
	for (int i = 0; i < 15; i++){
		if (hexValues[i] == ch) return i;
	}
	return 0;
}

void HexViewer::view() {
	if (!wasLoadedBefore) {
		std::fstream file(name, std::ios::in | std::ios::binary);
		//singed - unsigned char 
		unsigned char buffer;
		for (int i = 0; i < fileSize; i++) {
			file.read((char*)&buffer, sizeof(char));
			charToHex(buffer, bytes[i]);
			valuesOfBytes[i] = buffer;
		}
		wasLoadedBefore = true;
	}

	loadBytesAndTheirValues();
}

void HexViewer::save() {
	std::fstream file(name, std::ios::out | std::ios::binary | std::ios::trunc);
	for (int i = 0; i < fileSize; i++)
	{
	file.write((char*)&valuesOfBytes[i], sizeof(char));
	}
	wasLoadedBefore = false;

	std::cout << "File successfully saved"<<std::endl;
}

void HexViewer::saveAs(const char* fileName) {
	std::fstream file(fileName, std::ios::out | std::ios::binary | std::ios::trunc);
	for (int i = 0; i < fileSize; i++)
	{
		file.write((char*)&valuesOfBytes[i], sizeof(char));
	}
	wasLoadedBefore = false;
	std::cout << "File successfully savedAs: "<< fileName << std::endl;
}

void HexViewer::remove() {
	delete[] bytes[fileSize - 1];
	char* newValues = new char[fileSize - 1];
	for (int i = 0; i < fileSize - 1; i++){
		newValues[i] = valuesOfBytes[i];
	}
	delete[] valuesOfBytes;
	valuesOfBytes = new char[fileSize - 1];
	for (int i = 0; i < fileSize - 1; i++){
		valuesOfBytes[i] = newValues[i];
	}
	delete[] newValues;
	fileSize--;
}

void HexViewer::add(const char* hex) {
	//array
	char* newValues = new char[fileSize +1];
	for (int i = 0; i < fileSize; i++) {
		newValues[i] = valuesOfBytes[i];
	}
	newValues[fileSize] = hexToChar(hex);
	delete[] valuesOfBytes;
	valuesOfBytes = new char[fileSize+1];
	for (int i = 0; i < fileSize + 1; i++) {
		valuesOfBytes[i] = newValues[i];
	}
	delete[] newValues;
	//

	//matrix
	char** newBytes = new char* [fileSize + 1];
	for (int i = 0; i < fileSize; i++) {
		newBytes[i] = new char[2];
		newBytes[i][0] = bytes[i][0];
		newBytes[i][1] = bytes[i][1];
	}
	newBytes[fileSize] = new char[2];
	newBytes[fileSize][0] = hex[0];
	newBytes[fileSize][1] = hex[1];

	for (int i = 0; i < fileSize; i++) {
		delete[] bytes[i];
	}
	delete[] bytes;

	bytes = new char* [fileSize + 1];
	for (int i = 0; i < fileSize + 1; i++) {
		bytes[i] = new char[2];
		bytes[i][0] = newBytes[i][0];
		bytes[i][1] = newBytes[i][1];
	}
	for (int i = 0; i < fileSize + 1; i++) {
		delete[] newBytes[i];
	}
	delete[] newBytes;
	//

	fileSize++;
}

void HexViewer::change(int index, const char* hexValue) {
	bytes[index][0] = hexValue[0];
	bytes[index][1] = hexValue[1];

	valuesOfBytes[index] = hexToChar(hexValue);

	std::cout << "Operation successfully executed!" << std::endl;
}

