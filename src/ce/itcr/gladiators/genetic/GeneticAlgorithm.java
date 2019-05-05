package ce.itcr.gladiators.genetic;

import java.util.Collection;
import java.util.Random;

import ce.itcr.gladiators.entities.GladiatorSend;
import ce.itcr.gladiators.genetic.resources.Gladiator;
import ce.itcr.gladiators.genetic.resources.Gladiators;

public class GeneticAlgorithm {

	Random random = new Random();
	
	public void newGeneration(Collection<GladiatorSend> gladiatorCollection, int numOfGladiatorsToGenerate) {
		Gladiators.getInstance().population = collectionToGladiatorArray(gladiatorCollection);
		Gladiators.getInstance().sortGladiatorPopulation();
		Gladiator newGladiator;
		for (int i = 0; i < numOfGladiatorsToGenerate; i++) {
			newGladiator = Gladiators.getInstance().getFittestGladiator().crossover(Gladiators.getInstance().population[random.nextInt(Gladiators.getInstance().getPopulationSize()-1)]);
			Gladiators.getInstance().replaceGladiator(newGladiator);
		}
	}
	
	private Gladiator [] collectionToGladiatorArray(Collection<GladiatorSend> gladiatorCollection) {
//		GladiatorSend [] gladiatorSendArray = new GladiatorSend [gladiatorCollection.size()];
		Gladiator [] gladiatorArray = new Gladiator [100];
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
