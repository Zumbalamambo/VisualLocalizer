#pragma once
#include <string>
#include "Header.h"


// ���ģʽ - ���� singleton
class GlobalConfig 
{
	// ˽�е���ľ�̬��Ա���������ڶ��������
	static GlobalConfig config;

	// ˽�й��캯�����������캯������ֵ������
	GlobalConfig(std::string yaml);
	GlobalConfig(const GlobalConfig&) ;
	GlobalConfig& operator=(GlobalConfig) {};

	// read configuration file
	bool readConfig();

	cv::FileStorage fs;

public:
	static GlobalConfig& instance() { return config; }
	virtual ~GlobalConfig() {};
	bool getValid() const { return valid; };

	// the configs
	std::string pathRec;
	std::string pathTest;
	std::string backendType;
	int sequenceNum;
	int distanceType;
	double costHidden;
	
	// config valid
	bool valid;
};

