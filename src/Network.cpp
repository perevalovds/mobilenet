#include "Network.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

Network::Network() {

}

void Network::setup(string path) {
	path = ofToDataPath(path) + "/";
	cout << "Initializing Network..." << endl;

	m_Readdata = new ReadData((path + "means").c_str(), 224, 224, 3);

    m_Layers_bn = new Layers_Bn(3, 32, 224, 2, (path + "conv1.weights").c_str(), (path + "conv1_bn.mean").c_str(), (path + "conv1_bn.variance").c_str(), (path + "conv1_bn.filler").c_str(),
        (path + "conv1_bn.bias_filler").c_str());

    m_Layers_ds2_1 = new Layers_Ds(32, 64, 112, 1, (path + "conv2_1_dw.weights").c_str(), (path + "conv2_1_bn_dw.mean").c_str(), (path + "conv2_1_bn_dw.variance").c_str(), (path + "conv2_1_bn_dw.filler").c_str(),
        (path + "conv2_1_bn_dw.bias_filler").c_str(), (path + "conv2_1_sep.weights").c_str(), (path + "conv2_1_bn_sep.mean").c_str(), (path + "conv2_1_bn_sep.variance").c_str(), (path + "conv2_1_bn_sep.filler").c_str(),
        (path + "conv2_1_bn_sep.bias_filler").c_str());

    m_Layers_ds2_2 = new Layers_Ds(64, 128, 112, 2, (path + "conv2_2_dw.weights").c_str(), (path + "conv2_2_bn_dw.mean").c_str(), (path + "conv2_2_bn_dw.variance").c_str(), (path + "conv2_2_bn_dw.filler").c_str(),
        (path + "conv2_2_bn_dw.bias_filler").c_str(), (path + "conv2_2_sep.weights").c_str(), (path + "conv2_2_bn_sep.mean").c_str(), (path + "conv2_2_bn_sep.variance").c_str(), (path + "conv2_2_bn_sep.filler").c_str(),
        (path + "conv2_2_bn_sep.bias_filler").c_str());

    m_Layers_ds3_1 = new Layers_Ds(128, 128, 56, 1, (path + "conv3_1_dw.weights").c_str(), (path + "conv3_1_bn_dw.mean").c_str(), (path + "conv3_1_bn_dw.variance").c_str(), (path + "conv3_1_bn_dw.filler").c_str(),
        (path + "conv3_1_bn_dw.bias_filler").c_str(), (path + "conv3_1_sep.weights").c_str(), (path + "conv3_1_bn_sep.mean").c_str(), (path + "conv3_1_bn_sep.variance").c_str(), (path + "conv3_1_bn_sep.filler").c_str(),
        (path + "conv3_1_bn_sep.bias_filler").c_str());

    m_Layers_ds3_2 = new Layers_Ds(128, 256, 56, 2, (path + "conv3_2_dw.weights").c_str(), (path + "conv3_2_bn_dw.mean").c_str(), (path + "conv3_2_bn_dw.variance").c_str(), (path + "conv3_2_bn_dw.filler").c_str(),
        (path + "conv3_2_bn_dw.bias_filler").c_str(), (path + "conv3_2_sep.weights").c_str(), (path + "conv3_2_bn_sep.mean").c_str(), (path + "conv3_2_bn_sep.variance").c_str(), (path + "conv3_2_bn_sep.filler").c_str(),
        (path + "conv3_2_bn_sep.bias_filler").c_str());

    m_Layers_ds4_1 = new Layers_Ds(256, 256, 28, 1, (path + "conv4_1_dw.weights").c_str(), (path + "conv4_1_bn_dw.mean").c_str(), (path + "conv4_1_bn_dw.variance").c_str(), (path + "conv4_1_bn_dw.filler").c_str(),
        (path + "conv4_1_bn_dw.bias_filler").c_str(), (path + "conv4_1_sep.weights").c_str(), (path + "conv4_1_bn_sep.mean").c_str(), (path + "conv4_1_bn_sep.variance").c_str(), (path + "conv4_1_bn_sep.filler").c_str(),
        (path + "conv4_1_bn_sep.bias_filler").c_str());

    m_Layers_ds4_2 = new Layers_Ds(256, 512, 28, 2, (path + "conv4_2_dw.weights").c_str(), (path + "conv4_2_bn_dw.mean").c_str(), (path + "conv4_2_bn_dw.variance").c_str(), (path + "conv4_2_bn_dw.filler").c_str(),
        (path + "conv4_2_bn_dw.bias_filler").c_str(), (path + "conv4_2_sep.weights").c_str(), (path + "conv4_2_bn_sep.mean").c_str(), (path + "conv4_2_bn_sep.variance").c_str(), (path + "conv4_2_bn_sep.filler").c_str(),
        (path + "conv4_2_bn_sep.bias_filler").c_str());

    m_Layers_ds5_1 = new Layers_Ds(512, 512, 14, 1, (path + "conv5_1_dw.weights").c_str(), (path + "conv5_1_bn_dw.mean").c_str(), (path + "conv5_1_bn_dw.variance").c_str(), (path + "conv5_1_bn_dw.filler").c_str(),
        (path + "conv5_1_bn_dw.bias_filler").c_str(), (path + "conv5_1_sep.weights").c_str(), (path + "conv5_1_bn_sep.mean").c_str(), (path + "conv5_1_bn_sep.variance").c_str(), (path + "conv5_1_bn_sep.filler").c_str(),
        (path + "conv5_1_bn_sep.bias_filler").c_str());

    m_Layers_ds5_2 = new Layers_Ds(512, 512, 14, 1, (path + "conv5_2_dw.weights").c_str(), (path + "conv5_2_bn_dw.mean").c_str(), (path + "conv5_2_bn_dw.variance").c_str(), (path + "conv5_2_bn_dw.filler").c_str(),
        (path + "conv5_2_bn_dw.bias_filler").c_str(), (path + "conv5_2_sep.weights").c_str(), (path + "conv5_2_bn_sep.mean").c_str(), (path + "conv5_2_bn_sep.variance").c_str(), (path + "conv5_2_bn_sep.filler").c_str(),
        (path + "conv5_2_bn_sep.bias_filler").c_str());

    m_Layers_ds5_3 = new Layers_Ds(512, 512, 14, 1, (path + "conv5_3_dw.weights").c_str(), (path + "conv5_3_bn_dw.mean").c_str(), (path + "conv5_3_bn_dw.variance").c_str(), (path + "conv5_3_bn_dw.filler").c_str(),
        (path + "conv5_3_bn_dw.bias_filler").c_str(), (path + "conv5_3_sep.weights").c_str(), (path + "conv5_3_bn_sep.mean").c_str(), (path + "conv5_3_bn_sep.variance").c_str(), (path + "conv5_3_bn_sep.filler").c_str(),
        (path + "conv5_3_bn_sep.bias_filler").c_str());

    m_Layers_ds5_4 = new Layers_Ds(512, 512, 14, 1, (path + "conv5_4_dw.weights").c_str(), (path + "conv5_4_bn_dw.mean").c_str(), (path + "conv5_4_bn_dw.variance").c_str(), (path + "conv5_4_bn_dw.filler").c_str(),
        (path + "conv5_4_bn_dw.bias_filler").c_str(), (path + "conv5_4_sep.weights").c_str(), (path + "conv5_4_bn_sep.mean").c_str(), (path + "conv5_4_bn_sep.variance").c_str(), (path + "conv5_4_bn_sep.filler").c_str(),
        (path + "conv5_4_bn_sep.bias_filler").c_str());

    m_Layers_ds5_5 = new Layers_Ds(512, 512, 14, 1, (path + "conv5_5_dw.weights").c_str(), (path + "conv5_5_bn_dw.mean").c_str(), (path + "conv5_5_bn_dw.variance").c_str(), (path + "conv5_5_bn_dw.filler").c_str(),
        (path + "conv5_5_bn_dw.bias_filler").c_str(), (path + "conv5_5_sep.weights").c_str(), (path + "conv5_5_bn_sep.mean").c_str(), (path + "conv5_5_bn_sep.variance").c_str(), (path + "conv5_5_bn_sep.filler").c_str(),
        (path + "conv5_5_bn_sep.bias_filler").c_str());

    m_Layers_ds5_6 = new Layers_Ds(512, 1024, 14, 2, (path + "conv5_6_dw.weights").c_str(), (path + "conv5_6_bn_dw.mean").c_str(), (path + "conv5_6_bn_dw.variance").c_str(), (path + "conv5_6_bn_dw.filler").c_str(),
        (path + "conv5_6_bn_dw.bias_filler").c_str(), (path + "conv5_6_sep.weights").c_str(), (path + "conv5_6_bn_sep.mean").c_str(), (path + "conv5_6_bn_sep.variance").c_str(), (path + "conv5_6_bn_sep.filler").c_str(),
        (path + "conv5_6_bn_sep.bias_filler").c_str());

    m_Layers_ds6 = new Layers_Ds(1024, 1024, 7, 1, (path + "conv6_dw.weights").c_str(), (path + "conv6_bn_dw.mean").c_str(), (path + "conv6_bn_dw.variance").c_str(), (path + "conv6_bn_dw.filler").c_str(),
        (path + "conv6_bn_dw.bias_filler").c_str(), (path + "conv6_sep.weights").c_str(), (path + "conv6_bn_sep.mean").c_str(), (path + "conv6_bn_sep.variance").c_str(), (path + "conv6_bn_sep.filler").c_str(),
        (path + "conv6_bn_sep.bias_filler").c_str());

    m_Poollayer6 = new GlobalPoolLayer(1024, 7);

    //m_Convlayer7 = new ConvLayer((path + "fc7.weights").c_str(), 1024, 12, 1, 1, 0, 1, 1, (path + "fc7.biases").c_str());
    m_Fclayer7 = new FcLayer((path + "fc7.weights").c_str(), (path + "fc7.biases").c_str(), 1024, 12);

    m_Sigmoidlayer8 = new SigmoidLayer(12);

	
	m_vcClass.push_back("室内");
	m_vcClass.push_back("人像");
	m_vcClass.push_back("LDR");
	m_vcClass.push_back("绿植");
	m_vcClass.push_back("商场");
	m_vcClass.push_back("沙滩");
	m_vcClass.push_back("逆光");
	m_vcClass.push_back("日落");
	m_vcClass.push_back("蓝天");
	m_vcClass.push_back("雪景");
	m_vcClass.push_back("夜景");
	m_vcClass.push_back("文本");

	cout << "Initializing Done..." << endl;
	cout << endl;

}


