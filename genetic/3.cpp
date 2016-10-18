#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ga/ga.h>
using namespace std;

struct TVW
{
	int V;
	int W;
};

int VWCount, MaxW;
float SumV, SumW;
TVW VW[1000];

// This is the declaration of our obj function.
float Objective(GAGenome &);

int main(void)
{
	int i;
	
	cout << "Knapsack Problem !!!" << endl;
	
	srand((unsigned)time(NULL));
	GARandomSeed((unsigned int)rand());
	
	fstream in;
	in.open("data1.txt", (ios::in));
	if(!in)
	{
		cout << "파일 지정이 잘 못 되었습니다.\n";
		exit (1);
	}
	
	in >> VWCount >> MaxW;
	for (i = 0; i < VWCount; i++)
		in >> VW[i].V >> VW[i].W;
	
	/////////////////////////
	int length    = VWCount;
	int popsize  = 200;
	int ngen     = 1000;
	float pmut   = 0.001;
	float pcross = 0.9;
	/////////////////////////
	
	GA1DBinaryStringGenome genome(length, Objective);
	genome.crossover(GA1DBinaryStringGenome::TwoPointCrossover);
	
	GASimpleGA ga(genome);
	
	ga.selector(GARouletteWheelSelector());
	ga.populationSize(popsize);
	ga.nGenerations(ngen);
	ga.pMutation(pmut);
	ga.pCrossover(pcross);
	ga.selectScores(GAStatistics::AllScores);
	ga.scoreFrequency(5);
	ga.flushFrequency(10);
	GASigmaTruncationScaling trunc;
	ga.scaling(trunc);
	ga.maximize();
	ga.initialize();
	
	int EvalCount = 0;
	
	while(!ga.done())
	{
		ga.step();
		EvalCount++;
		if (EvalCount % 100 == 0)
			cout << " " << EvalCount;
		cout.flush();
	}
	
	// ga.evolve();
	cout << "\n\nThe GA found: " << ga.statistics().bestIndividual() << endl;
	cout << "Fitness : " << ga.statistics().bestIndividual().score() << endl;
	cout << "SumV : " << SumV << "\n" << "SumW : "
	<<SumW << ",    " << "MaxW : " << MaxW << endl;
	
	return 0;
}

///////////////////////////////////////////////////////////////
// Objective Function
float Objective(GAGenome &g)
{
	GA1DBinaryStringGenome &genome = (GA1DBinaryStringGenome &)g;
	
	SumV = 0.0;
	SumW = 0.0;
	
	for(int i=0; i<genome.length(); i++)
	{
		if(genome.gene(i) == 1)
		{
			SumV += VW[i].V;
			SumW += VW[i].W;
		}
	}
	
	if (SumW > MaxW)
		SumV = SumV - 10 * (SumW - MaxW);
	
	return SumV;
}
