#include <stdio.h>
#include <ctime>
#include "Neuron.h"

int main()
{
	srand((unsigned)time(NULL));
	
	Neuron* nr = new Neuron(2, 0.1);

	//샘플 데이터
	double sampleInput[4][2] = { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } };
	double sampleOutput[4] = { 0, 1, 1, 0 };

	for (int i = 0; i < 5000; i++)
	{
		for (int j = 0; j < 4; j++)
			nr->learn(sampleInput[j], sampleOutput[j]);
		nr->fix();

		//결과를 출력
		if ((i + 1) % 500 == 0)
		{
			printf("-학습 %d 번-\n", i + 1);
			for (int j = 0; j < 4; j++)
				printf("%.0lf %.0lf : %lf\n", sampleInput[j][0], sampleInput[j][1], nr->work(sampleInput[j]));
		}
	}

	delete nr;
	/*
	Neuron nr[2][2];

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			nr[i][j].init(2, 0.1f);
		}
	}*/
	return 0;
}