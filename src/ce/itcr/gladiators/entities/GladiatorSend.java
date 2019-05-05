package ce.itcr.gladiators.entities;

public class GladiatorSend {

    private String id;
    private int age;
	private int health;
	private int resistanceUpperBody;
	private int resistanceLowerBody;
	private int dodgeChance;

    public GladiatorSend() {}

    public GladiatorSend(String id, int age, int health, int resistanceUpperBody, int resistanceLowerBoddy, int dodgeChance) {
        this.id = id;
        this.age = age;
        this.health = health;
        this.resistanceLowerBody = resistanceLowerBoddy;
        this.resistanceUpperBody = resistanceUpperBody;
        this.dodgeChance = dodgeChance;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
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
