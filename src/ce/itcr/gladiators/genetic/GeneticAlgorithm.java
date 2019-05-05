package ce.itcr.gladiators.genetic;

import java.util.Collection;
import java.util.Random;

import ce.itcr.gladiators.entities.GladiatorSend;
import ce.itcr.gladiators.genetic.resources.Gladiator;
import ce.itcr.gladiators.genetic.resources.Gladiators;

public class GeneticAlgorithm {

	Gladiators gladiators = new Gladiators();
	Random random = new Random();
	
	public void newGeneration(Collection<GladiatorSend> gladiatorCollection, int numOfGladiatorsToGenerate) {
		gladiators.population = collectionToGladiatorArray(gladiatorCollection);
		gladiators.sortGladiatorPopulation();
		Gladiator newGladiator;
		for (int i = 0; i < numOfGladiatorsToGenerate; i++) {
			newGladiator = gladiators.getFittestGladiator().crossover(gladiators.population[random.nextInt(gladiators.getPopulationSize()-1)]);
			gladiators.replaceGladiator(newGladiator);
		}
	}
	
	private Gladiator [] collectionToGladiatorArray(Collection<GladiatorSend> gladiatorCollection) {
//		GladiatorSend [] gladiatorSendArray = new GladiatorSend [gladiatorCollection.size()];
		Gladiator [] gladiatorArray = new Gladiator [gladiatorCollection.size()];
		int i = 0;
		for (GladiatorSend gladiatorSend : gladiatorCollection) {
			gladiatorArray[i].getChromosome().setAge(gladiatorSend.getAge());
			gladiatorArray[i].getChromosome().setHealth(gladiatorSend.getHealth());
			gladiatorArray[i].getChromosome().setResistanceLowerBody(gladiatorSend.getResistanceLowerBody());
			gladiatorArray[i].getChromosome().setResistanceUpperBody(gladiatorSend.getResistanceUpperBody());
			gladiatorArray[i].getChromosome().setDodgeChance(gladiatorSend.getDodgeChance());
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
