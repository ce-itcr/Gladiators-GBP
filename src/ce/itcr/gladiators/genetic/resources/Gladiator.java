package ce.itcr.gladiators.genetic.resources;

import java.util.Random;

public class Gladiator {
	
	private Chromosome chromosome;
	private int fitness = 0;
	Random random = new Random();
	
	public Gladiator(Chromosome chromosome) {
		super();
		this.chromosome = chromosome;
		setFitness();
	}

	public Gladiator crossover(Gladiator gladiator) {
		Chromosome finalChromosome = new Chromosome(0);
		finalChromosome.setAge(0);
		finalChromosome.setHealth(this.chromosome.getHealth());
		finalChromosome.setResistanceLowerBody(this.chromosome.getResistanceLowerBody());
		finalChromosome.setResistanceUpperBody(gladiator.getChromosome().getResistanceUpperBody());
		finalChromosome.setDodgeChance(gladiator.getChromosome().getDodgeChance());
		Gladiator finalGladiator = new Gladiator(mutate(finalChromosome));
		return finalGladiator;
	}
	
	private Chromosome mutate(Chromosome chromosome) {
		if (Math.random() < 10)
			chromosome.mutateGene(random.nextInt(((3 - 0) + 1) + 0));
		return chromosome;
	}
	
	public int getSpeed() {
		int speed = 0;
		speed += chromosome.getResistanceLowerBody();
		speed -= chromosome.getResistanceUpperBody()/2;
		return speed;
	}
	
	public int getThoughness() {
		int thoughness = 0;
		thoughness += chromosome.getResistanceUpperBody();
		thoughness -= chromosome.getResistanceLowerBody()/2;
		return thoughness;
	}
	
	public Chromosome getChromosome() {
		return chromosome;
	}
	public void setChromosome(Chromosome chromosome) {
		this.chromosome = chromosome;
	}
	public void setFitness() {
		fitness += chromosome.getHealth() + chromosome.getDodgeChance() + chromosome.getResistanceLowerBody() + chromosome.getResistanceUpperBody();
	}
	public int getFitness() {
		return fitness;
	}
	public void setFitness(int fitness) {
		this.fitness = fitness;
	}

}
