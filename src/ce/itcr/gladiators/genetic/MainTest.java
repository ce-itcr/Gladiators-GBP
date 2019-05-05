package ce.itcr.gladiators.genetic;

import java.util.Random;

import ce.itcr.gladiators.genetic.resources.Gladiator;
import ce.itcr.gladiators.genetic.resources.Gladiators;

public class MainTest {

	public static void main(String[] args) throws InterruptedException {
		Random random = new Random();
//		Towers towers = new Towers();
//		towers.generateTowersList(10);
//		towers.printTowersList();
		Gladiators gladiators = new Gladiators();
		gladiators.generateRandomPopulation();
		gladiators.sortGladiatorPopulation();
		System.out.println("**************************************************************************");
		gladiators.printGladiatorPopulation();
		System.out.println("**************************************************************************");
		Gladiator finalGladiator = gladiators.getFittestGladiator().crossover(gladiators.population[random.nextInt(gladiators.getPopulationSize()-1)]);
//		System.out.println("New Gladiator Fitness: " + finalGladiator.getFitness());
		for (int i = 0; i < 100; i++) {
//			System.out.println("---------------------------------");
//			System.out.println("Final Gladiator Fitness: " + gladiators.getFittestGladiator().getFitness());
//			System.out.println("First Gladiator Fitness: " + gladiators.population[0].getFitness());
			finalGladiator = finalGladiator.crossover(gladiators.population[random.nextInt(gladiators.getPopulationSize()-1)]);
//			System.out.println("New Gladiator Fitness: " + finalGladiator.getFitness());
			gladiators.replaceGladiator(finalGladiator);
//			Thread.sleep(1000);
			
//			System.out.println("Final Gladiator: ");
//			System.out.println("Gladiator fitness: " + finalGladiator.getFitness());
//			System.out.println("Gladiator health: " + finalGladiator.getChromosome().getHealth());
//			System.out.println("Gladiator age: " + finalGladiator.getChromosome().getAge());
//			System.out.println("Gladiator stats: " + finalGladiator.getChromosome().getResistanceLowerBody() + ", " + finalGladiator.getChromosome().getResistanceUpperBody() + ", " + finalGladiator.getChromosome().getDodgeChance());	
		}
		gladiators.printGladiatorPopulation();
	}

}
