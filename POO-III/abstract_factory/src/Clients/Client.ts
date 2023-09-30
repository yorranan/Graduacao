import ITransportFactory from "../factories/interfaces/ITransportFactory";
import IAircraft from "../vehicles/aerial/interfaces/IAircraft";
import ILand from "../vehicles/land/interfaces/ILand";

export default class CLient {
  private vehicle: ILand;
  private aircraft: IAircraft;

  constructor(factory: ITransportFactory, isLand: boolean) {
    if (isLand == true) {
        this.vehicle = factory.createTransportVehicle();
    }
    else {
        this.aircraft = factory.createTransportAircraft();
    }
  }

  startRoute() {
    this.vehicle.startRoute();
    this.aircraft.startRoute();
  }
}
