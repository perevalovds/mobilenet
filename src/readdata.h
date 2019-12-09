#ifndef READDATA_H
#define READDATA_H

#include "ofMain.h"

class ReadData
{
public:
	ReadData(const string &file_name, int nInputWidth, int nInputHeight, int nInputChannel);
	~ReadData();
	float *ReadInput(const string &file_name);
	void ReadMean(const string &file_name);

private:
	int m_nInputSize, m_nInputWidth, m_nInputHeight, m_nInputChannel, m_nImageSize;
	float *m_pfInputData, *m_pfMean;

};


#endif