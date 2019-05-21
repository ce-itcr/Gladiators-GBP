package ce.itcr.gladiators.ws.res.towers;

import ce.itcr.gladiators.entities.TowerSend;
import ce.itcr.gladiators.genetic.resources.Tower;
import ce.itcr.gladiators.genetic.resources.Towers;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

public class TowersSend {

    private static TowersSend instance = new TowersSend();
    private Map<String, TowerSend> towers = new HashMap<>();

    private TowersSend() {}

    public static TowersSend getInstance() {
        return instance;
    }

    public Collection<TowerSend> viewAllTowers() {
        return towers.values();
    }

    public void clearAllTowers() {
        towers = new HashMap<>();
    }

    public void replaceAllTowers(Collection<TowerSend> newTowers) {
        towers = new HashMap<>();
//        LinkedList<Tower> towerList = new LinkedList<Tower>();
        int index = 0;
        for (TowerSend towerSend : newTowers) {
            int attackSpeed = towerSend.getAttackSpeed();
            int damagePerShot = towerSend.getDamagePerShot();
            int level = towerSend.getLevel();
            int type = towerSend.getType();
            int xpForLevelUp = towerSend.getXpForLevelUp();
            int xp = towerSend.getXp();
            int baseAttackSpeed = towerSend.getBaseAttackSpeed();
            int baseDamagePerShot = towerSend.getBaseDamagePerShot();
            int i = towerSend.getI();
            int j = towerSend.getJ();
            if (index < Towers.getInstance().getListSize()) {
                Towers.getInstance().getTowersList().set(index, new Tower(attackSpeed, damagePerShot, level, type, xpForLevelUp, xp, baseAttackSpeed, baseDamagePerShot, i, j));
                index++;
            } else {
                Towers.getInstance().getTowersList().add(new Tower(attackSpeed, damagePerShot, level, type, xpForLevelUp, xp, baseAttackSpeed, baseDamagePerShot, i, j));
                index++;
            }
            towers.put(towerSend.getId(), towerSend);
        }
//        Towers.getInstance().setTowersList(towerList);
        Towers.getInstance().levelManager();
        towers = new HashMap<>();
        int i = 0;
        for (TowerSend towerSend : newTowers){
            towerSend.setAttackSpeed(Towers.getInstance().getTowersList().get(i).getAttackSpeed());
            towerSend.setBaseAttackSpeed(Towers.getInstance().getTowersList().get(i).getBaseAttackSpeed());
            towerSend.setDamagePerShot(Towers.getInstance().getTowersList().get(i).getDamagePerShot());
            towerSend.setBaseDamagePerShot(Towers.getInstance().getTowersList().get(i).getBaseDamagePerShot());
            towerSend.setI(Towers.getInstance().getTowersList().get(i).getI());
            towerSend.setJ(Towers.getInstance().getTowersList().get(i).getJ());
            towerSend.setLevel(Towers.getInstance().getTowersList().get(i).getLevel());
            towerSend.setXp(Towers.getInstance().getTowersList().get(i).getXp());
            towerSend.setType(Towers.getInstance().getTowersList().get(i).getType());
            towerSend.setXpForLevelUp(Towers.getInstance().getTowersList().get(i).getXpForLevelUp());
            towers.put(towerSend.getId(), towerSend);
            i++;
        }
        Towers.getInstance().printTowersList();
    }

    public void removeTower(String towerId) {
        towers.remove(towerId);
    }

    public void putTower(TowerSend newTower) {
        towers.put(newTower.getId(), newTower);
    }

    public void updateTower(String towerId, TowerSend newTower) {
        towers.put(towerId, newTower);
    }
}
