package ce.itcr.gladiators.ws.res.towers;

import ce.itcr.gladiators.entities.TowerSend;
import ce.itcr.gladiators.genetic.resources.Towers;
import ce.itcr.gladiators.genetic.resources.Tower;
import sun.awt.image.ImageWatched;

import java.util.Collection;
import java.util.HashMap;
import java.util.LinkedList;
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

    public void replaceAllTowers(Collection<TowerSend> newTowers) {
        towers = new HashMap<>();
        LinkedList<Tower> towerList = new LinkedList<Tower>();
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
            towerList.add(new Tower(attackSpeed, damagePerShot, level, type, xpForLevelUp, xp, baseAttackSpeed, baseDamagePerShot, i, j));
            towers.put(towerSend.getId(), towerSend);
        }
        Towers.getInstance().setTowersList(towerList);
        Towers.getInstance().levelManager();
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
