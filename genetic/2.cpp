#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ga/ga.h>
using namespace std;

float Objective(GAGenome &g);

int main() {
	cout << "Function Optimization !!!" << endl;

	srand((unsigned)time(NULL));
	GARandomSeed((unsigned int)rand());

	GABin2DecPhenotype map;

	map.add (16, -5.12f, 5.12f);// 16bit로 -5.12~5.12표현
	map.add (16, -5.12f, 5.12f);
	map.add (16, -5.12f, 5.12f);

	int popsize  = 200;
	int ngen     = 500;
	float pmut   = 0.001;
	float pcross = 0.9;

	GABin2DecGenome genome(map, Objective);
	genome.crossover(GABin2DecGenome::TwoPointCrossover);

	GASimpleGA ga(genome);

	ga.selector(GARouletteWheelSelector());
	ga.populationSize(popsize);
	ga.nGenerations(ngen);
	ga.pMutation(pmut);
	ga.pCrossover(pcross);
	ga.selectScores(GAStatistics::AllScores);
	ga.scoreFrequency(5);
	ga.flushFrequency(10);
	ga.scoreFilename("ouput.txt");
	GASigmaTruncationScaling trunc; 
	ga.scaling(trunc);
	ga.maximize();
	ga.initialize();

	int EvalCount = 0;

	while(!ga.done()) {
		ga.step();
		EvalCount++;
		if (EvalCount % 100 == 0)
			cout << " " << EvalCount;
		cout.flush();
	}

	// ga.evolve();

	cout << "\n\nThe GA found: " << ga.statistics().bestIndividual() << endl;
	cout << "Fitness : " << ga.statistics().bestIndividual().score() << endl;

	return 0;
}

float Objective(GAGenome &g) {
	GABin2DecGenome & genome = (GABin2DecGenome &)g;

	float value = 0;

	value += genome.phenotype(0) * genome.phenotype(0);
	value += genome.phenotype(1) * genome.phenotype(1);
	value += genome.phenotype(2) * genome.phenotype(2);

	return value;
}