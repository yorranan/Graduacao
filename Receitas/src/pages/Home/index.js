import { Link } from "react-router-dom";
import React, { useEffect, useState } from "react";
import estilo from '../../assets/estilo.css';

function Home() {
    const [receitas, setReceitas] = useState([]);

    useEffect(() => {
      fetch('http://localhost:3000/posts')
      .then((r) => r.json())
      .then((json) => {
        setReceitas(json);
      });
    }, []);

    return (
        <div className="container">
            {receitas.map((receita) => (
                <article key={receita.id} className="post">
                    <h2 className="titulo">{receita.id} {receita.nome}</h2>     
                    <br/>
                    <Link to={`/receita/${receita.id}`} className="button">Acessar</Link>
                    <p></p>
                </article>
            ))}

        </div>
    );
}

export default Home;
