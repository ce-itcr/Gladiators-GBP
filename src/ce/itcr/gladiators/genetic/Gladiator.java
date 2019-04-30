package ce.itcr.gladiators.genetic;

import java.util.Random;
import java.util.stream.IntStream;

public class Gladiator {
	
	private Chromosome chromosome;
	private int fitness;
	Random random;
	
	public Gladiator(Chromosome chromosome) {
		super();
		this.chromosome = chromosome;
	}

	public Chromosome crossover(Chromosome chromosome) {
		Chromosome finalChromosome = new Chromosome();
		finalChromosome.setAge(0);
		finalChromosome.setHealth((chromosome.getHealth()+this.chromosome.getHealth())/2);
		finalChromosome.setResistanceLowerBody((chromosome.getResistanceLowerBody()+this.chromosome.getResistanceLowerBody())/2);
		finalChromosome.setResistanceUpperBody((chromosome.getResistanceUpperBody()+this.chromosome.getResistanceUpperBody())/2);
		finalChromosome.setDodgeChance((chromosome.getDodgeChance()+this.chromosome.getDodgeChance())/2);
		return finalChromosome;
	}
	
	public Chromosome mutate() {
		if (Math.random() < 0.5)
			random.nextInt()
		return chromosome;
	}
	
	public int getFitness() {
		
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
	public int getFitness() {
		return fitness;
	}
	public void setFitness(int fitness) {
		this.fitness = fitness;
	}

}
