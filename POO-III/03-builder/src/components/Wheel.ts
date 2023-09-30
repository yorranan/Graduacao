export default class Wheel {
    constructor (private _rim: number){}

    get rin(): number {
        return this._rim;
    }

    set rin(rim: number){
        this._rim = rim;
    }
}