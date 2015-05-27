#include "Neuron.h"

Neuron::Neuron()
{
}

Neuron::Neuron(int numOfInput, double alpha)
{
	_numInput = numOfInput;
	_learnAlpha = alpha;
	_inputWeight = new double[_numInput + 1];	//마지막은 상수 가중치 이다.
	_weightError = new double[_numInput + 1];	

	for (int i = 0; i < _numInput + 1; i++)
	{
		_inputWeight[i] = ((double)rand() / RAND_MAX) * 2 - 1;
		_weightError[i] = 0.0;
	}
}

Neuron::~Neuron()
{
	delete[] _inputWeight;
	delete[] _weightError;
}

void Neuron::init(int numOfInput, double alpha)
{
	_numInput = numOfInput;
	_learnAlpha = alpha;
	_inputWeight = new double[_numInput + 1];	//마지막은 상수 가중치 이다.
	_weightError = new double[_numInput + 1];

	for (int i = 0; i < _numInput + 1; i++)
	{
		_inputWeight[i] = ((double)rand() / RAND_MAX) * 2 - 1;
		_weightError[i] = 0.0;
	}
}

double Neuron::work(double input[])
{
	double sum = 0;
	for (int i = 0; i < _numInput; i++)
		sum += _inputWeight[i] * input[i];
	sum += _inputWeight[_numInput] * 1.0;		//상수 가중치를 계산한다.
	
	return sigmoid(sum);
}

void Neuron::learn(double input[], double target)
{
	double output = work(input);				//일단 계산해본다.
	double output_error = output - target;		//정답과의 오차를 계산

	for (int i = 0; i < _numInput; i++)			//오차를 누적한다.
		_weightError[i] += output_error * input[i] * output * (1 - output);
	_weightError[_numInput] += output_error * 1.0 * output * (1 - output);
}

void Neuron::fix()
{
	for (int i = 0; i < _numInput + 1; i++)		//누적한 오차에 alpha를 곱해 학습한다.
	{
		_inputWeight[i] -= _learnAlpha * _weightError[i];
		_weightError[i] = 0.0;
	}
}