Network::~Network()
{
	delete m_Readdata;
    delete m_Layers_bn;
    delete m_Layers_ds1;
    delete m_Layers_ds2_1;
    delete m_Layers_ds2_2;
    delete m_Layers_ds3_1;
    delete m_Layers_ds3_2;
    delete m_Layers_ds4_1;
    delete m_Layers_ds4_2;
    delete m_Layers_ds5_1;
    delete m_Layers_ds5_2;
    delete m_Layers_ds5_3;
    delete m_Layers_ds5_4;
    delete m_Layers_ds5_5;
    delete m_Layers_ds5_6;
    delete m_Layers_ds6;
    delete m_Poollayer6;
    //delete m_Convlayer7;
    delete m_Fclayer7;
    delete m_Sigmoidlayer8;
}


float *Network::Forward(const string &file_name)
{

    m_Layers_bn->forward(m_Readdata->ReadInput(file_name));

    m_Layers_ds2_1->forward(m_Layers_bn->GetOutput());
    m_Layers_ds2_2->forward(m_Layers_ds2_1->GetOutput());
    
    m_Layers_ds3_1->forward(m_Layers_ds2_2->GetOutput());
    m_Layers_ds3_2->forward(m_Layers_ds3_1->GetOutput());

    m_Layers_ds4_1->forward(m_Layers_ds3_2->GetOutput());
    m_Layers_ds4_2->forward(m_Layers_ds4_1->GetOutput());

    m_Layers_ds5_1->forward(m_Layers_ds4_2->GetOutput());
    m_Layers_ds5_2->forward(m_Layers_ds5_1->GetOutput());
    m_Layers_ds5_3->forward(m_Layers_ds5_2->GetOutput());
    m_Layers_ds5_4->forward(m_Layers_ds5_3->GetOutput());
    m_Layers_ds5_5->forward(m_Layers_ds5_4->GetOutput());
    m_Layers_ds5_6->forward(m_Layers_ds5_5->GetOutput());

    m_Layers_ds6->forward(m_Layers_ds5_6->GetOutput());

    m_Poollayer6->forward(m_Layers_ds6->GetOutput());

    //m_Convlayer7->forward(m_Poollayer6->GetOutput());
    m_Fclayer7->forward(m_Poollayer6->GetOutput());

    //m_Sigmoidlayer8->forward(m_Convlayer7->GetOutput());
    m_Sigmoidlayer8->forward(m_Fclayer7->GetOutput());

    float *pfOutput = m_Sigmoidlayer8->GetOutput();
	vector <int> argmax;
	vector <float> Max;

    //int nOutputSize = m_Convlayer7->GetOutputSize();
    int nOutputSize = m_Fclayer7->GetOutputSize();
	for (int i = 0; i<nOutputSize; i++)
	{

		if (pfOutput[i] > 0.5)
		{
			argmax.push_back(i);
			Max.push_back(pfOutput[i]);
		}
	}
	cout << endl;
	for (int i = 0; i < argmax.size(); i++)
	{
		cout << Max[i] << ": " << argmax[i] << ": " << m_vcClass[argmax[i]] << endl;
	}
	cout << endl;
    
    return pfOutput;
}
