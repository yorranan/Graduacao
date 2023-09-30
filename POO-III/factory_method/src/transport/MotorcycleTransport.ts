import Transport from "./Transport"
import IVehicle from "./vehicle/interface/IVehicle"
import Motorcycle from "./vehicle/motorcycle"

export default class MotorcycleTransport extends Transport{
    protected createTransport(): IVehicle {
        return new Motorcycle();
    }
}