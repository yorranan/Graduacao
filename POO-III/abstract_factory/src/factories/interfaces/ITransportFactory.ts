import IAircraft from "../../vehicles/aerial/interfaces/IAircraft";
import ILand from "../../vehicles/land/interfaces/ILand";

export default interface ITransportFactory {
    createTransportVehicle(): ILand;
    createTransportAircraft(): IAircraft
}