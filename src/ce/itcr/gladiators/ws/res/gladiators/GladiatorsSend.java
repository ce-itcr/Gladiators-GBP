package ce.itcr.gladiators.ws.res.gladiators;

import ce.itcr.gladiators.entities.GladiatorSend;
import ce.itcr.gladiators.genetic.resources.Gladiator;
import ce.itcr.gladiators.genetic.resources.Gladiators;
import ce.itcr.gladiators.genetic.GeneticAlgorithm;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

public class GladiatorsSend {

    private static GladiatorsSend instance = new GladiatorsSend();
    private Map<String, GladiatorSend> gladiators = new HashMap<>();
    private GeneticAlgorithm geneticAlgorithm = new GeneticAlgorithm();

    private GladiatorsSend() {}

    public static GladiatorsSend getInstance() {
        return instance;
    }

    public Collection<GladiatorSend> viewAllGladiators() {
        return gladiators.values();
    }

    public void replaceAllGladiators(Collection<GladiatorSend> newGladiators) {
        GeneticAlgorithm geneticAlgorithm = new GeneticAlgorithm();
        Gladiators.getInstance().population = geneticAlgorithm.collectionToGladiatorArray(newGladiators);
    	Gladiator [] gladiatorArray = Gladiators.getInstance().population;
        gladiators = new HashMap<>();
        geneticAlgorithm.newGeneration(newGladiators, 10);
        int i = 0;
        for (GladiatorSend gladiator : newGladiators) {
        	int age = gladiatorArray[i].getChromosome().getAge();
        	int health = gladiatorArray[i].getChromosome().getHealth();
        	int resistanceUpperBody = gladiatorArray[i].getChromosome().getResistanceUpperBody();
        	int resistanceLowerBody = gladiatorArray[i].getChromosome().getResistanceLowerBody();
        	int dodgeChance = gladiatorArray[i].getChromosome().getDodgeChance();
        	gladiator = new GladiatorSend(gladiator.getId(), age, health, resistanceUpperBody, resistanceLowerBody, dodgeChance);
            gladiators.put(gladiator.getId(), gladiator);
            i++;
        }
    }

    public void removeGladiator(String gladiatorId) {
        gladiators.remove(gladiatorId);
    }

    public void putGladiator(GladiatorSend newGladiator) {
        gladiators.put(newGladiator.getId(), newGladiator);
    }

    public void updateGladiator(String gladiatorId, GladiatorSend newGladiator) {
        gladiators.put(gladiatorId, newGladiator);
    }

}
