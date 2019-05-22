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
		if (Math.random() < 0.5){
			finalChromosome.setHealth(this.chromosome.getHealth());
			finalChromosome.setResistanceLowerBody(this.chromosome.getResistanceLowerBody());
			finalChromosome.setResistanceUpperBody(gladiator.getChromosome().getResistanceUpperBody());
			finalChromosome.setDodgeChance(gladiator.getChromosome().getDodgeChance());
		} else {
			finalChromosome.setHealth(gladiator.chromosome.getHealth());
			finalChromosome.setResistanceLowerBody(gladiator.chromosome.getResistanceLowerBody());
			finalChromosome.setResistanceUpperBody(this.getChromosome().getResistanceUpperBody());
			finalChromosome.setDodgeChance(this.getChromosome().getDodgeChance());
		}
		return new Gladiator(mutate(finalChromosome));
	}
	
	private Chromosome mutate(Chromosome chromosome) {
		if (Math.random() < 0.8)
			chromosome.mutateGene();
		return chromosome;
	}
	
	public Chromosome getChromosome() {
		return chromosome;
	}
	public void setChromosome(Chromosome chromosome) {
		this.chromosome = chromosome;
	}
	public void setFitness() {
		fitness += chromosome.getHealth() + chromosome.getResistanceLowerBody() + chromosome.getResistanceUpperBody() + chromosome.getDodgeChance();
	}
	public int getFitness() {
		return fitness;
	}

}
