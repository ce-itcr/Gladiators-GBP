package ce.itcr.gladiators.ws.res.gladiators;

import ce.itcr.gladiators.entities.GladiatorSend;

import javax.ws.rs.*;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;
import java.util.Collection;

@Path("/populations/gladiators")
@Consumes(MediaType.APPLICATION_JSON)
@Produces(MediaType.APPLICATION_JSON)
public class GladiatorsResource {

    private static GladiatorsSend gladiators = GladiatorsSend.getInstance();

    @GET
    public Response getGladiators() {
        Collection<GladiatorSend> gladiatorsResponse = gladiators.viewAllGladiators();
        Response.ResponseBuilder builder = Response.ok(gladiatorsResponse);
        builder.header("population-type", "gladiators");
        return builder.build();
    }

    @Path("/stats")
    @POST
    public void postGladiator(Collection<GladiatorSend> newGladiators) {
        gladiators.replaceAllGladiators(newGladiators);
    }

}
