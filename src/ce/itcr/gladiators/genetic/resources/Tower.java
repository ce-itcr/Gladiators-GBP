package ce.itcr.gladiators.genetic.resources;

public class Tower {
	
	private int attackSpeed;
	private int damagePerShot;
	private int level;
	private int type;
	private int xpForLevelUp;
	private int xp;
	private int baseAttackSpeed;
	private int baseDamagePerShot;
	private int i;
	private int j;

	public int getBaseAttackSpeed() {
		return baseAttackSpeed;
	}

	public void setBaseAttackSpeed(int baseAttackSpeed) {
		this.baseAttackSpeed = baseAttackSpeed;
	}

	public int getBaseDamagePerShot() {
		return baseDamagePerShot;
	}

	public void setBaseDamagePerShot(int baseDamagePerShot) {
		this.baseDamagePerShot = baseDamagePerShot;
	}

	public int getI() {
		return i;
	}

	public void setI(int i) {
		this.i = i;
	}

	public int getJ() {
		return j;
	}

	public void setJ(int j) {
		this.j = j;
	}

	public Tower() {
		super();
		this.attackSpeed = 1;
		this.damagePerShot = 1;
		this.baseAttackSpeed = 1;
		this.baseDamagePerShot = 1;
		this.level = 1;
		this.type = 1;
		this.xpForLevelUp = 10;
		this.xp = 0;
		this.i = -1;
		this.j = -1;
	}

	public Tower(int attackSpeed, int damagePerShot, int level, int type, int xpForLevelUp, int xp, int baseAttackSpeed, int baseDamagePerShot, int i, int j) {
		this.attackSpeed = attackSpeed;
		this.damagePerShot = damagePerShot;
		this.level = level;
		this.type = type;
		this.xpForLevelUp = xpForLevelUp;
		this.xp = xp;
		this.baseAttackSpeed = baseAttackSpeed;
		this.baseDamagePerShot = baseDamagePerShot;
		this.i = i;
		this.j = j;
	}

	public void levelUp() {
		if (this.level == 4 && this.type < 3) {
			this.type++;
			this.level = 1;
			this.xp -= xpForLevelUp;
			this.xpForLevelUp += 10;
			upgradeRNG();
		}
		if (this.attackSpeed > 500);
			this.attackSpeed -= 10;
		this.damagePerShot += 5;
		this.level++;
		this.xp -= this.xpForLevelUp;
		this.xpForLevelUp += 10;
	}
	
	private void upgradeRNG() {
		if (Math.random() < 0.1) {
			this.baseDamagePerShot = this.damagePerShot;
			this.baseAttackSpeed = this.attackSpeed;
			return;
		}
		this.attackSpeed = this.baseAttackSpeed;
		this.damagePerShot = this.baseDamagePerShot;
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