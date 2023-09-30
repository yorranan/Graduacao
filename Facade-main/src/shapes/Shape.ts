import Color from "../colors/Color";

export default abstract class Shape {
    draw(): void {
        console.log("A forma foi desenhada.");
    }
    setColor(color: Color): void {
        console.log("A cor é " + color);
    }
    abstract area(): void;
    perimeter(perimeter: number): void {
        console.log("O perímetro é " + perimeter + "u.a.");
    }
}