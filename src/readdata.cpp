#include "readdata.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <ctime>
#include <cassert>
#include <fstream>

using namespace std;

ReadData::ReadData(const string &file_name, int nInputWidth, int nInputHeight, int nInputChannel):
			m_nInputWidth(nInputWidth), m_nInputHeight(nInputHeight), m_nInputChannel(nInputChannel)
{
	m_nImageSize = nInputWidth * nInputHeight;
	m_nInputSize = nInputWidth * nInputHeight * nInputChannel;
	m_pfInputData = new float[m_nInputSize];
	m_pfMean = new float[m_nInputSize];
    ReadMean(file_name);
}

ReadData::~ReadData()
{
	delete[] m_pfInputData;
	delete[] m_pfMean;
}

float *ReadData::ReadInput(const string &file_name)
{
	cout << "Reading Picture: " << file_name << "..." << endl;

	ofPixels pixels;
	ofLoadImage(pixels, file_name);

	//const char *pstrImageName = ofToDataPath(file_name).c_str();


	//CvSize czSize;
	//IplImage *pSrcImage = cvLoadImage(pstrImageName, CV_LOAD_IMAGE_UNCHANGED);
	//IplImage *pDstImage = NULL;
	//czSize.width = m_nInputWidth;
	//czSize.height = m_nInputHeight;

	//pDstImage = cvCreateImage(czSize, pSrcImage->depth, pSrcImage->nChannels);
	//cvResize(pSrcImage, pDstImage, CV_INTER_LINEAR);

	int w = m_nInputWidth;
	int h = m_nInputHeight;

	pixels.setImageType(OF_IMAGE_COLOR);
	pixels.resize(w, h, OF_INTERPOLATE_BILINEAR);

	unsigned char *pucData = pixels.getData(); //pDstImage->imageData;
	int nChannel = 3; // pDstImage->nChannels;

	for(int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)	{
			int ind1 = i * w + j;
			int ind3 = 3 * (i * w + j);
			m_pfInputData[ind1] = (float)pucData[ind3 + 0] - m_pfMean[ind1];
			m_pfInputData[ind1 + m_nImageSize] = (float)pucData[ind3 + 1] - m_pfMean[ind1 + m_nImageSize];
			m_pfInputData[ind1 + 2 * m_nImageSize] = (float)pucData[ind3 + 2] - m_pfMean[ind1 + 2 * m_nImageSize];
		}
	}
	cout << "Reading Picture Done..." << endl;

	return m_pfInputData;
}

void ReadData::ReadMean(const string &file_name)
{
	int nMsize, nMreadsize;
	FILE *pM;
    pM = fopen(ofToDataPath(file_name).c_str(), "rb");

	assert(pM != NULL);

	nMsize = m_nInputSize;

	nMreadsize = fread(m_pfMean, sizeof(float), nMsize, pM);

	fclose(pM);
}