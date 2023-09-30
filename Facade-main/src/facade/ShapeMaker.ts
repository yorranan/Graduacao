import Color from "../colors/Color";
import Shape from "../shapes/Shape";
import Hello from "../shapes/hello/Hello";
import Circle from "../shapes/twodshapes/Circle";
import Hexagon from "../shapes/twodshapes/Hexagon";
import Rectangle from "../shapes/twodshapes/Rectangle";
import Square from "../shapes/twodshapes/Square";
import Triangle from "../shapes/twodshapes/Triangle";
import HelloMaker from "./HelloMaker";

export default class ShapeMaker {

    protected hello: HelloMaker;
    private circle: Shape;
    private hexagon: Shape;
    private rectangle: Shape;
    private square: Shape;
    private triangle: Shape;

    constructor() {
        this.circle = new Circle();
        this.hexagon = new Hexagon();
        this.rectangle = new Rectangle();
        this.square = new Square();
        this.triangle = new Triangle();
        this.hello = new HelloMaker();
    }
    
    drawCircle(): void {
        this.circle.draw();
        this.circle.area();
        this.circle.setColor(Color.RED);
        this.rectangle.perimeter(1);
    }

    drawHexagon(): void {
        this.hexagon.draw();
        this.hexagon.area();
        this.hexagon.setColor(Color.BLUE);
        this.rectangle.perimeter(10);
    }

    drawRetangle(): void {
        this.rectangle.draw();
        this.rectangle.area();
        this.rectangle.setColor(Color.PURPLE);
        this.rectangle.perimeter(100);
    }

    drawSquare(): void {
        this.square.draw();
        this.square.area();
        this.square.setColor(Color.GREEN);
        this.square.perimeter(101);
    }

    drawTriangle(): void {
        this.triangle.draw();
        this.triangle.area();
        this.triangle.setColor(Color.WHITE);
        this.triangle.perimeter(111);
    }   

    say(): void {
        this.hello.sayHello();
    }
}