package ce.itcr.gladiators.ws.res;

import ce.itcr.gladiators.genetic.resources.Gladiators;
import ce.itcr.gladiators.ws.res.gladiators.GladiatorsResource;

import javax.ws.rs.Consumes;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;

@Path("/populations")
@Consumes(MediaType.APPLICATION_JSON)
@Produces(MediaType.APPLICATION_JSON)
public class PopulationsResource {

    @POST
    public void startNewPopulation() {
    	Gladiators.getInstance().generateRandomPopulation();
    	FirstPopulation.generateFirstPopulation();
    }
}
