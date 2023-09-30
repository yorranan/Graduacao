import IItem from "../location/item/interface/IItem";
import Location from "./Location";
import Movie from "./item/movie";

export default class MovieLocation extends Location {
    protected createItem(): IItem {
        return new Movie;
    }
    
}