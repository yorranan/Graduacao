import Cliente from "./Cliente"
import Produto from "./Produto"

export default class Venda
{
    private _codigo: number
    private _data: number
    private _cliente: Cliente
    private _produtos: Produto[]

    constructor (codigo: number, data: number, cliente: Cliente, produto: Produto[])
    {
        this._codigo = codigo
        this._data = data
        this._cliente = cliente
        this._produtos = produto
    }

    get codigo(): number
    { 
        return this._codigo
    }
    get data(): number
    {
        return this._data
    }
    get cliente(): Cliente
    {
        return this._cliente
    }
    get produtos(): Produto[]
    {
        return this._produtos
    }

    set codigo(codigo: number)
    {
        this._codigo = codigo
    }
    set data(data: number)
    {
        this._data = data
    }
    set cliente(cliente: Cliente)
    {
        this._cliente = cliente
    }
    set produtos(produto: Produto[])
    {
        this._produtos = produto
    }
    
    calcularTotal(produtos: Produto[]): number
    {
        let total: number = 0;
        produtos.forEach((item) => {
            total += item.valor;
        });
        return total
    }

}