package ce.itcr.gladiators.genetic;

import java.util.Collection;
import java.util.Random;

import ce.itcr.gladiators.entities.GladiatorSend;
import ce.itcr.gladiators.genetic.resources.Chromosome;
import ce.itcr.gladiators.genetic.resources.Gladiator;
import ce.itcr.gladiators.genetic.resources.Gladiators;

public class GeneticAlgorithm {

	Random random = new Random();
	
	public void newGeneration(Collection<GladiatorSend> gladiatorCollection, int numOfGladiatorsToGenerate) {
		Gladiators.getInstance().printGladiatorPopulation();
		Gladiators.getInstance().population = collectionToGladiatorArray(gladiatorCollection);
		Gladiators.getInstance().sortGladiatorPopulation();
		for (int i = 0; i < numOfGladiatorsToGenerate; i++) {
			Gladiator newGladiator = Gladiators.getInstance().getFittestGladiator().crossover(Gladiators.getInstance().population[random.nextInt(Gladiators.getInstance().getPopulationSize()/3)]);
			Gladiators.getInstance().replaceGladiator(newGladiator);
		}
		Gladiators.getInstance().printGladiatorPopulation();
	}
	
	public Gladiator [] collectionToGladiatorArray(Collection<GladiatorSend> gladiatorCollection) {
		Gladiator [] gladiatorArray = new Gladiator [Gladiators.getInstance().getPopulationSize()];
		int i = 0;
		for (GladiatorSend gladiatorSend : gladiatorCollection) {
			gladiatorArray[i] = new Gladiator(new Chromosome(0));
			gladiatorArray[i].getChromosome().setAge(gladiatorSend.getAge());
			gladiatorArray[i].getChromosome().setHealth(gladiatorSend.getHealth());
			gladiatorArray[i].getChromosome().setResistanceLowerBody(gladiatorSend.getResistanceLowerBody());
			gladiatorArray[i].getChromosome().setResistanceUpperBody(gladiatorSend.getResistanceUpperBody());
			gladiatorArray[i].getChromosome().setDodgeChance(gladiatorSend.getDodgeChance());
			gladiatorArray[i].setFitness();
			i++;
		}
		return gladiatorArray;
	}
}
