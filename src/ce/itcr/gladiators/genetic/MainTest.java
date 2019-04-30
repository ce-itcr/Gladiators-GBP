package ce.itcr.gladiators.genetic;

public class MainTest {

	public static void main(String[] args) {
		Towers towers = new Towers();
		towers.generateTowersList(10);
		towers.printTowersList();
	}

}
