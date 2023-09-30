import IItem from "./item/interface/IItem";

export default abstract class Location {
    
    startItem(): void {
        const location = this.createItem();
        location.start();
    }
    protected abstract createItem(): IItem;
}