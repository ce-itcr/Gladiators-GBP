package ce.itcr.gladiators.ws.res.towers;

import ce.itcr.gladiators.entities.Tower;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

public class Towers {

    private static Towers instance = new Towers();
    private Map<String, Tower> towers = new HashMap<>();

    private Towers() {}

    public static Towers getInstance() {
        return instance;
    }

    public Collection<Tower> viewAllTowers() {
        return towers.values();
    }

    public void replaceAllGladiators(Collection<Tower> newTowers) {
        towers = new HashMap<>();
        for (Tower tower : newTowers) {
            towers.put(tower.getId(), tower);
        }
    }

    public void removeTower(String towerId) {
        towers.remove(towerId);
    }

    public void putTower(Tower newTower) {
        towers.put(newTower.getId(), newTower);
    }

    public void updateTower(String towerId, Tower newTower) {
        towers.put(towerId, newTower);
    }
}
