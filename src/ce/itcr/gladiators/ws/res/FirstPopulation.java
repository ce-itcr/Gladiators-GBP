package ce.itcr.gladiators.ws.res;

import ce.itcr.gladiators.entities.GladiatorSend;
import ce.itcr.gladiators.genetic.resources.Gladiators;
import ce.itcr.gladiators.ws.res.gladiators.GladiatorsSend;

public class FirstPopulation {
	
	public static void generateFirstPopulation() {
		Gladiators gladiators = new Gladiators();
		GladiatorsSend gladiatorsSend = GladiatorsSend.getInstance();
		for (int i = 0; i < gladiators.population.length-1; i++) {
			int age = gladiators.population[i].getChromosome().getAge();
			int health = gladiators.population[i].getChromosome().getHealth();
			int resistanceUpperBody = gladiators.population[i].getChromosome().getResistanceUpperBody();
			int resistanceLowerBody = gladiators.population[i].getChromosome().getResistanceLowerBody();
			int dodgeChance = gladiators.population[i].getChromosome().getDodgeChance();
			GladiatorSend g = new GladiatorSend(Integer.toString(i), age, health, resistanceUpperBody, resistanceLowerBody, dodgeChance);
			gladiatorsSend.putGladiator(g);
		}
	}

}
