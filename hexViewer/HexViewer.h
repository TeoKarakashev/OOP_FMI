#pragma once

class HexViewer {

	char* name;
	char** bytes;
	char* valuesOfBytes;
	int fileSize;
	bool wasLoadedBefore;
	char hexValues[16] = { '0', '1', '2', '3', '4','5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

	void setName(const char* name);
	void charToHex(unsigned char ch, char*& bytes);
	char hexToChar(const char* hex) const;
	int getFileSize() const;
	bool isLetter(char ch) const;
	void loadBytesAndTheirValues() const;
	int corespondingValue(char) const; 


public:
	HexViewer(const char* name);
	~HexViewer();

	void view() ;
	void change(int index, const char* hexValue);
	void remove();
	void add(const char* hexValue);
	void save();
	void saveAs(const char* name);
};
