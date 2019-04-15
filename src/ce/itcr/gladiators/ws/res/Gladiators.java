package ce.itcr.gladiators.ws.res;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

public class Gladiators {

    private static Gladiators instance = new Gladiators();
    private Map<String, Gladiator> gladiators = new HashMap<>();

    private Gladiators() {
        Gladiator g1 = new Gladiator("1", "Atilius", "23");
        Gladiator g2 = new Gladiator("2", "Marcus", "25");
        Gladiator g3 = new Gladiator("3", "Spartacus", "19");

        gladiators.put(g1.getId(), g1);
        gladiators.put(g2.getId(), g2);
        gladiators.put(g3.getId(), g3);
    }

    public static Gladiators getInstance() {
        return instance;
    }

    public Collection<Gladiator> viewAllGladiators() {
        return gladiators.values();
    }

    public void removeGladiator(String gladiatorId) {
        gladiators.remove(gladiatorId);
    }

    public void putGladiator(Gladiator newGladiator) {
        gladiators.put(newGladiator.getId(), newGladiator);
    }

    public void updateGladiator(String gladiatorId, Gladiator newGladiator) {
        gladiators.put(gladiatorId, newGladiator);
    }

}
