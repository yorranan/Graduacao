import Bread from "../components/Bread"
import Protein from "../components/Protein";
import Salad from "../components/Salad";
import Sauce from "../components/Sauce";

export default class Sanduiche {

    private _sanduicheType: SanduicheType;
    private _bread: Bread;
    private _protein: Protein;
    private _salad: Salad;
    private _sauce: Sauce[] = [];



    /**
     * Getter sanduicheType
     * @return {SanduicheType}
     */
	public get sanduicheType(): SanduicheType {
		return this._sanduicheType;
	}

    /**
     * Setter sanduicheType
     * @param {SanduicheType} value
     */
	public set sanduicheType(value: SanduicheType) {
		this._sanduicheType = value;
	}


    /**
     * Getter bread
     * @return {Bread}
     */
	public get bread(): Bread {
		return this._bread;
	}

    /**
     * Getter protein
     * @return {Protein}
     */
	public get protein(): Protein {
		return this._protein;
	}

    /**
     * Getter salad
     * @return {Salad}
     */
	public get salad(): Salad {
		return this._salad;
	}

   

    /**
     * Setter sanduicheType
     * @param {SanduicheType} value
     */
	public set sanduicheType(value: SanduicheType) {
		this._sanduicheType = value;
	}

    /**
     * Setter bread
     * @param {Bread} value
     */
	public set bread(value: Bread) {
		this._bread = value;
	}

    /**
     * Setter protein
     * @param {Protein} value
     */
	public set protein(value: Protein) {
		this._protein = value;
	}

    /**
     * Setter salad
     * @param {Salad} value
     */
	public set salad(value: Salad) {
		this._salad = value;
	}


    /**
     * Getter sauce
     * @return {Sauce[] }
     */
	public get sauce(): Sauce[]  {
		return this._sauce;
	}

    /**
     * Setter sauce
     * @param {Sauce[] } value
     */
	public set sauce(value: Sauce[] ) {
		this._sauce = value;
	}

    public addSauce(sauce: Sauce) {
        this._sauce;
    }
}