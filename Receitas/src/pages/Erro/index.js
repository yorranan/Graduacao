import { Link } from "react-router-dom";

function Erro() {
    return(
        <div>
            <h2>Ops! Parece que a página não existe!</h2>
            <h2>:/</h2>
            <span>Encontramos essas páginas aqui:</span>
            <br/>
            <Link to="/">Home</Link>
            <Link to="/sobre">Sobre</Link>
            <Link to="/contato">Contato</Link>
            <Link to="/produto">Produto</Link>
        </div>
    );
}

export default Erro;