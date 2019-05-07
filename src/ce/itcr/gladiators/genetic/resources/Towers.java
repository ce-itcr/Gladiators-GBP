package ce.itcr.gladiators.genetic.resources;

import java.util.LinkedList;

public class Towers {
	
	private LinkedList<Tower> towersList = new LinkedList<Tower>();
	private static Towers towers = new Towers();

	public static Towers getInstance() {
		return towers;
	}
	
	public int getListSize() {
		return towersList.size();
	}

	public LinkedList<Tower> getTowersList() {
		return towersList;
	}

	public void setTowersList(LinkedList<Tower> towersList) {
		this.towersList = towersList;
	}

	public void generateTowersList(int numOfTowers) {
		for (int i = 0; i < numOfTowers - 1; i++) {
			Tower t = new Tower();
			towersList.add(t);
		}
	}
	
	public void newTowerRNG() {
		if (Math.random() < 0.3)
			towersList.add(new Tower());
	}
	
	public void printTowersList() {
		int i = 1;
		for (Tower t : towersList) {
			System.out.println("-------------------------------------------------------");
			System.out.println("Tower" + i);
			System.out.println("Type: " + t.getType());
			System.out.println("Level: " + t.getLevel());
			System.out.println("Attack Speed: " + t.getAttackSpeed());
			System.out.println("Damage: " + t.getDamagePerShot());
			System.out.println("-------------------------------------------------------");
			i++;
		}
	}

	public void levelManager(){
		for (Tower tower : towersList) {
			while (tower.getXp() >= tower.getXpForLevelUp())
				tower.levelUp();
		}
	}

}
