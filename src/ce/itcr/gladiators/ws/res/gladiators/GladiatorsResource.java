package ce.itcr.gladiators.ws.res.gladiators;

import ce.itcr.gladiators.entities.Gladiator;

import javax.ws.rs.*;
import javax.ws.rs.core.MediaType;
import java.util.Collection;

@Path("/populations/gladiators")
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
