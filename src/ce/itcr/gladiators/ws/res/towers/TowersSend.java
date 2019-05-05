package ce.itcr.gladiators.ws.res.towers;

import ce.itcr.gladiators.entities.TowerSend;

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

    public void replaceAllTowers(Collection<TowerSend> newTowers) {
        towers = new HashMap<>();
        for (TowerSend tower : newTowers) {
            towers.put(tower.getId(), tower);
        }
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
