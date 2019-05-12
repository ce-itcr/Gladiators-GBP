package ce.itcr.gladiators.ws.res.towers;

import ce.itcr.gladiators.entities.TowerSend;

import javax.ws.rs.*;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;
import java.util.Collection;

@Path("/populations/towers")
@Consumes(MediaType.APPLICATION_JSON)
@Produces(MediaType.APPLICATION_JSON)
public class TowersResources {

    private static TowersSend towers = TowersSend.getInstance();

    @GET
    public Response getTowers() {
        Collection<TowerSend> towersResponse = towers.viewAllTowers();
        Response.ResponseBuilder builder = Response.ok(towersResponse);
        builder.header("population-type", "towers");
        return builder.build();
    }

    @Path("/stats")
    @POST
    public void postTowers(Collection<TowerSend> newTowers) {
        towers.replaceAllTowers(newTowers);
    }
}
