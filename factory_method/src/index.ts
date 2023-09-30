import Location from "./location/Location";
import GameLocation from "./location/GameLocation"
import MovieLocation from "./location/MovieLocation";

declare var process

let item: Location

if (process.argv.includes("--game")) {
    item = new GameLocation();
    item.startItem();
}
else if (process.argv.includes("--movie")){
    item = new MovieLocation();
    item.startItem();
}   
else {
    console.log("Opção não reconhecida! Tente novamente.")
}