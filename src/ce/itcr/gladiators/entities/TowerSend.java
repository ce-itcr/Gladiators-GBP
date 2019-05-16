package ce.itcr.gladiators.entities;

public class TowerSend {

    private String id;
    private int i;
    private int j;
    private int damagePerShot;
    private int attackSpeed;
    private int xp;
    private int type;
    private int level;
    private int baseAttackSpeed;
    private int baseDamagePerShot;
    private int xpForLevelUp;

    public TowerSend(String id, int i, int j, int damagePerShot, int attackSpeed, int xp, int type, int level, int baseAttackSpeed, int baseDamagePerShot, int xpForLevelUp) {
        this.id = id;
        this.i = i;
        this.j = j;
        this.damagePerShot = damagePerShot;
        this.attackSpeed = attackSpeed;
        this.xp = xp;
        this.type = type;
        this.level = level;
        this.baseAttackSpeed = baseAttackSpeed;
        this.baseDamagePerShot = baseDamagePerShot;
        this.xpForLevelUp = xpForLevelUp;
    }

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

    public int getXpForLevelUp() {
        return xpForLevelUp;
    }

    public void setXpForLevelUp(int xpForLevelUp) {
        this.xpForLevelUp = xpForLevelUp;
    }

    public int getLevel() {
        return level;
    }

    public void setLevel(int level) {
        this.level = level;
    }

    public TowerSend() {}

    public TowerSend(String id) {
        this.id = id;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
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

    public int getDamagePerShot() {
        return damagePerShot;
    }

    public void setDamagePerShot(int damagePerShot) {
        this.damagePerShot = damagePerShot;
    }

    public int getAttackSpeed() {
        return attackSpeed;
    }

    public void setAttackSpeed(int attackSpeed) {
        this.attackSpeed = attackSpeed;
    }

    public int getXp() {
        return xp;
    }

    public void setXp(int xp) {
        this.xp = xp;
    }

    public int getType() {
        return type;
    }

    public void setType(int type) {
        this.type = type;
    }
}
