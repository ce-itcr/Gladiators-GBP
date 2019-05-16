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
//		System.out.println("population[0]: " + Gladiators.getInstance().population[0]);
//		System.out.println("population[58]: " + Gladiators.getInstance().population[58]);
		Gladiators.getInstance().sortGladiatorPopulation();
		for (int i = 0; i < numOfGladiatorsToGenerate; i++) {
//			System.out.println("population size: " + Gladiators.getInstance().getPopulationSize());
//			System.out.println("random: " + Gladiators.getInstance().population[0]);
//			System.out.println("Fittest: " + Gladiators.getInstance().getFittestGladiator());
			Gladiator newGladiator = Gladiators.getInstance().getFittestGladiator().crossover(Gladiators.getInstance().population[random.nextInt(Gladiators.getInstance().getPopulationSize())]);
			Gladiators.getInstance().replaceGladiator(newGladiator);
		}
		Gladiators.getInstance().printGladiatorPopulation();
	}
	
	public Gladiator [] collectionToGladiatorArray(Collection<GladiatorSend> gladiatorCollection) {
//		GladiatorSend [] gladiatorSendArray = new GladiatorSend [gladiatorCollection.size()];
		Gladiator [] gladiatorArray = new Gladiator [Gladiators.getInstance().getPopulationSize()];
//		System.out.println("gladiatorArray: " + gladiatorArray.length);
		int i = 0;
//		for (int c = 0; c < gladiatorArray.length-1; c++)
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
	
//	private Gladiator [] getGladiatorArray(GladiatorSend [] gladiatorSendArray) {
//		Gladiator [] gladiatorArray = new Gladiator [gladiatorSendArray.length];
//		for (int i = 0; i < gladiatorSendArray.length-1; i++) {
//			gladiatorArray[i].getChromosome().setAge(gladiatorSendArray[i].getAge());
//			gladiatorArray[i].getChromosome().setHealth(gladiatorSendArray[i].getHealth());
//			gladiatorArray[i].getChromosome().setResistanceLowerBody(gladiatorSendArray[i].getResistanceLowerBody());
//			gladiatorArray[i].getChromosome().setResistanceUpperBody(gladiatorSendArray[i].getResistanceUpperBody());
//			gladiatorArray[i].getChromosome().setDodgeChance(gladiatorSendArray[i].getDodgeChance());
//		}
//		return gladiatorArray;
//	}

}
