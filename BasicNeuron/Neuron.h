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
	int _numInput;				//시냅스의 갯수
	double* _inputWeight;		//입력의 가중치
	double* _weightError;		//가중치의 에러를 누적 저장함
	double _learnAlpha;			//민감도(배우는 정도)
};

