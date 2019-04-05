#pragma once
#include "picGnssfile.h"
#include "GlobalConfig.h"
#include "database.h"
#include "DescriptorQuery.h"
#include "graph\networkflow.h"

enum BackendType{NetworkFlowTopology, BruteForce, Ordinary};

class VisualLocalization
{
public:
	VisualLocalization(GlobalConfig& config);
	virtual ~VisualLocalization();	
	/// ����ڶ���ͼ�������ӣ�һ����ConvNet-based Descriptor��������������Ӿ���λ
	bool featureLocalize(const bool & outPR = true);
	
private:
	int backendType;
	int distanceType;
	double costHidden;

	// ѵ��������(�����¼��·��)
	Descriptorbase* descriptorbase;

	// ���Լ�����
	DescriptorQuery* descriptorquery;
	std::vector<bool> keyGT, keyPredict, keyGPS;
	bool withGPS;
	std::string descriptor;

	// get a distance matrix, which is as follows
	//   ----> database
	//  |
	//  |
	//  V
	//  query images
	NetworkFlow* netFlow;

};
