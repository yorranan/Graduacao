import Transport from "./transport/Transport"
import CarTransport from "./transport/CarTransport"
import MotorcycleTransport from "./transport/MotorcycleTransport"
import BikeTransport from "./transport/BikeTransport"

declare var process

let transport: Transport
if (process.argv.includes("--uber")){
    transport = new CarTransport()
    transport.startTransport()
}
else if (process.argv.includes("--eats")){
    transport = new MotorcycleTransport()
    transport.startTransport()
}
else if (process.argv.includes("--bike")){
    transport = new BikeTransport()
    transport.startTransport()
}
else{
    console.log("Selecione o tipo de transporte.")
}