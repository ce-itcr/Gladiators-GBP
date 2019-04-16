package ce.itcr.gladiators.ws.res.towers;

import ce.itcr.gladiators.entities.Tower;

import javax.ws.rs.*;
import javax.ws.rs.core.MediaType;
import java.util.Collection;

@Path("/towers")
@Consumes(MediaType.APPLICATION_JSON)
@Produces(MediaType.APPLICATION_JSON)
public class TowersResources {

    private static Towers towers = Towers.getInstance();

    @GET
    public Collection<Tower> getTowers() {
        return towers.viewAllTowers();
    }

    @Path("/stats")
    @POST
    public void postTowers(Collection<Tower> newTowers) {
        towers.replaceAllGladiators(newTowers);
    }
}
