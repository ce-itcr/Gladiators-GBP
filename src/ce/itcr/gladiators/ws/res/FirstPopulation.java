package ce.itcr.gladiators.ws.res;

import ce.itcr.gladiators.entities.GladiatorSend;
import ce.itcr.gladiators.genetic.resources.Gladiators;
import ce.itcr.gladiators.ws.res.gladiators.GladiatorsSend;

public class FirstPopulation {
	
	public static void generateFirstPopulation() {
		GladiatorsSend gladiatorsSend = GladiatorsSend.getInstance();
		for (int i = 0; i < Gladiators.getInstance().getPopulationSize(); i++) {
			int age = Gladiators.getInstance().population[i].getChromosome().getAge();
			int health = Gladiators.getInstance().population[i].getChromosome().getHealth();
			int resistanceUpperBody = Gladiators.getInstance().population[i].getChromosome().getResistanceUpperBody();
			int resistanceLowerBody = Gladiators.getInstance().population[i].getChromosome().getResistanceLowerBody();
			int dodgeChance = Gladiators.getInstance().population[i].getChromosome().getDodgeChance();
			GladiatorSend g = new GladiatorSend(Integer.toString(i), age, health, resistanceUpperBody, resistanceLowerBody, dodgeChance);
			gladiatorsSend.putGladiator(g);
			System.out.println("i" + i);
		}
	}

}
