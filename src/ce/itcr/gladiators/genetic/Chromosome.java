package ce.itcr.gladiators.genetic;

public class Chromosome {
	
	private int health;
	private int resistanceUpperBody;
	private int resistanceLowerBody;
	private int dodgeChance;
	private int age;

	public int[] getChromosomeArray() {
		return new int[] {health, resistanceLowerBody, resistanceUpperBody, dodgeChance, age};
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
