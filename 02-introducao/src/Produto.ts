export default class Produto
{
    private _codigo: number
    private _descricao: string
    private _valor: number

    constructor(codigo: number, descricao: string, valor: number)
    {
        this._codigo = codigo
        this._descricao = descricao
        this._valor = valor
    }

    get codigo(): number
    {
        return this._codigo
    }
    get descricao(): string
    {
        return this._descricao
    }
    get valor(): number
    {
        return this._valor
    }

    set codigo(codigo: number) 
    {
        this._codigo = codigo
    }
    set descricao(descricao: string)
    {
        this._descricao = descricao
    }
    set valor(valor: number)
    {
        this._valor = valor
    }
}