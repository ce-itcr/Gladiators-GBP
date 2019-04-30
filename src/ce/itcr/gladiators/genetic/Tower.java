package ce.itcr.gladiators.genetic;

public class Tower {
	
	private int attackSpeed;
	private int damagePerShot;
	private int level;
	private int type;
	private int xpForLevelUp;
	private int xp;
	
	public Tower() {
		super();
		this.attackSpeed = 1;
		this.damagePerShot = 1;
		this.level = 1;
		this.type = 1;
		this.xpForLevelUp = 10;
		this.xp = 0;
	}
	
	public void levelUp() {
		if (this.level == 10 && this.type < 3) {
			this.type++;
			this.level = 1;
			this.xp = 0;
			this.xpForLevelUp += 10;
			upgradeRNG();
		}
		this.attackSpeed++;
		this.damagePerShot++;
		this.level++;
	}
	
	public void upgradeRNG() {
		if (Math.random() < 0.3)
			return;
		this.attackSpeed = 1;
		this.damagePerShot = 1;
	}

	public int getAttackSpeed() {
		return attackSpeed;
	}

	public void setAttackSpeed(int attackSpeed) {
		this.attackSpeed = attackSpeed;
	}

	public int getDamagePerShot() {
		return damagePerShot;
	}

	public void setDamagePerShot(int damagePerShot) {
		this.damagePerShot = damagePerShot;
	}

	public int getLevel() {
		return level;
	}

	public void setLevel(int level) {
		this.level = level;
	}

	public int getType() {
		return type;
	}

	public void setType(int type) {
		this.type = type;
	}

	public int getXpForLevelUp() {
		return xpForLevelUp;
	}

	public void setXpForLevelUp(int xpForLevelUp) {
		this.xpForLevelUp = xpForLevelUp;
	}

	public int getXp() {
		return xp;
	}

	public void setXp(int xp) {
		this.xp = xp;
	}
	
	
	
}
