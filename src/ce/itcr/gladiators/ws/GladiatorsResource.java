package ce.itcr.gladiators.ws;

import ce.itcr.gladiators.ws.res.Gladiator;
import ce.itcr.gladiators.ws.res.Gladiators;

import javax.ws.rs.*;
import javax.ws.rs.core.MediaType;
import java.util.Collection;

@Path("/gladiators")
@Consumes(MediaType.APPLICATION_JSON)
@Produces(MediaType.APPLICATION_JSON)
public class GladiatorsResource {

    private static Gladiators gladiators = Gladiators.getInstance();

    @GET
    public Collection<Gladiator> getGladiators() {
        return gladiators.viewAllGladiators();
    }

    @Path("/{id}")
    @DELETE
    public void deleteGladiator(@PathParam("id") String gladiatorId) {
        gladiators.removeGladiator(gladiatorId);
    }

    @POST
    public void postGladiator(Gladiator newGladiator) {
        gladiators.putGladiator(newGladiator);
    }

    @Path("{id}")
    @PUT
    public void putGladiator(@PathParam("id") String gladiatorId, Gladiator newGladiator) {
        gladiators.updateGladiator(gladiatorId, newGladiator);
    }
}
