#pragma once

#include <cstdlib>
#include <cmath>

#define sigmoid(x) (1.0 / (1.0 + exp(-(x))))

class Neuron
{
public:
	Neuron();
	Neuron(int numOfInput,  double alpha);
	virtual ~Neuron();

	void init(int numOfInput, double alpha);
	double work(double input[]);
	void learn(double input[], double target);
	void fix();
private:
	int _numInput;				//�ó����� ����
	double* _inputWeight;		//�Է��� ����ġ
	double* _weightError;		//����ġ�� ������ ���� ������
	double _learnAlpha;			//�ΰ���(���� ����)
};

