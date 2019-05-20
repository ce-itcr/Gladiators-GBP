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
		if (num < 1)
		    num = 1;
		this.health = num;
		this.resistanceUpperBody = num;
		this.resistanceLowerBody = num;
		this.dodgeChance = num;
		this.age = 0;
	}

	public Chromosome(){}

	public int[] getChromosomeArray() {
		this.chromosomeArray = new int[] {health, resistanceLowerBody, resistanceUpperBody, dodgeChance, age};
		return this.chromosomeArray;
	}

    public void setChromosomeArray(int[] chromosomeArray) {
        this.chromosomeArray = chromosomeArray;
        this.health = chromosomeArray[0];
        this.resistanceLowerBody = chromosomeArray[1];
        this.resistanceUpperBody = chromosomeArray[2];
        this.dodgeChance = chromosomeArray[3];
    }
	
	public void mutateGene() {
	    int [] newChromosomeArray = getChromosomeArray();
	    int strongestGene = getStrongestGene();
		newChromosomeArray[strongestGene] = getChromosomeArray()[strongestGene] + 2;
		if (Math.random() < 0.5)
            newChromosomeArray[strongestGene] = getChromosomeArray()[strongestGene] + 8;
		newChromosomeArray[0] += 5;
		if (Math.random() < 0.5)
		    newChromosomeArray[3]++;
		setChromosomeArray(newChromosomeArray);
	}

	private int getStrongestGene(){
	    if (getChromosomeArray()[1] < getChromosomeArray()[2])
	        return 1;
	    else
	        return 2;
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
