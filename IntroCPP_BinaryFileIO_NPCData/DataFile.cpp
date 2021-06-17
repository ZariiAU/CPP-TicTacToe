#include "DataFile.h"
#include <fstream>
using namespace std;

DataFile::DataFile()
{
	recordCount = 0;
}

DataFile::~DataFile()
{
	Clear();
}

void DataFile::AddRecord(string imageFilename, string name, int age)
{
	Image i = LoadImage(imageFilename.c_str());

	recordCount++;
}

DataFile::Record* DataFile::GetRecord(int index)
{
	ifstream infile(filename, ios::binary);

	recordCount = 0;
	infile.read((char*)&recordCount, sizeof(int));

	currentRecord = index;

	for (int i = 0; i <= currentRecord; i++)
	{
		int nameSize = 0;
		int ageSize = 0;
		int width = 0, height = 0, format = 0, imageSize = 0;

		infile.read((char*)&width, sizeof(int));
		infile.read((char*)&height, sizeof(int));

		infile.read((char*)&nameSize, sizeof(int));
		infile.read((char*)&ageSize, sizeof(int));

		imageSize = sizeof(Color) * width * height;

		if (i < currentRecord) 
		{
			infile.seekg(streamsize(imageSize) + streamsize(nameSize) + streamsize(ageSize), ios::cur);
		}
		else 
		{
			char* imgdata = new char[imageSize];
			infile.read(imgdata, imageSize);

			Image img = LoadImageEx((Color*)imgdata, width, height);
			char* name = new char[nameSize];
			int age = 0;

			infile.read((char*)name, nameSize);
			infile.read((char*)&age, ageSize);

			record.image = img;
			record.name = string(name, nameSize);
			record.age = age;

			delete[] imgdata;
			delete[] name;

			return &record;
		}
	}
	return nullptr;
}

void DataFile::Save(string filename)
{
	ofstream outfile(filename, ios::binary);

	/*int recordCount = records.size();
	outfile.write((char*)&recordCount, sizeof(int));

	for (int i = 0; i < recordCount; i++)
	{		
		Color* imgdata = GetImageData(records[i]->image);
				
		int imageSize = sizeof(Color) * records[i]->image.width * records[i]->image.height;
		int nameSize = records[i]->name.length();
		int ageSize = sizeof(int);

		outfile.write((char*)&records[i]->image.width, sizeof(int));
		outfile.write((char*)&records[i]->image.height, sizeof(int));
		
		outfile.write((char*)&nameSize, sizeof(int));
		outfile.write((char*)&ageSize, sizeof(int));

		outfile.write((char*)imgdata, imageSize);
		outfile.write((char*)records[i]->name.c_str(), nameSize);
		outfile.write((char*)&records[i]->age, ageSize);
	}*/

	outfile.close();
}

void DataFile::Load(string filename)
{
	Clear();

	ifstream infile(filename, ios::binary);

	recordCount = 0;
	infile.read((char*)&recordCount, sizeof(int));

	this->filename = filename;

	infile.close();
}

void DataFile::Clear()
{
	filename = "";
	recordCount = 0;
}