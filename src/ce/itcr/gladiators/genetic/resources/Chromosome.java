package ce.itcr.gladiators.genetic.resources;

public class Chromosome {
	
	private int [] chromosomeArray;
	private int health;
	private int resistanceUpperBody;
	private int resistanceLowerBody;
	private int dodgeChance;
	private int age;
	
	public Chromosome(int num) {
		super();
		this.health = num;
		this.resistanceUpperBody = num;
		this.resistanceLowerBody = num;
		this.dodgeChance = num;
		this.age = num;
	}

	public int[] getChromosomeArray() {
		this.chromosomeArray = new int[] {health, resistanceLowerBody, resistanceUpperBody, dodgeChance, age};
		return this.chromosomeArray;
	}
	
	public void mutateGene(int i) {
		getChromosomeArray()[i] ++;
		setHealth(chromosomeArray[0]);
		setResistanceLowerBody(chromosomeArray[1]);
		setResistanceUpperBody(chromosomeArray[2]);
		setDodgeChance(chromosomeArray[3]);
		setAge(chromosomeArray[4]++);
	}

	public int getHealth() {
		return health;
	}

	public void setHealth(int health) {
		this.health = health;
	}

	public int getResistanceUpperBody() {
		return resistanceUpperBody;
	}

	public void setResistanceUpperBody(int resistanceUpperBody) {
		this.resistanceUpperBody = resistanceUpperBody;
	}

	public int getResistanceLowerBody() {
		return resistanceLowerBody;
	}

	public void setResistanceLowerBody(int resistanceLowerBody) {
		this.resistanceLowerBody = resistanceLowerBody;
	}

	public int getDodgeChance() {
		return dodgeChance;
	}

	public void setDodgeChance(int dodgeChance) {
		this.dodgeChance = dodgeChance;
	}

	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		this.age = age;
	}
	
}
