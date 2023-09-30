import Shape from "../Shape";

export default class Hexagon extends Shape {
    
    draw(): void {
        console.log("O hexagono foi desenhado.");
    }

    area(): void {
        console.log("Área do Hexagono é 8u.a.");
    }

}