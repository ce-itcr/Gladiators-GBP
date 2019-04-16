package ce.itcr.gladiators.ws.res.gladiators;

import ce.itcr.gladiators.entities.Gladiator;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

public class Gladiators {

    private static Gladiators instance = new Gladiators();
    private Map<String, Gladiator> gladiators = new HashMap<>();

    private Gladiators() {}

    public static Gladiators getInstance() {
        return instance;
    }

    public Collection<Gladiator> viewAllGladiators() {
        return gladiators.values();
    }

    public void replaceAllGladiators(Collection<Gladiator> newGladiators) {
        gladiators = new HashMap<>();
        for (Gladiator gladiator : newGladiators) {
            gladiators.put(gladiator.getId(), gladiator);
        }
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
