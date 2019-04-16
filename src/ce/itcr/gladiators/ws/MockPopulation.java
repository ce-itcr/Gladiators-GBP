package ce.itcr.gladiators.ws;

import ce.itcr.gladiators.entities.Gladiator;
import ce.itcr.gladiators.entities.Tower;
import ce.itcr.gladiators.ws.res.gladiators.Gladiators;
import ce.itcr.gladiators.ws.res.towers.Towers;

public class MockPopulation {

    public static void startNewPopulation() {
        startGladiators();
        startTowers();
    }

    private static void startGladiators() {
        Gladiators gladiators = Gladiators.getInstance();

        Gladiator g1 = new Gladiator("1", "Atilius", "23");
        Gladiator g2 = new Gladiator("2", "Marcus", "25");
        Gladiator g3 = new Gladiator("3", "Spartacus", "19");

        gladiators.putGladiator(g1);
        gladiators.putGladiator(g2);
        gladiators.putGladiator(g3);
    }

    private static void startTowers() {
        Towers towers = Towers.getInstance();

        Tower t1 = new Tower("1");
        Tower t2 = new Tower("2");
        Tower t3 = new Tower("3");

        towers.putTower(t1);
        towers.putTower(t2);
        towers.putTower(t3);
    }
}
