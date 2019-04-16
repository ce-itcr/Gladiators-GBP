package ce.itcr.gladiators.ws;

import ce.itcr.gladiators.entities.Gladiator;
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

    @Path("/stats")
    @POST
    public void postGladiator(Collection<Gladiator> newGladiators) {
        gladiators.replaceAllGladiators(newGladiators);
    }

}
